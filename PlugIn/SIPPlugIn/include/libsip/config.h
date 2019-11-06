#pragma once

#include "acl_cpp/lib_acl.hpp"
#include "lib_acl.h"

#include <direct.h>
#include <string>
#include <vector>
#include <list>
#include <map>

#ifdef	_WIN32
#define	snprintf _snprintf
#define Line	"\r\n"
#else
#define Line	"\n"
#endif


#define DB_NONE		0
#define DB_ORACLE	1
#define DB_MYSQL	2
#define DB_SQLITE	3

#define LOG_INFO	0
#define LOG_WARN	1
#define LOG_ERROR	2
#define LOG_CLOSE	3

#define	SIP_RECVBUF_MAX		8192
#define SIP_ALIVETIME		30
#define SIP_ALIVETIMEOUT	90
#define SIP_SESSIONOVER		5

#define SIP_ROLE_CLIENT		0
#define SIP_ROLE_SUPERIOR	1
#define SIP_ROLE_LOWER		2
#define SIP_ROLE_SENDER		3
#define SIP_ROLE_MEDIA		4
#define SIP_ROLE_DEVICE		5
#define SIP_ROLE_CHANNEL	6
#define SIP_ROLE_DECODER	7
#define SIP_ROLE_MONITOR	8



class config
{
public:
	config();
	~config();
public:
	bool read();
	void log(int level, const char *fmt, ...);
private:
	int log_level;
public:
	char cwd[256];
	char local_addr[16];
	char local_code[24];
	char log_path[256];
	char db_addr[64];
	char db_name[64];
	char db_user[64];
	char db_pwd[64];

	char kfk_brokers[256];
	char kfk_topic[128];
	char kfk_group[128];

	int local_port;
	int db_driver;
	int db_pool;
	int srv_pool;
	int srv_role;
	int clnt_tranfer;
	int rtp_port;
	int rtp_check_ssrc;
	int specify_declib;
};

enum session_flow		//�Ự����
{
	SESSION_MEDIA_REQ,		//ý���������
	SESSION_MEDIA_OK,		//ý������Ӧ
	SESSION_SENDER_REQ,	//������������
	SESSION_SENDER_OK,	//�������ͻ�Ӧ
	SESSION_MEDIA_ACK,		//ý�����ȷ��
	SESSION_SENDER_ACK,	//��������ȷ��
	SESSION_RECVER_REQ,		//������������
	SESSION_RECVER_OK,		//�������ջ�Ӧ
	SESSION_SMEDIA_REQ,		//ý��������
	SESSION_SMEDIA_OK,		//ý������Ӧ
	SESSION_RECVER_ACK,		//��������ȷ��
	SESSION_SMEDIA_ACK,		//ý����ȷ��
	SESSION_RECVER_BYE,		//�������չر�
	SESSION_SMEDIA_BYE,		//ý�����ر�
	SESSION_MEDIA_BYE,		//ý�����ر�
	SESSION_SENDER_BYE,	//�������͹ر�
	SESSION_END				//�Ự����

};

struct record_info
{
	int nType;
	char sFileName[256];
	char startTime[20];
	char endTime[20];
	int  nSize;
};

struct session_info
{
	char deviceid[21];			//�豸����
	char addr[24];				//�豸��ַ
	char ftag[64];				//�Ự�����ʶ
	char ttag[64];				//�ỰӦ���ʶ
	char callid[64];			//�ỰID
	char ssrc[11];				//�Ựý������ʶ
	char terminalid[21];		//�ն˱��
	char sn[12];				//�������к�
	char starttime[20];			//��ʼʱ��
	char endtime[20];			//����ʱ��
	int  invite_type;			//�㲥����
	int  cseq;					//�Ự���к�
	int  alarm_method;			//��������
	int  alarm_type;			//����������
	int	 media_port;			//���˿�
	void *stream_cb;			//�����ص�
	void *stream_user;			//�����û�
	void *rtp_stream;			//�����߳�
	void *evnt_handle;			//�¼����
	record_info *rec_info;		//¼���ļ�ָ��
	int	rec_count;				//¼���ļ���
	time_t mediaover;			//ý��������ʱ��
	session_flow flow;			//�Ự����״̬
};

typedef std::list<session_info*>				session_list;
typedef session_list::iterator					seslist_iter;
typedef std::map<std::string, session_info*>	session_map;
typedef session_map::iterator					sesmap_iter;

struct register_info
{
	char addr[24];				//ע���ַ
	char user[21];				//ע�����
	char pwd[24];				//ע������
	char name[64];				//ע������
	int role;					//ע���ɫ			
	int expires;				//ע��ʱЧ
	int tranfer;				//����Э��
	bool online;				//�Ƿ�����
	bool vaild;					//�Ƿ���Ч
	time_t heartbeat;			//��ǰ����ʱ��
	time_t alivetime;			//��ǰ���ʱ��
	session_list *slist;		//�����Ự
};

typedef std::map<std::string, register_info>	register_map;
typedef register_map::iterator					regmap_iter;

typedef std::vector<acl::string>				register_list;
typedef register_list::iterator					reglist_iter;
typedef std::map<std::string, register_list*>	device_map;
typedef device_map::iterator					devmap_iter;

