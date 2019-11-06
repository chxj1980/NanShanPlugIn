#pragma once
//V1.5 �汾    (��V1.4�汾һ��ͷ�ļ�)
#include "NVSSDKDef.h"


class IDVRHandler
{
public:
/***********************�����ӿ�***********************************/

    //************************************
    // Method:    connectDVR    ����DVR
    // Returns:   bool          �����Ƿ�ɹ�
    // Parameter: char * sIP    IP��ַ
    // Parameter: int nPort     DVR�˿ں�
    // Parameter: char * sUser  �û���
    // Parameter: char * sPwd   ����
    // Parameter: int nChannel  ͨ����
    //************************************
    virtual bool connectDVR(char* sIP,int nPort,char* sUser,char* sPwd,int nChannel)=0;

    //************************************
    // Method:    connectDVREx                    ����DVR
    // Returns:   bool                            �����Ƿ�ɹ�
    // Parameter: PCONNECT_PARAM pCParam          �����ṹ���������������ӿ�ͬ
    //************************************
    virtual bool connectDVREx(PCONNECT_PARAM pCParam) = 0;

    //************************************
    // Method:    disconnectDVR ��DVR�Ͽ�����
    // Returns:   void
    //************************************
    virtual void disconnectDVR()=0;

    //************************************
    // Method:    freeLoginInfo     ɾ����½��Ϣ
    // Returns:   void
    //************************************
    virtual void freeLoginInfo()=0;

    //************************************
    // Method:    checkDVR         ���DVR״̬
    // Returns:   LONG             ����0��ʾDVR��½�ɹ�������ֵΪDVR��ͨ����  -1��ʾDVR��½ʧ��
    // Parameter: char * sIP       DVR��IP��ַ
    // Parameter: int nPort        DVR�˿�
    // Parameter: char * sUser     �û���
    // Parameter: char * sPwd      ����
    // Parameter: CLInfo pInfo[]   ���ڱ���ͨ���������Ϣ
    // Parameter: int nMaxCount    ���ͨ����
    //************************************
    virtual LONG checkDVR(char* sIP, int nPort, char* sUser, char* sPwd,CLInfo pInfo[],int nMaxCount)=0;

    //************************************
    // Method:    checkDVREx                         ���DVR״̬
    // Returns:   LONG                               ����0��ʾDVR��½�ɹ�������ֵΪDVR��ͨ����  -1��ʾDVR��½ʧ��
    // Parameter: PCONNECT_PARAM pCParam             �����ṹ���������������ӿڲ�࣬ͨ���ſ���Ϊ��
    // Parameter: CLInfo pInfo[]                     ���ڱ���ͨ���������Ϣ
    // Parameter: int nMaxCount                      ���ͨ����
    //************************************
    virtual LONG checkDVREx(PCONNECT_PARAM pCParam,CLInfo pInfo[],int nMaxCount)=0;

    //************************************
    // Method:    setDVR           ����DVRͼƬ�����ַ���ز���
    // Returns:   void
    // Parameter: char * sIP       DVR��IP��ַ
    // Parameter: int nPort        DVR�˿�
    // Parameter: char * sUser     �û���
    // Parameter: char * sPwd      ����
    // Parameter: CLInfo pInfo[]   ���ڱ���ͨ���������Ϣ
    // Parameter: int nInfoCount   �������
    //************************************
    virtual void setDVR(char* sIP, int nPort, char* sUser, char* sPwd,CLInfo pInfo[],int nInfoCount)=0;

    //************************************
    // Method:    setDVREx                                   ����DVRͼƬ�����ַ���ز���
    // Returns:   void
    // Parameter: PCONNECT_PARAM pCParam                     �����ṹ���������������ӿڲ�࣬ͨ���ſ���Ϊ��
    // Parameter: CLInfo pInfo[]                             ���ڱ���ͨ���������Ϣ
    // Parameter: int nInfoCount                             �������
    //************************************
    virtual void setDVREx(PCONNECT_PARAM pCParam,CLInfo pInfo[],int nInfoCount)=0;

    //************************************
    // Method:    releaseHandler    ɾ�����
    // Returns:   void
    //************************************
    virtual void releaseHandler()=0;

    //************************************
    // Method:    captureStream                              ��ʼԶ�̲��Ų���DVRȡ��
    // Returns:   bool                                       �����ɹ����
    // Parameter: LPCAPTURESTREAMCALLBACK lpCallBack         ȡ���ص�����
    // Parameter: void * pUser                               �û�ָ�룬�������ֵ������ĸ����������
    // Parameter: int nGetVideoType                          ��������
    //************************************
    virtual bool captureStream(LPCAPTURESTREAMCALLBACK lpCallBack, void* pUser, int nGetVideoType)=0;

    //************************************
    // Method:    captureStreamEx                            ��ʼԶ�̲��Ų���DVRȡ��
    // Returns:   bool                                       �����ɹ����
    // Parameter: PCAPTURE_PARAM pParam                      �����ṹ���������������ӿ�ͬ
    //************************************
    virtual bool captureStreamEx(PCAPTURE_PARAM pParam)=0;

    //************************************
    // Method:    stopCaptureStream     ֹͣ
    // Returns:   bool
    //************************************
    virtual bool stopCaptureStream()=0;

    //************************************
    // Method:    getRecordFileEx                       ��ȡ��ʷ��Ƶ����Ϣ
    // Returns:   int                                   С��0ʧ�� ����0 ��ʷ��Ƶ��
    // Parameter: int nType                             ��ʷ��Ƶ����
    // Parameter: char * startTime                      ��Ƶ��ʼʱ��
    // Parameter: char * endTime                        ��Ƶ����ʱ��
    // Parameter: RECORDFILE pRecordFile[]              ��Ƶ��Ϣ����
    // Parameter: int nMaxFileCount                     ����ȡ��Ƶ��
    //************************************
    virtual int getRecordFileEx(int nType,char* startTime,char* endTime,RECORDFILE pRecordFile[],int nMaxFileCount)=0;

