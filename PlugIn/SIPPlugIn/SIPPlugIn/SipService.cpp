 #include "stdafx.h"
#include "SipService.h"


static SipService	    *__sipsrv = NULL;
static acl::thread_pool *__thdpool = NULL;

static acl::locker __msglocker;
static register_map __regmap;		//注册管理
static session_list __seslist;		//会话列表
static session_list __sublist;		//订阅列表
static session_map	__sesmap;		//会话管理
static session_map	__msgmap;		//消息管理
static device_map	__devmap;		//设备管理


acl::string acl_xml_getElementValue(acl::xml1 &xml, const char *tag)
{
	acl::xml_node *node = xml.getFirstElementByTag(tag);
	if (node ==  NULL)
		return "";
	return node->text();
}

int acl_xml_getElementInt(acl::xml1 &xml, const char *tag)
{
	acl::xml_node *node = xml.getFirstElementByTag(tag);
	if (node == NULL)
		return 0;
	return atoi(node->text());
}

//depth: 子级层数
acl::json_node *acl_json_get_child(acl::json_node *node, int depth)
{
	int i = 0;
	acl::json_node *child = node->first_child();
	while (child)
	{
		++i;
		if (i == depth)
		{
			return child;
		}
		child = child->first_child();
	}
	return NULL;
}

void sip_sleep(int usec)
{
#ifdef _WIN32
	Sleep(usec);
#else
	usleep(usec);
#endif
}

//任务处理线程池
class sip_thread_pool : public acl::thread_pool
{
public:
	sip_thread_pool()
	{
	}
	~sip_thread_pool()
	{
	}
protected:
	virtual bool thread_on_init()
	{
		printf("thread_on_init curtid: %lu\n", acl::thread::thread_self());
		return true;
	}
	virtual void thread_on_exit()
	{
		printf("thread_on_exit curtid: %lu\n", acl::thread::thread_self());
	}
};
//任务处理子线程
class sip_handle_thread : public acl::thread
{
public:
	sip_handle_thread(acl::socket_stream* stream, const char *data, size_t dlen, void *sip)
	{
		pSip = (SipService *)sip;
		pStream = stream;
		pData = data;
		nDlen = dlen;
	}
	~sip_handle_thread()
	{
		pSip = NULL;
	}
protected:
	virtual void *run()
	{
		if (pSip)
		{
			pSip->on_handle(pStream, pData, nDlen);
		}
		delete this;
		return NULL;
	}
private:
	SipService *pSip;
	acl::socket_stream* pStream;
	const char *pData;
	size_t nDlen;
};
//注册管理线程
class regmnger_thread : public acl::thread
{
public:
	regmnger_thread(void *pUser)
	{
		pSip = (SipService *)pUser;
	}
	~regmnger_thread()
	{
		pSip = NULL;
	}
protected:
	virtual void *run()
	{
		if (pSip)
			pSip->register_manager();
		delete this;
		return NULL;
	}
private:
	SipService *pSip;
};
//会话管理线程
class sesmnger_thread : public acl::thread
{
public:
	sesmnger_thread(void *pUser)
	{
		pSip = (SipService *)pUser;
	}
	~sesmnger_thread()
	{
		pSip = NULL;
	}
protected:
	virtual void *run()
	{
		if (pSip)
			pSip->session_manager();
		delete this;
		return NULL;
	}
private:
	SipService *pSip;
};

//Kafka消费者线程
#ifdef _DBLIB_USE
class consumer_thread : public acl::thread
{
public:
	consumer_thread(msg_consume cbMsg, void *pUser)
	{
		pSip = (SipService *)pUser;
		msg_cb = cbMsg;
	}
	~consumer_thread()
	{
		pSip = NULL;
	}
	void stop()
	{
		cons.Stop();
	}
protected:
	virtual void *run()
	{
		if (pSip)
		{
			cons.Start(pSip->m_conf.kfk_brokers,pSip->m_conf.kfk_topic,pSip->m_conf.kfk_group, msg_cb,pSip);
		}
		delete this;
		return NULL;
	}
private:
	SipService *pSip;
	Consumer	cons;
	msg_consume msg_cb;

};
#endif

void __stdcall consume_msgcb(int64_t offset, char *message, size_t msglen, void *user)
{
	//acl::charset_conv conv;
	//acl::string msgout;
	//conv.convert("utf-8", "gb2312", message, msglen, &msgout);
	//printf("offset:%I64d msglen:%d\n%s\n", offset, (int)msgout.size(), msgout.c_str());

	acl::json jsonstr(message);
	acl::json_node *alarmtype = jsonstr.getFirstElementByTagName("command");
	if (!alarmtype)
	{
		return;
	}
	char szTags[128] = { 0 };
	sprintf(szTags, "imagelist/%slist", alarmtype->get_text());
	printf("报警类型:%s\n", alarmtype->get_text());
	//acl::json_node *deviceid = jsonstr.getFirstElementByTags(szTags);
	const std::vector<acl::json_node*>& jsonlist = jsonstr.getElementsByTags(szTags);
	if (jsonlist.empty())
	{
		return;
	}
	acl::json_node *child = acl_json_get_child(jsonlist[0],2);
	if (!child)
	{
		return;
	}
	acl::json_node *node = child->first_child();
	while (node)
	{
		printf("%s:%s\n", node->tag_name(), node->get_text());
		node = child->next_child();
	}
	jsonstr.reset();
}


/******************************************************************************************************************/
SipService::SipService()
{
	__sipsrv = this;
	m_running = true;
	m_conf.read();
	m_szRecvBuf = new char[SIP_RECVBUF_MAX];
	m_consumer_thd = NULL;
}

