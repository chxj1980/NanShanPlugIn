// **********************************************************************
//
// Copyright (c) 2006 ZeroThink, Inc. All rights reserved.
//
// **********************************************************************

#ifndef ZT_NVSINDEXDATA_H
#define ZT_NVSINDEXDATA_H


module NVSIndex
{
// 定义IP和Port结构
struct YPAddress
{
	// IP地址
	string			IP;
	// Port端口
	int				Port;
};

// 定义Nat类型枚举
enum NATTYPE {UNKNOWN,GLOBALIP,FULLCONE,RESTRICTCONE,PORTRESTRICTCONE,SYMMETRY};
//定义ID类型,
enum IDTYPE {ITCAMERAID,  ITSTOREID};  

// 定义摄像头连接信息
struct NVSCameraInfo
{
	// 唯一标志
	int				CameraID;
	// 是否有效
	bool			Valid;
	// 类型
	int				CameraType;
	// 硬盘录像机的ID
	int				DVRID;
	// 通道标号
	int				ChannelID;
	// 字符型通道标号 新增
	string			ChannelStrID;
	// 通道名称
	string			ChannelName;
	// 摄像头打开模式
	int				OpenType;
	string          sOpenType;
	// 统一编码
	string          ChannelNO;
	//原始的矩阵镜头ID
	int             PriorCameraID;
	//矩阵镜头是否被抢占 true -- 被抢占  false -- 未被抢占
	bool            bGrabed;
	//解码类型信息 新增
	int		   DecodeType;
	string          sDecodeType;
};

// 定义摄像头数组
sequence<NVSCameraInfo>		NVSCameraPool;
// 定义字符串连接池
sequence<string>			NVSConnectStrPool;

//定义域名解析IPServer信息
struct IPServerInfo
{
	// 内网IP
	string		sIPIn;
	// 内网Port
	int			nPortIn;
	// 外网IP
	string		sIPOut;
	// 外网Port
	int			nPortOut;
	
	//扩展IP
	string     sThirdIP;
	//扩展端口
	int        nThirdPort;
};
// 定义硬盘录像机连接信息
struct NVSDVRInfo
{
	// 唯一标志
	int				DVRID;
	// 是否已分配
	bool			Valid;
	// 类型
	int				DVRType;
	// IP
	string			IP;
	// 端口
	int				Port;
	// 用户名
	string			UserName;
	// 密码
	string			UserPwd;
	// 是否已经和相应的流媒体服务准备好
	bool			Ready;
	// Dvr所用的唯一标识
	string			DVRTypeKey;
	// 所管辖的摄像头
	NVSCameraPool	CameraPool;
	// DVR所使用的码流
	int				DvrFrequency;
	// 域名解析标志
	bool	        IsDNS;
	// DVR序列号
	string  		DvrSerialNO;
	// 域名解析服务IPServer
	IPServerInfo    ServerInfo;
	//是否针对VIS镜头
	bool            bUseed2Vis;
	//DVR接入方式 平台或设备 新增
    	string SDVRAccessType;

};

// 定义硬盘录像机连接信息
struct NVSDVRInfoEx
{
	NVSDVRInfo dvrinfo;
		// 外部IP
	string			ExternalIP;
	// 外部端口
	int				ExternalPort;
	
};
// 定义硬盘录像机数组
sequence<NVSDVRInfo>			NVSDVRPool;

// 定义流媒体服务的基本信息结构
struct NVSStreamServiceInfo
{
	// 自身唯一标志
	int				Key;
	// 所用的IP地址和端口
	YPAddress		ServiceAddress;
	// 特征字
	string			ServiceKey;
	// 当前负载的视频个数
	int				VideoLoad;
	// 当前负载的客户端个数
	int				MonitorLoad;
	// 服务类型
	string			Type;
};

// 定义一般用户信息结构
struct NVSMonitorInfo
{
	// 是否是源（在这里标志是否是直接请求的StreamService）
	bool			Root;
	// 内部IP地址
	int				IPInline;
	// 外部IP地址
	int				IPOutline;
	// 当前状态
	byte			Status;
	// 数据进来连接个数
	byte			CurIncomingCount;
	// 数据出来连接个数
	byte			CurOutgoingCount;
	// 分配的唯一标示（与YP连接关联）
	int				ID;
	// 自身Nat类型
	NATTYPE			DoorType;
	// 连接的开始时间
	int				StartTime;
	// 权限
	int				Right;
};

//系统运行状态
struct SystemState
{
	int nClientCount; //客户端个数
	int nStreamCount; //流媒体个数
	
};

};
#endif
