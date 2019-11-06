// **********************************************************************
//
// Copyright (c) 2003-2006 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************

// Ice version 3.1.1
// Generated from file `NVSIndex4Stream.ice'
#include "stdafx.h"
#include "NVSIndex4Stream.h"
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

static const ::std::string __NVSIndex__NVSIndex4Stream__registerMe_name = "registerMe";

static const ::std::string __NVSIndex__NVSIndex4Stream__heartBeat_name = "heartBeat";

static const ::std::string __NVSIndex__NVSIndex4Stream__getDvrInfo_name = "getDvrInfo";

static const ::std::string __NVSIndex__NVSIndex4Stream__getSouceStreamService_name = "getSouceStreamService";

static const ::std::string __NVSIndex__NVSIndex4Stream__transferLoad_name = "transferLoad";

static const ::std::string __NVSIndex__NVSIndex4Stream__getDvrPools_name = "getDvrPools";

static const ::std::string __NVSIndex__NVSIndex4Stream__getDvrInfoEx_name = "getDvrInfoEx";

static const ::std::string __NVSIndex__NVSIndex4StreamSend__notifyControlReload_name = "notifyControlReload";

static const ::std::string __NVSIndex__NVSIndex4StreamSend__notifyServiceConnect_name = "notifyServiceConnect";

void
IceInternal::incRef(::NVSIndex::NVSIndex4Stream* p)
{
    p->__incRef();
}

void
IceInternal::decRef(::NVSIndex::NVSIndex4Stream* p)
{
    p->__decRef();
}

void
IceInternal::incRef(::IceProxy::NVSIndex::NVSIndex4Stream* p)
{
    p->__incRef();
}

void
IceInternal::decRef(::IceProxy::NVSIndex::NVSIndex4Stream* p)
{
    p->__decRef();
}

void
IceInternal::incRef(::NVSIndex::NVSIndex4StreamSend* p)
{
    p->__incRef();
}

void
IceInternal::decRef(::NVSIndex::NVSIndex4StreamSend* p)
{
    p->__decRef();
}

void
IceInternal::incRef(::IceProxy::NVSIndex::NVSIndex4StreamSend* p)
{
    p->__incRef();
}

void
IceInternal::decRef(::IceProxy::NVSIndex::NVSIndex4StreamSend* p)
{
    p->__decRef();
}

void
NVSIndex::__write(::IceInternal::BasicStream* __os, const ::NVSIndex::NVSIndex4StreamPrx& v)
{
    __os->write(::Ice::ObjectPrx(v));
}

void
NVSIndex::__read(::IceInternal::BasicStream* __is, ::NVSIndex::NVSIndex4StreamPrx& v)
{
    ::Ice::ObjectPrx proxy;
    __is->read(proxy);
    if(!proxy)
    {
	v = 0;
    }
    else
    {
	v = new ::IceProxy::NVSIndex::NVSIndex4Stream;
	v->__copyFrom(proxy);
    }
}

void
NVSIndex::__write(::IceInternal::BasicStream* __os, const ::NVSIndex::NVSIndex4StreamPtr& v)
{
    __os->write(::Ice::ObjectPtr(v));
}

void
NVSIndex::__write(::IceInternal::BasicStream* __os, const ::NVSIndex::NVSIndex4StreamSendPrx& v)
{
    __os->write(::Ice::ObjectPrx(v));
}

void
NVSIndex::__read(::IceInternal::BasicStream* __is, ::NVSIndex::NVSIndex4StreamSendPrx& v)
{
    ::Ice::ObjectPrx proxy;
    __is->read(proxy);
    if(!proxy)
    {
	v = 0;
    }
    else
    {
	v = new ::IceProxy::NVSIndex::NVSIndex4StreamSend;
	v->__copyFrom(proxy);
    }
}

void
NVSIndex::__write(::IceInternal::BasicStream* __os, const ::NVSIndex::NVSIndex4StreamSendPtr& v)
{
    __os->write(::Ice::ObjectPtr(v));
}

