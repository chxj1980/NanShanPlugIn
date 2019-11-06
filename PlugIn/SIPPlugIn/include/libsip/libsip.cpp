#include "libsip.h"

//#include "acl_cpp/lib_acl.hpp"
//#include "lib_acl.h"


static char sipuser[21];
static char sipaddr[17];
static int	sipport;


bool msg_is_request(const char *msg, const char *head)
{
	if (strncasecmp(msg, head, strlen(head)) == 0)
		return true;
	return false;
}
int msg_is_response(const char *msg)
{
	const char *head = "SIP/2.0 ";
	size_t hlen = strlen(head);
	acl::string strMsg = msg;
	if (strMsg.ncompare(head, hlen) == 0)
	{
		acl::string strStatus;
		if (strMsg.substr(strStatus, hlen, 3) > 0)
			return atoi(strStatus.c_str());
	}
	return 0;
}
bool msg_is_status_1xx(const char *msg)
{
	int status = msg_is_response(msg);
	if (status >= 100 && status < 200)
		return true;
	return false;
}
bool msg_is_status_2xx(const char *msg)
{
	int status = msg_is_response(msg);
	if (status >= 200 && status < 300)
		return true;
	return false;
}
bool msg_is_status_3xx(const char *msg)
{
	int status = msg_is_response(msg);
	if (status >= 300 && status < 400)
		return true;
	return false;
}
bool msg_is_status_4xx(const char *msg)
{
	int status = msg_is_response(msg);
	if (status >= 400 && status < 500)
		return true;
	return false;
}
bool msg_is_status_5xx(const char *msg)
{
	int status = msg_is_response(msg);
	if (status >= 500 && status < 600)
		return true;
	return false;
}
bool msg_is_register(const char *msg)
{
	return msg_is_request(msg, "REGISTER");
}
bool msg_is_invite(const char *msg)
{
	return msg_is_request(msg, "INVITE");
}
bool msg_is_ack(const char *msg)
{
	return msg_is_request(msg, "ACK");
}
bool msg_is_bye(const char *msg)
{
	return msg_is_request(msg, "BYE");
}
bool msg_is_cancel(const char *msg)
{
	return msg_is_request(msg, "CANCEL");
}
bool msg_is_info(const char *msg)
{
	return msg_is_request(msg, "INFO");
}
bool msg_is_subscribe(const char *msg)
{
	return msg_is_request(msg, "SUBSCRIBE");
}
bool msg_is_notify(const char *msg)
{
	return msg_is_request(msg, "NOTIFY");
}
bool msg_is_message(const char *msg)
{
	return msg_is_request(msg, "MESSAGE");
}
bool msg_is_options(const char *msg)
{
	return msg_is_request(msg, "OPTIONS");
}

void sip_init(const char * sipcode, const char * ip, int port)
{
	memset(sipuser, 0, sizeof(sipuser));
	memset(sipaddr, 0, sizeof(sipaddr));
	strcpy(sipuser, sipcode);
	strcpy(sipaddr, ip);
	sipport = port;
}

time_t sip_get_totalseconds(char * time)
{
	int year, month, day, hour, min, sec;
	if (strlen(time) == 19)
	{
		time[10] = ' ';
		sscanf(time, "%04d-%02d-%02d %02d:%02d:%02d", &year, &month, &day, &hour, &min, &sec);
	}
	else if (strlen(time) == 14)
		sscanf(time, "%04d%02d%02d%02d%02d%02d", &year, &month, &day, &hour, &min, &sec);
	else
		return 0;
	tm tinfo;
	tinfo.tm_year = year - 1900;
	tinfo.tm_mon = month - 1;
	tinfo.tm_mday = day;
	tinfo.tm_hour = hour;
	tinfo.tm_min = min;
	tinfo.tm_sec = sec;
	tinfo.tm_isdst = 0;
	return mktime(&tinfo);
}

acl::string sip_get_formattime(char * time)
{
	int year, month, day, hour, min, sec;
	if (strlen(time) == 19)
		sscanf(time, "%04d-%02d-%02d %02d:%02d:%02d", &year, &month, &day, &hour, &min, &sec);
	else if (strlen(time) == 14)
		sscanf(time, "%04d%02d%02d%02d%02d%02d", &year, &month, &day, &hour, &min, &sec);
	else
		return "";
	acl::string strTime;
	strTime.format("%04d-%02d-%02dT%02d:%02d:%02d", year, month, day, hour, min, sec);
	return strTime;
}

acl::string sip_get_generaltime(char * time)
{
	acl::string strTime = time;
	return strTime.replace('T', ' ');
}

int sip_build_randsn()
{
	acl::string strSN;
	sip_build_randnum().substr(strSN, 0, 4);
	return atoi(strSN.c_str());
}

acl::string sip_build_randnum()
{
	static bool bSrand = false;
	static int  nRid = 0;
	unsigned int nNum = 0;
	unsigned int nOp = 100000000;
	if (!bSrand)
	{
		srand((unsigned int)time(NULL));
		bSrand = true;
	}
	acl::string strNum = "";
	strNum.format("%u", ((rand() % 10 + 1)*nOp + (rand() % nOp)*(rand() % nOp) % nOp)+nRid++);
	if (nRid >= 10000000)
		nRid = 0;
	return strNum;
}

