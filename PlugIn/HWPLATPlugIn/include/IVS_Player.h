/********************************************************************
filename    :    IVS_Player.h
author      :    
created     :    2012/11/12
description :    IVS���ſ�ӿ�
copyright   :    Copyright (c) 2012-2016 Huawei Tech.Co.,Ltd
history     :    2012/11/12 ��ʼ�汾
*********************************************************************/
#ifndef __IVS_PLAYER_H__
#define __IVS_PLAYER_H__

#include "IVS_PlayerTypes.h"

#ifdef IVS_PLAYER_EXPORTS
# define IVS_PLAYER_API extern "C" __declspec(dllexport)
#else
# define IVS_PLAYER_API extern "C" __declspec(dllimport)
#endif


/*****************************************************************************
 �������ƣ�IVS_PLAY_Init
 ������������ʼ��;
 ���������const char* pLogPath
 ���������NA
 �� �� ֵ���ɹ�:IVS_SUCCEED; ʧ��:IVS_FAIL;
*****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_Init(const char* pLogPath);

/*****************************************************************************
 �������ƣ�IVS_PLAY_UnInit
 ���������������;
 ���������NA
 ���������NA
 �� �� ֵ��NA
*****************************************************************************/
IVS_PLAYER_API void __stdcall IVS_PLAY_UnInit();

/*****************************************************************************
 �������ƣ�IVS_PLAY_GetChannel
 ������������ȡ���õ�ý��ͨ����;
 ���������NA
 ���������pChannel  ͨ����;
 �� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
*****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_GetChannel(HDL_PLAY* pChannel);

/*****************************************************************************
 �������ƣ�IVS_PLAY_FreeChannel
 �����������ͷ�ָ����ý��ͨ����;
 ���������ulChannel  ͨ����;
 ���������NA
 �� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
*****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_FreeChannel(HDL_PLAY ulChannel);

/***************************************************************************
 �� �� �� : IVS_PLAY_SetExceptionCallBack
 �������� : �����쳣�ص�����;
 ������� : cbExceptionCallBack        �쳣�ص�����;
            pUser                      �û�����;
 ������� : NA
 �� �� ֵ : �ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
***************************************************************************/
IVS_PLAYER_API void __stdcall IVS_PLAY_SetExceptionCallBack(PLAYER_EXCEPTION_CALLBACK cbExceptionCallBack, void* pUser);


/***************************************************************************
 �� �� �� : IVS_PLAY_SetExceptionCallBack
 �������� : �����¼��ص�����;
 ������� : ulChannel                  ͨ����
			cbExceptionCallBack        �쳣�ص�����;
            pUser                      �û�����;
 ������� : NA
 �� �� ֵ : �ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
***************************************************************************/
IVS_PLAYER_API void __stdcall IVS_PLAY_SetEventCallback(HDL_PLAY ulChannel, PLAYER_EVENT_CALLBACK cbExceptionCallBack, void* pUser);

/***************************************************************************
 �� �� �� : IVS_PLAY_MetadataCallBack
 �������� : ����Ԫ���ݻص�����;
 ������� : ulChannel                  ͨ����
			callback                   Ԫ���ݻص�����;
            pUser                      �û�����;
 ������� : NA
 �� �� ֵ : �ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
***************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_SetMetadataCallBack(HDL_PLAY ulChannel, METADATA_CALLBACK  callback, void *pUser);

/*****************************************************************************
 �������ƣ�IVS_PLAY_OpenStream
 ��������������ͨ��;
 ���������ulChannel  ͨ����;
           StreamParam  ������;
           uBufferSize ��������С;
 ���������NA
 �� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
 *****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_OpenStream(HDL_PLAY ulChannel, IVS_STREAM_PARAM *StreamParam, unsigned int uBufferSize);

/*****************************************************************************
 �������ƣ�IVS_PLAY_UpdateStream
 ����������������������
 ���������ulChannel  ͨ����;
           StreamParam  ������;
           uBufferSize ��������С;
 ���������NA
 �� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
 *****************************************************************************/
IVS_PLAYER_API int __stdcall  IVS_PLAY_UpdateStream(HDL_PLAY ulChannel, IVS_STREAM_PARAM *StreamParam, unsigned int uBufferSize); 