    //************************************
    // Method:    getRecordFile                         ��ȡ��ʷ��Ƶ����Ϣ
    // Returns:   RECORDFILE*                           ��Ƶ��Ϣ����
    // Parameter: int nType                             ��ʷ��Ƶ����
    // Parameter: char * startTime                      ��Ƶ��ʼʱ��
    // Parameter: char * endTime                        ��Ƶ����ʱ��
    // Parameter: int * nFileCount                      ����ȡ��Ƶ��
    //************************************
    virtual RECORDFILE* getRecordFile(int nType,char* startTime,char* endTime,int* nFileCount)=0;

    //************************************
    // Method:    downloadRecordFile                         ������ʷ��Ƶ
    // Returns:   LONG                                       С��0��ʾʧ�� ����Ϊ���ر�ʶ����ֹͣ����
    // Parameter: char * fileName                            ��Ƶ��
    // Parameter: char * startTime                           ��Ƶ��ʼʱ��
    // Parameter: char * endTime                             ��Ƶ����ʱ��
    // Parameter: int nFileSize                              �ļ���С��Ҳ�����ڴ���һЩ��������Ĳ�����
    // Parameter: char * saveFile                            �����ļ�·��
    // Parameter: LPDOWNLOADRECORDFILECALLBACK lpCallBack    ���ؽ��Ȼص�
    // Parameter: void * pUser                               �û�ָ�룬�������ֵ������ĸ����������
    //************************************
    virtual LONG downloadRecordFile(char* fileName,char* startTime, char* endTime,int nFileSize,char* saveFile,LPDOWNLOADRECORDFILECALLBACK lpCallBack,void* pUser)=0;

    //************************************
    // Method:    downloadRecordFileEx                       ������ʷ��Ƶ
    // Returns:   LONG                                       С��0��ʾʧ�� ����Ϊ���ر�ʶ����ֹͣ����
    // Parameter: RECORDFILE RecordFile                      �����ṹ�壬����������ӿ���ͬ
    // Parameter: char * saveFile                            �����ļ�·��
    // Parameter: LPDOWNLOADRECORDFILECALLBACK lpCallBack    ���ؽ��Ȼص�
    // Parameter: void * pUser                               �û�ָ�룬�������ֵ������ĸ����������
    //************************************
    virtual LONG downloadRecordFileEx(RECORDFILE RecordFile,char* saveFile,LPDOWNLOADRECORDFILECALLBACK lpCallBack,void* pUser)=0;

    //************************************
    // Method:    stopDownloadRecordFile                        ֹͣ��ʷ��Ƶ����
    // Returns:   bool                                          �����Ƿ�ɹ�
    // Parameter: LONG ldownFileHandle                          ���ر�ʶ��downloadRecordFile��������
    //************************************
    virtual bool stopDownloadRecordFile(LONG ldownFileHandle)=0;

    //************************************
    // Method:    replayRecordFile                              Զ�̻ط�
    // Returns:   LONG                                          �طž��������ؽӿ�ʹ��
    // Parameter: int hWnd                                      �طŵĴ��ھ��
    // Parameter: char * fileName                               �ط��ļ���
    // Parameter: char * startTime                              ��ʼʱ��
    // Parameter: char * endTime                                ����ʱ��
    // Parameter: int nFileSize                                 �ļ���С��Ҳ�����ڴ���һЩ��������Ĳ�����
    //************************************
    virtual LONG replayRecordFile(int hWnd,char* fileName,char* startTime, char* endTime,int nFileSize)=0;

    //************************************
    // Method:    replayRecordFileEx                            Զ�̻ط�
    // Returns:   LONG                                          �طž��������ؽӿ�ʹ��
    // Parameter: int hWnd                                      �طŵĴ��ھ��
    // Parameter: RECORDFILE RecordFile                         ¼���ļ��������Ϣ
    //************************************
    virtual LONG replayRecordFileEx(int hWnd,RECORDFILE RecordFile)=0;

    //************************************
    // Method:    controlReplayRecordFile                       �ؼ�Զ�̻ط�
    // Returns:   bool                                          �����ɹ����
    // Parameter: LONG lReplayHandle                            �طž��
    // Parameter: int nCmd                                      ����ָ��
    // Parameter: int nInValue                                  һЩ�ټ����������
    // Parameter: int * outValue                                һЩ�ټ����������
    //************************************
    virtual bool controlReplayRecordFile(LONG lReplayHandle,int nCmd,int nInValue,int* outValue)=0;

    //************************************
    // Method:    stopReplayRecordFile                          ֹͣԶ�̻ط�
    // Returns:   bool                                          �����ɹ����
    // Parameter: LONG lReplayHandle                            �طž��
    //************************************
    virtual bool stopReplayRecordFile(LONG lReplayHandle)=0;

    //************************************
    // Method:    startTalk                                     ��������
    // Returns:   bool                                          �����ɹ����
    //************************************
    virtual bool startTalk()=0;

    //************************************
    // Method:    stopTalk                                      �ر�����
    // Returns:   bool                                          �����ɹ����
    //************************************
    virtual bool stopTalk()=0;

    //************************************
    // Method:    controlPTZ                                    ��̨����
    // Returns:   bool                                          �����ɹ����
    // Parameter: int nCmd                                      ����ָ��
    // Parameter: bool bEnable                                  �����òټ�����ֹͣ�ټ�
    //************************************
    virtual bool controlPTZ(int nCmd, bool bEnable)=0;

