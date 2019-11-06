#ifndef   _NVSSDKDEF_H
#define   _NVSSDKDEF_H
//V1.5 �汾    (��V1.4�汾һ��ͷ�ļ�)
#include "NVSTypeDefine.h"

typedef struct _tagCLInfo
{
    char sChannelName[32];
    unsigned char nChannelNum;
    char sChannelNo[44];
}CLInfo;

#define DVR_DATA_INIT    1 //Ԥ������
#define DVR_DATA_STREAM  2 //������

//#define DVR_RECORDFILE_ALL      0
//#define DVR_RECORDFILE_MANUAL   1
//#define DVR_RECORDFILE_WARNING  2
//#define DVR_RECORDFILE_TIME     3

#define XY_PROPERTY_ISSUPPORT_PACK 0//��ѯ����Ҫ����ԭʼ��(�����ɷְ�) ,����true:��  false:��
#define XY_PROPERTY_ISHAVEHEAD     1//��ѯ���а�ͷ true:��  false:��

typedef  void(CALLBACK  *LPCAPTURESTREAMCALLBACK)(LONG  identify,int nDataType,BYTE* pBuffer,int nBufferSize,void* pUser);

typedef  void(CALLBACK  *LPGETRECORDFILECALLBACK)(LONG  identify,bool bValidate,char* sFileName,char* startTime,char* endTime,int nFileSize,void* pUser);

typedef  void(CALLBACK  *LPDOWNLOADRECORDFILECALLBACK)(LONG  identify,char* sFileName,int nLen,void* pUser);

typedef  void(CALLBACK * LPSTREAMBUFFERCALLBACK)(int nPort,void* pUser);

typedef  void(CALLBACK *LPDRAWCBCALLLBACK)(LONG  identify, LONG lRealHandle, DWORD hdc, void *pUser);

//YUV�ص���������
/*
Param:  pCameraID:  ��ͷ����20λ����
pBuf: ������
nSize: �����ݳ���
nWidth: ��Ƶ���Ŀ�
nHeight: ��Ƶ���ĸ�
nStamp: ʱ���
return:��
*/
typedef  void(CALLBACK* LPYUVCALLBACK)(char * pCameraID, unsigned char *pBuf, long nSize, long nWidth, long nHeight, long nStamp);

//�ļ������ص�
typedef  void(CALLBACK* pFileOverCB)(void * pUser);

typedef struct{
    LONG nWidth;  //�������λ���ء��������Ƶ������Ϊ0��
    LONG nHeight; //����ߡ��������Ƶ������Ϊ0��
    LONG nStamp;  //ʱ����Ϣ����λ���롣
    LONG nType;   //�������ͣ�T_AUDIO16��T_RGB32�� T_YV12��
    LONG nFrameRate; //����ʱ������ͼ��֡�ʡ�
}FRAME_INFO_D;
typedef void (CALLBACK *LPDecCBFun)(LONG nPort,char * pBuf,LONG nSize,FRAME_INFO_D * pFrameInfo, int nCameraID);

typedef struct _recordFile
{
    int nType;		    //0=���ļ�������;1=��ʱ�䲥��
    char sFileName[256];
    char startTime[20];//��ʽ��2006-11-06 10:10:00
    char endTime[20];//��ʽ��2006-11-06 10:10:00
    int  nSize;
} RECORDFILE;

typedef struct _infoCamera
{
    DWORD cameraId ;	  //��ͷID
    char cameraName[50];  //��ͷ����

}INFOCAMERA;

typedef struct _requestStreamState
{
    int nCameraId;
    char sStreamServerIP[20];//IP��ַ
}REQUESTSTREAMSTATE;

typedef struct _StreamServerWorkState
{
    int ChannelLoad ; //����ͨ������
    int MonitorLoad ; //�ͻ������Ӹ���
    int SendLoad;	  //����·��
    int MaxSendCount; //�����·��
    int MaxChannel;   //���ͨ��������
    char sStreamServerIP[20];
}STREAMSERVERWORKSTATE;


typedef int RECORDQUERYTYPE;

