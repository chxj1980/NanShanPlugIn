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
	//功能1 StreamService启动时向Index注册
	bool registerMe(NVSStreamServiceInfo frontInfo,Ice::Identity ident,out NVSStreamServiceInfo backInfo);
	
	//功能2 保持连接
	void heartBeat(int nID);
	
	//功能3 获取dvr信息
	bool getDvrInfo(int nCameraID,out NVSDVRInfo backInfo);
	
	//功能4 获取源流媒体服务信息
	byte getSouceStreamService(int cameraID,out string sSSProxy,out int serviceKey);
	
	//功能5 传输自身负载信息
	void transferLoad(string sServerKey,NVSCameraPool vCameraPool,int nMonitorLoad);

	//功能7 控制服务获取自身控制的DVR对象池
	void getDvrPools(string sKey,out NVSDVRPool backInfo);	
	
	//功能8 获取dvr信息
	bool getDvrInfoEx(int nCameraID,out NVSDVRInfoEx backInfo);
};

interface NVSIndex4StreamSend  //暂时无用
{
    //功能1 索引服务通知控制服务需要重新获取DVR对象池
    void notifyControlReload();
    //功能2 索引服务主动测试子服务是否连接正常
    void notifyServiceConnect();
};
};

#endif