    //************************************
    // Method:    presetPTZ                                     ��̨Ԥ��λ����
    // Returns:   bool                                          �����ɹ����
    // Parameter: int nCmd                                      �ؼ�ָ��
    // Parameter: int nIndex                                    Ԥ�õ�����
    //************************************
    virtual bool presetPTZ(int nCmd, int nIndex)=0;

    //************************************
    // Method:    showSettingPane                               ��ʾ����ҳ��
    // Returns:   bool                                          �����ɹ����
    //************************************
    virtual bool showSettingPane()=0;

    //************************************
    // Method:    alarm_startCapture                            ��ʼ�����ش�
    // Returns:   bool                                          �����ɹ����
    // Parameter: int nPort                                     �����˿ڣ�һ�㴫0�Ϳ�����
    // Parameter: LPALARMCALLBACK lpCallBack                    �ش��ص�
    //************************************
    virtual bool alarm_startCapture(int nPort,LPALARMCALLBACK lpCallBack)=0;

    //************************************
    // Method:    alarm_stop                                    ֹͣ�����ش�
    // Returns:   bool                                          �����ɹ����
    //************************************
    virtual bool alarm_stop()=0;

    //************************************
    // Method:    log_QueryEx                                   �鿴�豸��־
    // Returns:   int                                           ��־����
    // Parameter: LOGQUERYTYPE nQueryType                       ������־����
    // Parameter: LOGERRORTYPE nErrorType                       ��������
    // Parameter: char * startTime                              ��ʼʱ��
    // Parameter: char * endTime                                ����ʱ��
    // Parameter: LOGINFO pLogInfo[]                            ��־����
    // Parameter: int nMaxLogCount                              ����ѯ��־����
    //************************************
    virtual int log_QueryEx(LOGQUERYTYPE nQueryType, LOGERRORTYPE nErrorType,char* startTime,char* endTime,LOGINFO pLogInfo[],int nMaxLogCount)=0;

    //************************************
    // Method:    log_Query                                     �鿴�豸��־
    // Returns:   LOGINFO*                                      ��־����
    // Parameter: LOGQUERYTYPE nQueryType                       ������־����
    // Parameter: LOGERRORTYPE nErrorType                       ��������
    // Parameter: char * startTime                              ��ʼʱ��
    // Parameter: char * endTime                                ����ʱ��
    // Parameter: int * nLogCount                               ����ѯ��־����
    //************************************
    virtual LOGINFO* log_Query(LOGQUERYTYPE nQueryType, LOGERRORTYPE nErrorType,char* startTime,char* endTime,int* nLogCount)=0;

    //************************************
    // Method:    setVideoEffect                                ����Ԥ����Ƶ��ʾ����
    // Returns:   bool                                          �����ɹ����
    // Parameter: DWORD dwBrightValue                           ���ȣ�ȡֵ��Χ[1,10]
    // Parameter: DWORD dwContrastValue                         �Աȶȣ�ȡֵ��Χ[1,10]
    // Parameter: DWORD dwSaturationValue                       ���Ͷȣ�ȡֵ��Χ[1,10]
    // Parameter: DWORD dwHueValue                              ɫ�ȣ�ȡֵ��Χ[1,10]
    //************************************
    virtual bool setVideoEffect(DWORD dwBrightValue,DWORD dwContrastValue, DWORD dwSaturationValue,DWORD dwHueValue)=0;

    //************************************
    // Method:    getVideoEffect                                ��ȡԤ����Ƶ��ʾ����
    // Returns:   bool                                          �����ɹ����
    // Parameter: DWORD * pBrightValue                          ���ȣ�ȡֵ��Χ[1,10]
    // Parameter: DWORD * pContrastValue                        �Աȶȣ�ȡֵ��Χ[1,10]
    // Parameter: DWORD * pSaturationValue                      ���Ͷȣ�ȡֵ��Χ[1,10]
    // Parameter: DWORD * pHueValue                             ɫ�ȣ�ȡֵ��Χ[1,10]
    //************************************
    virtual bool getVideoEffect(DWORD *pBrightValue,DWORD *pContrastValue, DWORD *pSaturationValue,DWORD *pHueValue)=0;

    //************************************
    // Method:    setDVRConfig                                  �����豸��������Ϣ
    // Returns:   bool:                                         �����ɹ����
    // Parameter: DWORD dwCommand                               �豸��������
    // Parameter: LONG lChannel                                 ͨ���ţ���������Ҫͨ���ţ��ò�����Ч����Ϊ0xFFFFFFFF����
    // Parameter: LPVOID lpInBuffer                             �������ݵĻ���ָ��
    // Parameter: DWORD dwInBufferSize                          �������ݵĻ��峤��
    //************************************
    virtual bool setDVRConfig(DWORD dwCommand,LONG lChannel,LPVOID lpInBuffer,DWORD dwInBufferSize)=0;

    //************************************
    // Method:    getDVRConfig                                  ��ȡ�豸��������Ϣ
    // Returns:   bool                                          �����ɹ����
    // Parameter: DWORD dwCommand                               �豸��������
    // Parameter: LONG lChannel                                 ͨ����
    // Parameter: LPVOID lpOutBuffer                            �������ݵĻ���ָ��
    // Parameter: DWORD dwOutBufferSize                         �������ݵĻ��峤��
    // Parameter: LPDWORD lpBytesReturned                       ʵ���յ������ݳ���ָ��
    //************************************
    virtual bool getDVRConfig(DWORD dwCommand,LONG lChannel,LPVOID lpOutBuffer,DWORD dwOutBufferSize,LPDWORD lpBytesReturned)=0;

    //************************************
    // Method:    playBackSaveData                             ����طŵ�¼�����ݣ���������ļ�
    // Returns:   bool                                         �����ɹ����
    // Parameter: LONG lReplayHandle                           �طž��
    // Parameter: char * sFileName                             �������ݵ��ļ�·��
    //************************************
    virtual bool playBackSaveData(LONG lReplayHandle,char *sFileName)=0;

