#pragma once
#include "config.h"

#include <time.h>
#include <math.h>


/********ö������**************************************/

typedef enum sip_event_type		//��Ϣ�¼�����
{
	SIP_EVENT_UNKNOWN,		//δ֪�¼�
	SIP_REGISTER_REQUEST,	//ע������
	SIP_REGISTER_SUCCESS,   //ע��ɹ�
	SIP_REGISTER_FAILURE,   //ע��ʧ��
	SIP_INVITE_REQUEST,		//�㲥����
	SIP_INVITE_PROCEEDING,	//�㲥�ȴ�
	SIP_INVITE_SUCCESS,		//�㲥�ɹ�
	SIP_INVITE_FAILURE,		//�㲥ʧ��
	SIP_ACK_REQUEST,		//�㲥ȷ��	
	SIP_BYE_REQUEST,		//�ر�����
	SIP_BYE_SUCCESS,		//�رճɹ�
	SIP_BYE_FAILURE,		//�ر�ʧ��
	SIP_CANCEL_REQUEST,		//ȡ������
	SIP_CANCEL_SUCCESS,		//ȡ���ɹ�	
	SIP_CANCEL_FAILURE,		//ȡ��ʧ��
	SIP_INFO_REQUEST,		//��������
	SIP_INFO_SUCCESS,		//���Ƴɹ�
	SIP_INFO_FAILURE,		//����ʧ��
	SIP_SUBSCRIBE_REQUEST,	//��������
	SIP_SUBSCRIBE_SUCCESS,	//���ĳɹ�
	SIP_SUBSCRIBE_FAILURE,	//����ʧ��
	SIP_NOTIFY_EVENT,		//֪ͨ��Ϣ
	SIP_NOTIFY_SUCCESS,		//֪ͨ�ɹ�
	SIP_NOTIFY_FAILURE,		//֪ͨʧ��
	SIP_MESSAGE_EVENT,		//��Ϣ����
	SIP_MESSAGE_SUCCESS,	//��Ϣ�ɹ�
	SIP_MESSAGE_FAILURES,	//��Ϣʧ��
	SIP_OPTIONS_REQUEST,	//��ѯ����
	SIP_OPTIONS_RESPONSE	//��ѯ��Ӧ

}SIP_EVENT_TYPE;

typedef enum sip_message_type	//��Ϣ��������
{
	SIP_MESSAGE_UNKNOWN,
	SIP_CONTROL_PTZCMD,			//��̨����
	SIP_CONTROL_TELEBOOT,		//Զ������(�豸)
	SIP_CONTROL_RECORDCMD,		//�ֶ�¼��(�豸)
	SIP_CONTROL_GUARDCMD,		//����/����
	SIP_CONTROL_ALARMCMD,		//������λ
	SIP_CONTROL_IFAMECMD,		//ǿ��I֡
	SIP_CONTROL_DRAGZOOMIN,		//����Ŵ�
	SIP_CONTROL_DRAGZOOMOUT,	//������С
	SIP_CONTROL_HOMEPOSITION,	//��������
	SIP_CONTROL_CONFIG,			//���ÿ���
	SIP_RESPONSE_CONTROL,		//����Ӧ��
	SIP_QUERY_PRESETQUERY,		//Ԥ��λ��ѯ
	SIP_RESPONSE_PRESETQUERY,	//Ԥ��λ��Ӧ
	SIP_QUERY_DEVICESTATUS,		//�豸״̬��ѯ
	SIP_RESPONSE_DEVICESTATUS,	//�豸״̬��Ӧ
	SIP_QUERY_CATALOG,			//Ŀ¼��Ϣ��ѯ
	SIP_RESPONSE_CATALOG,		//Ŀ¼��Ϣ��Ӧ
	SIP_QUERY_DEVICEINFO,		//�豸��Ϣ��ѯ
	SIP_RESPONSE_DEVICEINFO,	//�豸��Ϣ��Ӧ
	SIP_QUERY_RECORDINFO,		//¼��Ŀ¼����
	SIP_RESPONSE_RECORDINFO,	//Ŀ¼������Ӧ
	SIP_QUERY_ALARM,			//������ѯ
	SIP_RESPONSE_QUERY_ALARM,	//������ѯ��Ӧ
	SIP_QUERY_CONFIGDOWNLOAD,	//�豸���ò�ѯ
	SIP_RESPONSE_CONFIGDOWNLOAD,//�豸���û�Ӧ
	SIP_QUERY_MOBILEPOSITION,	//��λ�����ѯ
	SIP_NOTIFY_MOBILEPOSITION,	//��λ�����Ӧ
	SIP_NOTIFY_KEEPALIVE,		//����֪ͨ
	SIP_NOTIFY_MEDIASTATUS,		//ý��������֪ͨ
	SIP_NOTIFY_ALARM,			//����֪ͨ
	SIP_RESPONSE_NOTIFY_ALARM,	//����֪ͨ��Ӧ

	SIP_NOTIFY_BROADCAST,		//�����㲥֪ͨ
	SIP_RESPONSE_BROADCAST		//�����㲥Ӧ��
	
}SIP_MESSAGE_TYPE;