SipService::~SipService()
{
	m_running = false;
#ifdef _DBLIB_USE
	if (m_consumer_thd)
	{
		((consumer_thread *)m_consumer_thd)->stop();
		m_consumer_thd = NULL;
	}
#endif
	if (m_szRecvBuf)
	{
		delete[] m_szRecvBuf;
		m_szRecvBuf = NULL;
	}
}
//接收SIP消息
void SipService::on_read(acl::socket_stream* stream)
{
	memset(m_szRecvBuf, 0, SIP_RECVBUF_MAX);
	int nBufSize = stream->read(m_szRecvBuf, SIP_RECVBUF_MAX, false);
	if (nBufSize < 0)
	{
		m_conf.log(LOG_ERROR, "read socket error");
	}
	if (nBufSize > 0)
	{
		sip_handle_thread *handlethd = new sip_handle_thread(stream, m_szRecvBuf, nBufSize, this);
		__thdpool->run(handlethd);
	}
}
//服务进程初始化
void SipService::proc_on_init()
{
	__thdpool = new sip_thread_pool;
	
	__thdpool->set_limit(m_conf.srv_pool);
	__thdpool->start();

	sip_init(m_conf.local_code, m_conf.local_addr, m_conf.local_port);
#ifdef _DBLIB_USE
	if (m_conf.db_driver != DB_NONE)
	{
		m_db.Connect(m_conf.db_driver, m_conf.db_addr, m_conf.db_name, m_conf.db_user, m_conf.db_pwd, m_conf.db_pool);
		m_db.GetSuperiorRegister(m_conf.local_code, __regmap);
	}
	if (m_conf.kfk_brokers[0] != '\0' && m_conf.kfk_topic[0] != '\0')
	{
		printf("开启Kafka订阅线程!订阅地址:%s\n", m_conf.kfk_brokers);
		m_consumer_thd = new consumer_thread(consume_msgcb, this);
		m_consumer_thd->set_detachable(true);
		m_consumer_thd->start();
	}
#endif
	//开启注册会话管理线程
	regmnger_thread *regmnger_thd = new regmnger_thread(this);
	regmnger_thd->set_detachable(true);
	regmnger_thd->start();
	sesmnger_thread *sesmnger_thd = new sesmnger_thread(this);
	sesmnger_thd->set_detachable(true);
	sesmnger_thd->start();
}
//服务进程退出
void SipService::proc_on_exit()
{
	m_running = false;
#ifdef _DBLIB_USE
	m_db.Disconnect();
	if (m_consumer_thd)
	{
		((consumer_thread *)m_consumer_thd)->stop();
		m_consumer_thd = NULL;
	}
#endif
	if (__thdpool)
	{
		__thdpool->stop();
		delete __thdpool;
		__thdpool = NULL;
	}
	
}

void SipService::on_handle(acl::socket_stream* stream, const char *data, size_t dlen)
{
	SIP_EVENT_TYPE even_type = sip_get_event_type(data);
	switch (even_type)
	{
	case SIP_REGISTER_REQUEST:
		on_register_request(stream, data, dlen);
		break;
	case SIP_REGISTER_SUCCESS:
		on_register_success(stream, data, dlen);
		break;
	case SIP_REGISTER_FAILURE:
		on_register_failure(stream, data, dlen);
		break;
	case SIP_INVITE_REQUEST:
		on_invite_request(stream, data, dlen);
		break;
	case SIP_INVITE_PROCEEDING:
		on_invite_proceeding(stream, data, dlen);
		break;
	case SIP_INVITE_SUCCESS:
		on_invite_success(stream, data, dlen);
		break;
	case SIP_INVITE_FAILURE:
		on_invite_failure(stream, data, dlen);
		break;
	case SIP_CANCEL_REQUEST:
		on_cancel_request(stream, data, dlen);
		break;
	case SIP_CANCEL_SUCCESS:
		on_cancel_success(stream, data, dlen);
		break;
	case SIP_CANCEL_FAILURE:
		on_cancel_failure(stream, data, dlen);
		break;
	case SIP_ACK_REQUEST:
		on_ack_request(stream, data, dlen);
		break;
	case SIP_BYE_REQUEST:
		on_bye_request(stream, data, dlen);
		break;
	case SIP_BYE_SUCCESS:
		on_bye_success(stream, data, dlen);
		break;
	case SIP_BYE_FAILURE:
		on_bye_failure(stream, data, dlen);
		break;
	case SIP_INFO_REQUEST:
		on_info_request(stream, data, dlen);
		break;
	case SIP_INFO_SUCCESS:
		on_info_success(stream, data, dlen);
		break;
	case SIP_INFO_FAILURE:
		on_info_failure(stream, data, dlen);
		break;
	case SIP_SUBSCRIBE_REQUEST:
		on_subscribe_request(stream, data, dlen);
		break;
	case SIP_SUBSCRIBE_SUCCESS:
		on_subscribe_success(stream, data, dlen);
		break;
	case SIP_SUBSCRIBE_FAILURE:
		on_subscribe_failure(stream, data, dlen);
		break;
	case SIP_NOTIFY_EVENT:
		on_notify_request(stream, data, dlen);
		break;
	case SIP_NOTIFY_SUCCESS:
		on_notify_success(stream, data, dlen);
		break;
	case SIP_NOTIFY_FAILURE:
		on_notify_failure(stream, data, dlen);
		break;
	case SIP_MESSAGE_EVENT:
		on_message_request(stream, data, dlen);
		break;
	case SIP_MESSAGE_SUCCESS:
		on_message_success(stream, data, dlen);
		break;
	case SIP_MESSAGE_FAILURES:
		on_message_failure(stream, data, dlen);
		break;
	case SIP_OPTIONS_REQUEST:
		on_options_request(stream, data, dlen);
		break;
	case SIP_OPTIONS_RESPONSE:
		on_options_response(stream, data, dlen);
		break;
	default:
		break;
	}
}

void SipService::on_options_response(acl::socket_stream * stream, const char * data, size_t dlen)
{
}

void SipService::on_register_success(acl::socket_stream * stream, const char * data, size_t dlen)
{
	const char *sAddr = stream->get_peer(true);
	regmap_iter riter = __regmap.find(sAddr);
	if (riter == __regmap.end())
	{
		m_conf.log(LOG_WARN, "未找到匹配的注册请求[%s]", sAddr);
		return;
	}
	if (riter->second.expires > 0)	//注册成功
	{
		if (riter->second.online)
		{
			printf("重连[%s]成功\n", sAddr);
			//会话重连。。。
		}
		riter->second.online = true;
		riter->second.alivetime = time(NULL);
	}
	else                            //注销成功
	{
		riter->second.online = false;
		riter->second.vaild = false;
	}
}

void SipService::on_register_failure(acl::socket_stream * stream, const char * data, size_t dlen)
{
	const char *sAddr = stream->get_peer(true);
	acl::string strRealm = sip_get_www_authenticate_realm(data);
	acl::string strNonce = sip_get_www_authenticate_nonce(data);
	if (strRealm == "" || strNonce == "")
	{
		m_conf.log(LOG_WARN, "向[%s]注册失败!\n%s", sAddr, data);
		return;
	}
	regmap_iter riter = __regmap.find(sAddr);
	if (riter == __regmap.end())
	{
		m_conf.log(LOG_WARN, "未找到匹配的注册请求[%s]", sAddr);
		return;
	}
	acl::string strUser = sip_get_from_user(data);
	acl::string strUri = sip_build_msg_to(riter->second.user, riter->second.addr);
	acl::string strRes = sip_build_authorization_response(strUser.c_str(), strRealm.c_str(), riter->second.pwd, strNonce.c_str(), strUri.c_str());
	acl::string strAuth;
	strAuth.format("Digest username=\"%s\",realm=\"%s\","
		"nonce=\"%s\",uri=\"%s\","
		"response=\"%s\",algorithm=MD5",
		strUser.c_str(), strRealm.c_str(), strNonce.c_str(), strUri.c_str(), strRes.c_str());
	acl::string strCallID = sip_get_header(data, "Call-ID: ");
	acl::string strFTag = sip_get_from_tag(data);
	acl::string strReg = sip_build_msg_register(strUri.c_str(),strAuth.c_str(),2,riter->second.expires, strCallID.c_str(), strFTag.c_str());
	stream->write(strReg);
}