acl::string sip_build_sdp_ssrc(SIP_INVITE_TYPE type)
{
	acl::string strUser(sipuser+3,5);
	acl::string strSsrc;
	strSsrc.format("%d%s%d", type == SIP_INVITE_PLAY ? 0 : 1, strUser.c_str(), sip_build_randsn());
	return strSsrc;
}

acl::string sip_build_nonce()
{
	char szOutNum[33] = { 0 };
	acl::string strNum = sip_build_randnum();
	acl::md5::md5_string(strNum.c_str(), strNum.size(), NULL, 0, szOutNum, sizeof(szOutNum));
	acl::string strOutNum = szOutNum;
	return strOutNum.left(16);
}

acl::string sip_build_sdp_time(const char * starttime, const char * endtime)
{
	acl::string strTime;
	strTime.format("%llu %llu", sip_get_totalseconds((char *)starttime), sip_get_totalseconds((char *)endtime));
	return strTime;
}

acl::string sip_build_authorization_response(const char * username, const char * realm, const char * password, const char * nonce, const char * uri)
{
	acl::string strAuth1,strAuth2,strAuth3;
	strAuth1.format("%s:%s:%s", username, realm, password);
	strAuth2.format("REGISTER:%s", uri);
	char szAuth1[33] = { 0 };
	acl::md5::md5_string(strAuth1.c_str(), strAuth1.size(), NULL, 0, szAuth1, sizeof(szAuth1));
	char szAuth2[33] = { 0 };
	acl::md5::md5_string(strAuth2.c_str(), strAuth2.size(), NULL, 0, szAuth2, sizeof(szAuth2));
	strAuth3.format("%s:%s:%s", szAuth1, nonce, szAuth2);
	char szRes[33] = { 0 };
	acl::md5::md5_string(strAuth3.c_str(), strAuth3.size(), NULL, 0, szRes, sizeof(szRes));
	return acl::string(szRes);
}

acl::string sip_build_msg_from()
{
	acl::string strFrom;
	strFrom.format("sip:%s@%s:%d", sipuser, sipaddr, sipport);
	return strFrom;
}

acl::string sip_build_msg_to(const char * user, const char * dst)
{
	acl::string strTo;
	strTo.format("sip:%s@%s", user, dst);
	return strTo;
}

acl::string sip_build_msg_call_id(unsigned int id)
{
	acl::string strCallId;
	if (id > 0)
	{
		strCallId.format("%u@%s", id, sipaddr);
	}
	else
		strCallId.format("%s@%s", sip_build_randnum().c_str(), sipaddr);
	return strCallId;
}

acl::string sip_build_msg_subject(const char * deviceid, const char * ssrc, const char * terminalid)
{
	acl::string strMsg;
	strMsg.format("%s:%s,%s:%s", deviceid, ssrc, sipuser, terminalid? terminalid:"0");
	return strMsg;
}

acl::string sip_build_msg_request(const char * method, const char * dst, const char * callid, int cseq, const char * from, const char * to, const char * ftag, const char * ttag)
{
	acl::string strReq;
	acl::string strDst = dst;
	acl::string strCallId = callid;
	acl::string strFrom = from;
	acl::string strTo = to;
	acl::string strFTag = ftag;
	if (dst == NULL || dst[0] == '\0')
	{
		strDst = to;
	}
	if (callid == NULL || callid[0] == '\0')
	{
		strCallId = sip_build_msg_call_id();
	}
	if (from == NULL || from[0] == '\0')
	{
		strFrom = sip_build_msg_from();
	}
	if (ftag == NULL || ftag[0] == '\0')
	{
		strFTag = sip_build_randnum();
	}
	if (to == NULL || to[0] == '\0')
	{
		to = strFrom.c_str();
	}
	if (ttag == NULL || ttag[0] == '\0')
	{
		strTo.format("<%s>", to);
	}
	else
	{
		strTo.format("<%s>;tag=%s", to, ttag);
	}
	strReq.format("%s %s SIP/2.0%s"
		"Via: SIP/2.0/UDP %s:%d;branch=z9hG4bK%s%s"
		"From: <%s>;tag=%s%s"
		"To: %s%s"
		"Call-ID: %s%s"
		"CSeq: %d %s%s"
		"Max-Forwards: 70%s"
		"User-Agent: XINYI%s"
		"Content-Length: 0%s%s",
		method, strDst.c_str(), Line,
		sipaddr, sipport, sip_build_randnum().c_str(), Line,
		strFrom.c_str(), strFTag.c_str(), Line,
		strTo.c_str(), Line,
		strCallId.c_str(), Line,
		cseq, method, Line,
		Line, Line, Line, Line);
	return strReq;
}

