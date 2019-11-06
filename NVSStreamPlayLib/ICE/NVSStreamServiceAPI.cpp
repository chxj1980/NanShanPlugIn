// **********************************************************************
//
// Copyright (c) 2003-2006 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************

// Ice version 3.1.1
// Generated from file `NVSStreamServiceAPI.ice'

#include "stdafx.h"
#include "NVSStreamServiceAPI.h"
#include <Ice/LocalException.h>
#include <Ice/ObjectFactory.h>
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

static const ::std::string __NVSStreamService__NVSStreamDataReceiver__sendStreamBody_name = "sendStreamBody";

static const ::std::string __NVSStreamService__NVSStreamDataReceiver__sendStreamHead_name = "sendStreamHead";

static const ::std::string __NVSStreamService__NVSStreamServiceAPI__startPlayer_name = "startPlayer";

static const ::std::string __NVSStreamService__NVSStreamServiceAPI__stopVideo_name = "stopVideo";

static const ::std::string __NVSStreamService__NVSStreamServiceAPI__getWorkState_name = "getWorkState";

static const ::std::string __NVSStreamService__NVSStreamServiceAPI__getCompress_name = "getCompress";

static const ::std::string __NVSStreamService__NVSStreamServiceAPI__setCompress_name = "setCompress";

static const ::std::string __NVSStreamService__NVSStreamServiceAPI__getVideoEffect_name = "getVideoEffect";

static const ::std::string __NVSStreamService__NVSStreamServiceAPI__setVideoEffect_name = "setVideoEffect";

static const ::std::string __NVSStreamService__NVSStreamServiceAPI__requestControlCamera_name = "requestControlCamera";

static const ::std::string __NVSStreamService__NVSStreamServiceAPI__controlCameraSpeed_name = "controlCameraSpeed";

static const ::std::string __NVSStreamService__NVSStreamServiceAPI__cancelControlCamera_name = "cancelControlCamera";

static const ::std::string __NVSStreamService__NVSStreamServiceAPI__presetPTZ_name = "presetPTZ";

static const ::std::string __NVSStreamService__NVSStreamServiceAPI__HeartBeat_name = "HeartBeat";

void
IceInternal::incRef(::NVSStreamService::NVSStreamDataReceiver* p)
{
    p->__incRef();
}

void
IceInternal::decRef(::NVSStreamService::NVSStreamDataReceiver* p)
{
    p->__decRef();
}

void
IceInternal::incRef(::IceProxy::NVSStreamService::NVSStreamDataReceiver* p)
{
    p->__incRef();
}

void
IceInternal::decRef(::IceProxy::NVSStreamService::NVSStreamDataReceiver* p)
{
    p->__decRef();
}

void
IceInternal::incRef(::NVSStreamService::NVSStreamServiceAPI* p)
{
    p->__incRef();
}

void
IceInternal::decRef(::NVSStreamService::NVSStreamServiceAPI* p)
{
    p->__decRef();
}

void
IceInternal::incRef(::IceProxy::NVSStreamService::NVSStreamServiceAPI* p)
{
    p->__incRef();
}

void
IceInternal::decRef(::IceProxy::NVSStreamService::NVSStreamServiceAPI* p)
{
    p->__decRef();
}

void
NVSStreamService::__write(::IceInternal::BasicStream* __os, const ::NVSStreamService::NVSStreamDataReceiverPrx& v)
{
    __os->write(::Ice::ObjectPrx(v));
}

void
NVSStreamService::__read(::IceInternal::BasicStream* __is, ::NVSStreamService::NVSStreamDataReceiverPrx& v)
{
    ::Ice::ObjectPrx proxy;
    __is->read(proxy);
    if(!proxy)
    {
	v = 0;
    }
    else
    {
	v = new ::IceProxy::NVSStreamService::NVSStreamDataReceiver;
	v->__copyFrom(proxy);
    }
}

void
NVSStreamService::__write(::IceInternal::BasicStream* __os, const ::NVSStreamService::NVSStreamDataReceiverPtr& v)
{
    __os->write(::Ice::ObjectPtr(v));
}

void
NVSStreamService::__write(::IceInternal::BasicStream* __os, const ::NVSStreamService::NVSStreamServiceAPIPrx& v)
{
    __os->write(::Ice::ObjectPrx(v));
}

void
NVSStreamService::__read(::IceInternal::BasicStream* __is, ::NVSStreamService::NVSStreamServiceAPIPrx& v)
{
    ::Ice::ObjectPrx proxy;
    __is->read(proxy);
    if(!proxy)
    {
	v = 0;
    }
    else
    {
	v = new ::IceProxy::NVSStreamService::NVSStreamServiceAPI;
	v->__copyFrom(proxy);
    }
}

void
NVSStreamService::__write(::IceInternal::BasicStream* __os, const ::NVSStreamService::NVSStreamServiceAPIPtr& v)
{
    __os->write(::Ice::ObjectPtr(v));
}

bool
NVSStreamService::PieceInfo::operator==(const PieceInfo& __rhs) const
{
    return !operator!=(__rhs);
}

bool
NVSStreamService::PieceInfo::operator!=(const PieceInfo& __rhs) const
{
    if(this == &__rhs)
    {
	return false;
    }
    if(sCameraID != __rhs.sCameraID)
    {
	return true;
    }
    if(sDVRKey != __rhs.sDVRKey)
    {
	return true;
    }
    if(TimeStampX != __rhs.TimeStampX)
    {
	return true;
    }
    return false;
}

bool
NVSStreamService::PieceInfo::operator<(const PieceInfo& __rhs) const
{
    if(this == &__rhs)
    {
	return false;
    }
    if(sCameraID < __rhs.sCameraID)
    {
	return true;
    }
    else if(__rhs.sCameraID < sCameraID)
    {
	return false;
    }
    if(sDVRKey < __rhs.sDVRKey)
    {
	return true;
    }
    else if(__rhs.sDVRKey < sDVRKey)
    {
	return false;
    }
    if(TimeStampX < __rhs.TimeStampX)
    {
	return true;
    }
    else if(__rhs.TimeStampX < TimeStampX)
    {
	return false;
    }
    return false;
}

void
NVSStreamService::PieceInfo::__write(::IceInternal::BasicStream* __os) const
{
    __os->write(sCameraID);
    __os->write(sDVRKey);
    __os->write(TimeStampX);
}

void
NVSStreamService::PieceInfo::__read(::IceInternal::BasicStream* __is)
{
    __is->read(sCameraID);
    __is->read(sDVRKey);
    __is->read(TimeStampX);
}

bool
NVSStreamService::DeviceInfo::operator==(const DeviceInfo& __rhs) const
{
    return !operator!=(__rhs);
}

bool
NVSStreamService::DeviceInfo::operator!=(const DeviceInfo& __rhs) const
{
    if(this == &__rhs)
    {
	return false;
    }
    if(sIP != __rhs.sIP)
    {
	return true;
    }
    if(sUser != __rhs.sUser)
    {
	return true;
    }
    if(sPassword != __rhs.sPassword)
    {
	return true;
    }
    if(nPort != __rhs.nPort)
    {
	return true;
    }
    if(nChannel != __rhs.nChannel)
    {
	return true;
    }
    if(sChannel != __rhs.sChannel)
    {
	return true;
    }
    if(sType != __rhs.sType)
    {
	return true;
    }
    return false;
}

bool
NVSStreamService::DeviceInfo::operator<(const DeviceInfo& __rhs) const
{
    if(this == &__rhs)
    {
	return false;
    }
    if(sIP < __rhs.sIP)
    {
	return true;
    }
    else if(__rhs.sIP < sIP)
    {
	return false;
    }
    if(sUser < __rhs.sUser)
    {
	return true;
    }
    else if(__rhs.sUser < sUser)
    {
	return false;
    }
    if(sPassword < __rhs.sPassword)
    {
	return true;
    }
    else if(__rhs.sPassword < sPassword)
    {
	return false;
    }
    if(nPort < __rhs.nPort)
    {
	return true;
    }
    else if(__rhs.nPort < nPort)
    {
	return false;
    }
    if(nChannel < __rhs.nChannel)
    {
	return true;
    }
    else if(__rhs.nChannel < nChannel)
    {
	return false;
    }
    if(sChannel < __rhs.sChannel)
    {
	return true;
    }
    else if(__rhs.sChannel < sChannel)
    {
	return false;
    }
    if(sType < __rhs.sType)
    {
	return true;
    }
    else if(__rhs.sType < sType)
    {
	return false;
    }
    return false;
}

void
NVSStreamService::DeviceInfo::__write(::IceInternal::BasicStream* __os) const
{
    __os->write(sIP);
    __os->write(sUser);
    __os->write(sPassword);
    __os->write(nPort);
    __os->write(nChannel);
    __os->write(sChannel);
    __os->write(sType);
}

void
NVSStreamService::DeviceInfo::__read(::IceInternal::BasicStream* __is)
{
    __is->read(sIP);
    __is->read(sUser);
    __is->read(sPassword);
    __is->read(nPort);
    __is->read(nChannel);
    __is->read(sChannel);
    __is->read(sType);
}

bool
NVSStreamService::StreamPiece::operator==(const StreamPiece& __rhs) const
{
    return !operator!=(__rhs);
}

bool
NVSStreamService::StreamPiece::operator!=(const StreamPiece& __rhs) const
{
    if(this == &__rhs)
    {
	return false;
    }
    if(Description != __rhs.Description)
    {
	return true;
    }
    if(Data != __rhs.Data)
    {
	return true;
    }
    return false;
}

bool
NVSStreamService::StreamPiece::operator<(const StreamPiece& __rhs) const
{
    if(this == &__rhs)
    {
	return false;
    }
    if(Description < __rhs.Description)
    {
	return true;
    }
    else if(__rhs.Description < Description)
    {
	return false;
    }
    if(Data < __rhs.Data)
    {
	return true;
    }
    else if(__rhs.Data < Data)
    {
	return false;
    }
    return false;
}