typedef enum sip_invite_type	//�㲥����
{
	SIP_INVITE_UNKNOWN,
	SIP_INVITE_PLAY,		//ʵʱ�㲥
	SIP_INVITE_PLAYBACK,	//��ʷ�㲥
	SIP_INVITE_DOWNLOAD,	//���ص㲥
	SIP_INVITE_TALK,		//�����Խ�
	SIP_INVITE_MEDIASERVER	//ý��������

}SIP_INVITE_TYPE;

typedef enum sip_content_type	//��Ϣ������
{
	SIP_APPLICATION_UNKNOWN,
	SIP_APPLICATION_XML,	//XML
	SIP_APPLICATION_SDP,	//SDP
	SIP_APPLICATION_RTSP	//RTSP

}SIP_CONTENT_TYPE;

typedef enum sip_direction_type	//ý������������
{
	SIP_DIRECTION_UNKNOWN,
	SIP_RECVONLY,			//ֻ����
	SIP_SENDONLY,			//ֻ����
	SIP_SENDRECV			//���պͷ���

}SIP_DIRECTION_TYPE;

typedef enum sip_protocol_type
{
	SIP_TRANSFER_UDP,		 //UDP����
	SIP_TRANSFER_TCP_ACTIVE, //TCP��������
	SIP_TRANSFER_TCP_PASSIVE //TCP��������
}SIP_PROTOCOL_TYPE;