acl::string sip_build_msg_answer(const char *msg, const char *status)
{
	acl::string strVia = sip_get_header(msg, "Via: ", false);
	acl::string strFrom = sip_get_header(msg, "From: ", false);
	acl::string strTo = sip_get_header(msg, "To: ");
	acl::string strCallID = sip_get_header(msg, "Call-ID: ", false);
	acl::string strCSeq = sip_get_header(msg, "CSeq: ", false);
	if (strVia == "" || strFrom == "" || strTo == "" || strCallID == "" || strCSeq == "")
	{
		return "";
	}
	char *sTag = strTo.rfind("tag=");
	if (sTag == NULL)
	{
		strTo.format_append(";tag=%s%s", sip_build_randnum().c_str(), Line);
	}
	acl::string strAnswer;
	strAnswer.format(
		"SIP/2.0 %s%s"
		"Via: %s"
		"From: %s"
		"To: %s"
		"Call-ID: %s"
		"CSeq: %s"
		"User-Agent: XINYI%s"
		"Content-Length: 0%s%s",
		status, Line, strVia.c_str(), strFrom.c_str(), strTo.c_str(), strCallID.c_str(), strCSeq.c_str(), Line, Line, Line);
	return strAnswer;
}

acl::string sip_build_msg_register(const char * to, const char *auth, int cseq, int expires, const char *callid, const char *ftag)
{
	acl::string strReq = sip_build_msg_request("REGISTER", to, callid, cseq, NULL, NULL, ftag, NULL);
	acl::string strCotact;
	strCotact.format("<%s>", sip_build_msg_from().c_str());
	strReq = sip_set_header(strReq.c_str(), "Contact: ", strCotact.c_str());
	if (auth)
	{
		strReq = sip_set_header(strReq.c_str(), "Authorization: ", auth);
	}
	acl::string strExpires;
	strExpires.format("%d", expires);
	strReq = sip_set_header(strReq.c_str(), "Expires: ", strExpires.c_str());
	return strReq;
}

acl::string sip_build_msg_keepalive(const char * to)
{
	acl::string strMsg = sip_build_msg_request("MESSAGE", NULL, NULL, 3, NULL, to, NULL, NULL);
	acl::string strBody;
	strBody.format(
		"<?xml version=\"1.0\"?>%s"
		"<Notify>%s"
		"<CmdType>Keepalive</CmdType>%s"
		"<SN>%d</SN>%s"
		"<DeviceID>%s</DeviceID>%s"
		"<Status>OK</Status>%s"
		"</Notify>%s",
		Line, Line, Line, sip_build_randsn(), Line, sipuser, Line, Line, Line);
	strMsg = sip_set_body(strMsg.c_str(), strBody.c_str(), SIP_APPLICATION_XML);
	return strMsg;
}

acl::string sip_build_msg_invite(const char * to, const char * subject, int cseq, const char * callid, const char * ftag)
{
	acl::string strMsg = sip_build_msg_request("INVITE", NULL, callid, cseq, NULL, to, ftag, NULL);
	strMsg = sip_set_header(strMsg.c_str(), "Subject: ", subject);
	return strMsg;
}

acl::string sip_build_msg_sdp(const char * user, const char * uri, const char * time, const char * recvip, int recvport, int type, int drct, int prot, int speed, int media, int playload, int stream)
{
	acl::string strSdp;
	acl::string strType = "Play";
	if (type == SIP_INVITE_PLAYBACK)
		strType = "Playback";
	else if (type == SIP_INVITE_DOWNLOAD)
		strType = "Download";
	else if (type == SIP_INVITE_TALK)
		strType = "Talk";
	strSdp.format(
		"v=0%s"
		"o=%s 0 0 IN IP4 %s%s"
		"s=%s%s"
		"u=%s%s"
		"c=IN IP4 %s%s"
		"t=%s%s",
		Line, user, recvip, Line, strType.c_str(), Line, uri, Line, recvip, Line, time, Line);
	acl::string strDrct = "sendonly";
	if (drct == SIP_RECVONLY)
		strDrct = "recvonly";
	else if (drct == SIP_SENDRECV)
		strDrct = "sendrecv";
	acl::string strStream = "PS";
	if (stream == SIP_STREAM_HIKVISION)
		strStream = "HIKVISON";
	else if (stream == SIP_STREAM_HIKVISION)
		strStream = "HIKVISON";
	else if (stream == SIP_STREAM_DAHUA)
		strStream = "DAHUA";
	else if (stream == SIP_STREAM_MPEG4)
		strStream = "MPEG4";
	else if (stream == SIP_STREAM_H264)
		strStream = "H264";
	else if (stream == SIP_STREAM_SVAC)
		strStream = "SVAC";
	else if (stream == SIP_STREAM_H265)
		strStream = "H265";
	else if (stream == SIP_STREAM_PCMA)
		strStream = "PCMA";
	else if (stream == SIP_STREAM_SVACA)
		strStream = "SVACA";
	else if (stream == SIP_STREAM_G723)
		strStream = "G723";
	else if (stream == SIP_STREAM_G729)
		strStream = "G729";
	else if (stream == SIP_STREAM_G722)
		strStream = "G722";
	acl::string strProt = "TCP/RTP/AVP";
	if (prot == SIP_TRANSFER_UDP)
		strProt = "RTP/AVP";
	if (media == SIP_MEDIA_VIDEO)
	{
		if (playload == 0)
		{
			strSdp.format_append(
				"m=video %d %s 96 98 97%s"
				"a=%s%s"
				"a=rtpmap:96 PS/90000%s"
				"a=rtpmap:98 H264/90000%s"
				"a=rtpmap:97 MPEG4/90000%s",
				recvport, strProt.c_str(), Line, strDrct.c_str(), Line, Line, Line, Line);
		}
		else
		{
			strSdp.format_append(
				"m=video %d %s %d%s"
				"a=%s%s"
				"a=rtpmap:%d %s/90000%s",
				recvport, strProt.c_str(), playload, Line, strDrct.c_str(), Line, playload, strStream.c_str(), Line);
		}
	}
	else
	{
		strSdp.format_append(
			"m=audio %d %s %d%s"
			"a=%s%s"
			"a=rtpmap:%d %s/8000%s",
			recvport, strProt.c_str(), playload, Line, strDrct.c_str(), Line, playload, strStream.c_str(), Line);
	}
	if (prot == SIP_TRANSFER_TCP_ACTIVE || prot == SIP_TRANSFER_TCP_PASSIVE)
	{
		acl::string strSetup = "active";
		if (prot == SIP_TRANSFER_TCP_PASSIVE)
			strSetup = "passive";
		strSdp.format_append(
			"a=setup:%s%s"
			"a=connection:new%s",
			strSetup.c_str(), Line, Line);
	}
	if (speed > 0)
	{
		strSdp.format_append("a=downloadspeed:%d%s", speed, Line);
	}
	return strSdp;
}

