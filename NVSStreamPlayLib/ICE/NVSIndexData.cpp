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
#include "stdafx.h"
#include "NVSIndexData.h"
#include <Ice/BasicStream.h>
#include <Ice/Object.h>
#include <IceUtil/Iterator.h>

#ifndef ICE_IGNORE_VERSION
#   if ICE_INT_VERSION / 100 != 301
#       error Ice version mismatch!
#   endif
#   if ICE_INT_VERSION % 100 < 1
#       error Ice patch level mismatch!
#   endif
#endif

bool
NVSIndex::YPAddress::operator==(const YPAddress& __rhs) const
{
    return !operator!=(__rhs);
}

bool
NVSIndex::YPAddress::operator!=(const YPAddress& __rhs) const
{
    if(this == &__rhs)
    {
	return false;
    }
    if(IP != __rhs.IP)
    {
	return true;
    }
    if(Port != __rhs.Port)
    {
	return true;
    }
    return false;
}

bool
NVSIndex::YPAddress::operator<(const YPAddress& __rhs) const
{
    if(this == &__rhs)
    {
	return false;
    }
    if(IP < __rhs.IP)
    {
	return true;
    }
    else if(__rhs.IP < IP)
    {
	return false;
    }
    if(Port < __rhs.Port)
    {
	return true;
    }
    else if(__rhs.Port < Port)
    {
	return false;
    }
    return false;
}

void
NVSIndex::YPAddress::__write(::IceInternal::BasicStream* __os) const
{
    __os->write(IP);
    __os->write(Port);
}

void
NVSIndex::YPAddress::__read(::IceInternal::BasicStream* __is)
{
    __is->read(IP);
    __is->read(Port);
}

void
NVSIndex::__write(::IceInternal::BasicStream* __os, ::NVSIndex::NATTYPE v)
{
    __os->write(static_cast< ::Ice::Byte>(v));
}

void
NVSIndex::__read(::IceInternal::BasicStream* __is, ::NVSIndex::NATTYPE& v)
{
    ::Ice::Byte val;
    __is->read(val);
    v = static_cast< ::NVSIndex::NATTYPE>(val);
}

void
NVSIndex::__write(::IceInternal::BasicStream* __os, ::NVSIndex::IDTYPE v)
{
    __os->write(static_cast< ::Ice::Byte>(v));
}

void
NVSIndex::__read(::IceInternal::BasicStream* __is, ::NVSIndex::IDTYPE& v)
{
    ::Ice::Byte val;
    __is->read(val);
    v = static_cast< ::NVSIndex::IDTYPE>(val);
}

bool
NVSIndex::NVSCameraInfo::operator==(const NVSCameraInfo& __rhs) const
{
    return !operator!=(__rhs);
}

bool
NVSIndex::NVSCameraInfo::operator!=(const NVSCameraInfo& __rhs) const
{
    if(this == &__rhs)
    {
	return false;
    }
    if(CameraID != __rhs.CameraID)
    {
	return true;
    }
    if(Valid != __rhs.Valid)
    {
	return true;
    }
    if(CameraType != __rhs.CameraType)
    {
	return true;
    }
    if(DVRID != __rhs.DVRID)
    {
	return true;
    }
    if(ChannelID != __rhs.ChannelID)
    {
	return true;
    }
    if(ChannelStrID != __rhs.ChannelStrID)
    {
	return true;
    }
    if(ChannelName != __rhs.ChannelName)
    {
	return true;
    }
    if(OpenType != __rhs.OpenType)
    {
	return true;
    }
    if(sOpenType != __rhs.sOpenType)
    {
	return true;
    }
    if(ChannelNO != __rhs.ChannelNO)
    {
	return true;
    }
    if(PriorCameraID != __rhs.PriorCameraID)
    {
	return true;
    }
    if(bGrabed != __rhs.bGrabed)
    {
	return true;
    }
    if(DecodeType != __rhs.DecodeType)
    {
	return true;
    }
    if(sDecodeType != __rhs.sDecodeType)
    {
	return true;
    }
    return false;
}