void SipService::on_invite_proceeding(acl::socket_stream * stream, const char * data, size_t dle)
{

}

void SipService::on_invite_success(acl::socket_stream * stream, const char * data, size_t dlen)
{
	const char *sAddr = stream->get_peer();
	acl::string strTtag = sip_get_to_tag(data);
	acl::string strCallId = sip_get_header(data, "Call-ID: ");
	sesmap_iter siter = __sesmap.find(strCallId.c_str());
	if (siter == __sesmap.end())
	{
		printf("收到[%s]200 OK:没有找到匹配的会话", sAddr);
		return;
	}
	strcpy(siter->second->ttag, strTtag.c_str());
	if (siter->second->flow < SESSION_SENDER_BYE)
		siter->second->flow = SESSION_SENDER_OK;
	acl::string strBody;
	SIP_CONTENT_TYPE nBoyeType = sip_get_body(data, strBody);
	acl::string strUser = sip_get_to_user(data);
	int nRole = sip_get_user_role(strUser.c_str());
	if (nRole == SIP_ROLE_CHANNEL)
	{
		//回复ACK
		acl::string strAck = sip_build_msg_ack(data);
		if (siter->second->flow < SESSION_SENDER_BYE)
			siter->second->flow = SESSION_SENDER_ACK;
		stream->write(strAck);
		sip_sdp_info info;
		sip_get_sdp_info(strBody.c_str(), &info);
		if (m_conf.rtp_check_ssrc)
			strcpy(siter->second->ssrc, info.y_ssrc);
		else
			memset(info.y_ssrc, 0, sizeof(info.y_ssrc));
		acl::string strDst;
		strDst.format("%s:%d", info.o_ip, info.m_port);
		media_stream_cb pCb = (media_stream_cb)siter->second->stream_cb;
		if (pCb)
			pCb(200, NULL, info.a_playload, siter->second->stream_user);
		siter->second->rtp_stream = sip_start_stream(m_conf.local_addr,siter->second->media_port,m_conf.clnt_tranfer,strDst.c_str(),pCb,siter->second->stream_user, siter->second);
	}
}

void SipService::on_invite_failure(acl::socket_stream * stream, const char * data, size_t dlen)
{
	const char *sAddr = stream->get_peer();
	acl::string strCallId = sip_get_header(data, "Call-ID: ");
	sesmap_iter siter = __sesmap.find(strCallId.c_str());
	if (siter == __sesmap.end())
	{
		printf("收到[%s]失败回应:没有找到匹配的会话", sAddr);
		return;
	}
	media_stream_cb pCb = (media_stream_cb)siter->second->stream_cb;
	if (pCb)
		pCb(sip_get_status_code(data), NULL, 0, siter->second->stream_user);
	siter->second->flow = SESSION_END;
	siter->second->mediaover = time(NULL);
}

void SipService::on_cancel_success(acl::socket_stream * stream, const char * data, size_t dlen)
{
}

void SipService::on_cancel_failure(acl::socket_stream * stream, const char * data, size_t dlen)
{
}

void SipService::on_bye_success(acl::socket_stream * stream, const char * data, size_t dlen)
{
}

void SipService::on_bye_failure(acl::socket_stream * stream, const char * data, size_t dlen)
{
}

void SipService::on_info_success(acl::socket_stream * stream, const char * data, size_t dlen)
{
}

void SipService::on_info_failure(acl::socket_stream * stream, const char * data, size_t dlen)
{
}

void SipService::on_subscribe_success(acl::socket_stream * stream, const char * data, size_t dlen)
{
}

void SipService::on_subscribe_failure(acl::socket_stream * stream, const char * data, size_t dlen)
{
}

void SipService::on_notify_success(acl::socket_stream * stream, const char * data, size_t dlen)
{
}

void SipService::on_notify_failure(acl::socket_stream * stream, const char * data, size_t dlen)
{
}

void SipService::on_message_success(acl::socket_stream * stream, const char * data, size_t dlen)
{
	if (sip_get_cseq_num(data) == SIP_CSEQ_KEEPALIVE)	//心跳成功
	{
		const char *sAddr = stream->get_peer(true);
		regmap_iter riter = __regmap.find(sAddr);
		if (riter != __regmap.end())
		{
			riter->second.alivetime = time(NULL);
		}
	}
}

void SipService::on_message_failure(acl::socket_stream * stream, const char * data, size_t dlen)
{
}

void SipService::on_msg_control_response(acl::socket_stream * stream, const char * data, size_t dlen)
{
}

void SipService::on_msg_preset_response(acl::socket_stream * stream, const char * data, size_t dlen)
{
}

void SipService::on_msg_devicestate_response(acl::socket_stream * stream, const char * data, size_t dlen)
{
}

void SipService::on_msg_catalog_response(acl::socket_stream * stream, const char * data, size_t dlen)
{
}

void SipService::on_msg_deviceinfo_response(acl::socket_stream * stream, const char * data, size_t dlen)
{
}

void SipService::on_msg_recordinfo_response(acl::socket_stream * stream, const char * data, size_t dlen)
{
	acl::string strBody;
	SIP_CONTENT_TYPE nBodyType = sip_get_body(data, strBody);
	if (nBodyType != SIP_APPLICATION_XML)
		return;
	acl::xml1 xml(strBody.c_str());
	int nSumNum = acl_xml_getElementInt(xml, "SumNum");
	acl::string strSn = acl_xml_getElementValue(xml, "SN");
	sesmap_iter siter = __msgmap.find(strSn.c_str());
	if (siter == __msgmap.end())
	{
		return;
	}
	record_info *pInfo = &siter->second->rec_info[siter->second->rec_count];
	acl::xml_node *pRecList = xml.getFirstElementByTag("RecordList");
	if (!pRecList)
		return;
	acl::xml_node *pRecItem = pRecList->first_child();
	while (pRecItem)
	{
		acl::xml_node *pItem = pRecItem->first_child();
		while (pItem)
		{
			if (strcmp(pItem->tag_name(), "FilePath") == 0)
				strcpy(pInfo->sFileName, pItem->text());
			else if (strcmp(pItem->tag_name(), "StartTime") == 0)
				strcpy(pInfo->startTime, sip_get_generaltime((char *)pItem->text()).c_str());
			else if (strcmp(pItem->tag_name(), "EndTime") == 0)
				strcpy(pInfo->startTime, sip_get_generaltime((char *)pItem->text()).c_str());
			else if (strcmp(pItem->tag_name(), "Type") == 0)
				pInfo->nType = (int)sip_get_record_type(pItem->text());
			else if (strcmp(pItem->tag_name(), "FileSize") == 0)
				pInfo->nSize = atoi(pItem->text());
			pInfo++;
			siter->second->rec_count++;
			pItem = pRecItem->next_child();
		}
		pRecItem = pRecList->next_child();
	}
	xml.reset();
	acl::string strAns = sip_build_msg_answer(data, SIP_STATUS_200);
	send_msg(stream->get_peer(true), strAns.c_str(), strAns.size());
	if (siter->second->rec_count == nSumNum)
	{
		((acl::aio_handle *)siter->second->evnt_handle)->stop();
	}
}

