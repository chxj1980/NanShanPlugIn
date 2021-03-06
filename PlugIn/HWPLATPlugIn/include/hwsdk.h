#ifndef _HW_IVS_SDK_H_
#define _HW_IVS_SDK_H_

#include "ivs_type.h"

#pragma pack(push, 1)

// 类型定义
typedef  void*              IVS_LPVOID;
typedef  int	            IVS_BOOL;
typedef  void               IVS_VOID;

#ifdef WIN32
#define __SDK_CALL __stdcall
#else
#define __SDK_CALL
#endif

//定义NULL
#ifndef NULL
#ifdef __cplusplus
#define NULL    0
#else
#define NULL    ((void *)0)
#endif
#endif

#ifndef IVS_TRUE
#define IVS_TRUE        1
#endif

#ifndef IVS_FALSE
#define IVS_FALSE       0
#endif

#ifndef IN
#define IN
#endif

#ifndef OUT
#define OUT
#endif

#ifndef INOUT
#define INOUT
#endif

//#ifndef IO
//#define IO
//#endif


// 消息定义(消息上报)
#define IVS_EVENT_AUTO_CONNECT_SUCCEED                  10001   // 重新登录成功事件上报
#define IVS_EVENT_KEEP_ALIVE_FAILED                     10002   // 保活失败事件上报
#define IVS_EVENT_REALPLAY_FAILED                       10003   // 实时浏览异常事件上报
#define IVS_EVENT_RECORD_FAILED                         10004   // 录像异常事件上报
#define IVS_EVENT_DOWNLOAD_FAILED                       10005   // 录像下载异常事件上报
#define IVS_EVENT_REMOTE_PLAYBACK_FAILED                10006   // 远程录像回放异常事件上报
#define IVS_EVENT_LOCAL_PLAYBACK_FAILED                 10007   // 本地录像回放异常事件上报
#define IVS_EVENT_TALKBACK_FAILED                       10008   // 语音对讲异常事件上报
#define IVS_EVENT_BROADCAST_FAILED		                10009   // 语音广播异常事件上报
//#define IVS_EVENT_START_MULT_SNAPSHOT                   10010   // 开始连续抓拍
//#define IVS_EVENT_STOP_MULT_SNAPSHOT                    10011   // 连续抓拍异常停止
//#define IVS_EVENT_FINISHED_MULT_SNAPSHOT                10012   // 连续抓拍完成
#define IVS_EVENT_REPORT_ALARM                          10013   // 告警上报
#define IVS_EVENT_FILE_BROADCAST_END                    10014   // 本地文件广播结束事件上报

//#define IVS_EVENT_REMOTE_RECORD_STOP                    10015   // 远程录像停止
//#define IVS_EVENT_REPORT_DEVICE                         10016   // 设备状态上报
#define IVS_EVENT_REPORT_ALARM_STATUS                   10017   // 告警状态上报

#define IVS_EVENT_USER_OFFLINE                          10019   // 用户下线通知
#define IVS_EVENT_RESUME_REALPLAY                       10020   // 启动实况重连
#define IVS_EVENT_RESUME_REALPLAY_OK                    10021   // 恢复实况浏览

#define IVS_EVENT_LOCAL_RECORD_SUCCESS                  10022   // 本地录像成功事件
#define IVS_EVENT_LOCAL_RECORD_EGENERIC                 10023   // 录像文件写入失败事件
#define IVS_EVENT_DO_LINKAGE_ACTION                     10024   // 告警联动动作执行通知

#define IVS_EVENT_FIND_DEVICE                           10025   // 发现前端设备事件
#define IVS_EVENT_OMU_REPORT_ALARM                      10026   // OMU将设备类告警发给CU的接口消息
#define IVS_EVENT_REPORT_WATERMARK_TIP                  10027   // 发现水印篡改提示（只有篡改开始时间）
#define IVS_EVENT_REPORT_WATERMARK_ALARM                10028   // 水印告警记录产生通知（有篡改开始时间和停止时间）

#define IVS_EVENT_PTZ_LOCK                              10029   // 云镜锁定上报（云镜操作结果返回时告知客户端）

//#define IVS_EVENT_OTHER                               10030   // 其他模式
#define IVS_EVENT_MANUAL_RECORD_STATE                   10031   // 手动录像状态通知
#define IVS_EVENT_STOP_LINKAGE_ACTION                   10032   // 告警联动动作停止通知
#define IVS_EVENT_DOWNLOAD_SUCCESS                      10033   // 录像下载完成事件上报
//#define IVS_EVENT_PWD_EXPIRE_DAYS                       10034   // 用户密码过期天数
#define IVS_EVENT_PLAYER_BUFFER                         10035   // 客户端缓存通知
#define IVS_EVENT_PLAY_SOUND_FAILED                     10036   // 随路语音开启失败（已有语音对讲不可开启随路语音）

#define IVS_EVENT_PLAYER_WATER_MARK_EXCEPTION           10037   // 水印异常事件上报

#define IVS_EVENT_MOD_USER_DEV_RSP                      10038   // 添加用户的设备/设备组信息响应

#define IVS_EVENT_DAHUA_DOWNLOAD_SUCCESS                10039   // 大华录像下载完成事件上报

#define IVS_EVENT_IPC_MODEL_UPDATE                      10040   //IPC模板更新上报

#define IVS_EVENT_LOGOUT_ONLINE_USER_BY_ID              10076   // 根据用户ID退出登录提示消息
#define IVS_EVENT_LOGOUT_ONLINE_USER_BY_ROLEID          10077   // 根据用户角色退出登录提示消息

#define IVS_EVENT_IA_BA_LEARNING_SCHEDULE_REPORT        10100   // 智能分析学习进度上报
#define IVS_EVENT_IA_FR_SCHEDULE_REPORT                 10101   // 智能分析人脸批量注册进度上报
#define IVS_EVENT_IA_PUSH_ALARM_LOCUS                   10102   // 智能分析轨迹推送
#define IVS_EVENT_IA_DRAW_OVER                          10103   // 智能分析绘图结束
#define IVS_EVENT_IA_ADDPLAN_SCHEDULE_REPORT            10104   // 智能分析添加计划进度上报

#define IVS_EVENT_MODE_CRUISE_RECORD_OVER               10203   // 模式轨迹录制结束通知

#define IVS_EVENT_LOGIN_FAILED                          10301   // 客户端登录失败（例如，重连时密码改变）

#define IVS_EVENT_PLAYBACK_STREAM_ID                    10310   // 回放成功，通知流ID

#define IVS_EVENT_PLAYER_CREATE_DECODER_FAILED          10311   //创建播放库失败上报
#define IVS_EVENT_REPORT_CREATE_DECODER_FAILED          10312   //创建播库失败事件上报
//DTS2017122505167 修改实况快速录像回放时，无录像的问题
#define IVS_EVENT_FAST_PLAYBACK_FAILED				    10313    //快速录像回放事件上报

// 通用常量定义
#define IVS_TIME_LEN          20          // 时间长度
#define IVS_NAME_LEN        128         // 名称长度
#define IVS_PWD_LEN           64          // 密码长度(网络传输使用密文)
#define IVS_SALT_LEN          16           //盐值长度
#define IVS_GROUP_CODE_LEN     64          // 组编号长度
#define IVS_DESCRIBE_LEN        256         // 描述长度
#define IVS_IP_LEN                      64  // IP长度
#define IVS_URL_LEN                 256     // URL长度
#define IVS_FILE_NAME_LEN       256     // 文件名最大长度
#define IVS_MAX_NAME_LIST_LEN   1024        // 名称列表最大长度，用逗号隔开
#define IVS_PROXY_LEN        128         // 代理名称长度
#define IVS_PROTOCOL_LEN        16         // 代理名称长度

// 用户
#define IVS_MACHINE_NAME_LEN    128 // PC机器名长度
#define IVS_DOMAIN_LEN                  64      // Windows域名长度
#define IVS_PHONE_NUMBER_LEN        64  // 电话号码最大长度
#define IVS_MAX_OPERATION_RIGHT     128     // 操作权限个数上线
#define	IVS_EMAILE_LEN      128             // 用户Email长度

// 设备信息
#define IVS_DEV_SERIALNO_LEN        64      // 设备序列号长度
#define IVS_DEV_CODE_LEN        64         // 设备编码最大长度
#define IVS_DEV_ACCESSCODE_LEN     64          // 设备统一编码最大长度
#define IVS_DEVICE_GROUP_LEN    128         // 设备组编码最大长度
#define IVS_DEVICE_GROUP_NAME_LEN 128  //设备组名称最大长度
#define IVS_TAS_CODE_LEN        32          // TAS编码长度
#define IVS_NVR_CODE_LEN        32          // NVR编码长度
#define IVS_CLUSTER_CODE_LEN    32          // 集群编码长度
#define IVS_DOMAIN_CODE_LEN     32          // 域编码最大长度
#define IVS_DEV_MODEL_LEN	    32          // 设备型号最大长度

#define IVS_MRU_CODE_LEN        64          //MRU分配方式

#define IVS_LONGITUDE_LATITUDE_LEN		20		//经纬度长度

//误删相机优化:0-主设备待彻底删除 1-正常
const IVS_INT32 DEV_STATUS_DELAY_DEL = 0;
const IVS_INT32 DEV_STATUS_NORMAL    = 1;
#define STR_DEV_STATUS_DELAY_DEL     "0"
#define STR_DEV_STATUS_NORMAL        "1"

#define IVS_MAX_STREAM_NUM	8
#define IVS_CAMERA_NAME_LEN 192 // 摄像机名称长度
#define IVS_CAMERACODE_LEN  20  //摄像机编码长度

/* 8字节ID转成字符串后长度 */
#define IVS_ID_LEN          24

#define IVS_MAX_STREAM_LIST_NUM      3           //码流信息列表最大3条
#if defined(ARM_HIS3536)
#define IVS_MAX_ENCODE_LIST_NUM      4           //编码类型信息列表最大4条
#else
#define IVS_MAX_ENCODE_LIST_NUM      3           //onvif支持编码类型信息列表最大3条
#endif
#define IVS_MAX_RESOLUTION_LIST_NUM  30          //分辨率列表最大30条

#define IVS_RELIABLE_TRANSMISSION_TYPE_NUM 5     //可靠传输类型最多为5种:NONE ARQ HARQ FEC SEC

// 快捷键
#define IVS_HOTKEY_CTRL         0x01
#define IVS_HOTKEY_SHIFT        0x02
#define IVS_HOTKEY_ALT          0x04
#define IVS_HOTKEY_WIN          0x08

#define IVS_CAP_VERSION_LEN 32 //后台能力版本号长度，格式为x.x.x，x为整数
#define IVS_VERSION_LEN  64      // 客户端版本号长度
#define IVS_MD5_LEN      32      // MD5值长度
#define IVS_TOKEN_LEN      128      // MD5值长度
#define IVS_SHA256_LEN     64   //SHA256值长度

//车辆元数据
#define IVS_ITS_COMM_LEN   16  //IMGU模块通用长度
#define IVS_PLATE_LEN     16  //车牌号码长度
#define IVS_ADD_SEC_PLATE_LEN     112  //车牌号码长度
#define IVS_ITS_RES_LEN   32  //预留字段长度
#define ITS_TIME_LEN         32
#define IVS_BRAND_YEAR_LEN     128  //车牌年款最大长度

//人体属性元数据长度
#define IVS_HUMAN_ATTRIBUTES_LEN     128  //人体属性元数据长度

//支持的抓拍信息附加信息的最大长度
#define IVS_SNAPSHOT_EXTRA_INFO_LEN (1024)
#define IVS_SNAPSHOT_EXTRA_INFO_BASE64_LEN (IVS_SNAPSHOT_EXTRA_INFO_LEN*3/2)

/* 最大协同集数量 */
#define IVS_MAX_IPC_COORDINATE_COMMUNITY_NUM                (50)

/* 单个协同集中最大的IPC数量 */
#define IVS_MAX_IPC_NUM_IN_COORDINATE_COMMUNITY             (50)

/* 通用的无效ID */
#define IVS_COMMON_INVALID_ID_VALUE                         (0)

/*流异常结构体*/
typedef struct ST_STREAM_EXCEPTION_INFO
{
    IVS_INT32 iSessionID;       //登录返回的会话ID
    IVS_ULONG ulHandle;         //句柄
    IVS_INT32 iExceptionCode;   //错误码
    IVS_ULONG iReseved1;        //备用
    IVS_CHAR szDeviceCode[IVS_DEV_CODE_LEN];

}STREAM_EXCEPTION_INFO;

typedef enum
{
    CU_LEFTTOP = 0, //CU左上角
    CU_LOGINABOUT,  //CU登录/关于
    MOBILE_PAD,     //移动PAD
    MOBILE_PHONE,   //移动Phone
    BS_LEFTTOP,     //BS左上角
    BS_LOGINABOUT,   //BS登录/关于
    CU_PLAYERBLACK,
    CU_PLAYERWHITE
}IVS_LOGO_TYPE;

typedef enum
{
    KEY_WEAK=0,
    KEY_MIDDLE,
    KEY_STRONG,
    KEY_STRONGER
}IVS_KEY_RELIABILITY;

// 账号签退类型
typedef enum
{
    USER_OFFLINE_LOCK=0,    // 账号被管理员锁定
    USER_OFFLINE_DELETE=1,  // 账号被管理员删除
    USER_OFFLINE_SIGNOUT=2, // 登录会话被管理员签退
}IVS_USER_OFFLINE_TYPE;

// 设备操作类型
typedef enum
{
    DEVICE_DELETE=0,    // 设备软删除
    DEVICE_COMPlETE_DELETE=1,  // 设备彻底删除
    DEVICE_ROLLBACK=2, // 设备恢复
}IVS_DEVICE_OPER_TYPE;

// 时间片段结构
typedef struct
{
    IVS_CHAR	cStart[IVS_TIME_LEN];   // 格式如yyyyMMddHHmmss
    IVS_CHAR	cEnd[IVS_TIME_LEN];     // 格式如yyyyMMddHHmmss
}IVS_TIME_SPAN;

// 本地录像文件上报通知
typedef struct
{
    IVS_CHAR    cCameraCode[IVS_DEV_CODE_LEN];      // 摄像机编码
    IVS_CHAR    cFileName[IVS_FILE_NAME_LEN];       // 文件名
    IVS_CHAR    cFilePath[IVS_FILE_NAME_LEN];       // 文件存放路径
    IVS_CHAR    cOperationTime[IVS_TIME_LEN];       // 操作时间
    IVS_TIME_SPAN   stRecordTime;                   // 录像起始、结束时间
    IVS_UINT32  uiRecordType;                       // 录像类型：0-本地录像，1-平台录像下载
    IVS_BOOL    bIsEncrypt;                         // 录像是否加密：0-不加密，1-加密
}IVS_LOCAL_RECORD_SUCCESS_INFO;

// 用户下线通知
typedef struct
{
    IVS_INT32   iSessionID;     // 下线用户的SessionID
    IVS_UINT32  uiOfflineType;  // 下线类型，值参考 IVS_USER_OFFLINE_TYPE
}IVS_USER_OFFLINE_INFO;

// 本地录像文件上报通知
typedef struct
{
    IVS_LONG    lErrorCode;     // 错误码
    IVS_ULONG   ulHandle;       // 播放句柄
    IVS_CHAR    cReserve[32];   // 保留字段
}IVS_LOCAL_RECORD_EGENERIC;

// 基本数据结构
typedef struct
{
    IVS_FLOAT	left;
    IVS_FLOAT	top;
    IVS_FLOAT	right;
    IVS_FLOAT	bottom;
}IVS_RECT_FLOAT;

typedef enum
{
    WIND_LAYOUT_1_1 = 11,   // 窗口数1,布局1
    WIND_LAYOUT_3_1 = 31,   // 窗口数3,布局1
    WIND_LAYOUT_3_2 = 32,   // 窗口数3,布局2
    WIND_LAYOUT_3_3 = 33,   // 窗口数3,布局3
    WIND_LAYOUT_4_1 = 41,   // 窗口数4,布局1
    WIND_LAYOUT_4_2 = 42,   // 窗口数4,布局2
    WIND_LAYOUT_4_3 = 43,   // 窗口数4,布局3
    WIND_LAYOUT_6_1 = 61,   // 窗口数6,布局1
    WIND_LAYOUT_6_2 = 62,   // 窗口数6,布局2
    WIND_LAYOUT_6_3 = 63,   // 窗口数6,布局3
    WIND_LAYOUT_6_4 = 64,   // 窗口数6,布局4
    WIND_LAYOUT_8_1 = 81,   // 窗口数8,布局1
    WIND_LAYOUT_9_1 = 91,   // 窗口数9,布局1
    WIND_LAYOUT_9_2 = 92,   // 窗口数9,布局2
    WIND_LAYOUT_10_1 = 101, // 窗口数10,布局1
    WIND_LAYOUT_10_2 = 102, // 窗口数10,布局2
    WIND_LAYOUT_12_1 = 121, // 窗口数12,布局1
    WIND_LAYOUT_12_2 = 122, // 窗口数12,布局2
    WIND_LAYOUT_13_1 = 131, // 窗口数13,布局1
    WIND_LAYOUT_13_2 = 132, // 窗口数13,布局2
    WIND_LAYOUT_16_1 = 161, // 窗口数16,布局1
    WIND_LAYOUT_16_2 = 162, // 窗口数16,布局2
    WIND_LAYOUT_17_1 = 171, // 窗口数17,布局1
    WIND_LAYOUT_20_1 = 201, // 窗口数20,布局1
    WIND_LAYOUT_25_1 = 251, // 窗口数25,布局1
    WIND_LAYOUT_26_1 = 261, // 窗口数26,布局1
    WIND_LAYOUT_36_1 = 361, // 窗口数36,布局1
    WIND_LAYOUT_49_1 = 491, // 窗口数49,布局1
    WIND_LAYOUT_64_1 = 641, // 窗口数64,布局1

    WIND_LAYOUT_CUSTOM_1 = 651, //自定义布局1
    WIND_LAYOUT_CUSTOM_2 = 652, //自定义布局2
    WIND_LAYOUT_CUSTOM_3 = 653, //自定义布局3
    WIND_LAYOUT_CUSTOM_4 = 654, //自定义布局4

    WIND_LAYOUT_MULTILENS_1 = 12, //单画面
    WIND_LAYOUT_MULTILENS_2 = 21, //两画面
    WIND_LAYOUT_MULTILENS_3 = 34, //三画面

    WIND_LAYOUT_TVW = 200,      // 电视墙
}IVS_WIND_LAYOUT;

// OCX工具条按钮
const IVS_UINT32 IVS_TOOLBAR_SNAPSHOT       = 0x00000001;   // 抓拍
const IVS_UINT32 IVS_TOOLBAR_LOCAL_RECORD   = 0x00000002;   // 本地录像
const IVS_UINT32 IVS_TOOLBAR_BOOKMARK       = 0x00000004;   // 书签
const IVS_UINT32 IVS_TOOLBAR_ZOOM           = 0x00000008;   // 局部放大
const IVS_UINT32 IVS_TOOLBAR_PLAY_RECORD    = 0x00000010;   // 即时回放
const IVS_UINT32 IVS_TOOLBAR_PLAY_SOUND     = 0x00000020;   // 声音
const IVS_UINT32 IVS_TOOLBAR_TALKBACK       = 0x00000040;   // 对讲
const IVS_UINT32 IVS_TOOLBAR_VIDEO_TVW      = 0x00000080;   // 视频上墙
const IVS_UINT32 IVS_TOOLBAR_ALARM_WIN      = 0x00000100;   // 设置告警窗口
const IVS_UINT32 IVS_TOOLBAR_PTZ            = 0x00000200;   // 云镜控制
const IVS_UINT32 IVS_TOOLBAR_IA             = 0x00000400;   // 叠加智能分析
const IVS_UINT32 IVS_TOOLBAR_OPEN_MAP       = 0x00000800;   // 打开电子地图
const IVS_UINT32 IVS_TOOLBAR_WINDOW_MAIN    = 0x00001000;   // 一主多辅
const IVS_UINT32 IVS_TOOLBAR_PLAY_QUALITY   = 0x00002000;   // 网速优先/画质优先
const IVS_UINT32 IVS_TOOLBAR_PTZ3D          = 0x00004000;   // 3D定位
const IVS_UINT32 IVS_TOOLBAR_EXIT_PLAY_RECORD= 0x00008000;   // 退出即时回放，返回正常播放

// OCX智能分析工具条
const IVS_UINT32 IVS_IA_TOOLBAR_DRAW_RECT       = 0x00000001;   // 矩形
const IVS_UINT32 IVS_IA_TOOLBAR_DRAW_POLYGON    = 0x00000002;   // 多边形
const IVS_UINT32 IVS_IA_TOOLBAR_ZOOM_IN         = 0x00000004;   // 放大
const IVS_UINT32 IVS_IA_TOOLBAR_ZOOM_OUT        = 0x00000008;   // 缩小
const IVS_UINT32 IVS_IA_TOOLBAR_DRAW_MOVE       = 0x00000010;   // 移动
const IVS_UINT32 IVS_IA_TOOLBAR_DISPLAY_MODE    = 0x00000020;   // 屏幕视频显示方式
const IVS_UINT32 IVS_IA_TOOLBAR_PLAY            = 0x00000040;   // 播放视频
const IVS_UINT32 IVS_IA_TOOLBAR_DELETE          = 0x00000080;   // 删除

// 录像状态
const IVS_UINT32 IVS_RECORD_STATE_MANUAL        = 0x00000001;   // 手动录像
const IVS_UINT32 IVS_RECORD_STATE_ALARM         = 0x00000002;   // 告警录像
const IVS_UINT32 IVS_RECORD_STATE_PLAN          = 0x00000004;   // 计划录像

// 视频轮巡窗口按钮状态
const IVS_UINT32 IVS_CAMERA_SWITCH_BUTTON_NULL  = 0x00000000;   // 无轮巡快速切换按钮
const IVS_UINT32 IVS_CAMERA_SWITCH_BUTTON_LEFT  = 0x00000001;   // 轮巡快速切换左按钮
const IVS_UINT32 IVS_CAMERA_SWITCH_BUTTON_RIGHT = 0x00000002;   // 轮巡快速切换右按钮

// 云镜控制码
typedef enum
{
    // 云台转动控制，包括停止、上、下、左、右等
    PTZ_STOP = 1,
    PTZ_UP,
    PTZ_DOWN,
    PTZ_LEFT,
    PTZ_UP_LEFT,
    PTZ_DOWN_LEFT,
    PTZ_RIGHT,
    PTZ_UP_RIGHT,
    PTZ_DOWN_RIGHT,
    PTZ_AUTO,
    PTZ_PREFAB_BIT_RUN,
    PTZ_CRUISE_RUN,
    PTZ_CRUISE_STOP,
    PTZ_MODE_CRUISE_RUN,
    PTZ_MODE_CRUISE_STOP,
    PTZ_MENU_OPEN,
    PTZ_MENU_EXIT,
    PTZ_MENU_ENTER,
    PTZ_FLIP,
    PTZ_START,
    // 镜头控制，包括光圈、缩放、聚焦
    PTZ_LENS_APERTURE_OPEN,
    PTZ_LENS_APERTURE_CLOSE,
    PTZ_LENS_ZOOM_IN,
    PTZ_LENS_ZOOM_OUT,
    PTZ_LENS_FOCAL_NEAT,
    PTZ_LENS_FOCAL_FAR,
    PTZ_AUX_OPEN,
    PTZ_AUX_STOP,
    // 模式
    MODE_SET_START,
    MODE_SET_STOP,
    // 增强操作
    PTZ_FAST_LOCATE,
    PTZ_HORIZONTAL_SCAN,
    PTZ_VERTICAL_SCAN,
    PTZ_LOCK,
    PTZ_UNLOCK
}IVS_PTZ_CODE;

// OCX窗口工具栏图标状态
// 巡航、告警、手动录像、单帧
typedef enum
{
    OCX_TITLEBAR_CRUISE = 0,  // 巡航
    OCX_TITLEBAR_WARNING= 1,  // 告警
    OCX_TITLEBAR_RECORD = 2,  // 手动录像
    OCX_TITLEBAR_FRAME  = 3,  // 单帧
}IVS_TITLEBAR_ICON;

// OCX窗口工具栏按钮状态
typedef enum
{
    OCX_TOOLBAR_STATUS_DISABLE= 0,  // 置灰
    OCX_TOOLBAR_STATUS_NORMAL,      // 正常
}IVS_TOOLBAR_STATUS;

// 分页信息
typedef struct
{
    IVS_UINT32 uiFromIndex; // 开始索引
    IVS_UINT32 uiToIndex;   // 结束索引
}IVS_INDEX_RANGE;

// IP类型
typedef enum
{
    IP_V4= 0,
    IP_V6= 1
}IVS_IP_TYPE;

// IP信息
typedef struct
{
    IVS_UINT32  uiIPType;   // IP类型：参考 IVS_IP_TYPE
    IVS_CHAR    cIP[IVS_IP_LEN];     // IP地址
}IVS_IP;

typedef struct
{
    IVS_UINT32	uiCUType;// 客户端类型：5-PC客户端 6-iPad 7-AndroidPhone 8-AndroidPad 9-iPhone
    IVS_CHAR	   cCUVersion[IVS_VERSION_LEN];// 客户端版本号
	IVS_UINT32	uiVersionPlatform;//操作系统平台：该字段只有2个值，32和64.其中32表示32位操作系统，64表示64位操作系统。
    IVS_CHAR     cReserve[60];// 保留字段
}IVS_CU_INFO;

// 客户端类型
typedef enum
{
    CLIENT_PC       =0, // PC客户端
    CLIENT_WEB      =1, // web浏览器
    CLIENT_MOBILE   =2, // 移动客户端
    CLIENT_PC_CHILD =3, // PC客户端子进程
    CLIENT_TV_WALL  =4, // 电视墙进程
    CLIENT_LDU = 5,          //本地人机
    CLIENT_VCM = 6          // VCM进程
}IVS_CLIENT_TYPE;

//升级信息
typedef struct
{
    IVS_BOOL    bIsUpgrade;//是否需要升级，0-否，1-是
    IVS_CHAR    cSetupFileMd5[IVS_MD5_LEN];// 安装压缩包MD5值,ios客户端时为空
	IVS_CHAR    cSetupFileSHA256[IVS_SHA256_LEN];//安装压缩包SHA256值
    IVS_UINT64      uiFileSize;     // 安装压缩包大小，字节数，ios客户端时为空
    // IVS_CHAR        cIosSetupUrl[IVS_URL_LEN];// ios客户端下载URL
    IVS_CHAR        cHttpURL[IVS_URL_LEN];//上传下载文件流URL信息
    // IVS_CHAR        cToken[IVS_TOKEN_LEN];//用户凭证
	IVS_CHAR	    cServerCapabilityVersion[IVS_CAP_VERSION_LEN]; //SMU能力版本号，用于兼容性开发
    IVS_CHAR        cReserve[48];// 保留字段
}IVS_UPGRADE_INFO;

//帮助文件信息
typedef struct
{
	IVS_UINT64      uiFileSize;            // 文件大小
	IVS_CHAR        cHttpURL[IVS_URL_LEN]; //帮助文件URL信息
	IVS_CHAR        cReserve[64];          // 保留字段
}IVS_HELP_FILE_INFO;

// 登陆类型
typedef enum
{
    LOGIN_BASIC= 0, // 基本身份验证
    LOGIN_WINDOWS_CURRENT,  // Windows域身份验证—当前用户
    LOGIN_WINDOWS_OTHER     // Windows域身份验证—其他用户
}IVS_LOGIN_TYPE;

// 用户登录信息
typedef struct
{
    IVS_CHAR cUserName[IVS_NAME_LEN];           // 用户名
    IVS_CHAR pPWD[IVS_PWD_LEN];                     // 登录类型为0（基本账号）时，不能为空

    IVS_IP  stIP;                    // 登录服务器IP
    IVS_UINT32 uiPort;                      // 登录服务器端口

    IVS_UINT32 uiLoginType;     // 登录类型：参考 IVS_LOGIN_TYPE 0–基本身份验证,	1–Windows域身份验证—当前用户，2–Windows域身份验证—其他用户
    IVS_CHAR cDomainName[IVS_DOMAIN_LEN];       // windows域名
    IVS_CHAR cMachineName[IVS_MACHINE_NAME_LEN];    // PC机器名

    IVS_UINT32 uiClientType;    // 客户端类型：参考 IVS_CLIENT_TYPE 0-PC客户端, 1-web浏览器, 2-移动客户端, 3-PC客户端子进程，4-电视墙进程
    IVS_CHAR cReserve[32];                          //保留字段
}IVS_LOGIN_INFO;

//Ldu 锁屏时用户登陆验证
typedef struct
{
    IVS_CHAR cUserName[IVS_NAME_LEN];           // 用户名
    IVS_CHAR pPWD[IVS_PWD_LEN];                     // 登录类型为0（基本账号）时，不能为空
}LDU_VERIFY_LOGIN_INFO;

// 在线用户信息
typedef struct
{
    IVS_UINT32  uiUserID;               // 用户ID
    IVS_UINT32  uiUserOnlineID;           // 在线用户信息ID （一个用户名可以多次同时登录）
    IVS_CHAR    cUserName[IVS_NAME_LEN];            // 登录账号
    IVS_CHAR    cDomainName[IVS_DOMAIN_LEN];    // 登录域名信息
    IVS_UINT32  uiClientType;       // 登录客户端类型 值参考 IVS_CLIENT_TYPE
    IVS_IP   stIP;          // 登录的客户端IP
    IVS_CHAR    cMachineName[IVS_MACHINE_NAME_LEN];	// PC机器名
    IVS_CHAR    cLoginTime[IVS_TIME_LEN];        // 用户登录时间
    IVS_CHAR    cReserve[64];                       // 保留字段
}IVS_ONLINE_USER;

typedef struct
{
    IVS_UINT32   uiTotal;               // 总记录数
    IVS_INDEX_RANGE stIndexRange;       // 分页信息
    IVS_ONLINE_USER stOnlineUser[1];    // 在线用户信息
}IVS_ONLINE_USER_LIST;

// 密码复杂性要求
typedef struct
{
    IVS_BOOL    bCapital;   // 大写字母，是否选中
    IVS_BOOL    bLowercase; // 小写字母，是否选中
    IVS_BOOL    bFigure;    // 数字，是否选中
    IVS_BOOL    bSpecialChar;   // 特殊字符，是否选中
    IVS_CHAR    cReserve[32];   // 保留字段
}IVS_PWD_CONSIST;

// 账户规则
typedef struct
{
    IVS_BOOL	bEnable;			// 是否启用
    IVS_PWD_CONSIST	stPswConsist;	// 密码复杂性要求
    IVS_BOOL	bFirstModify;		// 首次登录修改密码，是否选中
    IVS_BOOL	bCheckOldPwd;		// 修改密码时验证旧密码，是否选中
    IVS_BOOL	bAccountNotFit;		// 口令不能和帐号一样，是否选中
    IVS_BOOL	bAccountBackNotFit;	// 口令不能和帐号的倒写一样，是否选中
    IVS_BOOL	bDomainAccCheckPwd;	// Windows本地账号登录需要输入密码，是否选中
    IVS_UINT32	uiPwdMinLen;        // 密码长度最小值，数值范围在6-64位。
    IVS_UINT32	uiPwdDifferentNum;	// 新旧密码不相同字符，数值范围在0-密码长度
    IVS_UINT32	uiAccountLockNum;	// 账号锁定阈值，0表示无锁定限制，最大999
    IVS_UINT32	uiAccountLockElapse;// 账号锁定时长，数值范围在1-1440分钟

    IVS_UINT32	uiAccountLockInterval;  // 账号锁定间隔，数值范围在0-999分钟，0表示不自动清零，锁定后需要管理员手动解锁
    IVS_UINT32	uiPWDExpireTime;        // 密码过期时间，密码创建或修改后开始计时，单位：天，范围：0-999
    IVS_UINT32	uiPWDExpireNotifyTime;  // 密码过期提醒时间，密码过期时间到达前开始提醒，单位：天，范围：0-99
    IVS_BOOL	bPWDExpireForceNotify;  // 密码过期强制修改，是否选中。0-不强制修改，1-强制修改
    IVS_CHAR    cReserve[64];           // 保留字段
}IVS_ROLE_ACCOUNT_RULE;

typedef enum
{
    // 默认管理角色
    OR_MANAGER_DEVICE= 1,		// 设备管理：设备的增、删、改、查和子设备启动、设备组管理、设备参数配置（包含：高级参数配置（码率、分辨率、重启等）；基本参数配置（OSD、亮度、对比度等））
    OR_MANAGER_USER,			// 用户管理：用户管理、角色管理、权限管理、用户签退、告警订阅（其他用户）
    OR_MANAGER_RECORD,			// 录像管理：录像空间、计划配置、预录、补录、录像归档管理（视频归档）
    OR_MANAGER_RECORD_BACKUP,	// 录像备份管理：平台、前端录像备份管理、配置备份策略、手动录像备份
    //OR_MANAGER_IA,				// 智能分析管理：智能分析规则设置
    //OR_MANAGER_STORAGE,		// 存储管理：存储空间管理
    OR_MANAGER_ALARM=7,			// 告警管理：告警订阅、联动策略、防区管理、告警级别
    OR_MANAGER_NET,				// 网管：客户端网管（含设备类告警通知）
    OR_RECORD_BOOKMARK=10,      // 录像书签管理
    //OR_TRANSPARENT_CHANNEL,	// 透明通道
    OR_MANAGER_OUT_DOMAIN=12,   // 外域管理权限
    OR_MANAGER_MAP,             // 电子地图管理权限
    OR_MANAGER_QD,              // 视频质量诊断管理权限:14

    // 特殊业务角色
    OR_TV_WALL_HANDLE=20,       // 电视墙：上墙实况、上墙回放
    OR_ALARM_HANDLE,		    // 告警处理：告警确认、查询告警、导出告警、撤销、授权告警、本地告警参数配置
    OR_IA_HANDLE,			    // 智能分析操作
    OR_DEFENCE_HANDLE,		    // 防区布撤防
    OR_WATERMARK_HANDLE,	    // 水印篡改校验
    OR_MOBILE_CAMERA,	        // 手机模拟前端权限

    // 一般业务角色
    OR_SNAPSHOT_MANAGER=40,	    // 平台抓拍管理权限（配置、下载、预览、删除）
    OR_LOG_QUERY,			    // 日志查询、导出
    OR_MAP,					    // 电子地图操作
    OR_REALPLAY,			    // 软解、叠加智能分析结果、局部放大、轮巡/组轮巡、轮巡计划、布局管理、场景管理
    OR_RECORD_PLAY,				// 平台、前端录像回放、局部放大、同步回放、录像检索（包括备份录像）、VCR控制、录像书签
    OR_RECORD_DOWNLOAD,			// 平台、前端录像下载、录像检索
    OR_VOICE,				    // 语音：对讲和广播
    OR_PTZ,					    // 云台控制：云台预置位、巡航、云台控制、看守位设置、云台加解锁、3D定位、本地云台参数配置
    OR_RECORD_MANUAL,			// 手动录像：平台、前端、本地手动录像
    OR_SNAPSHOT_LOCAL,		    // 抓拍操作(包括本地、平台)
    OR_IMGU,                    // 图片混存管理
    OR_PRESET_EDIT,             //预置位编辑权限add for RM201612297260
    OR_RECORD_LOCK,             //录像锁定为（一般权限，不再为9，改为52）
}IVS_OPERATION_RIGHT;

// 平台支持能力集信息
#define IVS_ABILITY_IA_FR   0x01    // 智能分析-人脸
#define IVS_ABILITY_IA_BA   0x02    // 智能分析-行为
#define IVS_ABILITY_IA_QD   0x04    // 智能分析-质量诊断