//record file type
#define RECORD_FILE_ALL             0   //ȫ��¼��
#define RECORD_FILE_TIME            1   //��ʱ¼��
#define RECORD_FILE_MOVE            2   //�ƶ����
#define RECORD_FILE_ALARM           3   //����¼��
#define RECORD_FILE_ALARMORDYNAMIC  4   //�������߶���
#define RECORD_FILE_ALARMANDDYNAMIC 5   //���ⱨ��
#define RECORD_FILE_COMMAND         6   //�����
#define RECORD_FILE_MANUAL          7   //�ֶ�����
#define RECORD_FILE_OUTER           8   //�ⲿ����
#define RECORD_FILE_CARD            9   //���Ų�ѯ
#define RECORD_FILE_GROUP           10   //��ϲ�ѯ
#define RECORD_FILE_ALLALARM        11   //���б���_���ڴ�
//Ŀǰ��¼�˺����ʹ󻪵�����,������װ������SDKʱ���Լ�������




//��̨�����������
#define CAMERA_PAN_UP        1        //��̨����
#define CAMERA_PAN_DOWN      2        //��̨����
#define CAMERA_PAN_LEFT      3        //��̨����
#define CAMERA_PAN_RIGHT     4        //��̨����
#define CAMERA_FOCUS_IN      5        //����ǰ��
#define CAMERA_FOCUS_OUT     6        //������
#define CAMERA_IRIS_IN       7        //��Ȧ����
#define CAMERA_IRIS_OUT      8        //��Ȧ��С
#define CAMERA_ZOOM_IN       9        //���ʵ���
#define CAMERA_ZOOM_OUT      10       //���ʵ�С
#define CAMERA_LIGHT_CTRL    11       //�ƿ���
#define CAMERA_BRUSH_CTRL    12       //��ˢ����
#define CAMERA_HEATER_CTRL   13       //����������
#define CAMERA_AUX_CTRL      14       //�����豸����
#define CAMERA_AUTO_TURN	 15		  //��̨�Զ���ת
#define	CAMERA_LOCK			 16
#define	CAMERA_UNLOCK		 17

#define CAMERA_PAN_LU		 20		  //����
#define CAMERA_PAN_LD		 21		  //����
#define CAMERA_PAN_RU		 22		  //����
#define CAMERA_PAN_RD		 23		  //����

#define CAMERA_SETP			 24		  //���ڶ�λ��ʹ��nSpeed��������ԭ��������		
#define CAMERA_SETN			 25		  //���ڶ�λ��ʹ��nSpeed�������ö�λ��������		

//��̨Ԥ���������
#define PTZ_PRESET_SET       1        //����Ԥ�õ�
#define PTZ_PRESET_DELETE    2        //ɾ��Ԥ�õ�
#define PTZ_PRESET_GOTO      3        //ת��Ԥ�õ�

//�طſ�������
#define REPLAY_CTRL_PLAYPAUSE       1//��ͣ����
#define REPLAY_CTRL_PLAYRESTART     2//�ָ�����
#define REPLAY_CTRL_PLAYFAST        3//���
#define REPLAY_CTRL_PLAYSLOW        4//����
#define REPLAY_CTRL_PLAYNORMAL      5//�����ٶ�
#define REPLAY_CTRL_PLAYFRAME       6//��֡��
#define REPLAY_CTRL_PLAYSTARTAUDIO  7//������
#define REPLAY_CTRL_PLAYSTOPAUDIO   8//�ر�����
#define REPLAY_CTRL_PLAYAUDIOVOLUME 9//��������
#define REPLAY_CTRL_PLAYSETPOS      10//�ı��ļ��طŵĽ���
#define REPLAY_CTRL_PLAYGETPOS      11//��ȡ�ļ��طŵĽ���
#define REPLAY_CTRL_PLAYGETTIME     12//��ȡ��ǰ�Ѿ����ŵ�ʱ��
#define REPLAY_CTRL_PLAYGETFRAME    13//��ȡ��ǰ�Ѿ����ŵ�֡��
#define REPLAY_CTRL_GETTOTALFRAMES  14//��ȡ��ǰ�����ļ��ܵ�֡��
#define REPLAY_CTRL_GETTOTALTIME    15//��ȡ��ǰ�����ļ��ܵ�ʱ��
#define REPLAY_CTRL_PLAYSTART       16//��ʼ����
#define REPLAY_CTRL_PLAYSTOP        17//ֹͣ����
#define REPLAY_CTRL_GETFILESIZE     18//��ȡ�ļ��ܴ�С
#define REPLAY_CTRL_PLAYSETPOSBY1440 19//��1440�����ȷ��ؽ���
#define REPLAY_CTRL_PLAYGETOSDTIME	 20//��ȡ��ǰ���ŵ�OSDʱ��

