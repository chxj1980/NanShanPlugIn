// **********************************************************************
//
// Copyright (c) 2003-2006 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************

// Ice version 3.1.1
// Generated from file `NVSIndexData.ice'

#ifndef _____ICE_NVSIndexData_h__
#define _____ICE_NVSIndexData_h__

#include <Ice/LocalObjectF.h>
#include <Ice/ProxyF.h>
#include <Ice/ObjectF.h>
#include <Ice/Exception.h>
#include <Ice/LocalObject.h>
#include <Ice/UndefSysMacros.h>

#ifndef ICE_IGNORE_VERSION
#   if ICE_INT_VERSION / 100 != 301
#       error Ice version mismatch!
#   endif
#   if ICE_INT_VERSION % 100 < 1
#       error Ice patch level mismatch!
#   endif
#endif

namespace NVSIndex
{

struct YPAddress
{
    ::std::string IP;
    ::Ice::Int Port;

    bool operator==(const YPAddress&) const;
    bool operator!=(const YPAddress&) const;
    bool operator<(const YPAddress&) const;
    bool operator<=(const YPAddress& __rhs) const
    {
	return operator<(__rhs) || operator==(__rhs);
    }
    bool operator>(const YPAddress& __rhs) const
    {
	return !operator<(__rhs) && !operator==(__rhs);
    }
    bool operator>=(const YPAddress& __rhs) const
    {
	return !operator<(__rhs);
    }

    void __write(::IceInternal::BasicStream*) const;
    void __read(::IceInternal::BasicStream*);
};

enum NATTYPE
{
    UNKNOWN,
    GLOBALIP,
    FULLCONE,
    RESTRICTCONE,
    PORTRESTRICTCONE,
    SYMMETRY
};

void __write(::IceInternal::BasicStream*, NATTYPE);
void __read(::IceInternal::BasicStream*, NATTYPE&);

enum IDTYPE
{
    ITCAMERAID,
    ITSTOREID
};

void __write(::IceInternal::BasicStream*, IDTYPE);
void __read(::IceInternal::BasicStream*, IDTYPE&);

struct NVSCameraInfo
{
    ::Ice::Int CameraID;
    bool Valid;
    ::Ice::Int CameraType;
    ::Ice::Int DVRID;
    ::Ice::Int ChannelID;
    ::std::string ChannelStrID;
    ::std::string ChannelName;
    ::Ice::Int OpenType;
    ::std::string sOpenType;
    ::std::string ChannelNO;
    ::Ice::Int PriorCameraID;
    bool bGrabed;
    ::Ice::Int DecodeType;
    ::std::string sDecodeType;

    bool operator==(const NVSCameraInfo&) const;
    bool operator!=(const NVSCameraInfo&) const;
    bool operator<(const NVSCameraInfo&) const;
    bool operator<=(const NVSCameraInfo& __rhs) const
    {
	return operator<(__rhs) || operator==(__rhs);
    }
    bool operator>(const NVSCameraInfo& __rhs) const
    {
	return !operator<(__rhs) && !operator==(__rhs);
    }
    bool operator>=(const NVSCameraInfo& __rhs) const
    {
	return !operator<(__rhs);
    }

    void __write(::IceInternal::BasicStream*) const;
    void __read(::IceInternal::BasicStream*);
};

typedef ::std::vector< ::NVSIndex::NVSCameraInfo> NVSCameraPool;

class __U__NVSCameraPool { };
void __write(::IceInternal::BasicStream*, const ::NVSIndex::NVSCameraInfo*, const ::NVSIndex::NVSCameraInfo*, __U__NVSCameraPool);
void __read(::IceInternal::BasicStream*, NVSCameraPool&, __U__NVSCameraPool);

typedef ::std::vector< ::std::string> NVSConnectStrPool;

class __U__NVSConnectStrPool { };

struct IPServerInfo
{
    ::std::string sIPIn;
    ::Ice::Int nPortIn;
    ::std::string sIPOut;
    ::Ice::Int nPortOut;

    bool operator==(const IPServerInfo&) const;
    bool operator!=(const IPServerInfo&) const;
    bool operator<(const IPServerInfo&) const;
    bool operator<=(const IPServerInfo& __rhs) const
    {
	return operator<(__rhs) || operator==(__rhs);
    }
    bool operator>(const IPServerInfo& __rhs) const
    {
	return !operator<(__rhs) && !operator==(__rhs);
    }
    bool operator>=(const IPServerInfo& __rhs) const
    {
	return !operator<(__rhs);
    }

    void __write(::IceInternal::BasicStream*) const;
    void __read(::IceInternal::BasicStream*);
};

struct NVSDVRInfo
{
    ::Ice::Int DVRID;
    bool Valid;
    ::Ice::Int DVRType;
    ::std::string IP;
    ::Ice::Int Port;
    ::std::string UserName;
    ::std::string UserPwd;
    bool Ready;
    ::std::string DVRTypeKey;
    ::NVSIndex::NVSCameraPool CameraPool;
    ::Ice::Int DvrFrequency;
    bool IsDNS;
    ::std::string DvrSerialNO;
    ::NVSIndex::IPServerInfo ServerInfo;
    bool bUseed2Vis;
    ::std::string SDVRAccessType;