void
NVSStreamService::StreamPiece::__write(::IceInternal::BasicStream* __os) const
{
    Description.__write(__os);
    if(Data.size() == 0)
    {
	__os->writeSize(0);
    }
    else
    {
	__os->write(&Data[0], &Data[0] + Data.size());
    }
}

void
NVSStreamService::StreamPiece::__read(::IceInternal::BasicStream* __is)
{
    Description.__read(__is);
    ::std::pair<const ::Ice::Byte*, const ::Ice::Byte*> ___Data;
    __is->read(___Data);
    ::std::vector< ::Ice::Byte>(___Data.first, ___Data.second).swap(Data);
}

void
NVSStreamService::__write(::IceInternal::BasicStream* __os, const ::NVSStreamService::StreamPiece* begin, const ::NVSStreamService::StreamPiece* end, ::NVSStreamService::__U__StreamData)
{
    ::Ice::Int size = static_cast< ::Ice::Int>(end - begin);
    __os->writeSize(size);
    for(int i = 0; i < size; ++i)
    {
	begin[i].__write(__os);
    }
}

void
NVSStreamService::__read(::IceInternal::BasicStream* __is, ::NVSStreamService::StreamData& v, ::NVSStreamService::__U__StreamData)
{
    ::Ice::Int sz;
    __is->readSize(sz);
    __is->startSeq(sz, 11);
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
NVSStreamService::WorkState::operator==(const WorkState& __rhs) const
{
    return !operator!=(__rhs);
}

bool
NVSStreamService::WorkState::operator!=(const WorkState& __rhs) const
{
    if(this == &__rhs)
    {
	return false;
    }
    if(DvrLoad != __rhs.DvrLoad)
    {
	return true;
    }
    if(ChannelLoad != __rhs.ChannelLoad)
    {
	return true;
    }
    if(MonitorLoad != __rhs.MonitorLoad)
    {
	return true;
    }
    if(SendLoad != __rhs.SendLoad)
    {
	return true;
    }
    if(MaxSendCount != __rhs.MaxSendCount)
    {
	return true;
    }
    if(MaxChannel != __rhs.MaxChannel)
    {
	return true;
    }
    return false;
}

bool
NVSStreamService::WorkState::operator<(const WorkState& __rhs) const
{
    if(this == &__rhs)
    {
	return false;
    }
    if(DvrLoad < __rhs.DvrLoad)
    {
	return true;
    }
    else if(__rhs.DvrLoad < DvrLoad)
    {
	return false;
    }
    if(ChannelLoad < __rhs.ChannelLoad)
    {
	return true;
    }
    else if(__rhs.ChannelLoad < ChannelLoad)
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
    if(SendLoad < __rhs.SendLoad)
    {
	return true;
    }
    else if(__rhs.SendLoad < SendLoad)
    {
	return false;
    }
    if(MaxSendCount < __rhs.MaxSendCount)
    {
	return true;
    }
    else if(__rhs.MaxSendCount < MaxSendCount)
    {
	return false;
    }
    if(MaxChannel < __rhs.MaxChannel)
    {
	return true;
    }
    else if(__rhs.MaxChannel < MaxChannel)
    {
	return false;
    }
    return false;
}

void
NVSStreamService::WorkState::__write(::IceInternal::BasicStream* __os) const
{
    __os->write(DvrLoad);
    __os->write(ChannelLoad);
    __os->write(MonitorLoad);
    __os->write(SendLoad);
    __os->write(MaxSendCount);
    __os->write(MaxChannel);
}

void
NVSStreamService::WorkState::__read(::IceInternal::BasicStream* __is)
{
    __is->read(DvrLoad);
    __is->read(ChannelLoad);
    __is->read(MonitorLoad);
    __is->read(SendLoad);
    __is->read(MaxSendCount);
    __is->read(MaxChannel);
}

void
NVSStreamService::AMI_NVSStreamDataReceiver_sendStreamBody::__invoke(const ::NVSStreamService::NVSStreamDataReceiverPrx& __prx, const ::NVSStreamService::StreamPiece& sd, const ::Ice::Context& __ctx)
{
    try
    {
	__prepare(__prx, __NVSStreamService__NVSStreamDataReceiver__sendStreamBody_name, ::Ice::Normal, __ctx);
	sd.__write(__os);
	__os->endWriteEncaps();
    }
    catch(const ::Ice::LocalException& __ex)
    {
	__finished(__ex);
	return;
    }
    __send();
}

void
NVSStreamService::AMI_NVSStreamDataReceiver_sendStreamBody::__response(bool __ok)
{
    bool __ret;
    try
    {
	if(!__ok)
	{
	    try
	    {
		__is->throwException();
	    }
	    catch(const ::Ice::UserException& __ex)
	    {
		throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
	    }
	}
	__is->read(__ret);
    }
    catch(const ::Ice::LocalException& __ex)
    {
	__finished(__ex);
	return;
    }
    ice_response(__ret);
}

void
NVSStreamService::AMI_NVSStreamDataReceiver_sendStreamHead::__invoke(const ::NVSStreamService::NVSStreamDataReceiverPrx& __prx, const ::NVSStreamService::StreamPiece& sd, const ::Ice::Context& __ctx)
{
    try
    {
	__prepare(__prx, __NVSStreamService__NVSStreamDataReceiver__sendStreamHead_name, ::Ice::Normal, __ctx);
	sd.__write(__os);
	__os->endWriteEncaps();
    }
    catch(const ::Ice::LocalException& __ex)
    {
	__finished(__ex);
	return;
    }
    __send();
}

void
NVSStreamService::AMI_NVSStreamDataReceiver_sendStreamHead::__response(bool __ok)
{
    bool __ret;
    try
    {
	if(!__ok)
	{
	    try
	    {
		__is->throwException();
	    }
	    catch(const ::Ice::UserException& __ex)
	    {
		throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
	    }
	}
	__is->read(__ret);
    }
    catch(const ::Ice::LocalException& __ex)
    {
	__finished(__ex);
	return;
    }
    ice_response(__ret);
}

bool
IceProxy::NVSStreamService::NVSStreamDataReceiver::sendStreamBody(const ::NVSStreamService::StreamPiece& sd, const ::Ice::Context& __ctx)
{
    int __cnt = 0;
    while(true)
    {
	try
	{
	    __checkTwowayOnly(__NVSStreamService__NVSStreamDataReceiver__sendStreamBody_name);
	    ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase = __getDelegate();
	    ::IceDelegate::NVSStreamService::NVSStreamDataReceiver* __del = dynamic_cast< ::IceDelegate::NVSStreamService::NVSStreamDataReceiver*>(__delBase.get());
	    return __del->sendStreamBody(sd, __ctx);
	}
	catch(const ::IceInternal::LocalExceptionWrapper& __ex)
	{
	    __handleExceptionWrapper(__ex);
	}
	catch(const ::Ice::LocalException& __ex)
	{
	    __handleException(__ex, __cnt);
	}
    }
}

void
IceProxy::NVSStreamService::NVSStreamDataReceiver::sendStreamBody_async(const ::NVSStreamService::AMI_NVSStreamDataReceiver_sendStreamBodyPtr& __cb, const ::NVSStreamService::StreamPiece& sd)
{
    sendStreamBody_async(__cb, sd, __defaultContext());
}

void
IceProxy::NVSStreamService::NVSStreamDataReceiver::sendStreamBody_async(const ::NVSStreamService::AMI_NVSStreamDataReceiver_sendStreamBodyPtr& __cb, const ::NVSStreamService::StreamPiece& sd, const ::Ice::Context& __ctx)
{
    __cb->__invoke(this, sd, __ctx);
}

bool
IceProxy::NVSStreamService::NVSStreamDataReceiver::sendStreamHead(const ::NVSStreamService::StreamPiece& sd, const ::Ice::Context& __ctx)
{
    int __cnt = 0;
    while(true)
    {
	try
	{
	    __checkTwowayOnly(__NVSStreamService__NVSStreamDataReceiver__sendStreamHead_name);
	    ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase = __getDelegate();
	    ::IceDelegate::NVSStreamService::NVSStreamDataReceiver* __del = dynamic_cast< ::IceDelegate::NVSStreamService::NVSStreamDataReceiver*>(__delBase.get());
	    return __del->sendStreamHead(sd, __ctx);
	}
	catch(const ::IceInternal::LocalExceptionWrapper& __ex)
	{
	    __handleExceptionWrapper(__ex);
	}
	catch(const ::Ice::LocalException& __ex)
	{
	    __handleException(__ex, __cnt);
	}
    }
}

void
IceProxy::NVSStreamService::NVSStreamDataReceiver::sendStreamHead_async(const ::NVSStreamService::AMI_NVSStreamDataReceiver_sendStreamHeadPtr& __cb, const ::NVSStreamService::StreamPiece& sd)
{
    sendStreamHead_async(__cb, sd, __defaultContext());
}

void
IceProxy::NVSStreamService::NVSStreamDataReceiver::sendStreamHead_async(const ::NVSStreamService::AMI_NVSStreamDataReceiver_sendStreamHeadPtr& __cb, const ::NVSStreamService::StreamPiece& sd, const ::Ice::Context& __ctx)
{
    __cb->__invoke(this, sd, __ctx);
}

const ::std::string&
IceProxy::NVSStreamService::NVSStreamDataReceiver::ice_staticId()
{
    return ::NVSStreamService::NVSStreamDataReceiver::ice_staticId();
}

::IceInternal::Handle< ::IceDelegateM::Ice::Object>
IceProxy::NVSStreamService::NVSStreamDataReceiver::__createDelegateM()
{
    return ::IceInternal::Handle< ::IceDelegateM::Ice::Object>(new ::IceDelegateM::NVSStreamService::NVSStreamDataReceiver);
}

::IceInternal::Handle< ::IceDelegateD::Ice::Object>
IceProxy::NVSStreamService::NVSStreamDataReceiver::__createDelegateD()
{
    return ::IceInternal::Handle< ::IceDelegateD::Ice::Object>(new ::IceDelegateD::NVSStreamService::NVSStreamDataReceiver);
}

bool
IceProxy::NVSStreamService::operator==(const ::IceProxy::NVSStreamService::NVSStreamDataReceiver& l, const ::IceProxy::NVSStreamService::NVSStreamDataReceiver& r)
{
    return static_cast<const ::IceProxy::Ice::Object&>(l) == static_cast<const ::IceProxy::Ice::Object&>(r);
}

bool
IceProxy::NVSStreamService::operator!=(const ::IceProxy::NVSStreamService::NVSStreamDataReceiver& l, const ::IceProxy::NVSStreamService::NVSStreamDataReceiver& r)
{
    return static_cast<const ::IceProxy::Ice::Object&>(l) != static_cast<const ::IceProxy::Ice::Object&>(r);
}

bool
IceProxy::NVSStreamService::operator<(const ::IceProxy::NVSStreamService::NVSStreamDataReceiver& l, const ::IceProxy::NVSStreamService::NVSStreamDataReceiver& r)
{
    return static_cast<const ::IceProxy::Ice::Object&>(l) < static_cast<const ::IceProxy::Ice::Object&>(r);
}

bool
IceProxy::NVSStreamService::operator<=(const ::IceProxy::NVSStreamService::NVSStreamDataReceiver& l, const ::IceProxy::NVSStreamService::NVSStreamDataReceiver& r)
{
    return l < r || l == r;
}

bool
IceProxy::NVSStreamService::operator>(const ::IceProxy::NVSStreamService::NVSStreamDataReceiver& l, const ::IceProxy::NVSStreamService::NVSStreamDataReceiver& r)
{
    return !(l < r) && !(l == r);
}

bool
IceProxy::NVSStreamService::operator>=(const ::IceProxy::NVSStreamService::NVSStreamDataReceiver& l, const ::IceProxy::NVSStreamService::NVSStreamDataReceiver& r)
{
    return !(l < r);
}

::Ice::Int
IceProxy::NVSStreamService::NVSStreamServiceAPI::startPlayer(const ::NVSStreamService::DeviceInfo& connectInfo, const ::Ice::Identity& ident, ::std::string& sKey, const ::Ice::Context& __ctx)
{
    int __cnt = 0;
    while(true)
    {
	try
	{
	    __checkTwowayOnly(__NVSStreamService__NVSStreamServiceAPI__startPlayer_name);
	    ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase = __getDelegate();
	    ::IceDelegate::NVSStreamService::NVSStreamServiceAPI* __del = dynamic_cast< ::IceDelegate::NVSStreamService::NVSStreamServiceAPI*>(__delBase.get());
	    return __del->startPlayer(connectInfo, ident, sKey, __ctx);
	}
	catch(const ::IceInternal::LocalExceptionWrapper& __ex)
	{
	    __handleExceptionWrapper(__ex);
	}
	catch(const ::Ice::LocalException& __ex)
	{
	    __handleException(__ex, __cnt);
	}
    }
}

::Ice::Int
IceProxy::NVSStreamService::NVSStreamServiceAPI::stopVideo(const ::std::string& sKeyID, const ::Ice::Context& __ctx)
{
    int __cnt = 0;
    while(true)
    {
	try
	{
	    __checkTwowayOnly(__NVSStreamService__NVSStreamServiceAPI__stopVideo_name);
	    ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase = __getDelegate();
	    ::IceDelegate::NVSStreamService::NVSStreamServiceAPI* __del = dynamic_cast< ::IceDelegate::NVSStreamService::NVSStreamServiceAPI*>(__delBase.get());
	    return __del->stopVideo(sKeyID, __ctx);
	}
	catch(const ::IceInternal::LocalExceptionWrapper& __ex)
	{
	    __handleExceptionWrapper(__ex);
	}
	catch(const ::Ice::LocalException& __ex)
	{
	    __handleException(__ex, __cnt);
	}
    }
}

void
IceProxy::NVSStreamService::NVSStreamServiceAPI::getWorkState(::NVSStreamService::WorkState& wkState, const ::Ice::Context& __ctx)
{
    int __cnt = 0;
    while(true)
    {
	try
	{
	    __checkTwowayOnly(__NVSStreamService__NVSStreamServiceAPI__getWorkState_name);
	    ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase = __getDelegate();
	    ::IceDelegate::NVSStreamService::NVSStreamServiceAPI* __del = dynamic_cast< ::IceDelegate::NVSStreamService::NVSStreamServiceAPI*>(__delBase.get());
	    __del->getWorkState(wkState, __ctx);
	    return;
	}
	catch(const ::IceInternal::LocalExceptionWrapper& __ex)
	{
	    __handleExceptionWrapper(__ex);
	}
	catch(const ::Ice::LocalException& __ex)
	{
	    __handleException(__ex, __cnt);
	}
    }
}

::Ice::Int
IceProxy::NVSStreamService::NVSStreamServiceAPI::getCompress(const ::std::string& sKeyID, ::std::string& sInfo, const ::Ice::Context& __ctx)
{
    int __cnt = 0;
    while(true)
    {
	try
	{
	    __checkTwowayOnly(__NVSStreamService__NVSStreamServiceAPI__getCompress_name);
	    ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase = __getDelegate();
	    ::IceDelegate::NVSStreamService::NVSStreamServiceAPI* __del = dynamic_cast< ::IceDelegate::NVSStreamService::NVSStreamServiceAPI*>(__delBase.get());
	    return __del->getCompress(sKeyID, sInfo, __ctx);
	}
	catch(const ::IceInternal::LocalExceptionWrapper& __ex)
	{
	    __handleExceptionWrapper(__ex);
	}
	catch(const ::Ice::LocalException& __ex)
	{
	    __handleException(__ex, __cnt);
	}
    }
}

void
IceProxy::NVSStreamService::NVSStreamServiceAPI::setCompress(const ::std::string& sKeyID, const ::std::string& sInfo, const ::Ice::Context& __ctx)
{
    int __cnt = 0;
    while(true)
    {
	try
	{
	    ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase = __getDelegate();
	    ::IceDelegate::NVSStreamService::NVSStreamServiceAPI* __del = dynamic_cast< ::IceDelegate::NVSStreamService::NVSStreamServiceAPI*>(__delBase.get());
	    __del->setCompress(sKeyID, sInfo, __ctx);
	    return;
	}
	catch(const ::IceInternal::LocalExceptionWrapper& __ex)
	{
	    __handleExceptionWrapper(__ex);
	}
	catch(const ::Ice::LocalException& __ex)
	{
	    __handleException(__ex, __cnt);
	}
    }
}

::Ice::Int
IceProxy::NVSStreamService::NVSStreamServiceAPI::getVideoEffect(const ::std::string& sKeyID, ::Ice::Int& dwBrightValue, ::Ice::Int& dwContrastValue, ::Ice::Int& dwSaturationValue, ::Ice::Int& dwHueValue, const ::Ice::Context& __ctx)
{
    int __cnt = 0;
    while(true)
    {
	try
	{
	    __checkTwowayOnly(__NVSStreamService__NVSStreamServiceAPI__getVideoEffect_name);
	    ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase = __getDelegate();
	    ::IceDelegate::NVSStreamService::NVSStreamServiceAPI* __del = dynamic_cast< ::IceDelegate::NVSStreamService::NVSStreamServiceAPI*>(__delBase.get());
	    return __del->getVideoEffect(sKeyID, dwBrightValue, dwContrastValue, dwSaturationValue, dwHueValue, __ctx);
	}
	catch(const ::IceInternal::LocalExceptionWrapper& __ex)
	{
	    __handleExceptionWrapper(__ex);
	}
	catch(const ::Ice::LocalException& __ex)
	{
	    __handleException(__ex, __cnt);
	}
    }
}

void
IceProxy::NVSStreamService::NVSStreamServiceAPI::setVideoEffect(const ::std::string& sKeyID, ::Ice::Int dwBrightValue, ::Ice::Int dwContrastValue, ::Ice::Int dwSaturationValue, ::Ice::Int dwHueValue, const ::Ice::Context& __ctx)
{
    int __cnt = 0;
    while(true)
    {
	try
	{
	    ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase = __getDelegate();
	    ::IceDelegate::NVSStreamService::NVSStreamServiceAPI* __del = dynamic_cast< ::IceDelegate::NVSStreamService::NVSStreamServiceAPI*>(__delBase.get());
	    __del->setVideoEffect(sKeyID, dwBrightValue, dwContrastValue, dwSaturationValue, dwHueValue, __ctx);
	    return;
	}
	catch(const ::IceInternal::LocalExceptionWrapper& __ex)
	{
	    __handleExceptionWrapper(__ex);
	}
	catch(const ::Ice::LocalException& __ex)
	{
	    __handleException(__ex, __cnt);
	}
    }
}

::Ice::Int
IceProxy::NVSStreamService::NVSStreamServiceAPI::requestControlCamera(const ::std::string& sKeyID, const ::Ice::Context& __ctx)
{
    int __cnt = 0;
    while(true)
    {
	try
	{
	    __checkTwowayOnly(__NVSStreamService__NVSStreamServiceAPI__requestControlCamera_name);
	    ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase = __getDelegate();
	    ::IceDelegate::NVSStreamService::NVSStreamServiceAPI* __del = dynamic_cast< ::IceDelegate::NVSStreamService::NVSStreamServiceAPI*>(__delBase.get());
	    return __del->requestControlCamera(sKeyID, __ctx);
	}
	catch(const ::IceInternal::LocalExceptionWrapper& __ex)
	{
	    __handleExceptionWrapper(__ex);
	}
	catch(const ::Ice::LocalException& __ex)
	{
	    __handleException(__ex, __cnt);
	}
    }
}

::Ice::Int
IceProxy::NVSStreamService::NVSStreamServiceAPI::controlCameraSpeed(const ::std::string& sKeyID, ::Ice::Int nCmd, bool bEnable, ::Ice::Int nSpeed, const ::Ice::Context& __ctx)
{
    int __cnt = 0;
    while(true)
    {
	try
	{
	    __checkTwowayOnly(__NVSStreamService__NVSStreamServiceAPI__controlCameraSpeed_name);
	    ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase = __getDelegate();
	    ::IceDelegate::NVSStreamService::NVSStreamServiceAPI* __del = dynamic_cast< ::IceDelegate::NVSStreamService::NVSStreamServiceAPI*>(__delBase.get());
	    return __del->controlCameraSpeed(sKeyID, nCmd, bEnable, nSpeed, __ctx);
	}
	catch(const ::IceInternal::LocalExceptionWrapper& __ex)
	{
	    __handleExceptionWrapper(__ex);
	}
	catch(const ::Ice::LocalException& __ex)
	{
	    __handleException(__ex, __cnt);
	}
    }
}

::Ice::Int
IceProxy::NVSStreamService::NVSStreamServiceAPI::cancelControlCamera(const ::std::string& sKeyID, const ::Ice::Context& __ctx)
{
    int __cnt = 0;
    while(true)
    {
	try
	{
	    __checkTwowayOnly(__NVSStreamService__NVSStreamServiceAPI__cancelControlCamera_name);
	    ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase = __getDelegate();
	    ::IceDelegate::NVSStreamService::NVSStreamServiceAPI* __del = dynamic_cast< ::IceDelegate::NVSStreamService::NVSStreamServiceAPI*>(__delBase.get());
	    return __del->cancelControlCamera(sKeyID, __ctx);
	}
	catch(const ::IceInternal::LocalExceptionWrapper& __ex)
	{
	    __handleExceptionWrapper(__ex);
	}
	catch(const ::Ice::LocalException& __ex)
	{
	    __handleException(__ex, __cnt);
	}
    }
}

::Ice::Int
IceProxy::NVSStreamService::NVSStreamServiceAPI::presetPTZ(const ::std::string& sKeyID, ::Ice::Int nCmd, ::Ice::Int nIndex, const ::Ice::Context& __ctx)
{
    int __cnt = 0;
    while(true)
    {
	try
	{
	    __checkTwowayOnly(__NVSStreamService__NVSStreamServiceAPI__presetPTZ_name);
	    ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase = __getDelegate();
	    ::IceDelegate::NVSStreamService::NVSStreamServiceAPI* __del = dynamic_cast< ::IceDelegate::NVSStreamService::NVSStreamServiceAPI*>(__delBase.get());
	    return __del->presetPTZ(sKeyID, nCmd, nIndex, __ctx);
	}
	catch(const ::IceInternal::LocalExceptionWrapper& __ex)
	{
	    __handleExceptionWrapper(__ex);
	}
	catch(const ::Ice::LocalException& __ex)
	{
	    __handleException(__ex, __cnt);
	}
    }
}

void
IceProxy::NVSStreamService::NVSStreamServiceAPI::HeartBeat(const ::Ice::Context& __ctx)
{
    int __cnt = 0;
    while(true)
    {
	try
	{
	    ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase = __getDelegate();
	    ::IceDelegate::NVSStreamService::NVSStreamServiceAPI* __del = dynamic_cast< ::IceDelegate::NVSStreamService::NVSStreamServiceAPI*>(__delBase.get());
	    __del->HeartBeat(__ctx);
	    return;
	}
	catch(const ::IceInternal::LocalExceptionWrapper& __ex)
	{
	    __handleExceptionWrapper(__ex);
	}
	catch(const ::Ice::LocalException& __ex)
	{
	    __handleException(__ex, __cnt);
	}
    }
}

const ::std::string&
IceProxy::NVSStreamService::NVSStreamServiceAPI::ice_staticId()
{
    return ::NVSStreamService::NVSStreamServiceAPI::ice_staticId();
}

::IceInternal::Handle< ::IceDelegateM::Ice::Object>
IceProxy::NVSStreamService::NVSStreamServiceAPI::__createDelegateM()
{
    return ::IceInternal::Handle< ::IceDelegateM::Ice::Object>(new ::IceDelegateM::NVSStreamService::NVSStreamServiceAPI);
}

::IceInternal::Handle< ::IceDelegateD::Ice::Object>
IceProxy::NVSStreamService::NVSStreamServiceAPI::__createDelegateD()
{
    return ::IceInternal::Handle< ::IceDelegateD::Ice::Object>(new ::IceDelegateD::NVSStreamService::NVSStreamServiceAPI);
}

bool
IceProxy::NVSStreamService::operator==(const ::IceProxy::NVSStreamService::NVSStreamServiceAPI& l, const ::IceProxy::NVSStreamService::NVSStreamServiceAPI& r)
{
    return static_cast<const ::IceProxy::Ice::Object&>(l) == static_cast<const ::IceProxy::Ice::Object&>(r);
}

bool
IceProxy::NVSStreamService::operator!=(const ::IceProxy::NVSStreamService::NVSStreamServiceAPI& l, const ::IceProxy::NVSStreamService::NVSStreamServiceAPI& r)
{
    return static_cast<const ::IceProxy::Ice::Object&>(l) != static_cast<const ::IceProxy::Ice::Object&>(r);
}

bool
IceProxy::NVSStreamService::operator<(const ::IceProxy::NVSStreamService::NVSStreamServiceAPI& l, const ::IceProxy::NVSStreamService::NVSStreamServiceAPI& r)
{
    return static_cast<const ::IceProxy::Ice::Object&>(l) < static_cast<const ::IceProxy::Ice::Object&>(r);
}

bool
IceProxy::NVSStreamService::operator<=(const ::IceProxy::NVSStreamService::NVSStreamServiceAPI& l, const ::IceProxy::NVSStreamService::NVSStreamServiceAPI& r)
{
    return l < r || l == r;
}

bool
IceProxy::NVSStreamService::operator>(const ::IceProxy::NVSStreamService::NVSStreamServiceAPI& l, const ::IceProxy::NVSStreamService::NVSStreamServiceAPI& r)
{
    return !(l < r) && !(l == r);
}

bool
IceProxy::NVSStreamService::operator>=(const ::IceProxy::NVSStreamService::NVSStreamServiceAPI& l, const ::IceProxy::NVSStreamService::NVSStreamServiceAPI& r)
{
    return !(l < r);
}

bool
IceDelegateM::NVSStreamService::NVSStreamDataReceiver::sendStreamBody(const ::NVSStreamService::StreamPiece& sd, const ::Ice::Context& __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __NVSStreamService__NVSStreamDataReceiver__sendStreamBody_name, ::Ice::Normal, __context, __compress);
    try
    {
	::IceInternal::BasicStream* __os = __og.os();
	sd.__write(__os);
    }
    catch(const ::Ice::LocalException& __ex)
    {
	__og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
	::IceInternal::BasicStream* __is = __og.is();
	if(!__ok)
	{
	    try
	    {
		__is->throwException();
	    }
	    catch(const ::Ice::UserException& __ex)
	    {
		throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
	    }
	}
	bool __ret;
	__is->read(__ret);
	return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
	throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

bool
IceDelegateM::NVSStreamService::NVSStreamDataReceiver::sendStreamHead(const ::NVSStreamService::StreamPiece& sd, const ::Ice::Context& __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __NVSStreamService__NVSStreamDataReceiver__sendStreamHead_name, ::Ice::Normal, __context, __compress);
    try
    {
	::IceInternal::BasicStream* __os = __og.os();
	sd.__write(__os);
    }
    catch(const ::Ice::LocalException& __ex)
    {
	__og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
	::IceInternal::BasicStream* __is = __og.is();
	if(!__ok)
	{
	    try
	    {
		__is->throwException();
	    }
	    catch(const ::Ice::UserException& __ex)
	    {
		throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
	    }
	}
	bool __ret;
	__is->read(__ret);
	return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
	throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::Ice::Int
IceDelegateM::NVSStreamService::NVSStreamServiceAPI::startPlayer(const ::NVSStreamService::DeviceInfo& connectInfo, const ::Ice::Identity& ident, ::std::string& sKey, const ::Ice::Context& __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __NVSStreamService__NVSStreamServiceAPI__startPlayer_name, ::Ice::Normal, __context, __compress);
    try
    {
	::IceInternal::BasicStream* __os = __og.os();
	connectInfo.__write(__os);
	ident.__write(__os);
    }
    catch(const ::Ice::LocalException& __ex)
    {
	__og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
	::IceInternal::BasicStream* __is = __og.is();
	if(!__ok)
	{
	    try
	    {
		__is->throwException();
	    }
	    catch(const ::Ice::UserException& __ex)
	    {
		throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
	    }
	}
	::Ice::Int __ret;
	__is->read(sKey);
	__is->read(__ret);
	return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
	throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::Ice::Int
IceDelegateM::NVSStreamService::NVSStreamServiceAPI::stopVideo(const ::std::string& sKeyID, const ::Ice::Context& __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __NVSStreamService__NVSStreamServiceAPI__stopVideo_name, ::Ice::Normal, __context, __compress);
    try
    {
	::IceInternal::BasicStream* __os = __og.os();
	__os->write(sKeyID);
    }
    catch(const ::Ice::LocalException& __ex)
    {
	__og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
	::IceInternal::BasicStream* __is = __og.is();
	if(!__ok)
	{
	    try
	    {
		__is->throwException();
	    }
	    catch(const ::Ice::UserException& __ex)
	    {
		throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
	    }
	}
	::Ice::Int __ret;
	__is->read(__ret);
	return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
	throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::NVSStreamService::NVSStreamServiceAPI::getWorkState(::NVSStreamService::WorkState& wkState, const ::Ice::Context& __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __NVSStreamService__NVSStreamServiceAPI__getWorkState_name, ::Ice::Normal, __context, __compress);
    bool __ok = __og.invoke();
    try
    {
	::IceInternal::BasicStream* __is = __og.is();
	if(!__ok)
	{
	    try
	    {
		__is->throwException();
	    }
	    catch(const ::Ice::UserException& __ex)
	    {
		throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
	    }
	}
	wkState.__read(__is);
    }
    catch(const ::Ice::LocalException& __ex)
    {
	throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::Ice::Int
IceDelegateM::NVSStreamService::NVSStreamServiceAPI::getCompress(const ::std::string& sKeyID, ::std::string& sInfo, const ::Ice::Context& __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __NVSStreamService__NVSStreamServiceAPI__getCompress_name, ::Ice::Normal, __context, __compress);
    try
    {
	::IceInternal::BasicStream* __os = __og.os();
	__os->write(sKeyID);
    }
    catch(const ::Ice::LocalException& __ex)
    {
	__og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
	::IceInternal::BasicStream* __is = __og.is();
	if(!__ok)
	{
	    try
	    {
		__is->throwException();
	    }
	    catch(const ::Ice::UserException& __ex)
	    {
		throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
	    }
	}
	::Ice::Int __ret;
	__is->read(sInfo);
	__is->read(__ret);
	return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
	throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::NVSStreamService::NVSStreamServiceAPI::setCompress(const ::std::string& sKeyID, const ::std::string& sInfo, const ::Ice::Context& __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __NVSStreamService__NVSStreamServiceAPI__setCompress_name, ::Ice::Normal, __context, __compress);
    try
    {
	::IceInternal::BasicStream* __os = __og.os();
	__os->write(sKeyID);
	__os->write(sInfo);
    }
    catch(const ::Ice::LocalException& __ex)
    {
	__og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
	::IceInternal::BasicStream* __is = __og.is();
	if(!__ok)
	{
	    try
	    {
		__is->throwException();
	    }
	    catch(const ::Ice::UserException& __ex)
	    {
		throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
	    }
	}
    }
    catch(const ::Ice::LocalException& __ex)
    {
	throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::Ice::Int
IceDelegateM::NVSStreamService::NVSStreamServiceAPI::getVideoEffect(const ::std::string& sKeyID, ::Ice::Int& dwBrightValue, ::Ice::Int& dwContrastValue, ::Ice::Int& dwSaturationValue, ::Ice::Int& dwHueValue, const ::Ice::Context& __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __NVSStreamService__NVSStreamServiceAPI__getVideoEffect_name, ::Ice::Normal, __context, __compress);
    try
    {
	::IceInternal::BasicStream* __os = __og.os();
	__os->write(sKeyID);
    }
    catch(const ::Ice::LocalException& __ex)
    {
	__og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
	::IceInternal::BasicStream* __is = __og.is();
	if(!__ok)
	{
	    try
	    {
		__is->throwException();
	    }
	    catch(const ::Ice::UserException& __ex)
	    {
		throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
	    }
	}
	::Ice::Int __ret;
	__is->read(dwBrightValue);
	__is->read(dwContrastValue);
	__is->read(dwSaturationValue);
	__is->read(dwHueValue);
	__is->read(__ret);
	return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
	throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::NVSStreamService::NVSStreamServiceAPI::setVideoEffect(const ::std::string& sKeyID, ::Ice::Int dwBrightValue, ::Ice::Int dwContrastValue, ::Ice::Int dwSaturationValue, ::Ice::Int dwHueValue, const ::Ice::Context& __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __NVSStreamService__NVSStreamServiceAPI__setVideoEffect_name, ::Ice::Normal, __context, __compress);
    try
    {
	::IceInternal::BasicStream* __os = __og.os();
	__os->write(sKeyID);
	__os->write(dwBrightValue);
	__os->write(dwContrastValue);
	__os->write(dwSaturationValue);
	__os->write(dwHueValue);
    }
    catch(const ::Ice::LocalException& __ex)
    {
	__og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
	::IceInternal::BasicStream* __is = __og.is();
	if(!__ok)
	{
	    try
	    {
		__is->throwException();
	    }
	    catch(const ::Ice::UserException& __ex)
	    {
		throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
	    }
	}
    }
    catch(const ::Ice::LocalException& __ex)
    {
	throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::Ice::Int
IceDelegateM::NVSStreamService::NVSStreamServiceAPI::requestControlCamera(const ::std::string& sKeyID, const ::Ice::Context& __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __NVSStreamService__NVSStreamServiceAPI__requestControlCamera_name, ::Ice::Normal, __context, __compress);
    try
    {
	::IceInternal::BasicStream* __os = __og.os();
	__os->write(sKeyID);
    }
    catch(const ::Ice::LocalException& __ex)
    {
	__og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
	::IceInternal::BasicStream* __is = __og.is();
	if(!__ok)
	{
	    try
	    {
		__is->throwException();
	    }
	    catch(const ::Ice::UserException& __ex)
	    {
		throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
	    }
	}
	::Ice::Int __ret;
	__is->read(__ret);
	return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
	throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::Ice::Int
IceDelegateM::NVSStreamService::NVSStreamServiceAPI::controlCameraSpeed(const ::std::string& sKeyID, ::Ice::Int nCmd, bool bEnable, ::Ice::Int nSpeed, const ::Ice::Context& __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __NVSStreamService__NVSStreamServiceAPI__controlCameraSpeed_name, ::Ice::Normal, __context, __compress);
    try
    {
	::IceInternal::BasicStream* __os = __og.os();
	__os->write(sKeyID);
	__os->write(nCmd);
	__os->write(bEnable);
	__os->write(nSpeed);
    }
    catch(const ::Ice::LocalException& __ex)
    {
	__og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
	::IceInternal::BasicStream* __is = __og.is();
	if(!__ok)
	{
	    try
	    {
		__is->throwException();
	    }
	    catch(const ::Ice::UserException& __ex)
	    {
		throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
	    }
	}
	::Ice::Int __ret;
	__is->read(__ret);
	return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
	throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::Ice::Int
IceDelegateM::NVSStreamService::NVSStreamServiceAPI::cancelControlCamera(const ::std::string& sKeyID, const ::Ice::Context& __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __NVSStreamService__NVSStreamServiceAPI__cancelControlCamera_name, ::Ice::Normal, __context, __compress);
    try
    {
	::IceInternal::BasicStream* __os = __og.os();
	__os->write(sKeyID);
    }
    catch(const ::Ice::LocalException& __ex)
    {
	__og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
	::IceInternal::BasicStream* __is = __og.is();
	if(!__ok)
	{
	    try
	    {
		__is->throwException();
	    }
	    catch(const ::Ice::UserException& __ex)
	    {
		throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
	    }
	}
	::Ice::Int __ret;
	__is->read(__ret);
	return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
	throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::Ice::Int
IceDelegateM::NVSStreamService::NVSStreamServiceAPI::presetPTZ(const ::std::string& sKeyID, ::Ice::Int nCmd, ::Ice::Int nIndex, const ::Ice::Context& __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __NVSStreamService__NVSStreamServiceAPI__presetPTZ_name, ::Ice::Normal, __context, __compress);
    try
    {
	::IceInternal::BasicStream* __os = __og.os();
	__os->write(sKeyID);
	__os->write(nCmd);
	__os->write(nIndex);
    }
    catch(const ::Ice::LocalException& __ex)
    {
	__og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
	::IceInternal::BasicStream* __is = __og.is();
	if(!__ok)
	{
	    try
	    {
		__is->throwException();
	    }
	    catch(const ::Ice::UserException& __ex)
	    {
		throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
	    }
	}
	::Ice::Int __ret;
	__is->read(__ret);
	return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
	throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::NVSStreamService::NVSStreamServiceAPI::HeartBeat(const ::Ice::Context& __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __NVSStreamService__NVSStreamServiceAPI__HeartBeat_name, ::Ice::Normal, __context, __compress);
    bool __ok = __og.invoke();
    try
    {
	::IceInternal::BasicStream* __is = __og.is();
	if(!__ok)
	{
	    try
	    {
		__is->throwException();
	    }
	    catch(const ::Ice::UserException& __ex)
	    {
		throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
	    }
	}
    }
    catch(const ::Ice::LocalException& __ex)
    {
	throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

bool
IceDelegateD::NVSStreamService::NVSStreamDataReceiver::sendStreamBody(const ::NVSStreamService::StreamPiece& sd, const ::Ice::Context& __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __NVSStreamService__NVSStreamDataReceiver__sendStreamBody_name, ::Ice::Normal, __context);
    while(true)
    {
	::IceInternal::Direct __direct(__current);
	::NVSStreamService::NVSStreamDataReceiver* __servant = dynamic_cast< ::NVSStreamService::NVSStreamDataReceiver*>(__direct.servant().get());
	if(!__servant)
	{
	    ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
	    __opEx.id = __current.id;
	    __opEx.facet = __current.facet;
	    __opEx.operation = __current.operation;
	    throw __opEx;
	}
	try
	{
	    return __servant->sendStreamBody(sd, __current);
	}
	catch(const ::Ice::LocalException& __ex)
	{
	    throw ::IceInternal::LocalExceptionWrapper(__ex, false);
	}
    }
}

bool
IceDelegateD::NVSStreamService::NVSStreamDataReceiver::sendStreamHead(const ::NVSStreamService::StreamPiece& sd, const ::Ice::Context& __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __NVSStreamService__NVSStreamDataReceiver__sendStreamHead_name, ::Ice::Normal, __context);
    while(true)
    {
	::IceInternal::Direct __direct(__current);
	::NVSStreamService::NVSStreamDataReceiver* __servant = dynamic_cast< ::NVSStreamService::NVSStreamDataReceiver*>(__direct.servant().get());
	if(!__servant)
	{
	    ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
	    __opEx.id = __current.id;
	    __opEx.facet = __current.facet;
	    __opEx.operation = __current.operation;
	    throw __opEx;
	}
	try
	{
	    return __servant->sendStreamHead(sd, __current);
	}
	catch(const ::Ice::LocalException& __ex)
	{
	    throw ::IceInternal::LocalExceptionWrapper(__ex, false);
	}
    }
}

::Ice::Int
IceDelegateD::NVSStreamService::NVSStreamServiceAPI::startPlayer(const ::NVSStreamService::DeviceInfo& connectInfo, const ::Ice::Identity& ident, ::std::string& sKey, const ::Ice::Context& __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __NVSStreamService__NVSStreamServiceAPI__startPlayer_name, ::Ice::Normal, __context);
    while(true)
    {
	::IceInternal::Direct __direct(__current);
	::NVSStreamService::NVSStreamServiceAPI* __servant = dynamic_cast< ::NVSStreamService::NVSStreamServiceAPI*>(__direct.servant().get());
	if(!__servant)
	{
	    ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
	    __opEx.id = __current.id;
	    __opEx.facet = __current.facet;
	    __opEx.operation = __current.operation;
	    throw __opEx;
	}
	try
	{
	    return __servant->startPlayer(connectInfo, ident, sKey, __current);
	}
	catch(const ::Ice::LocalException& __ex)
	{
	    throw ::IceInternal::LocalExceptionWrapper(__ex, false);
	}
    }
}

::Ice::Int
IceDelegateD::NVSStreamService::NVSStreamServiceAPI::stopVideo(const ::std::string& sKeyID, const ::Ice::Context& __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __NVSStreamService__NVSStreamServiceAPI__stopVideo_name, ::Ice::Normal, __context);
    while(true)
    {
	::IceInternal::Direct __direct(__current);
	::NVSStreamService::NVSStreamServiceAPI* __servant = dynamic_cast< ::NVSStreamService::NVSStreamServiceAPI*>(__direct.servant().get());
	if(!__servant)
	{
	    ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
	    __opEx.id = __current.id;
	    __opEx.facet = __current.facet;
	    __opEx.operation = __current.operation;
	    throw __opEx;
	}
	try
	{
	    return __servant->stopVideo(sKeyID, __current);
	}
	catch(const ::Ice::LocalException& __ex)
	{
	    throw ::IceInternal::LocalExceptionWrapper(__ex, false);
	}
    }
}

void
IceDelegateD::NVSStreamService::NVSStreamServiceAPI::getWorkState(::NVSStreamService::WorkState& wkState, const ::Ice::Context& __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __NVSStreamService__NVSStreamServiceAPI__getWorkState_name, ::Ice::Normal, __context);
    while(true)
    {
	::IceInternal::Direct __direct(__current);
	::NVSStreamService::NVSStreamServiceAPI* __servant = dynamic_cast< ::NVSStreamService::NVSStreamServiceAPI*>(__direct.servant().get());
	if(!__servant)
	{
	    ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
	    __opEx.id = __current.id;
	    __opEx.facet = __current.facet;
	    __opEx.operation = __current.operation;
	    throw __opEx;
	}
	try
	{
	    __servant->getWorkState(wkState, __current);
	    return;
	}
	catch(const ::Ice::LocalException& __ex)
	{
	    throw ::IceInternal::LocalExceptionWrapper(__ex, false);
	}
    }
}

::Ice::Int
IceDelegateD::NVSStreamService::NVSStreamServiceAPI::getCompress(const ::std::string& sKeyID, ::std::string& sInfo, const ::Ice::Context& __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __NVSStreamService__NVSStreamServiceAPI__getCompress_name, ::Ice::Normal, __context);
    while(true)
    {
	::IceInternal::Direct __direct(__current);
	::NVSStreamService::NVSStreamServiceAPI* __servant = dynamic_cast< ::NVSStreamService::NVSStreamServiceAPI*>(__direct.servant().get());
	if(!__servant)
	{
	    ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
	    __opEx.id = __current.id;
	    __opEx.facet = __current.facet;
	    __opEx.operation = __current.operation;
	    throw __opEx;
	}
	try
	{
	    return __servant->getCompress(sKeyID, sInfo, __current);
	}
	catch(const ::Ice::LocalException& __ex)
	{
	    throw ::IceInternal::LocalExceptionWrapper(__ex, false);
	}
    }
}

void
IceDelegateD::NVSStreamService::NVSStreamServiceAPI::setCompress(const ::std::string& sKeyID, const ::std::string& sInfo, const ::Ice::Context& __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __NVSStreamService__NVSStreamServiceAPI__setCompress_name, ::Ice::Normal, __context);
    while(true)
    {
	::IceInternal::Direct __direct(__current);
	::NVSStreamService::NVSStreamServiceAPI* __servant = dynamic_cast< ::NVSStreamService::NVSStreamServiceAPI*>(__direct.servant().get());
	if(!__servant)
	{
	    ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
	    __opEx.id = __current.id;
	    __opEx.facet = __current.facet;
	    __opEx.operation = __current.operation;
	    throw __opEx;
	}
	try
	{
	    __servant->setCompress(sKeyID, sInfo, __current);
	    return;
	}
	catch(const ::Ice::LocalException& __ex)
	{
	    throw ::IceInternal::LocalExceptionWrapper(__ex, false);
	}
    }
}

::Ice::Int
IceDelegateD::NVSStreamService::NVSStreamServiceAPI::getVideoEffect(const ::std::string& sKeyID, ::Ice::Int& dwBrightValue, ::Ice::Int& dwContrastValue, ::Ice::Int& dwSaturationValue, ::Ice::Int& dwHueValue, const ::Ice::Context& __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __NVSStreamService__NVSStreamServiceAPI__getVideoEffect_name, ::Ice::Normal, __context);
    while(true)
    {
	::IceInternal::Direct __direct(__current);
	::NVSStreamService::NVSStreamServiceAPI* __servant = dynamic_cast< ::NVSStreamService::NVSStreamServiceAPI*>(__direct.servant().get());
	if(!__servant)
	{
	    ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
	    __opEx.id = __current.id;
	    __opEx.facet = __current.facet;
	    __opEx.operation = __current.operation;
	    throw __opEx;
	}
	try
	{
	    return __servant->getVideoEffect(sKeyID, dwBrightValue, dwContrastValue, dwSaturationValue, dwHueValue, __current);
	}
	catch(const ::Ice::LocalException& __ex)
	{
	    throw ::IceInternal::LocalExceptionWrapper(__ex, false);
	}
    }
}

void
IceDelegateD::NVSStreamService::NVSStreamServiceAPI::setVideoEffect(const ::std::string& sKeyID, ::Ice::Int dwBrightValue, ::Ice::Int dwContrastValue, ::Ice::Int dwSaturationValue, ::Ice::Int dwHueValue, const ::Ice::Context& __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __NVSStreamService__NVSStreamServiceAPI__setVideoEffect_name, ::Ice::Normal, __context);
    while(true)
    {
	::IceInternal::Direct __direct(__current);
	::NVSStreamService::NVSStreamServiceAPI* __servant = dynamic_cast< ::NVSStreamService::NVSStreamServiceAPI*>(__direct.servant().get());
	if(!__servant)
	{
	    ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
	    __opEx.id = __current.id;
	    __opEx.facet = __current.facet;
	    __opEx.operation = __current.operation;
	    throw __opEx;
	}
	try
	{
	    __servant->setVideoEffect(sKeyID, dwBrightValue, dwContrastValue, dwSaturationValue, dwHueValue, __current);
	    return;
	}
	catch(const ::Ice::LocalException& __ex)
	{
	    throw ::IceInternal::LocalExceptionWrapper(__ex, false);
	}
    }
}

::Ice::Int
IceDelegateD::NVSStreamService::NVSStreamServiceAPI::requestControlCamera(const ::std::string& sKeyID, const ::Ice::Context& __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __NVSStreamService__NVSStreamServiceAPI__requestControlCamera_name, ::Ice::Normal, __context);
    while(true)
    {
	::IceInternal::Direct __direct(__current);
	::NVSStreamService::NVSStreamServiceAPI* __servant = dynamic_cast< ::NVSStreamService::NVSStreamServiceAPI*>(__direct.servant().get());
	if(!__servant)
	{
	    ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
	    __opEx.id = __current.id;
	    __opEx.facet = __current.facet;
	    __opEx.operation = __current.operation;
	    throw __opEx;
	}
	try
	{
	    return __servant->requestControlCamera(sKeyID, __current);
	}
	catch(const ::Ice::LocalException& __ex)
	{
	    throw ::IceInternal::LocalExceptionWrapper(__ex, false);
	}
    }
}

::Ice::Int
IceDelegateD::NVSStreamService::NVSStreamServiceAPI::controlCameraSpeed(const ::std::string& sKeyID, ::Ice::Int nCmd, bool bEnable, ::Ice::Int nSpeed, const ::Ice::Context& __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __NVSStreamService__NVSStreamServiceAPI__controlCameraSpeed_name, ::Ice::Normal, __context);
    while(true)
    {
	::IceInternal::Direct __direct(__current);
	::NVSStreamService::NVSStreamServiceAPI* __servant = dynamic_cast< ::NVSStreamService::NVSStreamServiceAPI*>(__direct.servant().get());
	if(!__servant)
	{
	    ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
	    __opEx.id = __current.id;
	    __opEx.facet = __current.facet;
	    __opEx.operation = __current.operation;
	    throw __opEx;
	}
	try
	{
	    return __servant->controlCameraSpeed(sKeyID, nCmd, bEnable, nSpeed, __current);
	}
	catch(const ::Ice::LocalException& __ex)
	{
	    throw ::IceInternal::LocalExceptionWrapper(__ex, false);
	}
    }
}

::Ice::Int
IceDelegateD::NVSStreamService::NVSStreamServiceAPI::cancelControlCamera(const ::std::string& sKeyID, const ::Ice::Context& __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __NVSStreamService__NVSStreamServiceAPI__cancelControlCamera_name, ::Ice::Normal, __context);
    while(true)
    {
	::IceInternal::Direct __direct(__current);
	::NVSStreamService::NVSStreamServiceAPI* __servant = dynamic_cast< ::NVSStreamService::NVSStreamServiceAPI*>(__direct.servant().get());
	if(!__servant)
	{
	    ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
	    __opEx.id = __current.id;
	    __opEx.facet = __current.facet;
	    __opEx.operation = __current.operation;
	    throw __opEx;
	}
	try
	{
	    return __servant->cancelControlCamera(sKeyID, __current);
	}
	catch(const ::Ice::LocalException& __ex)
	{
	    throw ::IceInternal::LocalExceptionWrapper(__ex, false);
	}
    }
}

::Ice::Int
IceDelegateD::NVSStreamService::NVSStreamServiceAPI::presetPTZ(const ::std::string& sKeyID, ::Ice::Int nCmd, ::Ice::Int nIndex, const ::Ice::Context& __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __NVSStreamService__NVSStreamServiceAPI__presetPTZ_name, ::Ice::Normal, __context);
    while(true)
    {
	::IceInternal::Direct __direct(__current);
	::NVSStreamService::NVSStreamServiceAPI* __servant = dynamic_cast< ::NVSStreamService::NVSStreamServiceAPI*>(__direct.servant().get());
	if(!__servant)
	{
	    ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
	    __opEx.id = __current.id;
	    __opEx.facet = __current.facet;
	    __opEx.operation = __current.operation;
	    throw __opEx;
	}
	try
	{
	    return __servant->presetPTZ(sKeyID, nCmd, nIndex, __current);
	}
	catch(const ::Ice::LocalException& __ex)
	{
	    throw ::IceInternal::LocalExceptionWrapper(__ex, false);
	}
    }
}

void
IceDelegateD::NVSStreamService::NVSStreamServiceAPI::HeartBeat(const ::Ice::Context& __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __NVSStreamService__NVSStreamServiceAPI__HeartBeat_name, ::Ice::Normal, __context);
    while(true)
    {
	::IceInternal::Direct __direct(__current);
	::NVSStreamService::NVSStreamServiceAPI* __servant = dynamic_cast< ::NVSStreamService::NVSStreamServiceAPI*>(__direct.servant().get());
	if(!__servant)
	{
	    ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
	    __opEx.id = __current.id;
	    __opEx.facet = __current.facet;
	    __opEx.operation = __current.operation;
	    throw __opEx;
	}
	try
	{
	    __servant->HeartBeat(__current);
	    return;
	}
	catch(const ::Ice::LocalException& __ex)
	{
	    throw ::IceInternal::LocalExceptionWrapper(__ex, false);
	}
    }
}

::Ice::ObjectPtr
NVSStreamService::NVSStreamDataReceiver::ice_clone() const
{
    throw ::Ice::CloneNotImplementedException(__FILE__, __LINE__);
    return 0; // to avoid a warning with some compilers
}

static const ::std::string __NVSStreamService__NVSStreamDataReceiver_ids[2] =
{
    "::Ice::Object",
    "::NVSStreamService::NVSStreamDataReceiver"
};

bool
NVSStreamService::NVSStreamDataReceiver::ice_isA(const ::std::string& _s, const ::Ice::Current&) const
{
    return ::std::binary_search(__NVSStreamService__NVSStreamDataReceiver_ids, __NVSStreamService__NVSStreamDataReceiver_ids + 2, _s);
}

::std::vector< ::std::string>
NVSStreamService::NVSStreamDataReceiver::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&__NVSStreamService__NVSStreamDataReceiver_ids[0], &__NVSStreamService__NVSStreamDataReceiver_ids[2]);
}

