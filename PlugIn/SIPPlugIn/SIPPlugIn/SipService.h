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
	void on_handle(acl::socket_stream* stream, const char *data, size_t dlen);							//��Ϣ����
	//response
	void on_options_response(acl::socket_stream* stream, const char *data, size_t dlen);				//������Ӧ
	void on_register_success(acl::socket_stream* stream, const char *data, size_t dlen);				//ע��ɹ�
	void on_register_failure(acl::socket_stream* stream, const char *data, size_t dlen);				//ע��ʧ��
	void on_invite_proceeding(acl::socket_stream* stream, const char *data, size_t dle);				//�㲥�ȴ�
	void on_invite_success(acl::socket_stream* stream, const char *data, size_t dlen);					//�㲥�ɹ�
	void on_invite_failure(acl::socket_stream* stream, const char *data, size_t dlen);					//�㲥ʧ��
	void on_cancel_success(acl::socket_stream* stream, const char *data, size_t dlen);					//ȡ���ɹ�
	void on_cancel_failure(acl::socket_stream* stream, const char *data, size_t dlen);					//ȡ��ʧ��
	void on_bye_success(acl::socket_stream* stream, const char *data, size_t dlen);						//�رճɹ�
	void on_bye_failure(acl::socket_stream* stream, const char *data, size_t dlen);						//�ر�ʧ��
	void on_info_success(acl::socket_stream* stream, const char *data, size_t dlen);					//�طſ��Ƴɹ�
	void on_info_failure(acl::socket_stream* stream, const char *data, size_t dlen);					//�طſ���ʧ��
	void on_subscribe_success(acl::socket_stream* stream, const char *data, size_t dlen);				//���ĳɹ�
	void on_subscribe_failure(acl::socket_stream* stream, const char *data, size_t dlen);				//����ʧ��
	void on_notify_success(acl::socket_stream* stream, const char *data, size_t dlen);					//֪ͨ�ɹ�
	void on_notify_failure(acl::socket_stream* stream, const char *data, size_t dlen);					//֪ͨʧ��
	void on_message_success(acl::socket_stream* stream, const char *data, size_t dlen);					//��ѯ�ɹ�
	void on_message_failure(acl::socket_stream* stream, const char *data, size_t dlen);					//��ѯʧ��
	void on_msg_control_response(acl::socket_stream* stream, const char *data, size_t dlen);			//���ƻ�Ӧ
	void on_msg_preset_response(acl::socket_stream* stream, const char *data, size_t dlen);				//Ԥ��λ��Ӧ
	void on_msg_devicestate_response(acl::socket_stream* stream, const char *data, size_t dlen);		//�豸״̬��Ӧ
	void on_msg_catalog_response(acl::socket_stream* stream, const char *data, size_t dlen);			//Ŀ¼��ѯ��Ӧ
	void on_msg_deviceinfo_response(acl::socket_stream* stream, const char *data, size_t dlen);			//�豸��Ϣ��Ӧ
	void on_msg_recordinfo_response(acl::socket_stream* stream, const char *data, size_t dlen);			//¼���ѯ��Ӧ
	void on_msg_alarm_response(acl::socket_stream* stream, const char *data, size_t dlen);				//������ѯ��Ӧ
	void on_msg_configdownload_response(acl::socket_stream* stream, const char *data, size_t dlen);		//���ò�ѯ��Ӧ
	void on_msg_broadcast_response(acl::socket_stream* stream, const char *data, size_t dlen);			//�����㲥��Ӧ
	//request
	void on_options_request(acl::socket_stream* stream, const char *data, size_t dlen);					//������ѯ
	void on_register_request(acl::socket_stream* stream, const char *data, size_t dlen);				//ע������
	void on_invite_request(acl::socket_stream* stream, const char *data, size_t dlen);					//�㲥����
	void on_cancel_request(acl::socket_stream* stream, const char *data, size_t dlen);					//�㲥ȡ��
	void on_ack_request(acl::socket_stream* stream, const char *data, size_t dlen);						//�㲥ȷ��
	void on_bye_request(acl::socket_stream* stream, const char *data, size_t dlen);						//�㲥�ر�
	void on_info_request(acl::socket_stream* stream, const char *data, size_t dlen);					//�طſ���
	void on_subscribe_request(acl::socket_stream* stream, const char *data, size_t dlen);				//��������
	void on_notify_request(acl::socket_stream* stream, const char *data, size_t dlen);					//֪ͨ��Ϣ
	void on_message_request(acl::socket_stream* stream, const char *data, size_t dlen);					//��ѯ��Ϣ
	void on_msg_ptzcmd_request(acl::socket_stream* stream, const char *data, size_t dlen);				//��̨����
	void on_msg_teleboot_request(acl::socket_stream* stream, const char *data, size_t dlen);			//�豸Զ������
	void on_msg_recordcmd_request(acl::socket_stream* stream, const char *data, size_t dlen);			//�豸�ֶ�¼��
	void on_msg_guardcmd_request(acl::socket_stream* stream, const char *data, size_t dlen);			//��������
	void on_msg_alarmcmd_request(acl::socket_stream* stream, const char *data, size_t dlen);			//������ѯ
	void on_msg_ifamecmd_request(acl::socket_stream* stream, const char *data, size_t dlen);			//ǿ��I֡
	void on_msg_dragzoomin_request(acl::socket_stream* stream, const char *data, size_t dlen);			//����Ŵ�
	void on_msg_dragzoomout_request(acl::socket_stream* stream, const char *data, size_t dlen);			//������С
	void on_msg_homeposition_request(acl::socket_stream* stream, const char *data, size_t dlen);		//��������
	void on_msg_config_request(acl::socket_stream* stream, const char *data, size_t dlen);				//��������
	void on_msg_preset_request(acl::socket_stream* stream, const char *data, size_t dlen);				//Ԥ��λ��ѯ
	void on_msg_devicestate_request(acl::socket_stream* stream, const char *data, size_t dlen);			//�豸״̬��ѯ
	void on_msg_catalog_request(acl::socket_stream* stream, const char *data, size_t dlen);				//Ŀ¼��ѯ
	void on_msg_deviceinfo_request(acl::socket_stream* stream, const char *data, size_t dlen);			//�豸��Ϣ��ѯ
	void on_msg_recordinfo_request(acl::socket_stream* stream, const char *data, size_t dlen);			//¼���ѯ
	void on_msg_alarm_request(acl::socket_stream* stream, const char *data, size_t dlen);				//������ѯ
	void on_msg_configdownload_request(acl::socket_stream* stream, const char *data, size_t dlen);		//���ò�ѯ
	void on_msg_mobileposition_request(acl::socket_stream* stream, const char *data, size_t dlen);		//GPS��ѯ
	//notify
	void on_msg_mobileposition_notify(acl::socket_stream* stream, const char *data, size_t dlen);		//GPS֪ͨ
	void on_msg_keepalive_notify(acl::socket_stream* stream, const char *data, size_t dlen);			//����֪ͨ
	void on_msg_mediastatus_notify(acl::socket_stream* stream, const char *data, size_t dlen);			//ý��������֪ͨ
	void on_msg_alarm_notify(acl::socket_stream* stream, const char *data, size_t dlen);				//����֪ͨ
	void on_msg_broadcast_request(acl::socket_stream* stream, const char *data, size_t dlen);			//�����㲥֪ͨ
	//ע��Ự����
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
	//������Ϣ 
	bool send_msg(const char *addr, const char *msg, size_t mlen);
	//����ע����Ϣ
	void send_register(const char *ip, int port, const char *user, const char *pwd, int expires=3600);
	//���͵㲥��Ϣ return invite_cid
	int send_invite(const char*addr, int type, char *deviceid, char *terminalid=NULL, char *starttime=NULL, char *endtime=NULL, media_stream_cb stream_cb=NULL, void *user=NULL);
	//���͹ر���Ϣ
	void send_bye(int invite_cid);
	void send_bye_by_cid(const char *cid);
	//������̨����
	void send_ptzcmd(const char *addr, char *deviceid, unsigned char cmd, unsigned char param1, unsigned short param2=0, SIP_PTZ_RECT *param=NULL);
	//����¼���ѯ
	int send_recordinfo(const char *addr, char *deviceid, int rectype, char *starttime, char *endtime, record_info *recordinfo, int recordsize);
public:
	config	m_conf;
	
};