void SipService::on_msg_alarm_response(acl::socket_stream * stream, const char * data, size_t dlen)
{
}

void SipService::on_msg_configdownload_response(acl::socket_stream * stream, const char * data, size_t dlen)
{
}

void SipService::on_msg_broadcast_response(acl::socket_stream * stream, const char * data, size_t dlen)
{
}

void SipService::on_options_request(acl::socket_stream * stream, const char * data, size_t dlen)
{

}

void SipService::on_register_request(acl::socket_stream * stream, const char * data, size_t dlen)
{
	acl::string strContact = sip_get_header(data, "Contact: ");
	acl::string strExpires = sip_get_header(data, "Expires: ");
	int nExpires = atoi(strExpires.c_str());
	acl::string sAuthorization = sip_get_header(data, "Authorization: ");
	if (sAuthorization == "")	//未认证的注册/注销
	{
		acl::string strRealm(m_conf.local_code);
		acl::string strAuth = "";
		strAuth.format("Digest realm=\"%s\",nonce=\"%s\"", strRealm.left(10).c_str(), sip_build_nonce().c_str());
		acl::string strAnswer = sip_build_msg_answer(data, SIP_STATUS_401);
		strAnswer = sip_set_header(strAnswer.c_str(), "WWW-Authenticate: ", strAuth.c_str());
		stream->write(strAnswer);
		m_conf.log(LOG_WARN, "收到用户%s%s请求", strContact.c_str(), nExpires > 0 ? "注册" : "注销");
	}
	else                        //带认证再次注册/注销
	{
		acl::string strUsername = sip_get_authorization_username(sAuthorization.c_str());
		acl::string strRealm = sip_get_authorization_realm(sAuthorization.c_str());
		acl::string strNonce = sip_get_authorization_nonce(sAuthorization.c_str());
		acl::string strUri = sip_get_authorization_uri(sAuthorization.c_str());
		acl::string strResponse = sip_get_authorization_response(sAuthorization.c_str());
		if (strUsername == "" || strRealm == "" || strNonce == "" || strUri == "" || strResponse == "")
		{
			acl::string strAnswer = sip_build_msg_answer(data, SIP_STATUS_400);
			stream->write(strAnswer);
			m_conf.log(LOG_ERROR, "用户%s%s失败,无效的认证参数", strContact.c_str(), nExpires > 0 ? "注册" : "注销");
			return;
		}
		acl::string strRes = sip_build_authorization_response(strUsername.c_str(), strRealm.c_str(), "12345678", strNonce.c_str(), strUri.c_str());
		if (strcmp(strResponse.c_str(), strRes.c_str()) != 0)
		{
			acl::string strAnswer = sip_build_msg_answer(data, SIP_STATUS_400);
			stream->write(strAnswer);
			m_conf.log(LOG_ERROR, "用户%s%s失败,无效的认证密钥", strContact.c_str(), nExpires > 0 ? "注册" : "注销");
			return;
		}
		
		acl::string strAnswer = sip_build_msg_answer(data, SIP_STATUS_200);
		strAnswer = sip_set_header(strAnswer.c_str(), "Contact: ", strContact.c_str());
		strAnswer = sip_set_header(strAnswer.c_str(), "Date: ", sip_get_localtime().c_str());
		strAnswer = sip_set_header(strAnswer.c_str(), "Expires: ", strExpires.c_str());
		stream->write(strAnswer);

		acl::string strUser = sip_get_from_user(data);
		acl::string strAddr = sip_get_from_addr(data);
		regmap_iter riter = __regmap.find(strAddr.c_str());
		if (riter != __regmap.end())
		{
			if (nExpires == 0)
			{
				riter->second.online = false;
				riter->second.alivetime = time(NULL);
				size_t nCount = riter->second.slist->size();
				for (size_t i = 0; i < nCount; i++)
				{
					//释放该用户下有资源
				}
				m_conf.log(LOG_WARN, "用户%s注销成功", strContact.c_str());
			}
			else
			{
				riter->second.online = true;
				riter->second.alivetime = time(NULL);
			}
			return;
		}
		register_info rinfo;
		memset(&rinfo, 0, sizeof(register_info));
		strcpy(rinfo.addr, strAddr.c_str());
		rinfo.online = true;
		rinfo.alivetime = time(NULL);
		riter->second.slist = new session_list;
		__regmap[strAddr.c_str()] = rinfo;
		m_conf.log(LOG_WARN, "用户%s%s成功", strContact.c_str(), nExpires > 0 ? "注册" : "注销");
	}
}

void SipService::on_invite_request(acl::socket_stream * stream, const char * data, size_t dlen)
{
}

void SipService::on_cancel_request(acl::socket_stream * stream, const char * data, size_t dlen)
{
}

void SipService::on_ack_request(acl::socket_stream * stream, const char * data, size_t dlen)
{
}

void SipService::on_bye_request(acl::socket_stream * stream, const char * data, size_t dlen)
{
}

void SipService::on_info_request(acl::socket_stream * stream, const char * data, size_t dlen)
{
}