const ::std::string&
NVSStreamService::NVSStreamDataReceiver::ice_id(const ::Ice::Current&) const
{
    return __NVSStreamService__NVSStreamDataReceiver_ids[1];
}

const ::std::string&
NVSStreamService::NVSStreamDataReceiver::ice_staticId()
{
    return __NVSStreamService__NVSStreamDataReceiver_ids[1];
}

::IceInternal::DispatchStatus
NVSStreamService::NVSStreamDataReceiver::___sendStreamBody(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::NVSStreamService::StreamPiece sd;
    sd.__read(__is);
    bool __ret = sendStreamBody(sd, __current);
    __os->write(__ret);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
NVSStreamService::NVSStreamDataReceiver::___sendStreamHead(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::NVSStreamService::StreamPiece sd;
    sd.__read(__is);
    bool __ret = sendStreamHead(sd, __current);
    __os->write(__ret);
    return ::IceInternal::DispatchOK;
}

static ::std::string __NVSStreamService__NVSStreamDataReceiver_all[] =
{
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping",
    "sendStreamBody",
    "sendStreamHead"
};

::IceInternal::DispatchStatus
NVSStreamService::NVSStreamDataReceiver::__dispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair< ::std::string*, ::std::string*> r = ::std::equal_range(__NVSStreamService__NVSStreamDataReceiver_all, __NVSStreamService__NVSStreamDataReceiver_all + 6, current.operation);
    if(r.first == r.second)
    {
	return ::IceInternal::DispatchOperationNotExist;
    }

    switch(r.first - __NVSStreamService__NVSStreamDataReceiver_all)
    {
	case 0:
	{
	    return ___ice_id(in, current);
	}
	case 1:
	{
	    return ___ice_ids(in, current);
	}
	case 2:
	{
	    return ___ice_isA(in, current);
	}
	case 3:
	{
	    return ___ice_ping(in, current);
	}
	case 4:
	{
	    return ___sendStreamBody(in, current);
	}
	case 5:
	{
	    return ___sendStreamHead(in, current);
	}
    }

    assert(false);
    return ::IceInternal::DispatchOperationNotExist;
}