acl::string sip_build_msg_ack(const char * msg)
{
	acl::string strVia = sip_get_header(msg, "Via: ", false);
	acl::string strFrom = sip_get_header(msg, "From: ", false);
	acl::string strTo = sip_get_header(msg, "To: ", false);
	acl::string strDst = sip_get_to_uri(msg);
	acl::string strCallID = sip_get_header(msg, "Call-ID: ", false);
	acl::string strCSeq = sip_get_header(msg, "CSeq: ", false);
	if (strVia == "" || strFrom == "" || strTo == "" || strCallID == "" || strCSeq == "")
	{
		return "";
	}
	acl::string strAck;
	strAck.format(
		"ACK %s SIP/2.0%s"
		"Via: %s"
		"From: %s"
		"To: %s"
		"Call-ID: %s"
		"CSeq: %s"
		"Max-Forwards: 70%s"
		"User-Agent: XINYI%s"
		"Content-Length: 0%s%s",
		strDst.c_str(), Line, strVia.c_str(), strFrom.c_str(), strTo.c_str(), strCallID.c_str(), strCSeq.c_str(), Line, Line, Line, Line);
	return strAck;
}

acl::string sip_build_msg_bye(const char * to, int cseq, const char * callid, const char * ftag, const char * ttag)
{
	return sip_build_msg_request("BYE", NULL, callid, cseq, NULL, to, ftag, ttag);
}

SIP_EVENT_TYPE sip_get_event_type(const char *msg)
{
	if (msg_is_options(msg))
		return SIP_OPTIONS_REQUEST;
	else if (msg_is_register(msg))
		return SIP_REGISTER_REQUEST;
	else if (msg_is_invite(msg))
		return SIP_INVITE_REQUEST;
	else if (msg_is_ack(msg))
		return SIP_ACK_REQUEST;
	else if (msg_is_cancel(msg))
		return SIP_CANCEL_REQUEST;
	else if (msg_is_info(msg))
		return SIP_INFO_REQUEST;
	else if (msg_is_subscribe(msg))
		return SIP_SUBSCRIBE_REQUEST;
	else if (msg_is_notify(msg))
		return SIP_NOTIFY_EVENT;
	else if (msg_is_message(msg))
		return SIP_MESSAGE_EVENT;
	else if (msg_is_status_1xx(msg))
	{
		if (sip_get_cseq_method(msg).compare("INVITE", false) == 0)
			return SIP_INVITE_PROCEEDING;
	}
	else if (msg_is_status_2xx(msg))
	{
		if (sip_get_cseq_method(msg).compare("OPTIONS", false) == 0)
			return SIP_OPTIONS_RESPONSE;
		if (sip_get_cseq_method(msg).compare("REGISTER", false) == 0)
			return SIP_REGISTER_SUCCESS;
		if (sip_get_cseq_method(msg).compare("INVITE", false) == 0)
			return SIP_INVITE_SUCCESS;
		if (sip_get_cseq_method(msg).compare("BYE", false) == 0)
			return SIP_BYE_SUCCESS;
		if (sip_get_cseq_method(msg).compare("CANCEL", false) == 0)
			return SIP_CANCEL_SUCCESS;
		if (sip_get_cseq_method(msg).compare("CANCEL", false) == 0)
			return SIP_INFO_SUCCESS;
		if (sip_get_cseq_method(msg).compare("SUBSCRIBE", false) == 0)
			return SIP_SUBSCRIBE_SUCCESS;
		if (sip_get_cseq_method(msg).compare("NOTIFY", false) == 0)
			return SIP_NOTIFY_SUCCESS;
		if (sip_get_cseq_method(msg).compare("MESSAGE", false) == 0)
			return SIP_MESSAGE_SUCCESS;

	}
	else if (msg_is_status_4xx(msg) || msg_is_status_5xx(msg))
	{
		if (sip_get_cseq_method(msg).compare("REGISTER",false) == 0)
			return SIP_REGISTER_FAILURE;
		if (sip_get_cseq_method(msg).compare("INVITE", false) == 0)
			return SIP_INVITE_FAILURE;
		if (sip_get_cseq_method(msg).compare("BYE", false) == 0)
			return SIP_BYE_FAILURE;
		if (sip_get_cseq_method(msg).compare("CANCEL", false) == 0)
			return SIP_CANCEL_FAILURE;
		if (sip_get_cseq_method(msg).compare("INFO", false) == 0)
			return SIP_INFO_FAILURE;
		if (sip_get_cseq_method(msg).compare("SUBSCRIBE", false) == 0)
			return SIP_SUBSCRIBE_FAILURE;
		if (sip_get_cseq_method(msg).compare("NOTIFY", false) == 0)
			return SIP_NOTIFY_FAILURE;
		if (sip_get_cseq_method(msg).compare("MESSAGE", false) == 0)
			return SIP_MESSAGE_FAILURES;
	}
	return SIP_EVENT_UNKNOWN;
}