/*****************************************************************************
 �������ƣ�IVS_PLAY_CloseStream
 �����������ر���ͨ��;
 ���������ulChannel ͨ����;
 ���������NA
 �� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
*****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_CloseStream(HDL_PLAY ulChannel);

/*****************************************************************************
 �������ƣ�IVS_PLAY_StartPlay
 ������������������;
 ���������ulChannel ͨ����;
           HWND   ���ھ��;
           HwAccel  1/0 ����(�ر�)GPU�������           
 ���������NA
 �� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
*****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_StartPlay(HDL_PLAY ulChannel, HWND hWnd, int HwAccel);

/*****************************************************************************
 �������ƣ�IVS_PLAY_StopPlay
 ����������ֹͣ����;
 ���������ulChannel ͨ����;
 ���������NA
 �� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
*****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_StopPlay(HDL_PLAY ulChannel);

/*****************************************************************************
 �������ƣ�IVS_PLAY_PausePlay
 ������������ͣ����
 ���������ulChannel ͨ����;
 ���������NA
 �� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
*****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_PausePlay(HDL_PLAY ulChannel);

/*****************************************************************************
 �������ƣ�IVS_PLAY_ResumePlay
 �����������ָ�����
 ���������ulChannel ͨ����;
 ���������NA
 �� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
*****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_ResumePlay(HDL_PLAY ulChannel);

/*****************************************************************************
 �������ƣ�IVS_PLAY_SetPlaySpeed
 �������������ò����ٶ�
 ���������ulChannel ͨ����;
			dSpeed   �����ٶ�;
 ���������NA
 �� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
*****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_SetPlaySpeed(HDL_PLAY ulChannel, double dSpeed);

/*****************************************************************************
 �������ƣ�IVS_PLAY_StepPlayForward
 ������������������ǰ��
 ���������ulChannel ͨ����;
 ���������NA 
 �� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
*****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_StepPlayForward(HDL_PLAY ulChannel);

/*****************************************************************************
 �������ƣ�IVS_PLAY_StepPlayBackward
 �����������������ź���
 ���������ulChannel ͨ����;
 ���������NA
 �� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
*****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_StepPlayBackward(HDL_PLAY ulChannel);

/*****************************************************************************
 �������ƣ�IVS_PLAY_PlaySound
 ����������������Ƶ����;
 ���������ulChannel ͨ����;
 ���������NA
 �� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
*****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_PlaySound(HDL_PLAY ulChannel);

/*****************************************************************************
 �������ƣ�IVS_PLAY_StopSound
 ����������ֹͣ��Ƶ����;
 ���������ulChannel ͨ����;
 ���������NA
 �� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
*****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_StopSound(HDL_PLAY ulChannel);

/*****************************************************************************
 �������ƣ�IVS_PLAY_SetVolume
 ����������������Ƶ��������;
 ���������ulChannel ͨ����;
           uiVolumeValue ����
 ���������NA
 �� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
*****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_SetVolume(HDL_PLAY ulChannel, unsigned int uiVolumeValue);

/*****************************************************************************
 �������ƣ�IVS_PLAY_GetVolume
 ������������ȡ��Ƶ��������;
 ���������ulChannel ͨ����;
 ���������uiVolumeValue ����
 �� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
*****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_GetVolume(HDL_PLAY ulChannel, unsigned int* puiVolumeValue);

/*****************************************************************************
 �������ƣ�IVS_PLAY_SetFrameCallBack
 �������������������ص�;
 ���������ulChannel           ͨ����;
           CallBack  �ص�����ָ��;
           pUser             �û�����;
 ���������NA
 �� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
*****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_SetFrameCallBack(HDL_PLAY ulChannel, FRAME_CALLBACK CallBack, void *pUser);

/*****************************************************************************
 �������ƣ�IVS_PLAY_SetFrameCallBack
 �������������ý���֡���ݻص�;
 ���������ulChannel           ͨ����;
           CallBack    �ص�����ָ��;
           pUser               �û�����;
 ���������NA
 �� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
*****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_SetDecodeCallBack(HDL_PLAY ulChannel, DECODE_CALLBACK CallBack, void *pUser);

/*****************************************************************************
 �������ƣ�IVS_PLAY_SetDisplayFrameCallBack
 ����������������Ⱦ֡���ݻص�;
 ���������ulChannel           ͨ����;
           CallBack    �ص�����ָ��;
           pUser               �û�����;
 ���������NA
 �� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
*****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_SetDisplayCallBack(HDL_PLAY ulChannel, DISPLAY_CALLBACK CallBack, void *pUser);

/*****************************************************************************
 �������ƣ�IVS_PLAY_SetBufferStateCallback
 ����������������������ص�;
 ���������ulChannel  ͨ����;
           callback   �ص�����ָ��;
           pUser       �û�����;
 ���������NA
 �� �� ֵ��NA
*****************************************************************************/
IVS_PLAYER_API void __stdcall IVS_PLAY_SetBufferStateCallback(HDL_PLAY ulChannel, BUFFER_STATUS_CALLBACK CallBack, void *pUser);