// 权限组信息
#define IVS_MAX_RIGHT_GROUP_NAME_LEN	64	// 权限组最大英文名长度（多语言由客户端自己映射实现）
typedef struct
{
    IVS_CHAR	cRightGroupName[IVS_MAX_RIGHT_GROUP_NAME_LEN];	// 权限组名称
    IVS_CHAR	cRight[IVS_MAX_OPERATION_RIGHT];                // 角色权限数组：0-没权限，1-有权限，权限值参考 IVS_OPERATION_RIGHT
    IVS_CHAR    cReserve[32];                                   // 保留字段
}IVS_OPERATION_RIGHT_GROUP;

// 权限组列表
#define IVS_MAX_RIGHT_GROUP_NUM	8	// 权限组最大个数
typedef struct
{
    IVS_UINT32   uiTotal;           // 总记录数
    IVS_INDEX_RANGE stIndexRange;   // 分页信息
    IVS_OPERATION_RIGHT_GROUP stOperationRightGroup[1];    // 权限组信息
}IVS_OPERATION_RIGHT_GROUP_LIST;

// 角色类型
typedef enum
{
    ROLE_TYPE_CUSTOM=0,     // 用户自定义角色
    ROLE_TYPE_DEFAULT=1,    // 系统预置默认角色
    ROLE_TYPE_ADMIN=2,      // 超级管理员角色
}IVS_ROLE_TYPE;

// 角色
#define IVS_MAX_ROLE_INFO_NUM   128 // 最大角色个数
typedef struct
{
    IVS_CHAR	cDomainCode[IVS_DOMAIN_CODE_LEN];	// 角色所属域编码
    IVS_UINT32  uiRoleID;                           // 角色ID
    IVS_CHAR    cRoleName[IVS_NAME_LEN];            // 角色名称
    IVS_CHAR    cRoleDescribe[IVS_DESCRIBE_LEN];    // 角色描述
    IVS_UINT32  uiRoleType;                         // 角色类型：值参考 IVS_ROLE_TYPE
    IVS_UINT32  uiGroupID;                       //用户组ID：结构定义参考IVS_USER_GROUP
    IVS_CHAR    cRight[IVS_MAX_OPERATION_RIGHT];    // 角色权限数组：0-没权限，1-有权限，权限值参考 IVS_OPERATION_RIGHT
    IVS_ROLE_ACCOUNT_RULE	stAccountRule;          // 账号规则ID：参考 IVS_ROLE_ACCOUNT_RULE
    IVS_UINT32  uiRoleLogLevel;                     // 角色等级
    IVS_CHAR    cReserve[60];                       // 保留字段
}IVS_ROLE_INFO;

typedef struct
{
    IVS_UINT32   uiTotal;           // 总记录数
    IVS_INDEX_RANGE stIndexRange;   // 分页信息
    IVS_CHAR cReserve[32];          // 保留字段
    IVS_ROLE_INFO stRoleInfo[1];    // 角色信息
}IVS_ROLE_INFO_LIST;

// 用户组
#define IVS_MAX_USER_GROUP_LEVEL	    4	// 用户组层级最大个数
#define IVS_MAX_USER_GROUP_DESC_LEN 	256	// 用户组备注
typedef struct
{
    IVS_CHAR    cDomainCode[IVS_DOMAIN_CODE_LEN];	// 用户组所属域编码
    IVS_UINT32  uiID;               // 用户组ID
    IVS_CHAR    cName[IVS_NAME_LEN];         // 用户组名称
    IVS_UINT32  uiParentID;             // 父用户组ID
    IVS_UINT32  uiLevel;                    // 用户组层级，最多支持4层（包含根组在内）
    IVS_CHAR    cGroupDesc[IVS_MAX_USER_GROUP_DESC_LEN];	// 用户组备注，键盘可见字符和中文，0~64字符。值可以为空
    IVS_CHAR    cReserve[32];                       // 保留字段
}IVS_USER_GROUP;

//用户组列表
typedef struct
{
    IVS_UINT32   uiTotal;           // 总记录数
    IVS_INDEX_RANGE stIndexRange;   // 分页信息
    IVS_CHAR cReserve[32];          //保留字段
    IVS_USER_GROUP stUserGroup[1];  //用户组列表
}IVS_USER_GROUP_LIST;

// 账号状态
typedef enum
{
    ACCOUNT_STATUS_ACTIVE= 1,           // 激活
    ACCOUNT_STATUS_STOPPED= 2,          // 停用
    ACCOUNT_STATUS_INVALID_LOGIN= 3,    // 无效登录锁定
}IVS_ACCOUNT_STATUS;

// 用户信息
typedef struct
{
    IVS_CHAR cDomainCode[IVS_DOMAIN_CODE_LEN+1];   // 用户所属域编码
    IVS_UINT32 uiUserID;                      // 用户ID，系统分配
    IVS_BOOL bFirstLogin;                     // 是否是第一次登录
    // 添加用户需要的信息
    IVS_UINT32 uiRoleID;                     // 角色ID，管理员配置：结构定义参考 IVS_USER_ROLE
    IVS_CHAR    cRoleName[IVS_NAME_LEN];     // 角色名称
    IVS_UINT32 uiGroupID;                    // 用户组ID：结构定义参考 IVS_USER_GROUP
    IVS_CHAR cLoginName[IVS_NAME_LEN];         // 登录账号：登录账号，字母（a-z和A-Z）,数字，中划线和下划线，1~20个字符

    IVS_CHAR cPWD[IVS_PWD_LEN];	               // 登录密码：登录密码，键盘可见字符，1~16个字符。
    IVS_CHAR cSalt[IVS_SALT_LEN];             // 盐值
    IVS_CHAR cPwdModifyDate[IVS_TIME_LEN];      // 密码修改日期

    IVS_UINT32 uiUserType;                   // 用户类型：0：IVS普通用户，1：Windows域用户
    IVS_CHAR cUserDomain[IVS_DOMAIN_LEN];      // Windows域名
    IVS_UINT32 uiStatus;                     // 用户状态：参考 IVS_ACCOUNT_STATUS
    IVS_CHAR cRegiterDate[IVS_TIME_LEN];       // 创建日期
    IVS_CHAR cUserDesc[IVS_DESCRIBE_LEN];      // 用户描述，键盘可见字符和中文，0~64字符。
    IVS_UINT32 uiPTZLevel;                   // 云镜控制优先级：0~9
    IVS_UINT32 uiMaxSessionCnt;              // 多点登录数,最大长度3字符，数字
    IVS_UINT32 uiMaxVideoCnt;                // 最大视频路数，最大长度3字符，数字
    IVS_CHAR cLockTime[IVS_TIME_LEN];         // 账号被锁定的时间

    // 个人基本信息，用于个人修改
    IVS_CHAR    cUserName[IVS_NAME_LEN];         // 真实姓名，汉字和字母（a-z和A-Z），数字，中划线和下划线，1~20个字符
    IVS_CHAR    cEmail[IVS_EMAILE_LEN];          // 邮箱，参考网易163邮箱限制。
    IVS_CHAR    cPhone[IVS_PHONE_NUMBER_LEN];     // 电话，0~25位数字，中划线
    IVS_UINT32  uiSex;                     // 性别：0-女性，1-男性
    IVS_UINT32  uiValidDateFlag;            // 是否有账户有效时间
    IVS_CHAR    cValidDateStart[IVS_TIME_LEN];   // 账户有效起始日期
    IVS_CHAR    cValidDateEnd[IVS_TIME_LEN];     // 账户有效结束日期
    IVS_UINT32	uiPWDExpireTime;        // 密码过期时间，密码创建或修改后开始计时，单位：天，范围：0-999
    IVS_UINT32	uiPWDExpireNotifyTime;  // 密码过期提醒时间，密码过期时间到达前开始提醒，单位：天，范围：0-99
    IVS_CHAR    cReserve[56];               // 保留字段
    //IVS_UINT32	uiPWDExpireTime;			// 密码有效期
    //IVS_UINT32	uiPWDExpireNotifyTime;		// 密码提醒日期
}IVS_USER_INFO;

typedef struct
{
    IVS_UINT32   uiTotal;           // 总记录数
    IVS_INDEX_RANGE stIndexRange;   // 分页信息
    IVS_CHAR cReserve[32];          //保留字段
    IVS_USER_INFO stUserInfo[1];    // 用户信息
}IVS_USER_INFO_LIST;

// 设备用户信息
typedef struct
{
    IVS_UINT32  uiUserID;       // 用户ID，系统分配
    IVS_CHAR    cLoginName[IVS_NAME_LEN];   // 登录账号：登录账号，字母（a-z和A-Z）,数字，中划线和下划线，1~20个字符
    IVS_CHAR    cUserName[IVS_NAME_LEN];    // 真实姓名，汉字和字母（a-z和A-Z），数字，中划线和下划线，1~20个字符
    IVS_UINT32  uiGroupID;              // 用户组ID：结构定义参考 IVS_USER_GROUP
    IVS_CHAR    cReserve[8];
}IVS_DEVICE_USER_INFO;

// 设备用户列表
typedef struct
{
    IVS_UINT32   uiTotal;           // 总记录数
    IVS_INDEX_RANGE stIndexRange;   // 分页信息
    IVS_DEVICE_USER_INFO stDeviceUserInfo[1];    // 设备用户信息
}IVS_DEVICE_USER_INFO_LIST;

// 查询的条件类型
typedef enum
{
    QUERY_INVALID=0,                    // 查询条件无

    QUERY_TIME=1,                      // 默认按照数据库记录生成时间进行排序

    QUERY_USER_ID=100,                  // 用户ID
    QUERY_LOGIN_NAME,                   // 用户的登录账号
    QUERY_USER_NAME,                    // 用户真实姓名
    QUERY_USER_STATUS,                  // 用户状态
    QUERY_USER_NAME_TYPE,               // 用户状态

    QUERY_CAMERA_CODE=200,              // 摄像机编码

    QUERY_DEV_NVR_CODE=300,             // 设备所属NVR编码
    QUERY_DEV_DEV_NAME,                 // 设备名称
    QUERY_DEV_TYPE,                     // 具体设备类型
    QUERY_DEV_VENDOR_TYPE,              // 具体厂商类型
    QUERY_DEV_IP,                       // 具体的设备IP地址
    QUERY_DEV_ONLINE,                   // 是否在线
    QUERY_DEV_SN,                       // 设备SN
    QUERY_DEV_MODEL_TYPE,               // 设备SN
    QUERY_FLOAT_GW,						//浮动网关
	QUERY_CAMERA_TYPE,
	QUERY_CAMERA_LOCATION,
	QUERY_VENDOR_TYPE,
	QUERY_IMG_TYPE,                     /* 智能卡口类型, 0-普通, 1-人脸, 2-车牌, 3-未知, 4-机非人 */
    QUERY_DEV_DELETE_STATUS,                //设备删除状态
    QUERY_RTSP_STATUS_TYPE,                      // (全部不下发该节点，0-不启用，1-启用)

    QUERY_DEV_GROUP_CODE=500,           // 设备组编码
    QUERY_DEV_DOMAIN_CODE,              // 设备所属域编码

    QUERY_RECORD_QUERY_TYPE=600,        // 录像查询方式：0-按时间，1-按书签，2-按预置位，3-按锁定信息
    QUERY_RECORD_BOOKMARK_NAME,         // 书签名，模糊匹配
    QUERY_RECORD_PTZ_PRESET_NAME,       // 预置位名称，模糊匹配，查询预置位查询录像时有效
    QUERY_RECORD_LOCK_DESC,	 	        // 锁定描述，模糊匹配，查询锁定录像时有效
    QUERY_RECORD_LOCK_OPERATOR_TYPE,    // 锁定操作用户类型（查询锁定录像时有效），0-所有用户，1-当前用户
    QUERY_RECORD_METHOD,                // 按存储位置查询录像：值参考 IVS_RECORD_METHOD
    QUERY_RECORD_TYPE,                  // 值参考 IVS_RECORD_TYPE
    QUERY_RECORD_ALARM_TYPE,            // 录像告警类型
    QUERY_RECORD_USER_DOMAIN,           // 录像操作用户域（录像检索、书签、锁定等）
	QUERY_RECORD_LOCK_TIME,				// 录像锁定的时间

    QUERY_OPERATION_ACCOUNT=700,        // 管理员账号
    QUERY_OPERATION_RESULT,             // 操作结果：0-成功，1是失败
    QUERY_OPERATION_START_TIME,         // 开始时间，yyyyMMddhhmmss，查询操作时间
    QUERY_OPERATION_END_TIME,           // 结束时间，yyyyMMddhhmmss，查询操作时间
    QUERY_OPERATION_CODE,               // 操作功能代码
    QUERY_OPERATION_OBJECT_CODE,        // 操作对象编码

    QUERY_ALARM_CATEGORY=800,           // 告警类型级别
    QUERY_ALARM_TYPE,                   // 告警类型，条件必选（例如录像查询，为0表示所有）
    QUERY_ALARM_IN_TYPE,                // 告警源类型
    QUERY_ALARM_LEVEL_ID,               // 告警级别

    QUERY_ALARM_IN_CODES,               // 告警源编码；多选，用逗号“,”分隔；无此条件或为空表示所有
    QUERY_ALARM_IN_NAME,                // 告警源名称
    QUERY_ALARM_LEVEL_MIN,              // 告警级别下限
    QUERY_ALARM_LEVEL_MAX,              // 告警级别上限
    QUERY_ALARM_LEVEL_VALUE,            // 告警级别：同时传递多个告警级别，以逗号“,”隔开
    QUERY_ALARM_STATUS,                 // 告警信息状态；多选，按“,”分割；无此条件或为空表示所有

    QUERY_ALARM_LOCATION_INFO,          // 告警定位信息
    QUERY_ALARM_CONFIRM_OPERATOR,       // 确认人ID；多选，按“,”分割；无此条件或为空表示所有
    QUERY_ALARM_DESC,                   // 告警源描述，模糊查询
    QUERY_ALARM_TYPE_LIST,              // 告警类型列表，用“,”分割，可以表示同时查询多个告警类型，例如录像查询中
    QUERY_ALARM_TYPE_FILTER,            // 需要过滤的告警类型类别，以逗号隔开，010201：行为分析；    010202：人脸识别；    010203：质量诊断

    QUERY_DICTIONARY_TYPE=1000,         // 字典类型，精确查询，必选
    QUERY_DICTIONARY_NAME,              // 字典名称，精确查询，可选
    QUERY_DICTIONARY_PARENT_ID,         // 父节点ID，精确查询，可选

    QUERY_OPERATOR_ID=1100,             //执行查询操作的用户ID
    QUERY_NODE_CODE,        // 网元编码(如果一次查一个网元的，该字段必填)

    QUERY_WATERMARK_ALARM_STATUS=1300,  // 水印告警状态：0x01-未确认 0x02-已确认 0x04-已撤销；异或值表示多选，如0x07表示查询三种状态，0x06表示查询已确认和已撤销；
    QUERY_WATERMARK_USERID_DOMAIN,      // 当前用户所属域编码

    // 外域目录共享
    QUERY_SHARE_EXDOMAIN_CODE=1400,     // 互联域编码，精确查询，必选
    QUERY_SHARE_DIRECT,                 // 共享方向，精确查询，必选：1-本域共享给外域 2-外域共享给本域
    // DeviceType 共用 QUERY_DEV_TYPE   // 共享设备资源类型，精确查询：00：主设备 01：摄像机 02：报警输入设备 03：报警输出设备 99：区域
    QUERY_SHARE_PARENT_ID,              // 父设备编码，精确查询，
    QUERY_SHARE_DEVICE_ID,              // 设备互联编码，精确查询，
    // DevName    共用 QUERY_DEV_DEV_NAME // 设备名称，模糊查询
    QUERY_SHARE_ISLATEST,               // 是否查询最新：0-否，只查询库中的数据 1-是，与外域进行同步后，查询最新的数据

    QUERY_DEV_CATEGORY = 1450,            // 设备种类


    //车辆元数据相关
    QUERY_VEHICLE_SNAP_PLACE = 2000,    //车辆抓拍地点
    QUERY_VEHICLE_DERICTION ,	        //车辆方向
    QUERY_VEHICLE_CUSTOM_ILLEGATYPE ,   //违章类型
    QUERY_VEHICLE_VEHICLE_TYPE ,	    //车辆类型
    QUERY_VEHICLE_VEHICLE_COLOR ,		//车辆颜色
    QUERY_VEHICLE_LANE_CHANNEL ,		//车道信息
    QUERY_VEHICLE_PLATE_COLOR ,			//车牌颜色
    QUERY_VEHICLE_PLATE_TYPE ,			//车牌类型
    QUERY_VEHICLE_PLATE_LICENSE ,		//车牌号
    QUERY_VEHICLE_HANDLE_FLAGE ,		//违章处理标记，目前CU没有使用
    QUERY_VEHICLE_SPEED_MIN ,			//最低车速
    QUERY_VEHICLE_SPEED_MAX ,			//最高车速
    QUERY_VEHICLE_START_TIME ,			//查询开始时间
    QUERY_VEHICLE_END_TIME,				//查询结束时间
    QUERY_VEHICLE_PIC_ATTR ,			//照片属性，标记卡口图片或备份图片

}IVS_QUERY_FIELD_TYPE;

//查询的结构体
#define IVS_QUERY_VALUE_LEN 2048    // 查询字段大小
typedef struct
{
    IVS_UINT32  eFieID;                         //查询字段的类型 参考 IVS_QUERY_FIELD_TYPE
    IVS_CHAR    cValue[IVS_QUERY_VALUE_LEN];    //字段的值
    IVS_BOOL    bExactQuery;                    // 是否精确查询：0-否，1-是
}IVS_QUERY_FIELD;

//排序的结构体
typedef struct
{
    IVS_BOOL    bEnableOrder;       // 是否启用排序 0 - 不排序 1 - 排序
    IVS_UINT32  eFieID;             //排序的字段 参考 IVS_QUERY_FIELD_TYPE
    IVS_BOOL    bUp;                // 是否升序：0-降序，1-升序
}IVS_ORDER_COND;

// 查询通用格式
typedef struct
{
    IVS_INDEX_RANGE stIndex;    // 查询范围索引
    IVS_ORDER_COND stOrderCond; // 排序信息
    IVS_INT32 iFieldNum;        // 字段的数量为0表示无查询限制条件
    IVS_QUERY_FIELD stQueryField[1];
}IVS_QUERY_UNIFIED_FORMAT;


// 设备操作结果
typedef struct
{
    IVS_UINT32  uiSequence;             // 批量操作序号
    IVS_INT32   iResult;                // 错误返回代码（批量添加时）
    IVS_CHAR cCode[IVS_DEV_CODE_LEN];   // 设备编码
}IVS_RESULT_INFO;

// 设备操作结果，含摄像机名称
typedef struct
{
    IVS_UINT32  uiSequence;                     // 批量操作序号
    IVS_INT32   iResult;                        // 错误返回代码（批量添加时）
    IVS_CHAR    cCode[IVS_DEV_CODE_LEN];        // 设备编码
    IVS_CHAR    cCamName[IVS_CAMERA_NAME_LEN];  // 摄像机名称
    IVS_CHAR    cReserve[32];                   // 保留字段
}IVS_RESULT_EX_INFO;

// 设备批量操作结果列表
typedef struct
{
    IVS_UINT32  uiNum;          // 返回的操作结果个数
    IVS_RESULT_INFO stInfo[1];
}IVS_RESULT_LIST;

// 设备批量操作结果列表
typedef struct
{
    IVS_UINT32  uiNum;          // 返回的操作结果个数
    IVS_RESULT_EX_INFO stInfo[1];
}IVS_RESULT_EX_LIST;


// 摄像机计划信息
#define IVS_MAX_CAMERA_PLAN_NUM     64  // 摄像机最大计划种类数
typedef struct
{
    IVS_CHAR    cCameraCode[IVS_DEV_CODE_LEN];  // 摄像头编码
    IVS_INT32   iResult;                        // 错误返回代码（批量时，确认每个摄像机是否成功返回）
    IVS_BOOL    bSetPlan;                       // 是否设置计划 0-未设置 1-已设置
    IVS_CHAR    cReserve[32];                   // 保留字段
}IVS_CAMERA_PLAN_SET_INFO;

// 摄像机计划信息列表
typedef struct
{
    IVS_UINT32      uiNum;                      // 返回的操作结果个数
    IVS_CAMERA_PLAN_SET_INFO    stInfo[1];  // 摄像机计划信息列表
}IVS_CAMERA_PLAN_SET_INFO_LIST;

// 录像计划日类型
typedef enum
{
    DAY_TYPE_EVERYDAY = 0,  // 每天（所有天指定相同时间段录像）
    DAY_TYPE_MONDAY=1,  // 周一
    DAY_TYPE_TUESDAY,   // 周二
    DAY_TYPE_WEDNESDAY, // 周三
    DAY_TYPE_THURSDAY,  // 周四
    DAY_TYPE_FRIDAY,    // 周五
    DAY_TYPE_SATURDAY,  // 周六
    DAY_TYPE_SUNDAY,    // 周日
}IVS_DAY_TYPE;

// 回放时间信息
typedef struct
{
    IVS_CHAR    cPlayBackTime[IVS_TIME_LEN];        // 当前回放时间，格式为yyyyMMddHHmmss
    IVS_CHAR    cPlayBackStartTime[IVS_TIME_LEN];   // 当前开始时间，格式为yyyyMMddHHmmss（本地文件年月日为空）
    IVS_CHAR    cPlayBackEndTime[IVS_TIME_LEN];     // 当前结束时间，格式为yyyyMMddHHmmss（本地文件年月日为空）
    IVS_CHAR    cReserve[64];                       // 保留字段
}IVS_PLAYBACK_TIME;

#define IVS_MAX_TIMESPAN_NUM    24  // 时间段最大数量
#define IVS_MAX_PLAN_INFO_NUM   7   // 最大计划信息个数（一周7天）
// 计划时间信息
typedef struct
{
    IVS_UINT32      uiDayType;    //星期几：参考 IVS_DAY_TYPE 0 – 每天 1 – 周一 2 – 周二 3 – 周三 4 – 周四 5 – 周五 6 – 周六 7 – 周日
    IVS_UINT32      uiTimeSpanInfoNum;      //时间段数量
    IVS_CHAR        cReserve[32];                           // 保留字段
    IVS_TIME_SPAN   stTimeSpanInfo[IVS_MAX_TIMESPAN_NUM];   //时间段信息
}IVS_PLAN_INFO;

// 录像计划类型
typedef enum
{
    RECORD_PLAN_WEEK=0,     // 周计划
    RECORD_PLAN_DAY=1,      // 日计划
    RECORD_PLAN_ALLDAY=2,   // 全程录像
}IVS_RECORD_PLAN_TYPE;

// 录像存储位置
typedef enum
{
    RECORD_METHOD_PLATFORM = 0, // 平台录像
    RECORD_METHOD_PU,   // 前端录像
    RECORD_METHOD_MBU,          // 备份服务器
    RECORD_METHOD_DISASTER_RECOVERY,    // 容灾录像
}IVS_RECORD_METHOD;

// 录像计划
typedef struct
{
    IVS_UINT32  uiRecordMethod;         // 录像存储位置：参考 IVS_RECORD_METHOD
    IVS_BOOL    bEnableRecordPlan;      // 是否启用录像计划 0-未启用，1-启用
    IVS_UINT32  uiRecordPlanType;    // 计划方式：参考 IVS_RECORD_PLAN_TYPE 0-(WEEK)周计划,1(DAY)-日计划，周一到周日计划相同，2-全程录像，
    IVS_CHAR    cReserve[64];           // 保留字段

    IVS_UINT32  uiPlanInfoNum;  // 录像计划信息条数：周计划-7，日计划-1，全程录像-0
    IVS_PLAN_INFO   stPlanInfo[IVS_MAX_PLAN_INFO_NUM];	// 录像计划信息：周计划-最多7个计划信息，日计划-1一个计划信息，全程录像-无
}IVS_RECORD_PLAN;

// 录像计划类型
typedef enum
{
    PLAN_WEEK=0,    // 周计划
    PLAN_DAY=1, // 日计划
    PLAN_ALLDAY=2,  // 全程
}IVS_PLAN_TYPE;

// 防区布防计划
typedef struct
{
    IVS_UINT32  uiAlarmAreaID;          // 防区ID
    IVS_BOOL    bEnablePlan;            // 是否启用录像计划 0-未启用，1-启用
    IVS_UINT32  uiRecordPlanType;       // 计划方式：参考 IVS_PLAN_TYPE
    IVS_CHAR        cReserve[64];           // 保留字段

    IVS_UINT32  uiPlanInfoNum;  // 计划信息条数：周计划-7，日计划-1，全程录像-0
    IVS_PLAN_INFO	stPlanInfo[IVS_MAX_PLAN_INFO_NUM];	// 录像计划信息：周计划-最多7个计划信息，日计划-1一个计划信息，全程录像-无
}IVS_ALARM_AREA_PLAN;

// 本地录像文件分割方式
typedef enum
{
    RECORD_SPLITE_TIME      =1,   // 按时间分割
    RECORD_SPLITE_CAPACITY  =2,   // 按容量分割
}IVS_RECORD_SPLITE_TYPE;

// 本地录像文件命名规则
typedef enum
{
    RULE_NAME_NUM_TIME=1,       // 摄像机名_序号_时间（开始时间-结束时间，YYYY-MM-DD-hh-mm-ss）
    RULE_NAME_TIME_NUM=2,       // 摄像机名_时间（开始时间-结束时间，YYYY-MM-DD-hh-mm-ss）_序号
    RULE_TIME_NAME_NUM=3,       // 时间（开始时间-结束时间，YYYY-MM-DD-hh-mm-ss）_摄像机名_序号
}IVS_RECORD_NAME_RULE;

// 本地录像文件格式
typedef enum
{
    IVS_FILE_MP4=1,       // MP4文件
    IVS_FILE_AVI=2,       // AVI文件
}IVS_RECORD_FILE_TYPE;

// 本地录像参数
#define IVS_MIN_TIME_SPLITTER_VALUE     5       // 最小时间分割值，5分钟
#define IVS_MAX_TIME_SPLITTER_VALUE     720     // 最大时间分割值，720分钟
#define IVS_MIN_SPACE_SPLITTER_VALUE    50      // 最小容量分割值，50M
#define IVS_MAX_SPACE_SPLITTER_VALUE    3072    // 最大容量分割值，3072M
#define IVS_MIN_RECORD_TIME             300     // 最小录像时长，300，单位秒
#define IVS_MAX_RECORD_TIME             43200   // 最大录像时长，43200，单位秒（12小时）
#define IVS_LOCAL_RECORD_PWD_LEN        36      // 本地录像密码最大字节数，包含'\0'
typedef struct
{
    IVS_UINT32  uiRecordFormat;                 // 录像文件格式，参考 IVS_RECORD_FILE_TYPE
    IVS_UINT32  uiSplitterType;                 // 录像分割方式，参考 IVS_RECORD_SPLITE_TYPE
    IVS_UINT32  uiSplitterValue;                // 录像分割值，文件分割方式是时间时，填入时间，对应单位为分钟，5-60分钟，同时满足文件大小不超过2048MB的限制，文件分割方式是容量时，填入容量，对应单位为M，10-2048MB

    IVS_UINT32  uiDiskWarningValue;             // 本地录像，磁盘空间小于此值告警，单位M（进行“本地录像通用事件上报”2-本地录像告警）
    IVS_UINT32  uiStopRecordValue;              // 本地录像，磁盘空间小于此值停止录像，单位M（进行“本地录像通用事件上报”3-本地录像磁盘满停止）

    IVS_UINT32  uiRecordTime;                   // 录像时长，单位秒，整数，300 ~ 43200（12小时）

    IVS_BOOL    bEncryptRecord;                 // 录像是否加密
    IVS_CHAR    cRecordPWD[IVS_LOCAL_RECORD_PWD_LEN];   // 本地录像密码

    IVS_UINT32  uiNameRule;                     // 录像文件命名规则，参考 IVS_RECORD_NAME_RULE
    IVS_CHAR    cSavePath[IVS_FILE_NAME_LEN];   // 本地录像存放路径，加上文件名长度不超过256字节
    IVS_CHAR    cReserve[64];                   // 保留字段
}IVS_LOCAL_RECORD_PARAM;

// 录像下载参数
typedef struct
{
    IVS_UINT32  uiRecordFormat;                 // 录像文件格式，参考 IVS_RECORD_FILE_TYPE
    IVS_UINT32  uiSplitterType;                 // 录像分割方式，参考 IVS_RECORD_SPLITE_TYPE
    IVS_UINT32  uiSplitterValue;                // 录像分割值，文件分割方式是时间时，填入时间，对应单位为分钟，5-60分钟，同时满足文件大小不超过2048MB的限制，文件分割方式是容量时，填入容量，对应单位为M，1-2048MB

    IVS_UINT32  uiDiskWarningValue;             // 磁盘空间小于此值告警，单位M（进行“本地录像通用事件上报”2-本地录像告警）
    IVS_UINT32  uiStopRecordValue;              // 磁盘空间小于此值停止录像，单位M（进行“本地录像通用事件上报”3-本地录像磁盘满停止）

    IVS_UINT32  uiDownloadSpeed;                // 录像下载速度：0-不限速（全速），1-1倍速（前端只支持：1）
    IVS_TIME_SPAN stTimeSpan;                   // 录像下载时间段

    IVS_BOOL    bEncryptRecord;                 // 录像下载是否加密
    IVS_CHAR    cRecordPWD[IVS_LOCAL_RECORD_PWD_LEN];   // 录像下载密码

    IVS_UINT32  uiNameRule;                     // 录像文件命名规则，参考 IVS_RECORD_NAME_RULE
    IVS_CHAR    cSavePath[IVS_FILE_NAME_LEN];   // 录像存放路径，加上文件名长度不超过256字节

    IVS_CHAR    cFileName[IVS_FILE_NAME_LEN];   // 本地录像文件名，绝对路径，长度为256字节（包括后缀和结束符），多份录像文件用序号区分，为空时，根据uiNameRule的命名规则和cSavePath的路径确认文件名
    IVS_CHAR	cNvrCode[IVS_NVR_CODE_LEN + 1]; // NVR编码
    IVS_CHAR    cCamName[IVS_CAMERA_NAME_LEN + 1]; // 摄像机名称
    IVS_CHAR    cDomainCode[IVS_DOMAIN_CODE_LEN + 1]; // 录像所在域
    IVS_UINT32  uiAccessProto;            // 接入协议
	IVS_UINT32  RtspType;
    IVS_CHAR    cReserve[60];                   // 保留字段
}IVS_DOWNLOAD_PARAM;

typedef struct
{
    IVS_UINT32  uiRecordFormat;                 // 录像文件格式，参考 IVS_RECORD_FILE_TYPE
    IVS_UINT32  uiSplitterType;                 // 录像分割方式，参考 IVS_RECORD_SPLITE_TYPE
    IVS_UINT32  uiSplitterValue;                // 录像分割值，文件分割方式是时间时，填入时间，对应单位为分钟，5-60分钟，同时满足文件大小不超过2048MB的限制，文件分割方式是容量时，填入容量，对应单位为M，1-2048MB

    IVS_UINT32  uiDiskWarningValue;             // 磁盘空间小于此值告警，单位M（进行“本地录像通用事件上报”2-本地录像告警）
    IVS_UINT32  uiStopRecordValue;              // 磁盘空间小于此值停止录像，单位M（进行“本地录像通用事件上报”3-本地录像磁盘满停止）

    IVS_FLOAT  fDownloadSpeed;                // 录像下载速度：0-不限速（全速），1-1倍速（前端只支持：1）
    IVS_TIME_SPAN stTimeSpan;                   // 录像下载时间段

    IVS_BOOL    bEncryptRecord;                 // 录像下载是否加密
    IVS_CHAR    cRecordPWD[IVS_LOCAL_RECORD_PWD_LEN];   // 录像下载密码

    IVS_UINT32  uiNameRule;                     // 录像文件命名规则，参考 IVS_RECORD_NAME_RULE
    IVS_CHAR    cSavePath[IVS_FILE_NAME_LEN];   // 录像存放路径，加上文件名长度不超过256字节

    IVS_CHAR    cFileName[IVS_FILE_NAME_LEN];   // 本地录像文件名，绝对路径，长度为256字节（包括后缀和结束符），多份录像文件用序号区分，为空时，根据uiNameRule的命名规则和cSavePath的路径确认文件名
    IVS_CHAR	cNvrCode[IVS_NVR_CODE_LEN + 1]; // NVR编码
    IVS_BOOL    bDirectFirst;                   // 是否直连优先，0-否 1-是，默认为0

    IVS_CHAR    cCamName[IVS_CAMERA_NAME_LEN + 1]; // 摄像机名称
    IVS_CHAR    cDomainCode[IVS_DOMAIN_CODE_LEN + 1];
    IVS_UINT32  uiAccessProto;            // 接入协议
	IVS_UINT32 RtspType;
    IVS_CHAR    cReserve[60];                   // 保留字段

}IVS_DOWNLOAD_PARAM_FSPEED;

// 录像下载信息
typedef struct
{
    IVS_UINT32  uiDownloadStatus;   // 下载状态，0-暂停 1-下载
    IVS_UINT32  uiDownloadSpeed;    // 下载速度，单位KB/S
    IVS_UINT64  uiDownloadSize;     // 已下载大小，单位KB
    IVS_UINT32  uiTimeLeft;         // 剩余下载时间：单位秒
    IVS_UINT32  uiProgress;         // 当前下载进度：0-100，表示百分比
}IVS_DOWNLOAD_INFO;

// 媒体播放信息
typedef struct
{
    IVS_UINT32  uiWinID;                // 窗口ID
    IVS_UINT32  uiAudioStatus;          // 声音状态

    IVS_UINT32  uiVideoFrameRate;   // 视频当前帧率，单位(fps)，范围1-60

    IVS_UINT32  uiVideoBitrate;         //	视频当前码率
    IVS_UINT32  uiVideoAverageBitrate;  //	视频平均码率

    IVS_UINT32  uiAudioBitRate; // 音频当前码率，单位(kbps)
    IVS_UINT32  uiAudioAverageBitRate;  // 音频平均码率，单位(kbps)

    IVS_UINT32  uiVideoCodec;           // 视频编码格式：参考 IVS_VIDEO_DEC_TYPE
    IVS_UINT32  uiVideoWidth;           // 视频画面宽
    IVS_UINT32  uiVideoHeight;          // 视频画面高
    IVS_FLOAT   fLossTolerance;         // 丢包率

    IVS_UINT32  uiInfoLocationX;        // i按钮在屏幕上的右下角X坐标
    IVS_UINT32  uiInfoLocationY;        // i按钮在屏幕上的右下角Y坐标

    IVS_IP      stMediaSourceIP;        // 媒体流发送端IP
    IVS_CHAR    cReserve[64];           // 保留字段
}IVS_MEDIA_INFO;

// 存储类型
typedef enum
{
    RECORD_MODE_FULL=0, // 全量存储
    RECORD_MODE_FRAME_EXTRACTION=1, // 抽帧存储
    RECORD_MODE_VIDEO_COMPRESS=2,   // 运动检测智能存储
}IVS_RECORD_MODE;

// 预录设置
typedef enum
{
    PRERECORD_MODE_NONE=0,  // 不预录
    PRERECORD_MODE_PLAT=1,  // 平台预录
    PRERECORD_MODE_PU=2,    // 前端预录
}IVS_PRERECORD_MODE;

// 录像策略（时间）
#define IVS_MAX_PRERECORD_TIME	300     // 最大预录时间，单位：秒