SIP_MESSAGE_TYPE sip_get_message_type(const char *msg)
{
	acl::string strMsg = msg;
	if (strMsg.find("<Control>", false))
	{
		if (strMsg.find("<PTZCmd>", false))			//PTZType
			return SIP_CONTROL_PTZCMD;
		else if (strMsg.find("<TeleBoot>", false))	//Boot
			return SIP_CONTROL_TELEBOOT;
		else if (strMsg.find("<RecordCmd>", false))	//recordType:Record/StopRecord
			return SIP_CONTROL_RECORDCMD;
		else if (strMsg.find("<GuardCmd>", false))	//guardType:SetGuard/ResetGuard
			return SIP_CONTROL_GUARDCMD;
		else if (strMsg.find("<AlarmCmd>", false))	//ResetAlarm
			return SIP_CONTROL_ALARMCMD;
		else if (strMsg.find("<IFameCmd>", false))
			return SIP_CONTROL_IFAMECMD;
		else if (strMsg.find("<DragZpomIn>", false))
			return SIP_CONTROL_DRAGZOOMIN;
		else if (strMsg.find("<DragZpomOut>", false))
			return SIP_CONTROL_DRAGZOOMOUT;
		else if (strMsg.find("<HomePosition>", false))
			return SIP_CONTROL_HOMEPOSITION;
		else if (strMsg.find("<BasicParam>", false))
			return SIP_CONTROL_CONFIG;
		else if (strMsg.find("<SAVCEncodeConfig>", false))
			return SIP_CONTROL_CONFIG;
		else if (strMsg.find("<SAVCDecodeConfig>", false))
			return SIP_CONTROL_CONFIG;
	}
	else if (strMsg.find("<Query>", false))
	{
		if (strMsg.find(">DeviceStatus<", false))
			return SIP_QUERY_DEVICESTATUS;
		else if (strMsg.find(">Catalog<", false))
			return SIP_QUERY_CATALOG;
		else if (strMsg.find(">DeviceInfo<", false))
			return SIP_QUERY_DEVICEINFO;
		else if (strMsg.find(">RecordInfo<", false))
			return SIP_QUERY_RECORDINFO;
		else if (strMsg.find(">Alarm<", false))
			return SIP_QUERY_ALARM;
		else if (strMsg.find(">ConfigDownload<", false)) //BasicParam/VideoParam/SVACEncodeConfig/SVACDecodeConfig
			return SIP_QUERY_CONFIGDOWNLOAD;
		else if (strMsg.find(">PresetQuery<", false))
			return SIP_QUERY_PRESETQUERY;
		else if (strMsg.find(">MobilePosition<", false))
			return SIP_QUERY_MOBILEPOSITION;
	}
	else if (strMsg.find("<Notify>", false))
	{
		if (strMsg.find(">Keepalive<", false))
			return SIP_NOTIFY_KEEPALIVE;
		else if (strMsg.find(">Alarm<", false))
			return SIP_NOTIFY_ALARM;
		else if (strMsg.find(">MediaStatus<", false))
			return SIP_NOTIFY_MEDIASTATUS;
		else if (strMsg.find(">Broadcast<", false))
			return SIP_NOTIFY_BROADCAST;
		else if (strMsg.find(">MobilePositon<", false))
			return SIP_NOTIFY_MOBILEPOSITION;
	}
	else if (strMsg.find("<Response>", false))
	{
		if (strMsg.find(">DeviceControl<", false))	
			return SIP_RESPONSE_CONTROL;
		else if (strMsg.find(">Alarm<", false))
			return SIP_RESPONSE_NOTIFY_ALARM;
		else if (strMsg.find(">Catalog<", false))
			return SIP_RESPONSE_CATALOG;
		else if (strMsg.find(">DeviceInfo<", false))
			return SIP_RESPONSE_DEVICEINFO;
		else if (strMsg.find(">DeviceStatus<", false))
			return SIP_RESPONSE_DEVICESTATUS;
		else if (strMsg.find(">RecordInfo<", false))
			return SIP_RESPONSE_RECORDINFO;
		else if (strMsg.find(">ConfigDwonload<", false))
			return SIP_RESPONSE_CONFIGDOWNLOAD;
		else if (strMsg.find(">PresetQuery<", false))
			return SIP_RESPONSE_PRESETQUERY;
		else if (strMsg.find(">Broadcast<", false))
			return SIP_RESPONSE_BROADCAST;
	}
	return SIP_MESSAGE_UNKNOWN;
}