/*****************************************************************************
 �������ƣ�IVS_PLAY_AddPlayWindow
 �������������ò��Ŵ��ھ��
 ���������ulChannel ͨ����;
	       IVS_HANDLE�� ��Ⱦͨ�����
	       hWnd��       ���ھ��
	       nType��      ��Ⱦ��������
	       pLayout��    ���ڲ��ֲ���
 ���������NA
 �� �� ֵ��int
****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_AddPlayWindow(HDL_PLAY ulChannel, HWND hWnd, int nType, void *pLayout);

/*****************************************************************************
 �������ƣ�IVS_PLAY_AddPlayWindowPartial
 �������������Ӿֲ�ͼ�񲥷Ŵ���
 ���������ulChannel ͨ����;
	       hWnd ��Ⱦͨ�����
	       hWnd��       ���ھ��
	       pPartial��   �ֲ�ͼƬ����
 ���������NA
 �� �� ֵ��int
****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_AddPlayWindowPartial(HDL_PLAY ulChannel, HWND hWnd, LAYOUT_DRAW_PARTIAL *pPartial);

/*****************************************************************************
 �������ƣ�IVS_PLAY_UpdateWindowPartial
 �������������¾ֲ��Ŵ�Դ����
 ���������ulChannel ͨ����
	       hWnd��       ���ھ��
	       pPartial��   �ֲ�����
 ���������NA
 �� �� ֵ��int
****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_UpdateWindowPartial(HDL_PLAY ulChannel, HWND hWnd, LAYOUT_DRAW_PARTIAL *pPartial);

/*****************************************************************************
 �������ƣ�IVS_PLAY_DelPlayWindow
 ����������ɾ�����Ŵ��ھ��
 ���������ulChannel ͨ����;
	       hWnd��    ���ھ��
 ���������NA
 �� �� ֵ��int
****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_DelPlayWindow(HDL_PLAY ulChannel, HWND hWnd);

/*****************************************************************************
 �������ƣ�IVS_PLAY_SetDisplayAspectRatio
 ������������ͨ���ʹ���������Ƶ��ʾ����
 ���������ulChannel:    ͨ����;
		   uiScale:       ��ʾ����  1 ԭʼ 2 ����
 ���������NA
 �� �� ֵ��int
****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_SetDisplayAspectRatio(HDL_PLAY ulChannel, unsigned int uiScale);

/*****************************************************************************
 �������ƣ�IVS_PLAY_InputRtpData
 �����������򲥷ſ�����RTP��;
 ���������ulChannel    ͨ����;
           pBuf         ����;
		   ulSize       �����С;
 ���������NA
 �� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
 *****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_InputRtpData(HDL_PLAY ulChannel, char *pBuf, unsigned int uiSize);

IVS_PLAYER_API int __stdcall IVS_PLAY_InputEos(HDL_PLAY ulChannel);

/*****************************************************************************
 �������ƣ�IVS_PLAY_InputFrameData
 �����������򲥷ſ�����֡����(����Ƶ);
 ���������ulChannel    ͨ����;
           pFrameInfo   ֡������Ϣ;
		   pFrame       ֡����
		   uFrameSize   ֡���ݳ���
 ���������NA
 �� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
 *****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_InputFrameData(HDL_PLAY ulChannel, IVS_FRAME_INFO* pFrameInfo, char* pFrame, unsigned int uFrameSize);

/*****************************************************************************
 �������ƣ�IVS_PLAY_OpenFile
 �������������ļ�;
 ���������ulChannel    ͨ����;
 ���������pFileName    �ļ���;
 ���������NA
 �� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
*****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_OpenFile(HDL_PLAY ulChannel, const char* pFileName);

/*****************************************************************************
 �������ƣ�IVS_PLAY_SetFileTimeRange
 ���������������ļ�����ʱ�䷶Χ
 ���������ulChannel  ͨ����;
           beg        ��ʼʱ��
           end        ����ʱ��
 ���������NA
 �� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
*****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_SetFileTimeRange(HDL_PLAY ulChannel, unsigned int beg, unsigned int end);

/*****************************************************************************
 �������ƣ�IVS_PLAY_CloseFile
 �������������ļ�;
 ���������ulChannel    ͨ����;
 ���������NA
 �� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
*****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_CloseFile(HDL_PLAY ulChannel);

/*****************************************************************************
 �������ƣ�IVS_SetWaterMarkVerify()
 �������������ÿ���/ֹͣУ��ˮӡ
 ���������ulChannel ͨ����:  
         ��iStart 0-��ʼУ�飬1-ֹͣУ��
 ���������NA
 �� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
 *****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_SetWaterMarkVerify(HDL_PLAY ulChannel, int iStart);

/*****************************************************************************
 �������ƣ�IVS_PLAY_GetMediaInfo()
 ������������ȡ��Ƶ��������
 ���������ulChannel ͨ����:  
 ���������pMediaInfo ��Ƶ��������
 �� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
 *****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_GetMediaInfo(HDL_PLAY ulChannel, IVS_PLAY_STATUS* pMediaInfo);

/*****************************************************************************
 �������ƣ�IVS_PLAY_GetLostPacketRate()
 ������������ȡ��ǰ����ʱ��
 ���������ulChannel ͨ����
 ���������puPlayTime ��ǰ����ʱ��
 �� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
 *****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_GetPlayedTime(HDL_PLAY ulChannel,unsigned long long *puPlayTime);

/*****************************************************************************
 �������ƣ�IVS_PLAY_GetCurrentFrameTick
 ������������ȡ��ǰ֡ʱ���
 ���������ulChannel ͨ����
 ���������pTick ��ǰʱ���
 �� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
 *****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_GetCurrentFrameTick(HDL_PLAY ulChannel, unsigned long long *pTick);

/*****************************************************************************
 �������ƣ�IVS_PLAY_SetPlayTime
 �������������ò���ʱ��
 ���������ulChannel ͨ����
			tm ����ʱ��
 �� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
 *****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_SetPlayTime(HDL_PLAY ulChannel, time_t tm);

/*****************************************************************************
 �������ƣ�IVS_PLAY_SetDownLoadTimeSpan
 ������������������ʱ�䷶Χ
 ���������ulChannel ͨ����
		   tmBeg   ��ʼʱ��
		   tmEnd   ֹͣʱ��
		   bReportFinsh �Ƿ��ϱ�
 �� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
 *****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_SetDownLoadTimeSpan(HDL_PLAY ulChannel, time_t tmBeg, time_t tmEnd, int bReportFinsh);


/*****************************************************************************
 �������ƣ�IVS_PLAY_SetPlayQualityMode()
 ��������������ʵ������ģʽ������������
 ���������ulChannel ͨ����
		   iPlayQualityMode ����ģʽ
 ���������NA
 �� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
 *****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_SetPlayQualityMode(HDL_PLAY ulChannel,int iPlayQualityMode);

/*****************************************************************************
 �������ƣ�IVS_PLAY_SetDisplayDelay()
 �������������ò�����ʱ�����������øú���
 ���������ulChannel ͨ����
		   uMs  ����
 ���������NA
 �� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
 *****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_SetDisplayDelay(HDL_PLAY ulChannel, unsigned int uMs);


/*****************************************************************************
 �������ƣ�IVS_PLAY_SetDisplayBufferFrameMaxNum()
 �������������ò�������󻺴�����֡��
 ���������ulChannel ͨ����
		   uMs  ����
 ���������NA
 �� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
 *****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_SetDisplayBufferFrameMaxNum(HDL_PLAY ulChannel, unsigned int uFrameNum);


/*****************************************************************************
 �������ƣ�IVS_PLAY_ShowPlayStatis()
 �������������Ž�����ʾͳ����Ϣ
 ���������ulChannel  ͨ����
		   hWnd       ���ھ��
		   enable     �Ƿ�ʹ��
 ���������NA
 �� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
 *****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_ShowPlayStatis(HDL_PLAY ulChannel, HWND hWnd, int enable);

/*****************************************************************************
 �������ƣ�IVS_PLAY_ResetData
 �����������������;
 ���������ulChannel    ͨ����;
 ���������NA
 �� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
 *****************************************************************************/