typedef struct
{
    IVS_UINT32  uiRecordMode;       // 存储类型：参考 IVS_RECORD_MODE

    IVS_UINT32  uiTime;                  // 视频留存天数，单位：天
    IVS_UINT32  uiFrameExtractRecordTime;	// 抽帧存储天数，单位：天
    IVS_UINT32  uiAlarmTime;        // 有告警录像存储天数，单位：天
    IVS_UINT32  uiKeyframeTime;     // 关键帧天数，单位：天

    IVS_UINT32  uiBeforeAlarm;      // 运动检测警前时间，单位：秒（视频归档时有效）
    IVS_UINT32  uiAfterAlarm;       // 运动检测警后时间，单位：秒（视频归档时有效）

    IVS_UINT32  uiPlanStreamType;			// 计划录像使用的流：参考 IVS_STREAM_TYPE
    IVS_UINT32  uiAlarmStreamType;			// 告警录像使用的流：参考 IVS_STREAM_TYPE

    IVS_UINT32  uiAlarmRecordTTL;			// 告警录像留存期，非负整数，0–永久，	其他–留存期，单位：天
    IVS_UINT32  uiManualRecordTTL;			// 手动录像留存期，非负整数，0–永久，	其他–留存期，单位：天

    IVS_UINT32  uiPreRecord;				// 预录设置：参考 IVS_PRERECORD_MODE
    IVS_UINT32  uiPreRecordTime;			// 预录时长，单位：秒，范围(1～IVS_MAX_PRERECORD_TIME)

    IVS_BOOL    bAssociatedAudio;			// 随路音频叠加选项：	0-不叠加 1-叠加

    IVS_CHAR    cReserve[32];
}IVS_RECORD_POLICY_TIME;

// 录像策略（容量）
typedef struct
{
    IVS_UINT32  uiRecordMode;				// 存储类型：参考 IVS_RECORD_MODE

    IVS_UINT32  uiBeforeAlarm;				// 运动检测警前时间，单位：秒（视频归档时有效）
    IVS_UINT32  uiAfterAlarm;				// 运动检测警后时间，单位：秒（视频归档时有效）

    IVS_UINT32  uiPlanStreamType;			// 计划录像使用的流：参考 IVS_STREAM_TYPE
    IVS_UINT32  uiAlarmStreamType;			// 告警录像使用的流：参考 IVS_STREAM_TYPE

    IVS_UINT32  uiAlarmRecordTTL;			// 告警录像留存期，非负整数，0–永久，	其他–留存期，单位：天
    IVS_UINT32  uiManualRecordTTL;			// 手动录像留存期，非负整数，0–永久，	其他–留存期，单位：天

    IVS_UINT32  uiPreRecord;				// 预录设置：参考 IVS_PRERECORD_MODE
    IVS_UINT32  uiPreRecordTime;			// 预录时长，单位：秒，范围(1～IVS_MAX_PRERECORD_TIME)

    IVS_BOOL    bAssociatedAudio;			// 随路音频叠加选项：	0-不叠加 1-叠加

    IVS_UINT64  uiCapacity;                 // 容量，MB为单位
    IVS_UINT32  uiFullPolicy;               // 录像空间满处理策略：0-满覆盖所有录像  1-满覆盖计划录像 2-满停止

    IVS_CHAR    cReserve[32];
}IVS_RECORD_POLICY_CAPACITY;

#define IVS_RECORD_TYPE_LEN      8	// 录像类型长度
typedef enum
{
    RECORD_TYPE_IA=1,              // 智能分析录像
    RECORD_TYPE_ALARM=2,       // 普通告警录像
    RECORD_TYPE_PLAN=4,         // 计划录像
    RECORD_TYPE_MANUAL=8,    // 手动录像
}IVS_RECORD_TYPE;

// 录像抽帧次数
typedef enum
{
    FRAME_EXTRACTION_0= 0,  // 完整
    FRAME_EXTRACTION_1= 1,  // 不完整（抽帧一次）
    FRAME_EXTRACTION_2= 2,  // 不完整（抽帧二次）
    FRAME_EXTRACTION_3= 3,  // 不完整（抽帧三次）
}IVS_FRAME_EXTRACTION_TIMES;

// 录像标签信息，查询方式为按书签时有效
#define IVS_BOOKMARK_NAME_LEN 612
typedef struct
{
    IVS_UINT32	uiBookmarkID;                           // 录像标签ID
    IVS_CHAR	cBookmarkName[IVS_BOOKMARK_NAME_LEN];   // 标签名，长度最大150字符
    IVS_CHAR	cBookmarkTime[IVS_TIME_LEN];            // 标签时间：yyyyMMddHHmmss

    IVS_CHAR	cCameraCode[IVS_DEV_CODE_LEN];          // 摄像头编码
    IVS_CHAR	cCameraName[IVS_NAME_LEN];              // 摄像头名称

    IVS_CHAR	cUserDomain[IVS_DOMAIN_CODE_LEN];       // 操作用户所在域编码
    IVS_UINT32  uiBookmarkCreatorID;                    // 创建书签的用户ID
    IVS_CHAR    cBookmarkCreatorName[IVS_NAME_LEN];     // 创建书签的用户名

    IVS_CHAR	cNvrCode[IVS_NVR_CODE_LEN];             // NVR编码
    IVS_CHAR	cMBUDomain[IVS_DOMAIN_CODE_LEN];        // 备份服务器域编码备份录像检索结果中带此字段

    IVS_CHAR	cReserve[32];
}IVS_RECORD_BOOKMARK_INFO;

// 录像书签列表
typedef struct
{
    IVS_UINT32   uiTotal;                           // 总记录数
    IVS_INDEX_RANGE stIndexRange;                   // 分页信息
    IVS_CHAR cRes[32];                              //保留字段
    IVS_RECORD_BOOKMARK_INFO stBookmarkInfo[1];     // 录像书签信息
}IVS_RECORD_BOOKMARK_INFO_LIST;

// 录像锁定信息，查询方式为按锁定状态时有效
#define IVS_RECORD_LOCK_DESC_LEN 1024                   //260
typedef struct
{
    IVS_UINT64	uiLockID;						        // 锁定记录ID
	IVS_UINT32  uiLockDuration;                         // 锁定时长
    IVS_CHAR	cLockTime[IVS_TIME_LEN];		        // 执行锁定操作的时间
    IVS_TIME_SPAN	stLockTimeSpan;				        // 锁定的录像时段
    IVS_CHAR	cLockDesc[IVS_RECORD_LOCK_DESC_LEN];	// 锁定描述

    IVS_UINT32	uiOperatorID;						    // 执行锁定操作的用户ID
    IVS_CHAR	cOperatorName[IVS_NAME_LEN];            // 执行锁定操作的用户名
	IVS_CHAR	uiLockName[IVS_NAME_LEN];               // 执行锁定录像名称
    IVS_CHAR    cReserve[60];                           // 保留字段64-->60
}IVS_RECORD_LOCK_INFO;

// 录像锁定信息
typedef struct
{
	IVS_CHAR				cCameraCode[IVS_DEV_CODE_LEN + 1];
	IVS_CHAR    			cNVRCode[IVS_NVR_CODE_LEN + 1];
	IVS_RECORD_LOCK_INFO	stRecordLockInfo;
}IVS_RECORD_LOCK;

typedef struct
{
	IVS_UINT32		uiTotal;		 //返回的总条目数
	IVS_RECORD_LOCK stRecordLockInfo[1];
}IVS_QUERY_RECORD_LOCK_OUTPUT_INFO;

// 录像预置位信息，查询方式为按预置位查询时有效
#define IVS_RECORD_PTZ_PRESET_NAME_LEN 64
typedef struct
{
    IVS_UINT32  uiID;   // 预置位ID
    IVS_CHAR    cName[IVS_RECORD_PTZ_PRESET_NAME_LEN];  // 预置位名称
    IVS_CHAR    cReserve[32];                           // 保留字段
}IVS_RECORD_PTZ_PRESET_INFO;

// 录像检索信息
typedef struct
{
    IVS_CHAR    cRecordFileName[IVS_FILE_NAME_LEN];   // 录像文件名

    IVS_UINT32  uiRecordMethod;                     // 录像存储位置：参考 IVS_RECORD_METHOD
    IVS_CHAR    cNvrCode[IVS_NVR_CODE_LEN];             // NVR编码，仅在平台录像检索结果中带此字段（内部处理）
    IVS_CHAR    cMBUDomain[IVS_DOMAIN_CODE_LEN];        // 备份服务器域编码备份录像检索结果中带此字段

    IVS_UINT32  uiRecordType;                       // 录像类型：参考 IVS_RECORD_TYPE
    IVS_CHAR    cAlarmType[IVS_QUERY_VALUE_LEN];    // 告警类型，录像类型为告警录像时有效（英文字符串）
    IVS_TIME_SPAN   stTime;                             // 录像起止时间
    IVS_UINT32  uiFrameExtractionTimes;            // 录像抽帧次数：参考 IVS_FRAME_EXTRACTION_TIMES

    IVS_RECORD_BOOKMARK_INFO    stBookmarkInfo;         // 录像标签信息，查询方式为按书签时有效
    IVS_RECORD_LOCK_INFO    stLockInfo;         // 锁定信息，查询方式为按锁定状态时有效
    IVS_RECORD_PTZ_PRESET_INFO  stPtzPresetInfo;        // 录像预置位信息，查询方式为按预置位查询时有效
    IVS_CHAR    cReserve[64];                           // 保留字段
}IVS_RECORD_INFO;

// 录像信息列表
typedef struct
{
    IVS_UINT32   uiTotal;               // 总记录数
    IVS_INDEX_RANGE stIndexRange;       // 分页信息
    IVS_CHAR cRes[32];          //保留字段
    IVS_RECORD_INFO stRecordInfo[1];    // 录像检索信息
}IVS_RECORD_INFO_LIST;

// 运动幅度数据信息
typedef struct
{
    IVS_CHAR	StartTime[IVS_TIME_LEN];    // 统计间隔起始时间，国际标准时间, 只有时分秒
    IVS_CHAR	EndTime[IVS_TIME_LEN];      // 统计间隔结束时间，国际标准时间, 只有时分秒
    IVS_UINT64	uiMotionData;	            // [OUT]在查询时间段内按时间间隔统计的移动数据
    IVS_CHAR    cReserve[32];               // 保留字段
}IVS_MOTION_RANGE_DATA_INFO;

// 运动幅度数据列表
typedef struct
{
    IVS_TIME_SPAN   stTime;     // [OUT]运动幅度数据起止时间
    IVS_UINT32          uiTimeInterval; // [OUT]运动幅度数据统计时间间隔

    IVS_UINT32  uiTotal;    // [OUT]总记录数
    IVS_INDEX_RANGE stIndexRange;	// [IN]分页信息
    IVS_MOTION_RANGE_DATA_INFO	stMotionRangeDataInfo[1];   // [OUT]运动幅度数据信息，可多条
}IVS_MOTION_RANGE_DATA_LIST;

// 通用设备类型（查询设备时获取）
typedef enum
{
    DEVICE_TYPE_MAIN=1,		// 主设备
    DEVICE_TYPE_CAMERA,		// 摄像头设备
    DEVICE_TYPE_VOICE,		// 语音设备
    DEVICE_TYPE_ALARM,	    // 告警设备（同时获取告警输入、告警输出）
    DEVICE_TYPE_SERIAL,	    // 串口设备

    DEVICE_TYPE_ALARMIN = 6,      //开关量输入设备
    DEVICE_TYPE_ALARMOUT = 7,     //开关量输出设备
    DEVICE_TYPE_EXTEND_ALARM=9,   // 外域告警设备

    DEVICE_TYPE_SHADOW_CAMERA = 30, //影子摄像头
    DEVICE_TYPE_ALL_CAMERA = 31,    //所有类型的摄像头
}IVS_DEVICE_TYPE;

// 主设备形态类型
typedef enum
{
    DEVICE_IPC= 1,	// 摄像机
    DEVICE_DVS,		// DVS
    DEVICE_DVR,		// DVR
    DEVICE_ENVR,    // eNVR
}IVS_MAIN_DEVICE_TYPE;

// 子设备形态类型
typedef enum
{
    DEVICE_CAMERA= 1,	// 摄像头
    DEVICE_ALARM_IN,	// 告警输入子设备
    DEVICE_ALARM_OUT,	// 告警输出子设备
    DEVICE_AUDIO_IN,	// 音频输入子设备
    DEVICE_AUDIO_OUT,	// 音频输出子设备
    DEVICE_SERIAL,		// 串口子设备
}IVS_CHANNEL_TYPE;

// 厂商类型
typedef enum
{
    VENDOR_NONE=0,      // 厂商无
    VENDOR_HUAWEI=1,	// 华为
    VENDOR_HIKVISION,	// 海康威视
    VENDOR_DAHUA,		// 大华
    VENDOR_AXIS,		// 安讯士
    VENDOR_BOSCH,		// 博世
    VENDOR_SONY,		// 索尼
    VENDOR_PANASONIC	// 松下
}IVS_VENDOR_TYPE;

// IPC位置信息
typedef struct
{
    IVS_DOUBLE	dLongitude;             // 安装经度	20	最多12位小数，-180~180
    IVS_DOUBLE	dLatitude;				// 安装纬度	20	最多12位小数，-90~90
    IVS_DOUBLE	dHeight;                // 安装高度	5	单位m，0-999.99
    IVS_CHAR	cCameraLocation[IVS_DESCRIBE_LEN];	// 摄像机安装位置描述
    IVS_CHAR    cReserve[32];                       // 保留字段
}IVS_CAMERA_POSITION;

//码率类型
typedef enum
{
    BITRATE_CBR = 0,	//定码率
    BITRATE_VBR			//变码率
}IVS_BITRATE_TYPE;

// 设备网络地址信息
typedef struct
{
    IVS_IP		stIPV4;
    IVS_CHAR	cIPV4Gateway[IVS_IP_LEN];	// ipv4网关
    IVS_IP		stIPV6;
    IVS_CHAR	cIPV6Gateway[IVS_IP_LEN];	// ipv6网关
}IVS_DEV_IP_INFO;

// 设备状态
typedef enum
{
    DEV_STATUS_OFFLINE= 0,	// 离线
    DEV_STATUS_ONLINE,		// 在线
    DEV_STATUS_SLEEP,		// 休眠
}IVS_DEV_STATUS;

// 视频制式
typedef enum
{
    VIDEO_STANDART_NONE= 0,
    VIDEO_STANDART_PAL,
    VIDEO_STANDART_NTSC,
}IVS_VIDEO_STANDARD;

// 设备时间同步信息
typedef struct
{
    IVS_UINT32	uiNtpType;		// NTP同步方式：0-DHCP，1-手动指定服务器

    IVS_IP		stNtpServerIP;	// NTP服务器IP，当NTP同步方式uiNtpType为1时有效
    IVS_IP		stDnsIP;		// DNS地址，当NTP同步方式uiNtpType为1时有效
    IVS_CHAR	cRes[32];
}IVS_NTP_INFO;

// 主设备网络参数
typedef struct
{
    IVS_IP  stPUIp; // 前端IP
    IVS_IP  stPUGateway;    // 前端网关(onvif设备)
    IVS_UINT32  uiPUPort;       // 设备端口
    IVS_UINT32  uiMaxMtu;   // 最大MTU值
    IVS_IP  stSubNetMask;   // 子网掩码
	IVS_UINT32	uiRTSPEnable;
	IVS_UINT32	uiRTSPPort;	
    IVS_CHAR    cReserve[24];
}IVS_DEVICE_NET_CFG;

//获取摄像机Web端口
typedef struct
{
	IVS_CHAR  cCameraCode[IVS_DEV_CODE_LEN + 1];
	IVS_UINT32	uiWebPort;
	IVS_CHAR	cProtocolType[IVS_PROTOCOL_LEN];
	IVS_CHAR cReserve[64];
}IVS_DEV_NET_CFG_EX;

//获取摄像机的代理地址
typedef struct
{
	IVS_CHAR  cCameraCode[IVS_DEV_CODE_LEN + 1];
	IVS_CHAR cProxyName[IVS_PROXY_LEN];
	IVS_CHAR cReserve[64];
}IVS_DEV_PROXY;

// 摄像机安全参数
typedef struct
{
    IVS_BOOL    bEnableMediaSecurity;       // 是否启用媒体安全：0-关闭 1-开启
    IVS_BOOL    bEnableSecureStorage;       // 是否启用安全存储：0-关闭 1-开启
    IVS_UINT32  uiMediaSecurityAlgorithm;   // 媒体安全算法: 0-媒体扰码 1-AES256
    IVS_CHAR	cReserve[32];
}IVS_MEDIA_SECURITY_CFG;

// 可靠传输类型
typedef enum
{
    RELIABLE_TRANSMISSION_NONE,
    RELIABLE_TRANSMISSION_FEC,
    RELIABLE_TRANSMISSION_ARQ,
    RELIABLE_TRANSMISSION_HARQ,
    RELIABLE_TRANSMISSION_SEC,
}IVS_RELIABLE_TRANSMISSION_TYPE;

// 摄像机扩展参数
typedef struct
{
    IVS_BOOL    bEnableWatermark;        // 是否启用水印：0-关闭 1-开启
    IVS_BOOL    bEnableBandwidthAdaptive;   // 是否启用带宽自适应：0-关闭 1-开启
    IVS_BOOL    bEnableCache;               // 是否启用缓存：0-关闭 1-开启

    IVS_MEDIA_SECURITY_CFG stMediaSecurityCfg;  // 安全相关参数
    IVS_CHAR    cReserve[32];
}IVS_CAMERA_EXTEND_CFG;

// 摄像机FEC参数
typedef struct
{
    IVS_UINT32  uiReliableTransmission;     // 可靠传输类型，值参考 IVS_RELIABLE_TRANSMISSION_TYPE:0代表当前设备当前值
    IVS_UINT32  uiDataDropPercent;           // 可靠传输类型FEC模式下，丢包率    1:  1%丢包率   2:  2%丢包率  3:  3%丢包率   4:  4%丢包率   5:  5%丢包率
    IVS_CHAR	cReserve[32];
    IVS_UINT32  uiSelReliableTransmission[IVS_RELIABLE_TRANSMISSION_TYPE_NUM];	//可选择的传输类型：NONE FEC SEC ARQ HARQ
    IVS_UINT32  uiSelDataDropPercent[IVS_RELIABLE_TRANSMISSION_TYPE_NUM];        //每种可选择类型支持的丢包率
    IVS_UINT32  uiSelNum;                       //支持的类型个数
}IVS_CAMERA_FEC_CFG;

// 摄像机抓拍参数
typedef struct
{
    IVS_UINT32  uiSnapCount;    // 抓拍数量，范围1-5
    IVS_UINT32  uiSnapInterval; // 抓拍时间间隔，范围1-5秒
    IVS_CHAR	cReserve[8];
}IVS_CAMERA_SNAPSHOT_CFG;

// 摄像机前端录像码流参数
typedef struct
{
    IVS_UINT32	uiStreamType;	    // 码流类型：参考 IVS_STREAM_TYPE
    IVS_CHAR	cReserve[8];
}IVS_CAMERA_RECORD_STREAM_CFG;

// 主设备扩展属性
typedef struct
{
    IVS_BOOL	bEnableWatermark;	// 是否启用水印 0：否 1:是？视频子设备参数
    IVS_BOOL	bEnableEncrypt;		// 是否启用加密 0: 否 1:是？
    IVS_BOOL	bEnableCache;		// 是否支持缓存补录 0:否 1:是
    IVS_CHAR    cReserve[32];       // 保留字段
}IVS_DEVICE_EXCFG;

// 主设备通道信息
typedef struct
{
    IVS_UINT32	uiMaxVideoNum;		// 最大视频通道数
    IVS_UINT32	uiMaxAudioInNum;	// 最大音频输入通道数
    IVS_UINT32	uiMaxAudioOutNum;	// 最大音频输出通道数
    IVS_UINT32  uiMaxAlarmInNum;	// 最大告警输入通道数
    IVS_UINT32  uiMaxAlarmOutNum;	// 最大告警输出通道数
    IVS_UINT32  uiMaxSerialNum;		// 最大串口通道数
    IVS_CHAR    cReserve[32];       // 保留字段
}IVS_DEVICE_CHANNEL_CFG;

// 主设备时间参数
typedef struct
{
    IVS_BOOL	    bEnableNtp;	    // 是否启用NTP同步：0-不启用（手动设置时间），1-启用（自动同步时间）
    IVS_NTP_INFO    stNTP;	        // NTP信息(单独接口实现) 时间参数（当bEnableNtp值为1，自动同步时间时有效）
    IVS_INT32	    iTimezone;	    // 设备所在时区，以时区偏移量记录-50400~50400秒 （当bEnableNtp值为0，手动设置时间时有效）
    IVS_BOOL	    bEnableDst;	    // 是否启用夏令时 0:不启用,1:启用 （当bEnableNtp值为0，手动设置时间时有效）
    IVS_BOOL        bChangeNtp;     // 0 修改Ntp   1 不修改Ntp
    IVS_CHAR        cReserve[28];   // 保留字段
}IVS_DEVICE_TIME_CFG;

// 通用设备信息（NVR/TAS）（主设备 DVR/DVS/IPC）
#define IVS_MAX_VENDOR_TYPE_NAME_LEN    32  // 厂商名称最大长度
#define IVS_DEVICE_NAME_LEN             128 // 主设备名称长度
typedef struct
{
    IVS_UINT32	uiType;									// 主设备类型：参考 IVS_MAIN_DEVICE_TYPE
	IVS_UINT32 uiNodeType;                       // 主设备节点类型: 用来区分MPU-R和MPU-T
    IVS_CHAR	cSerialNumber[IVS_DEV_SERIALNO_LEN];	// 序列号(SN/IMEI)

    IVS_CHAR	cCode[IVS_DEV_CODE_LEN];	        // 设备编码
    IVS_CHAR	cName[IVS_DEVICE_NAME_LEN];		    // 设备名称

    IVS_CHAR	cParentCode[IVS_DEV_CODE_LEN];	    // 父设备编码，如果不为空，表示通过eNVR接入
    IVS_CHAR	cDomainCode[IVS_DOMAIN_CODE_LEN];	// 域编码

    IVS_CHAR	cVendorType[IVS_MAX_VENDOR_TYPE_NAME_LEN];  // 设备提供商类型: "HUAWEI" "HIK"

    IVS_CHAR	cModel[IVS_DEV_MODEL_LEN];	// 设备型号

    IVS_IP		stIP;						// 设备IP信息
    IVS_UINT32	uiPort;						// 设备连接端口
    IVS_UINT32  uiRole;                     // 角色 1：Server+Client     2：Client
    IVS_CHAR    cDCGIP[IVS_IP_LEN + 1];     // 接入网关IP，如果接入网关为本机，则显示空

    IVS_CHAR	cProductType[IVS_MAX_VENDOR_TYPE_NAME_LEN];  //产品类型: "VCN500" "VCN3000"

    IVS_BOOL	bShadowDev;                                  // 是否影子IPC
    IVS_CHAR	cOrigDevCode[IVS_DEV_CODE_LEN+1];	         // 源设备编码
    IVS_CHAR	cOriDevDomainCode[IVS_DOMAIN_CODE_LEN+1];	 // 源域编码
    IVS_BOOL	bRename;                                     // 是否允许重命名
    IVS_CHAR	cOriDevDomainType[16];	                     // 源域类型

    //IVS_UINT32  uiDevGroupID;               //主设备所在设备组ID
    //
    //IVS_CHAR	cReserve[28];

    /* 智能卡口类型, 0-普通, 1-人脸, 2-车牌, 3-未知, 4-机非人 */
    IVS_UINT32  uiImgType;
    IVS_CHAR	cReserve[24];}IVS_DEVICE_BASIC_INFO;

// 设备编码信息
typedef struct
{
    IVS_CHAR	cCode[IVS_DEV_CODE_LEN];	// 设备编码
    IVS_CHAR	cNvrCode[IVS_NVR_CODE_LEN];	// 设备所属NVR编码, 表示该设备被该NVR管理

    IVS_UINT32	uiSequence;	// 序号
    IVS_UINT32	uiResult;	// 操作结果
	IVS_UINT32	RegisterErr;
    IVS_CHAR    cReserve[28];   // 保留字段 增加RegisterErr 减少4字节
}IVS_DEVICE_OPER_RESULT;

// 设备编码列表
typedef struct
{
    IVS_UINT32	uiNum;
    IVS_DEVICE_OPER_RESULT	stCodeInfo[1];
}IVS_DEVICE_OPER_RESULT_LIST;

// 设备编码
typedef struct
{
    IVS_CHAR cDevCode[IVS_DEV_CODE_LEN];	// 设备编码
}IVS_DEVICE_CODE;

// 分组编码
typedef struct
{
    IVS_CHAR cGroupCode[IVS_GROUP_CODE_LEN];    // 分组编码
}IVS_GROUP_CODE;

// 认证类型
typedef enum
{
    LOGINTYPE_NONE= 0,
    LOGINTYPE_HTTP_DIGEST,		// HTTP Digest
    LOGINTYPE_USERNAME_TOKEN,	// WS-Usernametoken Authentication
}IVS_LOGINTYPE;

// 主设备配置参数
#define IVS_MAX_PROTOCOLTYPE_NAME_LEN   64  // 协议类型描述最大长度
typedef struct
{
    IVS_DEVICE_BASIC_INFO	stDeviceInfo;	        // 主设备基本信息
    //
    IVS_CHAR	cProtocolType[IVS_MAX_PROTOCOLTYPE_NAME_LEN];		// 主设备协议类型: "TEYES"-千里眼   "ONVIF"  "HWSDK"-华为SDK "HIKSDK"-海康SDK

    IVS_UINT32	iLoginType;			                // 认证类型：参考 IVS_LOGINTYPE 驱动为ONVIF时认证类型可设置，认证类型有三种（0:None、1:HTTP Digest、2:WS-Usernametoken Authentication）

    IVS_BOOL	bEnableAlarm;		                // 设备告警使能 1-启用（ON） 0-停用（OFF）参考：IVS_VIDEO_STANDARD
    IVS_UINT32	uiVideoFormat;		                // 视频制式 1-PAL 2-NTSC

    IVS_UINT32	uiDirectConnectFirst;	            // 是否直连优先： 0-非直连优先 1-直连优先
    IVS_UINT32	uiMaxDirectConnectNum;	            // 最大直连数目

    IVS_BOOL	bEnableSchedule;	                // 是否启用集群调度：0-否, 1-是(NVR CODE 不为空)
    IVS_CHAR	cNvrCode[IVS_NVR_CODE_LEN];			// 设备所属NVR编码, 表示该设备被该NVR管理
    IVS_CHAR	cTasCode[IVS_TAS_CODE_LEN];			// 设备所属TAS编码, 当是被通过独立部署的DCG接入时使用
    IVS_IP      stTasIP;                               // TASIP
    IVS_CHAR	cDevUser[IVS_NAME_LEN];				// 设备登录用户名
    IVS_CHAR	cDevPasswd[IVS_PWD_LEN];		// 设备登录密码
    IVS_CHAR	cDevRegPasswd[IVS_PWD_LEN];	// 设备向平台注册密码
    IVS_UINT32  uiRegMode;
    IVS_DEVICE_CHANNEL_CFG  stDeviceChannel;        // 设备通道信息
    IVS_UINT32	uiImgType;	            // 是否启用车牌分析或人脸检测
	IVS_UINT32 uiMode;                  //当前设备的模式
	IVS_UINT32 uiRTSPEnable;
	IVS_UINT32 uiRTSPPort;
    IVS_CHAR	cReserve[16];
}IVS_DEVICE_CFG;

// 主设备统一编码信息
typedef struct
{
    IVS_CHAR cUnifiedAccessCode[IVS_DEV_ACCESSCODE_LEN]; //主设备统一编码
    IVS_CHAR	cReserve[32];
}IVS_DEVICE_UNIFIEDCONDE_CFG;

// 主设备操作信息包含统一编码
typedef struct
{
    IVS_UINT32	uiSequence;			// 设备序号（如添加操作等）
    IVS_DEVICE_CFG	stDeviceCfg;	// 主设备配置参数
    IVS_CHAR    cUnifiedAccessCode[IVS_DEV_ACCESSCODE_LEN];        //设备统一编码
    IVS_CHAR    cReserve[32];       // 保留字段
}IVS_DEVICE_OPER_INFO_UNIFIED_ACCESS_CODE;

// 主设备操作信息
typedef struct
{
    IVS_UINT32	uiSequence;			// 设备序号（如添加操作等）
    IVS_DEVICE_CFG	stDeviceCfg;	// 主设备配置参数

    IVS_CHAR    cReserve[32];       // 保留字段
}IVS_DEVICE_OPER_INFO;

typedef struct
{
    IVS_DEVICE_BASIC_INFO	stDeviceInfo;	        // 主设备基本信息
    //
    IVS_CHAR	cProtocolType[IVS_MAX_PROTOCOLTYPE_NAME_LEN];		// 主设备协议类型: "TEYES"-千里眼   "ONVIF"  "HWSDK"-华为SDK "HIKSDK"-海康SDK

    IVS_UINT32	iLoginType;			                // 认证类型：参考 IVS_LOGINTYPE 驱动为ONVIF时认证类型可设置，认证类型有三种（0:None、1:HTTP Digest、2:WS-Usernametoken Authentication）

    IVS_BOOL	bEnableAlarm;		                // 设备告警使能 1-启用（ON） 0-停用（OFF）参考：IVS_VIDEO_STANDARD
    IVS_UINT32	uiVideoFormat;		                // 视频制式 1-PAL 2-NTSC

    IVS_UINT32	uiDirectConnectFirst;	            // 是否直连优先： 0-非直连优先 1-直连优先
    IVS_UINT32	uiMaxDirectConnectNum;	            // 最大直连数目

    IVS_BOOL	bEnableSchedule;	                // 是否启用集群调度：0-否, 1-是(NVR CODE 不为空)
    IVS_CHAR	cNvrCode[IVS_NVR_CODE_LEN];			// 设备所属NVR编码, 表示该设备被该NVR管理
    IVS_CHAR	cTasCode[IVS_TAS_CODE_LEN];			// 设备所属TAS编码, 当是被通过独立部署的DCG接入时使用
    IVS_IP      stTasIP;                               // TASIP
    IVS_CHAR	cDevUser[IVS_NAME_LEN];				// 设备登录用户名
    IVS_CHAR	cDevPasswd[IVS_PWD_LEN];		// 设备登录密码
    IVS_CHAR	cDevRegPasswd[IVS_PWD_LEN];	// 设备向平台注册密码
    IVS_UINT32  uiRegMode;
    IVS_DEVICE_CHANNEL_CFG  stDeviceChannel;        // 设备通道信息
    IVS_UINT32	uiImgType;	            // 是否启用车牌分析或人脸检测
	IVS_UINT32 uiMode;                  //当前设备的模式
	IVS_UINT32 uiRTSPEnable;
	IVS_UINT32 uiRTSPPort;
    IVS_CHAR    cConnectCode[IVS_DEV_CODE_LEN];   //互联编码
    IVS_CHAR	cReserve[128];
}IVS_DEVICE_CFG_V2;


typedef struct
{
    IVS_UINT32	uiSequence;			// 设备序号（如添加操作等）
    IVS_DEVICE_CFG_V2 stDeviceCfg;	// 主设备配置参数
    
    IVS_CHAR    cReserve[128];       // 保留字段

}IVS_DEVICE_OPER_INFO_V2;

// 影子IPC信息
typedef struct
{
    IVS_CHAR cDomainCode[IVS_DOMAIN_CODE_LEN + 1];	           // 设备所在域
    IVS_CHAR cDevCode[IVS_DEV_CODE_LEN + 1];	               // 设备编码
    IVS_CHAR cDevName[IVS_DEVICE_NAME_LEN + 1];		           // 设备名称
    IVS_CHAR cNvrCode[IVS_NVR_CODE_LEN + 1];	               // 设备所属NVR编码
    IVS_CHAR cProtocolType[IVS_MAX_PROTOCOLTYPE_NAME_LEN + 1]; // 设备协议类型: "TEYES"-千里眼   "ONVIF"  "HWSDK"-华为SDK "HIKSDK"-海康SDK
    IVS_CHAR cGroupCode[IVS_DEVICE_GROUP_LEN + 1];             // 设备组编码，如果为空的话，默认添加到根组
    IVS_CHAR cOrigDevDomain[IVS_DOMAIN_CODE_LEN + 1];	       // 设备所在原始域
    IVS_CHAR cOrigDevCode[IVS_DEV_CODE_LEN + 1];	           // 设备原始编码
    IVS_CHAR cOrigDomainType[16];                               // 设备所在原始域类型
}IVS_SHADOW_DEV_INFO;

// 同步影子IPC信息
typedef struct
{
    IVS_CHAR cDevCode[IVS_DEV_CODE_LEN + 1];	               // 设备编码
}IVS_SHADOW_DEV_INFO_SYNC;



// 摄像机显示参数
typedef struct
{
    IVS_UINT32	uiBrightness;	// 亮度，范围：0-255
    IVS_UINT32	uiContrast;		// 对比度，范围：0-255
    IVS_UINT32	uiHue;			// 色度，范围：0-255
    IVS_UINT32	uiSaturation;	// 饱和度，范围：0-255
    IVS_CHAR    cReserve[32];   // 保留字段
}IVS_CAMERA_DISPLAY_CFG;

// 背光补偿参数
typedef struct
{
    IVS_UINT32  uiBacklightMode;    // 背光补偿模式 0-关闭；1-开启
    IVS_UINT32  uiBacklightLevel;   // 背光补偿等级 0-3
    IVS_CHAR    cReserve[32];       // 保留字段
}IVS_BACKLIGHT;

// 曝光参数
typedef struct
{
    IVS_UINT32  uiExposureMode;     // 曝光模式 0-自动；1-手动
    IVS_UINT32  uiExposurePriority; // 曝光优先模式 0-低噪优先；1-帧率优先
    IVS_RECT_FLOAT    rectWindow;   // 曝光窗口
    IVS_UINT32  uiExposureTime;     // 曝光时间（单位微秒us）
    IVS_UINT32  uiExposureGain;     // 曝光增益（单位dB）
    IVS_UINT32  uiExposureIris;     // 光圈
    IVS_CHAR    cReserve[32];       // 保留字段
}IVS_EXPOSURE;

// 变焦参数
typedef struct
{
    IVS_UINT32  uiFocusMode;        // 变焦模式 0-自动；1-手动
    IVS_UINT32  uiFocusSpeed;       // 变焦速度
    IVS_UINT32  uiNearLimit;        // 最小变焦范围
    IVS_UINT32  uiFarLimit;         // 最大变焦范围
    IVS_CHAR    cReserve[32];       // 保留字段
}IVS_FOCUS;

// 宽动态参数
typedef struct
{
    IVS_UINT32  uiWideDynamicMode;  // 宽动态模式 0-关闭；1-开启
    IVS_UINT32  uiWideDynamicLevel; // 宽动态等级 0-20
    IVS_CHAR    cReserve[32];       // 保留字段
}IVS_WIDE_DYNAMIC;

// 白平衡参数
typedef struct
{
    IVS_UINT32  uiWhiteBalanceMode; // 白平衡模式 0-自动；1-手动
    IVS_UINT32  uiCrGain;           // 红色增益
    IVS_UINT32  uiCbGain;           // 蓝色增益
    IVS_CHAR    cReserve[32];       // 保留字段
}IVS_WHITE_BALANCE;

// 防抖动参数
typedef struct
{
    IVS_UINT32	uiStabilizationMode;	// 防抖动模式 0-关闭；1-打开；2-自动；3-扩展
    IVS_UINT32	uiStabilizationLevel;   // 防抖动等级
    IVS_CHAR    cReserve[32];           // 保留字段
}IVS_STABILIZATION;

// 摄像机图像参数
typedef struct
{
    IVS_BACKLIGHT       stBacklight;        // 背光
    IVS_EXPOSURE        stExposure;         // 曝光
    IVS_FOCUS           stFocus;            // 变焦
    IVS_WIDE_DYNAMIC    stWideDynamic;      // 宽动态
    IVS_WHITE_BALANCE   stWhiteBalance;     // 白平衡
    IVS_STABILIZATION   stStabilization;    // 防抖动
    IVS_UINT32          uiIrCutFilter;      // 红外过滤 0-关闭；1-打开；2-自动
    IVS_UINT32          uiSharpness;        // 锐度
    IVS_CHAR            cReserve[32];       // 保留字段
}IVS_CAMERA_IMAGING_CFG;

