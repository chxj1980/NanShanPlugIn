// **********************************************************************
//
// Copyright (c) 2006 ZeroThink, Inc. All rights reserved.
//
// **********************************************************************

#ifndef ZT_NVSINDEXDATA_H
#define ZT_NVSINDEXDATA_H


module NVSIndex
{
// ����IP��Port�ṹ
struct YPAddress
{
	// IP��ַ
	string			IP;
	// Port�˿�
	int				Port;
};

// ����Nat����ö��
enum NATTYPE {UNKNOWN,GLOBALIP,FULLCONE,RESTRICTCONE,PORTRESTRICTCONE,SYMMETRY};
//����ID����,
enum IDTYPE {ITCAMERAID,  ITSTOREID};  

// ��������ͷ������Ϣ
struct NVSCameraInfo
{
	// Ψһ��־
	int				CameraID;
	// �Ƿ���Ч
	bool			Valid;
	// ����
	int				CameraType;
	// Ӳ��¼�����ID
	int				DVRID;
	// ͨ�����
	int				ChannelID;
	// �ַ���ͨ����� ����
	string			ChannelStrID;
	// ͨ������
	string			ChannelName;
	// ����ͷ��ģʽ
	int				OpenType;
	string          sOpenType;
	// ͳһ����
	string          ChannelNO;
	//ԭʼ�ľ���ͷID
	int             PriorCameraID;
	//����ͷ�Ƿ���ռ true -- ����ռ  false -- δ����ռ
	bool            bGrabed;
	//����������Ϣ ����
	int		   DecodeType;
	string          sDecodeType;
};

// ��������ͷ����
sequence<NVSCameraInfo>		NVSCameraPool;
// �����ַ������ӳ�
sequence<string>			NVSConnectStrPool;

//������������IPServer��Ϣ
struct IPServerInfo
{
	// ����IP
	string		sIPIn;
	// ����Port
	int			nPortIn;
	// ����IP
	string		sIPOut;
	// ����Port
	int			nPortOut;
	
	//��չIP
	string     sThirdIP;
	//��չ�˿�
	int        nThirdPort;
};
// ����Ӳ��¼���������Ϣ
struct NVSDVRInfo
{
	// Ψһ��־
	int				DVRID;
	// �Ƿ��ѷ���
	bool			Valid;
	// ����
	int				DVRType;
	// IP
	string			IP;
	// �˿�
	int				Port;
	// �û���
	string			UserName;
	// ����
	string			UserPwd;
	// �Ƿ��Ѿ�����Ӧ����ý�����׼����
	bool			Ready;
	// Dvr���õ�Ψһ��ʶ
	string			DVRTypeKey;
	// ����Ͻ������ͷ
	NVSCameraPool	CameraPool;
	// DVR��ʹ�õ�����
	int				DvrFrequency;
	// ����������־
	bool	        IsDNS;
	// DVR���к�
	string  		DvrSerialNO;
	// ������������IPServer
	IPServerInfo    ServerInfo;
	//�Ƿ����VIS��ͷ
	bool            bUseed2Vis;
	//DVR���뷽ʽ ƽ̨���豸 ����
    	string SDVRAccessType;

};

// ����Ӳ��¼���������Ϣ
struct NVSDVRInfoEx
{
	NVSDVRInfo dvrinfo;
		// �ⲿIP
	string			ExternalIP;
	// �ⲿ�˿�
	int				ExternalPort;
	
};
// ����Ӳ��¼�������
sequence<NVSDVRInfo>			NVSDVRPool;

// ������ý�����Ļ�����Ϣ�ṹ
struct NVSStreamServiceInfo
{
	// ����Ψһ��־
	int				Key;
	// ���õ�IP��ַ�Ͷ˿�
	YPAddress		ServiceAddress;
	// ������
	string			ServiceKey;
	// ��ǰ���ص���Ƶ����
	int				VideoLoad;
	// ��ǰ���صĿͻ��˸���
	int				MonitorLoad;
	// ��������
	string			Type;
};

// ����һ���û���Ϣ�ṹ
struct NVSMonitorInfo
{
	// �Ƿ���Դ���������־�Ƿ���ֱ�������StreamService��
	bool			Root;
	// �ڲ�IP��ַ
	int				IPInline;
	// �ⲿIP��ַ
	int				IPOutline;
	// ��ǰ״̬
	byte			Status;
	// ���ݽ������Ӹ���
	byte			CurIncomingCount;
	// ���ݳ������Ӹ���
	byte			CurOutgoingCount;
	// �����Ψһ��ʾ����YP���ӹ�����
	int				ID;
	// ����Nat����
	NATTYPE			DoorType;
	// ���ӵĿ�ʼʱ��
	int				StartTime;
	// Ȩ��
	int				Right;
};

//ϵͳ����״̬
struct SystemState
{
	int nClientCount; //�ͻ��˸���
	int nStreamCount; //��ý�����
	
};

};
#endif