void SipService::on_subscribe_request(acl::socket_stream * stream, const char * data, size_t dlen)
{
	acl::string strAddr = stream->get_peer(true);
	acl::string strUser = sip_get_from_user(data);
	acl::string strCallID = sip_get_header(data, "Call-ID: ");
	int nCSeq = sip_get_cseq_num(data);
	acl::string strExpires = sip_get_header(data, "Expires: ");
	acl::string strEevent = sip_get_header(data, "Event: ");
	acl::string strBody;
	SIP_CONTENT_TYPE nBodyType =  sip_get_body(data, strBody);
	if (nBodyType != SIP_APPLICATION_XML)
	{
		acl::string strAnswer = sip_build_msg_answer(data, SIP_STATUS_400);
		stream->write(strAnswer);
		return;
	}
	acl::xml1 xml(strBody.c_str());
	acl::string strCmdType = acl_xml_getElementValue(xml, "CmdType");
	acl::string strSN = acl_xml_getElementValue(xml, "SN");
	acl::string strDevice = acl_xml_getElementValue(xml, "DeviceID");
	int nAlarmMethod = acl_xml_getElementInt(xml, "AlarmMethod");
	int nAlarmType = acl_xml_getElementInt(xml, "AlarmType");
	acl::string strStartTime = acl_xml_getElementValue(xml, "StartTime");
	acl::string strEndTime = acl_xml_getElementValue(xml, "EndTime");
	xml.reset();
	//判断有没镜头权限


	acl::string strAnswer = sip_build_msg_answer(data, SIP_STATUS_200);
	strAnswer = sip_set_header(strAnswer.c_str(), "Expires: ", strExpires.c_str());
	strAnswer = sip_set_header(strAnswer.c_str(), "Event: ", strEevent.c_str());
	acl::string strAnsBody;
	strAnsBody.format(
		"<?xml version=\"1.0\"?>%s"
		"<Response>%s"
		"<CmdType>Alarm</CmdType>%s"
		"<SN>%s</SN>%s"
		"<DeviceID>%s</DeviceID>%s"
		"<Result>OK</Result>%s"
		"</Response>%s", 
		Line, Line, Line, strSN.c_str(), Line, strDevice.c_str(), Line, Line, Line);
	strAnswer = sip_set_body(strAnswer.c_str(), strAnsBody.c_str(), nBodyType);
	stream->write(strAnswer);

	if (atoi(strExpires.c_str()) == 0)	//取消订阅
	{
		//释放订阅
		return;
	}
	if (strCmdType == "Alarm")			//报警订阅
	{
		devmap_iter diter = __devmap.find(strDevice.c_str());
		if (diter != __devmap.end())
		{
			bool bFnd = false;
			for (size_t i = 0; i < diter->second->size(); i++)
			{
				if (strcmp(strUser.c_str(), diter->second->at(i).c_str()) == 0)
				{
					//重复订阅
					bFnd = true;
					break;
				}
			}
			if (!bFnd)
			{
				diter->second->push_back(strUser);
			}
		}
		else
		{
			__devmap[strDevice.c_str()] = new register_list;
			__devmap[strDevice.c_str()]->push_back(strUser);
		}
	}
	else if (strCmdType == "Catalog")	//目录订阅
	{
		//创建线程
	}
	session_info *pSession = new session_info;
	memset(pSession, 0, sizeof(session_info));
	strcpy(pSession->addr, strAddr.c_str());
	strcpy(pSession->deviceid, strDevice.c_str());
	strcpy(pSession->callid, strCallID.c_str());
	strcpy(pSession->sn, strSN.c_str());
	strcpy(pSession->starttime, strStartTime.c_str());
	strcpy(pSession->endtime, strEndTime.c_str());
	pSession->cseq = nCSeq;
	pSession->alarm_method = nAlarmMethod;
	pSession->alarm_type = nAlarmType;
	__sublist.push_back(pSession);
	__regmap[strDevice.c_str()].slist->push_back(pSession);

}

void SipService::on_notify_request(acl::socket_stream * stream, const char * data, size_t dlen)
{

}

void SipService::on_message_request(acl::socket_stream * stream, const char * data, size_t dlen)
{
	SIP_MESSAGE_TYPE msg_type = sip_get_message_type(data);
	switch (msg_type)
	{
	case SIP_CONTROL_PTZCMD:
		on_msg_ptzcmd_request(stream, data, dlen);
		break;
	case SIP_CONTROL_TELEBOOT:
		on_msg_ptzcmd_request(stream, data, dlen);
		break;
	case SIP_CONTROL_RECORDCMD:
		on_msg_recordcmd_request(stream, data, dlen);
		break;
	case SIP_CONTROL_GUARDCMD:
		on_msg_guardcmd_request(stream, data, dlen);
		break;
	case SIP_CONTROL_ALARMCMD:
		on_msg_alarmcmd_request(stream, data, dlen);
		break;
	case SIP_CONTROL_IFAMECMD:
		on_msg_ifamecmd_request(stream, data, dlen);
		break;
	case SIP_CONTROL_DRAGZOOMIN:
		on_msg_dragzoomin_request(stream, data, dlen);
		break;
	case SIP_CONTROL_DRAGZOOMOUT:
		on_msg_dragzoomout_request(stream, data, dlen);
		break;
	case SIP_CONTROL_HOMEPOSITION:
		on_msg_homeposition_request(stream, data, dlen);
		break;
	case SIP_CONTROL_CONFIG:
		on_msg_config_request(stream, data, dlen);
		break;
	case SIP_RESPONSE_CONTROL:
		on_msg_control_response(stream, data, dlen);
		break;
	case SIP_QUERY_PRESETQUERY:
		on_msg_preset_request(stream, data, dlen);
		break;
	case SIP_RESPONSE_PRESETQUERY:
		on_msg_preset_response(stream, data, dlen);
		break;
	case SIP_QUERY_DEVICESTATUS:
		on_msg_devicestate_request(stream, data, dlen);
		break;
	case SIP_RESPONSE_DEVICESTATUS:
		on_msg_devicestate_response(stream, data, dlen);
		break;
	case SIP_QUERY_CATALOG:
		on_msg_catalog_request(stream, data, dlen);
		break;
	case SIP_RESPONSE_CATALOG:
		on_msg_catalog_response(stream, data, dlen);
		break;
	case SIP_QUERY_DEVICEINFO:
		on_msg_deviceinfo_request(stream, data, dlen);
		break;
	case SIP_RESPONSE_DEVICEINFO:
		on_msg_deviceinfo_response(stream, data, dlen);
		break;
	case SIP_QUERY_RECORDINFO:
		on_msg_recordinfo_request(stream, data, dlen);
		break;
	case SIP_RESPONSE_RECORDINFO:
		on_msg_recordinfo_response(stream, data, dlen);
		break;
	case SIP_QUERY_ALARM:
		on_msg_alarm_request(stream, data, dlen);
		break;
	case SIP_RESPONSE_QUERY_ALARM:
		on_msg_alarm_response(stream, data, dlen);
		break;
	case SIP_QUERY_CONFIGDOWNLOAD:
		on_msg_configdownload_request(stream, data, dlen);
		break;
	case SIP_RESPONSE_CONFIGDOWNLOAD:
		on_msg_configdownload_response(stream, data, dlen);
		break;
	case SIP_QUERY_MOBILEPOSITION:
		on_msg_mobileposition_request(stream, data, dlen);
		break;
	case SIP_NOTIFY_MOBILEPOSITION:
		on_msg_mobileposition_notify(stream, data, dlen);
		break;
	case SIP_NOTIFY_KEEPALIVE:
		on_msg_keepalive_notify(stream, data, dlen);
		break;
	case SIP_NOTIFY_MEDIASTATUS:
		on_msg_mediastatus_notify(stream, data, dlen);
		break;
	case SIP_NOTIFY_ALARM:
		on_msg_alarm_notify(stream, data, dlen);
		break;
	case SIP_NOTIFY_BROADCAST:
		on_msg_broadcast_request(stream, data, dlen);
		break;
	case SIP_RESPONSE_BROADCAST:
		on_msg_broadcast_response(stream, data, dlen);
		break;
	default:
		break;
	}
}

void SipService::on_msg_ptzcmd_request(acl::socket_stream * stream, const char * data, size_t dlen)
{
}

void SipService::on_msg_teleboot_request(acl::socket_stream * stream, const char * data, size_t dlen)
{
}

void SipService::on_msg_recordcmd_request(acl::socket_stream * stream, const char * data, size_t dlen)
{
}

void SipService::on_msg_guardcmd_request(acl::socket_stream * stream, const char * data, size_t dlen)
{
}

void SipService::on_msg_alarmcmd_request(acl::socket_stream * stream, const char * data, size_t dlen)
{
}