// 前端OSD时间
typedef struct
{
    IVS_BOOL	bEnableOSDTime;     // 是否显示时间：0-不显示，1-显示
    IVS_UINT32	uiTimeFormat;       // 时间显示格式：？1: XXXX-XX-XX XX:XX:XX(如2009-09-09 09:09:09), 2: XXXX年XX月XX日 XX :XX :XX(2009年09月09日 09 :09 :09；3: UTC时间
    IVS_FLOAT   fTimeX;             // 时间X坐标，以左上角为原点
    IVS_FLOAT   fTimeY;             // 时间Y坐标，以左上角为原点
    IVS_CHAR    cReserve[32];       // 保留字段
}IVS_OSD_TIME;

// 前端OSD文字
#define IVS_MAX_OSD_TEXT_LEN	256 // OSD文字最大长字节数
typedef struct
{
    IVS_BOOL	bEnableOSDName;                     // 是否显示文字：0-不显示，1-显示
    IVS_CHAR	cOSDNameText[IVS_MAX_OSD_TEXT_LEN]; // 文字内容
    IVS_RECT_FLOAT    rectText;                     // 文字区域

    IVS_BOOL	bEnableSwitch;		                // 是否交替显示：0-不交替，1-交替
    IVS_UINT32	uiSwitchInterval;                   // 交替显示时间间隔，单位为秒

    IVS_BOOL	bEnableTextBlink;		            // 是否允许闪烁：0-不闪烁，1-闪烁
    IVS_BOOL	bEnableTextTranslucent;	            // 是否允许透明：0-不透明，1-透明
    IVS_UINT32	uiTextTranslucentPercent;           // 文字透明度：0-100

    IVS_CHAR	cReserve[64];
}IVS_OSD_NAME;

// 摄像机OSD参数
typedef struct
{
    IVS_BOOL        bEnableOSD; // 是否启用：0-停用 1-启用
    IVS_OSD_TIME    stOSDTime;  // OSD时间信息
    IVS_OSD_NAME    stOSDName;  // OSD文字信息

    IVS_CHAR	cReserve[32];
}IVS_CAMERA_OSD_CFG;

// 摄像机多个OSD参数
#define IVS_MAX_OSD_TIME_MAX_NUM	8 // OSD时间信息最大个数
#define IVS_MAX_OSD_NAME_MAX_NUM	8 // OSD文字信息最大个数
typedef struct
{
    IVS_BOOL        bEnableOSD;                           // 是否启用：0-停用 1-启用
    IVS_UINT32	    uiOSDTimeNum;                         // OSD时间信息的个数
    IVS_UINT32	    uiOSDNameNum;                         // OSD文字信息的个数
    IVS_OSD_TIME    stOSDTime[IVS_MAX_OSD_TIME_MAX_NUM];  // OSD时间信息
    IVS_OSD_NAME    stOSDName[IVS_MAX_OSD_NAME_MAX_NUM];  // OSD文字信息

    IVS_CHAR	    cReserve[32];
}IVS_CAMERA_OSD_PARA_INFO;

// 运动检测
#define IVS_MAX_MOTION_DETECTION_AREA_NUM   8   // 运动检测区域个数
typedef struct
{
    IVS_BOOL    bMotionDetectionEnable;     // 设备运动检测告警使能 0-停用运动检测 1-启用运动检测
    IVS_BOOL    bPlatformMotionDetection;   // 平台运动检测告警使能 0-停用运动检测 1-启用运动检测

    IVS_UINT32  uiDetectInterval;       // 运动监测的时间间隔，在该间隔内的运动都作为同一个运动，取值范围：1~30秒 单位:秒 默认为：10秒
    IVS_UINT32  uiSensitivity;          // 运动监测的灵敏度，共分5级：1-5，数字越高表示灵敏度越高
    IVS_UINT32  uiAutoClearAlarmTime;   // 告警检测时间间隔1-255，单位：秒。默认为120秒，即每隔120秒检测一次是否在告警状态，并上报

    IVS_UINT32  uiRectNum;              // 有效区域信息的个数
    IVS_RECT_FLOAT    rectDetection[IVS_MAX_MOTION_DETECTION_AREA_NUM];   // 运动检测区域列表

    IVS_CHAR	cReserve[32];
}IVS_MOTION_DETECTION;

// 图像遮挡
#define IVS_MAX_VIDEO_HIDE_AREA_NUM 5   // 最大图像遮挡告警区域个数
#define IVS_MAX_VIDEO_HIDE_GUARD_TIME_NUM   12  // 最大视频遮挡布防时间段个数
typedef struct
{
    IVS_BOOL    bEnableVideoHide;       // 0-关闭视频遮挡告警，1-启用视频遮挡告警
    IVS_UINT32  uiSensitivity;          // 图像遮挡监测的灵敏度，共分5级：1-5，数字越高表示灵敏度越高
    IVS_UINT32  uiAutoClearAlarmTime;   // 告警检测时间间隔1-255，单位：秒。默认为120秒，即每隔120秒检测一次是否在告警状态，并上报

    IVS_UINT32  uiGuardTimeNum;                                         // 实际告警时间个数
    IVS_TIME_SPAN   stGuardTime[IVS_MAX_VIDEO_HIDE_GUARD_TIME_NUM];     // 视频遮挡布防时间段

    IVS_UINT32  uiAreaNum;                              // 实际设置的图像遮挡告警区域个数
    IVS_RECT_FLOAT    rectArea[IVS_MAX_VIDEO_HIDE_AREA_NUM];  // 图像遮挡告警区域数组

    IVS_CHAR	cReserve[32];
}IVS_VIDEO_HIDE_ALARM;

// 隐私保护
#define IVS_MAX_VIDEO_MASK_AREA_NUM 10   // 最大隐私保护区域个数
typedef struct
{
    IVS_BOOL    bEnableVideoMask;       // 0-关闭隐私保护，1-启用隐私保护

    IVS_UINT32  uiAreaNum;                              // 实际设置的图像遮挡告警区域个数
    IVS_RECT_FLOAT    rectArea[IVS_MAX_VIDEO_MASK_AREA_NUM];  // 图像遮挡告警区域数组

    IVS_CHAR	cReserve[32];
}IVS_VIDEO_MASK;

//音频有无检测
typedef struct
{
    IVS_BOOL   bEnableAudioCut;             //使能
    IVS_UINT32 uiSensitivity;               //异常检测灵敏度0~2，数字越高越灵敏
    IVS_UINT32 uiThreshold;                 //阈值
    IVS_CHAR   cReserve[32];
}IVS_AUDIO_CUT_PARA;

//音频陡降
typedef struct
{
    IVS_BOOL   bEnableAudioDown;            //使能
    IVS_UINT32 uiSensitivity;               //异常检测灵敏度0~2，数字越高越灵敏
    IVS_UINT32 uiThreshold;                 //阈值
    IVS_CHAR   cReserve[32];
}IVS_AUDIO_DOWN_PARA;

//音频陡升
typedef struct
{
    IVS_BOOL   bEnableAudioUp;              //使能
    IVS_UINT32 uiSensitivity;               //异常检测灵敏度0~2，数字越高越灵敏
    IVS_UINT32 uiThreshold;                 //阈值
    IVS_CHAR   cReserve[32];
}IVS_AUDIO_UP_PARA;

// 音频检测告警参数
typedef struct
{
    IVS_CHAR   cAudioCode[IVS_DEV_CODE_LEN];  //语音通道编码长度
    IVS_AUDIO_CUT_PARA  stAudioCut;           //音频有无检测
    IVS_AUDIO_DOWN_PARA stAudioDown;          //音频陡降
    IVS_AUDIO_UP_PARA   stAudioUp;            //音频陡升
    IVS_CHAR            cReserve[32];
}IVS_AUDIO_DETECTION_PARA;

// 告警输入子设备
#define IVS_ALARM_IN_NAME_LEN   260      // 告警输入子设备名称长度
typedef struct
{
    IVS_CHAR    cAlarmInName[IVS_ALARM_IN_NAME_LEN];    // 告警输入设备名称，汉字和字母（a-z和A-Z），数字，中划线和下划线，1~20个字符。
    IVS_UINT32  uiAlarmInChanIndex;                     // 告警输入通道索引
    IVS_UINT32  uiSwitchType;                           // 设备开关类型 0-常闭 1-常开
    IVS_UINT32  uiAutoClearAlarmTime;                   // 告警检测时间间隔1-255，单位：秒。默认为120秒，即每隔120秒检测一次是否在告警状态，并上报，数字。

    IVS_CHAR	cReserve[32];
}IVS_ALARM_IN_CFG;

// 告警输出子设备
#define IVS_ALARM_OUT_NAME_LEN   128      // 告警输出子设备名称长度
typedef struct
{
    IVS_CHAR    cAlarmOutName[IVS_ALARM_OUT_NAME_LEN];  // 告警输出设备名称，汉字和字母（a-z和A-Z），数字，中划线和下划线，1~20个字符。
    IVS_UINT32  uiAlarmOutChanIndex;                    // 告警输出通道索引
    IVS_UINT32  uiSwitchType;                           // 设备开关类型 0-常闭 1-常开
    IVS_UINT32  uiAlarmOutMode;                         // 告警输出模式：0-单稳态，1-双稳态
    IVS_UINT32  uiHoldTime;                             // 延迟时间，1秒~600秒；默认：10秒（单稳态时有效）

    IVS_CHAR	cReserve[32];
}IVS_ALARM_OUT_CFG;

typedef struct
{
    IVS_UINT32  uiPitch;        // 定调
    IVS_UINT32  uiVolume;       // 声道
    IVS_UINT32  uiInputType;    // 输入类型
    IVS_UINT32  uiDataFormat;   // 数据格式，参考 IVS_PAYLOAD_TYPE
    IVS_UINT32  uiSampleRate;   // 采样率
    IVS_UINT32  uiChannel;      // 频道
    IVS_UINT32  uiGain;         // 增益
    IVS_UINT32  uiSampleBits;   // 比特率

    IVS_CHAR	cReserve[32];
}IVS_AUDIO_PARAM;

// 音频子设备参数
#define IVS_AUDIO_NAME_LEN   128      // 音频子设备名称长度
typedef struct
{
    IVS_CHAR    cAudioName[IVS_AUDIO_NAME_LEN];     // 语音通道名称，汉字和字母（a-z和A-Z），数字，中划线和下划线，1~20个字符。
    IVS_UINT32  uiChannelType;                      // 通道类型 0-语音输入 1-语音输出
    IVS_UINT32  uiAudioIndex;                       // 语音通道索引，正整数。

    IVS_AUDIO_PARAM stAudioParam;                   // 音频参数

    IVS_CHAR	cReserve[32];
}IVS_AUDIO_CFG;

// 语音设备信息
typedef struct
{
    IVS_CHAR	cDevGroupCode[IVS_DEVICE_GROUP_LEN];           // 设备组编码
    IVS_CHAR    cAudioCode[IVS_DEV_CODE_LEN];       // 语音通道编码长度
    IVS_CHAR	cDomainCode[IVS_DOMAIN_CODE_LEN];	// 所属域编码
    IVS_CHAR    cAudioName[IVS_AUDIO_NAME_LEN];     // 语音通道名称，汉字和字母（a-z和A-Z），数字，中划线和下划线，1~20个字符。
    IVS_UINT32  uiChannelType;                      // 通道类型 0-语音输入 1-语音输出

    IVS_UINT32  uiDeleteStatus;                      // 设备删除状态 0-软删除设备，待彻底删除 1-设备正常
    IVS_CHAR    cReserve[28];
}IVS_AUDIO_BRIEF_INFO;

// 语音设备列表信息
typedef struct
{
    IVS_UINT32   uiTotal;           // 总记录数
    IVS_INDEX_RANGE stIndexRange;   // 分页信息
    IVS_CHAR cRes[32];              //保留字段
    IVS_AUDIO_BRIEF_INFO stAudioBriefInfo[1];  // 语音设备列表信息
}IVS_AUDIO_BRIEF_INFO_LIST;

// 告警设备信息
#define IVS_AUDIO_CODE_LEN  64      // 语音通道编码长度
typedef struct
{
    //IVS_UINT32	uiDevGroupID;                       // 设备组ID
    IVS_CHAR	cDevGroupCode[IVS_DEVICE_GROUP_LEN];// 所属设备组编码
    IVS_CHAR    cAlarmCode[IVS_DEV_CODE_LEN];       // 告警设备编码
    IVS_CHAR	cDomainCode[IVS_DOMAIN_CODE_LEN];	// 所属域编码
    IVS_CHAR    cAlarmName[IVS_ALARM_IN_NAME_LEN];  // 语音通道名称，汉字和字母（a-z和A-Z），数字，中划线和下划线，1~20个字符。
    IVS_UINT32  uiChannelType;                      // 通道类型 0-告警输入 1-告警输出
    IVS_CHAR    cParentCode[IVS_DEV_CODE_LEN];      // 主设备编码
    IVS_BOOL	bIsExDomain;                        // 是否为外部域 0-否  1-是

    IVS_UINT32  uiDeleteStatus;                      // 设备删除状态 0-软删除设备，待彻底删除 1-设备正常
    IVS_CHAR    cReserve[28];
}IVS_ALARM_BRIEF_INFO;

// 告警设备列表信息
typedef struct
{
    IVS_UINT32   uiTotal;           // 总记录数
    IVS_INDEX_RANGE stIndexRange;   // 分页信息
    IVS_CHAR cRes[32];              //保留字段
    IVS_ALARM_BRIEF_INFO stAlarmBriefInfo[1];  // 语音设备列表信息
}IVS_ALARM_BRIEF_INFO_LIST;

//外域设备信息
typedef struct
{
    IVS_CHAR	cDevCode[IVS_DEV_CODE_LEN];                  // 设备id
    IVS_CHAR	cDomainCode[IVS_DOMAIN_CODE_LEN];        // 所属域编码
    IVS_CHAR	cDevName[IVS_DEVICE_NAME_LEN];            // 设备名称
    IVS_UINT32  uiExpiration;
    IVS_UINT32  uiHeartBeatInterval;
    IVS_UINT32  uiHeartBeatCount;
    IVS_UINT32  uiPositionCapability;
    IVS_DOUBLE  dLongitude;
    IVS_DOUBLE  dLatitude;

    IVS_CHAR	cReserve[32];
}IVS_EXTERNAL_DEVICE_CFG;

typedef enum
{
    CONFIG_DEVICE_CFG=1,                    // 主设备基本参数 IVS_DEVICE_CFG
    CONFIG_DEVICE_NET_CFG,                  // 主设备网络参数 IVS_DEVICE_NET_CFG
    CONFIG_DEVICE_TIME_CFG,                 // 主设备时间参数（NTP、时区）IVS_DEVICE_TIME_CFG

    CONFIG_CAMERA_CFG,                      // 摄像机基本参数设置 IVS_CAMERA_CFG
    CONFIG_CAMERA_STREAM_CFG,               // 摄像机码流参数设置 IVS_CAMERA_STREAM_CFG
    CONFIG_CAMERA_DISPLAY_CFG,              // 摄像机基本显示参数设置 IVS_CAMERA_DISPLAY_CFG
    CONFIG_CAMERA_IMAGING_CFG,              // 摄像机图像参数设置 IVS_CAMERA_IMAGING_CFG
    CONFIG_CAMERA_OSD_CFG,                  // 摄像机OSD参数设置 IVS_CAMERA_OSD_CFG
    CONFIG_CAMERA_MOTION_DETECTION_CFG,     // 摄像机运动检测参数设置 IVS_MOTION_DETECTION
    CONFIG_CAMERA_VIDEO_HIDE_ALARM_CFG,     // 摄像机遮挡告警参数设置 IVS_VIDEO_HIDE_ALARM
    CONFIG_CAMERA_VIDEO_MASK_CFG,           // 摄像机隐私保护参数设置 IVS_VIDEO_MASK
    CONFIG_CAMERA_AUDIO_CFG,                // 摄像机音频参数设置 IVS_AUDIO_CFG

    CONFIG_SERIAL_CHANNEL_CFG,              // 摄像机串口参数设置 IVS_SERIAL_CHANNEL_CFG
    CONFIG_ALARM_IN_CFG,                    // 告警输入子设备设置 IVS_ALARM_IN_CFG
    CONFIG_ALARM_OUT_CFG,                   // 告警输出子设备设置 IVS_ALARM_OUT_CFG

    CONFIG_DEVICE_PTZ_CFG,                  // 云台参数设置 IVS_PTZ_CFG
    CONFIG_CAMERA_EXTEND_CFG,               // 摄像机扩展参数设置 IVS_CAMERA_EXTEND_CFG

    CONFIG_CAMERA_SNAPSHOT_CFG,             // 摄像机抓拍参数设置 IVS_CAMERA_SNAPSHOT_CFG
    CONFIG_CAMERA_RECORD_STREAM_CFG,        // 摄像机前端录像码流设置 IVS_CAMERA_RECORD_STREAM_CFG
    CONFIG_CAMERA_FEC_CFG,                  // 摄像机FEC参数 IVS_CAMERA_FEC_CFG
    CONFIG_CAMERA_MULTY_OSD_CFG,            // 摄像机多行OSD参数设置IVS_CAMERA_OSD_PARA_INFO
    CONFIG_CAMERA_AUDIO_DETECTION_CFG,       // 摄像机音频检测告警参数
    CONFIG_DEVICE_UNIFIEDACCESSCODE_CFG,    // 主设备统一编码信息
    CONFIG_CAMERA_VIDEO_TRAPEZIFORM_MASK_CFG,  ///摄像机不规则多边形隐私设置////
   
    CONFIG_EXTERNAL_DEVICE_CFG,      //外域设备基本参数 IVS_EXTERNAL_DEVICE_CFG

    CONFIG_DEVICE_CFG_V2,            //设置查询主设备新增互联编码IVS_DEVICE_CFG_V2
    CONFIG_CAMERA_CFG_V2,            // 摄像机基本参数设置 IVS_CAMERA_CFG_V2
}IVS_CONFIG_TYPE;

typedef enum
{
    DEVICE_ENCODE_CAPABILITY=1,             // 摄像机码流参数
}IVS_DEVICE_CAPABILITY_TYPE;

// 摄像机接入协议
typedef enum
{
    DEVICE_PRO_TEYES = 0,	// 千里眼
    DEVICE_PRO_ONVIF,		// ONVIF
    DEVICE_PRO_HUAWEI,		// 华为SDK
    DEVICE_PRO_HIK,			// 海康SDK
    DEVICE_PRO_T28181,		// T28181
    DEVICE_PRO_DHSDK,		// DHSDK
    DEVICE_PRO_GB35114      // GB35114
}IVS_DEVICE_PROTOCOL;

// 集群信息
#define IVS_MAX_CLUSTER_MEMBER_NUM 16  // 集群最大数目
typedef struct
{
    IVS_CHAR cClusterName[IVS_NAME_LEN];           // 集群名称
    IVS_CHAR cClusterCode[IVS_CLUSTER_CODE_LEN];   // 集群编码
    IVS_CHAR cDomainCode[IVS_DOMAIN_CODE_LEN];
    IVS_CHAR cProductType[IVS_CLUSTER_CODE_LEN + 1];   // 产品类型
    IVS_UINT32	uiStatus;			               // 设备状态：0-离线，1-在线，2-休眠 参考 IVS_DEV_STATUS
	IVS_BOOL  bIsForward;	                        // 是否纯转发集群：0-不是, 1-是
    IVS_CHAR cReserve[28];                         // 保留字段
}IVS_CLUSTER_INFO;


// 集群信息列表
#define IVS_MAX_CLUSTER_NUM 64
typedef struct
{
    IVS_UINT32 uiTotal;
    IVS_CLUSTER_INFO stClusterInfo[IVS_MAX_CLUSTER_NUM];    // 集群信息列表
}IVS_CLUSTER_INFO_LIST;

// 查询主设备列表信息（NVR/TAS）（主设备 DVR/DVS/IPC）
typedef struct
{
    IVS_DEVICE_BASIC_INFO	stDeviceInfo;	// 主设备基本信息

    IVS_CHAR	cProtocolType[IVS_MAX_PROTOCOLTYPE_NAME_LEN];		// 主设备协议类型: "TEYES"-千里眼   "ONVIF"  "HWSDK"-华为SDK "HIKSDK"-海康SDK

    IVS_UINT32	iLoginType;			// 认证类型：参考 IVS_LOGINTYPE 驱动为ONVIF时认证类型可设置，认证类型有三种（0:None、1:HTTP Digest、2:WS-Usernametoken Authentication）

    IVS_BOOL	bEnableSchedule;	// 是否启用集群调度：0-否, 1-是(NVR CODE 不为空)
    IVS_UINT32	uiStatus;			// 设备状态：0-离线，1-在线，2-休眠 参考 IVS_DEV_STATUS
	IVS_UINT32	RegisterErr;        ///返回的设备操作的错误码///
    IVS_UINT32  uiDeleteStatus;                      // 设备删除状态 0-软删除设备，待彻底删除 1-设备正常
    IVS_CHAR    cReserve[24];
}IVS_DEVICE_BRIEF_INFO;

typedef struct
{
    IVS_UINT32   uiTotal;           // 总记录数
    IVS_INDEX_RANGE stIndexRange;   // 分页信息
    IVS_CHAR cRes[32];              //保留字段
    IVS_DEVICE_BRIEF_INFO stDeviceBriefInfo[1];  // 主设备列表信息
}IVS_DEVICE_BRIEF_INFO_LIST;

// 主设备详细信息（DVR/DVS/IPC）
typedef struct
{
    IVS_DEVICE_CFG	stDeviceCfg;            // 主设备参数
    IVS_DEVICE_EXCFG	stDeviceExCfg;	    // 主设备扩展参数
    IVS_DEVICE_NET_CFG	stDeviceNetCfg;	    // 主设备网络参数
    IVS_DEVICE_CHANNEL_CFG	stChannelInfo;	// 通道数配置
    IVS_DEVICE_TIME_CFG	stTimeInfo;	        // 时间参数（NTP、时区）

    IVS_UINT32	uiStatus;			        // 设备状态：0-离线，1-在线，2-休眠 参考 IVS_DEV_STATUS

    IVS_CHAR	cReserve[32];
}IVS_DEVICE_INFO;

#define IVS_MAX_DEV_GROUP_NUM   5000    // 最大设备组数目
#define IVS_MAX_EX_DEV_GROUP_NUM   5000    // 外域最大设备组数目
#define IVS_MAX_EX_DOMAIN_NUM   128    // 外域最大连接个数

typedef struct
{
    IVS_CHAR	cGroupCode[IVS_DEVICE_GROUP_LEN];           // 设备组编码
    IVS_CHAR	cGroupName[IVS_NAME_LEN];	                // 设备组名称
    //IVS_UINT32	uiParentGroupID;                    // 父设备组ID
    IVS_CHAR	cParentGroupCode[IVS_DEVICE_GROUP_LEN];     // 父设备组编码
    IVS_CHAR	cDomainCode[IVS_DOMAIN_CODE_LEN];	        // 域编码
    IVS_BOOL	bIsExDomain;	                            // 是否外部域设备/组   0：否，1：是
    IVS_CHAR	cReserve[32];
}IVS_DEVICE_GROUP;

//根据域编码查询设备组专用结构体
typedef struct
{
	IVS_CHAR cGroupCode[IVS_DEVICE_GROUP_LEN];
	IVS_CHAR	cDomainCode[IVS_DOMAIN_CODE_LEN];	        // 本域编码
	IVS_CHAR	cExDomainCode[IVS_DOMAIN_CODE_LEN];	        // 外域编码
	IVS_BOOL	bIsExDomain;	                            // 是否查询外域设备组   0：否，1：是
}IVS_DEVICE_GROUP_QUERY;

// 设备组列表
typedef struct
{
    IVS_UINT32          uiTotal;				// 总记录数
    IVS_INDEX_RANGE     stIndexRange;			// 分页信息
    IVS_DEVICE_GROUP    stDeviceGroup[1];		// 用户设备组信息列表
}IVS_DEVICE_GROUP_LIST;

// 设备组列表
typedef struct
{
    IVS_UINT32   uiTotal;				// 总记录数
    IVS_INDEX_RANGE stIndexRange;       // 分页信息
    IVS_DEVICE_GROUP stDeviceGroup[1];		// 用户设备组信息列表
}IVS_DEV_GROUP_LIST;

//根据域编码查询设备组在线设备个数结构体
typedef struct
{
	IVS_CHAR	cDomainCode[IVS_DOMAIN_CODE_LEN];	        // 本域编码
	IVS_CHAR	cExDomainCode[IVS_DOMAIN_CODE_LEN];	        // 外域编码
	IVS_BOOL	bIsExDomain;	                            // 是否查询外域设备组   0：否，1：是
}IVS_DEVICE_GROUP_NUM_QUERY;

//设备组在线/总数信息
typedef struct
{
    IVS_CHAR	cGroupCode[IVS_DEVICE_GROUP_LEN];              // 设备组编码
    IVS_UINT32  uiIPCOnlineNum;                                // 普通IPC在线数
    IVS_UINT32  uiIPCTotalNum;                                 // 普通IPC总数
    IVS_UINT32  uiShadowIPCOnlineNum;                          // 影子IPC在线数
    IVS_UINT32  uiShadowIPCTotalNum;                           // 影子IPC总数
    IVS_CHAR	cReserve[128];
}IVS_DEVICE_GROUP_NUM;

// 设备组在线列表信息
typedef struct
{
    IVS_UINT32          uiTotal;				                // 总记录数
    IVS_INDEX_RANGE     stIndexRange;			                // 分页信息,预留
    IVS_CHAR	        cReserve[64];
    IVS_DEVICE_GROUP_NUM    stDeviceGroupNumList[1];		    // 用户设备组设备个数信息列表
}IVS_DEVICE_GROUP_NUM_LIST;

// 设备组摄像头信息(组操作使用)
typedef struct
{
    IVS_CHAR	cCameraCode[IVS_DEV_CODE_LEN];          // 摄像头编码
    IVS_CHAR	cCameraDomainCode[IVS_DOMAIN_CODE_LEN];    // 摄像头所属域编码
    IVS_CHAR	cDevGroupCode[IVS_DEVICE_GROUP_LEN];           // 摄像头所属设备组编码
//	IVS_CHAR	cDevGroupDomainCode[IVS_DOMAIN_CODE_LEN];	// 设备组所属域编码
    IVS_CHAR	cReserve[64];
}IVS_DEV_GROUP_CAMERA;

// 设备组
typedef struct
{
    IVS_UINT32   uiTotal;				// 总记录数
    IVS_INDEX_RANGE stIndexRange;			// 分页信息
    IVS_DEV_GROUP_CAMERA stDevGroupCamera[1];		// 设备组摄像头信息列表
}IVS_DEV_GROUP_CAMERA_LIST;

// 组播信息
typedef struct
{
    IVS_IP		stIP;	// 组播IP地址
    IVS_UINT32	uiPort;	// 组播端口
    IVS_UINT32	uiTTL;  // (Time To Live ) 生存时间
    IVS_CHAR	cReserve[32];
}IVS_BROADCAST_INFO;

// 云台参数
typedef struct ST_PTZ_PARA
{
    IVS_UINT32  uiDecoderType;                          // 云台解码器类型
    IVS_UINT32  uiDecoderAddress;                       // 云台解码器地址(1,2...) ，最大长度4，正整数
    IVS_BOOL    bPosNegDirectControl;                   // 正反向控制，取值范围：0-正向 1-反向
    IVS_CHAR    cSerialCode[IVS_DEV_SERIALNO_LEN];      // 串口编码

    IVS_CHAR	cReserve[32];
}IVS_PTZ_CFG;

// 云台控制返回信息结构体
typedef struct
{
    IVS_UINT32  uiLockStatus;              // 云台锁定状态：0-解锁，1-锁定
    IVS_UINT32	uiUserID;			       // 用户ID
    IVS_CHAR	cUserName[IVS_NAME_LEN];   // 用户登录账号
    IVS_IP	    stIP;			           // 登录的客户端IP
    IVS_UINT32  uiReleaseTimeRemain;       // 释放时长，以秒为单位
    IVS_CHAR	cReserve[32];
}IVS_PTZ_CONTROL_INFO;

typedef enum
{
    IMAGING_QUALITY_HIGH=0,     // 图像质量高，默认值
    IMAGING_QUALITY_MIDDLE=1,   // 图像质量中
    IMAGING_QUALITY_LOW=2,      // 图像质量低
}IVS_IMAGING_QUALITY;

// 分辨率
#define IVS_RESOLUTION_LEN  	16	// 分辨率字符串长度

// 视频流信息
typedef struct
{
    IVS_UINT32	uiStreamType;	    // 码流类型：参考 IVS_STREAM_TYPE
    IVS_UINT32	uiEncodeType;	    // 编码格式：参考 IVS_VIDEO_DEC_TYPE
    IVS_UINT32	uiProfile;          // 根据uiEncodeType确定，如果是H.264：参考IVS_H264_PROFILE；如果是MJPEG：参考IVS_MJPEG_PROFILE
    IVS_UINT32	uiFrameInterval;	// I帧间隔
    IVS_CHAR	cResolution[IVS_RESOLUTION_LEN];    // 分辨率，如“177*144”

    IVS_UINT32	uiPicQuality;	    // 图像质量 （0-高 1-中 2-低） IVS_IMAGING_QUALITY

    IVS_UINT32	uiTransProtocol;    // 传输协议：参考 IVS_PROTOCOL_TYPE
    IVS_UINT32	uiPktProtocol;      // 打包协议：参考 IVS_PACK_PROTOCOL_TYPE
    IVS_UINT32	uiBitRateType;	    // 码率类型：参考 IVS_BITRATE_TYPE
    IVS_UINT32	uiBitRate;		    // 码率，单位(kbps)
    IVS_UINT32  uiFrameRate;		// 帧率，单位(fps)，范围1-60

    IVS_UINT32  uiEventRecordAdapt; //告警录像视频质量配置开关 0-关，1-开
    IVS_UINT32  uiEventBitRate;     //告警录像码率，单位(kbps)
    IVS_UINT32  uiEventFrameRate;   //告警录像帧率，单位(fps)，范围1-60
	IVS_INT32  iIntelligenceCode; //智能编码

    IVS_CHAR	cReserve[28];
}IVS_STREAM_INFO;

// 视频子设备配置参数

typedef struct
{
    IVS_UINT32	uiVideoChannel;	                // 视频输入通道号

    IVS_CHAR    cCameraCode[IVS_DEV_CODE_LEN];	// 设备编码
    IVS_CHAR    cCameraName[IVS_CAMERA_NAME_LEN];		// 摄像机名称

    IVS_CAMERA_POSITION	stPosition;	            // 摄像头位置信息

    IVS_BOOL	bSupportBroadcast;		        // 是否支持组播 0: 否 1:是
    IVS_BROADCAST_INFO	stBroadcast;	        // 组播信息

    IVS_BOOL	bEnableVoice;	                    // 随路音频是否启用	0-停用 1-启用
    IVS_CHAR    cVoiceOutCode[IVS_DEV_CODE_LEN];    // 摄像机绑定的音频输出通道，只能为同主设备上的音频输出通道。

    // 非用户修改信息
    IVS_CHAR    cParentCode[IVS_DEV_CODE_LEN];  // 主设备编码
    IVS_CHAR	cNvrCode[IVS_NVR_CODE_LEN];     // 设备所属NVR编码, 表示该设备被该NVR管理

    IVS_UINT32	uiCameraType;	                // 摄像机类型 IVS_CAMERA_TYPE
    IVS_UINT32	uiCameraStatus;		            // 摄像机扩展状态：1 – 正常	2 – 视频丢失
    IVS_UINT32	uiImgType;	            // 是否启用车牌分析或人脸检测
    //IVS_CHAR	cImgCode[IVS_IMG_CODE_LEN];	                    // 卡口编码
    IVS_BOOL	bIsAutoReported;	            // 是否自动上报
	IVS_INT32	iProtocolType;			//协议类型;
    IVS_CHAR	cReserve[23];
}IVS_CAMERA_CFG;

typedef struct
{
    IVS_UINT32	uiVideoChannel;	                // 视频输入通道号

    IVS_CHAR    cCameraCode[IVS_DEV_CODE_LEN];	// 设备编码
    IVS_CHAR    cConnectCode[IVS_DEV_CODE_LEN];	// 设备互联编码
    IVS_CHAR    cCameraName[IVS_CAMERA_NAME_LEN];		// 摄像机名称

    IVS_CAMERA_POSITION	stPosition;	            // 摄像头位置信息

    IVS_BOOL	bSupportBroadcast;		        // 是否支持组播 0: 否 1:是
    IVS_BROADCAST_INFO	stBroadcast;	        // 组播信息

    IVS_BOOL	bEnableVoice;	                    // 随路音频是否启用	0-停用 1-启用
    IVS_CHAR    cVoiceOutCode[IVS_DEV_CODE_LEN];    // 摄像机绑定的音频输出通道，只能为同主设备上的音频输出通道。

    // 非用户修改信息
    IVS_CHAR    cParentCode[IVS_DEV_CODE_LEN];  // 主设备编码
    IVS_CHAR	cNvrCode[IVS_NVR_CODE_LEN];     // 设备所属NVR编码, 表示该设备被该NVR管理

    IVS_UINT32	uiCameraType;	                // 摄像机类型 IVS_CAMERA_TYPE
    IVS_UINT32	uiCameraStatus;		            // 摄像机扩展状态：1 – 正常	2 – 视频丢失
    IVS_UINT32	uiImgType;	            // 是否启用车牌分析或人脸检测
    //IVS_CHAR	cImgCode[IVS_IMG_CODE_LEN];	                    // 卡口编码
    IVS_BOOL	bIsAutoReported;	            // 是否自动上报
	IVS_INT32	iProtocolType;			//协议类型;
    IVS_CHAR	cReserve[23];
}IVS_CAMERA_CFG_V2;

// 摄像机码流信息
typedef struct
{
    IVS_UINT32		uiStreamInfoNum;	// 有效视频流信息数目
    IVS_STREAM_INFO	stStreamInfo[IVS_MAX_STREAM_NUM];	// 视频流信息
    IVS_INT32      iVariableBitRate; //动态码率 
    IVS_INT32      iVariableFrameRate; //动态帧率，单位(fps)

    IVS_CHAR	cReserve[24];
}IVS_CAMERA_STREAM_CFG;


typedef enum
{
    CAMERA_FIX=0,       // 固定枪机
    CAMERA_PTZ,         // 有云台枪机
    CAMERA_DOME,        // 球机
    CAMERA_FIX_DOME,    // 半球-固定摄像机
    CAMERA_BULLET,
}IVS_CAMERA_TYPE;

// 串口类型
typedef enum
{
    SERIAL_RS232=0, // RS232
    SERIAL_RS485=1, // RS485
    SERIAL_RS422=2  // RS422
}IVS_SERIAL_TYPE;

// 校验类型
typedef enum
{
    PARITY_TYPE_NONE=0,     // 无校验
    PARITY_TYPE_ODD=1,      // 奇校验
    PARITY_TYPE_EVEN=2,     // 偶校验
    PARITY_TYPE_MARK=3,     // 标记校验
    PARITY_TYPE_SPACE=4,    // 空校验
}IVS_PARITY_TYPE;

// 流控类型
typedef enum
{
    FLOW_CONTROL_NONE=0,    // 无流控
    FLOW_CONTROL_SOFT=1,    // 软流控
    FLOW_CONTROL_HARD=2,    // 硬流控
}IVS_FLOW_CONTROL_TYPE;

// 串口子设备信息
#define IVS_SERIAL_NAME_LEN 128  // 串口设备名称长度
typedef struct
{
    IVS_CHAR cSerialName[IVS_SERIAL_NAME_LEN];  // 串口设备名称，汉字和字母（a-z和A-Z），数字，中划线和下划线，1~20个字符。
    IVS_UINT32  uiSerialIndex;                  // 串口索引
    IVS_UINT32  uiSerialType;                   // 串口类型，值参考 IVS_SERIAL_TYPE
    IVS_UINT32  uiBaudRate;                     // 波特率(bps) (50, 75, 110, 150, 300, 600, 1200, 2400, 4800, 9600, 19200 38400, 57600, 115200)
    IVS_UINT32  uiDataBit;                      // 数据位 （5、6、7、8）
    IVS_UINT32  uiParity;                       // 校验，值参考IVS_PARITY_TYPE（0－无校验，1－奇校验，2－偶校验，3: 标记校验，4:空校验）
    IVS_UINT32  uiStopBit;                      // 停止位 （1、2）
    IVS_UINT32  uiFlowControl;                  // 流控，值参考 IVS_FLOW_CONTROL_TYPE

    IVS_CHAR	cReserve[32];
}IVS_SERIAL_CHANNEL_CFG;

