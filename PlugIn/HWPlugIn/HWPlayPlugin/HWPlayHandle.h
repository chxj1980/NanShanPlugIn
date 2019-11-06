#ifndef DHPlayHandle_h__
#define DHPlayHandle_h__

#include "idvrhandler_x64.h"
#include "dhplay.h"
#include "WriteLog.h"
#include <vector>
using namespace std;

#define BUFFERMAXSIZE 1024 * 1024 * 20

class DHPlayHandle :
    public IDVRHandler
{
public:
    DHPlayHandle(void);
    ~DHPlayHandle(void);

public:
	static void  CALLBACK DrawFunCallBack(long nPort,HDC hDc,void *nUser);

    virtual bool initialPlayer(int nPort,int nDecodeType,BYTE* buff, int nSize, int nStreamType);
    virtual bool initialPlayerEx(PINITPY_PARAM pIParam);

    virtual bool startPlayer(HWND hWnd);

    virtual bool startPlayer2(HWND hWnd, LPDRAWCBCALLLBACK lpDrawCBFun, void *pUser);

    //2007-04-23
    virtual bool startPlayer4Standard(HWND hWnd,LPDecCBFun lpDecCBFun, int nCameraID);
    virtual bool startPlayer4StandardEx(PSTARTPYS_PARAM pParam);

    virtual bool addData(BYTE* buff, int nSize);

    virtual bool stopPlayer();

    virtual bool locPlay_OpenFile(int nPort,int nDecodeType, HWND hWnd,char* fileName);
    virtual bool locPlay_OpenFileEx(PLOCPY_OPENF_PARAM_PARAM pParam);

    virtual bool locPlay_Control(int nCmd,int nInValue,int* outValue);

    virtual bool locPlay_Stop();

    virtual bool convertToBmpFile(char * pBuf,LONG nSize,LONG nWidth,LONG nHeight,LONG nType,char *sFileName);
    virtual bool oneByOneBack(LONG nPort);
    virtual bool oneByOne(LONG nPort);
    virtual bool setPlayedTimeEx(LONG nPort,DWORD nTime);

    //2008-03-10 ����
    virtual void reSetDDrawDevice(HWND hWnd);

    //2008-03-10 ����
    virtual bool controlCameraSound(bool bOpenSound);
    /*�ļ���ý�岥�ſ���*/
    virtual intptr_t openVideoFile(char *sFileName);
    virtual int readVideoFile(char *pBuff,int nLen, int *pOutStreamType);
    virtual bool closeVideoFile();
    virtual bool controlPlay(int nCmd,int param, int *outValue);
    virtual void ClearPlayBuffer();
    virtual void pusePlayDecode(bool bPuse);

    virtual bool setFileRefCallBack(LONG nPort,void (__stdcall *pFileRefDone) (DWORD nPort,void *nUser),void *nUser);
    virtual bool setDisplayCallBack(LONG nPort, void (__stdcall *pFileRefDone)(long nPort,char * pBuf,long nSize,long nWidth,long nHeight,long nStamp,long nType,void *nReserved));


    //2007-05-25 ����
    virtual bool capturePicture(char* sFilePath);


    static void CALLBACK DecCBFun4Standard(long nPort,char * pBuf,long nSize,FRAME_INFO * pFrameInfo, void *nReserved1,long nReserved2);
	static void CALLBACK DecCBDecode(LONG nPort, FRAME_DECODE_INFO* pFrameDecodeInfo, FRAME_INFO_EX* pFrameInfo, void* pUser);
    static void CALLBACK DecCBFunc(DWORD nPort,void *nUser);

	//2013 0926 zjf add
	bool SetCropArea( bool bFlag, int x1, int y1, int x2, int y2);
	bool SetDecodeParam( int nCmd, bool bFlag, int x1, int y1, int x2, int y2);
	bool SetYUVCallBack(LPYUVCALLBACK pCallBack);

	bool SetStreamSaveTime( int nSaveTime);
	bool PlayBackSaveStream( HWND hWnd);
	bool StopPlayBackSaveStream();
	//2013 0927 pzm add
	bool SetRenderMode( int nMode);

	bool SetPosByFrameNum(DWORD nFrameNum);

	bool GetVideoCut( DWORD beginFrame, DWORD endFrame, LPSTR filename);

	bool StopCutVideo();

	bool SetFileEndCallback( void *pUser, pFileOverCB pCallBack);

	bool GetMediaInfo(MediaInf &mInf);

	bool GetDecodeParam( int nCmd, int &x1, int &y1, int &x2, int &y2);

	int  AllpurposeI(int nCmd,char *pInPutPara,char *pOutPutPara);

	static void CALLBACK pDHFileOverCB(DWORD nPort, void *pUser);

	pFileOverCB m_pFileOverCB;
	LPDRAWCBCALLLBACK m_pDrawCallBack;

protected:
	int m_nSrcWind;
	LONG m_nSrcWidth;
	LONG m_nSrcHight;
	int m_Xlpoit;
	int m_Xrpoit;
	int m_Ytpoit;
	int m_Ydpoit;

    int m_nDecodeType;//���뷽ʽ 0:���  1:Ӳ��
    bool m_bHasSendInit;
    int    m_nPlayerPort;
    bool m_bHasOpenStream;
    int m_nDeviceNum;    //��ǰ��Ƶ��������Ĭ�ϴ���

    int   m_CountBag;
    int   m_nLocPlayPort;
	float m_fSpeed;
    bool  m_bDvrFile;
    int		m_nFilePlayerPort;
    HANDLE  m_hStreamFile;   //�ļ����
    int m_nFileHead;        //�ж��ļ�ͷ���ļ���
    DWORD  m_fileTotalTime;
    DWORD m_nFileTotalSize; //�ļ���С
    DWORD m_nFileOffset;    //��ȡ�ļ�ƫ��

    bool	 m_read;
    bool	m_nPuse;

    static char *mFileName;  //����ץͼ���ļ���ָ��
    static int m_PlayPort; //���ھ�̬������

    struct PLAYERINFO
    {
        int nPlayerPort;
        int nCameraID;
    };
    static vector<PLAYERINFO> m_vPlayChan;

    WriteLog m_log;

	HWND m_hWnd;
	void *m_pUserDraw;

	bool m_bOpenSound;
	void *m_pAudioHandle;
	FILE *m_aout;
public:
	typedef  void (CALLBACK *LpFileRefDone)(long nPort,char * pBuf,long nSize,long nWidth,long nHeight,long nStamp,long nType,void *nReserved);
	LpFileRefDone m_pFileRefDone;	

public:
    static CRITICAL_SECTION m_Lock;


    /************************************************************************/
    /*                 ����Ϊ����SDK��ؽӿ� ���ﲻʵ��                     */
    /************************************************************************/

    virtual int getDecoderAddress(LONG lChannelIndex){return -1;};

    virtual bool connectDVR(char* sIP,int nPort,char* sUser,char* sPwd,int nChannel){return false;};
    virtual bool connectDVREx(PCONNECT_PARAM pCParam){return false;};

    virtual void disconnectDVR(){return;};
    virtual void freeLoginInfo(){return;};
    virtual LONG checkDVR(char* sIP, int nPort, char* sUser, char* sPwd,CLInfo pInfo[],int nMaxCount){return -1;};
    virtual LONG checkDVREx(PCONNECT_PARAM pCParam,CLInfo pInfo[],int nMaxCount){return -1;};

    virtual void setDVR(char* sIP, int nPort, char* sUser, char* sPwd,CLInfo pInfo[],int nInfoCount){return;};
    virtual void setDVREx(PCONNECT_PARAM pCParam,CLInfo pInfo[],int nInfoCount){return;};

    virtual void releaseHandler(){delete this;};

    virtual bool captureStream(LPCAPTURESTREAMCALLBACK lpCallBack, void* pUser, int nGetVideoType){return false;};
    virtual bool captureStreamEx(PCAPTURE_PARAM pParam){return false;};

    virtual bool stopCaptureStream(){return false;};

    virtual int getRecordFileEx(RECORDQUERYTYPE nType,char* startTime,char* endTime,RECORDFILE pRecordFile[],int nMaxFileCount){return -1;};
    virtual RECORDFILE* getRecordFile(RECORDQUERYTYPE nType,char* startTime,char* endTime,int* nFileCount){return NULL;};

    virtual intptr_t downloadRecordFile(char* fileName,char* startTime, char* endTime,int nFileSize,char* saveFile,LPDOWNLOADRECORDFILECALLBACK lpCallBack,void* pUser){return -1;};
    virtual intptr_t downloadRecordFileEx(RECORDFILE RecordFile,char* saveFile,LPDOWNLOADRECORDFILECALLBACK lpCallBack,void* pUser){return -1;};

    virtual bool stopDownloadRecordFile(intptr_t ldownFileHandle){return false;};

    virtual intptr_t replayRecordFile(HWND hWnd,char* fileName,char* startTime, char* endTime,int nFileSize){return -1;};
    virtual intptr_t replayRecordFileEx(HWND hWnd,RECORDFILE RecordFile){return -1;};

    virtual bool controlReplayRecordFile(intptr_t lReplayHandle,int nCmd,int nInValue,int* outValue){return false;};

    virtual bool stopReplayRecordFile(intptr_t lReplayHandle){return false;};

    virtual bool startTalk(){return false;};

    virtual bool stopTalk(){return false;};

    virtual bool controlPTZ(int nCmd, bool bEnable){return false;};

    virtual bool presetPTZ(int nCmd, int nIndex){return false;};

    virtual bool showSettingPane(){return false;};

    //�����ش�
    static int CALLBACK MessageCallback(LONG lCommand,char *sDVRIP,char *pBuf,DWORD dwBufLen){return -1;};

    virtual bool alarm_startCapture(int nPort,LPALARMCALLBACK lpCallBack){return false;};

    virtual bool alarm_stop(){return false;};

    //��ѯ��־
    virtual int log_QueryEx(LOGQUERYTYPE nQueryType, LOGERRORTYPE nErrorType,char* startTime,char* endTime,LOGINFO pLogInfo[],int nMaxLogCount){return -1;};

    virtual LOGINFO* log_Query(LOGQUERYTYPE nQueryType, LOGERRORTYPE nErrorType,char* startTime,char* endTime,int* nLogCount){return NULL;};

    // 2007-1-28 ����
    virtual bool setVideoEffect(DWORD dwBrightValue,DWORD dwContrastValue, DWORD dwSaturationValue,DWORD dwHueValue){return false;};
    virtual bool getVideoEffect(DWORD *pBrightValue,DWORD *pContrastValue, DWORD *pSaturationValue,DWORD *pHueValue){return false;};
    virtual bool setDVRConfig(DWORD dwCommand,LONG lChannel,LPVOID lpInBuffer,DWORD dwInBufferSize){return false;};
    virtual bool getDVRConfig(DWORD dwCommand,LONG lChannel,LPVOID lpOutBuffer,DWORD dwOutBufferSize,LPDWORD lpBytesReturned){return false;};

    virtual bool playBackSaveData(intptr_t lReplayHandle,char *sFileName){return false;};
    virtual bool stopPlayBackSave(intptr_t lReplayHandle){return false;};
    //�ͻ���ͨ������SDK�ӿ�ֱ�Ӷ�����¼���ļ����صĽ��ȡ��̳���IDVRHandler�ӿ��ࡣ
    virtual int getDownloadPos(intptr_t lFileHandle){return -1;};
    virtual bool getDVRWorkState(char dvrWorkState[],int arrayLen){return false;};
    virtual bool getDVRIPByResolveSvr(char *sServerIP,int wServerPort,char *sDVRName,int wDVRNameLen,char *sDVRSerialNumber,int wDVRSerialLen,char* sGetIP){return false;};
    virtual bool setConnectTime(DWORD dwWaitTime,DWORD dwTryTimes){return false;};
    virtual bool startListen (char *sLocalIP,int wLocalPort){return false;};
    virtual bool stopListen(){return false;};
    virtual bool serialSend(char* pBuf,DWORD nLength,char* pBuf2,DWORD nLen2){return false;};
    virtual bool controlPTZSpeed(int nCmd, bool bEnable,int nSpeed);
    virtual void makeKey(){return;};
    //����PC ����������
    virtual bool clientAudioStart(){return false;};
    //ֹͣPC ����������
    virtual bool clientAudioStop(){return false;};
    //���һ̨DVR �����Խ���PC ������������
    virtual bool addDVR(){return false;};
    //ɾ���Ѿ��ӵ����DVR
    virtual bool delDVR(){return false;};
    virtual bool setVoiceComClientVolume(WORD wVolume){return false;};

    static void CALLBACK fRealDataCallBack(LONG lRealHandle, DWORD dwDataType, BYTE *pBuffer,DWORD dwBufSize,void* dwUser){return;};
    static void CALLBACK fFileDataCallBack(LONG lFileHandle, DWORD dwDataType, BYTE *pBuffer,DWORD dwBufSize,DWORD dwUser){return;};

    //���ͨ���ͻ�����ṩ�Ļص���֪ͨ�ͻ���¼���ļ����صĽ��ȡ����ڲ���ĳ�Ա������
    void getDownloadPos(void){return;};
    void splitString(string,vector<string>&,string){return;};

    //��̨�ٶȿ���_��ͨ��
    virtual bool controlPTZSpeedWithChannel(int nCmd, bool bEnable, int nSpeed, int nChannel);
    virtual bool controlPTZSpeedWithChannelEx(PCONTROL_PARAM pParam){return false;};
    //��̨����_��ͨ��.
    virtual bool presetPTZWithChannel(int nCmd, int nIndex, int nChannel){return false;};

    //��ȡ�ط�Osdʱ��
    virtual bool getPlayBackOsdTime(intptr_t lReplayHandle, char *pOsdTime){return false;};
    //���õ�ǰͨ��
    virtual void setCurrentChannel(int nChannel){return;};
    //��ȡ�������
    virtual DWORD getLastError(){return 0;};
    //Զ�̻ط�ʱץͼ
    bool playBackCaptureFile(intptr_t lReplayHandle, char *pFileName){return false;};
    //����Զ�̻طŵ�ץͼģʽ
    virtual bool setCapturePictureMode(DWORD dwCaptureMode){return false;};

    /*�ļ���ý�岥�ſ���*/
    virtual intptr_t captureFileStream( LPCAPTURESTREAMCALLBACK lpCallBack, void* pUser, int nStreamType, RECORDFILE FileInfo, char* sType){return -1;};

    virtual bool buildSerialSend(LONG lSerialPort,LPSERIALDATACALLBACK pSerialCallBack,bool bOpen){return false;};
    virtual bool serialSendWithCallBack(char* pBuf,DWORD nLength,int nCameraID){return false;};
    static void CALLBACK SerialDataCallBack(LONG lSerialHandle,char *pRecvDataBuffer,DWORD dwBufSize,DWORD dwUser){return;};

    //2009-08-17 ����(����֧�ֻ���)
    //! ��ȡ����������ľ�ͷ��Ϣ
    LONG getCameraInfo(int *){return 0;}
    //!���ò��Ŵ��ھ��(����)
    int setPlayWindow(HWND [], int ){return 0;}
    //!���ž�ͷ�����ھ��(����)
    bool  startPlayerByCamera(HWND , int ){return false;}
    //!ֹͣ���Ŵ��ھ��(����)
    bool stopPlayerByCamera(HWND , int ){return false;}
    void setCurrentCameraCode(char* ){return;};
    bool queryPorperySupport(XYPROPROPERTY ){return false;};
    bool startRecord(char* ){return false;}
    bool stopRecord(){return false;}
    public:
        int m_nStreamType;
};

#endif // DHPlayHandle_h__