IVS_PLAYER_API void __stdcall IVS_PLAY_ResetData(HDL_PLAY ulChannel);

/*****************************************************************************
 �������ƣ�IVS_PLAY_SetResetFlag
 �������������ø�λ���;
 ���������ulChannel    ͨ����;
		   bIsReset  �Ƿ�λ
 ���������NA
 �� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
 *****************************************************************************/
IVS_PLAYER_API void __stdcall IVS_PLAY_SetResetFlag(HDL_PLAY ulChannel, bool bIsReset);

/*****************************************************************************
 �������ƣ�IVS_PLAY_StartRecord
 ������������ʼ¼��
 ���������ulChannel ͨ����
		   pCamCode  �������
		   pCamName  �������
		   pName     �ļ���
		   pParameter ����¼�����ò���
		   bAssociatedAudio �Ƿ�Ϊ�������
 ���������NA
 �� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
 *****************************************************************************/
IVS_PLAYER_API int IVS_PLAY_StartRecord(HDL_PLAY ulChannel, const char *pCamCode, const char *pCamName, 
	                  const char *pName, const IVS_LOCAL_RECORD_CONFIG *pParameter, bool bAssociatedAudio);

/*****************************************************************************
�������ƣ�IVS_PLAY_StopRecord
����������ֹͣ¼��
���������ulChannel ͨ����
���������NA
�� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
*****************************************************************************/
IVS_PLAYER_API  int IVS_PLAY_StopRecord(HDL_PLAY ulChannel);