typedef enum sip_media_type
{
	SIP_MEDIA_VIDEO,		//��Ƶ��
	SIP_MEDIA_AUDIO			//��Ƶ��
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

typedef enum sip_resolution_type //�ֱ�������
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

typedef enum sip_info_type		//��������
{
	SIP_INFO_UNKNOWN,
	SIP_INFO_PLAY,			//�طſ���
	SIP_INFO_PAUSE,			//�ط���ͣ
	SIP_INFO_TEARDOWN		//����ֹͣ

}SIP_INFO_TYPE;

/********��������**************************************/
typedef enum sip_alarm_method
{
	SIP_ALARM_ALL,			//ȫ��
	SIP_ALARM_PHONE,		//�绰���� 
	SIP_ALARM_DEVICE,       //�豸����
	SIP_ALARM_SMS,			//���ű���
	SIP_ALARM_GPS,			//GPS����
	SIP_ALARM_VIDEO,		//��Ƶ����
	SIP_ALARM_DEVBROKEN,	//�豸���ϱ���
	SIP_ALARM_OTHER,		//��������
	SIP_ALARM_PEOPLE,		//���˱���
	SIP_ALARM_VEHICLE		//��������
}SIP_ARARM_METHOD;

typedef enum sip_alarm_device_type	//�豸��������
{
	SIP_ALARM_LOSE = 1,		//�豸��ʧ
	SIP_ALARM_DISASSEMBLY,	//���𱨾�
	SIP_ALARM_DISKFULL,		//������
	SIP_ALARM_HIGHTTEMP,	//�豸����
	SIP_ALARM_LOWTEMP		//�豸����
	
}SIP_ALARM_DEVICE_TYPE;

typedef enum sip_alarm_video_type	//��Ƶ��������
{
	SIP_ALARM_BLOCK,		//��Ƶ�ڵ�
	SIP_ALARM_MANUAL,		//�˹�����
	SIP_ALARM_MOVING,		//�ƶ����
	SIP_ALARM_LEAVEOVER,	//������
	SIP_ALARM_REMOVAL,		//�����Ƴ�
	SIP_ALARM_TRIPPINGLINE, //Խ�߼��
	SIP_ALARM_INVASION,		//���ּ��
	SIP_ALARM_RETROGRADE,	//���м��
	SIP_ALARM_WANDERING,	//�ǻ����
	SIP_ALARM_FLOWCOUNT,	//����ͳ��
	SIP_ALARM_CROWDED,		//��Ա�ܶ�
	SIP_ALARM_ANOMALY,		//��Ƶ�쳣
	SIP_ALARM_FASTMOVING	//�����ƶ�

}SIP_ALARM_VIDEO_TYPE;

typedef enum sip_alarm_devbroken_type
{
	SIP_ALARM_DISKBROKEN = 1, //���̹���
	SIP_ALARM_FANBROKEN		  //���ȹ���

}SIP_ALARM_DEVBORKEN_TYPE;

typedef enum sip_alarm_people_type
{
	SIP_ALARM_FACE,				//�������
	SIP_ALARM_HUMANBODY			//������

}SIP_ALARM_PEOPLE_TYPE;

typedef enum sip_alarm_vehicle_type
{
	SIP_ALARM_CAR,
	SIP_ALARM_NOMOTO

}SIP_ALARM_VEHICLE_TYPE;

typedef enum sip_alarm_invasion_event
{
	SIP_ALARM_EVENT_ENTERAREA = 1, //��������
	SIP_ALARM_EVENT_LEAVEAREA	   //�뿪����

}SIP_ALARM_INVASION_EVENT;

typedef enum sip_record_type
{
	SIP_RECORDTYPE_ALL,				//ȫ��¼��
	SIP_RECORDTYPE_TIME,			//��ʱ¼��
	SIP_RECORDTYPE_MOVE,			//���¼��
	SIP_RECORDTYPE_ALARM,			//�澯¼��
	SIP_RECORDTYPE_MANUAL			//�ֶ�¼��

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


/********ָ����**************************************/
#define SIP_PTZCMD_NONE				0xFF
#define SIP_PTZCMD_STOP				0x00		//ֹͣ
#define SIP_PTZCMD_UP				0x08		//����
#define SIP_PTZCMD_DOWN				0x04		//����
#define SIP_PTZCMD_LEFT				0x02		//����
#define SIP_PTZCMD_RIGHT			0x01		//����
#define SIP_PTZCMD_LU				0x0A		//����
#define SIP_PTZCMD_LD				0x06		//����
#define SIP_PTZCMD_RU				0x09		//����
#define SIP_PTZCMD_RD				0x05		//����
#define SIP_PTZCMD_ZOOM_IN			0x10		//�Ŵ�
#define SIP_PTZCMD_ZOOM_OUT			0x20		//��С

#define SIP_PTZCMD_FI_IRIS_IN		0x48		//��Ȧ�Ŵ�
#define SIP_PTZCMD_FI_IRIS_OUT		0x44		//��Ȧ��С
#define SIP_PTZCMD_FI_FOCUS_IN		0x42		//�۽�����
#define SIP_PTZCMD_FI_FOCUS_OUT		0x41		//�ۼ���Զ
#define SIP_PTZCMD_FI_STOP			0x40		//����ֹͣ

#define SIP_PTZCMD_SET				0x81		//Ԥ��λ����
#define SIP_PTZCMD_GOTO				0x82		//Ԥ��λ��ת
#define SIP_PTZCMD_DELETE			0x83		//Ԥ��λɾ��
#define SIP_PTZCMD_CRUISE_ADD		0x84		//Ѳ�������
#define	SIP_PTZCMD_CRUISE_DEL		0x85		//Ѳ����ɾ��
#define SIP_PTZCMD_CRUISE_SPEED		0x86		//Ѳ���ٶ�
#define SIP_PTZCMD_CRUISE_DTIME		0x87		//Ѳ��ͣ��ʱ��
#define SIP_PTZCMD_CRUISE_RUN		0x88		//Ѳ����ʼ

#define SIP_PTZCMD_AUTO_RUN			0x89		//�Զ�ɨ�迪ʼ
#define SIP_PTZCMD_AUTO_LBORDER		0x89		//�Զ�ɨ����߽�
#define SIP_PTZCMD_AUTO_RBORDER		0x89		//�Զ�ɨ���ұ߽�
#define SIP_PTZCMD_AUTO_SPEED		0x8A		//�Զ�ɨ���ٶ�

#define SIP_PTZCMD_AUXIOPEN			0x8C		//�������ش�(��ˢ)
#define SIP_PTZCMD_AUXICLOSE		0x8D		//�������عر�

#define SIP_PTZCMD_DRAGZOOM_IN		0x76
#define SIP_PTZCMD_DRAGZOOM_OUT		0X77
#define SIP_PTZCMD_INITIAL			0x78
#define SIP_PTZCMD_UNINITIAL		0X79

#define SIP_PTZCMD_LOCK				0xC0
#define SIP_PTZCMD_UNLOCK			0X80
/***********************************************************/

#define SIP_STATUS_100			"100 Trying"								//��������
#define SIP_STATUS_101			"101 Dialog Establishement"					//�Ự����
#define SIP_STATUS_200			"200 OK"									//�Ự�ɹ�
#define SIP_STATUS_201			"201 Canceling"								//�Ựȡ��
#define SIP_STATUS_400			"400 Bad Request"							//�������
#define SIP_STATUS_401			"401 Unauthorized"							//δ��֤
#define SIP_STATUS_403			"403 Forbidden"								//��ֹ����
#define SIP_STATUS_404			"404 Not Found"								//δ�ҵ�
#define	SIP_STATUS_405			"405 Method Not Allowed"					//��֧�ֵ�����
#define SIP_STATUS_408			"408 Request Timeout"						//�Ự��ʱ
#define SIP_STATUS_457			"457 Invalid Range"							//��Ч��Χ
#define SIP_STATUS_481			"481 Dialog/Transaction Does Not Exist"		//û��ƥ��ĻỰ		
#define SIP_STATUS_482			"482 Loop Detected"							//ѭ������
#define SIP_STATUS_486			"486 Busy Here"								//�豸æ
#define SIP_STATUS_487			"487 Request Terminated"					//������ֹ
#define SIP_STATUS_488			"488 Not Acceptable Here"					//SDP����
#define SIP_STATUS_500			"500 Server Internal Error"					//�����ڲ�����
#define SIP_STATUS_502			"502 Bad Gateway"							//��Ч��Ӧ��
#define SIP_STATUS_503			"503 Service Unavailable"					//����������
#define SIP_STATUS_551			"551 Option not supported"					//��֧�ֵĲ���




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
//nonl ȥ�����з� true �� false ��
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







