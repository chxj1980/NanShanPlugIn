/********************************************************************
	filename	: 	IVSSDKNetKeyBoardDef.h
	author		:	
	created		:	2011/10/29	
	description	:	�ṩIVSSDKNetKeyBoardDef����Ҫ��¶��������ʹ�õ��������ͣ�IVSSDKNetKeyBoardDef�ӿ�����Ҫ�õ����������ͣ�
	copyright	:	Copyright (C) 2011-2015
	history		:	2011/10/29 ��ʼ�汾
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

	KB_MSG_USE_PRESET,   // ����Ԥ��λ
    KB_MSG_SET_PRESET, // ����Ԥ��λ

    KB_MSG_CAPTURE,  // ��ͼ
    KB_MSG_RECORD,   // ¼��
    KB_MSG_DISPLAY,  // Ԥ��(��ǽ��cu����Ԥ��)
    KB_MSG_WINSWITCH  // Ԥ��(��ǽ��cu����Ԥ��)

};

typedef struct 
{
   int type;   // ��������, enmu KB_MSG_TYPE
   int mon;    // ��ʾͨ����(0 cu���� >0 ����ǽ)
   int window; // �����
   int cam;    // ��������

   int speed;  // ҡ���ƶ��ٶ�
   int preset; // Ԥ��λ���
   int ptzpara; // ptz����

   int recctl;  // ¼�����
   int recpara;  // ¼�����

   
     
   long reserve1;  // ����1
   long reserve2;  // ����2
} KEY_BOARD_MSG;




typedef int (__stdcall *LPCallBack)(int iKeyValue,int iSpeedFirst,int iSpeedSecond, bool bTvWall, KEY_BOARD_MSG *kb_msg);


#endif //IVS_SDK_NET_KEY_BOARD_DEF_H