bool
NVSIndex::NVSCameraInfo::operator<(const NVSCameraInfo& __rhs) const
{
    if(this == &__rhs)
    {
	return false;
    }
    if(CameraID < __rhs.CameraID)
    {
	return true;
    }
    else if(__rhs.CameraID < CameraID)
    {
	return false;
    }
    if(Valid < __rhs.Valid)
    {
	return true;
    }
    else if(__rhs.Valid < Valid)
    {
	return false;
    }
    if(CameraType < __rhs.CameraType)
    {
	return true;
    }
    else if(__rhs.CameraType < CameraType)
    {
	return false;
    }
    if(DVRID < __rhs.DVRID)
    {
	return true;
    }
    else if(__rhs.DVRID < DVRID)
    {
	return false;
    }
    if(ChannelID < __rhs.ChannelID)
    {
	return true;
    }
    else if(__rhs.ChannelID < ChannelID)
    {
	return false;
    }
    if(ChannelStrID < __rhs.ChannelStrID)
    {
	return true;
    }
    else if(__rhs.ChannelStrID < ChannelStrID)
    {
	return false;
    }
    if(ChannelName < __rhs.ChannelName)
    {
	return true;
    }
    else if(__rhs.ChannelName < ChannelName)
    {
	return false;
    }
    if(OpenType < __rhs.OpenType)
    {
	return true;
    }
    else if(__rhs.OpenType < OpenType)
    {
	return false;
    }
    if(sOpenType < __rhs.sOpenType)
    {
	return true;
    }
    else if(__rhs.sOpenType < sOpenType)
    {
	return false;
    }
    if(ChannelNO < __rhs.ChannelNO)
    {
	return true;
    }
    else if(__rhs.ChannelNO < ChannelNO)
    {
	return false;
    }
    if(PriorCameraID < __rhs.PriorCameraID)
    {
	return true;
    }
    else if(__rhs.PriorCameraID < PriorCameraID)
    {
	return false;
    }
    if(bGrabed < __rhs.bGrabed)
    {
	return true;
    }
    else if(__rhs.bGrabed < bGrabed)
    {
	return false;
    }
    if(DecodeType < __rhs.DecodeType)
    {
	return true;
    }
    else if(__rhs.DecodeType < DecodeType)
    {
	return false;
    }
    if(sDecodeType < __rhs.sDecodeType)
    {
	return true;
    }
    else if(__rhs.sDecodeType < sDecodeType)
    {
	return false;
    }
    return false;
}

void
NVSIndex::NVSCameraInfo::__write(::IceInternal::BasicStream* __os) const
{
    __os->write(CameraID);
    __os->write(Valid);
    __os->write(CameraType);
    __os->write(DVRID);
    __os->write(ChannelID);
    __os->write(ChannelStrID);
    __os->write(ChannelName);
    __os->write(OpenType);
    __os->write(sOpenType);
    __os->write(ChannelNO);
    __os->write(PriorCameraID);
    __os->write(bGrabed);
    __os->write(DecodeType);
    __os->write(sDecodeType);
}

void
NVSIndex::NVSCameraInfo::__read(::IceInternal::BasicStream* __is)
{
    __is->read(CameraID);
    __is->read(Valid);
    __is->read(CameraType);
    __is->read(DVRID);
    __is->read(ChannelID);
    __is->read(ChannelStrID);
    __is->read(ChannelName);
    __is->read(OpenType);
    __is->read(sOpenType);
    __is->read(ChannelNO);
    __is->read(PriorCameraID);
    __is->read(bGrabed);
    __is->read(DecodeType);
    __is->read(sDecodeType);
}

void
NVSIndex::__write(::IceInternal::BasicStream* __os, const ::NVSIndex::NVSCameraInfo* begin, const ::NVSIndex::NVSCameraInfo* end, ::NVSIndex::__U__NVSCameraPool)
{
    ::Ice::Int size = static_cast< ::Ice::Int>(end - begin);
    __os->writeSize(size);
    for(int i = 0; i < size; ++i)
    {
	begin[i].__write(__os);
    }
}

void
NVSIndex::__read(::IceInternal::BasicStream* __is, ::NVSIndex::NVSCameraPool& v, ::NVSIndex::__U__NVSCameraPool)
{
    ::Ice::Int sz;
    __is->readSize(sz);
    __is->startSeq(sz, 35);
    v.resize(sz);
    for(int i = 0; i < sz; ++i)
    {
	v[i].__read(__is);
	__is->checkSeq();
	__is->endElement();
    }
    __is->endSeq(sz);
}

bool
NVSIndex::IPServerInfo::operator==(const IPServerInfo& __rhs) const
{
    return !operator!=(__rhs);
}

bool
NVSIndex::IPServerInfo::operator!=(const IPServerInfo& __rhs) const
{
    if(this == &__rhs)
    {
	return false;
    }
    if(sIPIn != __rhs.sIPIn)
    {
	return true;
    }
    if(nPortIn != __rhs.nPortIn)
    {
	return true;
    }
    if(sIPOut != __rhs.sIPOut)
    {
	return true;
    }
    if(nPortOut != __rhs.nPortOut)
    {
	return true;
    }
    return false;
}