    //************************************
    // Method:    stopPlayBackSave                             ֹͣ����طŵ�¼������
    // Returns:   bool                                         �����ɹ����
    // Parameter: LONG lReplayHandle                           �طž��
    //************************************
    virtual bool stopPlayBackSave(LONG lReplayHandle)=0;

    //************************************
    // Method:    getDownloadPos                               ��ȡ���ؽ���
    // Returns:   int                                          ���ؽ���
    // Parameter: LONG lFileHandle                             ���ؾ��
    //************************************
    virtual int getDownloadPos(LONG lFileHandle)=0;

    //************************************
    // Method:    getDVRWorkState                              ��ȡ�豸�Ĺ���״̬
    // Returns:   bool                                         �����ɹ����
    // Parameter: char dvrWorkState[]                          ��ȡ���豸����״̬�ṹ�����
    // Parameter: int arrayLen                                 �������
    //************************************
    virtual bool getDVRWorkState(char dvrWorkState[],int arrayLen)=0;

    //************************************
    // Method:    getDVRIPByResolveSvr                         ͨ����������������ȡ�豸�Ķ�̬IP��ַ
    // Returns:   bool                                         �����ɹ����
    // Parameter: char * sServerIP                             ������������IP��ַ
    // Parameter: int wServerPort                              �����������Ķ˿ں�
    // Parameter: char * sDVRName                              �豸����
    // Parameter: int wDVRNameLen                              �豸���Ƶĳ���
    // Parameter: char * sDVRSerialNumber                      �豸�����к�
    // Parameter: int wDVRSerialLen                            �豸���кŵĳ���
    // Parameter: char * sGetIP                                ��ȡ�����豸IP��ַָ��
    //************************************
    virtual bool getDVRIPByResolveSvr(char *sServerIP,int wServerPort,char *sDVRName,int wDVRNameLen,char *sDVRSerialNumber,int wDVRSerialLen,char* sGetIP)=0;

    //************************************
    // Method:    setConnectTime                               �����������ӳ�ʱʱ������ӳ��Դ���
    // Returns:   bool                                         �����ɹ����
    // Parameter: DWORD dwWaitTime                             ��ʱʱ�䣬��λ����
    // Parameter: DWORD dwTryTimes                             ���ӳ��Դ���
    //************************************
    virtual bool setConnectTime(DWORD dwWaitTime,DWORD dwTryTimes)=0;

    //************************************
    // Method:    startListen                                  ���������������豸�����ϴ��ı�������Ϣ
    // Returns:   bool                                         �����ɹ����
    // Parameter: char * sLocalIP                              PC������IP��ַ
    // Parameter: int wLocalPort                               PC���ؼ����˿ںš�
    //************************************
    virtual bool startListen (char *sLocalIP,int wLocalPort)=0;

    //************************************
    // Method:    stopListen                                  ֹͣ�����������豸�����ϴ��ı�������Ϣ
    // Returns:   bool                                        �����ɹ����
    //************************************
    virtual bool stopListen()=0;

    //************************************
    // Method:    serialSend                                  �豸���ڷ�������
    // Returns:   bool                                        �����ɹ����
    // Parameter: char * pBuf                                 �������ݵĻ�����ָ��
    // Parameter: DWORD nLength                               �������Ĵ�С�����1016�ֽ�
    // Parameter: char * pBuf2                                �������ݵĻ�����ָ��
    // Parameter: DWORD nLen2                                 �������Ĵ�С�����1016�ֽ�
    //************************************
    virtual bool serialSend(char* pBuf,DWORD nLength,char* pBuf2,DWORD nLen2)=0;

    //************************************
    // Method:    serialSendWithCallBack                      ���ص���Ϣ���豸���ڷ�������
    // Returns:   bool                                        �����ɹ����
    // Parameter: char * pBuf                                 �������ݵĻ�����ָ��
    // Parameter: DWORD nLength                               �������Ĵ�С�����1016�ֽ�
    // Parameter: int nCameraID                               ��ͷID
    //************************************
    virtual bool serialSendWithCallBack(char* pBuf,DWORD nLength,int nCameraID)=0;

    //************************************
    // Method:    buildSerialSend                             �����豸���ڷ������ݵ�ͨ��
    // Returns:   bool                                        �����ɹ����
    // Parameter: LONG lSerialPort                            ���ں�:1��232���ڣ�2��485����
    // Parameter: LPSERIALDATACALLBACK pSerialCallBack        �ص�����
    // Parameter: bool bOpen                                  true  ��   false �ر�
    //************************************
    virtual bool buildSerialSend(LONG lSerialPort,LPSERIALDATACALLBACK pSerialCallBack,bool bOpen)=0;

    //************************************
    // Method:    makeKey                                     ����һ���ؼ�֡
    // Returns:   void
    //************************************
    virtual void makeKey()=0;

    //************************************
    // Method:    clientAudioStart                           ���������㲥��PC����������
    // Returns:   bool                                       �����ɹ����
    //************************************
    virtual bool clientAudioStart()=0;

    //************************************
    // Method:    clientAudioStop                            �ر������㲥��PC����������
    // Returns:   bool                                       �����ɹ����
    //************************************
    virtual bool clientAudioStop()=0;

    //************************************
    // Method:    addDVR                                     ����豸�����Խ���PC�������Ĺ㲥��
    // Returns:   bool                                       �����ɹ����
    //************************************
    virtual bool addDVR()=0;

    //************************************
    // Method:    delDVR                                     �ӿɽ���PC�������Ĺ㲥����ɾ���豸
    // Returns:   bool                                       �����ɹ����
    //************************************
    virtual bool delDVR()=0;

