// **********************************************************************
//
// Copyright (c) 2003-2006 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************

// Ice version 3.1.1
// Generated from file `NVSMonitorNotifier.ice'
#include "stdafx.h"
#include "NVSMonitorNotifier.h"
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

static const ::std::string __NVSStreamService__NVSMonitorNotifier__monitorNotify_name = "monitorNotify";

void
IceInternal::incRef(::NVSStreamService::NVSMonitorNotifier* p)
{
    p->__incRef();
}

void
IceInternal::decRef(::NVSStreamService::NVSMonitorNotifier* p)
{
    p->__decRef();
}

void
IceInternal::incRef(::IceProxy::NVSStreamService::NVSMonitorNotifier* p)
{
    p->__incRef();
}

void
IceInternal::decRef(::IceProxy::NVSStreamService::NVSMonitorNotifier* p)
{
    p->__decRef();
}

void
NVSStreamService::__write(::IceInternal::BasicStream* __os, const ::NVSStreamService::NVSMonitorNotifierPrx& v)
{
    __os->write(::Ice::ObjectPrx(v));
}

void
NVSStreamService::__read(::IceInternal::BasicStream* __is, ::NVSStreamService::NVSMonitorNotifierPrx& v)
{
    ::Ice::ObjectPrx proxy;
    __is->read(proxy);
    if(!proxy)
    {
	v = 0;
    }
    else
    {
	v = new ::IceProxy::NVSStreamService::NVSMonitorNotifier;
	v->__copyFrom(proxy);
    }
}

void
NVSStreamService::__write(::IceInternal::BasicStream* __os, const ::NVSStreamService::NVSMonitorNotifierPtr& v)
{
    __os->write(::Ice::ObjectPtr(v));
}

bool
NVSStreamService::NotifierData::operator==(const NotifierData& __rhs) const
{
    return !operator!=(__rhs);
}

bool
NVSStreamService::NotifierData::operator!=(const NotifierData& __rhs) const
{
    if(this == &__rhs)
    {
	return false;
    }
    if(nCameraID != __rhs.nCameraID)
    {
	return true;
    }
    if(nErr != __rhs.nErr)
    {
	return true;
    }
    return false;
}

bool
NVSStreamService::NotifierData::operator<(const NotifierData& __rhs) const
{
    if(this == &__rhs)
    {
	return false;
    }
    if(nCameraID < __rhs.nCameraID)
    {
	return true;
    }
    else if(__rhs.nCameraID < nCameraID)
    {
	return false;
    }
    if(nErr < __rhs.nErr)
    {
	return true;
    }
    else if(__rhs.nErr < nErr)
    {
	return false;
    }
    return false;
}

void
NVSStreamService::NotifierData::__write(::IceInternal::BasicStream* __os) const
{
    __os->write(nCameraID);
    __os->write(nErr);
}

void
NVSStreamService::NotifierData::__read(::IceInternal::BasicStream* __is)
{
    __is->read(nCameraID);
    __is->read(nErr);
}

