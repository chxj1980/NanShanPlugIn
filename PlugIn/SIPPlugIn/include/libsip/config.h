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

enum session_flow		//会话流程
{
	SESSION_MEDIA_REQ,		//媒体服务请求
	SESSION_MEDIA_OK,		//媒体服务回应
	SESSION_SENDER_REQ,	//码流发送请求
	SESSION_SENDER_OK,	//码流发送回应
	SESSION_MEDIA_ACK,		//媒体服务确认
	SESSION_SENDER_ACK,	//码流发送确认
	SESSION_RECVER_REQ,		//码流接收请求
	SESSION_RECVER_OK,		//码流接收回应
	SESSION_SMEDIA_REQ,		//媒体流请求
	SESSION_SMEDIA_OK,		//媒体流回应
	SESSION_RECVER_ACK,		//码流接收确认
	SESSION_SMEDIA_ACK,		//媒体流确认
	SESSION_RECVER_BYE,		//码流接收关闭
	SESSION_SMEDIA_BYE,		//媒体流关闭
	SESSION_MEDIA_BYE,		//媒体服务关闭
	SESSION_SENDER_BYE,	//码流发送关闭
	SESSION_END				//会话结束

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
	char deviceid[21];			//设备编码
	char addr[24];				//设备地址
	char ftag[64];				//会话请求标识
	char ttag[64];				//会话应答标识
	char callid[64];			//会话ID
	char ssrc[11];				//会话媒体流标识
	char terminalid[21];		//终端编号
	char sn[12];				//命令序列号
	char starttime[20];			//开始时间
	char endtime[20];			//结束时间
	int  invite_type;			//点播类型
	int  cseq;					//会话序列号
	int  alarm_method;			//报警类型
	int  alarm_type;			//报警子类型
	int	 media_port;			//流端口
	void *stream_cb;			//码流回调
	void *stream_user;			//码流用户
	void *rtp_stream;			//码流线程
	void *evnt_handle;			//事件句柄
	record_info *rec_info;		//录像文件指针
	int	rec_count;				//录像文件数
	time_t mediaover;			//媒体流结束时间
	session_flow flow;			//会话流程状态
};

typedef std::list<session_info*>				session_list;
typedef session_list::iterator					seslist_iter;
typedef std::map<std::string, session_info*>	session_map;
typedef session_map::iterator					sesmap_iter;

struct register_info
{
	char addr[24];				//注册地址
	char user[21];				//注册编码
	char pwd[24];				//注册密码
	char name[64];				//注册名称
	int role;					//注册角色			
	int expires;				//注册时效
	int tranfer;				//传输协议
	bool online;				//是否在线
	bool vaild;					//是否有效
	time_t heartbeat;			//当前心跳时间
	time_t alivetime;			//当前存活时间
	session_list *slist;		//关联会话
};

typedef std::map<std::string, register_info>	register_map;
typedef register_map::iterator					regmap_iter;

typedef std::vector<acl::string>				register_list;
typedef register_list::iterator					reglist_iter;
typedef std::map<std::string, register_list*>	device_map;
typedef device_map::iterator					devmap_iter;

