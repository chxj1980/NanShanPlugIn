/********************************************************************
	filename	: 	IVSSDKNetKeyBoardDef.h
	author		:	
	created		:	2011/10/29	
	description	:	提供IVSSDKNetKeyBoardDef中需要暴露给第三方使用的数据类型（IVSSDKNetKeyBoardDef接口中需要用到的数据类型）
	copyright	:	Copyright (C) 2011-2015
	history		:	2011/10/29 初始版本
*********************************************************************/
#ifndef IVS_SDK_NET_KEY_BOARD_DEF_H
#define IVS_SDK_NET_KEY_BOARD_DEF_H


enum KB_MSG_TYPE {
    KB_MSG_PTZ_STOP = 0,
    KB_MSG_PTZ_UP,
    KB_MSG_PTZ_DOWN,
    KB_MSG_PTZ_LEFT,
    KB_MSG_PTZ_RIGHT,
    KB_MSG_PTZ_LEFT_UP,
    KB_MSG_PTZ_RIGHT_UP,
    KB_MSG_PTZ_LEFT_DOWN,
    KB_MSG_PTZ_RIGHT_DOWN,
    KB_MSG_ZOOM_IN,
    KB_MSG_ZOOM_OUT,

    KB_MSG_FOCUS_IN,
    KB_MSG_FOCUS_OUT,

	KB_MSG_USE_PRESET,   // 调用预置位
    KB_MSG_SET_PRESET, // 设置预置位

    KB_MSG_CAPTURE,  // 截图
    KB_MSG_RECORD,   // 录像
    KB_MSG_DISPLAY,  // 预览(上墙或cu本地预览)
    KB_MSG_WINSWITCH  // 预览(上墙或cu本地预览)

};

typedef struct 
{
   int type;   // 命令类型, enmu KB_MSG_TYPE
   int mon;    // 显示通道号(0 cu界面 >0 电视墙)
   int window; // 窗格号
   int cam;    // 摄像机编号

   int speed;  // 摇杆移动速度
   int preset; // 预置位编号
   int ptzpara; // ptz参数

   int recctl;  // 录像操作
   int recpara;  // 录像参数

   
     
   long reserve1;  // 保留1
   long reserve2;  // 保留2
} KEY_BOARD_MSG;




typedef int (__stdcall *LPCallBack)(int iKeyValue,int iSpeedFirst,int iSpeedSecond, bool bTvWall, KEY_BOARD_MSG *kb_msg);


#endif //IVS_SDK_NET_KEY_BOARD_DEF_H