void
NVSStreamService::NVSStreamDataReceiver::__write(::IceInternal::BasicStream* __os) const
{
    __os->writeTypeId(ice_staticId());
    __os->startWriteSlice();
    __os->endWriteSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Object::__write(__os);
#else
    ::Ice::Object::__write(__os);
#endif
}

void
NVSStreamService::NVSStreamDataReceiver::__read(::IceInternal::BasicStream* __is, bool __rid)
{
    if(__rid)
    {
	::std::string myId;
	__is->readTypeId(myId);
    }
    __is->startReadSlice();
    __is->endReadSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Object::__read(__is, true);
#else
    ::Ice::Object::__read(__is, true);
#endif
}

void
NVSStreamService::NVSStreamDataReceiver::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type NVSStreamService::NVSStreamDataReceiver was not generated with stream support";
    throw ex;
}

void
NVSStreamService::NVSStreamDataReceiver::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type NVSStreamService::NVSStreamDataReceiver was not generated with stream support";
    throw ex;
}

void 
NVSStreamService::__patch__NVSStreamDataReceiverPtr(void* __addr, ::Ice::ObjectPtr& v)
{
    ::NVSStreamService::NVSStreamDataReceiverPtr* p = static_cast< ::NVSStreamService::NVSStreamDataReceiverPtr*>(__addr);
    assert(p);
    *p = ::NVSStreamService::NVSStreamDataReceiverPtr::dynamicCast(v);
    if(v && !*p)
    {
	::Ice::NoObjectFactoryException e(__FILE__, __LINE__);
	e.type = ::NVSStreamService::NVSStreamDataReceiver::ice_staticId();
	throw e;
    }
}