bool
NVSIndex::IPServerInfo::operator<(const IPServerInfo& __rhs) const
{
    if(this == &__rhs)
    {
	return false;
    }
    if(sIPIn < __rhs.sIPIn)
    {
	return true;
    }
    else if(__rhs.sIPIn < sIPIn)
    {
	return false;
    }
    if(nPortIn < __rhs.nPortIn)
    {
	return true;
    }
    else if(__rhs.nPortIn < nPortIn)
    {
	return false;
    }
    if(sIPOut < __rhs.sIPOut)
    {
	return true;
    }
    else if(__rhs.sIPOut < sIPOut)
    {
	return false;
    }
    if(nPortOut < __rhs.nPortOut)
    {
	return true;
    }
    else if(__rhs.nPortOut < nPortOut)
    {
	return false;
    }
    return false;
}

void
NVSIndex::IPServerInfo::__write(::IceInternal::BasicStream* __os) const
{
    __os->write(sIPIn);
    __os->write(nPortIn);
    __os->write(sIPOut);
    __os->write(nPortOut);
}

void
NVSIndex::IPServerInfo::__read(::IceInternal::BasicStream* __is)
{
    __is->read(sIPIn);
    __is->read(nPortIn);
    __is->read(sIPOut);
    __is->read(nPortOut);
}

bool
NVSIndex::NVSDVRInfo::operator==(const NVSDVRInfo& __rhs) const
{
    return !operator!=(__rhs);
}

bool
NVSIndex::NVSDVRInfo::operator!=(const NVSDVRInfo& __rhs) const
{
    if(this == &__rhs)
    {
	return false;
    }
    if(DVRID != __rhs.DVRID)
    {
	return true;
    }
    if(Valid != __rhs.Valid)
    {
	return true;
    }
    if(DVRType != __rhs.DVRType)
    {
	return true;
    }
    if(IP != __rhs.IP)
    {
	return true;
    }
    if(Port != __rhs.Port)
    {
	return true;
    }
    if(UserName != __rhs.UserName)
    {
	return true;
    }
    if(UserPwd != __rhs.UserPwd)
    {
	return true;
    }
    if(Ready != __rhs.Ready)
    {
	return true;
    }
    if(DVRTypeKey != __rhs.DVRTypeKey)
    {
	return true;
    }
    if(CameraPool != __rhs.CameraPool)
    {
	return true;
    }
    if(DvrFrequency != __rhs.DvrFrequency)
    {
	return true;
    }
    if(IsDNS != __rhs.IsDNS)
    {
	return true;
    }
    if(DvrSerialNO != __rhs.DvrSerialNO)
    {
	return true;
    }
    if(ServerInfo != __rhs.ServerInfo)
    {
	return true;
    }
    if(bUseed2Vis != __rhs.bUseed2Vis)
    {
	return true;
    }
    if(SDVRAccessType != __rhs.SDVRAccessType)
    {
	return true;
    }
    return false;
}