#define REPLAY_CTRL_PLAYSETTIME		26//��ʱ�䲥��

//���ز��ſ�������
#define LOCPLAY_CTRL_PLAYPAUSE       1	//��ͣ����
#define LOCPLAY_CTRL_PLAYRESTART     2	//�ָ�����
#define LOCPLAY_CTRL_PLAYFAST        3	//���
#define LOCPLAY_CTRL_PLAYSLOW        4	//����
#define LOCPLAY_CTRL_PLAYNORMAL      5	//�����ٶ�
#define LOCPLAY_CTRL_PLAYFRAME       6	//��֡��
#define LOCPLAY_CTRL_PLAYSTARTAUDIO  7	//������
#define LOCPLAY_CTRL_PLAYSTOPAUDIO   8	//�ر�����
#define LOCPLAY_CTRL_PLAYAUDIOVOLUME 9	//��������
#define LOCPLAY_CTRL_PLAYSETPOS      10	//�ı��ļ��طŵĽ���
#define LOCPLAY_CTRL_PLAYGETPOS      11	//��ȡ�ļ��طŵĽ���
#define LOCPLAY_CTRL_PLAYGETTIME     12	//��ȡ��ǰ�Ѿ����ŵ�ʱ��
#define LOCPLAY_CTRL_PLAYGETFRAME    13	//��ȡ��ǰ�Ѿ����ŵ�֡��
#define LOCPLAY_CTRL_GETTOTALFRAMES  14	//��ȡ��ǰ�����ļ��ܵ�֡��
#define LOCPLAY_CTRL_GETTOTALTIME    15	//��ȡ��ǰ�����ļ��ܵ�ʱ��
#define LOCPLAY_CTRL_PLAYSETFRAME    16	//���õ�ǰ�����ļ�֡��
#define LOCPLAY_CTRL_PLAYSETPOSBY1440	17//��1440�����ȷ��ؽ���
#define LOCPLAY_CTRL_PLAYGETOSDTIME		18//��ȡ��ǰ���ŵ�OSDʱ��

//Զ����������
#define CONFIG_GET_DEVICECFG		100		//��ȡ�豸����
#define CONFIG_SET_DEVICECFG		101		//�����豸����
#define CONFIG_GET_NETCFG			102		//��ȡ�������
#define CONFIG_SET_NETCFG			103		//�����������
#define CONFIG_GET_PICCFG			104		//��ȡͼ�����
#define CONFIG_SET_PICCFG			105		//����ͼ�����
#define CONFIG_GET_COMPRESSCFG		106		//��ȡѹ������
#define CONFIG_SET_COMPRESSCFG		107		//����ѹ������
#define CONFIG_GET_RECORDCFG		108		//��ȡ¼��ʱ�����
#define CONFIG_SET_RECORDCFG		109		//����¼��ʱ�����
#define CONFIG_GET_DECODERCFG		110		//��ȡ����������
#define CONFIG_SET_DECODERCFG		111		//���ý���������
#define CONFIG_GET_RS232CFG 		112		//��ȡ232���ڲ���
#define CONFIG_SET_RS232CFG			113		//����232���ڲ���
#define CONFIG_GET_ALARMINCFG 		114		//��ȡ�����������
#define CONFIG_SET_ALARMINCFG		115		//���ñ����������
#define CONFIG_GET_ALARMOUTCFG 		116		//��ȡ�����������
#define CONFIG_SET_ALARMOUTCFG		117		//���ñ����������
#define CONFIG_GET_TIMECFG 			118		//��ȡDVRʱ��
#define CONFIG_SET_TIMECFG			119		//����DVRʱ��
#define CONFIG_GET_PREVIEWCFG 		120		//��ȡԤ������
#define CONFIG_SET_PREVIEWCFG		121		//����Ԥ������
#define CONFIG_GET_VIDEOOUTCFG 		122		//��ȡ��Ƶ�������
#define CONFIG_SET_VIDEOOUTCFG		123		//������Ƶ�������
#define CONFIG_GET_USERCFG 			124		//��ȡ�û�����
#define CONFIG_SET_USERCFG			125		//�����û�����
#define CONFIG_GET_EXCEPTIONCFG 	126		//��ȡ�쳣����
#define CONFIG_SET_EXCEPTIONCFG		127		//�����쳣����
#define CONFIG_GET_ZONEANDDST		128		//��ȡʱ������ʱ�Ʋ���
#define CONFIG_SET_ZONEANDDST		129		//����ʱ������ʱ�Ʋ���
#define CONFIG_GET_SHOWSTRING		130		//��ȡ�����ַ�����
#define CONFIG_SET_SHOWSTRING		131		//���õ����ַ�����
#define CONFIG_GET_EVENTCOMPCFG		132		//��ȡ�¼�����¼�����
#define CONFIG_SET_EVENTCOMPCFG		133		//�����¼�����¼�����
#define CONFIG_GET_FTPCFG			134		//��ȡץͼ��FTP����(����)
#define CONFIG_SET_FTPCFG			135		//����ץͼ��FTP����(����)