// 主设备子设备通道（查询）
#define IVS_MAX_DEVICE_CHANNEL_NUM  256   //  设备通道最大数目
#define IVS_MAX_DEVICE_CHANNEL_NUM_V2 512 //  设备通道最大数目扩展
#define IVS_CHANNEL_NAME_LEN  128 //  通道名称长度
typedef struct
{
    IVS_CHAR	cChannelCode[IVS_DEV_CODE_LEN];	// 子设备编码
    IVS_UINT32	uiChannelType;		            // 通道类型：参考 IVS_CHANNEL_TYPE
    IVS_CHAR	cChannelName[IVS_CHANNEL_NAME_LEN];	// 通道名称
    IVS_CHAR	cReserve[32];
    IVS_UINT32  uiChannelEnable;
}IVS_DEV_CHANNEL_BRIEF_INFO;

// 主设备子设备列表
typedef struct
{
    IVS_UINT32   uiTotal;				        // 总记录数
    IVS_INDEX_RANGE stIndexRange;			    // 分页信息
    IVS_DEV_CHANNEL_BRIEF_INFO stDevChannelBriefInfo[1];   // 主设备子设备列表
}IVS_DEV_CHANNEL_BRIEF_INFO_LIST;

// 用户绑定设备信息
typedef struct
{
//	IVS_UINT32	uiDevGroupID;                               // 设备组ID
    IVS_CHAR	cDevGroupCode[IVS_DEVICE_GROUP_LEN];        // 设备组编码
    IVS_CHAR	cDevGroupDomainCode[IVS_DOMAIN_CODE_LEN];	// 设备组域编码
    IVS_CHAR	cDevCode[IVS_DEV_CODE_LEN];	                // 设备编码
    IVS_CHAR	cDevDomainCode[IVS_DOMAIN_CODE_LEN];	    // 设备域编码
    IVS_BOOL	bIsExDomain;	                            // 是否外部域设备/组   0：否，1：是
    IVS_BOOL	bIsTotalGroup;	// 0：绑定的是设备组中的设备	1：绑定整个设备组（设备组扩容后自动更新组内设备），此时：DevCode、DomainCode、ChanelType为空

    IVS_CHAR	cReserve[64];
}IVS_USER_DEVICE_INFO;

// 用户绑定设备信息列表
typedef struct
{
    IVS_UINT32   uiTotal;				        // 总记录数
    IVS_INDEX_RANGE stIndexRange;			    // 分页信息
    IVS_INT32    iRequsetID;                    // 请求ID
    IVS_USER_DEVICE_INFO stUserDeviceInfo[1];   // 用户绑定设备信息列表
}IVS_USER_DEVICE_INFO_LIST;

// 用户绑定设备信息列表
typedef enum
{
    NET_TYPE_LAN = 0,   // 有线
    NET_TYPE_WAN = 1,   // 无线
}IVS_NET_TYPE;

// 视频子设备列表简要信息（查询视频子设备列表）
typedef struct
{
    IVS_CHAR	cCode[IVS_DEV_CODE_LEN];	    // 设备编码
    IVS_CHAR	cName[IVS_CAMERA_NAME_LEN];		// 摄像机名称

    IVS_CHAR	cDevGroupCode[IVS_DEVICE_GROUP_LEN];// 所属设备组编码
    IVS_CHAR	cParentCode[IVS_DEV_CODE_LEN];	    // 父设备编码
    IVS_CHAR	cDomainCode[IVS_DOMAIN_CODE_LEN];	// 域编码
    IVS_CHAR	cDevModelType[IVS_DEV_MODEL_LEN];	// 主设备型号
    IVS_CHAR	cProtocolType[IVS_MAX_PROTOCOLTYPE_NAME_LEN];	// 主设备协议类型: "TEYES"-千里眼,"ONVIF","HWSDK"-华为SDK,"HIKSDK"-海康SDK

    IVS_CHAR	cVendorType[IVS_MAX_VENDOR_TYPE_NAME_LEN];  // 设备提供商类型: "HUAWEI" "HIK" "DAHUA"
    IVS_UINT32	uiDevFormType;                              // 主设备类型：参考 IVS_MAIN_DEVICE_TYPE

    IVS_UINT32	uiType;								// 摄像机类型 IVS_CAMERA_TYPE
    IVS_CHAR	cCameraLocation[IVS_DESCRIBE_LEN];	// 摄像机安装位置描述
    IVS_UINT32	uiCameraStatus;		                // 摄像机扩展状态：1 – 正常	2 – 视频丢失

    IVS_UINT32	uiStatus;			                // 设备状态：0-离线，1-在线，2-休眠 参考 IVS_DEV_STATUS

    IVS_UINT32  uiNetType;                          // 网络类型 0-有线  1-无线, 参考 IVS_NET_TYPE
    IVS_BOOL    bSupportIntelligent;                // 是否支持智能分析  0-不支持 1-支持

    IVS_BOOL	bEnableVoice;		                // 随路音频是否启用	0-停用 1-启用
    IVS_CHAR	cNvrCode[IVS_NVR_CODE_LEN];	        // 设备所属NVR编码, 表示该设备被该NVR管理

    IVS_CHAR    cDevCreateTime[IVS_TIME_LEN];       // 设备创建时间
    IVS_BOOL	bIsExDomain;                        // 是否为外部域 0-否  1-是
    IVS_CHAR    cDevIp[IVS_IP_LEN];                 // 前端IP

    IVS_BOOL	bShadowDev;                                 // 是否影子IPC
    IVS_CHAR	cOrigDevCode[IVS_DEV_CODE_LEN+1];	        // 源设备编码
    IVS_CHAR	cOriDevDomainCode[IVS_DOMAIN_CODE_LEN+1];	// 源域编码
    IVS_CHAR    cOrigDevDomainType[16];                        // 源域类型

    IVS_CHAR   cLongitude[64];   // 安装经度
    IVS_CHAR   cLatitude[64];	// 安装纬度

    IVS_BOOL    bHaveAlarmLinkage;          // 是否设置告警联动计划

    IVS_UINT32  uiDeleteStatus;                      // 设备删除状态 0-软删除设备，待彻底删除 1-设备正常
    IVS_CHAR    cReserve[24];
}IVS_CAMERA_BRIEF_INFO;

// 视频子设备列表
typedef struct
{
    IVS_UINT32   uiTotal;           // 总记录数
    IVS_INDEX_RANGE stIndexRange;   // 分页信息
    IVS_CAMERA_BRIEF_INFO stCameraBriefInfo[1];
}IVS_CAMERA_BRIEF_INFO_LIST;

// 操作日志
typedef struct
{
    IVS_CHAR    cAccount[IVS_NAME_LEN];                 //操作员账号
    IVS_CHAR    cClientIp[IVS_IP_LEN];                  //客户端IP
    IVS_UINT32  iGrade;                                 //日志级别
    IVS_CHAR    cServiceCode[IVS_DESCRIBE_LEN];         //业务代码，IVS平台写"IVS"
    IVS_CHAR    cModuleType[IVS_DESCRIBE_LEN];          //模块类型,譬如"SMU","SCU"
    IVS_CHAR    cModuleCode[IVS_DEV_CODE_LEN];          //模块唯一代码，指当前模块对应的机器编号
    IVS_CHAR    cOperationCode[IVS_DEV_CODE_LEN];       //操作代码用来唯一标示一个操作
    IVS_CHAR    cOperationObjectCode[IVS_DESCRIBE_LEN]; //操作对象代码，用来标示本次操作实施的对象
    IVS_CHAR    cOccurTime[IVS_TIME_LEN];               //日志发生时间
    IVS_CHAR    cErrorCode[IVS_DESCRIBE_LEN];           //错误码
    IVS_UINT32  iResult;                                //操作结果
    IVS_CHAR    cAdditionalInfo[IVS_DESCRIBE_LEN];      //附加信息
    IVS_CHAR	cReserve[32];
}IVS_OPERATION_LOG_INFO;

// 操作日志列表
typedef struct
{
    IVS_UINT32   uiTotal;           // 总记录数
    IVS_INDEX_RANGE stIndexRange;   // 分页信息
    IVS_OPERATION_LOG_INFO stOperationInfo[1];
}IVS_OPERATION_LOG_LIST;

// 功能代码
typedef enum
{
    FUNC_LOGIN= 1,	// 登录
    FUNC_MAIN_UI,	// 主界面
    FUNC_GROUP_MANAGER,	// 组织管理
    // 待添加..<eSpace IVS V100R001C02 用户操作功能和代码列表.xlsx>
}IVS_FUNCTION_CODE;

/////////////////////////////////////////////////告警///////////////////////////////////////////
#define IVS_ALARM_DESCRIPTION_LEN 1024
#define IVS_ALARM_CODE_LEN		64
#define IVS_ALARM_NAME_LEN		260
#define IVS_NODE_TYPE_LEN       8

// 告警级别
#define IVS_MAX_ALARM_LEVEL_NUM	20	// 告警级别最大个数
typedef struct
{
    IVS_UINT32  uiAlarmLevelId;		// 告警级别ID

    IVS_CHAR    cName[IVS_NAME_LEN];	// 告警级别名称,汉字和字母（a-z和A-Z），数字，中划线和下划线，1~20个字符
    IVS_UINT32  uiValue;				// 告警级别权值,1~100
    IVS_CHAR    cColor[16];			    // 告警级别颜色,使用颜色字符串表示ARGB,例如#FFFF0000 表示红色，不透明
    IVS_CHAR    cDescription[IVS_ALARM_DESCRIPTION_LEN];	// 告警级别描述,键盘可见字符和中文，0~256个字符
    IVS_BOOL    bIsUserDefined;		    // 是否为用户自定义 0-否，表示“系统定义” 1-是

    IVS_CHAR	cReserver[32];
}IVS_ALARM_LEVEL;

// 告警类型
#define IVS_ALARM_TYPE_CATEGORY_LEN  8
typedef struct
{
    IVS_UINT32  uiID;                   // 告警ID
    IVS_CHAR cType[IVS_ALARM_CODE_LEN];	// 告警类型编码
    IVS_CHAR cName[IVS_ALARM_NAME_LEN];	// 告警类型名称，汉字和字母（a-z和A-Z），数字，中划线和下划线，1~64个字符

    IVS_UINT32	uiType;					// 告警源类型 IVS_ALARM_IN_TYPE
    IVS_CHAR cCategory[IVS_ALARM_TYPE_CATEGORY_LEN];				// 告警类型类别
/*
告警类型类别（支持四级类别）
01：业务类告警
0101：一般业务告警
0102：智能分析告警
010201：行为分析告警
010202：人脸识别告警
0103：第三方接入告警
02：设备类告警
0201：一般设备告警
0202：智能分析告警
*/
    IVS_BOOL    bIsUserDefined;		    // 是否为用户自定义 0-否，表示“系统定义” 1-是

    IVS_ALARM_LEVEL stAlarmLevel;	    // 告警级别ID

    IVS_BOOL    bEnable;                // 是否启用 0-否 1-是
    IVS_CHAR	cReserver[32];
}IVS_ALARM_TYPE;

// 告警类型分页查询列表
typedef struct
{
    IVS_UINT32   iTotal;                // 总记录数
    IVS_INDEX_RANGE stIndexRange;       // 分页信息
    IVS_CHAR cReserve[32];              //保留字段
    IVS_ALARM_TYPE stSubscribeInfo[1];  // 告警类型信息列表
}IVS_ALARM_TYPE_LIST;

typedef enum
{
    ALARM_IN_CAMERA=1,      // 摄像头
    ALARM_IN_DI=2,          // 开关量输入设备
    ALARM_IN_EXTERN_DI=9,   // 第三方开关量输入
}IVS_ALARM_IN_TYPE;

// 开关量输出设备
typedef struct
{
    IVS_CHAR cCode[IVS_ALARM_CODE_LEN];	// 开关量输出编码
    IVS_CHAR cName[IVS_ALARM_NAME_LEN]; // 开关量输出名称

    IVS_CHAR	cReserver[32];
}IVS_ALARM_OUT;

// 告警处理信息
typedef struct
{
    IVS_UINT32	uiOperatorID;	                // 处理人ID 参考 IVS_USER_INFO
    IVS_CHAR    cOperatorName[IVS_NAME_LEN];	// 处理人名
    IVS_CHAR    cOperateTime[IVS_TIME_LEN];		// 告警处理时间

    IVS_CHAR	cReserver[32];
    IVS_CHAR    cOperateInfo[IVS_ALARM_DESCRIPTION_LEN];	// 告警处理人员输入的信息
}IVS_ALARM_OPERATE_INFO;

// 告警状态
typedef enum
{
    ALARM_STATUS_NO_OPERATE=0,	// 未操作
    ALARM_STATUS_TOBE_CONFIRM,	// 待确认
    ALARM_STATUS_CONFIRMED,	    // 已确认
    ALARM_STATUS_CANCELED,	    // 已撤销
    ALARM_STATUS_RECOVERED,	    // 已恢复
}IVS_ALARM_STATUS;

// 告警源设备
typedef struct
{
    IVS_CHAR cAlarmInCode[IVS_ALARM_CODE_LEN];	// 告警源编码
    IVS_CHAR cAlarmInName[IVS_ALARM_NAME_LEN];  // 告警源名称
    IVS_UINT32	uiAlarmInType;					// 告警源类型 IVS_ALARM_IN_TYPE

    IVS_UINT32	uiDeviceType;	                // 参考 IVS_CAMERA_TYPE 设备类型（目前只有摄像机区分设备类型，其余设备留空）
    IVS_BOOL	bOnline;		                // 是否在线：1-在线	0-离线
    IVS_BOOL	bEnable;		                // 是否启用：1-启用	0-停用
    IVS_CAMERA_POSITION	stLocation;		        // 	设备安装位置，对于没有位置信息的显示为空

    IVS_CHAR	cReserver[32];
}IVS_ALARM_IN;

// 告警源设备列表
typedef struct
{
    IVS_UINT32   iTotal;            // 总记录数
    IVS_INDEX_RANGE stIndexRange;   // 分页信息
    IVS_CHAR cReserve[32];          //保留字段
    IVS_ALARM_IN stAlarmInInfo[1];  // 告警源设备列表
}IVS_ALARM_IN_LIST;

// 告警上报信息(客户端等模块上报平台)
#define IVS_ALARM_EX_PARAM_LEN  2048    // 告警上报扩展参数
#define IVS_ALARM_REPORT_ID_LEN 32      // 告警上报ID
#define IVS_ALARM_TYPE_LEN  64          // 告警类型长度
typedef struct
{
    // 告警源设备
    IVS_CHAR    cAlarmInCode[IVS_ALARM_CODE_LEN];	// 告警源编码
    IVS_CHAR	cDevDomainCode[IVS_DOMAIN_CODE_LEN];// 设备所属域编码
    IVS_CHAR    cAlarmType[IVS_ALARM_TYPE_LEN];		// 告警源类型 英文字符串
    IVS_CHAR    cOccurTime[IVS_TIME_LEN];           // 告警发生时间：yyyyMMddHHmmss
    IVS_CHAR    cReportTime[IVS_TIME_LEN];          // 告警上报时间：yyyyMMddHHmmss

    IVS_BOOL    bAction;                                // 0-告警消除 1-告警
    IVS_CHAR    cAlarmID[IVS_ALARM_REPORT_ID_LEN];      // 告警ID，“告警消除”与“告警”时的告警ID相同

    IVS_UINT32  uiOccurNumber;                          // 告警发生次数，默认值1
    IVS_CHAR    cNvrCode[IVS_NVR_CODE_LEN];             // NVR编码，可用于更新NVR路由

    IVS_CHAR    cReserve[32];                           // 保留字段
    IVS_CHAR    cAlarmDesc[IVS_ALARM_DESCRIPTION_LEN];  // 告警描述信息，键盘可见字符和中文，1024字节
    IVS_CHAR    cExtParam[IVS_ALARM_EX_PARAM_LEN];      // 扩展参数
}IVS_ALARM_REPORT;

#define IVS_ALARM_LEVEL_COLOR_LEN   16
#define IVS_ALARM_CATEGORY_LEN   8

// 业务告警通知信息(平台通知客户端)
typedef struct
{
    IVS_UINT64	ullAlarmEventID;                    // 告警事件ID
    IVS_CHAR    cAlarmInCode[IVS_ALARM_CODE_LEN];	// 告警源编码
    IVS_CHAR	cDevDomainCode[IVS_DOMAIN_CODE_LEN];// 设备所属域编码
    IVS_UINT32  uiAlarmInType;					    // 告警源类型 IVS_ALARM_IN_TYPE
    IVS_CHAR    cAlarmInName[IVS_ALARM_NAME_LEN];   // 告警源名称

    IVS_UINT32  uiAlarmLevelValue;		        // 告警级别权值,1~100
    IVS_CHAR    cAlarmLevelName[IVS_NAME_LEN];	// 告警级别名称,汉字和字母（a-z和A-Z），数字，中划线和下划线，1~20个字符
    IVS_CHAR    cAlarmLevelColor[IVS_ALARM_LEVEL_COLOR_LEN];			// 告警级别颜色,使用颜色字符串表示ARGB,例如#FFFF0000 表示红色，不透明

    IVS_CHAR    cAlarmType[IVS_ALARM_TYPE_LEN];	    // 告警类型
    IVS_CHAR    cAlarmTypeName[IVS_ALARM_NAME_LEN];	// 告警类型名称，汉字和字母（a-z和A-Z），数字，中划线和下划线，1~64个字符
    IVS_CHAR    cAlarmCategory[IVS_ALARM_CATEGORY_LEN];				// 告警类型类别

    IVS_CHAR    cOccurTime[IVS_TIME_LEN];       // 告警发生时间：yyyyMMddHHmmss
    IVS_UINT32 uiOccurNumber;		            // 告警发生次数
    IVS_UINT32  uiAlarmStatus;		            // 告警状态 参考 IVS_ALARM_STATUS

    IVS_BOOL	bIsCommission;	                // 是否为授权告警信息：0-否，1-是
    IVS_CHAR    cPreviewUrl[IVS_URL_LEN];	    // 在存在联动抓拍或者智能分析时的图片预览URL

    IVS_BOOL	bExistsRecord;	                // 是否存在告警录像：0-否，1-是
    IVS_CHAR    cNvrCode[IVS_NVR_CODE_LEN];     // NVR编码，可用于更新NVR路由

    IVS_CHAR	cReserver[32];                  // 保留字段
    IVS_CHAR    cAlarmDesc[IVS_ALARM_DESCRIPTION_LEN];	// 告警描述信息，键盘可见字符和中文，0~256字符。
    IVS_CHAR    cExtParam[IVS_ALARM_EX_PARAM_LEN];      // 扩展参数
}IVS_ALARM_NOTIFY;

// 告警信息（告警事件查询）
typedef struct
{
    IVS_ALARM_NOTIFY        stAlarmNotify;      // 告警信息
    IVS_ALARM_OPERATE_INFO	stOperateInfo;	    // 告警处理信息
}IVS_ALARM_EVENT;

// 告警信息状态通知
typedef struct
{
    IVS_UINT64	ullAlarmEventID;                        // 告警事件ID
    IVS_CHAR    cAlarmInCode[IVS_ALARM_CODE_LEN];	    // 告警源编码
    IVS_CHAR	cDevDomainCode[IVS_DOMAIN_CODE_LEN];    // 告警源域编码
    IVS_CHAR    cAlarmType[IVS_ALARM_TYPE_LEN];	        // 告警类型

    IVS_UINT32  uiOccurNumber;		            // 告警发生次数
    IVS_UINT32  uiAlarmStatus;		            // 告警状态 参考 IVS_ALARM_STATUS

    IVS_CHAR	cReserve[32];                   // 保留字段

    IVS_ALARM_OPERATE_INFO	stOperateInfo;	    // 告警处理信息
}IVS_ALARM_STATUS_NOTIFY;

// 告警上报信息分页查询列表
typedef struct
{
    IVS_UINT32   iTotal;                    // 总记录数
    IVS_INDEX_RANGE stIndexRange;           // 分页信息
    IVS_CHAR cReserve[32];                  //保留字段
    IVS_ALARM_EVENT stSubscribeInfo[1];    // 告警通知信息
}IVS_ALARM_EVENT_LIST;

// 设备告警通知信息(OMU告警通知信息)
#define IVS_DEVICE_ALARM_LOCATION_INFO_LEN  256
#define IVS_NET_ELEMENT_ID_LEN  32
typedef struct
{
    IVS_UINT64	ullAlarmEventID;                    // 告警事件ID
    IVS_CHAR    cAlarmInCode[IVS_ALARM_CODE_LEN];	// 告警源编码
    IVS_UINT32  uiAlarmInType;					    // 告警源类型 IVS_ALARM_IN_TYPE
    IVS_CHAR    cAlarmInName[IVS_ALARM_NAME_LEN];   // 告警源名称
    IVS_CHAR    cNodeType[IVS_NODE_TYPE_LEN];       // 告警所属网元类型,如30858

    IVS_UINT32  uiAlarmLevelValue;		        // 告警级别权值，只有四种：1-提示；50-一般；80-重要；100-紧急；

    IVS_CHAR    cAlarmType[IVS_ALARM_CODE_LEN];	// 告警类型
    IVS_CHAR    cAlarmCategory[IVS_ALARM_CATEGORY_LEN];				// 告警类型类别 01：业务类告警 02：网管类告警 03：状态类告警

    IVS_CHAR    cOccurFirstTime[IVS_TIME_LEN];     // 告警首次发生时间：yyyyMMddHHmmss（告警抑制的第一次告警产生时间）
    IVS_CHAR    cOccurEndTime[IVS_TIME_LEN];       // 告警最后发生时间：yyyyMMddHHmmss（告警抑制的最后一次告警产生时间）

    IVS_UINT32 uiOccurNumber;		            // 告警发生次数

    IVS_CHAR	cReserver[32];                  // 保留字段
    // 告警定位信息。定位信息字段有格式要求，需要是“以逗号分隔的键值对”的形式，譬如：ip=xxx.xxx.xxx.xxx,hostname=linux,...可以为空，不能有中文
    IVS_CHAR    cLocationInfo[IVS_DEVICE_ALARM_LOCATION_INFO_LEN];
    IVS_CHAR    cNetEleID[IVS_NET_ELEMENT_ID_LEN];      // 告警产生模块归属的网元ID

    IVS_CHAR    cNetName[IVS_NAME_LEN];                 // 所属网元名称
    IVS_CHAR    cAlarmDest[IVS_ALARM_DESCRIPTION_LEN];  // 告警描述信息，键盘可见字符和中文，0~256字符。
    IVS_CHAR    cExtParam[IVS_ALARM_EX_PARAM_LEN];      // 扩展参数
}IVS_DEVICE_ALARM_NOTIFY;

typedef struct
{
    IVS_UINT64	ullAlarmEventID;                    // 告警事件ID
    IVS_CHAR    cAlarmInCode[IVS_ALARM_CODE_LEN];	// 告警源编码
    IVS_UINT32  uiAlarmInType;					    // 告警源类型 IVS_ALARM_IN_TYPE
    IVS_CHAR    cAlarmInName[IVS_ALARM_NAME_LEN];   // 告警源名称
    IVS_CHAR    cNodeType[IVS_NODE_TYPE_LEN];       // 告警所属网元类型,如30858

    IVS_UINT32  uiAlarmLevelValue;		        // 告警级别权值，只有四种：1-提示；50-一般；80-重要；100-紧急；

    IVS_CHAR    cAlarmType[IVS_ALARM_CODE_LEN];	// 告警类型
    IVS_CHAR    cAlarmCategory[IVS_ALARM_CATEGORY_LEN];				// 告警类型类别 01：业务类告警 02：网管类告警 03：状态类告警

    IVS_CHAR    cOccurFirstTime[IVS_TIME_LEN];     // 告警首次发生时间：yyyyMMddHHmmss（告警抑制的第一次告警产生时间）
    IVS_CHAR    cOccurEndTime[IVS_TIME_LEN];       // 告警最后发生时间：yyyyMMddHHmmss（告警抑制的最后一次告警产生时间）

    IVS_UINT32 uiOccurNumber;		            // 告警发生次数

    IVS_CHAR	cReserver[32];                  // 保留字段
    // 告警定位信息。定位信息字段有格式要求，需要是“以逗号分隔的键值对”的形式，譬如：ip=10.137.97.123,hostname=linux,...可以为空，不能有中文
    IVS_CHAR    cLocationInfo[IVS_DEVICE_ALARM_LOCATION_INFO_LEN];
    IVS_CHAR    cNetEleID[IVS_NET_ELEMENT_ID_LEN];      // 告警产生模块归属的网元ID

    IVS_CHAR    cNetName[IVS_NAME_LEN];                 // 所属网元名称
    IVS_CHAR    cAlarmDest[IVS_ALARM_DESCRIPTION_LEN];  // 告警描述信息，键盘可见字符和中文，0~256字符。
    IVS_CHAR    cExtParam[IVS_ALARM_EX_PARAM_LEN];      // 扩展参数

    IVS_CHAR    OperLoginName[IVS_NAME_LEN];          //编辑用户登录名
    IVS_CHAR    OperTime[IVS_TIME_LEN];             //编辑操作时间
    IVS_CHAR    OperInfo[IVS_DESCRIBE_LEN];    //编辑内容

}IVS_DEVICE_ALARM_NOTIFY_REQ;

// 设备告警信息分页查询列表
typedef struct
{
    IVS_UINT32   iTotal;                    // 总记录数
    IVS_INDEX_RANGE stIndexRange;           // 分页信息
    IVS_CHAR cReserve[32];                  //保留字段
    IVS_DEVICE_ALARM_NOTIFY stDeviceAlarmNotify[1];    // 告警通知信息
}IVS_DEVICE_ALARM_EVENT_LIST;

// 设备告警信息分页查询列表
typedef struct
{
    IVS_UINT32   iTotal;                    // 总记录数
    IVS_INDEX_RANGE stIndexRange;           // 分页信息
    IVS_CHAR cReserve[32];                  //保留字段
    IVS_DEVICE_ALARM_NOTIFY_REQ stDeviceAlarmNotify[1];    // 告警通知信息
}IVS_DEVICE_ALARM_EVENT_LIST_REQ;

// 用户ID信息
typedef struct
{
    IVS_UINT32	uiUserID;	                        // 被授权用户ID
    IVS_CHAR	cDomainCode[IVS_DOMAIN_CODE_LEN];	// 用户所属域编码
}IVS_USER_ID_INFO;

// 告警授权
typedef struct
{
    IVS_UINT64	ullAlarmEventID;	// 告警事件ID
    IVS_UINT32  uiUserNum;          // 被授权用户数
    IVS_USER_ID_INFO    stUserInfo[1];  // 被授权用户ID列表
}IVS_ALARM_COMMISSION;

// 订阅者类型
typedef enum
{
    SUBSCRIBER_TYPE_USER= 1,	// 用户订阅
    SUBSCRIBER_TYPE_DOMAIN= 2,	// 外域向本域订阅
}IVS_SUBSCRIBE_USER_TYPE;

// 告警订阅者信息
typedef struct
{
    IVS_UINT32	uiSubscriberType;	// 订阅者类型：参考 IVS_SUBSCRIBE_USER_TYPE
    IVS_UINT32	uiSubscriberId;		// 订阅者ID（用户ID/域ID）

    IVS_CHAR	cReserve[32];
}IVS_ALARM_SUBSCRIBER;

// 订阅方式
typedef enum
{
    SUBSCRIBE_ALL= 1,       // 所有
    SUBSCRIBE_BY_TYPE= 2,   // 按告警类型
    SUBSCRIBE_BY_LEVEL= 3,  // 按告警级别
}IVS_SUBSCRIBE_TYPE;

// 告警订阅信息（一个用户可以订阅多个告警源，每个告警源可以订阅多个告警类型）
#define IVS_MAX_ALARM_TYPE_NUM  32  // 最大告警类型个数
typedef struct
{
    IVS_CHAR cCode[IVS_ALARM_CODE_LEN];	// 告警源编码
    IVS_UINT32	uiSubscribeType;        // 订阅方式：参考 IVS_SUBSCRIBE_TYPE
    IVS_UINT32	uiAlarmLevelValueMin;	// 告警级别下限值，订阅方式为“3-按告警级别”必须，可以为空
    IVS_UINT32	uiAlarmLevelValueMax;	// 告警级别上限值，订阅方式为“3-按告警级别”必须，可以为空

    IVS_CHAR	cReserve[32];

    IVS_UINT32	uiAlarmTypeNumber;	// 实际告警类型订阅个数
    IVS_ALARM_TYPE	stAlaryType[IVS_MAX_ALARM_TYPE_NUM];	// 告警类型数据
}IVS_ALARM_SUBSCRIBE_INFO;

// 告警订阅信息分页查询列表
typedef struct
{
    IVS_UINT32   iTotal;            // 总记录数
    IVS_INDEX_RANGE stIndexRange;   // 分页信息
    IVS_CHAR cReserve[32];                          //保留字段
    IVS_ALARM_SUBSCRIBE_INFO stSubscribeInfo[1];    // 告警订阅信息
}IVS_ALARM_SUBSCRIBE_INFO_LIST;

typedef enum
{
    HELP_SOURCE_AREA= 1,	// 防区
    HELP_SOURCE_TYPE= 2,	// 告警类型
}IVS_ALARM_HELP_SOURCE;

// 防区信息
#define IVS_MAX_ALARM_IN_NUM	512	// 最大防区个数
typedef struct
{
    IVS_UINT32	uiAlarmAreaID;	                    // 防区的ID
    IVS_CHAR	cAlarmAreaName[IVS_ALARM_NAME_LEN];	// 防区名称
    IVS_BOOL	bGuard;			                    // 是否布防	0-撤防	1-布防
    IVS_CHAR	cReserve[32];

    IVS_UINT32      uiAlarmInNum;	                    // 防区告警源实际个数
    IVS_ALARM_IN    stAlarmIn[IVS_MAX_ALARM_IN_NUM];	// 防区告警源列表
}IVS_ALARM_AREA;

// 告警订阅信息分页查询列表
typedef struct
{
    IVS_UINT32   iTotal;                // 总记录数
    IVS_INDEX_RANGE stIndexRange;       // 分页信息
    IVS_CHAR cReserve[32];              //保留字段
    IVS_ALARM_AREA stAlarmAreaInfo[1];  // 告警订阅信息
}IVS_ALARM_AREA_LIST;

#define IVS_MAX_HELP_LEN	40960
// 帮助信息
typedef struct
{
    IVS_UINT32	uiSourceType;					// 帮助信息源类型：参考 IVS_ALARM_HELP_SOURCE
    IVS_UINT32	uiSourceId;						// 防区/告警类型ID
    IVS_CHAR	cSourceName[IVS_ALARM_NAME_LEN];// 防区/告警类型名称
    IVS_CHAR	cHelpInfo[IVS_MAX_HELP_LEN];	// 帮助信息正文，支持HTML，最大支持10000文字
    IVS_CHAR	cUserName[IVS_NAME_LEN];		// 更新帮助信息用户名
    IVS_CHAR	cUpdateTime[IVS_TIME_LEN];		// 编辑时间
    IVS_CHAR	cReserve[64];
}IVS_HELP_INFO;

// 帮助信息列表
typedef struct
{
    IVS_UINT32   uiTotal;           // 总记录数
    IVS_INDEX_RANGE stIndexRange;   // 分页信息
    IVS_HELP_INFO stHelpInfo[1];    // 帮助信息
}IVS_HELP_INFO_LIST;

// 联动策略>告警动作类型
typedef enum
{
    ACTION_TYPE_INTERACTIVE=1,      // 用户交互
    ACTION_TYPE_PLATFORM_RECORD,    // 联动录像
    ACTION_TYPE_PU_RECORD,          // 联动前端录像
    ACTION_TYPE_SNAP,               // 联动抓拍
    ACTION_TYPE_PRESET=5,           // 联动预置位

    ACTION_TYPE_IO,                 // 联动开关量输出
    ACTION_TYPE_LIVE,               // 联动客户端弹出实况
    ACTION_TYPE_TV,                 // 联动实况上墙
    ACTION_TYPE_EMAIL,              // 联动EMAIL
    ACTION_TYPE_SMS=10,             // 联动短信
    ACTION_TYPE_MMS,                // 联动彩信
    ACTION_TYPE_BACKUP_RECORD,      // 联动录像备份
    ACTION_TYPE_PLATFORM_STOP_RECORD=14, // 联动停止录像
}IVS_LINKAGE_ACTION_TYPE;

// 水印告警信息
typedef struct
{
    IVS_CHAR    cCameraCode[IVS_DEV_CODE_LEN]; // 摄像机编码
    IVS_UINT64  ullAlarmEventID;               // 告警ID
    IVS_CHAR    cStartTime[IVS_TIME_LEN];      // 告警开始时间
    IVS_CHAR    cEndTime[IVS_TIME_LEN];        // 告警结束时间
    IVS_CHAR	cReserve[32];
}IVS_ALARM_WATERMARK_INFO;

// 解码器库创建失败
typedef struct
{
    IVS_CHAR    cCameraCode[IVS_DEV_CODE_LEN]; // 摄像机编码
    IVS_UINT32  ullFailedID;               // 解码失败的错误码类型
    IVS_CHAR	cReserve[32];
}IVS_DECODER_FAILED_INFO;

// 联动策略>执行分支
typedef enum
{
    ACTION_BRANCH_ALWAYS = 0,		// 总是执行
    ACTION_BRANCH_AFTER_CONFIRM,	// 确认后执行
    ACTION_BRANCH_AFTER_TIMEOUT,	// 延时未确认执行
}IVS_LINKAGE_ACTION_BRANCH;

// 联动策略>设备信息
#define IVS_LINKAGE_DEV_PARAM_LEN     128  // 联动设备动作参数长度
typedef struct
{
    IVS_CHAR	cDevCode[IVS_DEV_CODE_LEN];	            // 设备编码
    IVS_CHAR    cDevDomainCode[IVS_DOMAIN_CODE_LEN];    // 设备所在域编码
    IVS_CHAR    cParam[IVS_LINKAGE_DEV_PARAM_LEN];      // 预置位 动作参数
    IVS_CHAR	cReserve[32];
}IVS_LINKAGE_DEV_INFO;

// 联动策略>用户信息
typedef struct
{
    IVS_UINT32  uiUserId;       // 用户ID
    IVS_CHAR	cReserve[32];
}IVS_LINKAGE_USER_INFO;

// 告警-》动作-》
//	摄像机
//	用户

// 告警联动策略联动动作
#define IVS_LINKAGE_GLOBAL_PARAM_LEN        1024// 联动全局动作参数长度
#define IVS_MAX_LINKAGE_ACTION_DEVICE_NUM   8   // 执行动作的设备最大个数
#define IVS_MAX_LINKAGE_ACTION_USER_NUM     32  // 告警联动目标用户的最大个数
typedef struct
{
    IVS_UINT32 uiActionID;                                     // 联动动作ID
    IVS_UINT32 uiActionType;                                   // 告警动作类型： 参考 IVS_LINKAGE_ACTION_TYPE
    IVS_CHAR	cGlobalParam[IVS_LINKAGE_GLOBAL_PARAM_LEN];	   // 全局动作参数
    IVS_UINT32	uiActionBranch;                                // 执行分支：参考 IVS_LINKAGE_ACTION_BRANCH
    IVS_UINT32  uiDevInfoNumber;                               // 执行动作的设备实际个数
    IVS_LINKAGE_DEV_INFO stDevInfo[IVS_MAX_LINKAGE_ACTION_DEVICE_NUM];  // 执行动作的设备列表
    IVS_UINT32  uiUserInfoNumber;								// 执行动作的目标实际用户数
    IVS_UINT32 uiUserID[IVS_MAX_LINKAGE_ACTION_USER_NUM];		// 动作目标用户列表
    IVS_CHAR	cReserve[32];
}IVS_LINKAGE_ACTION;