bool
NVSIndex::NVSDVRInfo::operator<(const NVSDVRInfo& __rhs) const
{
    if(this == &__rhs)
    {
	return false;
    }
    if(DVRID < __rhs.DVRID)
    {
	return true;
    }
    else if(__rhs.DVRID < DVRID)
    {
	return false;
    }
    if(Valid < __rhs.Valid)
    {
	return true;
    }
    else if(__rhs.Valid < Valid)
    {
	return false;
    }
    if(DVRType < __rhs.DVRType)
    {
	return true;
    }
    else if(__rhs.DVRType < DVRType)
    {
	return false;
    }
    if(IP < __rhs.IP)
    {
	return true;
    }
    else if(__rhs.IP < IP)
    {
	return false;
    }
    if(Port < __rhs.Port)
    {
	return true;
    }
    else if(__rhs.Port < Port)
    {
	return false;
    }
    if(UserName < __rhs.UserName)
    {
	return true;
    }
    else if(__rhs.UserName < UserName)
    {
	return false;
    }
    if(UserPwd < __rhs.UserPwd)
    {
	return true;
    }
    else if(__rhs.UserPwd < UserPwd)
    {
	return false;
    }
    if(Ready < __rhs.Ready)
    {
	return true;
    }
    else if(__rhs.Ready < Ready)
    {
	return false;
    }
    if(DVRTypeKey < __rhs.DVRTypeKey)
    {
	return true;
    }
    else if(__rhs.DVRTypeKey < DVRTypeKey)
    {
	return false;
    }
    if(CameraPool < __rhs.CameraPool)
    {
	return true;
    }
    else if(__rhs.CameraPool < CameraPool)
    {
	return false;
    }
    if(DvrFrequency < __rhs.DvrFrequency)
    {
	return true;
    }
    else if(__rhs.DvrFrequency < DvrFrequency)
    {
	return false;
    }
    if(IsDNS < __rhs.IsDNS)
    {
	return true;
    }
    else if(__rhs.IsDNS < IsDNS)
    {
	return false;
    }
    if(DvrSerialNO < __rhs.DvrSerialNO)
    {
	return true;
    }
    else if(__rhs.DvrSerialNO < DvrSerialNO)
    {
	return false;
    }
    if(ServerInfo < __rhs.ServerInfo)
    {
	return true;
    }
    else if(__rhs.ServerInfo < ServerInfo)
    {
	return false;
    }
    if(bUseed2Vis < __rhs.bUseed2Vis)
    {
	return true;
    }
    else if(__rhs.bUseed2Vis < bUseed2Vis)
    {
	return false;
    }
    if(SDVRAccessType < __rhs.SDVRAccessType)
    {
	return true;
    }
    else if(__rhs.SDVRAccessType < SDVRAccessType)
    {
	return false;
    }
    return false;
}

void
NVSIndex::NVSDVRInfo::__write(::IceInternal::BasicStream* __os) const
{
    __os->write(DVRID);
    __os->write(Valid);
    __os->write(DVRType);
    __os->write(IP);
    __os->write(Port);
    __os->write(UserName);
    __os->write(UserPwd);
    __os->write(Ready);
    __os->write(DVRTypeKey);
    if(CameraPool.size() == 0)
    {
	__os->writeSize(0);
    }
    else
    {
	::NVSIndex::__write(__os, &CameraPool[0], &CameraPool[0] + CameraPool.size(), ::NVSIndex::__U__NVSCameraPool());
    }
    __os->write(DvrFrequency);
    __os->write(IsDNS);
    __os->write(DvrSerialNO);
    ServerInfo.__write(__os);
    __os->write(bUseed2Vis);
    __os->write(SDVRAccessType);
}

void
NVSIndex::NVSDVRInfo::__read(::IceInternal::BasicStream* __is)
{
    __is->read(DVRID);
    __is->read(Valid);
    __is->read(DVRType);
    __is->read(IP);
    __is->read(Port);
    __is->read(UserName);
    __is->read(UserPwd);
    __is->read(Ready);
    __is->read(DVRTypeKey);
    ::NVSIndex::__read(__is, CameraPool, ::NVSIndex::__U__NVSCameraPool());
    __is->read(DvrFrequency);
    __is->read(IsDNS);
    __is->read(DvrSerialNO);
    ServerInfo.__read(__is);
    __is->read(bUseed2Vis);
    __is->read(SDVRAccessType);
}

bool
NVSIndex::NVSDVRInfoEx::operator==(const NVSDVRInfoEx& __rhs) const
{
    return !operator!=(__rhs);
}

bool
NVSIndex::NVSDVRInfoEx::operator!=(const NVSDVRInfoEx& __rhs) const
{
    if(this == &__rhs)
    {
	return false;
    }
    if(dvrinfo != __rhs.dvrinfo)
    {
	return true;
    }
    if(ExternalIP != __rhs.ExternalIP)
    {
	return true;
    }
    if(ExternalPort != __rhs.ExternalPort)
    {
	return true;
    }
    return false;
}

bool
NVSIndex::NVSDVRInfoEx::operator<(const NVSDVRInfoEx& __rhs) const
{
    if(this == &__rhs)
    {
	return false;
    }
    if(dvrinfo < __rhs.dvrinfo)
    {
	return true;
    }
    else if(__rhs.dvrinfo < dvrinfo)
    {
	return false;
    }
    if(ExternalIP < __rhs.ExternalIP)
    {
	return true;
    }
    else if(__rhs.ExternalIP < ExternalIP)
    {
	return false;
    }
    if(ExternalPort < __rhs.ExternalPort)
    {
	return true;
    }
    else if(__rhs.ExternalPort < ExternalPort)
    {
	return false;
    }
    return false;
}