/*******************ȫ�ִ����� begin**********************/
//1������
#define HK_DVR_NOERROR 					1000	//û�д���
#define HK_DVR_PASSWORD_ERROR 			1001	//�û����������
#define HK_DVR_NOENOUGHPRI 				1002	//Ȩ�޲���
#define HK_DVR_NOINIT 					1003	//û�г�ʼ��
#define HK_DVR_CHANNEL_ERROR 			1004	//ͨ���Ŵ���
#define HK_DVR_OVER_MAXLINK 			    1005	//���ӵ�DVR�Ŀͻ��˸����������
#define HK_DVR_VERSIONNOMATCH			1006	//�汾��ƥ��
#define HK_DVR_NETWORK_FAIL_CONNECT		1007	//���ӷ�����ʧ��
#define HK_DVR_NETWORK_SEND_ERROR		1008	//�����������ʧ��
#define HK_DVR_NETWORK_RECV_ERROR		1009	//�ӷ�������������ʧ��
#define HK_DVR_NETWORK_RECV_TIMEOUT		1010	//�ӷ������������ݳ�ʱ
#define HK_DVR_NETWORK_ERRORDATA		    1011	//���͵���������
#define HK_DVR_ORDER_ERROR				1012	//���ô������
#define HK_DVR_OPERNOPERMIT				1013	//�޴�Ȩ��
#define HK_DVR_COMMANDTIMEOUT			1014	//DVR����ִ�г�ʱ
#define HK_DVR_ERRORSERIALPORT			1015	//���ںŴ���
#define HK_DVR_ERRORALARMPORT			1016	//�����˿ڴ���
#define HK_DVR_PARAMETER_ERROR 			1017  //��������
#define HK_DVR_CHAN_EXCEPTION			1018	//������ͨ�����ڴ���״̬
#define HK_DVR_NODISK					1019	//û��Ӳ��
#define HK_DVR_ERRORDISKNUM				1020	//Ӳ�̺Ŵ���
#define HK_DVR_DISK_FULL				    1021	//������Ӳ����
#define HK_DVR_DISK_ERROR				1022	//������Ӳ�̳���
#define HK_DVR_NOSUPPORT				    1023	//��������֧��
#define HK_DVR_BUSY						1024	//������æ
#define HK_DVR_MODIFY_FAIL				1025	//�������޸Ĳ��ɹ�
#define HK_DVR_PASSWORD_FORMAT_ERROR	    1026	//���������ʽ����ȷ
#define HK_DVR_DISK_FORMATING			1027	//Ӳ�����ڸ�ʽ����������������
#define HK_DVR_DVRNORESOURCE			    1028	//DVR��Դ����
#define	HK_DVR_DVROPRATEFAILED			1029  //DVR����ʧ��
#define HK_DVR_OPENHOSTSOUND_FAIL 		1030  //��PC����ʧ��
#define HK_DVR_DVRVOICEOPENED 			1031  //�����������Խ���ռ��
#define	HK_DVR_TIMEINPUTERROR			1032  //ʱ�����벻��ȷ
#define	HK_DVR_NOSPECFILE				1033  //�ط�ʱ������û��ָ�����ļ�
#define HK_DVR_CREATEFILE_ERROR			1034	//�����ļ�����
#define	HK_DVR_FILEOPENFAIL				1035  //���ļ�����
#define	HK_DVR_OPERNOTFINISH			    1036  //�ϴεĲ�����û�����
#define	HK_DVR_GETPLAYTIMEFAIL			1037  //��ȡ��ǰ���ŵ�ʱ�����
#define	HK_DVR_PLAYFAIL					1038  //���ų���
#define HK_DVR_FILEFORMAT_ERROR			1039  //�ļ���ʽ����ȷ
#define HK_DVR_DIR_ERROR				    1040	//·������
#define HK_DVR_ALLOC_RESOURCE_ERROR		1041  //��Դ�������
#define HK_DVR_AUDIO_MODE_ERROR			1042	//����ģʽ����
#define HK_DVR_NOENOUGH_BUF				1043	//������̫С
#define HK_DVR_CREATESOCKET_ERROR		1044	//����SOCKET����
#define HK_DVR_SETSOCKET_ERROR			1045	//����SOCKET����
#define HK_DVR_MAX_NUM					1046	//�����ﵽ���
#define HK_DVR_USERNOTEXIST				1047	//�û�������
#define HK_DVR_WRITEFLASHERROR			1048  //дFLASH����
#define HK_DVR_UPGRADEFAIL				1049  //DVR����ʧ��
#define HK_DVR_CARDHAVEINIT				1050  //���뿨�Ѿ���ʼ����
#define HK_DVR_PLAYERFAILED				1051	//���ò��ſ���ĳ������ʧ��
#define HK_DVR_MAX_USERNUM				1052  //�豸���û����ﵽ���
#define HK_DVR_GETLOCALIPANDMACFAIL		1053  //��ÿͻ��˵�IP��ַ�������ַʧ��
#define HK_DVR_NOENCODEING				1054	//��ͨ��û�б���
#define HK_DVR_IPMISMATCH				1055	//IP��ַ��ƥ��
#define HK_DVR_MACMISMATCH				1056	//MAC��ַ��ƥ��
#define HK_DVR_UPGRADELANGMISMATCH		1057	//�����ļ����Բ�ƥ��
#define HK_DVR_MAX_PLAYERPORT			1058	//������·���ﵽ���
#define HK_DVR_NOSPACEBACKUP			    1059	//�����豸��û���㹻�ռ���б���
#define HK_DVR_NODEVICEBACKUP			1060	//û���ҵ�ָ���ı����豸
#define HK_DVR_PICTURE_BITS_ERROR		1061	//ͼ����λ����������24ɫ
#define HK_DVR_PICTURE_DIMENSION_ERROR	1062	//ͼƬ��*���ޣ� ��128*256
#define HK_DVR_PICTURE_SIZ_ERROR		    1063	//ͼƬ��С���ޣ���100K
#define HK_DVR_LOADPLAYERSDKFAILED		1064	//���뵱ǰĿ¼��Player Sdk����
#define HK_DVR_LOADPLAYERSDKPROC_ERROR	1065	//�Ҳ���Player Sdk��ĳ���������
#define HK_DVR_LOADDSSDKFAILED			1066	//���뵱ǰĿ¼��DSsdk����
#define HK_DVR_LOADDSSDKPROC_ERROR		1067	//�Ҳ���DsSdk��ĳ���������
#define HK_DVR_DSSDK_ERROR				1068	//����Ӳ�����DsSdk��ĳ������ʧ��
#define HK_DVR_VOICEMONOPOLIZE			1069	//��������ռ
#define HK_DVR_JOINMULTICASTFAILED		1070	//����ಥ��ʧ��
#define HK_DVR_CREATEDIR_ERROR			1071	//������־�ļ�Ŀ¼ʧ��
#define HK_DVR_BINDSOCKET_ERROR			1072	//���׽���ʧ��
#define HK_DVR_SOCKETCLOSE_ERROR		    1073	//socket�����жϣ��˴���ͨ�������������жϻ�Ŀ�ĵز��ɴ�
#define HK_DVR_USERID_ISUSING			1074	//ע��ʱ�û�ID���ڽ���ĳ����
#define HK_DVR_SOCKETLISTEN_ERROR		1075	//����ʧ��
#define HK_DVR_PROGRAM_EXCEPTION		    1076	//�����쳣
#define HK_DVR_WRITEFILE_FAILED			1077	//д�ļ�ʧ��
#define HK_DVR_FORMAT_READONLY			1078  //��ֹ��ʽ��ֻ��Ӳ��
#define HK_DVR_WITHSAMEUSERNAME		    1079  //�û����ýṹ�д�����ͬ���û���
#define HK_DVR_DEVICETYPE_ERROR          1080  /*�������ʱ�豸�ͺŲ�ƥ��*/
#define HK_DVR_LANGUAGE_ERROR            1081  /*�������ʱ���Բ�ƥ��*/
#define HK_DVR_PARAVERSION_ERROR         1082  /*�������ʱ����汾��ƥ��*/
#define HK_DVR_IPCHAN_NOTALIVE           1083  /*Ԥ��ʱ���IPͨ��������*/
#define HK_DVR_RTSP_SDK_ERROR			1084	/*���ظ���IPCͨѶ��StreamTransClientʧ��*/
#define HK_DVR_CONVERT_SDK_ERROR		    1085	/*����ת���CVT_StdToHikʧ��*/
#define HK_DVR_IPC_COUNT_OVERFLOW		1086  /*��������ip����ͨ����*/