    //************************************
    // Method:    setVoiceComClientVolume                    ���������Խ��ͻ��˵�����
    // Returns:   bool                                       �����ɹ����
    // Parameter: WORD wVolume                               ����������ȡֵ��Χ[0,0xffff]
    //************************************
    virtual bool setVoiceComClientVolume(WORD wVolume)=0;

    //************************************
    // Method:    controlPTZSpeed                            ���ٶȵ���̨����
    // Returns:   bool                                       �����ɹ����
    // Parameter: int nCmd                                   ����ָ��
    // Parameter: bool bEnable                               ������ͣ
    // Parameter: int nSpeed                                 �ٶ�
    //************************************
    virtual bool controlPTZSpeed(int nCmd, bool bEnable,int nSpeed)=0;

    //************************************
    // Method:    getDecoderAddress                          ��ȡ����������
    // Returns:   int                                        ������// Parameter:0 - 255
    // Parameter: LONG lChannelIndex                         ͨ����
    //************************************
    virtual int getDecoderAddress(LONG lChannelIndex)=0;

    //************************************
    // Method:    controlPTZSpeedWithChannel                 ��ͨ�����ٶȵ���̨����
    // Returns:   bool                                       �����ɹ����
    // Parameter: int nCmd                                   ����ָ��
    // Parameter: bool bEnable                               ������ͣ
    // Parameter: int nSpeed                                 �ٶ�
    // Parameter: int nChannel                               ͨ����
    //************************************
    virtual bool controlPTZSpeedWithChannel(int nCmd, bool bEnable, int nSpeed, int nChannel)=0;

    //************************************
    // Method:    presetPTZWithChannel                       ��ͨ�׵���̨Ԥ�õ�����
    // Returns:   bool                                       �����ɹ����
    // Parameter: int nCmd                                   ����ָ��
    // Parameter: int nIndex                                 Ԥ�õ���
    // Parameter: int nChannel                               ͨ����
    //************************************
    virtual bool presetPTZWithChannel(int nCmd, int nIndex, int nChannel)=0;

    //************************************
    // Method:    controlPTZSpeedWithChannelEx               ��ͨ�����ٶȵ���̨����
    // Returns:   bool                                       �����ɹ����
    // Parameter: PCONTROL_PARAM pParam                      ��̨������ؽṹ��
    //************************************
    virtual bool controlPTZSpeedWithChannelEx(PCONTROL_PARAM pParam)=0;

    //************************************
    // Method:    getPlayBackOsdTime                         ��ȡ¼��ط�ʱ��OSDʱ��
    // Returns:   bool                                       �����ɹ����
    // Parameter: LONG lReplayHandle                         ���ž��
    // Parameter: char * pOsdTime                            ��ȡ��OSDʱ���ָ��
    //************************************
    virtual bool getPlayBackOsdTime(LONG  lReplayHandle, char *pOsdTime)=0;

    //************************************
    // Method:    setCurrentChannel                          ���õ�ǰͨ��
    // Returns:   void
    // Parameter: int nChannel                               ͨ����
    //************************************
    virtual void setCurrentChannel(int nChannel)=0;

    //************************************
    // Method:    playBackCaptureFile                        ¼��ط�ʱץͼ�����������ļ���
    // Returns:   bool                                       �����ɹ����
    // Parameter: LONG lReplayHandle                         ���ž��
    // Parameter: char * pFileName                           ����ͼƬ���ݵ��ļ�·��
    //************************************
    virtual bool playBackCaptureFile(LONG lReplayHandle, char *pFileName)=0;

    //************************************
    // Method:    setCapturePictureMode                      ���õ�ǰ��ͼģʽ
    // Returns:   bool                                       �����ɹ����
    // Parameter: DWORD dwCaptureMode                        ��ͼģʽ
    //************************************
    virtual bool setCapturePictureMode(DWORD dwCaptureMode)=0;

    //************************************
    // Method:    captureFileStream                          ��ȡ�ļ���
    // Returns:   LONG                                       �ļ������
    // Parameter: LPCAPTURESTREAMCALLBACK lpCallBack         �ص�����
    // Parameter: void * pUser                               �û�ָ��
    // Parameter: int nStreamType                            ������
    // Parameter: RECORDFILE FileInfo                        �ļ���Ϣ
    // Parameter: char * sType                               δ֪
    //************************************
    virtual LONG captureFileStream(LPCAPTURESTREAMCALLBACK lpCallBack, void* pUser, int nStreamType, RECORDFILE FileInfo, char* sType)=0;

    //************************************
    // Method:    getCameraInfo                              ��ȡ����������ľ�ͷ��Ϣ
    // Returns:   LONG                                       δ֪
    // Parameter: int * nSize                                δ֪
    //************************************
    virtual LONG getCameraInfo(int *nSize)=0;

    //************************************
    // Method:    setPlayWindow                              ���ò��Ŵ��ھ��(����)
    // Returns:   int                                        �ټ���� ������˼δ֪
    // Parameter: HWND palyWindow[]                          ���ھ������
    // Parameter: int nMaxCount                              �������
    //************************************
    virtual int setPlayWindow(HWND palyWindow[], int nMaxCount)=0;

    //************************************
    // Method:    startPlayerByCamera                        ���ž�ͷ�����ھ��(����)
    // Returns:   bool                                       �����ɹ����
    // Parameter: HWND hwndPlay                              ���ھ��
    // Parameter: int nCameraID                              ��ͷID
    //************************************
    virtual bool startPlayerByCamera(HWND hwndPlay, int nCameraID)=0;

    //************************************
    // Method:    stopPlayerByCamera                         ֹͣ���Ŵ��ھ��(����)
    // Returns:   bool                                       �����ɹ����
    // Parameter: HWND hwndPlay                              ���ھ��
    // Parameter: int nCameraID                              ��ͷID
    //************************************
    virtual bool  stopPlayerByCamera(HWND hwndPlay, int nCameraID)=0;

