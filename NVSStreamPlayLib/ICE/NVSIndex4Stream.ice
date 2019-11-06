// **********************************************************************
//
// Copyright (c) 2006 ZeroThink, Inc. All rights reserved.
//
// **********************************************************************

#ifndef ZT_NVSINDEX4STREAM_H
#define ZT_NVSINDEX4STREAM_H

#include <Ice/Identity.ice>
#include "NVSIndexData.ice"

module NVSIndex
{
interface NVSIndex4Stream
{
	//����1 StreamService����ʱ��Indexע��
	bool registerMe(NVSStreamServiceInfo frontInfo,Ice::Identity ident,out NVSStreamServiceInfo backInfo);
	
	//����2 ��������
	void heartBeat(int nID);
	
	//����3 ��ȡdvr��Ϣ
	bool getDvrInfo(int nCameraID,out NVSDVRInfo backInfo);
	
	//����4 ��ȡԴ��ý�������Ϣ
	byte getSouceStreamService(int cameraID,out string sSSProxy,out int serviceKey);
	
	//����5 ������������Ϣ
	void transferLoad(string sServerKey,NVSCameraPool vCameraPool,int nMonitorLoad);

	//����7 ���Ʒ����ȡ������Ƶ�DVR�����
	void getDvrPools(string sKey,out NVSDVRPool backInfo);	
	
	//����8 ��ȡdvr��Ϣ
	bool getDvrInfoEx(int nCameraID,out NVSDVRInfoEx backInfo);
};

interface NVSIndex4StreamSend  //��ʱ����
{
    //����1 ��������֪ͨ���Ʒ�����Ҫ���»�ȡDVR�����
    void notifyControlReload();
    //����2 �����������������ӷ����Ƿ���������
    void notifyServiceConnect();
};
};

#endif