bool
NVSStreamService::operator==(const ::NVSStreamService::NVSStreamDataReceiver& l, const ::NVSStreamService::NVSStreamDataReceiver& r)
{
    return static_cast<const ::Ice::Object&>(l) == static_cast<const ::Ice::Object&>(r);
}

bool
NVSStreamService::operator!=(const ::NVSStreamService::NVSStreamDataReceiver& l, const ::NVSStreamService::NVSStreamDataReceiver& r)
{
    return static_cast<const ::Ice::Object&>(l) != static_cast<const ::Ice::Object&>(r);
}

bool
NVSStreamService::operator<(const ::NVSStreamService::NVSStreamDataReceiver& l, const ::NVSStreamService::NVSStreamDataReceiver& r)
{
    return static_cast<const ::Ice::Object&>(l) < static_cast<const ::Ice::Object&>(r);
}

bool
NVSStreamService::operator<=(const ::NVSStreamService::NVSStreamDataReceiver& l, const ::NVSStreamService::NVSStreamDataReceiver& r)
{
    return l < r || l == r;
}

bool
NVSStreamService::operator>(const ::NVSStreamService::NVSStreamDataReceiver& l, const ::NVSStreamService::NVSStreamDataReceiver& r)
{
    return !(l < r) && !(l == r);
}