// 告警联动策略
typedef struct
{
    IVS_UINT32 uiID;                            // 联动策略ID
//	IVS_CHAR cLinkageName[IVS_ALARM_NAME_LEN];	// 联动策略名称
    IVS_CHAR cAlarmInCode[IVS_ALARM_CODE_LEN];	// 告警源编码
    IVS_CHAR cAlarmType[IVS_ALARM_CODE_LEN];	// 告警类型编码
    IVS_CHAR cReserve[32];
    IVS_UINT32 uiActionNumber;                  // 联动动作个数
    IVS_LINKAGE_ACTION stAction[1];             // 联动动作列表
}IVS_LINKAGE_POLICY;

// 告警联动策略列表
typedef struct
{
    IVS_UINT32   uiTotal;               // 总记录数
    IVS_INDEX_RANGE stIndexRange;       // 分页信息
    IVS_LINKAGE_POLICY stLinkagePolicy[1];  // 告警联动策略列表
}IVS_LINKAGE_POLICY_LIST;

// 告警联动动作停止通知
typedef struct
{
    IVS_CHAR    cSrcDomainCode[IVS_DOMAIN_CODE_LEN];            // 动作源域编码，为可选，不带该字段时表示为本域
    IVS_UINT64	ullAlarmEventID;                                // 告警事件ID，和SrcDomainCode组成唯一值
    IVS_UINT32  uiActionType;                                   // 告警动作类型： 参考 IVS_LINKAGE_ACTION_TYPE
    IVS_CHAR	cGlobalParam[IVS_LINKAGE_GLOBAL_PARAM_LEN];	    // 全局动作参数

    IVS_UINT32  uiDevInfoNumber;                                // 执行动作的设备实际个数
    IVS_LINKAGE_DEV_INFO stDevInfo[IVS_MAX_LINKAGE_ACTION_DEVICE_NUM];  // 执行动作的设备列表
    IVS_UINT32  uiUserInfoNumber;								// 执行动作的目标实际用户数
    IVS_UINT32  uiUserID[IVS_MAX_LINKAGE_ACTION_USER_NUM];		// 动作目标用户列表
    IVS_CHAR	cReserve[32];
}IVS_STOP_LINKAGE_ACTION;

// 手动录像状态通知
typedef struct
{
    IVS_CHAR    cCameraCode[IVS_DEV_CODE_LEN];      // 摄像机编码
    IVS_UINT32	uiUserID;                           // 用户ID
    IVS_UINT32	uiRecordMethod;                     // 录像方式：值参考IVS_RECORD_METHOD
    IVS_UINT32	uiManualRecordState;                // 手动录像状态：0-停止1-启动
    IVS_UINT32	uiNotifInfo;                        // 停止原因，停止时有效：0-手动停止 1-超时停止 2-异常停止
    IVS_CHAR	cReserve[32];
}IVS_MANUAL_RECORD_STATUS_NOTIFY;

// 策略属性
typedef struct
{
//	char          Id[POLICYID_LEN + 1]; // 策略ID
    unsigned char Type;        			// 0x00: 禁止，0x01: 连续，0x02: 事件触发(加一等于数据库表里的值)
    unsigned char Week;        			// 周标志, 1 ~ 8分别对应周日 ~ 周六
    unsigned char Once;        			// 表示该策略只执行一次
    IVS_CHAR	StartTime[IVS_TIME_LEN];// 开始时间，国际标准时间, 只有时分秒
    IVS_CHAR	EndTime[IVS_TIME_LEN];  // 结束时间，国际标准时间, 只有时分秒
    unsigned char isEnable;     		// 是否启用：0-未启用，1-启用
    IVS_CHAR	cReserve[32];
}IVS_STRAT_PROPERTY;

// 字典信息
#define IVS_DICTIONARY_NAME_LEN     64      // 字段名称长度
#define IVS_DICTIONARY_VALUE_LEN    256     // 字典值长度
#define IVS_DICTIONARY_TYPE_LEN     32      // 字典类型长度
#define IVS_DICTIONARY_REMARK_LEN   256      // 备注长度
typedef struct
{
    IVS_UINT32  uiID;                                   // 记录唯一ID
    IVS_CHAR    cDictName[IVS_DICTIONARY_NAME_LEN];     // 字典名称（英文字母和符号）
    IVS_CHAR    cDictValue[IVS_DICTIONARY_VALUE_LEN];   // 字典值，支持中文、英文
    IVS_CHAR    cDictType[IVS_DICTIONARY_TYPE_LEN];     // 字典类型
    IVS_UINT32  uiParentID;                             // 父节点ID
    IVS_CHAR    cRemark[IVS_DICTIONARY_REMARK_LEN];     // 备注

    IVS_CHAR cReserve[32];                              //保留字段
}IVS_DICTIONARY_INFO;

// 字典信息列表
typedef struct
{
    IVS_UINT32   uiTotal;                       // 总记录数
    IVS_INDEX_RANGE stIndexRange;               // 分页信息
    IVS_DICTIONARY_INFO stDictionaryInfo[1];    // 字典信息
}IVS_DICTIONARY_INFO_LIST;

////////////////////////////////////////MLib相关的头文件////////////////////////////////////////////
// 业务类型 ServiceType;
typedef enum
{
    SERVICE_TYPE_INVALID            = 0,
    SERVICE_TYPE_REALVIDEO          = 0x0001,   // 实况;
    SERVICE_TYPE_RECORD             = 0x0002,   // 平台录像;
    SERVICE_TYPE_DOWNLOAD           = 0x0003,   // 本地录像下载;
    SERVICE_TYPE_PLAYBACK           = 0x0004,   // 录像回放;
    SERVICE_TYPE_AUDIO_CALL         = 0x0005,   // 音频对讲;
    SERVICE_TYPE_AUDIO_BROADCAST    = 0x0006,   // 音频广播;
    SERVICE_TYPE_PU_DOWNLOAD        = 0x0007,   // 前端录像下载
    SERVICE_TYPE_PU_PLAYBACK        = 0x0008,   // 前端录像回放

    SERVICE_TYPE_REALVIDEO_BACKUP       = 0x0014,       // 实况备份
    SERVICE_TYPE_PLATRECORD_BACKUP      = 0x0015,       // 平台录像备份
    SERVICE_TYPE_PURECORD_BACKUP        = 0x0016,       // 前端录像备份
    SERVICE_TYPE_BACKUPRECORD_PLAYBACK  = 0x0017,       // 录像备份回放
    SERVICE_TYPE_BACKUPRECORD_DOWNLOAD  = 0x0018,       // 录像备份下载
    SERVICE_TYPE_DISASTEBACKUP_PLAYBACK = 0x0019,       // 容灾录像回放
    SERVICE_TYPE_DISASTEBACKUP_DOWNLOAD = 0x001A,       // 容灾录像下载
    SERVICE_TYPE_PU_UPLOAD              = 0x001B,       // 前端缓存补录
    SERVICE_TYPE_PU_PRERECORD           = 0x001C,       // 前端预录
    SERVICE_TYPE_IMGU_URL           = 0x001D,       // IMGU Get URL
    SERVICE_TYPE_MATADATA_DOWNLOAD  = 0x001E,       // 元数据流
    SERVICE_TYPE_SOURCE_DATA_STARM           = 0x001E,       //元数据流
    SERVICE_TYPE_CACHED_METADATA_DOWNLOAD  = 0x001F,       // 元数据流缓存补录
    SERVICE_TYPE_HIGH_SPEED_DOWNLOAD   = 0x0020,   //高速下载
    SERVICE_TYPE_MAX
}IVS_SERVICE_TYPE;

// 播发类型;
typedef enum
{
    BROADCAST_UNICAST   = 0x0000,   // 单播;
    BROADCAST_MULTICAST = 0x0001    // 组播;
}IVS_BROADCAST_TYPE;

// 连接类型;
typedef enum
{
    MEDIA_TRANS     = 0x0000, // 中转
    MEDIA_DIRECT    = 0x0001, // 直连;
    MEDIA_DIRECT_IPC    = 0x0002, // 直连IPC
}IVS_MEDIA_TRANS_MODE;

// 传输协议;
typedef enum
{
    PROTOCOL_RTP_OVER_UDP = 0x0001, //RTP over UDP
    PROTOCOL_RTP_OVER_TCP = 0x0002, //RTP over TCP
    PROTOCOL_UDP          = 0x0003, //UDP
    PROTOCOL_TCP          = 0x0004  //TCP
}IVS_PROTOCOL_TYPE;

// RTSP协议;
typedef enum
{
	PROTOCOL_RTSP_VIDEO  = 0x0000, //RTSP
	PROTOCOL_RTSP_VIDEO_OVER_TLS = 0x0001 //RTSP over TLS
}IVS_RTSP_VIDEO_TYPE;

// 打包协议类型;
typedef enum
{
    PACK_PROTOCOL_ES     = 0x0001,
    PACK_PROTOCOL_PS     = 0x0002,
    PACK_PROTOCOL_TS     = 0x0003
}IVS_PACK_PROTOCOL_TYPE;

// 视频解码类型;
typedef enum
{
    VIDEO_DEC_H264              = 0x0001,
    VIDEO_DEC_MJPEG             = 0x0002,
    VIDEO_DEC_MPEG4             = 0x0003,
    VIDEO_DEC_MPEG2             = 0x0004,
    VIDEO_DEC_AVS               = 0x0005,
    VIDEO_DEC_H265				= 0x0006,
    VIDEO_DEC_SVAC				= 0x0007,
    VIDEO_DEC_INIT                =0x0008 //初始化的解码类型
}IVS_VIDEO_DEC_TYPE;

// H264 Profile
typedef enum
{
    H264_PROFILE_BASELINE= 1,	// BP
    H264_PROFILE_EXTENDED,		// EP
    H264_PROFILE_MAIN,			// MP
    H264_PROFILE_HIGH,			// HP
}IVS_H264_PROFILE;

typedef enum {
    H265_PROFILE_MAIN = 1,
    H265_PROFILE_MAIN10,
    H265_PROFILE_MAINSP
}IVS_H265_PROFILE;

// MJPEG Profile
typedef enum
{
    MJPEG_PROFILE_SP= 1,	// SP
    MJPEG_PROFILE_ASP,		// ASP
}IVS_MJPEG_PROFILE;

// 音频解码类型;
typedef enum
{
    AUDIO_DEC_G711A             = 0x0001,
    AUDIO_DEC_G711U             = 0x0002,
    AUDIO_DEC_G726              = 0x0003
}IVS_AUDIO_DEC_TYPE;

// 码流类型
typedef enum
{
    STREAM_TYPE_UNSPECIFIED=0,  // 不指定流
    STREAM_TYPE_MAIN=1, // 主码流
    STREAM_TYPE_SUB1,	// 辅码流1
    STREAM_TYPE_SUB2,	// 辅码流2
}IVS_STREAM_TYPE;

// 媒体参数
typedef struct
{
    IVS_VENDOR_TYPE         DecoderCompany; // 解码器厂商，1-HUAWEI，默认为1
    IVS_STREAM_TYPE         StreamType;     // 码流类型,1-主码流 2-辅码流1 3-辅码流2，默认为1
    IVS_PROTOCOL_TYPE       ProtocolType;   // 协议类型，1-UDP 2-TCP，默认为1
    IVS_MEDIA_TRANS_MODE    TransMode;      // 是否直连优先,0-否 1-是，默认为0
    IVS_BROADCAST_TYPE      BroadCastType;  // 是否支持组播，0-不支持 1-支持，默认为0
    IVS_UINT32	            VideoDecType;   // 视频编码格式：参考 IVS_VIDEO_DEC_TYPE 1-H.264，默认为1
    IVS_AUDIO_DEC_TYPE      AudioDecType;   // 音频编码格式，1-PCMA 2-PCMU，默认为1
    IVS_DEVICE_PROTOCOL     AccessProtocal;
    IVS_RTSP_VIDEO_TYPE     RtspType;       // RTSP类型，1-RTSP 2-RTSP OVER TLS，默认为1
    IVS_UINT32              MetaData;       //是否携带元数据，0-不带元数据 非0-带元数据
    IVS_CHAR                cReserve[56];
} IVS_MEDIA_PARA;


// 视频质量参数
typedef struct
{
    IVS_UINT32  VideoDecType;           // 视频编码格式：参考 IVS_VIDEO_DEC_TYPE

    IVS_UINT32  VideoCodeRate;          // 视频码率
    IVS_UINT32  VideoAverageCodeRate;   // 视频平均码率

    IVS_UINT32  VideoFPS;        // 视频帧率
    IVS_UINT32  VideoWidth;      // 视频宽
    IVS_UINT32  VideoHeight;     // 视频高
    IVS_UINT32  CurrPlayTime;    // 当前播放时间

    IVS_UINT32  Reserved1;       //保留1
    IVS_UINT32  Reserved2;       //保留2
}IVS_VEDIO_QUALITY_PARA;

// 音频质量参数
typedef struct
{
    IVS_AUDIO_DEC_TYPE      AudioDecType;           // 音频编码方式
    IVS_UINT32              AudioCodeRate;          // 音频码率
    IVS_UINT32              AudioAverageCodeRate;   // 音频平均码率
    IVS_UINT32              AudioState;             // 音频状态    0-关闭  1-打开

    IVS_UINT32              Reserved1;              // 保留1
    IVS_UINT32              Reserved2;              // 保留2
}IVS_AUDIO_QUALITY_PARA;

typedef enum
{
    DOMAIN_TYPE_STACK=1,	// 堆叠
    DOMAIN_TYPE_CLUSTER=2,	// 集群
    DOMAIN_TYPE_SINGLE=3,	// 单机
}IVS_DOMAIN_TYPE;

typedef enum
{
    NVR_MODE_STACK = 1,   // 堆叠
    NVR_MODE_CLUSTER = 2, // 集群
    NVR_MODE_NONE    =3,
}IVS_NVR_MODE;

// 域路由信息
#define IVS_MAX_DOMAIN_ROUTE_NUM    1024     // 域路由最大记录数
typedef struct
{
    IVS_UINT32	uiDomainType;                       // SMU工作模式，参考 IVS_DOMAIN_TYPE 1-堆叠 2-集群 3-单机
    IVS_BOOL	bIsAgent;	                        // 是否代理
    IVS_CHAR	cDomainCode[IVS_DOMAIN_CODE_LEN];	// 域编码
    IVS_CHAR	cDomainName[IVS_NAME_LEN];		    // 域名称
    IVS_IP		stIP;                               // 域IP
    IVS_UINT32	uiPort;                             // 域端口
	IVS_UINT32 uiTLSPort;                       // TLS通道端口
	IVS_UINT32 uiSupportTls;				  //是否支持TLS通道 1-支持，0-不支持
    IVS_UINT32	uiStatus;			                // 设备状态：0-离线，1-在线，2-休眠 参考 IVS_DEV_STATUS
    IVS_CHAR	cSuperDomain[IVS_DOMAIN_CODE_LEN];	// 上级域编码
    IVS_BOOL    bIsLocalDomain;                     // 是否本域 0-不是 1-是
    IVS_BOOL    bProgressionTransmit;               // 是否支持转发 0-不是 1-是
    IVS_CHAR	cReserve[60];
}IVS_DOMAIN_ROUTE;

// 域路由信息列表
// 系统域路由最大个数 128
typedef struct
{
    IVS_UINT32   uiTotal;               // 系统实际域路由个数
    //IVS_INDEX_RANGE stIndexRange;     // 分页信息
    IVS_DOMAIN_ROUTE stDomainRoute[1];  // 域路由信息
}IVS_DOMAIN_ROUTE_LIST;

// 视频显示比例
typedef enum
{
    DISPLAY_SCALE_ORIGINAL=1,   // 原始比例
    DISPLAY_SCALE_FULL=2,       // 铺满窗口
}IVS_DISPLAY_SCALE;

// 视频播放效果
typedef enum
{
    PLAY_QUALITY_FLUENCY=1,    // 流畅优先
    PLAY_QUALITY_DEFINITION=2, // 清晰度优先
}IVS_PLAY_QUALITY_MODE;

// 密码过期信息
typedef struct
{
    IVS_BOOL    bIsNeedWarning;     // 是否需要提示用户：0-不需要；1-需要
    IVS_UINT32  uiRemainDays;       // 密码还剩多少天过期
    IVS_UINT32  uiExpiredDays;      // 密码已过期的天数（平台可设置过期不锁定账号）
    IVS_CHAR    cReserve[32];
}IVS_PWD_EXPIRE_INFO;

typedef enum
{
    PAY_LOAD_NO_TYPE     = -1,
    PAY_LOAD_TYPE_PCMU   = 0,   // G711的u率
    PAY_LOAD_TYPE_PCM    = 1,
    PAY_LOAD_TYPE_G723   = 4,   // G723
    PAY_LOAD_TYPE_PCMA   = 8,   // G711的a率
    PAY_LOAD_TYPE_G722   = 9,   // G722

    PAY_LOAD_TYPE_G726   = 16,  // G726
    PAY_LOAD_TYPE_AAC    = 17,  // AAC

    PAY_LOAD_TYPE_MJPEG  = 26,  // MJPEG
    PAY_LOAD_TYPE_H264_1 = 96,  // H264(非标准定义)
    PAY_LOAD_TYPE_AMR_MB = 97,  // AMR_NB
    PAY_LOAD_TYPE_MPEG4  = 98,  // MPEG4
    PAY_LOAD_TYPE_H264   = 99,  // H264
    PAY_LOAD_TYPE_H265   = 108, // H265
    PAY_LOAD_TYPE_MP3    = 101, // MP3
    PAY_LOAD_TYPE_3GPP   = 102,  // 3GPP
    PAY_LOAD_TYPE_AVS    = 103,  // AVS
    PAY_LOAD_TYPE_SVAC   = 104,
    PAY_LOAD_TYPE_H264_2 = 105, //宇视摄像机pt
    PAY_LOAD_TYPE_TRACK  = 107,  // 轨迹
}IVS_PAYLOAD_TYPE;

/*****************************未接码原始数据结构****************************/
typedef struct
{
    IVS_UINT32	uiStreamType;		// 编码格式，参考：IVS_PAYLOAD_TYPE
    IVS_UINT32  uiFrameType;		// 帧数据类型，SPS、PPS、IDR、P（视频数据有效）
    IVS_UINT32  uiTimeStamp;		// 时间戳
    IVS_UINT64  ullTimeTick;		// 绝对时间戳
    IVS_UINT32  uiWaterMarkValue;	// 水印数据 ，0表示无水印数据（视频数据有效）

    IVS_UINT32	uiWidth;			// 视屏宽度
    IVS_UINT32	uiHeight;			// 视频高度

    IVS_UINT32	uiGopSequence;		// GOP序列
    IVS_UINT64  ullInTick;          // 接收时间
}IVS_RAW_FRAME_INFO;

/*****************************解码数据结构*********************************/
typedef enum
{
    PICTURE_FORMAT_YUV420 = 0,
    PICTURE_FORMAT_YUV422,
    PICTURE_FORMAT_YUV444,
    PICTURE_FORMAT_YUV422V,
    PICTURE_FORMAT_YUV400,
    PICTURE_FORMAT_YV12,
    PICTURE_FORMAT_NV12,
    PICTURE_FORMAT_YUV422H,
}IVS_PICTURE_FORMAT;

typedef struct
{
    IVS_UCHAR*  pY;
    IVS_UCHAR*  pU;
    IVS_UCHAR*  pV;
    IVS_UINT32  uiPitch;            // 平面的内存占用长度(也叫做跨度Stride)
    IVS_UINT32  uiWidth;            // 画面宽
    IVS_UINT32  uiHeight;           // 画面高
    IVS_UINT32  uiPictureFormat;    // 画面格式,参考IVS_PICTURE_FORMAT
    IVS_UINT32  uiTimeStamp;        // RTP时间戳
    IVS_UINT64  ullTimeTick;        // 时标信息，单位毫秒
    IVS_UINT32	uiGopSequence;		// GOP序列
    IVS_CHAR	cReserve[32];
    IVS_UINT32  uiFrameType;        //帧类型(I P)
}IVS_VIDEO_FRAME;

typedef struct
{
    IVS_UCHAR*  pFrame;         // 音频帧首地址
    IVS_UINT32  uiFrameSize;    // 音频帧长度
    IVS_UINT32  uiSampleRate;   // 采样率
    IVS_UINT32  uiChannels;     // 音频声道数
    IVS_UINT32  uiBits;         // 样位率
    IVS_UINT32  uiTimeStamp;    // RTP时间戳
    IVS_UINT64  ullTimeTick;    // 时标信息，单位毫秒
    IVS_UINT32  uiAudioFormat;  // 音频格式，直接使用payload Type定义的值，参考 IVS_PAYLOAD_TYPE
    IVS_CHAR	cReserve[32];
}IVS_AUDIO_FRAME;

// 媒体流类型;
typedef enum
{
    MEDIA_STREAM_VIDEO = 0,       // 视频;
    MEDIA_STREAM_AUDIO            // 音频;
}IVS_MEDIA_STREAM;

// 设备状态;
typedef struct
{
    IVS_CHAR	cCode[IVS_DEV_CODE_LEN];	// 设备编码
    IVS_UINT32	uiStatus;			        // IVS_DEV_STATUS
    IVS_IP		stIP;						// 设备IP信息
    IVS_UINT32	uiPort;						// 设备连接端口
    IVS_CHAR	cReserve[32];
}IVS_DEVICE_STATE;

// 语音对讲参数
typedef struct
{
    IVS_UINT32      uiProtocolType;     // 协议类型，1-UDP
    IVS_BOOL        bDirectFirst;       // 是否直连优先，0-否 1-是，默认为0
    IVS_CHAR        cNVRCode[IVS_NVR_CODE_LEN + 1];   // NVRCode

    IVS_CHAR	    cReserve[32];
}IVS_VOICE_TALKBACK_PARAM;

// 预置位信息
#define IVS_MAX_PRESET_NUM      256     // 预置位
#define IVS_PRESET_NAME_LEN     84      // 预置位名称
typedef struct
{
    IVS_UINT32  uiPresetIndex;   // 预置位索引
    IVS_CHAR    cPresetName[IVS_PRESET_NAME_LEN];   // 预置位名称，1~20个字符。
    IVS_UINT32  uiFocusSwitch;   // 对焦记忆开关   0-不启用，1-启用
    IVS_CHAR	cReserve[32];
}IVS_PTZ_PRESET;

// 看守位信息
typedef struct
{
    IVS_UINT32  uiPresetIndex;          // 预置位索引
    IVS_BOOL    bEnableGuardPosition;   // 启用标识：0-不启用，1-启用
    IVS_UINT32  uiWaitTime;             // 自动归位等待时长，30秒~3600秒
    IVS_CHAR	cReserve[32];
}IVS_GUARD_POS_INFO;

// 巡航类型
typedef enum
{
    CRUISE_TRACK = 1,       // 轨迹巡航
    CRUISE_MODE,            // 模式巡航
    CRUISE_HORIZONTAL,      // 水平巡航
    CRUISE_VERTICAL,        // 垂直巡航
}IVS_CRUISE_TYPE;

// 云镜巡航轨迹点
typedef struct
{
    IVS_UINT32  uiPresetIndex;  // 预置位索引, 最多20个点
    IVS_UINT32  uiDwellTime;    // 预置位停留时间，秒为单位，1~3600秒
    IVS_UINT32  uiSpeed;        // 云台速度，1~10
    IVS_CHAR	cReserve[32];
}IVS_CRUISE_TRACK_POINT;

// 云镜巡航轨迹
#define IVS_MAX_CURISE_TRACK_NUM    16  // 单个摄像机最大巡航轨迹个数
#define IVS_CURISE_TRACK_NAME_LEN   84  // 轨迹名称
#define IVS_MAX_CURISE_TRACK_POINT  20  // 巡航轨迹预置位最大个数
typedef struct
{
    IVS_UINT32  uiCruiseNO;                                             // 轨迹索引
    IVS_UINT32  uiCruiseType;                                           // 巡航类型，值参考 IVS_CRUISE_TYPE
    IVS_CHAR    cTrackName[IVS_CURISE_TRACK_NAME_LEN];                  // 轨迹名称
    IVS_UINT32  uiTrackPointNum;                                        // 轨迹点个数
    IVS_CRUISE_TRACK_POINT  stTrackPoint[IVS_MAX_CURISE_TRACK_POINT];   // 轨迹点列表
    IVS_UINT32  uiCruiseStatus;                                         // 巡航状态:1执行;0未执行
    IVS_CHAR	cReserve[32];
}IVS_CRUISE_TRACK;

// 时间片段结构
typedef struct
{
    IVS_CHAR	cStart[IVS_TIME_LEN];   // 格式如yyyyMMddHHmmss
    IVS_CHAR	cEnd[IVS_TIME_LEN];     // 格式如yyyyMMddHHmmss
    IVS_UINT32  uiCruiseNO;             // 轨迹索引
    IVS_UINT32  uiCruiseType;           // 巡航类型，值参考 IVS_CRUISE_TYPE
    IVS_CHAR	cReserve[32];
}IVS_CRUISE_TIME_SPAN;

// 巡航计划信息
typedef struct
{
    IVS_UINT32      uiDayType;								//星期几：参考 IVS_DAY_TYPE 0 – 每天 1 – 周一 2 – 周二 3 – 周三 4 – 周四 5 – 周五 6 – 周六 7 – 周日
    IVS_UINT32      uiTimeSpanInfoNum;						//时间段数量
    IVS_CRUISE_TIME_SPAN   stTimeSpanInfo[IVS_MAX_TIMESPAN_NUM];   //时间段信息
}IVS_CRUISE_PLAN_INFO;

// 巡航计划
typedef struct
{
    IVS_BOOL	bEnable;        // 是否启用计划：0-停用，1-启用
    IVS_UINT32	uiPlanType;		// 计划方式：0-(WEEK)周计划,1(DAY)-日计划，周一到周日计划相同
    IVS_CHAR	cReserve[32];
    IVS_UINT32	uiPlanInfoNum;			                // 计划信息条数：周计划-7，日计划-1
    IVS_CRUISE_PLAN_INFO	stPlanInfo[IVS_MAX_PLAN_INFO_NUM];	// 计划信息：周计划-最多7个计划信息，日计划-1一个计划信息
}IVS_CRUISE_PLAN;

// 时间片段结构
typedef struct
{
    IVS_CHAR	cStart[IVS_TIME_LEN];   // 格式如yyyyMMddHHmmss
    IVS_CHAR	cEnd[IVS_TIME_LEN];     // 格式如yyyyMMddHHmmss
    IVS_UINT32  SnapInterval;           // 抓拍时间间隔
}IVS_SNAPSHOT_TIME_SPAN;

// 抓拍计划信息
typedef struct
{
    IVS_UINT32      uiDayType;								//星期几：参考 IVS_DAY_TYPE 0 – 每天 1 – 周一 2 – 周二 3 – 周三 4 – 周四 5 – 周五 6 – 周六 7 – 周日
    IVS_UINT32      uiTimeSpanInfoNum;						//时间段数量
    IVS_SNAPSHOT_TIME_SPAN   stTimeSpanInfo[IVS_MAX_TIMESPAN_NUM];   //时间段信息
}IVS_SNAPSHOT_PLAN_INFO;

// 抓拍计划
typedef struct
{
    IVS_BOOL	bEnable;        // 是否启用计划：0-停用，1-启用
    IVS_UINT32	uiPlanType;		// 计划方式：0-(WEEK)周计划,1(DAY)-日计划，周一到周日计划相同
    IVS_CHAR	cReserve[32];
    IVS_UINT32	uiPlanInfoNum;			                // 计划信息条数：周计划-7，日计划-1
    IVS_SNAPSHOT_PLAN_INFO	stPlanInfo[IVS_MAX_PLAN_INFO_NUM];	// 计划信息：周计划-最多7个计划信息，日计划-1一个计划信息
}IVS_SNAPSHOT_PLAN;
const IVS_UINT32 IVS_SNAPSHOT_TYPE_IA       = 0x00000001;   // 智能分析抓拍
const IVS_UINT32 IVS_SNAPSHOT_TYPE_ALARM    = 0x00000002;   // 告警抓拍
const IVS_UINT32 IVS_SNAPSHOT_TYPE_MANUAL   = 0x00000004;   // 手动抓拍(包括定时抓拍)

// 抓拍图片查询信息
typedef struct
{
    IVS_TIME_SPAN   stTimeSpan;     // 抓拍图片时间范围
    IVS_INDEX_RANGE stIndexRange;   // 抓拍图片索引信息
    IVS_UINT32      uiSnapType;     // 抓拍图片类型：异或标记值，例如0x01 | 0x02=3表示查询类型包括智能分析抓拍和告警抓拍；值参考IVS_SNAPSHOT_TYPE_IA
    IVS_CHAR	    cReserve[64];
}IVS_QUERY_SNAPSHOT_PARAM;

// 抓拍图片信息
typedef struct
{
    IVS_CHAR    cCameraCode[IVS_DEV_CODE_LEN];      // 摄像机编码
    IVS_CHAR	cSnapTime[IVS_TIME_LEN];            // 抓拍图片时间，格式如yyyyMMddHHmmss
    IVS_UINT32  uiSnapType;                         // 抓拍类型：参考IVS_SNAPSHOT_TYPE_IA
    IVS_UINT32	uiPictureID;                        // 抓拍图片ID
    IVS_CHAR    cPictureName[IVS_FILE_NAME_LEN];    // 文件名
    IVS_UINT32	uiPictureSize;                      // 图片文件大小
    IVS_CHAR    cPreviewUrl[IVS_URL_LEN];	        // 抓拍图片缩略图URL
    IVS_CHAR    cPictureUrl[IVS_URL_LEN];	        // 抓怕图片URL
    IVS_CHAR    cReserve[32];
}IVS_SNAPSHOT_INFO;

// 抓拍图片列表信息
typedef struct
{
    IVS_UINT32   uiTotal;                   // 总记录数
    IVS_INDEX_RANGE stIndexRange;           // 分页信息
    IVS_SNAPSHOT_INFO stSnapshotInfo[1];    // 抓拍图片信息
}IVS_SNAPSHOT_INFO_LIST;

#define IVS_MAX_IPC_MODEL_LIST_NUM 	1024	// 系统支持的最大模板数

//IPC模板信息
typedef struct
{
	IVS_CHAR   cModelFileName[IVS_FILE_NAME_LEN];     //IPC模板文件名

	IVS_CHAR   cReserve[256];       //预留字段
}IVS_IPCMODEL_INFO;


//IPC模板信息列表
typedef struct
{
    IVS_UINT32   uiTotal;                   // 总记录数
    IVS_UINT32   uiFromSerial;              //更新起始流水号
    IVS_UINT32   uiToSerial;                //更新的结束流水号
    IVS_CHAR     cModelFilePath[IVS_FILE_NAME_LEN]; //更新模板的路径信息
	IVS_INDEX_RANGE stIndexRange;           // 索引信息
    IVS_IPCMODEL_INFO stIPCModelInfo[1];    // IPC模板信息
}IVS_IPCMODEL_LIST;



// 实况参数
typedef struct
{
    IVS_UINT32      uiStreamType;       // 码流类型，值参考 IVS_STREAM_TYPE
    IVS_UINT32      uiProtocolType;     // 协议类型，1-UDP 2-TCP，默认为1
    IVS_BOOL        bDirectFirst;       // 是否直连优先，0-否 1-是，默认为0
    IVS_BOOL        bMultiCast;         // 是否组播，0-单播，1-组播，默认为0

    IVS_CHAR        cNVRCode[IVS_NVR_CODE_LEN + 1];   // NVRCode
    IVS_CHAR        cCamName[IVS_CAMERA_NAME_LEN + 1]; // 摄像机名称
    IVS_DEVICE_PROTOCOL  enAccessProto;      // 设备接入协议枚举值
    IVS_BOOL        bShadowDev;
    IVS_UINT32      uiRtspType;         // RTSP类型，1-RTSP 2-RTSP OVER TLS，默认为1
    IVS_UINT32      uiMetaDataType;         // 元数据类型，0-不请求元数据，非0-请求元数据
    IVS_CHAR	    cReserve[24];
}IVS_REALPLAY_PARAM;

// 录像回放参数
typedef struct
{
    IVS_UINT32      uiProtocolType;                   // 协议类型，1-UDP 2-TCP，默认为1
    IVS_TIME_SPAN   stTimeSpan;                       // 实况启动、结束时间
    IVS_FLOAT       fSpeed;                           // 回放速率
    IVS_CHAR        cNVRCode[IVS_NVR_CODE_LEN + 1];   // 要回放的录像文件所在的NVR的NVRCode
    IVS_BOOL        bDirectFirst;       // 是否直连优先，0-否 1-是，默认为0
    IVS_CHAR        cDomainCode[IVS_DOMAIN_CODE_LEN + 1]; // 录像所在的域code
    IVS_CHAR        cCamName[IVS_CAMERA_NAME_LEN + 1]; // 摄像机名称
    IVS_DEVICE_PROTOCOL  enAccessProto;  // 接入协议
	IVS_UINT32      uiRtspType;         // RTSP类型，1-RTSP 2-RTSP OVER TLS，默认为1
    IVS_UINT32      uiMetaDataType;         // 元数据类型，零-不请求元数据 非0-请求元数据
    IVS_CHAR	    cReserve[24];
}IVS_PLAYBACK_PARAM;

// 本地录像回放参数
typedef struct
{
    IVS_UINT32      uiStartTime;        // 回放起始时间，单位是秒
    IVS_UINT32      uiEndTime;          // 回放结束时间，单位是秒
    IVS_FLOAT       fSpeed;             // 回放速率
    IVS_CHAR        cPWD[IVS_PWD_LEN];  // 录像密码（为空表示无密码）
    IVS_CHAR	    cReserve[32];
}IVS_LOCAL_PLAYBACK_PARAM;

// 媒体地址
typedef struct
{
    IVS_IP      stIP;		                    // 媒体流目的IP
    IVS_UINT32  uiAudioPort;                    // 媒体流目的音频端口
    IVS_UINT32  uiVideoPort;                    // 媒体流目的视频端口
    IVS_CHAR	cReserve[32];
}IVS_MEDIA_ADDR;

// 电视墙参数
#define IVS_TVWALL_DECODER_CODE_LEN     24  // 电视墙解码器长度
typedef struct
{
    IVS_CHAR    cDecoderCode[IVS_TVWALL_DECODER_CODE_LEN];  // 电视墙解码器编码
    IVS_UINT32  uiChannel;                                  // 解码器通道号
    IVS_BOOL    bSDKConnect;                                // 是否SDK方式接入解码器，0-否 1-是，默认为0  // 修改 1 - hiksdk  2-huaweisdk
    IVS_BOOL    bPatrol;                                    // 是否轮巡
    IVS_CHAR	cReserve[32];
}IVS_TVWALL_PARAM;

// 水印告警确认信息
#define IVS_WATERMARK_ALARM_DESCRIPTION_LEN 1024
typedef struct
{
    IVS_CHAR    cCameraCode[IVS_DEV_CODE_LEN];                      // 摄像机编码
    IVS_UINT64	ullAlarmEventID;                                    // 告警事件ID
    IVS_CHAR    cConfirmInfo[IVS_WATERMARK_ALARM_DESCRIPTION_LEN];	// 告警处理人员输入的信息
    IVS_CHAR    cConfirmTime[IVS_TIME_LEN];				            // 告警处理时间
    IVS_CHAR	cReserve[64];
}IVS_WATERMARK_ALARM_CONFIRM;

// 水印告警取消信息
typedef struct
{
    IVS_CHAR    cCameraCode[IVS_DEV_CODE_LEN];                      // 摄像机编码
    IVS_UINT64	ullAlarmEventID;                                    // 告警事件ID
    IVS_CHAR    cCancelInfo[IVS_WATERMARK_ALARM_DESCRIPTION_LEN];	// 告警处理人员输入的信息
    IVS_CHAR    cCancelTime[IVS_TIME_LEN];				            // 告警撤销时间
    IVS_CHAR	cReserve[64];
}IVS_WATERMARK_ALARM_CANCEL;

