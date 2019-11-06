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

struct IndexNoticeInfo  //用于存储RightChange表中的字段
{
	int nUserID;     //用户ID
	int nChangeType; //更改类型
	int nLimitTime;  //限时重启时间
};    
	
interface NVSIndexNotice
{
	//索引服务在定时数据检测线程中增加检测数据表RightChange，当发现有新的用户修改记录时，群发广播本消息
	["ami"] bool notifyClient(IndexNoticeInfo NoticeInfo);
	//在客户端视频被切换时，向客户端发通知消息
	["ami"] bool notifySwitched(int nMonitorID,int nPriorCameraID,int nCameraID,string Description);
};
	
interface NVSIndex4Monitor
{
	//接口1 Monitor向Index注册
	bool registerMe(NVSMonitorInfo outInfo,out NVSMonitorInfo backInfo);
	
	//接口2 Monitor向Index请求摄像头的录像在哪个StreamService上,返回 [0]可直连获取 [1]没有StreamService来管理硬盘录像机 [2]都已分配好，也取得相应的StreamService，不过当前这个StreamService还没有Ready这个硬盘录像机  [3]未知错误） 
	byte getStreamService(int MonitorID,int cameraID,out string sSSProxy,out int serviceKey);
	
	//接口2扩展 区别：返回的流媒体地址是外部IP地址
	byte getExternalStreamService(int MonitorID,int cameraID,out string sSSProxy,out int serviceKey);
	//接口3 保持连接
	void heartBeat(int nID);
	
	//接口4 获取某个DVR的信息
	bool getDvrInfo(int nID,out NVSDVRInfo backInfo);
	
	//接口5 获取所有在线状态的流媒体服务的连接字符串
	void getStreamOnline(out NVSConnectStrPool backInfo);
	
	//接口6 获取控制服务字符串代理
	int  getControlService(int cameraID,out string sSSProxy,out int serviceKey);
	
	//接口7 获取客户端连接数和流媒体连接数
	void getStreamMonitorNum(out int nStreamNum,out int nMonitorNum);
	
	//接口8 远程控制重启服务器
	bool reSetServer();
	
	//接口9 检测修改时间是否需要客户端重启
	bool checkNeedRebootSyn(int nUID, int nOrgID, string sLastLoginTime);
	
	//接口10 通知回调对象建立完成
	bool NoticeReady(int nID,::Ice::Identity id);
	
	//接口14 索引重连后客户端ID发生变化，此时需要更新
	//以保证在通知客户端的时候可以找到ID发生变化的客户端
	bool UpdateClientID(int nNewID,int nPriorID);
	
	//接口11 客户端通知VIS服务已经释放使用此视频的用户
	bool NoticeReleaseUser(int nID,int nCameraID);
	
	//接口12 客户端通知VIS服务释放此用户的所有视频
	bool NoticeReleaseUserAll(int nUserID);
	
	//接口13 CameraID转换成全市统一编码
	string ConvertCameraID(int nCameraID);
	
	//接口14 获取系统运行状态
	 void getSystemRunState(out SystemState ss);
	//接口14 保持连接 带返回值的
	//增加客户端的权限值
	bool heartBeatRetVaule(int nID,int nRight);
	
	//nNetType = 1 内网; =2 外网; 3 扩展IP
	byte getStreamService2(int MonitorID, int nNetType,int cameraID,out string sSSProxy,out int serviceKey);
};

};

#endif