SIP_CONTENT_TYPE sip_get_content_type(const char *msg)
{
	acl::string strContentType = sip_get_header(msg, "Content-Type: ");
	if (strContentType != "")
	{
		if (strContentType.find("xml", false))
			return SIP_APPLICATION_XML;
		else if (strContentType.find("sdp", false))
			return SIP_APPLICATION_SDP;
		else if (strContentType.find("rtsp", false))
			return SIP_APPLICATION_RTSP;
	}
	return SIP_APPLICATION_UNKNOWN;
}

SIP_RECORD_TYPE sip_get_record_type(const char * type)
{
	if (strcasecmp(type, "time") == 0)
		return SIP_RECORDTYPE_TIME;
	else if (strcasecmp(type, "move") == 0)
		return SIP_RECORDTYPE_MOVE;
	else if (strcasecmp(type, "alarm") == 0)
		return SIP_RECORDTYPE_ALARM;
	else if (strcasecmp(type, "manual") == 0)
		return SIP_RECORDTYPE_MANUAL;
	else
		return SIP_RECORDTYPE_ALL;
}

acl::string get_msg_substr(const char *msg, const char *begin, const char *end)
{
	acl::string strMsg = msg;
	size_t blen = strlen(begin);
	char *sBegin = strMsg.find(begin, false);
	if (sBegin)
	{
		acl::string strSubstr = sBegin + blen;
		char *sEnd = strSubstr.find(end, false);
		if (sEnd)
		{
			sEnd[0] = '\0';
			return strSubstr;
		}
	}
	return "";
}

acl::string get_msg_substr2(const char *msg, const char *head, const char *begin, const char *end)
{
	size_t hlen = strlen(head);
	size_t blen = strlen(begin);
	char *pHead = (char *)strstr(msg, head);
	if (pHead == NULL)
	{
		return "";
	}
	pHead += hlen;
	char *pBegin = (char *)strstr(pHead, begin);
	if (pBegin == NULL)
	{
		return "";
	}
	pBegin += blen;
	acl::string strSubstr = pBegin;
	char *sEnd = strSubstr.find(end);
	if (sEnd == NULL)
	{
		return "";
	}
	sEnd[0] = '\0';
	return strSubstr;
}

acl::string sip_get_localtime()
{
	time_t ctime = time(NULL);
	tm *ctm = localtime(&ctime);
	acl::string strDate;
	strDate.format("%04d-%02d-%02dT%02d:%02d:%02d", ctm->tm_year+1900, ctm->tm_mon+1, ctm->tm_mday, ctm->tm_hour, ctm->tm_min, ctm->tm_sec);
	return strDate;
}

int sip_get_user_role(const char * user)
{
	acl::string strUser = user;
	acl::string strType;
	strUser.substr(strType,10, 3);
	int nRoleType = atoi(strType.c_str());
	if (nRoleType >= 300)
	{
		return SIP_ROLE_CLIENT;
	}
	else if (nRoleType >= 200 && nRoleType < 300)
	{
		if (nRoleType == 202)
		{
			return SIP_ROLE_MEDIA;
		}
		return SIP_ROLE_SENDER;
	}
	else if (nRoleType > 130 && nRoleType <= 140)
	{
		if (nRoleType == 133)
		{
			return SIP_ROLE_MONITOR;
		}
		return SIP_ROLE_CHANNEL;
	}
	else if (nRoleType > 110 && nRoleType <= 130)
	{
		if (nRoleType == 114)
		{
			return SIP_ROLE_DECODER;
		}
		return SIP_ROLE_DEVICE;
	}
	return 0;
}

acl::string sip_get_header(const char *msg, const char *head, bool nonl)
{
	acl::string strMsg = msg;
	char *sFnd = strMsg.find(head, false);
	if (sFnd != NULL)
	{	
		sFnd += strlen(head);
		acl::string strFnd = sFnd;
		acl::string strHead;
		if (strFnd.scan_line(strHead, nonl))
			return strHead;
	}
	return "";
}

int sip_get_status_code(const char * msg)
{
	acl::string strMsg = msg;
	acl::string strCode;
	strMsg.substr(strCode,8,3);
	int nStatus = atoi(strMsg.c_str());
	return nStatus > 0 ? nStatus : 400;
}

acl::string sip_get_from_user(const char * msg)
{
	return get_msg_substr(msg, "From: <sip:", "@");
}

acl::string sip_get_from_addr(const char * msg)
{
	return get_msg_substr2(msg, "From: ", "@", ">");
}

acl::string sip_get_from_tag(const char * msg)
{
	acl::string strFrom = sip_get_header(msg, "From: ");
	char *sFnd = strFrom.rfind("tag=");
	if (sFnd)
	{
		sFnd += strlen("tag=");
		return acl::string(sFnd);
	}
	return "";
}

acl::string sip_get_to_uri(const char * msg)
{
	return get_msg_substr(msg, "To: <", ">");
}

acl::string sip_get_to_user(const char * msg)
{
	return get_msg_substr(msg, "To: <sip:", "@");
}

acl::string sip_get_to_addr(const char * msg)
{
	return get_msg_substr2(msg, "To: ", "@", ">");
}

acl::string sip_get_to_tag(const char * msg)
{
	acl::string strTo = sip_get_header(msg, "To: ");
	char *sFnd = strTo.rfind("tag=");
	if (sFnd)
	{
		sFnd += strlen("tag=");
		return acl::string(sFnd);
	}
	return "";
}

