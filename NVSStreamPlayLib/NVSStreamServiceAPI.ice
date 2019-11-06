#ifndef ZT_NVSSTREAMSERVICEAPI_H
#define ZT_NVSSTREAMSERVICEAPI_H

#include <Ice/Identity.ice>


module NVSStreamService
{

	// ����������
	sequence<byte>		StreamContent;
	// �������ݰ�˵����Ϣ
	struct PieceInfo
	{
		// ͨ����ʶ
		string			sCameraID;
		// ����
		string			sDVRKey;
		// ʱ���
		long			TimeStampX;
	};
	struct DeviceInfo
	{
		string sIP;
		string sUser;
		string sPassword;
		int nPort;
		int nChannel;
		string sChannel;
		string sType;
	};

	// ���������ݿ�
	struct StreamPiece
	{
		// ������˵����Ϣ
		PieceInfo		Description;
		// ������
		StreamContent	Data;
	};
	// ����������
	sequence<StreamPiece>		StreamData;
	
	struct WorkState
	{
		// ����DVR����
		int				DvrLoad;
		// ͨ�����Ӹ���
		int				ChannelLoad;
		// �ͻ������Ӹ���
		int				MonitorLoad;
		// �ܹ����͵�·��
		int				SendLoad;
		//����͸���
		int				MaxSendCount;
		//���������Ƶͨ������ 
		int				MaxChannel;
	};
	interface NVSStreamDataReceiver
	{
	    ["ami"] bool sendStreamBody(StreamPiece sd);
	    ["ami"] bool sendStreamHead(StreamPiece sd);
	};

	interface NVSStreamServiceAPI
	{	
	    //������Ƶ
		int startPlayer(DeviceInfo connectInfo, Ice::Identity ident,out string sKey);
		
		//ֹͣ����
		int stopVideo(string sKeyID);
		
		// ��ȡ����״̬
		void getWorkState(out WorkState wkState);

		// ѹ��������ȡ 
		int getCompress(string sKeyID,out string sInfo);

		// ѹ������
		void setCompress(string sKeyID,string sInfo);

		// ��ȡ��Ƶ����
		int getVideoEffect(string sKeyID,out int dwBrightValue,out int dwContrastValue,out int dwSaturationValue,out int dwHueValue);

		// ������Ƶ����
		void setVideoEffect(string sKeyID,int dwBrightValue,int dwContrastValue,int dwSaturationValue,int dwHueValue);

		// �ͻ������������̨
		int requestControlCamera(string sKeyID);

		// ��̨�ٶȿ���
		int controlCameraSpeed(string sKeyID,int nCmd, bool bEnable,int nSpeed);

		// �ͻ��˹رտ�����̨;
		int cancelControlCamera(string sKeyID);

		// �ͻ���Ԥ��λָ�� 
		int presetPTZ(string sKeyID,int nCmd,int nIndex);
		
		//�ͻ�������
		void HeartBeat();			
	};

};


#endif
