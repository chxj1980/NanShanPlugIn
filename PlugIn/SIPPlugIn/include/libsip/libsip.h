#pragma once
#include "config.h"

#include <time.h>
#include <math.h>


/********枚举类型**************************************/

typedef enum sip_event_type		//消息事件类型
{
	SIP_EVENT_UNKNOWN,		//未知事件
	SIP_REGISTER_REQUEST,	//注册请求
	SIP_REGISTER_SUCCESS,   //注册成功
	SIP_REGISTER_FAILURE,   //注册失败
	SIP_INVITE_REQUEST,		//点播请求
	SIP_INVITE_PROCEEDING,	//点播等待
	SIP_INVITE_SUCCESS,		//点播成功
	SIP_INVITE_FAILURE,		//点播失败
	SIP_ACK_REQUEST,		//点播确认	
	SIP_BYE_REQUEST,		//关闭请求
	SIP_BYE_SUCCESS,		//关闭成功
	SIP_BYE_FAILURE,		//关闭失败
	SIP_CANCEL_REQUEST,		//取消请求
	SIP_CANCEL_SUCCESS,		//取消成功	
	SIP_CANCEL_FAILURE,		//取消失败
	SIP_INFO_REQUEST,		//控制请求
	SIP_INFO_SUCCESS,		//控制成功
	SIP_INFO_FAILURE,		//控制失败
	SIP_SUBSCRIBE_REQUEST,	//订阅请求
	SIP_SUBSCRIBE_SUCCESS,	//订阅成功
	SIP_SUBSCRIBE_FAILURE,	//订阅失败
	SIP_NOTIFY_EVENT,		//通知消息
	SIP_NOTIFY_SUCCESS,		//通知成功
	SIP_NOTIFY_FAILURE,		//通知失败
	SIP_MESSAGE_EVENT,		//消息请求
	SIP_MESSAGE_SUCCESS,	//消息成功
	SIP_MESSAGE_FAILURES,	//消息失败
	SIP_OPTIONS_REQUEST,	//查询功能
	SIP_OPTIONS_RESPONSE	//查询响应

}SIP_EVENT_TYPE;

typedef enum sip_message_type	//消息请求类型
{
	SIP_MESSAGE_UNKNOWN,
	SIP_CONTROL_PTZCMD,			//云台控制
	SIP_CONTROL_TELEBOOT,		//远程重启(设备)
	SIP_CONTROL_RECORDCMD,		//手动录像(设备)
	SIP_CONTROL_GUARDCMD,		//布防/撤防
	SIP_CONTROL_ALARMCMD,		//报警复位
	SIP_CONTROL_IFAMECMD,		//强制I帧
	SIP_CONTROL_DRAGZOOMIN,		//拉框放大
	SIP_CONTROL_DRAGZOOMOUT,	//拉框缩小
	SIP_CONTROL_HOMEPOSITION,	//守望控制
	SIP_CONTROL_CONFIG,			//配置控制
	SIP_RESPONSE_CONTROL,		//控制应答
	SIP_QUERY_PRESETQUERY,		//预置位查询
	SIP_RESPONSE_PRESETQUERY,	//预置位回应
	SIP_QUERY_DEVICESTATUS,		//设备状态查询
	SIP_RESPONSE_DEVICESTATUS,	//设备状态回应
	SIP_QUERY_CATALOG,			//目录信息查询
	SIP_RESPONSE_CATALOG,		//目录信息回应
	SIP_QUERY_DEVICEINFO,		//设备信息查询
	SIP_RESPONSE_DEVICEINFO,	//设备信息回应
	SIP_QUERY_RECORDINFO,		//录像目录检索
	SIP_RESPONSE_RECORDINFO,	//目录检索回应
	SIP_QUERY_ALARM,			//报警查询
	SIP_RESPONSE_QUERY_ALARM,	//报警查询回应
	SIP_QUERY_CONFIGDOWNLOAD,	//设备配置查询
	SIP_RESPONSE_CONFIGDOWNLOAD,//设备配置回应
	SIP_QUERY_MOBILEPOSITION,	//点位坐标查询
	SIP_NOTIFY_MOBILEPOSITION,	//点位坐标回应
	SIP_NOTIFY_KEEPALIVE,		//心跳通知
	SIP_NOTIFY_MEDIASTATUS,		//媒体流结束通知
	SIP_NOTIFY_ALARM,			//报警通知
	SIP_RESPONSE_NOTIFY_ALARM,	//报警通知回应

	SIP_NOTIFY_BROADCAST,		//语音广播通知
	SIP_RESPONSE_BROADCAST		//语音广播应答
	
}SIP_MESSAGE_TYPE;