int sip_get_cseq_num(const char * msg)
{
	return atoi(get_msg_substr(msg, "CSeq: ", " ").c_str());
}

acl::string sip_get_cseq_method(const char * msg)
{
	acl::string strCseq = sip_get_header(msg, "CSeq: ");
	char *sFnd = strCseq.rfind(" ");
	if (sFnd)
	{
		return acl::string(sFnd + 1);
	}
	return "";
}

acl::string sip_get_authorization_username(const char * msg)
{
	return get_msg_substr(msg, "username=\"", "\"");
}

acl::string sip_get_authorization_realm(const char * msg)
{
	return get_msg_substr(msg, "realm=\"", "\"");
}

acl::string sip_get_authorization_nonce(const char * msg)
{
	return get_msg_substr(msg, "nonce=\"", "\"");
}

acl::string sip_get_authorization_uri(const char * msg)
{
	return get_msg_substr(msg, "uri=\"", "\"");
}

acl::string sip_get_authorization_response(const char * msg)
{
	return get_msg_substr(msg, "response=\"", "\"");
}

acl::string sip_get_authorization_algorithm(const char * msg)
{
	return get_msg_substr(msg, "algorithm=\"", "\"");
}

acl::string sip_get_www_authenticate_realm(const char * msg)
{
	return get_msg_substr(msg, "realm=\"", "\"");
}

acl::string sip_get_www_authenticate_nonce(const char * msg)
{
	return get_msg_substr(msg, "nonce=\"", "\"");
}

SIP_CONTENT_TYPE sip_get_body(const char * msg, acl::string &strBody)
{
	acl::string strMsg = msg;
	char *sBody = NULL;
	SIP_CONTENT_TYPE content_type = sip_get_content_type(msg);
	switch (content_type)
	{
	case SIP_APPLICATION_XML:
		sBody = strMsg.find("<?xml version=");
		break;
	case SIP_APPLICATION_SDP:
		sBody = strMsg.find("v=");
		break;
	case SIP_APPLICATION_RTSP:
		sBody = strMsg.find("RTSP/1.0");
		break;
	}
	if (sBody)
	{
		strBody = sBody;
		return content_type;
	}
	strBody = "";
	return SIP_APPLICATION_UNKNOWN;
}

void sip_get_sdp_info(const char * sdp, sip_sdp_info * info)
{
	memset(info, 0, sizeof(sip_sdp_info));
	acl::string strSdp = sdp;
	acl::string strInfo;
	while (strSdp.scan_line(strInfo, true, NULL))
	{
		if (strInfo.ncompare("o=",strlen("o=")) == 0)
		{
			char *p = strInfo.find("IP4 ");
			if (p)
			{
				p += strlen("IP4 ");
				strcpy(info->o_ip, p);
			}
		}
		else if (strInfo.ncompare("c=", strlen("c=")) == 0)
		{
			char *p = strInfo.find("IP4 ");
			if (p)
			{
				p += strlen("IP4 ");
				strcpy(info->o_ip, p);
			}
		}
		else if (strInfo.ncompare("m=", strlen("m=")) == 0)
		{
			acl::string strM = strInfo.right(1);
			std::vector<acl::string> vecM = strM.split2(" ");
			if (vecM.size() < 3)
			{
				memset(info, 0, sizeof(sip_sdp_info));
				return;
			}
			info->m_type = SIP_MEDIA_VIDEO;
			if (vecM[0].compare("audio"))
			{
				info->m_type = SIP_MEDIA_AUDIO;
			}
			info->m_port = atoi(vecM[1].c_str());
			info->m_protocol = SIP_TRANSFER_UDP;
			if (vecM[2].find("TCP",false))
			{
				if (info->m_protocol == 0)
				{
					info->m_protocol = SIP_TRANSFER_TCP_ACTIVE;
				}
			}
		}
		else if (strInfo.ncompare("a=", strlen("a=")) == 0)
		{
			acl::string strA = strInfo.right(1);
			if (strA.compare("sendonly", false) == 0)
			{
				info->a_direct = SIP_SENDONLY;
			}
			else if (strA.compare("recvonly", false) == 0)
			{
				info->a_direct = SIP_RECVONLY;
			}
			else if (strA.compare("sendrecv", false) == 0)
			{
				info->a_direct = SIP_SENDRECV;
			}
			else
			{
				if (strA.ncompare("rtpmap:", strlen("rtpmap:")) == 0)
				{
					strA = strA.right(strlen("rtpmap:")-1);
					if (info->a_playload == 0)
					{
						info->a_playload = atoi(strA.c_str());
					}
					if (info->a_streamtype[0] == '\0')
					{
						acl::string strType = get_msg_substr(strA.c_str(), " ", "/");
						strcpy(info->a_streamtype, strType.c_str());
					}
				}
				else if (strA.ncompare("setup:", strlen("setup:")) == 0)
				{
					strA = strA.right(strlen("setup:")-1);
					if (strA.compare("passive ", false) == 0)
					{
						info->m_protocol = SIP_TRANSFER_TCP_PASSIVE;
					}
				}
				else if (strA.ncompare("downloadspeed:", strlen("downloadspeed:")) == 0)
				{
					strA = strA.right(strlen("downloadspeed:")-1);
					info->a_downloadspeed = atoi(strA.c_str());
				}
				else if (strA.ncompare("filesize:", strlen("filesize:")) == 0)
				{
					strA = strA.right(strlen("filesize:")-1);
					long long lSize = atoll(strA.c_str());
					if (lSize > 0)
					{
						info->a_filesize = lSize;
					}
				}
			}
		}
		else if (strInfo.ncompare("y=", strlen("y=")) == 0)
		{
			acl::string strY = strInfo.right(1);
			strcpy(info->y_ssrc, strY.c_str());
		}
		else if (strInfo.ncompare("u=", strlen("u=")) == 0)
		{
			acl::string strU = strInfo.right(1);
			strcpy(info->u_uri, strU.c_str());
		}
		else if (strInfo.ncompare("f=", strlen("f=")) == 0)
		{
			acl::string strF = strInfo.right(1);
			strcpy(info->f_parm, strF.c_str());
		}
		strInfo.clear();
	}
}