bool
NVSStreamService::operator>=(const ::NVSStreamService::NVSStreamDataReceiver& l, const ::NVSStreamService::NVSStreamDataReceiver& r)
{
    return !(l < r);
}

::Ice::ObjectPtr
NVSStreamService::NVSStreamServiceAPI::ice_clone() const
{
    throw ::Ice::CloneNotImplementedException(__FILE__, __LINE__);
    return 0; // to avoid a warning with some compilers
}

static const ::std::string __NVSStreamService__NVSStreamServiceAPI_ids[2] =
{
    "::Ice::Object",
    "::NVSStreamService::NVSStreamServiceAPI"
};

bool
NVSStreamService::NVSStreamServiceAPI::ice_isA(const ::std::string& _s, const ::Ice::Current&) const
{
    return ::std::binary_search(__NVSStreamService__NVSStreamServiceAPI_ids, __NVSStreamService__NVSStreamServiceAPI_ids + 2, _s);
}

::std::vector< ::std::string>
NVSStreamService::NVSStreamServiceAPI::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&__NVSStreamService__NVSStreamServiceAPI_ids[0], &__NVSStreamService__NVSStreamServiceAPI_ids[2]);
}

const ::std::string&
NVSStreamService::NVSStreamServiceAPI::ice_id(const ::Ice::Current&) const
{
    return __NVSStreamService__NVSStreamServiceAPI_ids[1];
}