typedef enum sip_invite_type	//点播类型
{
	SIP_INVITE_UNKNOWN,
	SIP_INVITE_PLAY,		//实时点播
	SIP_INVITE_PLAYBACK,	//历史点播
	SIP_INVITE_DOWNLOAD,	//下载点播
	SIP_INVITE_TALK,		//语音对讲
	SIP_INVITE_MEDIASERVER	//媒体流结束

}SIP_INVITE_TYPE;

typedef enum sip_content_type	//消息体类型
{
	SIP_APPLICATION_UNKNOWN,
	SIP_APPLICATION_XML,	//XML
	SIP_APPLICATION_SDP,	//SDP
	SIP_APPLICATION_RTSP	//RTSP

}SIP_CONTENT_TYPE;

typedef enum sip_direction_type	//媒体流方向类型
{
	SIP_DIRECTION_UNKNOWN,
	SIP_RECVONLY,			//只接收
	SIP_SENDONLY,			//只发送
	SIP_SENDRECV			//接收和发送

}SIP_DIRECTION_TYPE;

typedef enum sip_protocol_type
{
	SIP_TRANSFER_UDP,		 //UDP传输
	SIP_TRANSFER_TCP_ACTIVE, //TCP主动传输
	SIP_TRANSFER_TCP_PASSIVE //TCP被动传输
}SIP_PROTOCOL_TYPE;

typedef enum sip_media_type
{
	SIP_MEDIA_VIDEO,		//视频流
	SIP_MEDIA_AUDIO			//音频流
}SIP_MEDIA_TYPE;

typedef enum sip_stream_type
{
	SIP_STREAM_PS,			//96
	SIP_STREAM_HIKVISION,	//
	SIP_STREAM_DAHUA,		//
	SIP_STREAM_MPEG4,		//97
	SIP_STREAM_H264,		//98
	SIP_STREAM_SVAC,		//99
	SIP_STREAM_H265,		//108
	SIP_STREAM_PCMA,		//8
	SIP_STREAM_SVACA,		//20
	SIP_STREAM_G723,		//4
	SIP_STREAM_G729,		//18
	SIP_STREAM_G722			//9
}SIP_STREAM_TYPE;

typedef enum sip_encode_type
{
	SIP_F_MPEG4=1,
	SIP_F_H264,
	SIP_F_SVAC,
	SIP_F_3GP,
	SIP_F_H265
}SIP_ENCODE_TYPE;

typedef enum sip_resolution_type //分辨率类型
{
	SIP_F_QCIF=1,
	SIP_F_CIF,
	SIP_F_4CIF,
	SIP_F_D1,
	SIP_F_720P,
	SIP_F_1080P,
	SIP_F_2K,
	SIP_F_4K
}SIP_RESOLUTION_TYPE;

typedef enum sip_bitrate_type
{
	SIP_F_CBR=1,
	SIP_F_VBR
}SIP_BITRATE_TYPE;

typedef enum sip_voice_type
{
	SIP_F_G711=1,
	SIP_F_G723,
	SIP_F_G729,
	SIP_F_G722
}SIP_VOICE_TYPE;

typedef enum sip_bitsize_type
{
	SIP_F_5_3KBPS=1,		//g723
	SIP_F_6_3KBPS,			//g723
	SIP_F_8KBPS,			//g729
	SIP_F_16KBPS,			//g722/g711
	SIP_F_24KBPS,			//g722
	SIP_F_32KBPS,			//g722
	SIP_F_48KBPS,			//g722
	SIP_F_64KBPS			//g711
}SIP_BITSIZE_TYPE;

typedef enum sip_samples_type
{
	SIP_F_8KHZ=1,			//g711/g723/g729
	SIP_F_14KHZ,			//g722
	SIP_F_16KHZ,			//g722
	SIP_F_32KHZ				//g722
}SIP_SAMPLES_TYPE;