#define  HK_PLAYM4_NOERROR					    1500	//no error
#define	 HK_PLAYM4_PARA_OVER				        1501	//input parameter is invalid;
#define  HK_PLAYM4_ORDER_ERROR				    1502	//The order of the function to be called is error.
#define	 HK_PLAYM4_TIMER_ERROR				    1503	//Create multimedia clock failed;
#define  HK_PLAYM4_DEC_VIDEO_ERROR			    1504	//Decode video data failed.
#define  HK_PLAYM4_DEC_AUDIO_ERROR			    1505	//Decode audio data failed.
#define	 HK_PLAYM4_ALLOC_MEMORY_ERROR		    1506	//Allocate memory failed.
#define  HK_PLAYM4_OPEN_FILE_ERROR			    1507	//Open the file failed.
#define  HK_PLAYM4_CREATE_OBJ_ERROR		        1508	//Create thread or event failed
#define  HK_PLAYM4_CREATE_DDRAW_ERROR		    1509	//Create DirectDraw object failed.
#define  HK_PLAYM4_CREATE_OFFSCREEN_ERROR        1510	//failed when creating off-screen surface.
#define  HK_PLAYM4_BUF_OVER			            1511	//buffer is overflow
#define  HK_PLAYM4_CREATE_SOUND_ERROR	        1512	//failed when creating audio device.
#define	 HK_PLAYM4_SET_VOLUME_ERROR	            1513	//Set volume failed
#define  HK_PLAYM4_SUPPORT_FILE_ONLY	            1514	//The function only support play file.
#define  HK_PLAYM4_SUPPORT_STREAM_ONLY	        1515	//The function only support play stream.
#define  HK_PLAYM4_SYS_NOT_SUPPORT		        1516	//System not support.
#define  HK_PLAYM4_FILEHEADER_UNKNOWN            1517	//No file header.
#define  HK_PLAYM4_VERSION_INCORRECT	            1518	//The version of decoder and encoder is not adapted.
#define  HK_PALYM4_INIT_DECODER_ERROR            1519	//Initialize decoder failed.
#define  HK_PLAYM4_CHECK_FILE_ERROR	            1520	//The file data is unknown.
#define  HK_PLAYM4_INIT_TIMER_ERROR	            1521	//Initialize multimedia clock failed.
#define	 HK_PLAYM4_BLT_ERROR			            1522	//Blt failed.
#define  HK_PLAYM4_UPDATE_ERROR		            1523	//Update failed.
#define  HK_PLAYM4_OPEN_FILE_ERROR_MULTI         1524   //openfile error, streamtype is multi
#define  HK_PLAYM4_OPEN_FILE_ERROR_VIDEO         1525   //openfile error, streamtype is video
#define  HK_PLAYM4_JPEG_COMPRESS_ERROR           1526   //JPEG compress error
#define  HK_PLAYM4_EXTRACT_NOT_SUPPORT           1527	//Don't support the version of this file.
#define  HK_PLAYM4_EXTRACT_DATA_ERROR            1528	//extract video data failed.