const ::std::string&
NVSStreamService::NVSStreamServiceAPI::ice_staticId()
{
    return __NVSStreamService__NVSStreamServiceAPI_ids[1];
}

::IceInternal::DispatchStatus
NVSStreamService::NVSStreamServiceAPI::___startPlayer(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::NVSStreamService::DeviceInfo connectInfo;
    ::Ice::Identity ident;
    connectInfo.__read(__is);
    ident.__read(__is);
    ::std::string sKey;
    ::Ice::Int __ret = startPlayer(connectInfo, ident, sKey, __current);
    __os->write(sKey);
    __os->write(__ret);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
NVSStreamService::NVSStreamServiceAPI::___stopVideo(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string sKeyID;
    __is->read(sKeyID);
    ::Ice::Int __ret = stopVideo(sKeyID, __current);
    __os->write(__ret);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
NVSStreamService::NVSStreamServiceAPI::___getWorkState(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __os = __inS.os();
    ::NVSStreamService::WorkState wkState;
    getWorkState(wkState, __current);
    wkState.__write(__os);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
NVSStreamService::NVSStreamServiceAPI::___getCompress(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string sKeyID;
    __is->read(sKeyID);
    ::std::string sInfo;
    ::Ice::Int __ret = getCompress(sKeyID, sInfo, __current);
    __os->write(sInfo);
    __os->write(__ret);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
NVSStreamService::NVSStreamServiceAPI::___setCompress(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::std::string sKeyID;
    ::std::string sInfo;
    __is->read(sKeyID);
    __is->read(sInfo);
    setCompress(sKeyID, sInfo, __current);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
NVSStreamService::NVSStreamServiceAPI::___getVideoEffect(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string sKeyID;
    __is->read(sKeyID);
    ::Ice::Int dwBrightValue;
    ::Ice::Int dwContrastValue;
    ::Ice::Int dwSaturationValue;
    ::Ice::Int dwHueValue;
    ::Ice::Int __ret = getVideoEffect(sKeyID, dwBrightValue, dwContrastValue, dwSaturationValue, dwHueValue, __current);
    __os->write(dwBrightValue);
    __os->write(dwContrastValue);
    __os->write(dwSaturationValue);
    __os->write(dwHueValue);
    __os->write(__ret);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
NVSStreamService::NVSStreamServiceAPI::___setVideoEffect(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::std::string sKeyID;
    ::Ice::Int dwBrightValue;
    ::Ice::Int dwContrastValue;
    ::Ice::Int dwSaturationValue;
    ::Ice::Int dwHueValue;
    __is->read(sKeyID);
    __is->read(dwBrightValue);
    __is->read(dwContrastValue);
    __is->read(dwSaturationValue);
    __is->read(dwHueValue);
    setVideoEffect(sKeyID, dwBrightValue, dwContrastValue, dwSaturationValue, dwHueValue, __current);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
NVSStreamService::NVSStreamServiceAPI::___requestControlCamera(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string sKeyID;
    __is->read(sKeyID);
    ::Ice::Int __ret = requestControlCamera(sKeyID, __current);
    __os->write(__ret);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
NVSStreamService::NVSStreamServiceAPI::___controlCameraSpeed(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string sKeyID;
    ::Ice::Int nCmd;
    bool bEnable;
    ::Ice::Int nSpeed;
    __is->read(sKeyID);
    __is->read(nCmd);
    __is->read(bEnable);
    __is->read(nSpeed);
    ::Ice::Int __ret = controlCameraSpeed(sKeyID, nCmd, bEnable, nSpeed, __current);
    __os->write(__ret);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
NVSStreamService::NVSStreamServiceAPI::___cancelControlCamera(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string sKeyID;
    __is->read(sKeyID);
    ::Ice::Int __ret = cancelControlCamera(sKeyID, __current);
    __os->write(__ret);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
NVSStreamService::NVSStreamServiceAPI::___presetPTZ(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string sKeyID;
    ::Ice::Int nCmd;
    ::Ice::Int nIndex;
    __is->read(sKeyID);
    __is->read(nCmd);
    __is->read(nIndex);
    ::Ice::Int __ret = presetPTZ(sKeyID, nCmd, nIndex, __current);
    __os->write(__ret);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
NVSStreamService::NVSStreamServiceAPI::___HeartBeat(::IceInternal::Incoming&, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    HeartBeat(__current);
    return ::IceInternal::DispatchOK;
}

static ::std::string __NVSStreamService__NVSStreamServiceAPI_all[] =
{
    "HeartBeat",
    "cancelControlCamera",
    "controlCameraSpeed",
    "getCompress",
    "getVideoEffect",
    "getWorkState",
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping",
    "presetPTZ",
    "requestControlCamera",
    "setCompress",
    "setVideoEffect",
    "startPlayer",
    "stopVideo"
};

::IceInternal::DispatchStatus
NVSStreamService::NVSStreamServiceAPI::__dispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair< ::std::string*, ::std::string*> r = ::std::equal_range(__NVSStreamService__NVSStreamServiceAPI_all, __NVSStreamService__NVSStreamServiceAPI_all + 16, current.operation);
    if(r.first == r.second)
    {
	return ::IceInternal::DispatchOperationNotExist;
    }

    switch(r.first - __NVSStreamService__NVSStreamServiceAPI_all)
    {
	case 0:
	{
	    return ___HeartBeat(in, current);
	}
	case 1:
	{
	    return ___cancelControlCamera(in, current);
	}
	case 2:
	{
	    return ___controlCameraSpeed(in, current);
	}
	case 3:
	{
	    return ___getCompress(in, current);
	}
	case 4:
	{
	    return ___getVideoEffect(in, current);
	}
	case 5:
	{
	    return ___getWorkState(in, current);
	}
	case 6:
	{
	    return ___ice_id(in, current);
	}
	case 7:
	{
	    return ___ice_ids(in, current);
	}
	case 8:
	{
	    return ___ice_isA(in, current);
	}
	case 9:
	{
	    return ___ice_ping(in, current);
	}
	case 10:
	{
	    return ___presetPTZ(in, current);
	}
	case 11:
	{
	    return ___requestControlCamera(in, current);
	}
	case 12:
	{
	    return ___setCompress(in, current);
	}
	case 13:
	{
	    return ___setVideoEffect(in, current);
	}
	case 14:
	{
	    return ___startPlayer(in, current);
	}
	case 15:
	{
	    return ___stopVideo(in, current);
	}
    }

    assert(false);
    return ::IceInternal::DispatchOperationNotExist;
}

void
NVSStreamService::NVSStreamServiceAPI::__write(::IceInternal::BasicStream* __os) const
{
    __os->writeTypeId(ice_staticId());
    __os->startWriteSlice();
    __os->endWriteSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Object::__write(__os);
#else
    ::Ice::Object::__write(__os);
#endif
}

void
NVSStreamService::NVSStreamServiceAPI::__read(::IceInternal::BasicStream* __is, bool __rid)
{
    if(__rid)
    {
	::std::string myId;
	__is->readTypeId(myId);
    }
    __is->startReadSlice();
    __is->endReadSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Object::__read(__is, true);
#else
    ::Ice::Object::__read(__is, true);
#endif
}

void
NVSStreamService::NVSStreamServiceAPI::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type NVSStreamService::NVSStreamServiceAPI was not generated with stream support";
    throw ex;
}

void
NVSStreamService::NVSStreamServiceAPI::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type NVSStreamService::NVSStreamServiceAPI was not generated with stream support";
    throw ex;
}

void 
NVSStreamService::__patch__NVSStreamServiceAPIPtr(void* __addr, ::Ice::ObjectPtr& v)
{
    ::NVSStreamService::NVSStreamServiceAPIPtr* p = static_cast< ::NVSStreamService::NVSStreamServiceAPIPtr*>(__addr);
    assert(p);
    *p = ::NVSStreamService::NVSStreamServiceAPIPtr::dynamicCast(v);
    if(v && !*p)
    {
	::Ice::NoObjectFactoryException e(__FILE__, __LINE__);
	e.type = ::NVSStreamService::NVSStreamServiceAPI::ice_staticId();
	throw e;
    }
}

bool
NVSStreamService::operator==(const ::NVSStreamService::NVSStreamServiceAPI& l, const ::NVSStreamService::NVSStreamServiceAPI& r)
{
    return static_cast<const ::Ice::Object&>(l) == static_cast<const ::Ice::Object&>(r);
}

bool
NVSStreamService::operator!=(const ::NVSStreamService::NVSStreamServiceAPI& l, const ::NVSStreamService::NVSStreamServiceAPI& r)
{
    return static_cast<const ::Ice::Object&>(l) != static_cast<const ::Ice::Object&>(r);
}

bool
NVSStreamService::operator<(const ::NVSStreamService::NVSStreamServiceAPI& l, const ::NVSStreamService::NVSStreamServiceAPI& r)
{
    return static_cast<const ::Ice::Object&>(l) < static_cast<const ::Ice::Object&>(r);
}

bool
NVSStreamService::operator<=(const ::NVSStreamService::NVSStreamServiceAPI& l, const ::NVSStreamService::NVSStreamServiceAPI& r)
{
    return l < r || l == r;
}

bool
NVSStreamService::operator>(const ::NVSStreamService::NVSStreamServiceAPI& l, const ::NVSStreamService::NVSStreamServiceAPI& r)
{
    return !(l < r) && !(l == r);
}

bool
NVSStreamService::operator>=(const ::NVSStreamService::NVSStreamServiceAPI& l, const ::NVSStreamService::NVSStreamServiceAPI& r)
{
    return !(l < r);
}