typedef enum sip_info_type		//控制类型
{
	SIP_INFO_UNKNOWN,
	SIP_INFO_PLAY,			//回放控制
	SIP_INFO_PAUSE,			//回放暂停
	SIP_INFO_TEARDOWN		//回旋停止

}SIP_INFO_TYPE;

/********报警类型**************************************/
typedef enum sip_alarm_method
{
	SIP_ALARM_ALL,			//全部
	SIP_ALARM_PHONE,		//电话报警 
	SIP_ALARM_DEVICE,       //设备报警
	SIP_ALARM_SMS,			//短信报警
	SIP_ALARM_GPS,			//GPS报警
	SIP_ALARM_VIDEO,		//视频报警
	SIP_ALARM_DEVBROKEN,	//设备故障报警
	SIP_ALARM_OTHER,		//其它报警
	SIP_ALARM_PEOPLE,		//行人报警
	SIP_ALARM_VEHICLE		//车辆报警
}SIP_ARARM_METHOD;

typedef enum sip_alarm_device_type	//设备报警类型
{
	SIP_ALARM_LOSE = 1,		//设备丢失
	SIP_ALARM_DISASSEMBLY,	//防拆报警
	SIP_ALARM_DISKFULL,		//磁盘满
	SIP_ALARM_HIGHTTEMP,	//设备高温
	SIP_ALARM_LOWTEMP		//设备低温
	
}SIP_ALARM_DEVICE_TYPE;

typedef enum sip_alarm_video_type	//视频报警类型
{
	SIP_ALARM_BLOCK,		//视频遮挡
	SIP_ALARM_MANUAL,		//人工报警
	SIP_ALARM_MOVING,		//移动侦测
	SIP_ALARM_LEAVEOVER,	//遗留物
	SIP_ALARM_REMOVAL,		//物体移除
	SIP_ALARM_TRIPPINGLINE, //越线检测
	SIP_ALARM_INVASION,		//入侵检测
	SIP_ALARM_RETROGRADE,	//逆行检测
	SIP_ALARM_WANDERING,	//徘徊检测
	SIP_ALARM_FLOWCOUNT,	//流量统计
	SIP_ALARM_CROWDED,		//人员密度
	SIP_ALARM_ANOMALY,		//视频异常
	SIP_ALARM_FASTMOVING	//快速移动

}SIP_ALARM_VIDEO_TYPE;

typedef enum sip_alarm_devbroken_type
{
	SIP_ALARM_DISKBROKEN = 1, //磁盘故障
	SIP_ALARM_FANBROKEN		  //风扇故障

}SIP_ALARM_DEVBORKEN_TYPE;

typedef enum sip_alarm_people_type
{
	SIP_ALARM_FACE,				//人脸检测
	SIP_ALARM_HUMANBODY			//人体检测

}SIP_ALARM_PEOPLE_TYPE;

typedef enum sip_alarm_vehicle_type
{
	SIP_ALARM_CAR,
	SIP_ALARM_NOMOTO

}SIP_ALARM_VEHICLE_TYPE;

typedef enum sip_alarm_invasion_event
{
	SIP_ALARM_EVENT_ENTERAREA = 1, //进入区域
	SIP_ALARM_EVENT_LEAVEAREA	   //离开区域

}SIP_ALARM_INVASION_EVENT;

typedef enum sip_record_type
{
	SIP_RECORDTYPE_ALL,				//全部录像
	SIP_RECORDTYPE_TIME,			//定时录像
	SIP_RECORDTYPE_MOVE,			//侦测录像
	SIP_RECORDTYPE_ALARM,			//告警录像
	SIP_RECORDTYPE_MANUAL			//手动录像

}SIP_RECORD_TYPE;

typedef struct sip_sdp_info
{
	char o_ip[16];
	int	m_type;
	int	m_port;
	int m_protocol;
	int	a_direct;
	int	a_playload;
	int a_downloadspeed;
	size_t a_filesize;
	char a_streamtype[11];
	char y_ssrc[11];
	char u_uri[128];
	char f_parm[128];

}SIP_SDP_INFO;

typedef struct sip_ptz_rect
{
	unsigned short left;			
	unsigned short top;
	unsigned short right;
	unsigned short bottom;
	unsigned short width;
	unsigned short height;
}SIP_PTZ_RECT;

#define SIP_CSEQ_KEEPALIVE		3