void SipService::on_msg_ifamecmd_request(acl::socket_stream * stream, const char * data, size_t dlen)
{
}

void SipService::on_msg_dragzoomin_request(acl::socket_stream * stream, const char * data, size_t dlen)
{
}

void SipService::on_msg_dragzoomout_request(acl::socket_stream * stream, const char * data, size_t dlen)
{
}

void SipService::on_msg_homeposition_request(acl::socket_stream * stream, const char * data, size_t dlen)
{
}

void SipService::on_msg_config_request(acl::socket_stream * stream, const char * data, size_t dlen)
{
}

void SipService::on_msg_preset_request(acl::socket_stream * stream, const char * data, size_t dlen)
{
}

void SipService::on_msg_devicestate_request(acl::socket_stream * stream, const char * data, size_t dlen)
{
}

void SipService::on_msg_catalog_request(acl::socket_stream * stream, const char * data, size_t dlen)
{
}

void SipService::on_msg_deviceinfo_request(acl::socket_stream * stream, const char * data, size_t dlen)
{
}

void SipService::on_msg_recordinfo_request(acl::socket_stream * stream, const char * data, size_t dlen)
{
}

void SipService::on_msg_alarm_request(acl::socket_stream * stream, const char * data, size_t dlen)
{
}

void SipService::on_msg_configdownload_request(acl::socket_stream * stream, const char * data, size_t dlen)
{
}

void SipService::on_msg_mobileposition_request(acl::socket_stream * stream, const char * data, size_t dlen)
{
}

void SipService::on_msg_mobileposition_notify(acl::socket_stream * stream, const char * data, size_t dlen)
{
}

void SipService::on_msg_keepalive_notify(acl::socket_stream * stream, const char * data, size_t dlen)
{
	acl::string strUser = sip_get_from_user(data);
	regmap_iter riter = __regmap.find(strUser.c_str());
	if (riter != __regmap.end())
	{
		if (riter->second.online)
		{
			riter->second.alivetime = time(NULL);
			acl::string strAnswer = sip_build_msg_answer(data, SIP_STATUS_200);
			stream->write(strAnswer);
		}
		else
		{
			acl::string strAnswer = sip_build_msg_answer(data, SIP_STATUS_400);
			stream->write(strAnswer);
		}
	}
	else
	{
		acl::string strAnswer = sip_build_msg_answer(data, SIP_STATUS_400);
		stream->write(strAnswer);
	}
}

void SipService::on_msg_mediastatus_notify(acl::socket_stream * stream, const char * data, size_t dlen)
{
			
}

void SipService::on_msg_alarm_notify(acl::socket_stream * stream, const char * data, size_t dlen)
{

}

void SipService::on_msg_broadcast_request(acl::socket_stream * stream, const char * data, size_t dlen)
{

}

void SipService::register_manager()
{
	while (m_running)
	{
		regmap_iter riter = __regmap.begin();
		while (riter != __regmap.end())
		{
			time_t now = time(NULL);
			if (riter->second.role == SIP_ROLE_SUPERIOR)	//上级管理
			{
				if (riter->second.vaild == 0)	//失效
				{
					//失效处理
					riter = __regmap.erase(riter);
					continue;
				}
				if (now - riter->second.alivetime > SIP_ALIVETIMEOUT)
				{
					//注册
					acl::string strTo = sip_build_msg_to(riter->second.user, riter->second.addr);
					acl::string strReg = sip_build_msg_register(strTo.c_str(), NULL, 1, 3600);
					int nSendReg = 1;
					while (!send_msg(riter->second.addr, strReg.c_str(), strReg.size()))
					{
						m_conf.log(LOG_ERROR, "regist is false try:%d", nSendReg);
						if (nSendReg >= 3)
							break;
						sleep(1);
						nSendReg++;
					}
					riter->second.alivetime = time(NULL);
				}
				if (now - riter->second.heartbeat > SIP_ALIVETIME)
				{
					//心跳
					if (riter->second.online)
					{
						acl::string strTo = sip_build_msg_to(riter->second.user, riter->second.addr);
						acl::string strMsg = sip_build_msg_keepalive(strTo.c_str());
						send_msg(riter->second.addr, strMsg.c_str(), strMsg.size());
						riter->second.heartbeat = time(NULL);
					}
				}
			}
			else if (riter->second.role == SIP_ROLE_LOWER)	//下级管理
			{
				if (now - riter->second.alivetime > SIP_ALIVETIME * 2)
				{
					//置为下线
					//失效处理
					riter->second.online = false;
					riter->second.vaild = 0;
				}
			}
			else if (riter->second.role == SIP_ROLE_CLIENT) //客户端管理
			{
				if (now - riter->second.alivetime > SIP_ALIVETIME)
				{
					//失效处理
					riter = __regmap.erase(riter);
				}
			}
			riter++;
		}
		sleep(1);
	}
}

void SipService::register_slist_erase(const char * addr, const char * callid)
{
	regmap_iter riter = __regmap.find(addr);
	if (riter == __regmap.end())
	{
		seslist_iter slter = riter->second.slist->begin();
		while (slter != riter->second.slist->end())
		{
			if (strcmp((*slter)->callid, callid) == 0)
			{
				delete (*slter);
				(*slter) = NULL;
				riter->second.slist->erase(slter);
				break;
			}
		}
	}
}

void SipService::session_manager()
{
	while (m_running)
	{
		sesmap_iter siter = __sesmap.begin();
		while (siter != __sesmap.end())
		{
			time_t now = time(NULL);
			if (siter->second->mediaover > 0 && now - siter->second->mediaover >= SIP_SESSIONOVER)
			{
				acl::string strAddr = siter->second->addr;
				acl::string strCallId = siter->second->callid;
				if (siter->second->flow < SESSION_SENDER_BYE)
				{
					send_bye_by_cid(siter->second->callid);
				}
				sip_free_media_port(siter->second->media_port);
				siter->second = NULL;
				siter = __sesmap.erase(siter);
				register_slist_erase(strAddr.c_str(), strCallId.c_str());
			}
			else
				siter++;	
		}
		sleep(1);
	}
}

bool SipService::send_msg(const char * addr, const char * msg, size_t mlen)
{
	std::vector<acl::socket_stream *> streams = get_sstreams();
	if (streams.size() == 0)
	{
		m_conf.log(LOG_ERROR, "socket is null");
		return false;
	}
	streams[0]->set_peer(addr);
	if (streams[0]->write(msg, mlen) == -1)
	{
		return false;
	}
	return true;
}

void SipService::send_register(const char * ip, int port, const char * user, const char * pwd, int expires)
{
	char szAddr[32] = { 0 };
	sprintf(szAddr, "%s:%d", ip, port);

	regmap_iter riter = __regmap.find(szAddr);
	if (riter == __regmap.end())
	{
		register_info rinfo;
		memset(&rinfo, 0, sizeof(register_info));
		strcpy(rinfo.addr, szAddr);
		strcpy(rinfo.user, user);
		strcpy(rinfo.pwd, pwd);
		rinfo.role = SIP_ROLE_SUPERIOR;
		rinfo.expires = expires;
		rinfo.tranfer = m_conf.clnt_tranfer;
		rinfo.online = false;
		rinfo.vaild = true;
		rinfo.slist = new session_list;
		__regmap.insert(register_map::value_type(szAddr, rinfo));
	}
}