    //************************************
    // Method:    setCurrentCameraCode                       ���õ�ǰ��ͷ���
    // Returns:   void
    // Parameter: char * sCameraCode                         ��ͷ���
    //************************************
    virtual void setCurrentCameraCode(char* sCameraCode)=0;

    //************************************
    // Method:    startRecord                                ��ʼ¼��
    // Returns:   bool                                       �����ɹ����
    // Parameter: char * saveFile                            ¼�񱣴��·��
    //************************************
    virtual bool startRecord(char* saveFile)=0;

    //************************************
    // Method:    stopRecord                                 ֹͣ¼��
    // Returns:   bool                                       �����ɹ����
    //************************************
    virtual bool stopRecord()=0;

/***********************���ſ�ӿ�***********************************/

    //************************************
    // Method:    initialPlayer                              ��ʼ������
    // Returns:   bool                                       �����ɹ����
    // Parameter: int nPort                                  ����ͨ��
    // Parameter: int nDecodeType                            ��������
    // Parameter: BYTE * buff                                ֡����
    // Parameter: int nSize                                  �����С
    // Parameter: int nStreamType                            ������
    //************************************
    virtual bool initialPlayer(int nPort,int nDecodeType,BYTE* buff, int nSize, int nStreamType)=0;

    //************************************
    // Method:    initialPlayerEx                            ��ʼ������
    // Returns:   bool                                       �����ɹ����
    // Parameter: PINITPY_PARAM pIParam                      �����ṹ���������������ӿ�ͬ
    //************************************
    virtual bool initialPlayerEx(PINITPY_PARAM pIParam)=0;

    //************************************
    // Method:    startPlayer                                ��ʼ����
    // Returns:   bool                                       �����ɹ����
    // Parameter: HWND hWnd                                  ���Ŵ��ھ��
    //************************************
    virtual bool startPlayer(HWND hWnd)=0;

    //************************************
    // Method:    startPlayer2                               ��ʼ����
    // Returns:   bool                                       �����ɹ����
    // Parameter: HWND hWnd                                  ���Ŵ��ھ��
    // Parameter: LPDRAWCBCALLLBACK lpDrawCBFun              �ص�����
    // Parameter: void * pUser                               �û�����
    //************************************
    virtual bool startPlayer2(HWND hWnd, LPDRAWCBCALLLBACK lpDrawCBFun, void *pUser)=0;

    //************************************
    // Method:    startPlayer4Standard                       ��ʼ����
    // Returns:   bool                                       �����ɹ����
    // Parameter: HWND hWnd                                  ���Ŵ��ھ��
    // Parameter: LPDecCBFun lpDecCBFun                      �ص�����
    // Parameter: int nCameraID                              ��ͷID
    //************************************
    virtual bool startPlayer4Standard(HWND hWnd,LPDecCBFun lpDecCBFun, int nCameraID)=0;

    //************************************
    // Method:    startPlayer4StandardEx                     ��ʼ����
    // Returns:   bool                                       �����ɹ����
    // Parameter: PSTARTPYS_PARAM pParam                     �����ṹ���������������ӿ�ͬ
    //************************************
    virtual bool startPlayer4StandardEx(PSTARTPYS_PARAM pParam)=0;

    //************************************
    // Method:    addData                                    ��������м�������
    // Returns:   bool                                       �����ɹ����
    // Parameter: BYTE * buff                                ���ݻ���
    // Parameter: int nSize                                  ���泤��
    //************************************
    virtual bool addData(BYTE* buff, int nSize)=0;

    //************************************
    // Method:    stopPlayer                                 ֹͣ����
    // Returns:   bool                                       �����ɹ����
    //************************************
    virtual bool stopPlayer()=0;

    //************************************
    // Method:    locPlay_OpenFile                           ���ű����ļ�
    // Returns:   bool                                       �����ɹ����
    // Parameter: int nPort                                  ����ͨ����
    // Parameter: int nDecodeType                            ��������
    // Parameter: int hWnd
    // Parameter: char * fileName
    //************************************
    virtual bool locPlay_OpenFile(int nPort,int nDecodeType,int hWnd,char* fileName)=0;

    //************************************
    // Method:    locPlay_OpenFileEx                         ���ű����ļ�
    // Returns:   bool                                       �����ɹ����
    // Parameter: PLOCPY_OPENF_PARAM_PARAM pParam            �����ṹ���������������ӿ�ͬ
    //************************************
    virtual bool locPlay_OpenFileEx(PLOCPY_OPENF_PARAM_PARAM pParam)=0;

    //************************************
    // Method:    locPlay_Control                            ���ز��ſ���
    // Returns:   bool                                       �����ɹ����
    // Parameter: int nCmd                                   ����ָ��
    // Parameter: int nInValue                               �������
    // Parameter: int * outValue                             �������
    //************************************
    virtual bool locPlay_Control(int nCmd,int nInValue,int* outValue)=0;

    //************************************
    // Method:    locPlay_Stop                               ���ز���ֹͣ
    // Returns:   bool                                       �����ɹ����
    //************************************
    virtual bool locPlay_Stop()=0;

    //************************************
    // Method:    convertToBmpFile                           ��ץͼ�õ���ͼ�����ݱ����BMP�ļ�
    // Returns:   bool                                       �����ɹ����
    // Parameter: char * pBuf                                ץͼ�ص�������ͼ�񻺳���
    // Parameter: LONG nSize                                 ץͼ�ص�������ͼ��Ĵ�С
    // Parameter: LONG nWidth                                ץͼ�ص�������ͼ����
    // Parameter: LONG nHeight                               ץͼ�ص�������ͼ��߶�
    // Parameter: LONG nType                                 ץͼ�ص�������ͼ������
    // Parameter: char * sFileName                           Ҫ������ļ����������BMP��Ϊ�ļ���չ��
    //************************************
    virtual bool convertToBmpFile(char * pBuf,LONG nSize,LONG nWidth,LONG nHeight,LONG nType,char *sFileName)=0;