void
NVSIndex::NVSDVRInfoEx::__write(::IceInternal::BasicStream* __os) const
{
    dvrinfo.__write(__os);
    __os->write(ExternalIP);
    __os->write(ExternalPort);
}

void
NVSIndex::NVSDVRInfoEx::__read(::IceInternal::BasicStream* __is)
{
    dvrinfo.__read(__is);
    __is->read(ExternalIP);
    __is->read(ExternalPort);
}

void
NVSIndex::__write(::IceInternal::BasicStream* __os, const ::NVSIndex::NVSDVRInfo* begin, const ::NVSIndex::NVSDVRInfo* end, ::NVSIndex::__U__NVSDVRPool)
{
    ::Ice::Int size = static_cast< ::Ice::Int>(end - begin);
    __os->writeSize(size);
    for(int i = 0; i < size; ++i)
    {
	begin[i].__write(__os);
    }
}

void
NVSIndex::__read(::IceInternal::BasicStream* __is, ::NVSIndex::NVSDVRPool& v, ::NVSIndex::__U__NVSDVRPool)
{
    ::Ice::Int sz;
    __is->readSize(sz);
    __is->startSeq(sz, 37);
    v.resize(sz);
    for(int i = 0; i < sz; ++i)
    {
	v[i].__read(__is);
	__is->checkSeq();
	__is->endElement();
    }
    __is->endSeq(sz);
}

bool
NVSIndex::NVSStreamServiceInfo::operator==(const NVSStreamServiceInfo& __rhs) const
{
    return !operator!=(__rhs);
}

bool
NVSIndex::NVSStreamServiceInfo::operator!=(const NVSStreamServiceInfo& __rhs) const
{
    if(this == &__rhs)
    {
	return false;
    }
    if(Key != __rhs.Key)
    {
	return true;
    }
    if(ServiceAddress != __rhs.ServiceAddress)
    {
	return true;
    }
    if(ServiceKey != __rhs.ServiceKey)
    {
	return true;
    }
    if(VideoLoad != __rhs.VideoLoad)
    {
	return true;
    }
    if(MonitorLoad != __rhs.MonitorLoad)
    {
	return true;
    }
    if(Type != __rhs.Type)
    {
	return true;
    }
    return false;
}

bool
NVSIndex::NVSStreamServiceInfo::operator<(const NVSStreamServiceInfo& __rhs) const
{
    if(this == &__rhs)
    {
	return false;
    }
    if(Key < __rhs.Key)
    {
	return true;
    }
    else if(__rhs.Key < Key)
    {
	return false;
    }
    if(ServiceAddress < __rhs.ServiceAddress)
    {
	return true;
    }
    else if(__rhs.ServiceAddress < ServiceAddress)
    {
	return false;
    }
    if(ServiceKey < __rhs.ServiceKey)
    {
	return true;
    }
    else if(__rhs.ServiceKey < ServiceKey)
    {
	return false;
    }
    if(VideoLoad < __rhs.VideoLoad)
    {
	return true;
    }
    else if(__rhs.VideoLoad < VideoLoad)
    {
	return false;
    }
    if(MonitorLoad < __rhs.MonitorLoad)
    {
	return true;
    }
    else if(__rhs.MonitorLoad < MonitorLoad)
    {
	return false;
    }
    if(Type < __rhs.Type)
    {
	return true;
    }
    else if(__rhs.Type < Type)
    {
	return false;
    }
    return false;
}

void
NVSIndex::NVSStreamServiceInfo::__write(::IceInternal::BasicStream* __os) const
{
    __os->write(Key);
    ServiceAddress.__write(__os);
    __os->write(ServiceKey);
    __os->write(VideoLoad);
    __os->write(MonitorLoad);
    __os->write(Type);
}

void
NVSIndex::NVSStreamServiceInfo::__read(::IceInternal::BasicStream* __is)
{
    __is->read(Key);
    ServiceAddress.__read(__is);
    __is->read(ServiceKey);
    __is->read(VideoLoad);
    __is->read(MonitorLoad);
    __is->read(Type);
}

bool
NVSIndex::NVSMonitorInfo::operator==(const NVSMonitorInfo& __rhs) const
{
    return !operator!=(__rhs);
}

