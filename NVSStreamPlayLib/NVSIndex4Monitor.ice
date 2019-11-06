// **********************************************************************
//
// Copyright (c) 2006 ZeroThink, Inc. All rights reserved.
//
// **********************************************************************

#ifndef ZT_NVSINDEX4MONITOR_H
#define ZT_NVSINDEX4MONITOR_H

#include <Ice/Identity.ice>
#include "NVSIndexData.ice"


module NVSIndex
{

exception RangeError {};
interface NVSModel 
{
	["ami", "amd"] int checkNeedReboot(int nUID, int nOrgID, string sLastLoginTime) throws RangeError;
};

struct IndexNoticeInfo  //���ڴ洢RightChange���е��ֶ�
{
	int nUserID;     //�û�ID
	int nChangeType; //��������
	int nLimitTime;  //��ʱ����ʱ��
};    
	
interface NVSIndexNotice
{
	//���������ڶ�ʱ���ݼ���߳������Ӽ�����ݱ�RightChange�����������µ��û��޸ļ�¼ʱ��Ⱥ���㲥����Ϣ
	["ami"] bool notifyClient(IndexNoticeInfo NoticeInfo);
	//�ڿͻ�����Ƶ���л�ʱ����ͻ��˷�֪ͨ��Ϣ
	["ami"] bool notifySwitched(int nMonitorID,int nPriorCameraID,int nCameraID,string Description);
};
	
interface NVSIndex4Monitor
{
	//�ӿ�1 Monitor��Indexע��
	bool registerMe(NVSMonitorInfo outInfo,out NVSMonitorInfo backInfo);
	
	//�ӿ�2 Monitor��Index��������ͷ��¼�����ĸ�StreamService��,���� [0]��ֱ����ȡ [1]û��StreamService������Ӳ��¼��� [2]���ѷ���ã�Ҳȡ����Ӧ��StreamService��������ǰ���StreamService��û��Ready���Ӳ��¼���  [3]δ֪���� 
	byte getStreamService(int MonitorID,int cameraID,out string sSSProxy,out int serviceKey);
	
	//�ӿ�2��չ ���𣺷��ص���ý���ַ���ⲿIP��ַ
	byte getExternalStreamService(int MonitorID,int cameraID,out string sSSProxy,out int serviceKey);
	//�ӿ�3 ��������
	void heartBeat(int nID);
	
	//�ӿ�4 ��ȡĳ��DVR����Ϣ
	bool getDvrInfo(int nID,out NVSDVRInfo backInfo);
	
	//�ӿ�5 ��ȡ��������״̬����ý�����������ַ���
	void getStreamOnline(out NVSConnectStrPool backInfo);
	
	//�ӿ�6 ��ȡ���Ʒ����ַ�������
	int  getControlService(int cameraID,out string sSSProxy,out int serviceKey);
	
	//�ӿ�7 ��ȡ�ͻ�������������ý��������
	void getStreamMonitorNum(out int nStreamNum,out int nMonitorNum);
	
	//�ӿ�8 Զ�̿�������������
	bool reSetServer();
	
	//�ӿ�9 ����޸�ʱ���Ƿ���Ҫ�ͻ�������
	bool checkNeedRebootSyn(int nUID, int nOrgID, string sLastLoginTime);
	
	//�ӿ�10 ֪ͨ�ص����������
	bool NoticeReady(int nID,::Ice::Identity id);
	
	//�ӿ�14 ����������ͻ���ID�����仯����ʱ��Ҫ����
	//�Ա�֤��֪ͨ�ͻ��˵�ʱ������ҵ�ID�����仯�Ŀͻ���
	bool UpdateClientID(int nNewID,int nPriorID);
	
	//�ӿ�11 �ͻ���֪ͨVIS�����Ѿ��ͷ�ʹ�ô���Ƶ���û�
	bool NoticeReleaseUser(int nID,int nCameraID);
	
	//�ӿ�12 �ͻ���֪ͨVIS�����ͷŴ��û���������Ƶ
	bool NoticeReleaseUserAll(int nUserID);
	
	//�ӿ�13 CameraIDת����ȫ��ͳһ����
	string ConvertCameraID(int nCameraID);
	
	//�ӿ�14 ��ȡϵͳ����״̬
	 void getSystemRunState(out SystemState ss);
	//�ӿ�14 �������� ������ֵ��
	//���ӿͻ��˵�Ȩ��ֵ
	bool heartBeatRetVaule(int nID,int nRight);
	
	//nNetType = 1 ����; =2 ����; 3 ��չIP
	byte getStreamService2(int MonitorID, int nNetType,int cameraID,out string sSSProxy,out int serviceKey);
};

};

#endif