//2����

/*******************ȫ�ִ����� end**********************/


typedef struct _alarmInfo
{
    unsigned long ip;
    int  alarmType;
    int  alarmFlag;
} ALARMINFO;

typedef struct _logInfo
{
    char sTime[20];//��ʽ��2006-11-06 10:10:00
    char log[1024];
} LOGINFO;

typedef int LOGQUERYTYPE;
typedef int LOGERRORTYPE;

//log file type
#define LOG_FILE_ALL             0   //ȫ����־
#define LOG_FILE_TIME            1   //��ʱ���ѯ
#define LOG_FILE_TYPE            2   //�����Ͳ�ѯ
#define LOG_FILE_TIMETYPE        3   //��ʱ�����Ͳ�ѯ

//�����Ͳ�ѯʱ,�������Ͷ���:
#define LOG_FILE_TYPE_ALARM      0   //����
#define LOG_FILE_TYPE_EXCEPTION  1   //�쳣
#define LOG_FILE_TYPE_OPERATION  2   //����
#define LOG_FILE_TYPE_OTHER      3   //��������
//Ŀǰ��¼�˺����ʹ󻪵�����,������װ������SDKʱ���Լ�������


typedef  void(CALLBACK * LPALARMCALLBACK)(ALARMINFO* pAlarmInfo);

/*! ͸��ͨ���ص����� */
typedef void(CALLBACK* LPSERIALDATACALLBACK)(char* pRecDataBuffer,DWORD dwBufSize,int nCameraID);


//��ѯ�豸֧������(queryPorperySupport����ʹ��)
typedef int XYPROPROPERTY;
#define PROPERTY_ISSUPPORT_PACK 0//��ѯ����Ҫ����ԭʼ��(�����ɷְ�) ,����true:��  false:��
#define PROPERTY_ISHAVEHEAD     1//��ѯ���а�ͷ true:��  false:��



 #define REAL_STREAM  1 //ʵʱ��
 #define DVRFILE_STREAM  2 //DVR�ļ���
 #define STOREFILE_STREAM 3 //¼���ļ���
//��Ƶ�ļ����ſ���
#define PLAY_NOMAL                   1//��������
#define PLAY_FAST                    2//���
#define PLAY_SLOW                    3//����
#define PLAY_ONEBYONE                4//��֡����
//
typedef struct __RecordFileInfo
{
    char fileName[128];
    char startTime[64];
    char endTime[64];
}RecordFileInfo;

//2011-11-23, �ӿڲ����б�
//����DVR
typedef struct CONNECT_PARAM
{
    DWORD size;//�ɸ��ݴ˲������ṹ���С�����ݰ汾���죩
    const char* sIP;
    int nPort;
    const char* sType; //�豸����
    const char* sUser;
    const char* sPwd;
    int nChannel;
    int nModuleType;//ģ������(��ý��,����...)
    char chReser[32]; //�ɸ��ݴ˲���(������չ)
    //CONNECT_PARAM()
    //{
    //	ZeroMemory(this, sizeof CONNECT_PARAM);
    //}
}*PCONNECT_PARAM;