    bool operator==(const NVSDVRInfo&) const;
    bool operator!=(const NVSDVRInfo&) const;
    bool operator<(const NVSDVRInfo&) const;
    bool operator<=(const NVSDVRInfo& __rhs) const
    {
	return operator<(__rhs) || operator==(__rhs);
    }
    bool operator>(const NVSDVRInfo& __rhs) const
    {
	return !operator<(__rhs) && !operator==(__rhs);
    }
    bool operator>=(const NVSDVRInfo& __rhs) const
    {
	return !operator<(__rhs);
    }

    void __write(::IceInternal::BasicStream*) const;
    void __read(::IceInternal::BasicStream*);
};

struct NVSDVRInfoEx
{
    ::NVSIndex::NVSDVRInfo dvrinfo;
    ::std::string ExternalIP;
    ::Ice::Int ExternalPort;

    bool operator==(const NVSDVRInfoEx&) const;
    bool operator!=(const NVSDVRInfoEx&) const;
    bool operator<(const NVSDVRInfoEx&) const;
    bool operator<=(const NVSDVRInfoEx& __rhs) const
    {
	return operator<(__rhs) || operator==(__rhs);
    }
    bool operator>(const NVSDVRInfoEx& __rhs) const
    {
	return !operator<(__rhs) && !operator==(__rhs);
    }
    bool operator>=(const NVSDVRInfoEx& __rhs) const
    {
	return !operator<(__rhs);
    }

    void __write(::IceInternal::BasicStream*) const;
    void __read(::IceInternal::BasicStream*);
};

typedef ::std::vector< ::NVSIndex::NVSDVRInfo> NVSDVRPool;

class __U__NVSDVRPool { };
void __write(::IceInternal::BasicStream*, const ::NVSIndex::NVSDVRInfo*, const ::NVSIndex::NVSDVRInfo*, __U__NVSDVRPool);
void __read(::IceInternal::BasicStream*, NVSDVRPool&, __U__NVSDVRPool);

struct NVSStreamServiceInfo
{
    ::Ice::Int Key;
    ::NVSIndex::YPAddress ServiceAddress;
    ::std::string ServiceKey;
    ::Ice::Int VideoLoad;
    ::Ice::Int MonitorLoad;
    ::std::string Type;

    bool operator==(const NVSStreamServiceInfo&) const;
    bool operator!=(const NVSStreamServiceInfo&) const;
    bool operator<(const NVSStreamServiceInfo&) const;
    bool operator<=(const NVSStreamServiceInfo& __rhs) const
    {
	return operator<(__rhs) || operator==(__rhs);
    }
    bool operator>(const NVSStreamServiceInfo& __rhs) const
    {
	return !operator<(__rhs) && !operator==(__rhs);
    }
    bool operator>=(const NVSStreamServiceInfo& __rhs) const
    {
	return !operator<(__rhs);
    }

    void __write(::IceInternal::BasicStream*) const;
    void __read(::IceInternal::BasicStream*);
};

struct NVSMonitorInfo
{
    bool Root;
    ::Ice::Int IPInline;
    ::Ice::Int IPOutline;
    ::Ice::Byte Status;
    ::Ice::Byte CurIncomingCount;
    ::Ice::Byte CurOutgoingCount;
    ::Ice::Int ID;
    ::NVSIndex::NATTYPE DoorType;
    ::Ice::Int StartTime;
    ::Ice::Int Right;

    bool operator==(const NVSMonitorInfo&) const;
    bool operator!=(const NVSMonitorInfo&) const;
    bool operator<(const NVSMonitorInfo&) const;
    bool operator<=(const NVSMonitorInfo& __rhs) const
    {
	return operator<(__rhs) || operator==(__rhs);
    }
    bool operator>(const NVSMonitorInfo& __rhs) const
    {
	return !operator<(__rhs) && !operator==(__rhs);
    }
    bool operator>=(const NVSMonitorInfo& __rhs) const
    {
	return !operator<(__rhs);
    }

    void __write(::IceInternal::BasicStream*) const;
    void __read(::IceInternal::BasicStream*);
};

struct SystemState
{
    ::Ice::Int nClientCount;
    ::Ice::Int nStreamCount;

    bool operator==(const SystemState&) const;
    bool operator!=(const SystemState&) const;
    bool operator<(const SystemState&) const;
    bool operator<=(const SystemState& __rhs) const
    {
	return operator<(__rhs) || operator==(__rhs);
    }
    bool operator>(const SystemState& __rhs) const
    {
	return !operator<(__rhs) && !operator==(__rhs);
    }
    bool operator>=(const SystemState& __rhs) const
    {
	return !operator<(__rhs);
    }

    void __write(::IceInternal::BasicStream*) const;
    void __read(::IceInternal::BasicStream*);
};

}

#endif