// 水印告警信息
typedef struct
{
    IVS_UINT64	ullAlarmEventID;                                    // 告警事件ID
    IVS_CHAR    cAlarmType[IVS_ALARM_TYPE_LEN];		                // 告警类型：水印告警
    IVS_CHAR    cCheckoutOperator[IVS_NAME_LEN];	                // 水印校验人
    IVS_CHAR    cCameraCode[IVS_DEV_CODE_LEN];                      // 摄像机编码
    IVS_CHAR	cOccurStartTime[IVS_TIME_LEN];                      // 水印告警发生时间：YYYYMMDDHHMMSSmmm
    IVS_CHAR	cOccurStopTime[IVS_TIME_LEN];                       // 水印告警结束时间：YYYYMMDDHHMMSSmmm
    IVS_CHAR    cConfirmOperator[IVS_NAME_LEN];	                    // 告警确认人
    IVS_CHAR    cConfirmTime[IVS_TIME_LEN];	                        // 告警确认时间
    IVS_CHAR    cConfirmInfo[IVS_WATERMARK_ALARM_DESCRIPTION_LEN];	// 告警确认描述信息，键盘可见字符和中文，
    IVS_UINT32  uiWatermarkAlarmStatus;                             // 水印告警状态：0x01-未确认 0x02-已确认 0x04-已撤销；异或值表示多选，如0x07表示查询三种状态，0x06表示查询已确认和已撤销；
    IVS_CHAR	cReserve[64];
}IVS_WATERMARK_ALARM_INFO;

typedef struct
{
    IVS_UINT32   uiTotal;                               // 总记录数
    IVS_INDEX_RANGE stIndexRange;                       // 分页信息
    IVS_WATERMARK_ALARM_INFO stWatermarkAlarmInfo[1];   // 水印告警信息
}IVS_WATERMARK_ALARM_INFO_LIST;

// SFTP信息
#define IVS_FTP_ACCOUNT_LEN			64			// 名称长度
typedef struct
{
    IVS_IP      stIP;		                    // 服务器IP
    IVS_UINT32  uiPort;		                    // 服务器端口
    IVS_CHAR    cAccount[IVS_FTP_ACCOUNT_LEN];  // 服务器账号
    IVS_CHAR    cPWD[IVS_PWD_LEN];              // 服务器账号的密码
    IVS_CHAR	cReserve[32];
}IVS_FTP_INFO;

typedef struct
{
    IVS_FTP_INFO    stFTPInfo;                          // ftp信息
    IVS_CHAR        cMapFilePath[IVS_FILE_NAME_LEN];    // 电子地图路径信息
    IVS_CHAR        cReserve[32];                       //保留字段
}IVS_MAP_FTP_INFO;

/*广播失败异常事件结构体*/
typedef struct ST_BROADCAST_FAILED_INFO
{
    IVS_INT32 iSessionID;                             //登录会话ID
    IVS_CHAR cVoiceCode[IVS_DEV_CODE_LEN + 1];          //广播失败的语音设备编码
}BROADCAST_FAILED_INFO;

/*分辨率信息*/
typedef struct
{
    IVS_CHAR cResolution[IVS_FILE_NAME_LEN];   //分辨率信息
    IVS_CHAR cPFrameList[IVS_MAX_NAME_LIST_LEN]; //帧率列表，以逗号分隔
    IVS_CHAR cNFrameList[IVS_MAX_NAME_LIST_LEN]; //帧率列表，以逗号分隔
    IVS_CHAR cReserve[32]; //保留字段
}IVS_RESOLUTION_INFO;

/*I帧信息*/
typedef struct
{
    IVS_INT32 iPMinIFrameInterval; //P制最小I帧间隔
    IVS_INT32 iPMaxIFrameInterval; //P制最大I帧间隔
    IVS_INT32 iNMinIFrameInterval; //N制最小I帧间隔
    IVS_INT32 iNMaxIFrameInterval; //N制最大I帧间隔
    IVS_CHAR cReserve[32]; //保留字段
}IVS_IFRAME_INFO;

/*编码类型信息*/
typedef struct
{
    IVS_CHAR cEncodeMode[IVS_DEV_MODEL_LEN];    // 编码类型
    IVS_CHAR cProfileList[IVS_MAX_NAME_LIST_LEN];   // Profile列表,以逗号分隔
    IVS_CHAR cBitRateList[IVS_MAX_NAME_LIST_LEN];  //码率列表,以逗号分隔
    IVS_INT32 iRealNum;    // 列表个数，最大30条
    IVS_IFRAME_INFO stIFrameInfo;   //I帧信息
    IVS_RESOLUTION_INFO stResolution[IVS_MAX_RESOLUTION_LIST_NUM];        // 分辨率列表
    IVS_CHAR cReserve[32]; //保留字段
}IVS_ENCODEMODE_INFO;

/*码流类型结构体*/
typedef struct
{
    IVS_CHAR cStreamType[IVS_FILE_NAME_LEN];  //码流类型
    IVS_INT32 iRealNum;     // 列表个数，最大2条
    IVS_ENCODEMODE_INFO stEncodeMode[IVS_MAX_ENCODE_LIST_NUM]; //编码类型列表
    IVS_CHAR cReserve[32]; //保留字段
}IVS_ST_STREAM_INFO;

/*摄像机码流列表结构体*/
typedef struct
{
    IVS_INT32 iRealNum;                   // 列表个数，最大3条
    IVS_ST_STREAM_INFO stStreamInfo[IVS_MAX_STREAM_LIST_NUM];  // 码流信息列表
    IVS_CHAR cReserve[32]; //保留字段
}IVS_STREAM_INFO_LIST;

/*
 * C30 IVS 解码器专用结构体
 */
#define MAX_DECODER_PORTS   16
typedef struct {
    IVS_UINT32 id;
    IVS_UINT32 uiResolv;     // 分辨率
    IVS_UINT32 uiScreenDiv;  // 分屏数
    IVS_UINT32 uiStreamType; //主辅码流, 不指定:0, 1:主码流， 2:辅助码流1, 3:辅助码流2
    IVS_UINT32 uiChannelID[64];
    IVS_CHAR   ChannelName[64][64];
} DECODER_PORT_CONF;

typedef struct {
    IVS_UINT32 uiNum;
    IVS_UINT32 uiPlayMode;  // 画质优先
    DECODER_PORT_CONF PortConf[MAX_DECODER_PORTS];
} DECODER_PORT_CONF_LIST;

/*
 * C30 解码器需要SMU用户名密码
 */
typedef struct {
    IVS_CHAR SmuIp[64];
    IVS_CHAR SmuUsr[128];
    IVS_CHAR SmuPass[128];
}IVS_TVWALL_SMU_INFO;

typedef struct {
    IVS_UINT32  uiInterval;
    IVS_CHAR    cCamera[IVS_DEV_CODE_LEN + 1];
}IVS_PATROL_CAMERA;


typedef enum
{
    VCN_SERVICE = 0,   //传统盒子产品
    OM_SERVICE =  1,   //OM服务
    SMU_SERVICE = 2,   //SMU服务
    ZOOKEEPER_SERVICE =  3,   //ZOOKEEPER服务
    CENTERDB_SERVICE = 4,   //CENTERDB服务
    MPU_R_SERVICE =  5,   //MPU_R服务
    MPU_T_SERVICE = 6,    //MPU_T服务
    SDK_SERVICE = 7,   //SDK服务
    PCG_SERVICE =  8,   //PCG服务
    TAU_SERVICE = 9,    //TAU服务
    ESIGHT_SERVICE = 10,   //ESIGHT服务

}IVS_CLOUD_SERVICE_TYPE;


// VCN集群类型
typedef enum IVS_CLUSTER_TYPE
{
    IVS_RECORD_CLUSTER = 0, //普通集群
    IVS_TRANSIMIT_CLUSTER = 1, //纯转发集群
    IVS_MIX_CLUSTER = 2,      //混合集群
    IVS_ZK_CLUSTER = 3,      //zk集群
    IVS_INVALID_CLUSTER
} IVS_CLUSTER_TYPE;


typedef struct
{
	IVS_USER_INFO stUserInfo;    //脫脙禄搂禄霉卤戮脨脜脧垄
	IVS_INT32 iOperType;              // 脫脙禄搂脨脜脧垄卤盲赂眉脌脿脨脥拢卢1隆垄脨脗脭枚隆垄2 脡戮鲁媒隆垄 3隆垄脨脼赂脛
	IVS_CHAR	cDomainCode[IVS_DOMAIN_CODE_LEN + 1];	// 卤盲赂眉脫脙禄搂脣霉脭脷脫貌卤脿脗毛
}IVS_USER_NOTIFY;

typedef struct
{
	IVS_USER_GROUP stUserGroup;    //脫脙禄搂脳茅脨脜脧垄
	IVS_INT32 iOperType;              // 脫脙禄搂脨脜脧垄卤盲赂眉脌脿脨脥拢卢1隆垄脨脗脭枚隆垄2 脡戮鲁媒隆垄 3隆垄脨脼赂脛
	IVS_CHAR	cDomainCode[IVS_DOMAIN_CODE_LEN + 1];	// 卤盲赂眉脫脙禄搂脳茅脣霉脭脷脫貌卤脿脗毛
}IVS_USER_GROUP_NOTIFY;



/******************************************************************
 function   : EventCallBack
 description: 事件回调函数(事件通知，异常回调等)
 input      : NA
 output     : iEventType    事件类型;
              pEventBuf     事件数据;
              uiBufSize     buf长度;
              pUserData     用户数据;
 return     : IVS_VOID
*******************************************************************/
typedef IVS_VOID (__SDK_CALL * EventCallBack)(IVS_INT32 iEventType, IVS_VOID* pEventBuf, IVS_UINT32 uiBufSize, IVS_VOID* pUserData);

/******************************************************************
 function   : DownloadCallBackRaw
 description: 拼帧祼码流回调函数(录像下载)
 input      : NA
 output     : ulHandle      播放句柄;
              pRawFrameInfo 裸码流帧类型参数;
              pBuf          帧数据;
              uiBufSize     buf长度;
              pUserData     用户数据;
 return     : IVS_VOID
*******************************************************************/
typedef IVS_VOID (__SDK_CALL * DownloadCallBackRaw)(IVS_ULONG ulHandle, IVS_RAW_FRAME_INFO* pRawFrameInfo, IVS_VOID* pBuf, IVS_UINT32 uiBufSize, IVS_VOID* pUserData);

/******************************************************************
 function   : RealPlayCallBackRaw
 description: 拼帧祼码流回调函数(实况)
 input      : NA
 output     : ulHandle      播放句柄;
              pRawFrameInfo 裸码流帧类型参数;
              pBuf          帧数据;
              uiBufSize     buf长度;
              pUserData     用户数据;
 return     : IVS_VOID
*******************************************************************/
typedef IVS_VOID (__SDK_CALL * RealPlayCallBackRaw)(IVS_ULONG ulHandle, IVS_RAW_FRAME_INFO* pRawFrameInfo, IVS_VOID* pBuf, IVS_UINT32 uiBufSize, IVS_VOID* pUserData);

/******************************************************************
 function   : PlayBackCallBackRaw
 description: 拼帧祼码流回调函数(录像回放)
 input      : NA
 output     : ulHandle      播放句柄;
              pRawFrameInfo 裸码流帧类型参数;
              pBuf          帧数据;
              uiBufSize     buf长度;
              pUserData     用户数据;
 return     : IVS_VOID
*******************************************************************/
typedef IVS_VOID (__SDK_CALL * PlayBackCallBackRaw)(IVS_ULONG ulHandle, IVS_RAW_FRAME_INFO* pRawFrameInfo, IVS_VOID* pBuf, IVS_UINT32 uiBufSize, IVS_VOID* pUserData);

/******************************************************************
 function   : RealPlayCallBackFrame
 description: 获取解码后码流回调函数(实况)
 input      : NA
 output     : ulHandle      播放句柄;
              uiStreamType  帧类型(音频或视频，参考IVS_MEDIA_STREAM);
              pFrameInfo    帧类型参数(视频类型参考IVS_VIDEO_FRAME，音频类型参考IVS_AUDIO_FRAME);
              pUserData     用户数据;
 return     : IVS_VOID
*******************************************************************/
typedef IVS_VOID (__SDK_CALL * RealPlayCallBackFrame)(IVS_ULONG ulHandle, IVS_UINT32 uiStreamType, IVS_VOID* pFrameInfo, IVS_VOID* pUserData);

/******************************************************************
 function   : PlayBackCallBackFrame
 description: 获取解码后码流回调函数(录像回放)
 input      : NA
 output     : ulHandle      播放句柄;
              uiStreamType  帧类型(音频或视频，参考IVS_MEDIA_STREAM);
              pFrameInfo    帧类型参数(视频类型参考IVS_VIDEO_FRAME，音频类型参考IVS_AUDIO_FRAME);
              pUserData     用户数据;
 return     : IVS_VOID
*******************************************************************/
typedef IVS_VOID (__SDK_CALL * PlayBackCallBackFrame)(IVS_ULONG ulHandle, IVS_UINT32 uiStreamType, IVS_VOID* pFrameInfo, IVS_VOID* pUserData);

// 画图回调
typedef IVS_VOID (__SDK_CALL * DRAW_PROC)(IVS_VOID *hDc, IVS_VOID *rc, IVS_UINT64 ullFrameID, IVS_VOID *pUser);


/******************************************************************
 function   : METADATA_PROC
 description: 元数据回调函数
 input      : NA
 output     : uiType 元数据类型，参考IVS_METADATA_CALLBACK_TYPE
              pData  元数据内容，不同类型对应不同元数据结构
              uiLen  元数据长度
              pUser  用户数据;
 return     : IVS_VOID
*******************************************************************/
typedef IVS_VOID (__SDK_CALL * METADATA_PROC)(IVS_UINT32 uiType, IVS_VOID* pData, IVS_UINT32 uiLen, IVS_VOID* pUser);

enum UserSDKEventType
{
    SMU_LOGIN = 1,
    SMU_CONNECT_ERROR,
};
typedef void (* UserSDKCallBack)(int iRet , UserSDKEventType EventType);


/************************************************************************/
/*                                     卡口图片相关SDK                                 */
/************************************************************************/

/*0-由东向西,1-由西向东
2-由南向北,3-由北向南
4-由东南向西北，5-由西北向东南
6-由东北向西南,7-有西南向东北*/
typedef enum enITSDirectionType
{
    ITS_DIR_TYPE_EAST_TO_WAST  = 0,
    ITS_DIR_TYPE_WEST_TO_EAST,
    ITS_DIR_TYPE_SORTH_TO_NORTH,
    ITS_DIR_TYPE_NORTH_TO_SORTH,
    ITS_DIR_TYPE_EASTSOUTH_WESTNORTH,
    ITS_DIR_TYPE_WESTNORTH_EASTSOUTH,
    ITS_DIR_TYPE_EASTNORTH_WESTSOUTH,
    ITS_DIR_TYPE_WESTSOUTH_EASTNORTH,
}ITS_DIRECTION_TYPE_E;

/*检测方式：1-地感触发2-视频触发3-多帧识别4-雷达触发*/
typedef enum enITSDetectType
{

}ITS_DETECT_TYPE_E;

/*车牌颜色:0-白色,1-黄色,2-蓝色,3-黑色,-1-其他*/
typedef enum enITSPlateColor
{
    ITS_PLATE_COLOR_OTHERS = -1,
    ITS_PLATE_COLOR_WHITE = 0,
    ITS_PLATE_COLOR_YELLOW,
    ITS_PLATE_COLOR_BLUE,
    ITS_PLATE_COLOR_BLACK,    
    ITS_PLATE_COLOR_GREEN,//4///
    ITS_PLATE_COLOR_GRADIENT_GREEN,
    ITS_PLATE_COLOR_YELLOW_GREEN,
}ITS_PLATE_COLOR;

/*车牌类型-----待修改同GA24.7有差异*/
typedef enum enITSPlateType
{
    ITS_PLATE_TYPE_NONE = 0,//0-无类型
    ITS_PLATE_TYPE_STANDARD92 = 1, //1-92式民用车
    ITS_PLATE_TYPE_POLICE = 2, //2-警用车
    //3-上下军车
    ITS_PLATE_TYPE_ARMED = 4, //4-92式武警车
    //5-左右军车
    ITS_PLATE_TYPE_PERSONAL = 7, //7-02式个性化车
    //8-黄色双行尾牌
    //9-04式新军车
    ITS_PLATE_TYPE_EMBASSY = 10,//10-使馆车
    //11-一行结构的新WJ车
    //12-两行结构的新WJ车
    ITS_PLATE_TYPE_YELLOW_AGRI = 13, //13-黄色1225农用车
    ITS_PLATE_TYPE_GREEN_AGRI = 14,//14-绿色1325农用车
    //15-黄色1325农用车
    ITS_PLATE_TYPE_MOTO = 16,//16-摩托车
    ITS_PLATE_TYPE_TRAINNING = 100,//100-教练车
    //101-临时行驶车
    //102-挂车
    //103-领馆汽车
    ITS_PLATE_TYPE_SAR = 104,//104-港澳入出车
    //105-临时入境车

}IVS_ITS_PLATE_TYPE;

/*车身颜色江苏320标准*/
//typedef enum enITSVehicleColor
//{
//    ITS_VEHICLE_COLOR_WHITE = 'A',
//    ITS_VEHICLE_COLOR_GRAY = 'B',
//    ITS_VEHICLE_COLOR_YELLOW = 'C',
//    ITS_VEHICLE_COLOR_PINK = 'D',
//    ITS_VEHICLE_COLOR_RED = 'E',
//    ITS_VEHICLE_COLOR_PURPLE = 'F',
//    ITS_VEHICLE_COLOR_GREEN = 'G',
//    ITS_VEHICLE_COLOR_BLUE = 'H',
//    ITS_VEHICLE_COLOR_BROWN = 'I',
//    ITS_VEHICLE_COLOR_BLACK = 'J',
//    ITS_VEHICLE_COLOR_OTHER = 'Z',
//}ITS_VEHICLE_COLOR;

//车身颜色同海康
typedef enum enITSVehicleColor
{
    ITS_VEHICLE_COLOR_UNKNOWN      = -1,//未知
    ITS_VEHICLE_COLOR_UNSUPPORT    = 0, //不支持
    ITS_VEHICLE_COLOR_WHITE             = 1,//白
    ITS_VEHICLE_COLOR_SILVER            = 2,  //银
    ITS_VEHICLE_COLOR_GRAY               = 3,//灰
    ITS_VEHICLE_COLOR_BLACK             = 4,//黑
    ITS_VEHICLE_COLOR_RED                 = 5,//红
    ITS_VEHICLE_COLOR_DARKBLUE      =6,//深蓝
    ITS_VEHICLE_COLOR_BLUE                = 7, //蓝
    ITS_VEHICLE_COLOR_YELLOW           = 8,//黄
    ITS_VEHICLE_COLOR_GREEN             = 9,//绿
    ITS_VEHICLE_COLOR_BROWN           = 10,//棕
    ITS_VEHICLE_COLOR_PINK                = 11,//粉
    ITS_VEHICLE_COLOR_PURPLE            = 12,//紫
    ITS_VEHICLE_COLOR_DARKGRAY      = 13,//深灰
	ITS_VEHICLE_COLOR_ORANGE           = 14,//桔色
	ITS_VEHICLE_COLOR_CYAN                = 15,//青色
	ITS_VEHICLE_COLOR_GOLDEN            = 16,//金色
}ITS_VEHICLE_COLOR;


/*车身颜色深浅*/
typedef enum enITSVehicleColorDepth
{
    ITS_VEHICLE_LIGHT_COLOR = 0,
    ITS_VEHICLE_DEEP_COLOR ,
}ITS_VEHICLE_COLOR_DEPTH;

/*车辆类型识别结果---------同海康一致*/
typedef enum enITSVehicleType
{
    ITS_VEHICLE_TYPE_OTHER      =  0,  //未知
    ITS_VEHICLE_TYPE_BUS        =  1,  //客车(大型)
    ITS_VEHICLE_TYPE_TRUCK      =  2,  //货车(大型)
    ITS_VEHICLE_TYPE_CAR        =  3,  //轿车(小型)
    ITS_VEHICLE_TYPE_MINIBUS    =  4,  //面包车
    ITS_VEHICLE_TYPE_SMALLTRUCK =  5,  //小货车
    ITS_VEHICLE_TYPE_HUMAN      =  6,  //行人
    ITS_VEHICLE_TYPE_TUMBREL    =  7,  //二轮车
    ITS_VEHICLE_TYPE_TRIKE      =  8,  //三轮车
    ITS_VEHICLE_TYPE_SUV_MPV    =  9,  //SUV/MPV
    ITS_VEHICLE_TYPE_MEDIUM_BUS =  10  //中型客车
}ITS_VEHICLE_TYPE;

/*车辆主品牌类型*/
typedef enum enITSVehicleClass
{
    //参考海康VLR_VEHICLE_CLASS
    ITS_VEHICLE_CLASS_OTHER       = 0,    //其它
    ITS_VEHICLE_CLASS_VOLKSWAGEN  = 1,    //大众
    ITS_VEHICLE_CLASS_BUICK       = 2,    //别克
    ITS_VEHICLE_CLASS_BMW         = 3,    //宝马
    ITS_VEHICLE_CLASS_HONDA       = 4,    //本田
    ITS_VEHICLE_CLASS_PEUGEOT     = 5,    //标致
    ITS_VEHICLE_CLASS_TOYOTA      = 6,    //丰田
    ITS_VEHICLE_CLASS_FORD        = 7,    //福特
    ITS_VEHICLE_CLASS_NISSAN      = 8,    //日产
    ITS_VEHICLE_CLASS_AUDI        = 9,    //奥迪
    ITS_VEHICLE_CLASS_MAZDA       = 10,   //马自达
    ITS_VEHICLE_CLASS_CHEVROLET   = 11,   //雪佛兰
    ITS_VEHICLE_CLASS_CITROEN     = 12,   //雪铁龙
    ITS_VEHICLE_CLASS_HYUNDAI     = 13,   //现代
    ITS_VEHICLE_CLASS_CHERY       = 14,   //奇瑞
    ITS_VEHICLE_CLASS_KIA         = 15,   //起亚
    ITS_VEHICLE_CLASS_ROEWE       = 16,   //荣威
    ITS_VEHICLE_CLASS_MITSUBISHI  = 17,   //三菱
    ITS_VEHICLE_CLASS_SKODA       = 18,   //斯柯达
    ITS_VEHICLE_CLASS_GEELY       = 19,   //吉利
    ITS_VEHICLE_CLASS_ZHONGHUA    = 20,   //中华
    ITS_VEHICLE_CLASS_VOLVO       = 21,   //沃尔沃
    ITS_VEHICLE_CLASS_LEXUS       = 22,   //雷克萨斯
    ITS_VEHICLE_CLASS_FIAT        = 23,   //菲亚特
    ITS_VEHICLE_CLASS_EMGRAND     = 24,   //帝豪
    ITS_VEHICLE_CLASS_DONGFENG    = 25,   //东风
    ITS_VEHICLE_CLASS_BYD         = 26,   //比亚迪
    ITS_VEHICLE_CLASS_SUZUKI      = 27,   //铃木
    ITS_VEHICLE_CLASS_JINBEI      = 28,   //金杯
    ITS_VEHICLE_CLASS_HAIMA       = 29,   //海马
    ITS_VEHICLE_CLASS_SGMW        = 30,   //五菱
    ITS_VEHICLE_CLASS_JAC         = 31,   //江淮
    ITS_VEHICLE_CLASS_SUBARU      = 32,   //斯巴鲁
    ITS_VEHICLE_CLASS_ENGLON      = 33,   //英伦
    ITS_VEHICLE_CLASS_GREATWALL   = 34,   //长城
    ITS_VEHICLE_CLASS_HAFEI       = 35,   //哈飞
    ITS_VEHICLE_CLASS_ISUZU       = 36,   //五十铃
    ITS_VEHICLE_CLASS_SOUEAST     = 37,   //东南
    ITS_VEHICLE_CLASS_CHANA       = 38,   //长安
    ITS_VEHICLE_CLASS_FOTON       = 39,   //福田
    ITS_VEHICLE_CLASS_XIALI       = 40,   //夏利
    ITS_VEHICLE_CLASS_BENZ        = 41,   //奔驰
    ITS_VEHICLE_CLASS_FAW         = 42,   //一汽
    ITS_VEHICLE_CLASS_NAVECO      = 43,   //依维柯
    ITS_VEHICLE_CLASS_LIFAN       = 44,   //力帆
    ITS_VEHICLE_CLASS_BESTURN     = 45,   //一汽奔腾
    ITS_VEHICLE_CLASS_CROWN       = 46,   //皇冠
    ITS_VEHICLE_CLASS_RENAULT     = 47,   //雷诺
    ITS_VEHICLE_CLASS_JMC         = 48,   //JMC
    ITS_VEHICLE_CLASS_MG          = 49,   //MG名爵
    ITS_VEHICLE_CLASS_KAMA        = 50,   //凯马
    ITS_VEHICLE_CLASS_ZOTYE       = 51,   //众泰
    ITS_VEHICLE_CLASS_CHANGHE     = 52,   //昌河
    ITS_VEHICLE_CLASS_XMKINGLONG  = 53,   //厦门金龙
    ITS_VEHICLE_CLASS_HUIZHONG    = 54,   //上海汇众
    ITS_VEHICLE_CLASS_SZKINGLONG  = 55,   //苏州金龙
    ITS_VEHICLE_CLASS_HIGER       = 56,   //海格
    ITS_VEHICLE_CLASS_YUTONG      = 57,   //宇通
    ITS_VEHICLE_CLASS_CNHTC       = 58,   //中国重汽
    ITS_VEHICLE_CLASS_BEIBEN      = 59,   //北奔重卡
    ITS_VEHICLE_CLASS_XINGMA      = 60,   //华菱星马
    ITS_VEHICLE_CLASS_YUEJIN      = 61,   //跃进
    ITS_VEHICLE_CLASS_HUANGHAI    = 62,   //黄海
    ITS_VEHICLE_CLASS_OLDWALL     = 63,   //老款长城
    ITS_VEHICLE_CLASS_CHANACOMMERCIAL = 64,   //长安商用
    ITS_VEHICLE_CLASS_USER1       = 65,   //用户1
    ITS_VEHICLE_CLASS_USER2       = 66,   //用户2
    ITS_VEHICLE_CLASS_USER3       = 67,   //用户3
    ITS_VEHICLE_CLASS_USER4       = 68,   //用户4
    ITS_VEHICLE_CLASS_USER5       = 69,   //用户5
    ITS_VEHICLE_CLASS_USER6       = 70,   //用户6
    ITS_VEHICLE_CLASS_USER7       = 71,   //用户7
    ITS_VEHICLE_CLASS_USER8       = 72    //用户8
}ITS_VEHICLE_CLASS;

/*违法信息*/
typedef enum enITSIllegalType
{


}ITS_ILLEGAL_TYPE;

typedef enum _ITS_PICTURE_TYPE
{
    ITS_PICTURE_TYPE_UNKNOW = -1,   // 未知图
    ITS_PICTURE_TYPE_SCENE = 0,     // 场景图
    ITS_PICTURE_TYPE_PLATE = 1,     // 车牌图
    ITS_PICTURE_TYPE_FEATURE = 2,   // 特写图
    ITS_PICTURE_TYPE_FACE_SCENE = 3,	/*人脸场景图*/
    ITS_PICTURE_TYPE_FACE_FEATURE = 4,	/*人脸抠图*/
    ITS_PICTURE_TYPE_HUMAN_FEATURE = 5, /*人体抠图*/
    ITS_PICTURE_TYPE_END
}ITS_PICTURE_TYPE;

//pic_mode只用于人体图的属性
typedef enum _ITS_PICTURE_MODE
{
    ITS_PICTURE_MODE_DEFAULT = 0,   // 默认模式
    ITS_PICTURE_MODE_FEATURE = 1,     // 小图模式
    ITS_PICTURE_MODE_SCENE = 2,     // 大图模式
    ITS_PICTURE_MODE_END
}ITS_PICTURE_MODE;

//分析类型，用于填充发往VCM的probuf中的alarm_type字段
typedef enum _ITS_ALARM_TYPE
{
    ITS_ALARM_TYPE_BA = 0,          // 行为分析
    ITS_ALARM_TYPE_LPR = 1,         // 车牌分析
    ITS_ALARM_TYPE_SYN_AND_INDX = 2,// 视频摘要+索引
    ITS_ALARM_TYPE_INDX = 3,        //索引
    ITS_ALARM_TYPE_FR = 4,          //人脸识别
    ITS_ALARM_TYPE_HUMAN = 5,       //人体识别
    ITS_ALARM_TYPE_LPR_PIC = 6,     //车型识别图片模式
    ITS_ALARM_TYPE_LPR_GPU = 8,     //车牌识别GPU
    ITS_ALARM_TYPE_MIX_STARUCT = 9,
    ITS_ALARM_TYPE_OTHERS
}ITS_ALARM_TYPE;

//需要统计过车流量的统计类型
typedef enum _ITS_QUERY_FLOW_TYPE
{
    ITS_QUERY_FLOW_TYPE_UNKNOW = -1,    /*无效类型*/
    ITS_QUERY_FLOW_TYPE_DIRECTION = 0,     /*方向统计*/
    ITS_QUERY_FLOW_TYPE_VEHICLE_TYPE = 1,     /*车辆类型统计*/
    ITS_QUERY_FLOW_TYPE_END
}ITS_QUERY_FLOW_TYPE;

//查询过车列表分页事，翻页的方向，
typedef enum _ITS_VEHICLE_QUERY_PAGE_DIRECTION
{
    ITS_VEHICLE_QUERY_PAGE_PREVIOUS = -1,    /*上一页*/
    ITS_VEHICLE_QUERY_PAGE_CURRENT = 0,     /*当前页*/
    ITS_VEHICLE_QUERY_PAGE_NEXT = 1,     /*下一页*/
    ITS_VEHICLE_QUERY_PAGE_MULTI = 2,     /*多页跳转，不区分往前还是往后跳转*/
    ITS_VEHICLE_QUERY_PAGE_END
}ITS_VEHICLE_QUERY_PAGE_DIRECTION;

//图片属性
typedef enum _ITS_PIC_ATTRIBUTE
{
    ITS_PIC_ATTRIBUTE_ILLEGAL = -1,    /*不合法*/
    ITS_PIC_ATTRIBUTE_ALL  =  0,
    ITS_PIC_ATTRIBUTE_KAKOU = 1,     /*卡口图片*/
    ITS_PIC_ATTRIBUTE_BACKUP = 2,     /*备份图片*/

}ITS_PIC_ATTRIBUTE;

/*交通抓拍结果车牌信息结构体*/
typedef struct _IVS_ITS_PLATE_INFO
{
    IVS_CHAR    cPlateType;//车牌种类
    IVS_CHAR    cPlateColor;	      //车牌颜色,参考ITS_PLATE_COLOR
    IVS_CHAR    cPlateBelieve;	      //整个车牌可信度
    IVS_CHAR    cReserve[5];          //预留字段。8字节对齐
    IVS_CHAR    cPlateLicense[IVS_PLATE_LEN];    //车牌号码
}ITS_PLATE_INFO, *LP_ITS_PLATE_INFO;

/*车辆信息参数结构体*/
typedef struct _ITS_VEHICLE_INFO
{
    IVS_CHAR    cVehicleType;//车辆类型
    IVS_CHAR    cVehicleColor; 	      //车身颜色
    IVS_CHAR    cVehicleColorDepth;    //车身颜色深浅
    IVS_INT32    cVehicleLogoRecog;     //车辆主品牌,ITS_VEHICLE_CLASS
    IVS_INT32   iVehicleSpeed;	     //车辆速度km/h, 1表示无测速功能
    IVS_INT32   iVehicleLength;    //车身长度单位cm
    IVS_INT32   iCustomIllegalType;//即违法类型，参见GA408.1
    IVS_INT32    cVehicleSubLogoRecog;	//车辆子品牌
    IVS_CHAR    cVehicleModel;	//车辆子品牌2，预留字段
    IVS_CHAR    cVehicleYear[IVS_BRAND_YEAR_LEN];	//车辆年款
    IVS_CHAR    cReserve[6];          //预留字段
}ITS_VEHICLE_INFO, *LP_ITS_VEHICLE_INFO;

//车辆简要信息，用于列表查询
typedef struct _IVS_ITS_VEHICLE_BRIEF_INFO
{
    IVS_INT64   ullID;                //记录ID
    IVS_CHAR    cIPCCode[IVS_DEV_CODE_LEN];    //卡口IPC编码
    IVS_CHAR    cTollGateName[IVS_NAME_LEN]; //卡口IPC所在卡口的名称
    IVS_CHAR    cPlateLicense[IVS_PLATE_LEN+IVS_ADD_SEC_PLATE_LEN];    //车牌号码
    IVS_UINT64  uiSnapTime;  //YYYYMMDDHHMMSSmmm，24小时制（I图像拍摄时间，IPC时间）
    IVS_UINT64  uiUploadTime;  //YYYYMMDDHHMMSSmmm，24小时制（图像上传时间，服务器时间）
    IVS_INT32   iVehicleSpeed;       //车辆速度km/h, 1表示无测速功能
    IVS_CHAR    cVehicleType;        //车辆类型
    IVS_CHAR    cVehicleColor;        //车身颜色
    IVS_INT32   iVehicleLength;    //车身长度单位cm

    IVS_CHAR    cLaneChannel;        //车道编号
    IVS_CHAR    cPlateColor;        //车牌颜色
    IVS_CHAR    cPlateType;         //车牌种类

    IVS_CHAR    cHandleFlage;       //处理标记
    IVS_CHAR    cReserve[7];          //预留字段
    IVS_INT32   iCustomIllegalType;//即违法类型，参见GA408.1
    IVS_UINT64  ullPictureIDs[ITS_PICTURE_TYPE_END];    //抓拍图片对应的ID
    IVS_INT32   iPicAttr;// 0-卡口图片1-备份图片
    IVS_CHAR        cNVRCode[IVS_NVR_CODE_LEN + 1];   // 保存这条记录的所属NVR
}IVS_ITS_VEHICLE_BRIEF_INFO;

//车辆详细信息
typedef struct _IVS_ITS_VEHICLE_INFO
{
    IVS_INT64   ullID;                //记录ID
    IVS_CHAR    cIPCCode[IVS_DEV_CODE_LEN];    //卡口IPC编码
    IVS_CHAR    cTollGateName[IVS_NAME_LEN]; //卡口IPC所在卡口的名称
    IVS_CHAR    cPlateLicense[IVS_PLATE_LEN];    //车牌号码
    IVS_CHAR    cPlateLicenseManual[IVS_PLATE_LEN];        //人工识别车牌号
    IVS_UINT64  uiSnapTime;  //YYYYMMDDHHMMSSmmm，24小时制（I图像拍摄时间，IPC时间）
    IVS_UINT64  uiUploadTime;  //YYYYMMDDHHMMSSmmm，24小时制（图像上传时间，服务器时间）
    IVS_INT32   iVehicleSpeed;       //车辆速度km/h, 1表示无测速功能
    IVS_CHAR    cLaneChannel;        //车道编号
    IVS_CHAR    cVehicleColor;        //车身颜色
    IVS_CHAR    cHandleFlage;    //处理标记
    IVS_CHAR    cRelaLaneDirectionType;              //行驶（车道）方向,参考ITS_DIRECTION_TYPE_E
    ITS_PLATE_INFO    stPlateInfo; //车牌信息
    ITS_VEHICLE_INFO   stVehicleInfo;  //车辆信息
    IVS_CHAR    cReserve[16];          //预留字段

    IVS_UINT64 ullPictureIDs[ITS_PICTURE_TYPE_END];    //抓拍图片对应的ID
    IVS_CHAR        cNVRCode[IVS_NVR_CODE_LEN + 1];   // 保存这条记录的所属NVR
}IVS_ITS_VEHICLE_INFO;