bool
IceProxy::NVSIndex::NVSIndex4Stream::registerMe(const ::NVSIndex::NVSStreamServiceInfo& frontInfo, const ::Ice::Identity& ident, ::NVSIndex::NVSStreamServiceInfo& backInfo, const ::Ice::Context& __ctx)
{
    int __cnt = 0;
    while(true)
    {
	try
	{
	    __checkTwowayOnly(__NVSIndex__NVSIndex4Stream__registerMe_name);
	    ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase = __getDelegate();
	    ::IceDelegate::NVSIndex::NVSIndex4Stream* __del = dynamic_cast< ::IceDelegate::NVSIndex::NVSIndex4Stream*>(__delBase.get());
	    return __del->registerMe(frontInfo, ident, backInfo, __ctx);
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
IceProxy::NVSIndex::NVSIndex4Stream::heartBeat(::Ice::Int nID, const ::Ice::Context& __ctx)
{
    int __cnt = 0;
    while(true)
    {
	try
	{
	    ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase = __getDelegate();
	    ::IceDelegate::NVSIndex::NVSIndex4Stream* __del = dynamic_cast< ::IceDelegate::NVSIndex::NVSIndex4Stream*>(__delBase.get());
	    __del->heartBeat(nID, __ctx);
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

bool
IceProxy::NVSIndex::NVSIndex4Stream::getDvrInfo(::Ice::Int nCameraID, ::NVSIndex::NVSDVRInfo& backInfo, const ::Ice::Context& __ctx)
{
    int __cnt = 0;
    while(true)
    {
	try
	{
	    __checkTwowayOnly(__NVSIndex__NVSIndex4Stream__getDvrInfo_name);
	    ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase = __getDelegate();
	    ::IceDelegate::NVSIndex::NVSIndex4Stream* __del = dynamic_cast< ::IceDelegate::NVSIndex::NVSIndex4Stream*>(__delBase.get());
	    return __del->getDvrInfo(nCameraID, backInfo, __ctx);
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

::Ice::Byte
IceProxy::NVSIndex::NVSIndex4Stream::getSouceStreamService(::Ice::Int cameraID, ::std::string& sSSProxy, ::Ice::Int& serviceKey, const ::Ice::Context& __ctx)
{
    int __cnt = 0;
    while(true)
    {
	try
	{
	    __checkTwowayOnly(__NVSIndex__NVSIndex4Stream__getSouceStreamService_name);
	    ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase = __getDelegate();
	    ::IceDelegate::NVSIndex::NVSIndex4Stream* __del = dynamic_cast< ::IceDelegate::NVSIndex::NVSIndex4Stream*>(__delBase.get());
	    return __del->getSouceStreamService(cameraID, sSSProxy, serviceKey, __ctx);
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
IceProxy::NVSIndex::NVSIndex4Stream::transferLoad(const ::std::string& sServerKey, const ::NVSIndex::NVSCameraPool& vCameraPool, ::Ice::Int nMonitorLoad, const ::Ice::Context& __ctx)
{
    int __cnt = 0;
    while(true)
    {
	try
	{
	    ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase = __getDelegate();
	    ::IceDelegate::NVSIndex::NVSIndex4Stream* __del = dynamic_cast< ::IceDelegate::NVSIndex::NVSIndex4Stream*>(__delBase.get());
	    __del->transferLoad(sServerKey, vCameraPool, nMonitorLoad, __ctx);
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

void
IceProxy::NVSIndex::NVSIndex4Stream::getDvrPools(const ::std::string& sKey, ::NVSIndex::NVSDVRPool& backInfo, const ::Ice::Context& __ctx)
{
    int __cnt = 0;
    while(true)
    {
	try
	{
	    __checkTwowayOnly(__NVSIndex__NVSIndex4Stream__getDvrPools_name);
	    ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase = __getDelegate();
	    ::IceDelegate::NVSIndex::NVSIndex4Stream* __del = dynamic_cast< ::IceDelegate::NVSIndex::NVSIndex4Stream*>(__delBase.get());
	    __del->getDvrPools(sKey, backInfo, __ctx);
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

bool
IceProxy::NVSIndex::NVSIndex4Stream::getDvrInfoEx(::Ice::Int nCameraID, ::NVSIndex::NVSDVRInfoEx& backInfo, const ::Ice::Context& __ctx)
{
    int __cnt = 0;
    while(true)
    {
	try
	{
	    __checkTwowayOnly(__NVSIndex__NVSIndex4Stream__getDvrInfoEx_name);
	    ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase = __getDelegate();
	    ::IceDelegate::NVSIndex::NVSIndex4Stream* __del = dynamic_cast< ::IceDelegate::NVSIndex::NVSIndex4Stream*>(__delBase.get());
	    return __del->getDvrInfoEx(nCameraID, backInfo, __ctx);
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
IceProxy::NVSIndex::NVSIndex4Stream::ice_staticId()
{
    return ::NVSIndex::NVSIndex4Stream::ice_staticId();
}

::IceInternal::Handle< ::IceDelegateM::Ice::Object>
IceProxy::NVSIndex::NVSIndex4Stream::__createDelegateM()
{
    return ::IceInternal::Handle< ::IceDelegateM::Ice::Object>(new ::IceDelegateM::NVSIndex::NVSIndex4Stream);
}

::IceInternal::Handle< ::IceDelegateD::Ice::Object>
IceProxy::NVSIndex::NVSIndex4Stream::__createDelegateD()
{
    return ::IceInternal::Handle< ::IceDelegateD::Ice::Object>(new ::IceDelegateD::NVSIndex::NVSIndex4Stream);
}

bool
IceProxy::NVSIndex::operator==(const ::IceProxy::NVSIndex::NVSIndex4Stream& l, const ::IceProxy::NVSIndex::NVSIndex4Stream& r)
{
    return static_cast<const ::IceProxy::Ice::Object&>(l) == static_cast<const ::IceProxy::Ice::Object&>(r);
}

bool
IceProxy::NVSIndex::operator!=(const ::IceProxy::NVSIndex::NVSIndex4Stream& l, const ::IceProxy::NVSIndex::NVSIndex4Stream& r)
{
    return static_cast<const ::IceProxy::Ice::Object&>(l) != static_cast<const ::IceProxy::Ice::Object&>(r);
}

bool
IceProxy::NVSIndex::operator<(const ::IceProxy::NVSIndex::NVSIndex4Stream& l, const ::IceProxy::NVSIndex::NVSIndex4Stream& r)
{
    return static_cast<const ::IceProxy::Ice::Object&>(l) < static_cast<const ::IceProxy::Ice::Object&>(r);
}

bool
IceProxy::NVSIndex::operator<=(const ::IceProxy::NVSIndex::NVSIndex4Stream& l, const ::IceProxy::NVSIndex::NVSIndex4Stream& r)
{
    return l < r || l == r;
}

bool
IceProxy::NVSIndex::operator>(const ::IceProxy::NVSIndex::NVSIndex4Stream& l, const ::IceProxy::NVSIndex::NVSIndex4Stream& r)
{
    return !(l < r) && !(l == r);
}

bool
IceProxy::NVSIndex::operator>=(const ::IceProxy::NVSIndex::NVSIndex4Stream& l, const ::IceProxy::NVSIndex::NVSIndex4Stream& r)
{
    return !(l < r);
}

void
IceProxy::NVSIndex::NVSIndex4StreamSend::notifyControlReload(const ::Ice::Context& __ctx)
{
    int __cnt = 0;
    while(true)
    {
	try
	{
	    ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase = __getDelegate();
	    ::IceDelegate::NVSIndex::NVSIndex4StreamSend* __del = dynamic_cast< ::IceDelegate::NVSIndex::NVSIndex4StreamSend*>(__delBase.get());
	    __del->notifyControlReload(__ctx);
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

void
IceProxy::NVSIndex::NVSIndex4StreamSend::notifyServiceConnect(const ::Ice::Context& __ctx)
{
    int __cnt = 0;
    while(true)
    {
	try
	{
	    ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase = __getDelegate();
	    ::IceDelegate::NVSIndex::NVSIndex4StreamSend* __del = dynamic_cast< ::IceDelegate::NVSIndex::NVSIndex4StreamSend*>(__delBase.get());
	    __del->notifyServiceConnect(__ctx);
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
IceProxy::NVSIndex::NVSIndex4StreamSend::ice_staticId()
{
    return ::NVSIndex::NVSIndex4StreamSend::ice_staticId();
}

::IceInternal::Handle< ::IceDelegateM::Ice::Object>
IceProxy::NVSIndex::NVSIndex4StreamSend::__createDelegateM()
{
    return ::IceInternal::Handle< ::IceDelegateM::Ice::Object>(new ::IceDelegateM::NVSIndex::NVSIndex4StreamSend);
}

::IceInternal::Handle< ::IceDelegateD::Ice::Object>
IceProxy::NVSIndex::NVSIndex4StreamSend::__createDelegateD()
{
    return ::IceInternal::Handle< ::IceDelegateD::Ice::Object>(new ::IceDelegateD::NVSIndex::NVSIndex4StreamSend);
}

bool
IceProxy::NVSIndex::operator==(const ::IceProxy::NVSIndex::NVSIndex4StreamSend& l, const ::IceProxy::NVSIndex::NVSIndex4StreamSend& r)
{
    return static_cast<const ::IceProxy::Ice::Object&>(l) == static_cast<const ::IceProxy::Ice::Object&>(r);
}

bool
IceProxy::NVSIndex::operator!=(const ::IceProxy::NVSIndex::NVSIndex4StreamSend& l, const ::IceProxy::NVSIndex::NVSIndex4StreamSend& r)
{
    return static_cast<const ::IceProxy::Ice::Object&>(l) != static_cast<const ::IceProxy::Ice::Object&>(r);
}

bool
IceProxy::NVSIndex::operator<(const ::IceProxy::NVSIndex::NVSIndex4StreamSend& l, const ::IceProxy::NVSIndex::NVSIndex4StreamSend& r)
{
    return static_cast<const ::IceProxy::Ice::Object&>(l) < static_cast<const ::IceProxy::Ice::Object&>(r);
}

bool
IceProxy::NVSIndex::operator<=(const ::IceProxy::NVSIndex::NVSIndex4StreamSend& l, const ::IceProxy::NVSIndex::NVSIndex4StreamSend& r)
{
    return l < r || l == r;
}

bool
IceProxy::NVSIndex::operator>(const ::IceProxy::NVSIndex::NVSIndex4StreamSend& l, const ::IceProxy::NVSIndex::NVSIndex4StreamSend& r)
{
    return !(l < r) && !(l == r);
}

bool
IceProxy::NVSIndex::operator>=(const ::IceProxy::NVSIndex::NVSIndex4StreamSend& l, const ::IceProxy::NVSIndex::NVSIndex4StreamSend& r)
{
    return !(l < r);
}

bool
IceDelegateM::NVSIndex::NVSIndex4Stream::registerMe(const ::NVSIndex::NVSStreamServiceInfo& frontInfo, const ::Ice::Identity& ident, ::NVSIndex::NVSStreamServiceInfo& backInfo, const ::Ice::Context& __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __NVSIndex__NVSIndex4Stream__registerMe_name, ::Ice::Normal, __context, __compress);
    try
    {
	::IceInternal::BasicStream* __os = __og.os();
	frontInfo.__write(__os);
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
	bool __ret;
	backInfo.__read(__is);
	__is->read(__ret);
	return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
	throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::NVSIndex::NVSIndex4Stream::heartBeat(::Ice::Int nID, const ::Ice::Context& __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __NVSIndex__NVSIndex4Stream__heartBeat_name, ::Ice::Normal, __context, __compress);
    try
    {
	::IceInternal::BasicStream* __os = __og.os();
	__os->write(nID);
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

bool
IceDelegateM::NVSIndex::NVSIndex4Stream::getDvrInfo(::Ice::Int nCameraID, ::NVSIndex::NVSDVRInfo& backInfo, const ::Ice::Context& __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __NVSIndex__NVSIndex4Stream__getDvrInfo_name, ::Ice::Normal, __context, __compress);
    try
    {
	::IceInternal::BasicStream* __os = __og.os();
	__os->write(nCameraID);
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
	backInfo.__read(__is);
	__is->read(__ret);
	return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
	throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::Ice::Byte
IceDelegateM::NVSIndex::NVSIndex4Stream::getSouceStreamService(::Ice::Int cameraID, ::std::string& sSSProxy, ::Ice::Int& serviceKey, const ::Ice::Context& __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __NVSIndex__NVSIndex4Stream__getSouceStreamService_name, ::Ice::Normal, __context, __compress);
    try
    {
	::IceInternal::BasicStream* __os = __og.os();
	__os->write(cameraID);
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
	::Ice::Byte __ret;
	__is->read(sSSProxy);
	__is->read(serviceKey);
	__is->read(__ret);
	return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
	throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::NVSIndex::NVSIndex4Stream::transferLoad(const ::std::string& sServerKey, const ::NVSIndex::NVSCameraPool& vCameraPool, ::Ice::Int nMonitorLoad, const ::Ice::Context& __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __NVSIndex__NVSIndex4Stream__transferLoad_name, ::Ice::Normal, __context, __compress);
    try
    {
	::IceInternal::BasicStream* __os = __og.os();
	__os->write(sServerKey);
	if(vCameraPool.size() == 0)
	{
	    __os->writeSize(0);
	}
	else
	{
	    ::NVSIndex::__write(__os, &vCameraPool[0], &vCameraPool[0] + vCameraPool.size(), ::NVSIndex::__U__NVSCameraPool());
	}
	__os->write(nMonitorLoad);
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

void
IceDelegateM::NVSIndex::NVSIndex4Stream::getDvrPools(const ::std::string& sKey, ::NVSIndex::NVSDVRPool& backInfo, const ::Ice::Context& __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __NVSIndex__NVSIndex4Stream__getDvrPools_name, ::Ice::Normal, __context, __compress);
    try
    {
	::IceInternal::BasicStream* __os = __og.os();
	__os->write(sKey);
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
	::NVSIndex::__read(__is, backInfo, ::NVSIndex::__U__NVSDVRPool());
    }
    catch(const ::Ice::LocalException& __ex)
    {
	throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

bool
IceDelegateM::NVSIndex::NVSIndex4Stream::getDvrInfoEx(::Ice::Int nCameraID, ::NVSIndex::NVSDVRInfoEx& backInfo, const ::Ice::Context& __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __NVSIndex__NVSIndex4Stream__getDvrInfoEx_name, ::Ice::Normal, __context, __compress);
    try
    {
	::IceInternal::BasicStream* __os = __og.os();
	__os->write(nCameraID);
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
	backInfo.__read(__is);
	__is->read(__ret);
	return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
	throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::NVSIndex::NVSIndex4StreamSend::notifyControlReload(const ::Ice::Context& __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __NVSIndex__NVSIndex4StreamSend__notifyControlReload_name, ::Ice::Normal, __context, __compress);
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

void
IceDelegateM::NVSIndex::NVSIndex4StreamSend::notifyServiceConnect(const ::Ice::Context& __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __NVSIndex__NVSIndex4StreamSend__notifyServiceConnect_name, ::Ice::Normal, __context, __compress);
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
IceDelegateD::NVSIndex::NVSIndex4Stream::registerMe(const ::NVSIndex::NVSStreamServiceInfo& frontInfo, const ::Ice::Identity& ident, ::NVSIndex::NVSStreamServiceInfo& backInfo, const ::Ice::Context& __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __NVSIndex__NVSIndex4Stream__registerMe_name, ::Ice::Normal, __context);
    while(true)
    {
	::IceInternal::Direct __direct(__current);
	::NVSIndex::NVSIndex4Stream* __servant = dynamic_cast< ::NVSIndex::NVSIndex4Stream*>(__direct.servant().get());
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
	    return __servant->registerMe(frontInfo, ident, backInfo, __current);
	}
	catch(const ::Ice::LocalException& __ex)
	{
	    throw ::IceInternal::LocalExceptionWrapper(__ex, false);
	}
    }
}

void
IceDelegateD::NVSIndex::NVSIndex4Stream::heartBeat(::Ice::Int nID, const ::Ice::Context& __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __NVSIndex__NVSIndex4Stream__heartBeat_name, ::Ice::Normal, __context);
    while(true)
    {
	::IceInternal::Direct __direct(__current);
	::NVSIndex::NVSIndex4Stream* __servant = dynamic_cast< ::NVSIndex::NVSIndex4Stream*>(__direct.servant().get());
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
	    __servant->heartBeat(nID, __current);
	    return;
	}
	catch(const ::Ice::LocalException& __ex)
	{
	    throw ::IceInternal::LocalExceptionWrapper(__ex, false);
	}
    }
}

bool
IceDelegateD::NVSIndex::NVSIndex4Stream::getDvrInfo(::Ice::Int nCameraID, ::NVSIndex::NVSDVRInfo& backInfo, const ::Ice::Context& __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __NVSIndex__NVSIndex4Stream__getDvrInfo_name, ::Ice::Normal, __context);
    while(true)
    {
	::IceInternal::Direct __direct(__current);
	::NVSIndex::NVSIndex4Stream* __servant = dynamic_cast< ::NVSIndex::NVSIndex4Stream*>(__direct.servant().get());
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
	    return __servant->getDvrInfo(nCameraID, backInfo, __current);
	}
	catch(const ::Ice::LocalException& __ex)
	{
	    throw ::IceInternal::LocalExceptionWrapper(__ex, false);
	}
    }
}

::Ice::Byte
IceDelegateD::NVSIndex::NVSIndex4Stream::getSouceStreamService(::Ice::Int cameraID, ::std::string& sSSProxy, ::Ice::Int& serviceKey, const ::Ice::Context& __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __NVSIndex__NVSIndex4Stream__getSouceStreamService_name, ::Ice::Normal, __context);
    while(true)
    {
	::IceInternal::Direct __direct(__current);
	::NVSIndex::NVSIndex4Stream* __servant = dynamic_cast< ::NVSIndex::NVSIndex4Stream*>(__direct.servant().get());
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
	    return __servant->getSouceStreamService(cameraID, sSSProxy, serviceKey, __current);
	}
	catch(const ::Ice::LocalException& __ex)
	{
	    throw ::IceInternal::LocalExceptionWrapper(__ex, false);
	}
    }
}

void
IceDelegateD::NVSIndex::NVSIndex4Stream::transferLoad(const ::std::string& sServerKey, const ::NVSIndex::NVSCameraPool& vCameraPool, ::Ice::Int nMonitorLoad, const ::Ice::Context& __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __NVSIndex__NVSIndex4Stream__transferLoad_name, ::Ice::Normal, __context);
    while(true)
    {
	::IceInternal::Direct __direct(__current);
	::NVSIndex::NVSIndex4Stream* __servant = dynamic_cast< ::NVSIndex::NVSIndex4Stream*>(__direct.servant().get());
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
	    __servant->transferLoad(sServerKey, vCameraPool, nMonitorLoad, __current);
	    return;
	}
	catch(const ::Ice::LocalException& __ex)
	{
	    throw ::IceInternal::LocalExceptionWrapper(__ex, false);
	}
    }
}

void
IceDelegateD::NVSIndex::NVSIndex4Stream::getDvrPools(const ::std::string& sKey, ::NVSIndex::NVSDVRPool& backInfo, const ::Ice::Context& __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __NVSIndex__NVSIndex4Stream__getDvrPools_name, ::Ice::Normal, __context);
    while(true)
    {
	::IceInternal::Direct __direct(__current);
	::NVSIndex::NVSIndex4Stream* __servant = dynamic_cast< ::NVSIndex::NVSIndex4Stream*>(__direct.servant().get());
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
	    __servant->getDvrPools(sKey, backInfo, __current);
	    return;
	}
	catch(const ::Ice::LocalException& __ex)
	{
	    throw ::IceInternal::LocalExceptionWrapper(__ex, false);
	}
    }
}

bool
IceDelegateD::NVSIndex::NVSIndex4Stream::getDvrInfoEx(::Ice::Int nCameraID, ::NVSIndex::NVSDVRInfoEx& backInfo, const ::Ice::Context& __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __NVSIndex__NVSIndex4Stream__getDvrInfoEx_name, ::Ice::Normal, __context);
    while(true)
    {
	::IceInternal::Direct __direct(__current);
	::NVSIndex::NVSIndex4Stream* __servant = dynamic_cast< ::NVSIndex::NVSIndex4Stream*>(__direct.servant().get());
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
	    return __servant->getDvrInfoEx(nCameraID, backInfo, __current);
	}
	catch(const ::Ice::LocalException& __ex)
	{
	    throw ::IceInternal::LocalExceptionWrapper(__ex, false);
	}
    }
}

void
IceDelegateD::NVSIndex::NVSIndex4StreamSend::notifyControlReload(const ::Ice::Context& __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __NVSIndex__NVSIndex4StreamSend__notifyControlReload_name, ::Ice::Normal, __context);
    while(true)
    {
	::IceInternal::Direct __direct(__current);
	::NVSIndex::NVSIndex4StreamSend* __servant = dynamic_cast< ::NVSIndex::NVSIndex4StreamSend*>(__direct.servant().get());
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
	    __servant->notifyControlReload(__current);
	    return;
	}
	catch(const ::Ice::LocalException& __ex)
	{
	    throw ::IceInternal::LocalExceptionWrapper(__ex, false);
	}
    }
}

void
IceDelegateD::NVSIndex::NVSIndex4StreamSend::notifyServiceConnect(const ::Ice::Context& __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __NVSIndex__NVSIndex4StreamSend__notifyServiceConnect_name, ::Ice::Normal, __context);
    while(true)
    {
	::IceInternal::Direct __direct(__current);
	::NVSIndex::NVSIndex4StreamSend* __servant = dynamic_cast< ::NVSIndex::NVSIndex4StreamSend*>(__direct.servant().get());
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
	    __servant->notifyServiceConnect(__current);
	    return;
	}
	catch(const ::Ice::LocalException& __ex)
	{
	    throw ::IceInternal::LocalExceptionWrapper(__ex, false);
	}
    }
}

::Ice::ObjectPtr
NVSIndex::NVSIndex4Stream::ice_clone() const
{
    throw ::Ice::CloneNotImplementedException(__FILE__, __LINE__);
    return 0; // to avoid a warning with some compilers
}

static const ::std::string __NVSIndex__NVSIndex4Stream_ids[2] =
{
    "::Ice::Object",
    "::NVSIndex::NVSIndex4Stream"
};

bool
NVSIndex::NVSIndex4Stream::ice_isA(const ::std::string& _s, const ::Ice::Current&) const
{
    return ::std::binary_search(__NVSIndex__NVSIndex4Stream_ids, __NVSIndex__NVSIndex4Stream_ids + 2, _s);
}

::std::vector< ::std::string>
NVSIndex::NVSIndex4Stream::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&__NVSIndex__NVSIndex4Stream_ids[0], &__NVSIndex__NVSIndex4Stream_ids[2]);
}

const ::std::string&
NVSIndex::NVSIndex4Stream::ice_id(const ::Ice::Current&) const
{
    return __NVSIndex__NVSIndex4Stream_ids[1];
}

const ::std::string&
NVSIndex::NVSIndex4Stream::ice_staticId()
{
    return __NVSIndex__NVSIndex4Stream_ids[1];
}

::IceInternal::DispatchStatus
NVSIndex::NVSIndex4Stream::___registerMe(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::NVSIndex::NVSStreamServiceInfo frontInfo;
    ::Ice::Identity ident;
    frontInfo.__read(__is);
    ident.__read(__is);
    ::NVSIndex::NVSStreamServiceInfo backInfo;
    bool __ret = registerMe(frontInfo, ident, backInfo, __current);
    backInfo.__write(__os);
    __os->write(__ret);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
NVSIndex::NVSIndex4Stream::___heartBeat(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::Ice::Int nID;
    __is->read(nID);
    heartBeat(nID, __current);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
NVSIndex::NVSIndex4Stream::___getDvrInfo(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::Int nCameraID;
    __is->read(nCameraID);
    ::NVSIndex::NVSDVRInfo backInfo;
    bool __ret = getDvrInfo(nCameraID, backInfo, __current);
    backInfo.__write(__os);
    __os->write(__ret);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
NVSIndex::NVSIndex4Stream::___getSouceStreamService(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::Int cameraID;
    __is->read(cameraID);
    ::std::string sSSProxy;
    ::Ice::Int serviceKey;
    ::Ice::Byte __ret = getSouceStreamService(cameraID, sSSProxy, serviceKey, __current);
    __os->write(sSSProxy);
    __os->write(serviceKey);
    __os->write(__ret);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
NVSIndex::NVSIndex4Stream::___transferLoad(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::std::string sServerKey;
    ::NVSIndex::NVSCameraPool vCameraPool;
    ::Ice::Int nMonitorLoad;
    __is->read(sServerKey);
    ::NVSIndex::__read(__is, vCameraPool, ::NVSIndex::__U__NVSCameraPool());
    __is->read(nMonitorLoad);
    transferLoad(sServerKey, vCameraPool, nMonitorLoad, __current);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
NVSIndex::NVSIndex4Stream::___getDvrPools(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string sKey;
    __is->read(sKey);
    ::NVSIndex::NVSDVRPool backInfo;
    getDvrPools(sKey, backInfo, __current);
    if(backInfo.size() == 0)
    {
	__os->writeSize(0);
    }
    else
    {
	::NVSIndex::__write(__os, &backInfo[0], &backInfo[0] + backInfo.size(), ::NVSIndex::__U__NVSDVRPool());
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
NVSIndex::NVSIndex4Stream::___getDvrInfoEx(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::Int nCameraID;
    __is->read(nCameraID);
    ::NVSIndex::NVSDVRInfoEx backInfo;
    bool __ret = getDvrInfoEx(nCameraID, backInfo, __current);
    backInfo.__write(__os);
    __os->write(__ret);
    return ::IceInternal::DispatchOK;
}

static ::std::string __NVSIndex__NVSIndex4Stream_all[] =
{
    "getDvrInfo",
    "getDvrInfoEx",
    "getDvrPools",
    "getSouceStreamService",
    "heartBeat",
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping",
    "registerMe",
    "transferLoad"
};

::IceInternal::DispatchStatus
NVSIndex::NVSIndex4Stream::__dispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair< ::std::string*, ::std::string*> r = ::std::equal_range(__NVSIndex__NVSIndex4Stream_all, __NVSIndex__NVSIndex4Stream_all + 11, current.operation);
    if(r.first == r.second)
    {
	return ::IceInternal::DispatchOperationNotExist;
    }

    switch(r.first - __NVSIndex__NVSIndex4Stream_all)
    {
	case 0:
	{
	    return ___getDvrInfo(in, current);
	}
	case 1:
	{
	    return ___getDvrInfoEx(in, current);
	}
	case 2:
	{
	    return ___getDvrPools(in, current);
	}
	case 3:
	{
	    return ___getSouceStreamService(in, current);
	}
	case 4:
	{
	    return ___heartBeat(in, current);
	}
	case 5:
	{
	    return ___ice_id(in, current);
	}
	case 6:
	{
	    return ___ice_ids(in, current);
	}
	case 7:
	{
	    return ___ice_isA(in, current);
	}
	case 8:
	{
	    return ___ice_ping(in, current);
	}
	case 9:
	{
	    return ___registerMe(in, current);
	}
	case 10:
	{
	    return ___transferLoad(in, current);
	}
    }

    assert(false);
    return ::IceInternal::DispatchOperationNotExist;
}

void
NVSIndex::NVSIndex4Stream::__write(::IceInternal::BasicStream* __os) const
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
NVSIndex::NVSIndex4Stream::__read(::IceInternal::BasicStream* __is, bool __rid)
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
NVSIndex::NVSIndex4Stream::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type NVSIndex::NVSIndex4Stream was not generated with stream support";
    throw ex;
}

void
NVSIndex::NVSIndex4Stream::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type NVSIndex::NVSIndex4Stream was not generated with stream support";
    throw ex;
}

void 
NVSIndex::__patch__NVSIndex4StreamPtr(void* __addr, ::Ice::ObjectPtr& v)
{
    ::NVSIndex::NVSIndex4StreamPtr* p = static_cast< ::NVSIndex::NVSIndex4StreamPtr*>(__addr);
    assert(p);
    *p = ::NVSIndex::NVSIndex4StreamPtr::dynamicCast(v);
    if(v && !*p)
    {
	::Ice::NoObjectFactoryException e(__FILE__, __LINE__);
	e.type = ::NVSIndex::NVSIndex4Stream::ice_staticId();
	throw e;
    }
}

bool
NVSIndex::operator==(const ::NVSIndex::NVSIndex4Stream& l, const ::NVSIndex::NVSIndex4Stream& r)
{
    return static_cast<const ::Ice::Object&>(l) == static_cast<const ::Ice::Object&>(r);
}

bool
NVSIndex::operator!=(const ::NVSIndex::NVSIndex4Stream& l, const ::NVSIndex::NVSIndex4Stream& r)
{
    return static_cast<const ::Ice::Object&>(l) != static_cast<const ::Ice::Object&>(r);
}

bool
NVSIndex::operator<(const ::NVSIndex::NVSIndex4Stream& l, const ::NVSIndex::NVSIndex4Stream& r)
{
    return static_cast<const ::Ice::Object&>(l) < static_cast<const ::Ice::Object&>(r);
}

bool
NVSIndex::operator<=(const ::NVSIndex::NVSIndex4Stream& l, const ::NVSIndex::NVSIndex4Stream& r)
{
    return l < r || l == r;
}

bool
NVSIndex::operator>(const ::NVSIndex::NVSIndex4Stream& l, const ::NVSIndex::NVSIndex4Stream& r)
{
    return !(l < r) && !(l == r);
}

bool
NVSIndex::operator>=(const ::NVSIndex::NVSIndex4Stream& l, const ::NVSIndex::NVSIndex4Stream& r)
{
    return !(l < r);
}

::Ice::ObjectPtr
NVSIndex::NVSIndex4StreamSend::ice_clone() const
{
    throw ::Ice::CloneNotImplementedException(__FILE__, __LINE__);
    return 0; // to avoid a warning with some compilers
}

static const ::std::string __NVSIndex__NVSIndex4StreamSend_ids[2] =
{
    "::Ice::Object",
    "::NVSIndex::NVSIndex4StreamSend"
};

bool
NVSIndex::NVSIndex4StreamSend::ice_isA(const ::std::string& _s, const ::Ice::Current&) const
{
    return ::std::binary_search(__NVSIndex__NVSIndex4StreamSend_ids, __NVSIndex__NVSIndex4StreamSend_ids + 2, _s);
}

::std::vector< ::std::string>
NVSIndex::NVSIndex4StreamSend::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&__NVSIndex__NVSIndex4StreamSend_ids[0], &__NVSIndex__NVSIndex4StreamSend_ids[2]);
}

const ::std::string&
NVSIndex::NVSIndex4StreamSend::ice_id(const ::Ice::Current&) const
{
    return __NVSIndex__NVSIndex4StreamSend_ids[1];
}

const ::std::string&
NVSIndex::NVSIndex4StreamSend::ice_staticId()
{
    return __NVSIndex__NVSIndex4StreamSend_ids[1];
}

::IceInternal::DispatchStatus
NVSIndex::NVSIndex4StreamSend::___notifyControlReload(::IceInternal::Incoming&, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    notifyControlReload(__current);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
NVSIndex::NVSIndex4StreamSend::___notifyServiceConnect(::IceInternal::Incoming&, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    notifyServiceConnect(__current);
    return ::IceInternal::DispatchOK;
}

static ::std::string __NVSIndex__NVSIndex4StreamSend_all[] =
{
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping",
    "notifyControlReload",
    "notifyServiceConnect"
};

::IceInternal::DispatchStatus
NVSIndex::NVSIndex4StreamSend::__dispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair< ::std::string*, ::std::string*> r = ::std::equal_range(__NVSIndex__NVSIndex4StreamSend_all, __NVSIndex__NVSIndex4StreamSend_all + 6, current.operation);
    if(r.first == r.second)
    {
	return ::IceInternal::DispatchOperationNotExist;
    }

    switch(r.first - __NVSIndex__NVSIndex4StreamSend_all)
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
	    return ___notifyControlReload(in, current);
	}
	case 5:
	{
	    return ___notifyServiceConnect(in, current);
	}
    }

    assert(false);
    return ::IceInternal::DispatchOperationNotExist;
}

void
NVSIndex::NVSIndex4StreamSend::__write(::IceInternal::BasicStream* __os) const
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
NVSIndex::NVSIndex4StreamSend::__read(::IceInternal::BasicStream* __is, bool __rid)
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
NVSIndex::NVSIndex4StreamSend::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type NVSIndex::NVSIndex4StreamSend was not generated with stream support";
    throw ex;
}

void
NVSIndex::NVSIndex4StreamSend::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type NVSIndex::NVSIndex4StreamSend was not generated with stream support";
    throw ex;
}

void 
NVSIndex::__patch__NVSIndex4StreamSendPtr(void* __addr, ::Ice::ObjectPtr& v)
{
    ::NVSIndex::NVSIndex4StreamSendPtr* p = static_cast< ::NVSIndex::NVSIndex4StreamSendPtr*>(__addr);
    assert(p);
    *p = ::NVSIndex::NVSIndex4StreamSendPtr::dynamicCast(v);
    if(v && !*p)
    {
	::Ice::NoObjectFactoryException e(__FILE__, __LINE__);
	e.type = ::NVSIndex::NVSIndex4StreamSend::ice_staticId();
	throw e;
    }
}

bool
NVSIndex::operator==(const ::NVSIndex::NVSIndex4StreamSend& l, const ::NVSIndex::NVSIndex4StreamSend& r)
{
    return static_cast<const ::Ice::Object&>(l) == static_cast<const ::Ice::Object&>(r);
}

bool
NVSIndex::operator!=(const ::NVSIndex::NVSIndex4StreamSend& l, const ::NVSIndex::NVSIndex4StreamSend& r)
{
    return static_cast<const ::Ice::Object&>(l) != static_cast<const ::Ice::Object&>(r);
}

bool
NVSIndex::operator<(const ::NVSIndex::NVSIndex4StreamSend& l, const ::NVSIndex::NVSIndex4StreamSend& r)
{
    return static_cast<const ::Ice::Object&>(l) < static_cast<const ::Ice::Object&>(r);
}

bool
NVSIndex::operator<=(const ::NVSIndex::NVSIndex4StreamSend& l, const ::NVSIndex::NVSIndex4StreamSend& r)
{
    return l < r || l == r;
}

bool
NVSIndex::operator>(const ::NVSIndex::NVSIndex4StreamSend& l, const ::NVSIndex::NVSIndex4StreamSend& r)
{
    return !(l < r) && !(l == r);
}

bool
NVSIndex::operator>=(const ::NVSIndex::NVSIndex4StreamSend& l, const ::NVSIndex::NVSIndex4StreamSend& r)
{
    return !(l < r);
}
