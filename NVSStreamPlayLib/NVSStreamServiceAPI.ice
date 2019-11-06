#ifndef ZT_NVSSTREAMSERVICEAPI_H
#define ZT_NVSSTREAMSERVICEAPI_H

#include <Ice/Identity.ice>


module NVSStreamService
{

	// 定义流类型
	sequence<byte>		StreamContent;
	// 定义数据包说明信息
	struct PieceInfo
	{
		// 通道标识
		string			sCameraID;
		// 类型
		string			sDVRKey;
		// 时间戳
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

	// 定义流数据块
	struct StreamPiece
	{
		// 流数据说明信息
		PieceInfo		Description;
		// 流数据
		StreamContent	Data;
	};
	// 定义流数据
	sequence<StreamPiece>		StreamData;
	
	struct WorkState
	{
		// 连接DVR个数
		int				DvrLoad;
		// 通道连接个数
		int				ChannelLoad;
		// 客户端连接个数
		int				MonitorLoad;
		// 总共发送的路数
		int				SendLoad;
		//最大发送个数
		int				MaxSendCount;
		//最大连接视频通道个数 
		int				MaxChannel;
	};
	interface NVSStreamDataReceiver
	{
	    ["ami"] bool sendStreamBody(StreamPiece sd);
	    ["ami"] bool sendStreamHead(StreamPiece sd);
	};

	interface NVSStreamServiceAPI
	{	
	    //播放视频
		int startPlayer(DeviceInfo connectInfo, Ice::Identity ident,out string sKey);
		
		//停止播放
		int stopVideo(string sKeyID);
		
		// 获取工作状态
		void getWorkState(out WorkState wkState);

		// 压缩参数获取 
		int getCompress(string sKeyID,out string sInfo);

		// 压缩配置
		void setCompress(string sKeyID,string sInfo);

		// 获取视频参数
		int getVideoEffect(string sKeyID,out int dwBrightValue,out int dwContrastValue,out int dwSaturationValue,out int dwHueValue);

		// 设置视频参数
		void setVideoEffect(string sKeyID,int dwBrightValue,int dwContrastValue,int dwSaturationValue,int dwHueValue);

		// 客户端请求控制云台
		int requestControlCamera(string sKeyID);

		// 云台速度控制
		int controlCameraSpeed(string sKeyID,int nCmd, bool bEnable,int nSpeed);

		// 客户端关闭控制云台;
		int cancelControlCamera(string sKeyID);

		// 客户端预置位指令 
		int presetPTZ(string sKeyID,int nCmd,int nIndex);
		
		//客户端心跳
		void HeartBeat();			
	};

};


#endif