    //************************************
    // Method:    oneByOneBack                               ��֡����
    // Returns:   bool                                       �����ɹ����
    // Parameter: LONG nPort                                 ������ͨ��
    //************************************
    virtual bool oneByOneBack(LONG nPort)=0;

    //************************************
    // Method:    oneByOne                                   ��֡����
    // Returns:   bool                                       �����ɹ����
    // Parameter: LONG nPort                                 ������ͨ��
    //************************************
    virtual bool oneByOne(LONG nPort)=0;

    //************************************
    // Method:    setPlayedTimeEx                            ���ò���ʱ��
    // Returns:   bool                                       �����ɹ����
    // Parameter: LONG nPort                                 ������ͨ��
    // Parameter: DWORD nTime                                ����ʱ��
    //************************************
    virtual bool setPlayedTimeEx(LONG nPort,DWORD nTime)=0;

    //************************************
    // Method:    setFileRefCallBack                         PlayM4_SetFileRefCallBack
    // Returns:   bool                                       �����ɹ����
    // Parameter: LONG nPort                                 ������ͨ��
    // Parameter: void (__stdcall *pFileRefDone) (DWORD nPort,DWORD nUser)
    //                                                       �ص�
    // Parameter: DWORD nUser                                �û�����
    //************************************
    virtual bool setFileRefCallBack(LONG nPort,void (__stdcall *pFileRefDone) (DWORD nPort,DWORD nUser),DWORD nUser)=0;

    //************************************
    // Method:    setDisplayCallBack                         ����ץͼ�ص�����
    // Returns:   bool                                       �����ɹ����
    // Parameter: LONG nPort                                 ������ͨ��
    // Parameter: void (__stdcall *pFileRefDone)(long nPort,char * pBuf,long nSize,long nWidth,long nHeight,long nStamp,long nType,long nReserved)
    //
    //************************************
    virtual bool setDisplayCallBack(LONG nPort, void (__stdcall *pFileRefDone)(long nPort,char * pBuf,long nSize,long nWidth,long nHeight,long nStamp,long nType,long nReserved))=0;

    //************************************
    // Method:    capturePicture                             ��ͼ
    // Returns:   bool                                       �����ɹ����
    // Parameter: char * sFilePath                           ����·��
    //************************************
    virtual bool capturePicture(char* sFilePath)=0;

    //************************************
    // Method:    reSetDDrawDevice                           ˢ����ʾ
    // Returns:   void
    // Parameter: HWND hWnd                                  ���Ŵ��ھ��
    //************************************
    virtual void reSetDDrawDevice(HWND hWnd)=0;

    //************************************
    // Method:    controlCameraSound                         �ؼ���������
    // Returns:   bool                                       �����ɹ����
    // Parameter: bool bOpenSound                            true ������ false ��
    //************************************
    virtual bool controlCameraSound(bool bOpenSound)=0;

    //************************************
    // Method:    openVideoFile                              ����Ƶ�ļ�
    // Returns:   LONG                                       ��Ƶ�ļ����
    // Parameter: char * sFileName                           ��Ƶ�ļ�
    //************************************
    virtual LONG openVideoFile(char *sFileName)=0;

    //************************************
    // Method:    readVideoFile                              ����Ƶ�ļ��ж�ȡ��Ƶ����
    // Returns:   int                                        �ļ���ȡ���
    // Parameter: char * pBuff                               ��Ƶ���ݻ���
    // Parameter: int nLen                                   �����С
    // Parameter: int * pOutStreamType                       ������
    //************************************
    virtual int readVideoFile(char *pBuff,int nLen, int *pOutStreamType)=0;

    //************************************
    // Method:    closeVideoFile                             �ر���Ƶ����
    // Returns:   bool                                       �����ɹ����
    //************************************
    virtual bool closeVideoFile()=0;

    //************************************
    // Method:    controlPlay                                ���ſ���
    // Returns:   bool                                       �����ɹ����
    // Parameter: int nCmd                                   ����ָ��
    // Parameter: int param                                  ���Ž���
    // Parameter: int * outValue                             �����������ȡ���Ľ��ȵȵȣ�
    //************************************
    virtual bool controlPlay(int nCmd,int param, int *outValue)=0;

    //************************************
    // Method:    ClearPlayBuffer                            ������Ż���
    // Returns:   void
    //************************************
    virtual void ClearPlayBuffer()=0;

    //************************************
    // Method:    pusePlayDecode                             ��ͣ/����
    // Returns:   void
    // Parameter: bool bPuse                                 true ��ͣ  false ����
    //************************************
    virtual void pusePlayDecode(bool bPuse)=0;


//zjf 20130926
	//************************************
	//�ֲ��Ŵ�
	/*
	// Parameter: bFlag: ������
	// 			  x1, y1, x2, y2�ֱ�Ϊ����ڲ��Ŵ����ϵ����ϼ����µ�����, ȫ��Ϊ0ʱ��ʾֹͣ�ֲ��Ŵ�.
	// Returns:true �ɹ�, false ʧ��*/
	//************************************
	virtual bool SetCropArea(bool bFlag, int x1, int y1, int x2, int y2)=0;
	//************************************
	//��Ƶ�������ܵ���
	/*
	// Parameter: nCmd: ���ܵ��ڵ�����, 1Ϊȥ��, 2Ϊ��ɫ, 3Ϊ��, 4Ϊ���ȵ���
	//			  bFlag: trueΪִ�����ܵ���, falseΪȡ��
	//			  x1, y1: ȥ��ʱ��ʾ��ʼ������, �߶ȵ���ʱΪ����
	//			  x2, y2: ���ȵ��ڱ�ʾ�ս������.
	// Returns: 0�ɹ�, <0ʧ��*/
	//************************************
	virtual bool SetDecodeParam(int nCmd, bool bFlag, int x1, int y1, int x2, int y2)=0; 