//*virtual  bool */captureStream(CAPTURE_PARAM *pParam) = 0;
typedef struct CAPTURE_PARAM
{
    DWORD size;
    LPCAPTURESTREAMCALLBACK lpCallBack;
    void* pUser;
    int nGetVideoType;
    char chReser[32];
    //CAPTURE_PARAM()
    //{
    //	ZeroMemory(this, sizeof(CAPTURE_PARAM));
    //}
}*PCAPTURE_PARAM;
//virtual  bool controlPTZSpeedWithChannel(CONTROL_PARAM * pParam) = 0;
typedef struct CONTROL_PARAM
{
    DWORD size;
    int nCmd;
    bool bEnable;
    int nSpeed;
    int nChannel;
    char chReser[32];
    //CONTROL_PARAM()
    //{
    //	ZeroMemory(this, sizeof(CONTROL_PARAM));
    //}
}*PCONTROL_PARAM;

//Ӳ������Ӳ��⣩����⣨��HKΪ����Ҫ����ͨѶ���Ӳ��⣩
//ʾ����
//bool initialPlayer(INITPY_PARAM *pIParam, CONNECT_PARAM *pCParam ); //Ӳ�ⵥ��ʹ�û���⸴�ô˽ӿ�
typedef struct INITPY_PARAM
{
    DWORD size;
    int nPort;
    int nDecodeType;
    int nSpeed;
    BYTE* buff;
    int nSize;
    int nType;
    char chReser[32];

    //INITPY_PARAM()
    //{
    //	ZeroMemory(this, sizeof(INITPY_PARAM));
    //}
}*PINITPY_PARAM;

//���ڶ�·�������Ľ���ʵ����Զ�̽��룬�Ǳ��أ���ҪӦ�õ�CONNECT_PARAM��������Ҫʹ�ñ���Ӳ��ӿڡ�
//�ͻ���ʹ�ã����⣩����⣨��HKΪ����Ҫ�������⣩
//ʾ����
//bool startPlayer4Standard(STARTPYSTD_PARAM *pParam); //��Ӳ�Ⲣ��

typedef struct STARTPYSTD_PARAM
{
    DWORD size;
    HWND hWnd;
    LPDecCBFun lpDecCBFun;
    int nCameraID;
    char chReser[32];
    //STARTPYSTD_PARAM()
    //{
    //	ZeroMemory(this, sizeof(STARTPYSTD_PARAM));
    //}
}* PSTARTPYS_PARAM;

//bool locPlay_OpenFile(LOCPY_OPENF_PARAM *pParam); //����Ⲣ��
typedef struct LOCPY_OPENF_PARAM
{
    DWORD size;
    int nPort;
    int nDecodeType;
    int hWnd;
    char* fileName;
    char chReser[32];
    //LOCPY_OPENF_PARAM()
    //{
    //	ZeroMemory(this, sizeof(LOCPY_OPENF_PARAM));
    //}

}* PLOCPY_OPENF_PARAM_PARAM;

#define MODULE_CONNECT   0
#define MODULE_STREAM    1
#define MODULE_CONTROL   2
#define MODULE_PLAYER	 10

namespace MODULENAME
{
    const char* const MODULE_NAME[20] = {"Connect","Stream","Control","","","","","","","","Player"};
}

#define PLAY_ONEBYONEBACK            5//��֡�ط�
#define PLAY_BACK                    6//����

#define RENDER_BY_OPENGL	0x01		//ʹ��OpenGL��Ⱦͼ��
#define RENDER_BY_D3D		0x02		//ʹ��D3D��Ⱦͼ��

/*
MediaInf�ṹ˵����
�˽ṹ���ڱ����ļ�����ʱ��������ȡ�ļ���ý����Ϣ
XY_OpenFile�󣬴���XY_GetMediaInfo()���ɻ�ȡ�����Ϣ
*/
typedef struct _MediaInf{
	char fileformat[32]; //�ļ���ʽ
	char codeType[32];   //�����ʽ
	char colorType[32];  //ɫ�ʿռ� ���磺yuv420p
	int  bit_rate;		 //����
	int  frame_rate;     //֡��
	int  v_width;        //ͼ����
	int  v_height;		 //ͼ��߶�
}MediaInf; 
#endif//_NVSSDKDEF_H
