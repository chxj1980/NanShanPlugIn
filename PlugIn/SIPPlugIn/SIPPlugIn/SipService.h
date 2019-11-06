#pragma once
#include "config.h"
#include "libsip.h"
#include "librtp.h"
#ifdef _DBLIB_USE
#include "DatabaseClient.h"
#include "Consumer.h"
#endif

void sip_sleep(int usec);

class SipService : public acl::master_udp
{
public:
	SipService();
	~SipService();
protected:
	virtual void on_read(acl::socket_stream* stream);
	virtual void proc_on_init();
	virtual void proc_on_exit();
public:
	void on_handle(acl::socket_stream* stream, const char *data, size_t dlen);							//消息处理
	//response
	void on_options_response(acl::socket_stream* stream, const char *data, size_t dlen);				//能力回应
	void on_register_success(acl::socket_stream* stream, const char *data, size_t dlen);				//注册成功
	void on_register_failure(acl::socket_stream* stream, const char *data, size_t dlen);				//注册失败
	void on_invite_proceeding(acl::socket_stream* stream, const char *data, size_t dle);				//点播等待
	void on_invite_success(acl::socket_stream* stream, const char *data, size_t dlen);					//点播成功
	void on_invite_failure(acl::socket_stream* stream, const char *data, size_t dlen);					//点播失败
	void on_cancel_success(acl::socket_stream* stream, const char *data, size_t dlen);					//取消成功
	void on_cancel_failure(acl::socket_stream* stream, const char *data, size_t dlen);					//取消失败
	void on_bye_success(acl::socket_stream* stream, const char *data, size_t dlen);						//关闭成功
	void on_bye_failure(acl::socket_stream* stream, const char *data, size_t dlen);						//关闭失败
	void on_info_success(acl::socket_stream* stream, const char *data, size_t dlen);					//回放控制成功
	void on_info_failure(acl::socket_stream* stream, const char *data, size_t dlen);					//回放控制失败
	void on_subscribe_success(acl::socket_stream* stream, const char *data, size_t dlen);				//订阅成功
	void on_subscribe_failure(acl::socket_stream* stream, const char *data, size_t dlen);				//订阅失败
	void on_notify_success(acl::socket_stream* stream, const char *data, size_t dlen);					//通知成功
	void on_notify_failure(acl::socket_stream* stream, const char *data, size_t dlen);					//通知失败
	void on_message_success(acl::socket_stream* stream, const char *data, size_t dlen);					//查询成功
	void on_message_failure(acl::socket_stream* stream, const char *data, size_t dlen);					//查询失败
	void on_msg_control_response(acl::socket_stream* stream, const char *data, size_t dlen);			//控制回应
	void on_msg_preset_response(acl::socket_stream* stream, const char *data, size_t dlen);				//预置位回应
	void on_msg_devicestate_response(acl::socket_stream* stream, const char *data, size_t dlen);		//设备状态回应
	void on_msg_catalog_response(acl::socket_stream* stream, const char *data, size_t dlen);			//目录查询回应
	void on_msg_deviceinfo_response(acl::socket_stream* stream, const char *data, size_t dlen);			//设备信息回应
	void on_msg_recordinfo_response(acl::socket_stream* stream, const char *data, size_t dlen);			//录像查询回应
	void on_msg_alarm_response(acl::socket_stream* stream, const char *data, size_t dlen);				//报警查询回应
	void on_msg_configdownload_response(acl::socket_stream* stream, const char *data, size_t dlen);		//配置查询回应
	void on_msg_broadcast_response(acl::socket_stream* stream, const char *data, size_t dlen);			//语音广播回应
	//request
	void on_options_request(acl::socket_stream* stream, const char *data, size_t dlen);					//能力查询
	void on_register_request(acl::socket_stream* stream, const char *data, size_t dlen);				//注册请求
	void on_invite_request(acl::socket_stream* stream, const char *data, size_t dlen);					//点播请求
	void on_cancel_request(acl::socket_stream* stream, const char *data, size_t dlen);					//点播取消
	void on_ack_request(acl::socket_stream* stream, const char *data, size_t dlen);						//点播确认
	void on_bye_request(acl::socket_stream* stream, const char *data, size_t dlen);						//点播关闭
	void on_info_request(acl::socket_stream* stream, const char *data, size_t dlen);					//回放控制
	void on_subscribe_request(acl::socket_stream* stream, const char *data, size_t dlen);				//订阅请求
	void on_notify_request(acl::socket_stream* stream, const char *data, size_t dlen);					//通知消息
	void on_message_request(acl::socket_stream* stream, const char *data, size_t dlen);					//查询消息
	void on_msg_ptzcmd_request(acl::socket_stream* stream, const char *data, size_t dlen);				//云台控制
	void on_msg_teleboot_request(acl::socket_stream* stream, const char *data, size_t dlen);			//设备远程重启
	void on_msg_recordcmd_request(acl::socket_stream* stream, const char *data, size_t dlen);			//设备手动录像
	void on_msg_guardcmd_request(acl::socket_stream* stream, const char *data, size_t dlen);			//布防撤防
	void on_msg_alarmcmd_request(acl::socket_stream* stream, const char *data, size_t dlen);			//报警查询
	void on_msg_ifamecmd_request(acl::socket_stream* stream, const char *data, size_t dlen);			//强制I帧
	void on_msg_dragzoomin_request(acl::socket_stream* stream, const char *data, size_t dlen);			//拉框放大
	void on_msg_dragzoomout_request(acl::socket_stream* stream, const char *data, size_t dlen);			//拉框缩小
	void on_msg_homeposition_request(acl::socket_stream* stream, const char *data, size_t dlen);		//守望控制
	void on_msg_config_request(acl::socket_stream* stream, const char *data, size_t dlen);				//配置设置
	void on_msg_preset_request(acl::socket_stream* stream, const char *data, size_t dlen);				//预置位查询
	void on_msg_devicestate_request(acl::socket_stream* stream, const char *data, size_t dlen);			//设备状态查询
	void on_msg_catalog_request(acl::socket_stream* stream, const char *data, size_t dlen);				//目录查询
	void on_msg_deviceinfo_request(acl::socket_stream* stream, const char *data, size_t dlen);			//设备信息查询
	void on_msg_recordinfo_request(acl::socket_stream* stream, const char *data, size_t dlen);			//录像查询
	void on_msg_alarm_request(acl::socket_stream* stream, const char *data, size_t dlen);				//报警查询
	void on_msg_configdownload_request(acl::socket_stream* stream, const char *data, size_t dlen);		//配置查询
	void on_msg_mobileposition_request(acl::socket_stream* stream, const char *data, size_t dlen);		//GPS查询
	//notify
	void on_msg_mobileposition_notify(acl::socket_stream* stream, const char *data, size_t dlen);		//GPS通知
	void on_msg_keepalive_notify(acl::socket_stream* stream, const char *data, size_t dlen);			//心跳通知
	void on_msg_mediastatus_notify(acl::socket_stream* stream, const char *data, size_t dlen);			//媒体流结束通知
	void on_msg_alarm_notify(acl::socket_stream* stream, const char *data, size_t dlen);				//报警通知
	void on_msg_broadcast_request(acl::socket_stream* stream, const char *data, size_t dlen);			//语音广播通知
	//注册会话管理
	void register_manager();
	void register_slist_erase(const char *addr, const char *callid);
	void session_manager();
private:
#ifdef _DBLIB_USE
	DatabaseClient  m_db;
#endif
	acl::thread		*m_consumer_thd;
	bool			m_running;
	char			*m_szRecvBuf;
public:
	//发送消息 
	bool send_msg(const char *addr, const char *msg, size_t mlen);
	//发送注册消息
	void send_register(const char *ip, int port, const char *user, const char *pwd, int expires=3600);
	//发送点播消息 return invite_cid
	int send_invite(const char*addr, int type, char *deviceid, char *terminalid=NULL, char *starttime=NULL, char *endtime=NULL, media_stream_cb stream_cb=NULL, void *user=NULL);
	//发送关闭消息
	void send_bye(int invite_cid);
	void send_bye_by_cid(const char *cid);
	//发送云台控制
	void send_ptzcmd(const char *addr, char *deviceid, unsigned char cmd, unsigned char param1, unsigned short param2=0, SIP_PTZ_RECT *param=NULL);
	//发送录像查询
	int send_recordinfo(const char *addr, char *deviceid, int rectype, char *starttime, char *endtime, record_info *recordinfo, int recordsize);
public:
	config	m_conf;
	
};