int SipService::send_invite(const char * addr, int type, char * deviceid, char *terminalid, char *starttime, char *endtime, media_stream_cb stream_cb, void *user)
{
	for (size_t i = 0; i < 3; i++)
	{
		regmap_iter riter = __regmap.find(addr);
		if (riter != __regmap.end())
		{
			if (riter->second.online)
			{
				acl::string strTo = sip_build_msg_to(deviceid, addr);
				acl::string strSsrc = sip_build_sdp_ssrc(SIP_INVITE_TYPE(type));
				acl::string strSub = sip_build_msg_subject(deviceid, strSsrc.c_str(), terminalid);
				acl::string strCallId = sip_build_msg_call_id();
				acl::string strFtag = sip_build_randnum();
				int nCseq = 20;
				acl::string strInvite = sip_build_msg_invite(strTo.c_str(), strSub.c_str(), nCseq, strCallId.c_str(), strFtag.c_str());
				
				int nMediaPort = sip_get_media_port(m_conf.rtp_port);
				acl::string strTime = "0 0";
				if (type == SIP_INVITE_PLAYBACK || type == SIP_INVITE_DOWNLOAD)
				{
					strTime = sip_build_sdp_time(starttime, endtime);
				}
				acl::string strSdp = sip_build_msg_sdp(m_conf.local_code, deviceid, strTime.c_str(), m_conf.local_addr, nMediaPort, type, SIP_RECVONLY, m_conf.clnt_tranfer);
				strInvite = sip_set_body(strInvite.c_str(), strSdp.c_str(), SIP_APPLICATION_SDP);
				if (send_msg(addr, strInvite.c_str(), strInvite.size()))
				{
					session_info *pInfo = new session_info;
					memset(pInfo, 0, sizeof(session_info));
					pInfo->invite_type = type;
					pInfo->cseq = nCseq;
					pInfo->media_port = nMediaPort;
					strcpy(pInfo->addr, addr);
					strcpy(pInfo->callid, strCallId.c_str());
					strcpy(pInfo->ftag, strFtag.c_str());
					strcpy(pInfo->deviceid, deviceid);
					if (terminalid)
						strcpy(pInfo->terminalid, terminalid);
					if (starttime)
						strcpy(pInfo->starttime, starttime);
					if (endtime)
						strcpy(pInfo->endtime, endtime);
					if (stream_cb)
						pInfo->stream_cb = stream_cb;
					if (user)
						pInfo->stream_user = user;
					pInfo->flow = SESSION_RECVER_REQ;
					__sesmap[strCallId.c_str()] = pInfo;
					riter->second.slist->push_back(pInfo);
					return atoi(strCallId.c_str());
				}
			}
		}
		sleep(1);
	}
	m_conf.log(LOG_WARN, "注册没有成功!\n");
	return 0;
}

void SipService::send_bye(int invite_cid)
{
	acl::string strCallId = sip_build_msg_call_id(invite_cid);
	send_bye_by_cid(strCallId.c_str());
}

void SipService::send_bye_by_cid(const char * cid)
{
	sesmap_iter siter = __sesmap.find(cid);
	if (siter != __sesmap.end())
	{
		sip_stop_stream(siter->second->rtp_stream);
		acl::string strAddr = siter->second->addr;
		acl::string strTo = sip_build_msg_to(siter->second->deviceid, siter->second->addr);
		acl::string strBye = sip_build_msg_bye(strTo.c_str(), siter->second->cseq + 1, cid, siter->second->ftag, siter->second->ttag);
		if (send_msg(strAddr.c_str(), strBye.c_str(), strBye.size()))
		{
			siter->second->flow = SESSION_SENDER_BYE;
			//sip_free_media_port(siter->second->media_port);
			//siter->second = NULL;
			//__sesmap.erase(siter);
			//register_slist_erase(strAddr.c_str(), strCallId.c_str());
		}
		siter->second->mediaover = time(NULL);
	}
}