// 过车信息分页查询列表
typedef struct
{
    IVS_UINT32   uiRspCode;                 // 查询响应码
    IVS_UINT32   uiTotal;                    // 总记录数
    IVS_INDEX_RANGE stIndexRange;           // 分页信息
    IVS_UINT64   uiEndTime;             //结果中最大的抓拍时间
    IVS_CHAR cReserve[32];                  //保留字段
    IVS_ITS_VEHICLE_BRIEF_INFO stSubscribeInfo[1];    // 过车简要信息
}IVS_ITS_VEHICLE_LIST;

//查询条件结构体
typedef struct
{
    int iFromIndex;                  //从第几条记录开始返回
    int iToIndex;                    //截止第几条记录
    int iDirection;                  //本次查询的翻页方向，0表示当前页，1表示下一页，-1表示上一页
    int iCursor;            //游标，指示在CU上显示到了哪一条记录用。查询的时候查询从游标起始开始查
    int iAsc;            //默认降序排列iAsc = 0;降序，1升序
    int iPicAttr;            //0-卡口图片1-备份图片 默认0

    IVS_CHAR    cSnapPlace[IVS_NAME_LEN];    //抓拍地点,即卡口名称
    IVS_CHAR    cIPCCode[IVS_DEV_CODE_LEN];   //摄像机编码
    IVS_CHAR    cDirection;        //行驶方向参考ITS_DIRECTION_TYPE_E
    IVS_INT32   iCustomIllegalType;//即违法类型，参见GA408.1

    IVS_CHAR    cVehicleType;        //车辆类型
    IVS_CHAR    cVehicleColor;        //车身颜色

    IVS_CHAR    cLaneChannel;        //车道编号
    IVS_CHAR    cPlateColor;        //车牌颜色
    IVS_CHAR    cPlateType;         //车牌种类
    IVS_CHAR    cPlateLicense[IVS_PLATE_LEN];    //车牌号码

    IVS_CHAR    cHandleFlage;       //处理状态

    IVS_INT32   iVehicleSpeedMin;       //车辆速度km/h区间
    IVS_INT32   iVehicleSpeedMax;       //车辆速度km/h区间

    IVS_UINT64  uiStartTime;  //YYYYMMDDHHMMSSmmm，24小时制开始时间
    IVS_UINT64  uiEndTime;  //YYYYMMDDHHMMSSmmm，24小时制结束时间

}IVS_ITS_VEHICLE_QUERY_INFO;

//单张图片信息结构体
typedef struct
{
    IVS_UINT32      ulPicBufLen;       //图片缓冲区长度
    IVS_UINT32      ulPicLen;       //单张图片长度
    IVS_UINT64      ullPictureID;    //图片对应的ID
    IVS_UINT64      ullSnapTime;    //图片对应的抓拍时间
    IVS_CHAR        cNVRCode[IVS_NVR_CODE_LEN + 1];   // 保存图片的NVR编码
    IVS_CHAR*       pPictureBuf;    //图片数据
}IVS_IMG_STORE_INFO;

//单张图片信息结构体
typedef struct
{
    IVS_CHAR        cDomainCode[IVS_DOMAIN_CODE_LEN + 1];	// 域编码
    IVS_CHAR        cClusterCode[IVS_CLUSTER_CODE_LEN + 1];   // 保存图片的集群编码，此编码仅在保存图片到集群场景下使用，仅作为入参用
    IVS_CHAR        cNVRCode[IVS_NVR_CODE_LEN + 1];   // 保存图片的NVR编码，此编码在保存图片到堆叠场景下保存图片到指定NVR上使用，仅作为入参用
}IVS_IMG_STORE_NVR_INFO;

typedef enum _ITS_MOVE_DIRECT
{
    IVS_DIRECT_UNKNOWN = 0,
    IVS_DIRECT_FORWARD,
    IVS_DIRECT_BACKWARD,
}ITS_MOVE_DIRECT;

typedef enum _ITS_MOVE_SPEED
{
    IVS_SPEED_UNKNOWN = 0,
    IVS_SLOW,
    IVS_FAST,
}ITS_MOVE_SPEED;

/*人体属性结构体*/
typedef struct _ITS_HUMAN_ATTRIBUTES_INFO
{
    IVS_INT32 iIsVaild;

    //IVS_INT32 定义的属性 0 代表 未知，1-n依次代表后面的属性具体含义
    IVS_INT32 iAge;                        // 年龄 {少年,青年,老年} 
    IVS_INT32 igender;                     // 性别{男，女}
    IVS_INT32 iUpperStyle;                 // 上衣款式 {长袖，短袖} 
    IVS_INT32 iUpperColor;                 // 上衣颜色 {黑，蓝，绿，白/灰，黄/橙/棕，红/粉/紫}  
    IVS_INT32 iUpperTexture;               // 上衣纹理 {纯色，条纹} 
    IVS_INT32 iLowerStyle;                 // 下衣款式 {长裤,短裤}      
    IVS_INT32 iLowerColor;                 // 下衣颜色 {黑，蓝，绿，白/灰，黄/橙/棕，红/粉/紫}  
    IVS_INT32 iShape;                      // 体型{standard, fat, thin}
    IVS_INT32 iMouthmask;                  // 口罩{no,yes}  
    IVS_INT32 iHair;                       // 发型{ long, short }
    IVS_INT32 iBackpack;                   // 背包{no,yes} 
    IVS_INT32 iCarry;                      // 是否拎东西{no,yes}
    IVS_INT32 iSatchel;                    // 斜挎包{no,yes} 
    IVS_INT32 iUmbrella;                   // 雨伞{no,yes}
    IVS_INT32 iFrontpack;                  // 前面背包{no,yes}
    IVS_INT32 iLuggage;                    // 行李箱{no,yes} 

    ITS_MOVE_DIRECT eMoveDirect;           // 行进方向{direct_unknow,forward,backward}
    ITS_MOVE_SPEED  eMoveSpeed;            // 行进速度{speed_unknow,slow,fast}
}ITS_HUMAN_ATTRIBUTES_INFO, *LP_ITS_HUMAN_ATTRIBUTES_INFO;



typedef struct _HW_ITS_VEHICLE_INFO
{
    IVS_INT32   iIPCId;
    IVS_CHAR    cMainDevCode[32];			//主设备编码
    IVS_CHAR    cRelaLaneDirectionType;  	//行驶（车道）方向,参考ITS_DIRECTION_TYPE_E
    IVS_CHAR    cLaneChannel;        		//车道编号
    IVS_CHAR    cSnapPhotoNum;    			//采集的照片数量，0表示无照片         
    IVS_CHAR    cHandleFlage;    			//处理标记
    IVS_UINT64  uiSnapTime;  				//YYYYMMDDHHMMSSmmm，24小时制（图像拍摄时间）
    IVS_UINT64  uiUploadTime;  				//YYYYMMDDHHMMSSmmm，24小时制（图像存储的时间，获取当前时间）

    ITS_PLATE_INFO     stPlateInfo; 		//车牌信息
    ITS_VEHICLE_INFO   stVehicleInfo;  		//车辆信息
    IVS_CHAR    cPlateLicenseManual[IVS_PLATE_LEN];   //人工识别车牌号

    IVS_UINT64   iAlarmArmID;				//布控编号
    IVS_CHAR     cAlarmArmInfoNum;    		//布控代码 1-被盗车2-被抢车3-交通违法车4-紧急查控车
    IVS_CHAR	 cTriggerType; 				//触发方式
    IVS_INT32   iPicAttr;// 0-全部类型1-卡口图片2-备份图片
    ITS_HUMAN_ATTRIBUTES_INFO stHumanAttrInfo; //人体属性信息    
    IVS_CHAR    cHumanPhotoNum;             //采集的人体数量   

    IVS_CHAR    cReserve[6];          		//预留字段
}HW_ITS_VEHICLE_INFO;

typedef struct _HW_ITS_VEHICLE_INFO_IN_DB
{
    IVS_CHAR    cMainDevCode[32];			//主设备编码
    IVS_CHAR    cRelaLaneDirectionType;  	//行驶（车道）方向,参考ITS_DIRECTION_TYPE_E
    IVS_CHAR    cLaneChannel;        		//车道编号     
    IVS_CHAR    cHandleFlage;    			//处理标记 
    IVS_CHAR    cPlateLicenseManual[IVS_PLATE_LEN];   //人工识别车牌号
    IVS_CHAR     cAlarmArmInfoNum;    		//布控代码 1-被盗车2-被抢车3-交通违法车4-紧急查控车
    IVS_CHAR	 cTriggerType; 				//触发方式
    IVS_CHAR    cVehicleType;//车辆类型
    IVS_CHAR    cVehicleColor; 	      //车身颜色
    IVS_CHAR    cVehicleColorDepth;    //车身颜色深浅
    IVS_CHAR    cPlateType;//车牌种类
    IVS_CHAR    cPlateColor;	      //车牌颜色,参考ITS_PLATE_COLOR
    IVS_CHAR    cPlateBelieve;	      //整个车牌可信度
    IVS_CHAR    cPlateLicense[IVS_PLATE_LEN];    //车牌号码
    IVS_CHAR    cVehicleModel;	//车辆子品牌2，预留字段
    IVS_INT32   iPicAttr;// 0-全部类型1-卡口图片2-备份图片
    IVS_INT32    cVehicleLogoRecog;     //车辆主品牌,ITS_VEHICLE_CLASS
    IVS_INT32   iVehicleSpeed;	     //车辆速度km/h, 1表示无测速功能
    IVS_INT32   iVehicleLength;    //车身长度单位cm
    IVS_INT32   iCustomIllegalType;//即违法类型，参见GA408.1
    IVS_INT32    cVehicleSubLogoRecog;	//车辆子品牌
    IVS_UINT64  uiSnapTime;  				//YYYYMMDDHHMMSSmmm，24小时制（图像拍摄时间）
    IVS_UINT64  uiUploadTime;  				//YYYYMMDDHHMMSSmmm，24小时制（图像存储的时间，获取当前时间）
    IVS_INT64   llPicIdScene;  				//大图ID
    IVS_INT64   llPicIdPlate;  				//车牌小图ID
    IVS_INT64   llPicIdFeature;  			//车辆小图ID
    IVS_UCHAR   ucClosed;               //备份元数据是否完整 0--完整  1--不完整
    IVS_CHAR    cReserve[3];          //预留字段。8字节对齐
}HW_ITS_VEHICLE_INFO_IN_DB;

/*图片信息*/
typedef struct _ITSSnapPictureInfo
{
    IVS_INT32 iPicType;    /*图片类型。参见_ITS_PICTURE_TYPE*/
    IVS_UINT32 iPicLen;     /*图片长度*/
    IVS_UINT64 ulPicFileID; /*图片对应的fileID*/
    IVS_UCHAR* ptrPicBuffer; /*图片数据*/
}ITS_SNAP_PICTURE_INFO;

typedef struct
{
    IVS_CHAR cDeviceCode[IVS_DEV_CODE_LEN + 1];             //子设备编码
    IVS_CHAR cDeviceName[IVS_NAME_LEN];                     //子设备名称
    IVS_CHAR cLongitude[IVS_LONGITUDE_LATITUDE_LEN + 1];    //经度
    IVS_CHAR cLatitude[IVS_LONGITUDE_LATITUDE_LEN + 1];     //纬度
    IVS_CHAR cLocation[IVS_DESCRIBE_LEN + 1];           //位置
    IVS_CHAR cReserve[32];
}IVS_DEVICE_LAL_INFO;

typedef struct _TLVSnapPictureInfo
{
    IVS_INT32  iPicType;    /*图片类型。参见_ITS_PICTURE_TYPE*/
    IVS_UINT32 iPicLen;     /*图片长度*/
    IVS_UINT32 iPicPos;     /*图片在TLV中的位置*/
    IVS_UINT64 uiSnapTime;  //YYYYMMDDHHMMSSmmm，24小时制（图像拍摄时间）
    IVS_UINT64 ulPicFileID; /*图片对应的fileID*/
    IVS_CHAR   cPictureURL[IVS_URL_LEN];		/*图片URL. 空表示无效URL*/
}TLV_SNAP_PICTURE_INFO;

typedef struct
{
    //IVS_UINT32          uiSequence;
    IVS_DEVICE_LAL_INFO stDeviceLalInfo;
    IVS_CHAR            cReserve[32];
}IVS_DEVICE_LAL_OPER_INFO;

typedef struct
{
    IVS_CHAR    cDeviceCode[IVS_DEV_CODE_LEN + 1];
    IVS_UINT32  uiResult;
    IVS_CHAR    cReserve[32];
}IVS_DEVICE_LAL_OPER_RESULT;

typedef struct
{
    IVS_UINT32                  uiTotal;
    IVS_DEVICE_LAL_OPER_RESULT  stCodeInfo[1];
}IVS_DEVICE_LAL_OPER_RESULT_LIST;


/*数据通道消息*/
#define IVS_DC_MESSAGE_LEN 1024
#define IVS_IMGU_URL_LEN 1024
#define IVS_AES_KEY      256
#define IVS_DC_MESSAGE_MAGIC 0x13579BDF
#define IVS_DC_MESSAGE_RSP_CODE 0x9000


//数据通道消息类型，响应消息为0x07xx + 0x9000
typedef enum _IVS_DC_MESSAGE_TYPE
{
    IVS_DC_MESSAGE_TYPE_CLOSE = 0x0700,                  //关闭数据通道
    IVS_DC_MESSAGE_TYPE_KEEPALIVE = 0x0701,          //数据通道保活
    IVS_DC_MESSAGE_TYPE_VALIDATION = 0x0702,     //URL验证
    IVS_DC_MESSAGE_TYPE_DOWNLOAD = 0x0703,    //下载图片
    IVS_DC_MESSAGE_TYPE_UPLOAD = 0x0704, //上传图片
    IVS_DC_MESSAGE_TYPE_DOWNLOAD_METADATA = 0x0705, //批量下载元数据
    IVS_DC_MESSAGE_TYPE_UPLOAD_METADATA = 0x0706, //上传元数据+图片
    IVS_DC_MESSAGE_TYPE_REQUIRE_METADATA_NUM = 0x0707,//查询结构化数据条目
    IVS_DC_MESSAGE_TYPE_DOWNLOAD_HISTORY_TLV =0x0708,//下载历史结构化数据
    IVS_DC_MESSAGE_TYPE_DOWNLOAD_REALTIME_TLV  =0x0709,//实时下载结构化数据
    IVS_DC_MESSAGE_TYPE_DOWNLOAD_TLV = 0x0710,       //实时和历史统一响应消息
    IVS_DC_MESSAGE_TYPE_DOWNLOAD_SINGLE_SUCCESS = 0x0715,
    IVS_DC_MESSAGE_TYPE_UPLOAD_AES256_KEY  = 0x0716, //加密密钥数据
    IVS_DC_MESSAGE_TYPE_HIGHSPEED_HISTORY_TLV  =0x0717,//高速下载拉流
    IVS_DC_MESSAGE_TYPE_END
}IVS_DC_MESSAGE_TYPE;

typedef struct _IVS_DC_MESSAGE_HEAD
{
    IVS_INT32 iMagic;
    IVS_INT32 iCmd;         //参见IVS_DC_MESSAGE_TYPE
    IVS_INT32 iMsgLen;  //消息总长度，包括IVS_DC_MESSAGE_HEAD
    IVS_CHAR cPayload[1];//消息内容。长度为iMsgLen-sizeof(IVS_DC_MESSAGE_HEAD)
}IVS_DC_MESSAGE_HEAD;

typedef struct _IVS_DC_MESSAGE_VALIDATION
{
    IVS_CHAR cURL[IVS_IMGU_URL_LEN];
}IVS_DC_MESSAGE_VALIDATION;

typedef struct _IVS_DC_MESSAGE_AESKEY
{
    IVS_CHAR AesKey[IVS_AES_KEY];
}IVS_DC_MESSAGE_AESKEY;

typedef struct _IVS_DC_MESSAGE_DOWNLOAD_REQ
{
    IVS_UINT64 ullPictureIDs[1];    //抓拍图片对应的ID
    IVS_UINT64 ullSnapTime[1];		//抓拍图片的时间
    IVS_CHAR   cNVRCode[IVS_NVR_CODE_LEN + 1];   // 保存图片的NVR编码
}IVS_DC_MESSAGE_DOWNLOAD_REQ;

typedef struct _IVS_DC_MESSAGE_DOWNLOAD_RSP
{
    IVS_UINT64 ullPictureID;    //图片对应的ID
    IVS_CHAR cPictureBuf[1];    //图片数据
}IVS_DC_MESSAGE_DOWNLOAD_RSP;

typedef struct _IVS_DC_MESSAGE_METADATA_DOWNLOAD_REQ
{
    IVS_UINT32 uiXmlLength;
    IVS_CHAR cPictureBuf[1];    //请求XML的数据
}IVS_DC_MESSAGE_METADATA_DOWNLOAD_REQ;

typedef struct _IVS_DC_MESSAGE_METADATA_UPLOAD_REQ
{
    IVS_ITS_VEHICLE_BRIEF_INFO stVehicleInfo;
    IVS_UINT32 uiPicNum;
    IVS_CHAR cPictureBuf[1];    //图片内存地址
}IVS_DC_MESSAGE_METADATA_UPLOAD_REQ;

//数据通道的通用响应，IVS_SUCCEED表示成功
typedef struct _IVS_DC_MESSAGE_COMMON_RSP
{
    IVS_INT32 iRspCode;
}IVS_DC_MESSAGE_COMMON_RSP;

typedef struct
{
	IVS_CHAR        cDomainCode[IVS_DOMAIN_CODE_LEN + 1];     // 域编码
	IVS_CHAR        cNVRCode[IVS_NVR_CODE_LEN + 1];           // NVR编码,二选一
	IVS_CHAR        cClusterCode[IVS_CLUSTER_CODE_LEN + 1];   // 集群编码,二选一
}IVS_NVR_INFO;

/*图片下载回调*/
typedef IVS_INT32 (*HW_PICUTRE_DOWNLOAD_CALLBACK) (IVS_UINT64 ullFileID, IVS_CHAR* pPictureBuffer, IVS_UINT32 iPictureLen);

/*图片上传回调*/
typedef IVS_INT32 (*HW_PICUTRE_UPLOAD_CALLBACK) (IVS_UINT64 ullFileID);

/*图片上传回调*/
typedef IVS_INT32 (*HW_METADATA_UPLOAD_CALLBACK) (IVS_INT32 iRspCode);

typedef enum _IVS_IMG_TYPE
{
    IMG_TYPE_COMMON     =0, // 普通
    IMG_TYPE_HUMAN_FACE =1, // 人脸
    IMG_TYPE_CAR_NUMBER =2, // 车牌
    IMG_TYPE_VHD        =4  //机非人
}IVS_IMG_TYPE;
typedef enum _IVS_SNAPSHOT_PICTURE_TYPE
{
    IVS_SNAPSHOT_TYPE_UNKNOW = -1,    /*未知图*/
    IVS_SNAPSHOT_TYPE_RESERVE = 0,     /*场景图*/
    IVS_SNAPSHOT_TYPE_FACE = 1,     /*人脸图*/
    IVS_SNAPSHOT_TYPE_END
}IVS_SNAPSHOT_PICTURE_TYPE;

typedef enum _IVS_SNAPSHOT_DATA_TAG_TYPE
{
    IVS_SNAPSHOT_DATA_TAG_TYPE_UNKNOW = 0,    /*未知*/
    IVS_SNAPSHOT_DATA_TAG_TYPE_FACE_FEATURE = 1,     /*人脸特征值*/
    IVS_SNAPSHOT_DATA_TAG_TYPE_VEHICLE = 2,
    IVS_SNAPSHOT_DATA_TAG_TYPE_HUMAN_FEATURE = 3,    /*人体特征值*/
    IVS_SNAPSHOT_DATA_TAG_TYPE_END
}IVS_SNAPSHOT_DATA_TAG_TYPE;

//抓拍图片坐标信息
typedef struct
{
    IVS_LONG    left;
    IVS_LONG    top;
    IVS_LONG    right;
    IVS_LONG    bottom;
}IVS_RECT;

//单张抓拍图片信息结构体
typedef struct
{
    IVS_UINT32      ulPicBufLen;    //图片缓冲区长度
    IVS_UINT32      ulPicLen;       //单张图片实际长度
    IVS_UINT64      ullPictureID;   //图片对应的ID,上传时作为返回参数
    IVS_CHAR        cPictureURL[IVS_URL_LEN];		//图片URL. 空表示无效URL
    IVS_CHAR*       pPictureBuf;    //图片数据
}IVS_SNAPSHOT_IMG_INFO;

//人脸抓拍结构化信息
typedef struct _IVS_FACE_META_INFO
{
    IVS_UINT64  ullSnapTime;		//图片抓拍时间YYYYMMDDHHMMSSmmm，24小时制（I图像拍摄时间，IPC时间）
    IVS_RECT    stFaceBox;			//抓拍图片坐标信息
    ITS_PICTURE_TYPE eITSType;		//抓拍图片类型
    IVS_UINT32	uiSnapshotGroup;	//抓拍图片组别标识
    IVS_CHAR    cReserved[220];		//预留扩展
}IVS_FACE_META_INFO;

//人脸抓拍图片信息
typedef struct
{
    IVS_FACE_META_INFO stFaceInfo;		//单张人脸抓拍图片信息结构体
    IVS_SNAPSHOT_IMG_INFO stSnapImg;	//单张人脸抓拍结构化数据
}IVS_FACE_SNAPSHOT_IMG_INFO;

//人脸抓拍信息
typedef struct
{
    IVS_CHAR cNVRCode[IVS_NVR_CODE_LEN + 1];    //图片所在NVR编码,上传时作为返回参数
    IVS_CHAR cCameraCode[IVS_DEV_CODE_LEN + 1];	//上传图片的设备编码
    IVS_CHAR cSnapExtraInfo[IVS_SNAPSHOT_EXTRA_INFO_LEN];
    IVS_INT32 iPicNum;							//上传图片张数
    IVS_FACE_SNAPSHOT_IMG_INFO stSnapInfo[1];	//人脸抓拍图片信息
}IVS_FACE_SNAPSHOT_INFO;
typedef struct
{
    IVS_UINT32 uiMetaDataStreamType;//获取元数据流类型，0--结构化数据+图片，1--结构化数据，2--图片，3--抠图
    IVS_CHAR   cReserve[28];
}IVS_METADATA_PARAM;

//typedef struct _TLVSnapPictureInfo
//{
//    IVS_INT32  iPicType;    /*图片类型。参见_ITS_PICTURE_TYPE*/
//    IVS_UINT32 iPicLen;     /*图片长度*/
//    IVS_UINT32 iPicPos;     /*图片在TLV中的位置*/
//    IVS_UINT64 uiSnapTime;  //YYYYMMDDHHMMSSmmm，24小时制（图像拍摄时间）
//    IVS_UINT64 ulPicFileID; /*图片对应的fileID*/
//}TLV_SNAP_PICTURE_INFO;

//使用IVS_SDK_DownloadImgEx下载图片时需使用图片ID.
//图片URL通常为http URL,通过HTTP协议下载.
//VCN当前版本只支持图片ID下载图片,图片存储在第三方系统时,图片ID为0,VCM通过图片URL下载图片.
typedef struct
{
    ITS_PICTURE_TYPE uiPictureType;	//图片类型
    IVS_UINT32 uiPicLen;            //图片长度
    IVS_UINT32 uiPicPos;            //图片在TLV中的位置
    IVS_UINT64 uiSnapTime;          //YYYYMMDDHHMMSSmmm，24小时制（图像拍摄时间）
    IVS_UINT64 ullPictureID;		//图片ID
    IVS_CHAR   cPictureURL[IVS_URL_LEN];		//图片URL. 空表示无效URL
}TLV_PIC_INFO;

typedef struct _IVS_METADATA_INFO
{
    IVS_CHAR cNVRCode[IVS_NVR_CODE_LEN + 1];    //图片所在NVR编码,回调时作为返回参数
    IVS_CHAR cCameraCode[IVS_DEV_CODE_LEN + 1]; //图片所属摄像机子设备编码
    IVS_CHAR cSnapExtraInfo[IVS_SNAPSHOT_EXTRA_INFO_BASE64_LEN]; //base6编码后会变长,预留50%
    IVS_UINT64 uiUploadTime;        //图片上传时间
    IVS_UINT32 iPicNum;              //回调图片个数
    TLV_PIC_INFO stPicInfo[1];
}IVS_METADATA_INFO;

typedef struct _IVS_DC_MESSAGE_TLV_DOWNLOAD_RSP
{
    IVS_METADATA_INFO stMetadataInfo;    //TLV对应的图片偏移信息
    IVS_CHAR cPictureBuf[1];    //TLV数据
}IVS_DC_MESSAGE_TLV_DOWNLOAD_RSP;
typedef struct
{
    IVS_METADATA_PARAM stMetadataParam;
    IVS_TIME_SPAN   stTimeSpan;
} IVS_METADATA_PLAYBACK_PARAM;

typedef struct
{
    IVS_CHAR cCameraCode[IVS_DEV_CODE_LEN + 1];	//上传图片的设备编码
    IVS_METADATA_PLAYBACK_PARAM stPlayBackParam;
}IVS_DC_MESSAGE_DOWNLOAD_HISTORY_TLV_REQ;
typedef struct
{
    IVS_CHAR cCameraCode[IVS_DEV_CODE_LEN + 1];	//上传图片的设备编码
    IVS_METADATA_PARAM stMetadataParam;
}IVS_DC_MESSAGE_DOWNLOAD_REALTIME_TLV_REQ;

//图片以及元数据留存期
typedef struct
{
    IVS_UINT32  uiMetadataTTL;	    // 图片以及元数据留存期
	IVS_UINT32  uIsSaveImage;		// 图片是否保存;
    IVS_CHAR    cReserve[28];
}IVS_METADATA_POLICY_TIME;
typedef IVS_VOID (__SDK_CALL *HW_METADATA_CALLBACK)(IVS_ULONG ulHandle, IVS_METADATA_INFO* pMetadataInfo, IVS_VOID* pBuf, IVS_UINT32 uiBufSize, IVS_INT32 iRspCode, IVS_VOID* pUserData, bool bIsBackUp, int iAllTrnNoAllStore);


/// 需求IVS平台隐私保护支持不规则四边形 zMX538106///
#define IVS_MAX_VIDEO_MASK_POINT_NUM 16   /// 最大隐私保护区域的边的数量，必须是闭合区域即可///
typedef struct
{
	IVS_FLOAT	fPointPosX;              ///X轴坐标点///
	IVS_FLOAT	fPointPosY;              ///Y轴坐标点///
}IVS_TRAPREZIFORM_FLOAT;
/// 不规则四边形隐私保护///
typedef struct
{
	IVS_UINT32 uiPolygonNum;     ///不规则图形的边数量,不规则四边形4个，移动侦测及遮挡设置可根据配置的数量确定，最大不能超过16///
	IVS_TRAPREZIFORM_FLOAT stCoordinate[IVS_MAX_VIDEO_MASK_POINT_NUM];             ///不规则图形的点坐标数据///
}IVS_TRAPREZIFORM_COORDINATE;

typedef struct
{
	IVS_BOOL    bEnableVideoMask;                                                  /// 0-关闭隐私保护，1-启用隐私保护///
	IVS_UINT32  uiAreaNum;                                                         /// 实际设置的不规则四边形图像遮挡告警区域个数///
	IVS_TRAPREZIFORM_COORDINATE    stTrapeziformArea[IVS_MAX_VIDEO_MASK_AREA_NUM]; /// 不规则四边形图像遮挡告警区域数组///

	IVS_CHAR	cReserve[32];                                                      ///备用///
}IVS_VIDEO_TRAPREZIFORM_MASK;

//手动迁移SDK
typedef struct
{
	IVS_CHAR     cDevCode[IVS_DEV_CODE_LEN];
	IVS_CHAR     cOrginalNvrCode[IVS_NVR_CODE_LEN + 1];
	IVS_CHAR     cTargetNvrCode[IVS_NVR_CODE_LEN + 1];
	IVS_CHAR     cReserve[64];
} IVS_SHIFT_DEVICE_INFO;

//手动迁移SDK
typedef struct
{
	IVS_CHAR     cDevCode[IVS_DEV_CODE_LEN];
	IVS_CHAR     cNvrCode[IVS_NVR_CODE_LEN + 1];
	IVS_UINT32	 uiResult;	// 操作结果
	IVS_CHAR     cReserve[64];
}IVS_SHIFT_DEVICE_OPER_RESULT_INFO;

//手动迁移SDK
typedef struct
{
	IVS_UINT32	    uiTotal;
	IVS_CHAR        cReserve[64];
	IVS_SHIFT_DEVICE_OPER_RESULT_INFO stShiftResultInfo[1];
}IVS_SHIFT_DEVICE_OPER_RESULT;

//手动迁移SDK
typedef struct
{
	IVS_UINT32      uiNum;         // 总记录数
	IVS_CHAR        cReserve[64];
	IVS_SHIFT_DEVICE_INFO stShiftDeviceInfo[1];
} IVS_SHIFT_DEVICE_LIST_INFO;

typedef enum _IVS_GET_DOMAIN_TYPE
{
    IVS_DOMAIN_BOTH=0,
    IVS_DOMAIN_LOCAL=1,
    IVS_DOMAIN_EXTERNAL=2,
    IVS_DOMAIN_INVALID
}IVS_GET_DOMAIN_TYPE;

typedef struct
{
    IVS_CHAR	cDomainCode[IVS_DOMAIN_CODE_LEN+1];	// 查询域编码
    IVS_CHAR	cGroupIDCode[IVS_GROUP_CODE_LEN+1];
    IVS_BOOL    bGetExDomain;                       //0-查询本域    1-查询外域
    IVS_BOOL    bIncludeSubGroup;                   //是否查询子组 0-只查询当前组   1-查询当前组及其子组
    IVS_CHAR    cReserve[128];
}IVS_GROUP_QUERY_INFO;

typedef struct
{
    IVS_QUERY_UNIFIED_FORMAT* pQueryFormat;         //搜索接口暂不支持分页查询，stIndex无需填写
    IVS_GET_DOMAIN_TYPE  uiGetDomainType;
    IVS_UINT32  uiMaxQueryNum;                      //搜索最大记录数
    IVS_CHAR    cReserve[128];
}IVS_SUBDEV_QUERY_INFO;

/* tagIvsIpcCoordinateCommunitySumInfo
 * @brief 协同集摘要信息
 * @notes 无
 */
typedef struct tagIvsIpcCoordinateCommunitySumInfo
{
    /* 协同集ID, 添加时填0, 会在添加结果中返回 */
    IVS_UINT64  duiCommunityId;
    /* 协同集名称 */
    IVS_CHAR    szCommunityName[IVS_NAME_LEN];
    /* 协同集所属域编码 */
    IVS_CHAR    szBelongDomainCode[IVS_DOMAIN_CODE_LEN + 1];
    /* 入口IPC编码 */
    IVS_CHAR    szEntryIpcCode[IVS_DEV_CODE_LEN + 1];
    /* 告警阈值上限 */
    IVS_FLOAT   fWarningUpperThresholdRate;
    /* 告警阈值下限 */
    IVS_FLOAT   fWarningLowerThresholdRate;
    /* 最大预警数量 */
    IVS_UINT32  uiMaxWarningCompareNum;
    /* 是否使能 */
    IVS_BOOL    bIsCommunityEnable;
    /* 预留字段 */
    IVS_CHAR    szReserved[128];
}IVS_IPC_COORDINATE_COMMUNITY_SUM_INFO;

/* tagIvsCoordinateCommunityIpcInfo
 * @brief 协同集中IPC信息
 * @notes 无
 */
typedef struct tagIvsCoordinateCommunityIpcInfo
{
    /* IPC编码 */
    IVS_CHAR    szIpcCode[IVS_DEV_CODE_LEN + 1];
    /* IPC名称 */
    IVS_CHAR    szIpcName[IVS_NAME_LEN];
    /* 是否入口IPC */
    IVS_BOOL    bIsEntryIpc;
    /* 预留字段 */
    IVS_CHAR    szReserved[128];
}IVS_COORDINATE_COMMUNITY_IPC_INFO;

/* tagIvsIpcCoordinateCommunityFullInfo
 * @brief 单个协同集完整信息
 * @notes 无
 */
typedef struct tagIvsIpcCoordinateCommunityFullInfo
{
    /* 协同集摘要信息 */
    IVS_IPC_COORDINATE_COMMUNITY_SUM_INFO stCommunitySumInfo;
    /* 协同集中IPC的实际总数量, 包括入口IPC */
    IVS_UINT32 uiRealIpcNum;
    /* 协同集IPC成员列表信息, 实际数量由uiRealIpcNum字段决定 */
    IVS_COORDINATE_COMMUNITY_IPC_INFO astCommunityIpcInfo[IVS_MAX_IPC_NUM_IN_COORDINATE_COMMUNITY];
}IVS_IPC_COORDINATE_COMMUNITY_FULL_INFO;

// 元数据回调类型
typedef enum
{
    IVS_METADATA_TRACE_LIST = 1,                 // 枪球联动目标框信息，对应结构体IVS_TRACE_LIST
    IVS_METADATA_CALLBACK_TYPE_INVALID
}IVS_METADATA_CALLBACK_TYPE;

// 枪球联动相机协议
typedef enum
{
    IVS_DEVICE_LINKAGE_FIX_CAMERA = 0,                // 枪球联动
    IVS_DEVICE_LINKAGE_PANORAMIC_CAMERA = 1,           // 全景球相机联动
    IVS_DEVICE_LINKAGE_INVALID
}IVS_DEVICE_LINKAGE_TYPE;

// 枪球联动跟踪类型
typedef enum
{
    IVS_DETECT_TRACE = 1,                // 检测跟踪
    IVS_TARGET_TRACE = 2,                // 目标跟踪
    IVS_EVENT_TRACE = 3,                 // 事件跟踪
    IVS_TRACE_INVALID
}IVS_TRACE_TYPE;

typedef struct _IVS_LINKAGE_INFO
{
    IVS_BOOL    bTrackEnable;                  //跟踪开关
    IVS_BOOL    bManualPosEnable;              //手动定位开关
    IVS_BOOL    bLinkageEnable;                //是否配置联动开关，该参数当前仅用于查询
    IVS_CHAR    szReserved[64];
}IVS_LINKAGE_INFO;

typedef struct _IVS_RECT_INFO
{
    IVS_UINT32  uiLinkageType;                  //联动类型 : 0-点击联动； 1-框选联动
    IVS_RECT    stRectPercent;                  //框选坐标百分比
    IVS_UINT32  uiRectDirection;                //框选方向 : 0-从左上到右下，表示放大；1-从右下到左上，表示缩小
    IVS_CHAR    szReserved[64];
}IVS_RECT_INFO;

typedef struct _IVS_MANUAL_POS_INFO
{
    IVS_UINT32  uiDeviceType;                  //设备类型 : 见IVS_DEVICE_LINKAGE_TYPE
    IVS_RECT_INFO stRectInfo;                  //框选/点选信息
    IVS_CHAR    szReserved[128];
}IVS_MANUAL_POS_INFO;

typedef struct _IVS_MANUAL_TRACE_INFO
{
    IVS_UINT32  uiDeviceType;                  //设备类型 : 见IVS_DEVICE_LINKAGE_TYPE
    IVS_RECT_INFO stRectInfo;                  //框选/点选信息
    IVS_UINT32  uiTraceID;                     //跟踪目标ID
    IVS_CHAR    szReserved[128];
}IVS_MANUAL_TRACE_INFO;


typedef struct _IVS_TRACE_INFO
{
    IVS_UINT32  uiObjectID;                     //目标ID
    IVS_RECT    stRectInfo;
    IVS_UINT32  uiTraceType;                    //参见IVS_TRACE_TYPE
    IVS_CHAR    szReserved[64];
}IVS_TRACE_INFO;

typedef struct _IVS_TRACE_LIST
{
    IVS_UINT32  uiNum;
    IVS_CHAR    szReserved[64];
    IVS_TRACE_INFO stTraceInfo[1];
}IVS_TRACE_LIST;
#pragma pack(pop)
#endif //_HW_IVS_SDK_H_