void
IceProxy::NVSStreamService::NVSMonitorNotifier::monitorNotify(const ::NVSStreamService::NotifierData& NData, const ::Ice::Context& __ctx)
{
    int __cnt = 0;
    while(true)
    {
	try
	{
	    ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase = __getDelegate();
	    ::IceDelegate::NVSStreamService::NVSMonitorNotifier* __del = dynamic_cast< ::IceDelegate::NVSStreamService::NVSMonitorNotifier*>(__delBase.get());
	    __del->monitorNotify(NData, __ctx);
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
IceProxy::NVSStreamService::NVSMonitorNotifier::ice_staticId()
{
    return ::NVSStreamService::NVSMonitorNotifier::ice_staticId();
}

::IceInternal::Handle< ::IceDelegateM::Ice::Object>
IceProxy::NVSStreamService::NVSMonitorNotifier::__createDelegateM()
{
    return ::IceInternal::Handle< ::IceDelegateM::Ice::Object>(new ::IceDelegateM::NVSStreamService::NVSMonitorNotifier);
}

::IceInternal::Handle< ::IceDelegateD::Ice::Object>
IceProxy::NVSStreamService::NVSMonitorNotifier::__createDelegateD()
{
    return ::IceInternal::Handle< ::IceDelegateD::Ice::Object>(new ::IceDelegateD::NVSStreamService::NVSMonitorNotifier);
}

bool
IceProxy::NVSStreamService::operator==(const ::IceProxy::NVSStreamService::NVSMonitorNotifier& l, const ::IceProxy::NVSStreamService::NVSMonitorNotifier& r)
{
    return static_cast<const ::IceProxy::Ice::Object&>(l) == static_cast<const ::IceProxy::Ice::Object&>(r);
}

bool
IceProxy::NVSStreamService::operator!=(const ::IceProxy::NVSStreamService::NVSMonitorNotifier& l, const ::IceProxy::NVSStreamService::NVSMonitorNotifier& r)
{
    return static_cast<const ::IceProxy::Ice::Object&>(l) != static_cast<const ::IceProxy::Ice::Object&>(r);
}

bool
IceProxy::NVSStreamService::operator<(const ::IceProxy::NVSStreamService::NVSMonitorNotifier& l, const ::IceProxy::NVSStreamService::NVSMonitorNotifier& r)
{
    return static_cast<const ::IceProxy::Ice::Object&>(l) < static_cast<const ::IceProxy::Ice::Object&>(r);
}

bool
IceProxy::NVSStreamService::operator<=(const ::IceProxy::NVSStreamService::NVSMonitorNotifier& l, const ::IceProxy::NVSStreamService::NVSMonitorNotifier& r)
{
    return l < r || l == r;
}

bool
IceProxy::NVSStreamService::operator>(const ::IceProxy::NVSStreamService::NVSMonitorNotifier& l, const ::IceProxy::NVSStreamService::NVSMonitorNotifier& r)
{
    return !(l < r) && !(l == r);
}

bool
IceProxy::NVSStreamService::operator>=(const ::IceProxy::NVSStreamService::NVSMonitorNotifier& l, const ::IceProxy::NVSStreamService::NVSMonitorNotifier& r)
{
    return !(l < r);
}

void
IceDelegateM::NVSStreamService::NVSMonitorNotifier::monitorNotify(const ::NVSStreamService::NotifierData& NData, const ::Ice::Context& __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __NVSStreamService__NVSMonitorNotifier__monitorNotify_name, ::Ice::Normal, __context, __compress);
    try
    {
	::IceInternal::BasicStream* __os = __og.os();
	NData.__write(__os);
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
IceDelegateD::NVSStreamService::NVSMonitorNotifier::monitorNotify(const ::NVSStreamService::NotifierData& NData, const ::Ice::Context& __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __NVSStreamService__NVSMonitorNotifier__monitorNotify_name, ::Ice::Normal, __context);
    while(true)
    {
	::IceInternal::Direct __direct(__current);
	::NVSStreamService::NVSMonitorNotifier* __servant = dynamic_cast< ::NVSStreamService::NVSMonitorNotifier*>(__direct.servant().get());
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
	    __servant->monitorNotify(NData, __current);
	    return;
	}
	catch(const ::Ice::LocalException& __ex)
	{
	    throw ::IceInternal::LocalExceptionWrapper(__ex, false);
	}
    }
}

::Ice::ObjectPtr
NVSStreamService::NVSMonitorNotifier::ice_clone() const
{
    throw ::Ice::CloneNotImplementedException(__FILE__, __LINE__);
    return 0; // to avoid a warning with some compilers
}

static const ::std::string __NVSStreamService__NVSMonitorNotifier_ids[2] =
{
    "::Ice::Object",
    "::NVSStreamService::NVSMonitorNotifier"
};

bool
NVSStreamService::NVSMonitorNotifier::ice_isA(const ::std::string& _s, const ::Ice::Current&) const
{
    return ::std::binary_search(__NVSStreamService__NVSMonitorNotifier_ids, __NVSStreamService__NVSMonitorNotifier_ids + 2, _s);
}

::std::vector< ::std::string>
NVSStreamService::NVSMonitorNotifier::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&__NVSStreamService__NVSMonitorNotifier_ids[0], &__NVSStreamService__NVSMonitorNotifier_ids[2]);
}