/********指令码**************************************/
#define SIP_PTZCMD_NONE				0xFF
#define SIP_PTZCMD_STOP				0x00		//停止
#define SIP_PTZCMD_UP				0x08		//向上
#define SIP_PTZCMD_DOWN				0x04		//向下
#define SIP_PTZCMD_LEFT				0x02		//向左
#define SIP_PTZCMD_RIGHT			0x01		//向右
#define SIP_PTZCMD_LU				0x0A		//左上
#define SIP_PTZCMD_LD				0x06		//左下
#define SIP_PTZCMD_RU				0x09		//右上
#define SIP_PTZCMD_RD				0x05		//右下
#define SIP_PTZCMD_ZOOM_IN			0x10		//放大
#define SIP_PTZCMD_ZOOM_OUT			0x20		//缩小

#define SIP_PTZCMD_FI_IRIS_IN		0x48		//光圈放大
#define SIP_PTZCMD_FI_IRIS_OUT		0x44		//光圈缩小
#define SIP_PTZCMD_FI_FOCUS_IN		0x42		//聚焦拉近
#define SIP_PTZCMD_FI_FOCUS_OUT		0x41		//聚集拉远
#define SIP_PTZCMD_FI_STOP			0x40		//调节停止

#define SIP_PTZCMD_SET				0x81		//预置位设置
#define SIP_PTZCMD_GOTO				0x82		//预置位跳转
#define SIP_PTZCMD_DELETE			0x83		//预置位删除
#define SIP_PTZCMD_CRUISE_ADD		0x84		//巡航点添加
#define	SIP_PTZCMD_CRUISE_DEL		0x85		//巡航点删除
#define SIP_PTZCMD_CRUISE_SPEED		0x86		//巡航速度
#define SIP_PTZCMD_CRUISE_DTIME		0x87		//巡航停顿时间
#define SIP_PTZCMD_CRUISE_RUN		0x88		//巡航开始

#define SIP_PTZCMD_AUTO_RUN			0x89		//自动扫描开始
#define SIP_PTZCMD_AUTO_LBORDER		0x89		//自动扫描左边界
#define SIP_PTZCMD_AUTO_RBORDER		0x89		//自动扫描右边界
#define SIP_PTZCMD_AUTO_SPEED		0x8A		//自动扫描速度

#define SIP_PTZCMD_AUXIOPEN			0x8C		//辅助开关打开(雨刷)
#define SIP_PTZCMD_AUXICLOSE		0x8D		//辅助开关关闭

#define SIP_PTZCMD_DRAGZOOM_IN		0x76
#define SIP_PTZCMD_DRAGZOOM_OUT		0X77
#define SIP_PTZCMD_INITIAL			0x78
#define SIP_PTZCMD_UNINITIAL		0X79

#define SIP_PTZCMD_LOCK				0xC0
#define SIP_PTZCMD_UNLOCK			0X80
/***********************************************************/

#define SIP_STATUS_100			"100 Trying"								//尝试连接
#define SIP_STATUS_101			"101 Dialog Establishement"					//会话建立
#define SIP_STATUS_200			"200 OK"									//会话成功
#define SIP_STATUS_201			"201 Canceling"								//会话取消
#define SIP_STATUS_400			"400 Bad Request"							//请求错误
#define SIP_STATUS_401			"401 Unauthorized"							//未认证
#define SIP_STATUS_403			"403 Forbidden"								//禁止访问
#define SIP_STATUS_404			"404 Not Found"								//未找到
#define	SIP_STATUS_405			"405 Method Not Allowed"					//不支持的请求
#define SIP_STATUS_408			"408 Request Timeout"						//会话超时
#define SIP_STATUS_457			"457 Invalid Range"							//无效范围
#define SIP_STATUS_481			"481 Dialog/Transaction Does Not Exist"		//没有匹配的会话		
#define SIP_STATUS_482			"482 Loop Detected"							//循环请求
#define SIP_STATUS_486			"486 Busy Here"								//设备忙
#define SIP_STATUS_487			"487 Request Terminated"					//请求终止
#define SIP_STATUS_488			"488 Not Acceptable Here"					//SDP错误
#define SIP_STATUS_500			"500 Server Internal Error"					//服务内部错误
#define SIP_STATUS_502			"502 Bad Gateway"							//无效的应答
#define SIP_STATUS_503			"503 Service Unavailable"					//服务器过载
#define SIP_STATUS_551			"551 Option not supported"					//不支持的操作