void SipService::send_ptzcmd(const char * addr, char * deviceid, unsigned char cmd, unsigned char param1, unsigned short param2, SIP_PTZ_RECT *param)
{
	int nSwitch = 0;
	char szPtzcmd[17] = { 0 };
	unsigned char szBit[8] = { 0 };
	szBit[0] = 0xA5;
	szBit[1] = 0x0F;
	szBit[2] = 0x01;
	szBit[3] = cmd;
	switch (cmd)
	{
	case SIP_PTZCMD_STOP:
		break;
	case SIP_PTZCMD_UP:
	case SIP_PTZCMD_DOWN:
		szBit[5] = param1 * 32 - 1;
		break;
	case SIP_PTZCMD_LEFT:
	case SIP_PTZCMD_RIGHT:
		szBit[4] = param1 * 32 - 1;
		break;
	case SIP_PTZCMD_LU:
	case SIP_PTZCMD_LD:;
	case SIP_PTZCMD_RU:
	case SIP_PTZCMD_RD:
		szBit[4] = param1 * 32 - 1;
		szBit[5] = param1 * 32 - 1;
		break;
	case SIP_PTZCMD_ZOOM_IN:
	case SIP_PTZCMD_ZOOM_OUT:
		szBit[6] = param1 * 32 - 1;
		break;
	case SIP_PTZCMD_FI_IRIS_IN:
	case SIP_PTZCMD_FI_IRIS_OUT:
		szBit[5] = param1 * 32 - 1;
		break;
	case SIP_PTZCMD_FI_FOCUS_IN:
	case SIP_PTZCMD_FI_FOCUS_OUT:
		szBit[4] = param1 * 32 - 1;
		break;
	case SIP_PTZCMD_SET:
	case SIP_PTZCMD_GOTO:
	case SIP_PTZCMD_DELETE:
		szBit[5] = param1;
		break;
	case SIP_PTZCMD_CRUISE_ADD:
	case SIP_PTZCMD_CRUISE_DEL:
		szBit[5] = param1;
		szBit[6] = (unsigned char)param2;
		break;
	case SIP_PTZCMD_CRUISE_SPEED:
	case SIP_PTZCMD_CRUISE_DTIME:
		szBit[5] = param1;
		szBit[6] = (unsigned char)param2;
		szBit[7] = param2 >> 12;
		break;
	case SIP_PTZCMD_CRUISE_RUN:
		szBit[5] = param1;
		break;
	case SIP_PTZCMD_AUTO_RUN:
		szBit[5] = param1;
		szBit[6] = (unsigned char)param2;	//0 开始 1 往左 2 往右
		break;
	case SIP_PTZCMD_AUTO_SPEED:
		szBit[5] = param1;
		szBit[6] = (unsigned char)param2;
		szBit[7] = param2 >> 12;
		break;
	case SIP_PTZCMD_AUXIOPEN:
	case SIP_PTZCMD_AUXICLOSE:
		szBit[5] = 0x01;
		break;
	case SIP_PTZCMD_LOCK:
	case SIP_PTZCMD_UNLOCK:
		break;
	case SIP_PTZCMD_DRAGZOOM_IN:
		strcpy(szPtzcmd, "DragZoomIn");
		break;
	case SIP_PTZCMD_DRAGZOOM_OUT:
		strcpy(szPtzcmd, "DragZoomOut");
		break;
	case SIP_PTZCMD_INITIAL:
		nSwitch = 1;
		break;
	case SIP_PTZCMD_UNINITIAL:
		nSwitch = 0;
		break;
	default:
		return;
	}
	acl::string strTo = sip_build_msg_to(deviceid, addr);
	acl::string strMsg = sip_build_msg_request("MESSAGE", NULL, NULL, 20, NULL, strTo.c_str(), NULL, NULL);
	acl::string strBody;
	if (cmd == SIP_PTZCMD_DRAGZOOM_IN || cmd == SIP_PTZCMD_DRAGZOOM_OUT)
	{
		strBody.format(
			"<?xml version=\"1.0\"?>%s"
			"<Control>%s"
			"<CmdType>DeviceControl</CmdType>%s"
			"<SN>%d</SN>%s"
			"<DeviceID>%s</DeviceID>%s"
			"<%s>%s"
			"<Length>%d</Length>%s"
			"<Width>%d</Width>%s"
			"<MidPointX>%d</MidPointX>%s"
			"<MidPointY>%d</MidPointY>%s"
			"<LengthX>%d</LengthX>%s"
			"<LengthY>%d</LengthY>%s"
			"</%s>%s"
			"</Control>%s",
			Line, Line, Line, sip_build_randsn(), Line, deviceid, Line, szPtzcmd, Line, param->height, Line, param->width, Line, 
			param->left, Line, param->top, Line, param->right, Line, param->bottom, Line, szPtzcmd, Line, Line);
	}
	else if (cmd == SIP_PTZCMD_INITIAL || cmd == SIP_PTZCMD_UNINITIAL)
	{
		strBody.format(
			"<?xml version=\"1.0\"?>%s"
			"<Control>%s"
			"<CmdType>DeviceControl</CmdType>%s"
			"<SN>%d</SN>%s"
			"<DeviceID>%s</DeviceID>%s"
			"<HomePosition>%s"
			"<Enable>%d</Enable>%s"
			"<ResetTime>%d</ResetTime>%s"
			"<PresetIndex>%d</PresetIndex>%s"
			"</HomePosition>%s"
			"</Control>%s",
			Line, Line, Line, sip_build_randsn(), Line, deviceid, Line, Line, nSwitch, Line,
			param2, Line, param1, Line, Line, Line);
	}
	else
	{
		szBit[7] = (szBit[0] + szBit[1] + szBit[2] + szBit[3] + szBit[4] + szBit[5] + szBit[6]) % 0x100;
		sprintf(szPtzcmd, "A50F%02X%02X%02X%02X%02X%02X", szBit[2], szBit[3], szBit[4], szBit[5], szBit[6], szBit[7]);
		strBody.format(
			"<?xml version=\"1.0\"?>%s"
			"<Control>%s"
			"<CmdType>DeviceControl</CmdType>%s"
			"<SN>%d</SN>%s"
			"<DeviceID>%s</DeviceID>%s"
			"<PTZCmd>%s</PTZCmd>%s"
			"<Info>%s"
			"<ControlPriority>5</ControlPriority>%s"
			"</Info>%s"
			"</Control>%s",
			Line, Line, Line, sip_build_randsn(), Line, deviceid, Line, szPtzcmd, Line, Line, Line, Line, Line);
	}
	strMsg = sip_set_body(strMsg.c_str(), strBody.c_str(), SIP_APPLICATION_XML);
	send_msg(addr, strMsg.c_str(), strMsg.size());
}

int SipService::send_recordinfo(const char * addr, char * deviceid, int rectype, char * starttime, char * endtime, record_info *recordinfo, int recordsize)
{
	acl::string strRecId = deviceid;
	regmap_iter riter = __regmap.find(addr);
	if (riter != __regmap.end())
	{
		strRecId = riter->second.user;
	}
	acl::string strRecType = "all";
	switch (rectype)
	{
	case SIP_RECORDTYPE_TIME:
		strRecType = "time";
		break;
	case SIP_RECORDTYPE_MOVE:
		strRecType = "move";
		break;
	case SIP_RECORDTYPE_ALARM:
		strRecType = "alarm";
		break;
	case SIP_RECORDTYPE_MANUAL:
		strRecType = "manual";
		break;
	default:
		break;
	}
	acl::string strSn;
	strSn.format("%d", sip_build_randsn());
	acl::string strStartTime = sip_get_formattime(starttime);
	acl::string strEndTime = sip_get_formattime(endtime);
	acl::string strTo = sip_build_msg_to(deviceid, addr);
	acl::string strCallId = sip_build_msg_call_id();
	acl::string strMsg = sip_build_msg_request("MESSAGE", NULL, strCallId.c_str(), 20, NULL, strTo.c_str(), NULL, NULL);
	acl::string strBody;
	strBody.format(
		"<?xml version=\"1.0\"?>%s"
		"<Query>%s"
		"<CmdType>RecordInfo</CmdType>%s"
		"<SN>%s</SN>%s"
		"<DeviceID>%s</DeviceID>%s"
		"<StartTime>%s</StartTime>%s"
		"<EndTime>%s</EndTime>%s"
		"<Secrecy>0</Secrecy>%s"
		"<Type>%s</Type>%s"
		"<RecorderID>%s</RecorderID>%s"
		"</Query>%s",
		Line, Line, Line, strSn.c_str(), Line, deviceid, Line,
		strStartTime.c_str(), Line, strEndTime.c_str(), Line, Line, strRecType.c_str(), Line,
		strRecId.c_str(), Line, Line);
	strMsg = sip_set_body(strMsg, strBody, SIP_APPLICATION_XML);
	if (send_msg(addr, strMsg.c_str(), strMsg.size()))
	{
		session_info *pInfo = new session_info;
		memset(pInfo, 0, sizeof(session_info));
		pInfo->rec_info = recordinfo;
		pInfo->rec_count = 0;
		acl::aio_handle *pHandle = new acl::aio_handle;
		pInfo->evnt_handle = pHandle;
		__msgmap[strSn.c_str()] = pInfo;
		pHandle->set_delay_sec(5);
		pHandle->check();
		sesmap_iter siter = __msgmap.find(strSn.c_str());
		if (siter == __msgmap.end())
			return 0;
		int nRecordCount = siter->second->rec_count;
		delete pHandle;
		delete siter->second;
		siter->second = NULL;
		__msgmap.erase(siter);
		return nRecordCount;
	}
	return 0;
}