const ::std::string&
NVSStreamService::NVSMonitorNotifier::ice_id(const ::Ice::Current&) const
{
    return __NVSStreamService__NVSMonitorNotifier_ids[1];
}

const ::std::string&
NVSStreamService::NVSMonitorNotifier::ice_staticId()
{
    return __NVSStreamService__NVSMonitorNotifier_ids[1];
}

::IceInternal::DispatchStatus
NVSStreamService::NVSMonitorNotifier::___monitorNotify(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::NVSStreamService::NotifierData NData;
    NData.__read(__is);
    monitorNotify(NData, __current);
    return ::IceInternal::DispatchOK;
}

static ::std::string __NVSStreamService__NVSMonitorNotifier_all[] =
{
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping",
    "monitorNotify"
};

::IceInternal::DispatchStatus
NVSStreamService::NVSMonitorNotifier::__dispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair< ::std::string*, ::std::string*> r = ::std::equal_range(__NVSStreamService__NVSMonitorNotifier_all, __NVSStreamService__NVSMonitorNotifier_all + 5, current.operation);
    if(r.first == r.second)
    {
	return ::IceInternal::DispatchOperationNotExist;
    }

    switch(r.first - __NVSStreamService__NVSMonitorNotifier_all)
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
	    return ___monitorNotify(in, current);
	}
    }

    assert(false);
    return ::IceInternal::DispatchOperationNotExist;
}

void
NVSStreamService::NVSMonitorNotifier::__write(::IceInternal::BasicStream* __os) const
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
NVSStreamService::NVSMonitorNotifier::__read(::IceInternal::BasicStream* __is, bool __rid)
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
NVSStreamService::NVSMonitorNotifier::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type NVSStreamService::NVSMonitorNotifier was not generated with stream support";
    throw ex;
}

void
NVSStreamService::NVSMonitorNotifier::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type NVSStreamService::NVSMonitorNotifier was not generated with stream support";
    throw ex;
}

void 
NVSStreamService::__patch__NVSMonitorNotifierPtr(void* __addr, ::Ice::ObjectPtr& v)
{
    ::NVSStreamService::NVSMonitorNotifierPtr* p = static_cast< ::NVSStreamService::NVSMonitorNotifierPtr*>(__addr);
    assert(p);
    *p = ::NVSStreamService::NVSMonitorNotifierPtr::dynamicCast(v);
    if(v && !*p)
    {
	::Ice::NoObjectFactoryException e(__FILE__, __LINE__);
	e.type = ::NVSStreamService::NVSMonitorNotifier::ice_staticId();
	throw e;
    }
}

bool
NVSStreamService::operator==(const ::NVSStreamService::NVSMonitorNotifier& l, const ::NVSStreamService::NVSMonitorNotifier& r)
{
    return static_cast<const ::Ice::Object&>(l) == static_cast<const ::Ice::Object&>(r);
}

bool
NVSStreamService::operator!=(const ::NVSStreamService::NVSMonitorNotifier& l, const ::NVSStreamService::NVSMonitorNotifier& r)
{
    return static_cast<const ::Ice::Object&>(l) != static_cast<const ::Ice::Object&>(r);
}

bool
NVSStreamService::operator<(const ::NVSStreamService::NVSMonitorNotifier& l, const ::NVSStreamService::NVSMonitorNotifier& r)
{
    return static_cast<const ::Ice::Object&>(l) < static_cast<const ::Ice::Object&>(r);
}

bool
NVSStreamService::operator<=(const ::NVSStreamService::NVSMonitorNotifier& l, const ::NVSStreamService::NVSMonitorNotifier& r)
{
    return l < r || l == r;
}

bool
NVSStreamService::operator>(const ::NVSStreamService::NVSMonitorNotifier& l, const ::NVSStreamService::NVSMonitorNotifier& r)
{
    return !(l < r) && !(l == r);
}

bool
NVSStreamService::operator>=(const ::NVSStreamService::NVSMonitorNotifier& l, const ::NVSStreamService::NVSMonitorNotifier& r)
{
    return !(l < r);
}