void			 sip_init(const char *sipcode, const char *ip, int port);
time_t			 sip_get_totalseconds(char *time);
acl::string		 sip_get_formattime(char *time);
acl::string		 sip_get_generaltime(char *time);
int				 sip_build_randsn();
acl::string		 sip_build_randnum();
acl::string		 sip_build_nonce();
acl::string		 sip_build_sdp_ssrc(SIP_INVITE_TYPE type);
acl::string		 sip_build_sdp_time(const char *starttime, const char *endtime);
acl::string		 sip_build_authorization_response(const char *username, const char *realm, const char *password, const char *nonce, const char *uri);
acl::string		 sip_build_msg_from();
acl::string		 sip_build_msg_to(const char*user, const char *dst);
acl::string		 sip_build_msg_call_id(unsigned int id=0);
acl::string		 sip_build_msg_subject(const char *deviceid, const char *ssrc, const char *terminalid=NULL);
acl::string		 sip_build_msg_request(const char *method, const char *dst, const char *callid, int cseq, const char *from, const char *ftag, const char *to, const char*ttag);
acl::string		 sip_build_msg_answer(const char *msg, const char *status);
acl::string		 sip_build_msg_register(const char *to, const char *auth, int cseq, int expires, const char *callid=NULL, const char *ftag=NULL);
acl::string		 sip_build_msg_keepalive(const char *to);
acl::string		 sip_build_msg_invite(const char *to, const char *subject, int cseq, const char *callid = NULL, const char *ftag = NULL);
acl::string		 sip_build_msg_sdp(const char *user, const char *uri, const char *time, const char *recvip, int recvport, int type, int drct, int prot=0, int speed=0, int media=0, int playload=0, int stream=0);
acl::string		 sip_build_msg_ack(const char *msg);
acl::string		 sip_build_msg_bye(const char *to, int cseq, const char *callid, const char *ftag, const char*ttag);

SIP_EVENT_TYPE	 sip_get_event_type(const char *msg);
SIP_MESSAGE_TYPE sip_get_message_type(const char *msg);
SIP_CONTENT_TYPE sip_get_content_type(const char *msg);
SIP_RECORD_TYPE	 sip_get_record_type(const char *type);

acl::string		 sip_get_localtime();
int				 sip_get_user_role(const char *user);
//nonl 去掉换行符 true 是 false 否
acl::string		 sip_get_header(const char *msg, const char *head, bool nonl=true);
int				 sip_get_status_code(const char *msg);
acl::string		 sip_get_from_user(const char *msg);
acl::string		 sip_get_from_addr(const char *msg);
acl::string		 sip_get_from_tag(const char *msg);
acl::string		 sip_get_to_uri(const char *msg);
acl::string		 sip_get_to_user(const char *msg);
acl::string		 sip_get_to_addr(const char *msg);
acl::string		 sip_get_to_tag(const char *msg);
int				 sip_get_cseq_num(const char *msg);
acl::string		 sip_get_cseq_method(const char *msg);
//REGISTER HEADER
acl::string		 sip_get_authorization_username(const char *msg);
acl::string		 sip_get_authorization_realm(const char *msg);
acl::string		 sip_get_authorization_nonce(const char *msg);
acl::string		 sip_get_authorization_uri(const char *msg);
acl::string		 sip_get_authorization_response(const char *msg);
acl::string		 sip_get_authorization_algorithm(const char *msg);
acl::string		 sip_get_www_authenticate_realm(const char *msg);
acl::string		 sip_get_www_authenticate_nonce(const char *msg);

SIP_CONTENT_TYPE sip_get_body(const char *msg, acl::string &strBody);
void			 sip_get_sdp_info(const char *sdp, sip_sdp_info *info);

acl::string		 sip_set_header(const char *msg, const char *head, const char *value);

acl::string		 sip_set_body(const char *msg, const char *body, SIP_CONTENT_TYPE type);
acl::string		 sip_set_sdp_y(const char *sdp, const char *ssrc);
acl::string		 sip_set_sdp_f(const char *sdp, int encode, int resolution, int frame, int bitrate, int kbps, int voice, int bitsize, int samples);