	//************************************
	//����YUV�ص�����
	/*
	// Parameter: pCallBack: �ص�����, ���������.
	// Returns:true �ɹ�, false ʧ��*/
	//************************************
	virtual bool SetYUVCallBack(LPYUVCALLBACK pCallBack) = 0;
	/****���������ӿ���Ϊ��ʵ���ڿͻ��˲���ʵʱ��Ƶʱ��15����ٻط�****/

	//************************************
	//����ʵʱ����ʱ���������ݵ�ʱ��, Ĭ��15��
	/*
	// Parameter:  identify: ���
	//			   nSaveTime: �����ʱ��(��λ:�룩
	// Returns: true�ɹ�, falseʧ��*/
	//************************************
	virtual bool SetStreamSaveTime(int nSaveTime)=0;
	//************************************
	//�طű������Ƶ��
	/*
	// Parameter:  identify: ���;
	//			   hWnd: ���ھ��
	// Returns: true�ɹ�, falseʧ��*/
	//************************************
	virtual bool PlayBackSaveStream(HWND hWnd)=0;
	//************************************
	//ֹͣ�طű������Ƶ��
	/*
	// Parameter:  identify: ���
	// Returns: true�ɹ�, falseʧ��*/
	//************************************
	virtual bool StopPlayBackSaveStream()=0;
//zjf 20130926 end

//pzm 20130927
	//************************************
	//����ͼ�����Ⱦģʽ��Ĭ��ΪD3D��Ⱦ
	/*
	// Parameter:nMode ��Ⱦģʽ
	// OutParameter:��
	// Returns:�ɹ�����true�����򷵻�false
	*/
	//************************************
	virtual bool SetRenderMode(int nMode)=0;

	//************************************
	//����֡�Ŷ�λ,��λ��nFrameNum����Ĺؼ�֡����ǰ���ң�
	/*
	// Parameter:nFrameNum ֡��
	// OutParameter:��
	// Returns:�ɹ�����true�����򷵻�false
	*/
	//************************************
	virtual bool SetPosByFrameNum(DWORD nFrameNum)=0;

	//************************************
	//��ȡbeginTime��endTime֮���¼�񣬱�����filename��ָ����·����beginTime��endTimeΪ�뼶ʱ��
	/*
	// Parameter:beginFrame:��ȡ��ʼ��ʱ�䣻
	//			 endFrame:��ȡ������ʱ�䣻
	//			 filename:¼�񱣴�ľ���·��
	// OutParameter:��
	// Returns:�ɹ�����true�����򷵻�false
	*/
	//************************************
	virtual bool GetVideoCut(DWORD beginFrame, DWORD endFrame, LPSTR filename)=0;
	//************************************
	//��ֹ�ļ�����
	/*
	// Parameter:
	// OutParameter:��
	// Returns:�ɹ�����true�����򷵻�false
	*/
	//************************************
	virtual bool StopCutVideo()=0;
	//************************************
	//�����ļ������ص�
	/*
	// Parameter:
	// OutParameter:��
	// Returns:�ɹ�����true�����򷵻�false
	*/
	//************************************
	virtual bool SetFileEndCallback(void *pUser, pFileOverCB pCallBack)=0;
	//************************************
	//��ȡý����Ϣ
	/*
	// Parameter:mInf������ȡý����Ϣ�Ľṹָ��
	// OutParameter:��
	// Returns:�ɹ�����true�����򷵻�false
	*/
	//************************************
	virtual bool GetMediaInfo(MediaInf &mInf)=0;
	//************************************
	//��Ƶ�����ȡ���ò���
	/*
	// Parameter: nCmd: ���ܵ��ڵ�����, 1Ϊȥ��, 2Ϊ��ɫ, 3Ϊ��, 4Ϊ���ȵ���				
	// OutParameter:
	//				��nCmdΪ1ȥ�����ʱ:
	//				x1				��ʼ��X����
	//				y1				��ʼ��Y����
	//				x2				������X����
	//				y2				������Y����
	//				��nCmdΪ4���ȵ���ʱ:
	//				x1 Ϊgray1	���ȵ��ڲ����ĻҶ�ֵ1
	//				y1 Ϊgray2	���ȵ��ڲ����ĻҶ�ֵ2
	// Returns: 0�ɹ�, <0ʧ��*/
	//************************************
	virtual bool GetDecodeParam(int nCmd, int &x1, int &y1, int &x2, int &y2)=0;
//pzm 20130927 end

/***********************���ýӿ�***********************************/

    //************************************
    // Method:    queryPorperySupport                        ��ѯ����֧��
    // Returns:   bool                                       true ֧��   false��֧��
    // Parameter: XYPROPROPERTY propery                      ���ܲ���
    //************************************
    virtual bool queryPorperySupport(XYPROPROPERTY propery)=0;

    //************************************
    // Method:    getLastError                               ��ȡ���Ĵ�����
    // Returns:   DWORD                                      �������
    //************************************
    virtual DWORD getLastError()=0;

	//2013-09-27 ���� Э��ӿ� AllpurposeI
	//************************************
	// Method:    AllpurposeI                               ��ȡ���Ĵ�����
	// Returns:   int  0�ɹ�,-1ʧ��                         �����ɹ����
	// Parameter: char * pInPutPara ,char *pOutPutPara
	//************************************
	int  AllpurposeI(int nCmd,char *pInPutPara,char *pOutPutPara);
};