bool
NVSIndex::NVSMonitorInfo::operator!=(const NVSMonitorInfo& __rhs) const
{
    if(this == &__rhs)
    {
	return false;
    }
    if(Root != __rhs.Root)
    {
	return true;
    }
    if(IPInline != __rhs.IPInline)
    {
	return true;
    }
    if(IPOutline != __rhs.IPOutline)
    {
	return true;
    }
    if(Status != __rhs.Status)
    {
	return true;
    }
    if(CurIncomingCount != __rhs.CurIncomingCount)
    {
	return true;
    }
    if(CurOutgoingCount != __rhs.CurOutgoingCount)
    {
	return true;
    }
    if(ID != __rhs.ID)
    {
	return true;
    }
    if(DoorType != __rhs.DoorType)
    {
	return true;
    }
    if(StartTime != __rhs.StartTime)
    {
	return true;
    }
    if(Right != __rhs.Right)
    {
	return true;
    }
    return false;
}

bool
NVSIndex::NVSMonitorInfo::operator<(const NVSMonitorInfo& __rhs) const
{
    if(this == &__rhs)
    {
	return false;
    }
    if(Root < __rhs.Root)
    {
	return true;
    }
    else if(__rhs.Root < Root)
    {
	return false;
    }
    if(IPInline < __rhs.IPInline)
    {
	return true;
    }
    else if(__rhs.IPInline < IPInline)
    {
	return false;
    }
    if(IPOutline < __rhs.IPOutline)
    {
	return true;
    }
    else if(__rhs.IPOutline < IPOutline)
    {
	return false;
    }
    if(Status < __rhs.Status)
    {
	return true;
    }
    else if(__rhs.Status < Status)
    {
	return false;
    }
    if(CurIncomingCount < __rhs.CurIncomingCount)
    {
	return true;
    }
    else if(__rhs.CurIncomingCount < CurIncomingCount)
    {
	return false;
    }
    if(CurOutgoingCount < __rhs.CurOutgoingCount)
    {
	return true;
    }
    else if(__rhs.CurOutgoingCount < CurOutgoingCount)
    {
	return false;
    }
    if(ID < __rhs.ID)
    {
	return true;
    }
    else if(__rhs.ID < ID)
    {
	return false;
    }
    if(DoorType < __rhs.DoorType)
    {
	return true;
    }
    else if(__rhs.DoorType < DoorType)
    {
	return false;
    }
    if(StartTime < __rhs.StartTime)
    {
	return true;
    }
    else if(__rhs.StartTime < StartTime)
    {
	return false;
    }
    if(Right < __rhs.Right)
    {
	return true;
    }
    else if(__rhs.Right < Right)
    {
	return false;
    }
    return false;
}

void
NVSIndex::NVSMonitorInfo::__write(::IceInternal::BasicStream* __os) const
{
    __os->write(Root);
    __os->write(IPInline);
    __os->write(IPOutline);
    __os->write(Status);
    __os->write(CurIncomingCount);
    __os->write(CurOutgoingCount);
    __os->write(ID);
    ::NVSIndex::__write(__os, DoorType);
    __os->write(StartTime);
    __os->write(Right);
}

void
NVSIndex::NVSMonitorInfo::__read(::IceInternal::BasicStream* __is)
{
    __is->read(Root);
    __is->read(IPInline);
    __is->read(IPOutline);
    __is->read(Status);
    __is->read(CurIncomingCount);
    __is->read(CurOutgoingCount);
    __is->read(ID);
    ::NVSIndex::__read(__is, DoorType);
    __is->read(StartTime);
    __is->read(Right);
}

bool
NVSIndex::SystemState::operator==(const SystemState& __rhs) const
{
    return !operator!=(__rhs);
}

bool
NVSIndex::SystemState::operator!=(const SystemState& __rhs) const
{
    if(this == &__rhs)
    {
	return false;
    }
    if(nClientCount != __rhs.nClientCount)
    {
	return true;
    }
    if(nStreamCount != __rhs.nStreamCount)
    {
	return true;
    }
    return false;
}

bool
NVSIndex::SystemState::operator<(const SystemState& __rhs) const
{
    if(this == &__rhs)
    {
	return false;
    }
    if(nClientCount < __rhs.nClientCount)
    {
	return true;
    }
    else if(__rhs.nClientCount < nClientCount)
    {
	return false;
    }
    if(nStreamCount < __rhs.nStreamCount)
    {
	return true;
    }
    else if(__rhs.nStreamCount < nStreamCount)
    {
	return false;
    }
    return false;
}

void
NVSIndex::SystemState::__write(::IceInternal::BasicStream* __os) const
{
    __os->write(nClientCount);
    __os->write(nStreamCount);
}

void
NVSIndex::SystemState::__read(::IceInternal::BasicStream* __is)
{
    __is->read(nClientCount);
    __is->read(nStreamCount);
}