/*****************************************************************************
�������ƣ�IVS_PLAY_GetRecordStatis
������������ȡ¼����Ϣ
���������ulChannel ͨ����
���������pTime ¼��ʱ��
		  pSpeed ¼������
		  pTotalSz ¼���С
�� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
*****************************************************************************/
IVS_PLAYER_API int IVS_PLAY_GetRecordStatis(HDL_PLAY ulChannel, 
	        unsigned int *pTime, unsigned int *pSpeed, unsigned long long *pTotalSz);

/*****************************************************************************
 �������ƣ�IVS_PLAY_Snapshot
 ��������������ץ�ĵ���ͼƬ
 ���������pSavePath		ͼƬ����·����
		   ulSnapshotFormat	ͼƬ��������
 ���������NA
 �� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
 *****************************************************************************/
IVS_PLAYER_API int IVS_PLAY_Snapshot(HDL_PLAY ulChannel, const char *pSavePath, unsigned long ulSnapshotFormat);

/*****************************************************************************
 �������ƣ�IVS_PLAY_SnapshotRect
 ��������������ץ�ĵ���ͼƬ
 ���������pSavePath			ͼƬ����·����
		   ulSnapshotFormat	ͼƬ��������
		   Rct   ����λ����Ϣ
 ���������NA
 �� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
 *****************************************************************************/
IVS_PLAYER_API int IVS_PLAY_SnapshotRect(HDL_PLAY ulChannel, const char *pSavePath, unsigned long ulSnapshotFormat, const RECT *Rct);