acl::string sip_set_header(const char * msg, const char * head, const char * value)
{
	acl::string strMsg = msg;
	acl::string strHeader;
	strHeader.format("%s%s%s", head, value, Line);
	char *sFnd = strMsg.find(head);
	if (sFnd)
	{
		acl::string strAfterBody = sFnd;
		sFnd[0] = '\0';
		sFnd = strAfterBody.find(Line);
		if (sFnd == NULL)
		{
			return "";
		}
		sFnd += strlen(Line);
		strAfterBody = sFnd;
		strMsg.append(strHeader);
		strMsg.append(strAfterBody);
	}
	else
	{
		sFnd = strMsg.find("Content-Length: ");
		if (sFnd == NULL)
		{
			return "";
		}
		acl::string strAfterBody = sFnd;
		sFnd[0] = '\0';
		strMsg = strMsg.c_str();
		strMsg.append(strHeader);
		strMsg.append(strAfterBody);
	}
	return strMsg;
}

acl::string sip_set_body(const char * msg, const char * body, SIP_CONTENT_TYPE type)
{
	acl::string sContentType;
	if (type == SIP_APPLICATION_XML)
		sContentType = "Application/MANSCDP+XML";
	else if (type == SIP_APPLICATION_SDP)
		sContentType = "APPLICATION/SDP";
	else if (type == SIP_APPLICATION_RTSP)
		sContentType = "Application/MANSRTSP";
	else
		return msg;
	size_t nBodylen = strlen(body);
	acl::string strMsg = sip_set_header(msg, "Content-Type: ", sContentType.c_str());
	char *sBodylen = strMsg.rfind("0");
	sBodylen[0] = '\0';
	acl::string strReq;
	strReq.format("%s%d%s%s%s", strMsg.c_str(), nBodylen, Line, Line, body);
	return strReq;
}

acl::string sip_set_sdp_y(const char * sdp, const char * ssrc)
{
	acl::string strSdp = sdp;
	char *sFnd = strSdp.find("y=");
	if (sFnd)
	{
		acl::string strAfter = sFnd;
		sFnd[0] = '\0';
		sFnd = strAfter.find(Line);
		if (sFnd)
		{
			sFnd += strlen(Line);
			strAfter = sFnd;
			strSdp.format_append("y=%s%s%s", ssrc, Line, strAfter.c_str());
		}
	}
	else
	{
		strSdp.format_append("y=%s%s", ssrc, Line);
	}
	return strSdp;
}

acl::string sip_set_sdp_f(const char * sdp, int encode, int resolution, int frame, int bitrate, int kbps, int voice, int bitsize, int samples)
{
	acl::string strEncode, strResolution, strFrame, strBitrate, strKbps, strVoice, strBitszie, srtSamples;
	if (encode > 0)
		strEncode.format("%d", encode);
	if (resolution > 0)
		strResolution.format("%d", resolution);
	if (frame > 0)
		strFrame.format("%d", frame);
	if (bitrate > 0)
		strBitrate.format("%d", bitrate);
	if (kbps > 0)
		strKbps.format("%d", kbps);
	if (voice > 0)
		strVoice.format("%d", voice);
	if (bitsize > 0)
		strBitszie.format("%d", bitsize);
	if (samples > 0)
		srtSamples.format("%d", samples);
	acl::string strSdp = sdp;
	char *sFnd = strSdp.find("f=");
	if (sFnd)
	{
		acl::string strAfter = sFnd;
		sFnd[0] = '\0';
		sFnd = strAfter.find(Line);
		if (sFnd)
		{
			sFnd += strlen(Line);
			strAfter = sFnd;
			strSdp.format_append("f=v/%s/%s/%s/%s/%sa/%s/%s/%s%s", strEncode.c_str(), strResolution.c_str(), strFrame.c_str(), strBitrate.c_str(), strKbps.c_str(), strVoice.c_str(), strBitszie.c_str(), srtSamples.c_str(), Line, strAfter.c_str());
		}
	}
	else
	{
		strSdp.format_append("f=v/%s/%s/%s/%s/%sa/%s/%s/%s%s", strEncode.c_str(), strResolution.c_str(), strFrame.c_str(), strBitrate.c_str(), strKbps.c_str(), strVoice.c_str(), strBitszie.c_str(), srtSamples.c_str(), Line);
	}
	return strSdp;
}