/*****************************************************************************
 �������ƣ�IVS_PLAY_SetDrawCallBack
 �������������û�ͼ�ص�
 ���������ulChannel  ͨ����
           Callback   �ص�����
           pUser      �û�����
 ���������NA
 �� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
 *****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_SetDrawCallBack(HDL_PLAY ulChannel, DRAW_CALLBACK Callback, void *pUser);

/*****************************************************************************
 �������ƣ�IVS_PLAY_SetDrawCallBack
 �������������û�ͼ�ص���չ�ӿ�
 ���������ulChannel  ͨ����
		   hWnd       ���ھ��
           Callback   �ص�����
           pUser      �û�����
 ���������NA
 �� �� ֵ���ɹ�:IVS_SUCCEED;ʧ��:IVS_FAIL;
 *****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_SetDrawCallBackEx(HDL_PLAY ulChannel, HWND hWnd, DRAW_CALLBACK callback, void *pUser);

/*****************************************************************************
 �������ƣ�IVS_PLAY_StartAudioCapture
 �������������������ɼ�
 ��������� ulChannel  ͨ����
			conf       ����ץ�����ò���
			Callback   �ص�����
			pUser      �û�����
 �����������
 �� �� ֵ�� ULONG
 *****************************************************************************/
IVS_PLAYER_API int  __stdcall IVS_PLAY_StartAudioCapture(
	                            HDL_PLAY ulChannel,
	                            AUDIO_CAPTURE_CONF *conf,
	                            AUDIO_CAPTURE_CALLBACK Callback, 
	                            void *pUser
	                            );
								
/*****************************************************************************
 �������ƣ�IVS_PLAY_StopAudioCapture
 ����������ֹͣ�����ɼ�
 ��������� ulChannel  ͨ����
 �����������
 �� �� ֵ�� ULONG
 *****************************************************************************/
IVS_PLAYER_API void __stdcall IVS_PLAY_StopAudioCapture(HDL_PLAY ulChannel);


/*****************************************************************************
 �������ƣ�IVS_PLAY_StartAudioCapture
 ������������ȡ��Ƶ����ص�
 ��������� ulChannel  ͨ����
			pFileName  �ļ�����
			bLoop   �Ƿ�ѭ��
			conf      ����ץ�����ò���
			Callback  �ص�����
			pUser     �û�����
 �����������
 �� �� ֵ�� ULONG
 *****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_StartFileAudioCapture (
                                HDL_PLAY ulChannel,
                                const char *pFileName,
                                int bLoop,
                                AUDIO_CAPTURE_CONF *conf,
	                            AUDIO_CAPTURE_CALLBACK Callback, 
	                            void *pUser
	                           );

/*****************************************************************************
 �������ƣ�IVS_PLAY_StopFileAudioCapture
 ����������ֹͣ��Ƶ����ص�
 ��������� ulChannel  ͨ����
 �����������
 �� �� ֵ�� ULONG
 *****************************************************************************/
IVS_PLAYER_API  void __stdcall IVS_PLAY_StopFileAudioCapture(HDL_PLAY ulChannel);




/*****************************************************************************
 �������ƣ�IVS_PLAY_SetWaitForVertiBlank
 �������������ô�ֱͬ��ʹ��
 ���������ulChannel  ͨ����
			bEnable    �Ƿ�ʹ��
 �����������
 �� �� ֵ�� int
*****************************************************************************/
IVS_PLAYER_API  int __stdcall IVS_PLAY_SetWaitForVertiBlank(HDL_PLAY ulChannel, int bEnable);


/*****************************************************************************
 �������ƣ�IVS_PLAY_SetVideoEffect
 ����������������Ƶ����
 ���������ulChannel  ͨ����
		   lBright     ������
           lContrast	�Աȶ�
		   lSaturation  ���Ͷ�
		   lHue     ɫ��
 �����������
 �� �� ֵ��int
*****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_SetVideoEffect(
                                  HDL_PLAY ulChannel,
                                  long lBright,
								  long lContrast,
								  long lSaturation, 
								  long lHue);




/*****************************************************************************
 �������ƣ�IVS_PLAY_EnableOptimization
 �������������������Ż�
 ���������iEnable  ������ʶ
 �����������
 �� �� ֵ��int
*****************************************************************************/
IVS_PLAYER_API int __stdcall IVS_PLAY_EnableOptimization(HDL_PLAY ulChannel, int iEnable);

#endif //__IVS_PLAYER_H__

