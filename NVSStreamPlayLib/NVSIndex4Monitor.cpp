// **********************************************************************
//
// Copyright (c) 2003-2006 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************

// Ice version 3.1.1
// Generated from file `NVSIndex4Monitor.ice'
#include "stdafx.h"
#include <Ice/LocalException.h>
#include <Ice/ObjectFactory.h>
#include <Ice/BasicStream.h>
#include <Ice/Object.h>
#include <IceUtil/Iterator.h>

#include "NVSIndex4Monitor.h"

#ifndef ICE_IGNORE_VERSION
#   if ICE_INT_VERSION / 100 != 301
#       error Ice version mismatch!
#   endif
#   if ICE_INT_VERSION % 100 < 1
#       error Ice patch level mismatch!
#   endif
#endif

static const ::std::string __NVSIndex__NVSModel__checkNeedReboot_name = "checkNeedReboot";

static const ::std::string __NVSIndex__NVSIndexNotice__notifyClient_name = "notifyClient";

static const ::std::string __NVSIndex__NVSIndexNotice__notifySwitched_name = "notifySwitched";

static const ::std::string __NVSIndex__NVSIndex4Monitor__registerMe_name = "registerMe";

static const ::std::string __NVSIndex__NVSIndex4Monitor__getStreamService_name = "getStreamService";

static const ::std::string __NVSIndex__NVSIndex4Monitor__getExternalStreamService_name = "getExternalStreamService";

static const ::std::string __NVSIndex__NVSIndex4Monitor__heartBeat_name = "heartBeat";

static const ::std::string __NVSIndex__NVSIndex4Monitor__getDvrInfo_name = "getDvrInfo";

static const ::std::string __NVSIndex__NVSIndex4Monitor__getStreamOnline_name = "getStreamOnline";

static const ::std::string __NVSIndex__NVSIndex4Monitor__getControlService_name = "getControlService";

static const ::std::string __NVSIndex__NVSIndex4Monitor__getStreamMonitorNum_name = "getStreamMonitorNum";

static const ::std::string __NVSIndex__NVSIndex4Monitor__reSetServer_name = "reSetServer";

static const ::std::string __NVSIndex__NVSIndex4Monitor__checkNeedRebootSyn_name = "checkNeedRebootSyn";

static const ::std::string __NVSIndex__NVSIndex4Monitor__NoticeReady_name = "NoticeReady";

static const ::std::string __NVSIndex__NVSIndex4Monitor__UpdateClientID_name = "UpdateClientID";

static const ::std::string __NVSIndex__NVSIndex4Monitor__NoticeReleaseUser_name = "NoticeReleaseUser";

static const ::std::string __NVSIndex__NVSIndex4Monitor__NoticeReleaseUserAll_name = "NoticeReleaseUserAll";

static const ::std::string __NVSIndex__NVSIndex4Monitor__ConvertCameraID_name = "ConvertCameraID";

static const ::std::string __NVSIndex__NVSIndex4Monitor__getSystemRunState_name = "getSystemRunState";

static const ::std::string __NVSIndex__NVSIndex4Monitor__heartBeatRetVaule_name = "heartBeatRetVaule";

void
IceInternal::incRef(::NVSIndex::NVSModel* p)
{
    p->__incRef();
}

void
IceInternal::decRef(::NVSIndex::NVSModel* p)
{
    p->__decRef();
}

void
IceInternal::incRef(::IceProxy::NVSIndex::NVSModel* p)
{
    p->__incRef();
}

void
IceInternal::decRef(::IceProxy::NVSIndex::NVSModel* p)
{
    p->__decRef();
}

void
IceInternal::incRef(::NVSIndex::NVSIndexNotice* p)
{
    p->__incRef();
}

void
IceInternal::decRef(::NVSIndex::NVSIndexNotice* p)
{
    p->__decRef();
}

void
IceInternal::incRef(::IceProxy::NVSIndex::NVSIndexNotice* p)
{
    p->__incRef();
}

void
IceInternal::decRef(::IceProxy::NVSIndex::NVSIndexNotice* p)
{
    p->__decRef();
}

void
IceInternal::incRef(::NVSIndex::NVSIndex4Monitor* p)
{
    p->__incRef();
}

void
IceInternal::decRef(::NVSIndex::NVSIndex4Monitor* p)
{
    p->__decRef();
}

void
IceInternal::incRef(::IceProxy::NVSIndex::NVSIndex4Monitor* p)
{
    p->__incRef();
}

void
IceInternal::decRef(::IceProxy::NVSIndex::NVSIndex4Monitor* p)
{
    p->__decRef();
}

void
NVSIndex::__write(::IceInternal::BasicStream* __os, const ::NVSIndex::NVSModelPrx& v)
{
    __os->write(::Ice::ObjectPrx(v));
}

void
NVSIndex::__read(::IceInternal::BasicStream* __is, ::NVSIndex::NVSModelPrx& v)
{
    ::Ice::ObjectPrx proxy;
    __is->read(proxy);
    if(!proxy)
    {
	v = 0;
    }
    else
    {
	v = new ::IceProxy::NVSIndex::NVSModel;
	v->__copyFrom(proxy);
    }
}

void
NVSIndex::__write(::IceInternal::BasicStream* __os, const ::NVSIndex::NVSModelPtr& v)
{
    __os->write(::Ice::ObjectPtr(v));
}

void
NVSIndex::__write(::IceInternal::BasicStream* __os, const ::NVSIndex::NVSIndexNoticePrx& v)
{
    __os->write(::Ice::ObjectPrx(v));
}

void
NVSIndex::__read(::IceInternal::BasicStream* __is, ::NVSIndex::NVSIndexNoticePrx& v)
{
    ::Ice::ObjectPrx proxy;
    __is->read(proxy);
    if(!proxy)
    {
	v = 0;
    }
    else
    {
	v = new ::IceProxy::NVSIndex::NVSIndexNotice;
	v->__copyFrom(proxy);
    }
}

void
NVSIndex::__write(::IceInternal::BasicStream* __os, const ::NVSIndex::NVSIndexNoticePtr& v)
{
    __os->write(::Ice::ObjectPtr(v));
}

void
NVSIndex::__write(::IceInternal::BasicStream* __os, const ::NVSIndex::NVSIndex4MonitorPrx& v)
{
    __os->write(::Ice::ObjectPrx(v));
}

void
NVSIndex::__read(::IceInternal::BasicStream* __is, ::NVSIndex::NVSIndex4MonitorPrx& v)
{
    ::Ice::ObjectPrx proxy;
    __is->read(proxy);
    if(!proxy)
    {
	v = 0;
    }
    else
    {
	v = new ::IceProxy::NVSIndex::NVSIndex4Monitor;
	v->__copyFrom(proxy);
    }
}

void
NVSIndex::__write(::IceInternal::BasicStream* __os, const ::NVSIndex::NVSIndex4MonitorPtr& v)
{
    __os->write(::Ice::ObjectPtr(v));
}

static const char* __NVSIndex__RangeError_name = "NVSIndex::RangeError";

const ::std::string
NVSIndex::RangeError::ice_name() const
{
    return __NVSIndex__RangeError_name;
}

::Ice::Exception*
NVSIndex::RangeError::ice_clone() const
{
    return new RangeError(*this);
}

void
NVSIndex::RangeError::ice_throw() const
{
    throw *this;
}

void
NVSIndex::RangeError::__write(::IceInternal::BasicStream* __os) const
{
    __os->write(::std::string("::NVSIndex::RangeError"), false);
    __os->startWriteSlice();
    __os->endWriteSlice();
}

void
NVSIndex::RangeError::__read(::IceInternal::BasicStream* __is, bool __rid)
{
    if(__rid)
    {
	::std::string myId;
	__is->read(myId, false);
    }
    __is->startReadSlice();
    __is->endReadSlice();
}

void
NVSIndex::RangeError::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "exception NVSIndex::RangeError was not generated with stream support";
    throw ex;
}

void
NVSIndex::RangeError::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "exception NVSIndex::RangeError was not generated with stream support";
    throw ex;
}

struct __F__NVSIndex__RangeError : public ::IceInternal::UserExceptionFactory
{
    virtual void
    createAndThrow()
    {
	throw ::NVSIndex::RangeError();
    }
};

static ::IceInternal::UserExceptionFactoryPtr __F__NVSIndex__RangeError__Ptr = new __F__NVSIndex__RangeError;

const ::IceInternal::UserExceptionFactoryPtr&
NVSIndex::RangeError::ice_factory()
{
    return __F__NVSIndex__RangeError__Ptr;
}

class __F__NVSIndex__RangeError__Init
{
public:

    __F__NVSIndex__RangeError__Init()
    {
	::IceInternal::factoryTable->addExceptionFactory("::NVSIndex::RangeError", ::NVSIndex::RangeError::ice_factory());
    }

    ~__F__NVSIndex__RangeError__Init()
    {
	::IceInternal::factoryTable->removeExceptionFactory("::NVSIndex::RangeError");
    }
};

static __F__NVSIndex__RangeError__Init __F__NVSIndex__RangeError__i;

#ifdef __APPLE__
extern "C" { void __F__NVSIndex__RangeError__initializer() {} }
#endif

bool
NVSIndex::IndexNoticeInfo::operator==(const IndexNoticeInfo& __rhs) const
{
    return !operator!=(__rhs);
}

bool
NVSIndex::IndexNoticeInfo::operator!=(const IndexNoticeInfo& __rhs) const
{
    if(this == &__rhs)
    {
	return false;
    }
    if(nUserID != __rhs.nUserID)
    {
	return true;
    }
    if(nChangeType != __rhs.nChangeType)
    {
	return true;
    }
    if(nLimitTime != __rhs.nLimitTime)
    {
	return true;
    }
    return false;
}

bool
NVSIndex::IndexNoticeInfo::operator<(const IndexNoticeInfo& __rhs) const
{
    if(this == &__rhs)
    {
	return false;
    }
    if(nUserID < __rhs.nUserID)
    {
	return true;
    }
    else if(__rhs.nUserID < nUserID)
    {
	return false;
    }
    if(nChangeType < __rhs.nChangeType)
    {
	return true;
    }
    else if(__rhs.nChangeType < nChangeType)
    {
	return false;
    }
    if(nLimitTime < __rhs.nLimitTime)
    {
	return true;
    }
    else if(__rhs.nLimitTime < nLimitTime)
    {
	return false;
    }
    return false;
}

void
NVSIndex::IndexNoticeInfo::__write(::IceInternal::BasicStream* __os) const
{
    __os->write(nUserID);
    __os->write(nChangeType);
    __os->write(nLimitTime);
}

void
NVSIndex::IndexNoticeInfo::__read(::IceInternal::BasicStream* __is)
{
    __is->read(nUserID);
    __is->read(nChangeType);
    __is->read(nLimitTime);
}

void
NVSIndex::AMI_NVSModel_checkNeedReboot::__invoke(const ::NVSIndex::NVSModelPrx& __prx, ::Ice::Int nUID, ::Ice::Int nOrgID, const ::std::string& sLastLoginTime, const ::Ice::Context& __ctx)
{
    try
    {
	__prepare(__prx, __NVSIndex__NVSModel__checkNeedReboot_name, ::Ice::Normal, __ctx);
	__os->write(nUID);
	__os->write(nOrgID);
	__os->write(sLastLoginTime);
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
NVSIndex::AMI_NVSModel_checkNeedReboot::__response(bool __ok)
{
    ::Ice::Int __ret;
    try
    {
	if(!__ok)
	{
	    try
	    {
		__is->throwException();
	    }
	    catch(const ::NVSIndex::RangeError& __ex)
	    {
		ice_exception(__ex);
		return;
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
NVSIndex::AMI_NVSIndexNotice_notifyClient::__invoke(const ::NVSIndex::NVSIndexNoticePrx& __prx, const ::NVSIndex::IndexNoticeInfo& NoticeInfo, const ::Ice::Context& __ctx)
{
    try
    {
	__prepare(__prx, __NVSIndex__NVSIndexNotice__notifyClient_name, ::Ice::Normal, __ctx);
	NoticeInfo.__write(__os);
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
NVSIndex::AMI_NVSIndexNotice_notifyClient::__response(bool __ok)
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
NVSIndex::AMI_NVSIndexNotice_notifySwitched::__invoke(const ::NVSIndex::NVSIndexNoticePrx& __prx, ::Ice::Int nMonitorID, ::Ice::Int nPriorCameraID, ::Ice::Int nCameraID, const ::std::string& Description, const ::Ice::Context& __ctx)
{
    try
    {
	__prepare(__prx, __NVSIndex__NVSIndexNotice__notifySwitched_name, ::Ice::Normal, __ctx);
	__os->write(nMonitorID);
	__os->write(nPriorCameraID);
	__os->write(nCameraID);
	__os->write(Description);
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
NVSIndex::AMI_NVSIndexNotice_notifySwitched::__response(bool __ok)
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

IceAsync::NVSIndex::AMD_NVSModel_checkNeedReboot::AMD_NVSModel_checkNeedReboot(::IceInternal::Incoming& in) :
    ::IceInternal::IncomingAsync(in)
{
}

void
IceAsync::NVSIndex::AMD_NVSModel_checkNeedReboot::ice_response(::Ice::Int __ret)
{
    try
    {
	::IceInternal::BasicStream* __os = this->__os();
	__os->write(__ret);
    }
    catch(const ::Ice::Exception& __ex)
    {
	__exception(__ex);
	return;
    }
    __response(true);
}

void
IceAsync::NVSIndex::AMD_NVSModel_checkNeedReboot::ice_exception(const ::Ice::Exception& ex)
{
    try
    {
	ex.ice_throw();
    }
    catch(const ::NVSIndex::RangeError& __ex)
    {
	__os()->write(__ex);
	__response(false);
    }
    catch(const ::Ice::Exception& __ex)
    {
	__exception(__ex);
    }
}

void
IceAsync::NVSIndex::AMD_NVSModel_checkNeedReboot::ice_exception(const ::std::exception& ex)
{
    __exception(ex);
}

void
IceAsync::NVSIndex::AMD_NVSModel_checkNeedReboot::ice_exception()
{
    __exception();
}

::Ice::Int
IceProxy::NVSIndex::NVSModel::checkNeedReboot(::Ice::Int nUID, ::Ice::Int nOrgID, const ::std::string& sLastLoginTime, const ::Ice::Context& __ctx)
{
    int __cnt = 0;
    while(true)
    {
	try
	{
	    __checkTwowayOnly(__NVSIndex__NVSModel__checkNeedReboot_name);
	    ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase = __getDelegate();
	    ::IceDelegate::NVSIndex::NVSModel* __del = dynamic_cast< ::IceDelegate::NVSIndex::NVSModel*>(__delBase.get());
	    return __del->checkNeedReboot(nUID, nOrgID, sLastLoginTime, __ctx);
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
IceProxy::NVSIndex::NVSModel::checkNeedReboot_async(const ::NVSIndex::AMI_NVSModel_checkNeedRebootPtr& __cb, ::Ice::Int nUID, ::Ice::Int nOrgID, const ::std::string& sLastLoginTime)
{
    checkNeedReboot_async(__cb, nUID, nOrgID, sLastLoginTime, __defaultContext());
}

void
IceProxy::NVSIndex::NVSModel::checkNeedReboot_async(const ::NVSIndex::AMI_NVSModel_checkNeedRebootPtr& __cb, ::Ice::Int nUID, ::Ice::Int nOrgID, const ::std::string& sLastLoginTime, const ::Ice::Context& __ctx)
{
    __cb->__invoke(this, nUID, nOrgID, sLastLoginTime, __ctx);
}

const ::std::string&
IceProxy::NVSIndex::NVSModel::ice_staticId()
{
    return ::NVSIndex::NVSModel::ice_staticId();
}

::IceInternal::Handle< ::IceDelegateM::Ice::Object>
IceProxy::NVSIndex::NVSModel::__createDelegateM()
{
    return ::IceInternal::Handle< ::IceDelegateM::Ice::Object>(new ::IceDelegateM::NVSIndex::NVSModel);
}

::IceInternal::Handle< ::IceDelegateD::Ice::Object>
IceProxy::NVSIndex::NVSModel::__createDelegateD()
{
    return ::IceInternal::Handle< ::IceDelegateD::Ice::Object>(new ::IceDelegateD::NVSIndex::NVSModel);
}

bool
IceProxy::NVSIndex::operator==(const ::IceProxy::NVSIndex::NVSModel& l, const ::IceProxy::NVSIndex::NVSModel& r)
{
    return static_cast<const ::IceProxy::Ice::Object&>(l) == static_cast<const ::IceProxy::Ice::Object&>(r);
}

bool
IceProxy::NVSIndex::operator!=(const ::IceProxy::NVSIndex::NVSModel& l, const ::IceProxy::NVSIndex::NVSModel& r)
{
    return static_cast<const ::IceProxy::Ice::Object&>(l) != static_cast<const ::IceProxy::Ice::Object&>(r);
}

bool
IceProxy::NVSIndex::operator<(const ::IceProxy::NVSIndex::NVSModel& l, const ::IceProxy::NVSIndex::NVSModel& r)
{
    return static_cast<const ::IceProxy::Ice::Object&>(l) < static_cast<const ::IceProxy::Ice::Object&>(r);
}

bool
IceProxy::NVSIndex::operator<=(const ::IceProxy::NVSIndex::NVSModel& l, const ::IceProxy::NVSIndex::NVSModel& r)
{
    return l < r || l == r;
}

bool
IceProxy::NVSIndex::operator>(const ::IceProxy::NVSIndex::NVSModel& l, const ::IceProxy::NVSIndex::NVSModel& r)
{
    return !(l < r) && !(l == r);
}

bool
IceProxy::NVSIndex::operator>=(const ::IceProxy::NVSIndex::NVSModel& l, const ::IceProxy::NVSIndex::NVSModel& r)
{
    return !(l < r);
}

bool
IceProxy::NVSIndex::NVSIndexNotice::notifyClient(const ::NVSIndex::IndexNoticeInfo& NoticeInfo, const ::Ice::Context& __ctx)
{
    int __cnt = 0;
    while(true)
    {
	try
	{
	    __checkTwowayOnly(__NVSIndex__NVSIndexNotice__notifyClient_name);
	    ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase = __getDelegate();
	    ::IceDelegate::NVSIndex::NVSIndexNotice* __del = dynamic_cast< ::IceDelegate::NVSIndex::NVSIndexNotice*>(__delBase.get());
	    return __del->notifyClient(NoticeInfo, __ctx);
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
IceProxy::NVSIndex::NVSIndexNotice::notifyClient_async(const ::NVSIndex::AMI_NVSIndexNotice_notifyClientPtr& __cb, const ::NVSIndex::IndexNoticeInfo& NoticeInfo)
{
    notifyClient_async(__cb, NoticeInfo, __defaultContext());
}

void
IceProxy::NVSIndex::NVSIndexNotice::notifyClient_async(const ::NVSIndex::AMI_NVSIndexNotice_notifyClientPtr& __cb, const ::NVSIndex::IndexNoticeInfo& NoticeInfo, const ::Ice::Context& __ctx)
{
    __cb->__invoke(this, NoticeInfo, __ctx);
}

bool
IceProxy::NVSIndex::NVSIndexNotice::notifySwitched(::Ice::Int nMonitorID, ::Ice::Int nPriorCameraID, ::Ice::Int nCameraID, const ::std::string& Description, const ::Ice::Context& __ctx)
{
    int __cnt = 0;
    while(true)
    {
	try
	{
	    __checkTwowayOnly(__NVSIndex__NVSIndexNotice__notifySwitched_name);
	    ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase = __getDelegate();
	    ::IceDelegate::NVSIndex::NVSIndexNotice* __del = dynamic_cast< ::IceDelegate::NVSIndex::NVSIndexNotice*>(__delBase.get());
	    return __del->notifySwitched(nMonitorID, nPriorCameraID, nCameraID, Description, __ctx);
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
IceProxy::NVSIndex::NVSIndexNotice::notifySwitched_async(const ::NVSIndex::AMI_NVSIndexNotice_notifySwitchedPtr& __cb, ::Ice::Int nMonitorID, ::Ice::Int nPriorCameraID, ::Ice::Int nCameraID, const ::std::string& Description)
{
    notifySwitched_async(__cb, nMonitorID, nPriorCameraID, nCameraID, Description, __defaultContext());
}

void
IceProxy::NVSIndex::NVSIndexNotice::notifySwitched_async(const ::NVSIndex::AMI_NVSIndexNotice_notifySwitchedPtr& __cb, ::Ice::Int nMonitorID, ::Ice::Int nPriorCameraID, ::Ice::Int nCameraID, const ::std::string& Description, const ::Ice::Context& __ctx)
{
    __cb->__invoke(this, nMonitorID, nPriorCameraID, nCameraID, Description, __ctx);
}

const ::std::string&
IceProxy::NVSIndex::NVSIndexNotice::ice_staticId()
{
    return ::NVSIndex::NVSIndexNotice::ice_staticId();
}

::IceInternal::Handle< ::IceDelegateM::Ice::Object>
IceProxy::NVSIndex::NVSIndexNotice::__createDelegateM()
{
    return ::IceInternal::Handle< ::IceDelegateM::Ice::Object>(new ::IceDelegateM::NVSIndex::NVSIndexNotice);
}

::IceInternal::Handle< ::IceDelegateD::Ice::Object>
IceProxy::NVSIndex::NVSIndexNotice::__createDelegateD()
{
    return ::IceInternal::Handle< ::IceDelegateD::Ice::Object>(new ::IceDelegateD::NVSIndex::NVSIndexNotice);
}

bool
IceProxy::NVSIndex::operator==(const ::IceProxy::NVSIndex::NVSIndexNotice& l, const ::IceProxy::NVSIndex::NVSIndexNotice& r)
{
    return static_cast<const ::IceProxy::Ice::Object&>(l) == static_cast<const ::IceProxy::Ice::Object&>(r);
}

bool
IceProxy::NVSIndex::operator!=(const ::IceProxy::NVSIndex::NVSIndexNotice& l, const ::IceProxy::NVSIndex::NVSIndexNotice& r)
{
    return static_cast<const ::IceProxy::Ice::Object&>(l) != static_cast<const ::IceProxy::Ice::Object&>(r);
}

bool
IceProxy::NVSIndex::operator<(const ::IceProxy::NVSIndex::NVSIndexNotice& l, const ::IceProxy::NVSIndex::NVSIndexNotice& r)
{
    return static_cast<const ::IceProxy::Ice::Object&>(l) < static_cast<const ::IceProxy::Ice::Object&>(r);
}

bool
IceProxy::NVSIndex::operator<=(const ::IceProxy::NVSIndex::NVSIndexNotice& l, const ::IceProxy::NVSIndex::NVSIndexNotice& r)
{
    return l < r || l == r;
}

bool
IceProxy::NVSIndex::operator>(const ::IceProxy::NVSIndex::NVSIndexNotice& l, const ::IceProxy::NVSIndex::NVSIndexNotice& r)
{
    return !(l < r) && !(l == r);
}

bool
IceProxy::NVSIndex::operator>=(const ::IceProxy::NVSIndex::NVSIndexNotice& l, const ::IceProxy::NVSIndex::NVSIndexNotice& r)
{
    return !(l < r);
}

bool
IceProxy::NVSIndex::NVSIndex4Monitor::registerMe(const ::NVSIndex::NVSMonitorInfo& outInfo, ::NVSIndex::NVSMonitorInfo& backInfo, const ::Ice::Context& __ctx)
{
    int __cnt = 0;
    while(true)
    {
	try
	{
	    __checkTwowayOnly(__NVSIndex__NVSIndex4Monitor__registerMe_name);
	    ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase = __getDelegate();
	    ::IceDelegate::NVSIndex::NVSIndex4Monitor* __del = dynamic_cast< ::IceDelegate::NVSIndex::NVSIndex4Monitor*>(__delBase.get());
	    return __del->registerMe(outInfo, backInfo, __ctx);
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
IceProxy::NVSIndex::NVSIndex4Monitor::getStreamService(::Ice::Int MonitorID, ::Ice::Int cameraID, ::std::string& sSSProxy, ::Ice::Int& serviceKey, const ::Ice::Context& __ctx)
{
    int __cnt = 0;
    while(true)
    {
	try
	{
	    __checkTwowayOnly(__NVSIndex__NVSIndex4Monitor__getStreamService_name);
	    ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase = __getDelegate();
	    ::IceDelegate::NVSIndex::NVSIndex4Monitor* __del = dynamic_cast< ::IceDelegate::NVSIndex::NVSIndex4Monitor*>(__delBase.get());
	    return __del->getStreamService(MonitorID, cameraID, sSSProxy, serviceKey, __ctx);
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
IceProxy::NVSIndex::NVSIndex4Monitor::getExternalStreamService(::Ice::Int MonitorID, ::Ice::Int cameraID, ::std::string& sSSProxy, ::Ice::Int& serviceKey, const ::Ice::Context& __ctx)
{
    int __cnt = 0;
    while(true)
    {
	try
	{
	    __checkTwowayOnly(__NVSIndex__NVSIndex4Monitor__getExternalStreamService_name);
	    ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase = __getDelegate();
	    ::IceDelegate::NVSIndex::NVSIndex4Monitor* __del = dynamic_cast< ::IceDelegate::NVSIndex::NVSIndex4Monitor*>(__delBase.get());
	    return __del->getExternalStreamService(MonitorID, cameraID, sSSProxy, serviceKey, __ctx);
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
IceProxy::NVSIndex::NVSIndex4Monitor::heartBeat(::Ice::Int nID, const ::Ice::Context& __ctx)
{
    int __cnt = 0;
    while(true)
    {
	try
	{
	    ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase = __getDelegate();
	    ::IceDelegate::NVSIndex::NVSIndex4Monitor* __del = dynamic_cast< ::IceDelegate::NVSIndex::NVSIndex4Monitor*>(__delBase.get());
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
IceProxy::NVSIndex::NVSIndex4Monitor::getDvrInfo(::Ice::Int nID, ::NVSIndex::NVSDVRInfo& backInfo, const ::Ice::Context& __ctx)
{
    int __cnt = 0;
    while(true)
    {
	try
	{
	    __checkTwowayOnly(__NVSIndex__NVSIndex4Monitor__getDvrInfo_name);
	    ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase = __getDelegate();
	    ::IceDelegate::NVSIndex::NVSIndex4Monitor* __del = dynamic_cast< ::IceDelegate::NVSIndex::NVSIndex4Monitor*>(__delBase.get());
	    return __del->getDvrInfo(nID, backInfo, __ctx);
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
IceProxy::NVSIndex::NVSIndex4Monitor::getStreamOnline(::NVSIndex::NVSConnectStrPool& backInfo, const ::Ice::Context& __ctx)
{
    int __cnt = 0;
    while(true)
    {
	try
	{
	    __checkTwowayOnly(__NVSIndex__NVSIndex4Monitor__getStreamOnline_name);
	    ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase = __getDelegate();
	    ::IceDelegate::NVSIndex::NVSIndex4Monitor* __del = dynamic_cast< ::IceDelegate::NVSIndex::NVSIndex4Monitor*>(__delBase.get());
	    __del->getStreamOnline(backInfo, __ctx);
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
IceProxy::NVSIndex::NVSIndex4Monitor::getControlService(::Ice::Int cameraID, ::std::string& sSSProxy, ::Ice::Int& serviceKey, const ::Ice::Context& __ctx)
{
    int __cnt = 0;
    while(true)
    {
	try
	{
	    __checkTwowayOnly(__NVSIndex__NVSIndex4Monitor__getControlService_name);
	    ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase = __getDelegate();
	    ::IceDelegate::NVSIndex::NVSIndex4Monitor* __del = dynamic_cast< ::IceDelegate::NVSIndex::NVSIndex4Monitor*>(__delBase.get());
	    return __del->getControlService(cameraID, sSSProxy, serviceKey, __ctx);
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
IceProxy::NVSIndex::NVSIndex4Monitor::getStreamMonitorNum(::Ice::Int& nStreamNum, ::Ice::Int& nMonitorNum, const ::Ice::Context& __ctx)
{
    int __cnt = 0;
    while(true)
    {
	try
	{
	    __checkTwowayOnly(__NVSIndex__NVSIndex4Monitor__getStreamMonitorNum_name);
	    ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase = __getDelegate();
	    ::IceDelegate::NVSIndex::NVSIndex4Monitor* __del = dynamic_cast< ::IceDelegate::NVSIndex::NVSIndex4Monitor*>(__delBase.get());
	    __del->getStreamMonitorNum(nStreamNum, nMonitorNum, __ctx);
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
IceProxy::NVSIndex::NVSIndex4Monitor::reSetServer(const ::Ice::Context& __ctx)
{
    int __cnt = 0;
    while(true)
    {
	try
	{
	    __checkTwowayOnly(__NVSIndex__NVSIndex4Monitor__reSetServer_name);
	    ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase = __getDelegate();
	    ::IceDelegate::NVSIndex::NVSIndex4Monitor* __del = dynamic_cast< ::IceDelegate::NVSIndex::NVSIndex4Monitor*>(__delBase.get());
	    return __del->reSetServer(__ctx);
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
IceProxy::NVSIndex::NVSIndex4Monitor::checkNeedRebootSyn(::Ice::Int nUID, ::Ice::Int nOrgID, const ::std::string& sLastLoginTime, const ::Ice::Context& __ctx)
{
    int __cnt = 0;
    while(true)
    {
	try
	{
	    __checkTwowayOnly(__NVSIndex__NVSIndex4Monitor__checkNeedRebootSyn_name);
	    ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase = __getDelegate();
	    ::IceDelegate::NVSIndex::NVSIndex4Monitor* __del = dynamic_cast< ::IceDelegate::NVSIndex::NVSIndex4Monitor*>(__delBase.get());
	    return __del->checkNeedRebootSyn(nUID, nOrgID, sLastLoginTime, __ctx);
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
IceProxy::NVSIndex::NVSIndex4Monitor::NoticeReady(::Ice::Int nID, const ::Ice::Identity& id, const ::Ice::Context& __ctx)
{
    int __cnt = 0;
    while(true)
    {
	try
	{
	    __checkTwowayOnly(__NVSIndex__NVSIndex4Monitor__NoticeReady_name);
	    ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase = __getDelegate();
	    ::IceDelegate::NVSIndex::NVSIndex4Monitor* __del = dynamic_cast< ::IceDelegate::NVSIndex::NVSIndex4Monitor*>(__delBase.get());
	    return __del->NoticeReady(nID, id, __ctx);
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
IceProxy::NVSIndex::NVSIndex4Monitor::UpdateClientID(::Ice::Int nNewID, ::Ice::Int nPriorID, const ::Ice::Context& __ctx)
{
    int __cnt = 0;
    while(true)
    {
	try
	{
	    __checkTwowayOnly(__NVSIndex__NVSIndex4Monitor__UpdateClientID_name);
	    ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase = __getDelegate();
	    ::IceDelegate::NVSIndex::NVSIndex4Monitor* __del = dynamic_cast< ::IceDelegate::NVSIndex::NVSIndex4Monitor*>(__delBase.get());
	    return __del->UpdateClientID(nNewID, nPriorID, __ctx);
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
IceProxy::NVSIndex::NVSIndex4Monitor::NoticeReleaseUser(::Ice::Int nID, ::Ice::Int nCameraID, const ::Ice::Context& __ctx)
{
    int __cnt = 0;
    while(true)
    {
	try
	{
	    __checkTwowayOnly(__NVSIndex__NVSIndex4Monitor__NoticeReleaseUser_name);
	    ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase = __getDelegate();
	    ::IceDelegate::NVSIndex::NVSIndex4Monitor* __del = dynamic_cast< ::IceDelegate::NVSIndex::NVSIndex4Monitor*>(__delBase.get());
	    return __del->NoticeReleaseUser(nID, nCameraID, __ctx);
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
IceProxy::NVSIndex::NVSIndex4Monitor::NoticeReleaseUserAll(::Ice::Int nUserID, const ::Ice::Context& __ctx)
{
    int __cnt = 0;
    while(true)
    {
	try
	{
	    __checkTwowayOnly(__NVSIndex__NVSIndex4Monitor__NoticeReleaseUserAll_name);
	    ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase = __getDelegate();
	    ::IceDelegate::NVSIndex::NVSIndex4Monitor* __del = dynamic_cast< ::IceDelegate::NVSIndex::NVSIndex4Monitor*>(__delBase.get());
	    return __del->NoticeReleaseUserAll(nUserID, __ctx);
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

::std::string
IceProxy::NVSIndex::NVSIndex4Monitor::ConvertCameraID(::Ice::Int nCameraID, const ::Ice::Context& __ctx)
{
    int __cnt = 0;
    while(true)
    {
	try
	{
	    __checkTwowayOnly(__NVSIndex__NVSIndex4Monitor__ConvertCameraID_name);
	    ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase = __getDelegate();
	    ::IceDelegate::NVSIndex::NVSIndex4Monitor* __del = dynamic_cast< ::IceDelegate::NVSIndex::NVSIndex4Monitor*>(__delBase.get());
	    return __del->ConvertCameraID(nCameraID, __ctx);
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
IceProxy::NVSIndex::NVSIndex4Monitor::getSystemRunState(::NVSIndex::SystemState& ss, const ::Ice::Context& __ctx)
{
    int __cnt = 0;
    while(true)
    {
	try
	{
	    __checkTwowayOnly(__NVSIndex__NVSIndex4Monitor__getSystemRunState_name);
	    ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase = __getDelegate();
	    ::IceDelegate::NVSIndex::NVSIndex4Monitor* __del = dynamic_cast< ::IceDelegate::NVSIndex::NVSIndex4Monitor*>(__delBase.get());
	    __del->getSystemRunState(ss, __ctx);
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
IceProxy::NVSIndex::NVSIndex4Monitor::heartBeatRetVaule(::Ice::Int nID, ::Ice::Int nRight, const ::Ice::Context& __ctx)
{
    int __cnt = 0;
    while(true)
    {
	try
	{
	    __checkTwowayOnly(__NVSIndex__NVSIndex4Monitor__heartBeatRetVaule_name);
	    ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase = __getDelegate();
	    ::IceDelegate::NVSIndex::NVSIndex4Monitor* __del = dynamic_cast< ::IceDelegate::NVSIndex::NVSIndex4Monitor*>(__delBase.get());
	    return __del->heartBeatRetVaule(nID, nRight, __ctx);
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
IceProxy::NVSIndex::NVSIndex4Monitor::ice_staticId()
{
    return ::NVSIndex::NVSIndex4Monitor::ice_staticId();
}

::IceInternal::Handle< ::IceDelegateM::Ice::Object>
IceProxy::NVSIndex::NVSIndex4Monitor::__createDelegateM()
{
    return ::IceInternal::Handle< ::IceDelegateM::Ice::Object>(new ::IceDelegateM::NVSIndex::NVSIndex4Monitor);
}

::IceInternal::Handle< ::IceDelegateD::Ice::Object>
IceProxy::NVSIndex::NVSIndex4Monitor::__createDelegateD()
{
    return ::IceInternal::Handle< ::IceDelegateD::Ice::Object>(new ::IceDelegateD::NVSIndex::NVSIndex4Monitor);
}

bool
IceProxy::NVSIndex::operator==(const ::IceProxy::NVSIndex::NVSIndex4Monitor& l, const ::IceProxy::NVSIndex::NVSIndex4Monitor& r)
{
    return static_cast<const ::IceProxy::Ice::Object&>(l) == static_cast<const ::IceProxy::Ice::Object&>(r);
}

bool
IceProxy::NVSIndex::operator!=(const ::IceProxy::NVSIndex::NVSIndex4Monitor& l, const ::IceProxy::NVSIndex::NVSIndex4Monitor& r)
{
    return static_cast<const ::IceProxy::Ice::Object&>(l) != static_cast<const ::IceProxy::Ice::Object&>(r);
}

bool
IceProxy::NVSIndex::operator<(const ::IceProxy::NVSIndex::NVSIndex4Monitor& l, const ::IceProxy::NVSIndex::NVSIndex4Monitor& r)
{
    return static_cast<const ::IceProxy::Ice::Object&>(l) < static_cast<const ::IceProxy::Ice::Object&>(r);
}

bool
IceProxy::NVSIndex::operator<=(const ::IceProxy::NVSIndex::NVSIndex4Monitor& l, const ::IceProxy::NVSIndex::NVSIndex4Monitor& r)
{
    return l < r || l == r;
}

bool
IceProxy::NVSIndex::operator>(const ::IceProxy::NVSIndex::NVSIndex4Monitor& l, const ::IceProxy::NVSIndex::NVSIndex4Monitor& r)
{
    return !(l < r) && !(l == r);
}

bool
IceProxy::NVSIndex::operator>=(const ::IceProxy::NVSIndex::NVSIndex4Monitor& l, const ::IceProxy::NVSIndex::NVSIndex4Monitor& r)
{
    return !(l < r);
}

::Ice::Int
IceDelegateM::NVSIndex::NVSModel::checkNeedReboot(::Ice::Int nUID, ::Ice::Int nOrgID, const ::std::string& sLastLoginTime, const ::Ice::Context& __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __NVSIndex__NVSModel__checkNeedReboot_name, ::Ice::Normal, __context, __compress);
    try
    {
	::IceInternal::BasicStream* __os = __og.os();
	__os->write(nUID);
	__os->write(nOrgID);
	__os->write(sLastLoginTime);
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
	    catch(const ::NVSIndex::RangeError&)
	    {
		throw;
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

bool
IceDelegateM::NVSIndex::NVSIndexNotice::notifyClient(const ::NVSIndex::IndexNoticeInfo& NoticeInfo, const ::Ice::Context& __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __NVSIndex__NVSIndexNotice__notifyClient_name, ::Ice::Normal, __context, __compress);
    try
    {
	::IceInternal::BasicStream* __os = __og.os();
	NoticeInfo.__write(__os);
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
IceDelegateM::NVSIndex::NVSIndexNotice::notifySwitched(::Ice::Int nMonitorID, ::Ice::Int nPriorCameraID, ::Ice::Int nCameraID, const ::std::string& Description, const ::Ice::Context& __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __NVSIndex__NVSIndexNotice__notifySwitched_name, ::Ice::Normal, __context, __compress);
    try
    {
	::IceInternal::BasicStream* __os = __og.os();
	__os->write(nMonitorID);
	__os->write(nPriorCameraID);
	__os->write(nCameraID);
	__os->write(Description);
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
IceDelegateM::NVSIndex::NVSIndex4Monitor::registerMe(const ::NVSIndex::NVSMonitorInfo& outInfo, ::NVSIndex::NVSMonitorInfo& backInfo, const ::Ice::Context& __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __NVSIndex__NVSIndex4Monitor__registerMe_name, ::Ice::Normal, __context, __compress);
    try
    {
	::IceInternal::BasicStream* __os = __og.os();
	outInfo.__write(__os);
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
IceDelegateM::NVSIndex::NVSIndex4Monitor::getStreamService(::Ice::Int MonitorID, ::Ice::Int cameraID, ::std::string& sSSProxy, ::Ice::Int& serviceKey, const ::Ice::Context& __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __NVSIndex__NVSIndex4Monitor__getStreamService_name, ::Ice::Normal, __context, __compress);
    try
    {
	::IceInternal::BasicStream* __os = __og.os();
	__os->write(MonitorID);
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

::Ice::Byte
IceDelegateM::NVSIndex::NVSIndex4Monitor::getExternalStreamService(::Ice::Int MonitorID, ::Ice::Int cameraID, ::std::string& sSSProxy, ::Ice::Int& serviceKey, const ::Ice::Context& __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __NVSIndex__NVSIndex4Monitor__getExternalStreamService_name, ::Ice::Normal, __context, __compress);
    try
    {
	::IceInternal::BasicStream* __os = __og.os();
	__os->write(MonitorID);
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
IceDelegateM::NVSIndex::NVSIndex4Monitor::heartBeat(::Ice::Int nID, const ::Ice::Context& __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __NVSIndex__NVSIndex4Monitor__heartBeat_name, ::Ice::Normal, __context, __compress);
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
IceDelegateM::NVSIndex::NVSIndex4Monitor::getDvrInfo(::Ice::Int nID, ::NVSIndex::NVSDVRInfo& backInfo, const ::Ice::Context& __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __NVSIndex__NVSIndex4Monitor__getDvrInfo_name, ::Ice::Normal, __context, __compress);
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
IceDelegateM::NVSIndex::NVSIndex4Monitor::getStreamOnline(::NVSIndex::NVSConnectStrPool& backInfo, const ::Ice::Context& __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __NVSIndex__NVSIndex4Monitor__getStreamOnline_name, ::Ice::Normal, __context, __compress);
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
	__is->read(backInfo);
    }
    catch(const ::Ice::LocalException& __ex)
    {
	throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::Ice::Int
IceDelegateM::NVSIndex::NVSIndex4Monitor::getControlService(::Ice::Int cameraID, ::std::string& sSSProxy, ::Ice::Int& serviceKey, const ::Ice::Context& __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __NVSIndex__NVSIndex4Monitor__getControlService_name, ::Ice::Normal, __context, __compress);
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
	::Ice::Int __ret;
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
IceDelegateM::NVSIndex::NVSIndex4Monitor::getStreamMonitorNum(::Ice::Int& nStreamNum, ::Ice::Int& nMonitorNum, const ::Ice::Context& __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __NVSIndex__NVSIndex4Monitor__getStreamMonitorNum_name, ::Ice::Normal, __context, __compress);
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
	__is->read(nStreamNum);
	__is->read(nMonitorNum);
    }
    catch(const ::Ice::LocalException& __ex)
    {
	throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

bool
IceDelegateM::NVSIndex::NVSIndex4Monitor::reSetServer(const ::Ice::Context& __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __NVSIndex__NVSIndex4Monitor__reSetServer_name, ::Ice::Normal, __context, __compress);
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
IceDelegateM::NVSIndex::NVSIndex4Monitor::checkNeedRebootSyn(::Ice::Int nUID, ::Ice::Int nOrgID, const ::std::string& sLastLoginTime, const ::Ice::Context& __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __NVSIndex__NVSIndex4Monitor__checkNeedRebootSyn_name, ::Ice::Normal, __context, __compress);
    try
    {
	::IceInternal::BasicStream* __os = __og.os();
	__os->write(nUID);
	__os->write(nOrgID);
	__os->write(sLastLoginTime);
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
IceDelegateM::NVSIndex::NVSIndex4Monitor::NoticeReady(::Ice::Int nID, const ::Ice::Identity& id, const ::Ice::Context& __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __NVSIndex__NVSIndex4Monitor__NoticeReady_name, ::Ice::Normal, __context, __compress);
    try
    {
	::IceInternal::BasicStream* __os = __og.os();
	__os->write(nID);
	id.__write(__os);
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
IceDelegateM::NVSIndex::NVSIndex4Monitor::UpdateClientID(::Ice::Int nNewID, ::Ice::Int nPriorID, const ::Ice::Context& __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __NVSIndex__NVSIndex4Monitor__UpdateClientID_name, ::Ice::Normal, __context, __compress);
    try
    {
	::IceInternal::BasicStream* __os = __og.os();
	__os->write(nNewID);
	__os->write(nPriorID);
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
IceDelegateM::NVSIndex::NVSIndex4Monitor::NoticeReleaseUser(::Ice::Int nID, ::Ice::Int nCameraID, const ::Ice::Context& __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __NVSIndex__NVSIndex4Monitor__NoticeReleaseUser_name, ::Ice::Normal, __context, __compress);
    try
    {
	::IceInternal::BasicStream* __os = __og.os();
	__os->write(nID);
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
	__is->read(__ret);
	return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
	throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

bool
IceDelegateM::NVSIndex::NVSIndex4Monitor::NoticeReleaseUserAll(::Ice::Int nUserID, const ::Ice::Context& __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __NVSIndex__NVSIndex4Monitor__NoticeReleaseUserAll_name, ::Ice::Normal, __context, __compress);
    try
    {
	::IceInternal::BasicStream* __os = __og.os();
	__os->write(nUserID);
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

::std::string
IceDelegateM::NVSIndex::NVSIndex4Monitor::ConvertCameraID(::Ice::Int nCameraID, const ::Ice::Context& __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __NVSIndex__NVSIndex4Monitor__ConvertCameraID_name, ::Ice::Normal, __context, __compress);
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
	::std::string __ret;
	__is->read(__ret);
	return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
	throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::NVSIndex::NVSIndex4Monitor::getSystemRunState(::NVSIndex::SystemState& ss, const ::Ice::Context& __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __NVSIndex__NVSIndex4Monitor__getSystemRunState_name, ::Ice::Normal, __context, __compress);
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
	ss.__read(__is);
    }
    catch(const ::Ice::LocalException& __ex)
    {
	throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

bool
IceDelegateM::NVSIndex::NVSIndex4Monitor::heartBeatRetVaule(::Ice::Int nID, ::Ice::Int nRight, const ::Ice::Context& __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __NVSIndex__NVSIndex4Monitor__heartBeatRetVaule_name, ::Ice::Normal, __context, __compress);
    try
    {
	::IceInternal::BasicStream* __os = __og.os();
	__os->write(nID);
	__os->write(nRight);
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
IceDelegateD::NVSIndex::NVSModel::checkNeedReboot(::Ice::Int, ::Ice::Int, const ::std::string&, const ::Ice::Context&)
{
    throw ::Ice::CollocationOptimizationException(__FILE__, __LINE__);
    return ::Ice::Int(); // to avoid a warning with some compilers;
}

bool
IceDelegateD::NVSIndex::NVSIndexNotice::notifyClient(const ::NVSIndex::IndexNoticeInfo& NoticeInfo, const ::Ice::Context& __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __NVSIndex__NVSIndexNotice__notifyClient_name, ::Ice::Normal, __context);
    while(true)
    {
	::IceInternal::Direct __direct(__current);
	::NVSIndex::NVSIndexNotice* __servant = dynamic_cast< ::NVSIndex::NVSIndexNotice*>(__direct.servant().get());
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
	    return __servant->notifyClient(NoticeInfo, __current);
	}
	catch(const ::Ice::LocalException& __ex)
	{
	    throw ::IceInternal::LocalExceptionWrapper(__ex, false);
	}
    }
}

bool
IceDelegateD::NVSIndex::NVSIndexNotice::notifySwitched(::Ice::Int nMonitorID, ::Ice::Int nPriorCameraID, ::Ice::Int nCameraID, const ::std::string& Description, const ::Ice::Context& __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __NVSIndex__NVSIndexNotice__notifySwitched_name, ::Ice::Normal, __context);
    while(true)
    {
	::IceInternal::Direct __direct(__current);
	::NVSIndex::NVSIndexNotice* __servant = dynamic_cast< ::NVSIndex::NVSIndexNotice*>(__direct.servant().get());
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
	    return __servant->notifySwitched(nMonitorID, nPriorCameraID, nCameraID, Description, __current);
	}
	catch(const ::Ice::LocalException& __ex)
	{
	    throw ::IceInternal::LocalExceptionWrapper(__ex, false);
	}
    }
}

bool
IceDelegateD::NVSIndex::NVSIndex4Monitor::registerMe(const ::NVSIndex::NVSMonitorInfo& outInfo, ::NVSIndex::NVSMonitorInfo& backInfo, const ::Ice::Context& __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __NVSIndex__NVSIndex4Monitor__registerMe_name, ::Ice::Normal, __context);
    while(true)
    {
	::IceInternal::Direct __direct(__current);
	::NVSIndex::NVSIndex4Monitor* __servant = dynamic_cast< ::NVSIndex::NVSIndex4Monitor*>(__direct.servant().get());
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
	    return __servant->registerMe(outInfo, backInfo, __current);
	}
	catch(const ::Ice::LocalException& __ex)
	{
	    throw ::IceInternal::LocalExceptionWrapper(__ex, false);
	}
    }
}

::Ice::Byte
IceDelegateD::NVSIndex::NVSIndex4Monitor::getStreamService(::Ice::Int MonitorID, ::Ice::Int cameraID, ::std::string& sSSProxy, ::Ice::Int& serviceKey, const ::Ice::Context& __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __NVSIndex__NVSIndex4Monitor__getStreamService_name, ::Ice::Normal, __context);
    while(true)
    {
	::IceInternal::Direct __direct(__current);
	::NVSIndex::NVSIndex4Monitor* __servant = dynamic_cast< ::NVSIndex::NVSIndex4Monitor*>(__direct.servant().get());
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
	    return __servant->getStreamService(MonitorID, cameraID, sSSProxy, serviceKey, __current);
	}
	catch(const ::Ice::LocalException& __ex)
	{
	    throw ::IceInternal::LocalExceptionWrapper(__ex, false);
	}
    }
}

::Ice::Byte
IceDelegateD::NVSIndex::NVSIndex4Monitor::getExternalStreamService(::Ice::Int MonitorID, ::Ice::Int cameraID, ::std::string& sSSProxy, ::Ice::Int& serviceKey, const ::Ice::Context& __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __NVSIndex__NVSIndex4Monitor__getExternalStreamService_name, ::Ice::Normal, __context);
    while(true)
    {
	::IceInternal::Direct __direct(__current);
	::NVSIndex::NVSIndex4Monitor* __servant = dynamic_cast< ::NVSIndex::NVSIndex4Monitor*>(__direct.servant().get());
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
	    return __servant->getExternalStreamService(MonitorID, cameraID, sSSProxy, serviceKey, __current);
	}
	catch(const ::Ice::LocalException& __ex)
	{
	    throw ::IceInternal::LocalExceptionWrapper(__ex, false);
	}
    }
}

void
IceDelegateD::NVSIndex::NVSIndex4Monitor::heartBeat(::Ice::Int nID, const ::Ice::Context& __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __NVSIndex__NVSIndex4Monitor__heartBeat_name, ::Ice::Normal, __context);
    while(true)
    {
	::IceInternal::Direct __direct(__current);
	::NVSIndex::NVSIndex4Monitor* __servant = dynamic_cast< ::NVSIndex::NVSIndex4Monitor*>(__direct.servant().get());
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
IceDelegateD::NVSIndex::NVSIndex4Monitor::getDvrInfo(::Ice::Int nID, ::NVSIndex::NVSDVRInfo& backInfo, const ::Ice::Context& __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __NVSIndex__NVSIndex4Monitor__getDvrInfo_name, ::Ice::Normal, __context);
    while(true)
    {
	::IceInternal::Direct __direct(__current);
	::NVSIndex::NVSIndex4Monitor* __servant = dynamic_cast< ::NVSIndex::NVSIndex4Monitor*>(__direct.servant().get());
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
	    return __servant->getDvrInfo(nID, backInfo, __current);
	}
	catch(const ::Ice::LocalException& __ex)
	{
	    throw ::IceInternal::LocalExceptionWrapper(__ex, false);
	}
    }
}

void
IceDelegateD::NVSIndex::NVSIndex4Monitor::getStreamOnline(::NVSIndex::NVSConnectStrPool& backInfo, const ::Ice::Context& __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __NVSIndex__NVSIndex4Monitor__getStreamOnline_name, ::Ice::Normal, __context);
    while(true)
    {
	::IceInternal::Direct __direct(__current);
	::NVSIndex::NVSIndex4Monitor* __servant = dynamic_cast< ::NVSIndex::NVSIndex4Monitor*>(__direct.servant().get());
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
	    __servant->getStreamOnline(backInfo, __current);
	    return;
	}
	catch(const ::Ice::LocalException& __ex)
	{
	    throw ::IceInternal::LocalExceptionWrapper(__ex, false);
	}
    }
}

::Ice::Int
IceDelegateD::NVSIndex::NVSIndex4Monitor::getControlService(::Ice::Int cameraID, ::std::string& sSSProxy, ::Ice::Int& serviceKey, const ::Ice::Context& __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __NVSIndex__NVSIndex4Monitor__getControlService_name, ::Ice::Normal, __context);
    while(true)
    {
	::IceInternal::Direct __direct(__current);
	::NVSIndex::NVSIndex4Monitor* __servant = dynamic_cast< ::NVSIndex::NVSIndex4Monitor*>(__direct.servant().get());
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
	    return __servant->getControlService(cameraID, sSSProxy, serviceKey, __current);
	}
	catch(const ::Ice::LocalException& __ex)
	{
	    throw ::IceInternal::LocalExceptionWrapper(__ex, false);
	}
    }
}

void
IceDelegateD::NVSIndex::NVSIndex4Monitor::getStreamMonitorNum(::Ice::Int& nStreamNum, ::Ice::Int& nMonitorNum, const ::Ice::Context& __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __NVSIndex__NVSIndex4Monitor__getStreamMonitorNum_name, ::Ice::Normal, __context);
    while(true)
    {
	::IceInternal::Direct __direct(__current);
	::NVSIndex::NVSIndex4Monitor* __servant = dynamic_cast< ::NVSIndex::NVSIndex4Monitor*>(__direct.servant().get());
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
	    __servant->getStreamMonitorNum(nStreamNum, nMonitorNum, __current);
	    return;
	}
	catch(const ::Ice::LocalException& __ex)
	{
	    throw ::IceInternal::LocalExceptionWrapper(__ex, false);
	}
    }
}

bool
IceDelegateD::NVSIndex::NVSIndex4Monitor::reSetServer(const ::Ice::Context& __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __NVSIndex__NVSIndex4Monitor__reSetServer_name, ::Ice::Normal, __context);
    while(true)
    {
	::IceInternal::Direct __direct(__current);
	::NVSIndex::NVSIndex4Monitor* __servant = dynamic_cast< ::NVSIndex::NVSIndex4Monitor*>(__direct.servant().get());
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
	    return __servant->reSetServer(__current);
	}
	catch(const ::Ice::LocalException& __ex)
	{
	    throw ::IceInternal::LocalExceptionWrapper(__ex, false);
	}
    }
}

bool
IceDelegateD::NVSIndex::NVSIndex4Monitor::checkNeedRebootSyn(::Ice::Int nUID, ::Ice::Int nOrgID, const ::std::string& sLastLoginTime, const ::Ice::Context& __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __NVSIndex__NVSIndex4Monitor__checkNeedRebootSyn_name, ::Ice::Normal, __context);
    while(true)
    {
	::IceInternal::Direct __direct(__current);
	::NVSIndex::NVSIndex4Monitor* __servant = dynamic_cast< ::NVSIndex::NVSIndex4Monitor*>(__direct.servant().get());
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
	    return __servant->checkNeedRebootSyn(nUID, nOrgID, sLastLoginTime, __current);
	}
	catch(const ::Ice::LocalException& __ex)
	{
	    throw ::IceInternal::LocalExceptionWrapper(__ex, false);
	}
    }
}

bool
IceDelegateD::NVSIndex::NVSIndex4Monitor::NoticeReady(::Ice::Int nID, const ::Ice::Identity& id, const ::Ice::Context& __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __NVSIndex__NVSIndex4Monitor__NoticeReady_name, ::Ice::Normal, __context);
    while(true)
    {
	::IceInternal::Direct __direct(__current);
	::NVSIndex::NVSIndex4Monitor* __servant = dynamic_cast< ::NVSIndex::NVSIndex4Monitor*>(__direct.servant().get());
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
	    return __servant->NoticeReady(nID, id, __current);
	}
	catch(const ::Ice::LocalException& __ex)
	{
	    throw ::IceInternal::LocalExceptionWrapper(__ex, false);
	}
    }
}

bool
IceDelegateD::NVSIndex::NVSIndex4Monitor::UpdateClientID(::Ice::Int nNewID, ::Ice::Int nPriorID, const ::Ice::Context& __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __NVSIndex__NVSIndex4Monitor__UpdateClientID_name, ::Ice::Normal, __context);
    while(true)
    {
	::IceInternal::Direct __direct(__current);
	::NVSIndex::NVSIndex4Monitor* __servant = dynamic_cast< ::NVSIndex::NVSIndex4Monitor*>(__direct.servant().get());
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
	    return __servant->UpdateClientID(nNewID, nPriorID, __current);
	}
	catch(const ::Ice::LocalException& __ex)
	{
	    throw ::IceInternal::LocalExceptionWrapper(__ex, false);
	}
    }
}

bool
IceDelegateD::NVSIndex::NVSIndex4Monitor::NoticeReleaseUser(::Ice::Int nID, ::Ice::Int nCameraID, const ::Ice::Context& __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __NVSIndex__NVSIndex4Monitor__NoticeReleaseUser_name, ::Ice::Normal, __context);
    while(true)
    {
	::IceInternal::Direct __direct(__current);
	::NVSIndex::NVSIndex4Monitor* __servant = dynamic_cast< ::NVSIndex::NVSIndex4Monitor*>(__direct.servant().get());
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
	    return __servant->NoticeReleaseUser(nID, nCameraID, __current);
	}
	catch(const ::Ice::LocalException& __ex)
	{
	    throw ::IceInternal::LocalExceptionWrapper(__ex, false);
	}
    }
}

bool
IceDelegateD::NVSIndex::NVSIndex4Monitor::NoticeReleaseUserAll(::Ice::Int nUserID, const ::Ice::Context& __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __NVSIndex__NVSIndex4Monitor__NoticeReleaseUserAll_name, ::Ice::Normal, __context);
    while(true)
    {
	::IceInternal::Direct __direct(__current);
	::NVSIndex::NVSIndex4Monitor* __servant = dynamic_cast< ::NVSIndex::NVSIndex4Monitor*>(__direct.servant().get());
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
	    return __servant->NoticeReleaseUserAll(nUserID, __current);
	}
	catch(const ::Ice::LocalException& __ex)
	{
	    throw ::IceInternal::LocalExceptionWrapper(__ex, false);
	}
    }
}

::std::string
IceDelegateD::NVSIndex::NVSIndex4Monitor::ConvertCameraID(::Ice::Int nCameraID, const ::Ice::Context& __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __NVSIndex__NVSIndex4Monitor__ConvertCameraID_name, ::Ice::Normal, __context);
    while(true)
    {
	::IceInternal::Direct __direct(__current);
	::NVSIndex::NVSIndex4Monitor* __servant = dynamic_cast< ::NVSIndex::NVSIndex4Monitor*>(__direct.servant().get());
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
	    return __servant->ConvertCameraID(nCameraID, __current);
	}
	catch(const ::Ice::LocalException& __ex)
	{
	    throw ::IceInternal::LocalExceptionWrapper(__ex, false);
	}
    }
}

void
IceDelegateD::NVSIndex::NVSIndex4Monitor::getSystemRunState(::NVSIndex::SystemState& ss, const ::Ice::Context& __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __NVSIndex__NVSIndex4Monitor__getSystemRunState_name, ::Ice::Normal, __context);
    while(true)
    {
	::IceInternal::Direct __direct(__current);
	::NVSIndex::NVSIndex4Monitor* __servant = dynamic_cast< ::NVSIndex::NVSIndex4Monitor*>(__direct.servant().get());
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
	    __servant->getSystemRunState(ss, __current);
	    return;
	}
	catch(const ::Ice::LocalException& __ex)
	{
	    throw ::IceInternal::LocalExceptionWrapper(__ex, false);
	}
    }
}

bool
IceDelegateD::NVSIndex::NVSIndex4Monitor::heartBeatRetVaule(::Ice::Int nID, ::Ice::Int nRight, const ::Ice::Context& __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __NVSIndex__NVSIndex4Monitor__heartBeatRetVaule_name, ::Ice::Normal, __context);
    while(true)
    {
	::IceInternal::Direct __direct(__current);
	::NVSIndex::NVSIndex4Monitor* __servant = dynamic_cast< ::NVSIndex::NVSIndex4Monitor*>(__direct.servant().get());
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
	    return __servant->heartBeatRetVaule(nID, nRight, __current);
	}
	catch(const ::Ice::LocalException& __ex)
	{
	    throw ::IceInternal::LocalExceptionWrapper(__ex, false);
	}
    }
}

::Ice::ObjectPtr
NVSIndex::NVSModel::ice_clone() const
{
    throw ::Ice::CloneNotImplementedException(__FILE__, __LINE__);
    return 0; // to avoid a warning with some compilers
}

static const ::std::string __NVSIndex__NVSModel_ids[2] =
{
    "::Ice::Object",
    "::NVSIndex::NVSModel"
};

bool
NVSIndex::NVSModel::ice_isA(const ::std::string& _s, const ::Ice::Current&) const
{
    return ::std::binary_search(__NVSIndex__NVSModel_ids, __NVSIndex__NVSModel_ids + 2, _s);
}

::std::vector< ::std::string>
NVSIndex::NVSModel::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&__NVSIndex__NVSModel_ids[0], &__NVSIndex__NVSModel_ids[2]);
}

const ::std::string&
NVSIndex::NVSModel::ice_id(const ::Ice::Current&) const
{
    return __NVSIndex__NVSModel_ids[1];
}

const ::std::string&
NVSIndex::NVSModel::ice_staticId()
{
    return __NVSIndex__NVSModel_ids[1];
}

::IceInternal::DispatchStatus
NVSIndex::NVSModel::___checkNeedReboot(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::Ice::Int nUID;
    ::Ice::Int nOrgID;
    ::std::string sLastLoginTime;
    __is->read(nUID);
    __is->read(nOrgID);
    __is->read(sLastLoginTime);
    ::NVSIndex::AMD_NVSModel_checkNeedRebootPtr __cb = new IceAsync::NVSIndex::AMD_NVSModel_checkNeedReboot(__inS);
    try
    {
	checkNeedReboot_async(__cb, nUID, nOrgID, sLastLoginTime, __current);
    }
    catch(const ::Ice::Exception& __ex)
    {
	__cb->ice_exception(__ex);
    }
    catch(const ::std::exception& __ex)
    {
	__cb->ice_exception(__ex);
    }
    catch(...)
    {
	__cb->ice_exception();
    }
    return ::IceInternal::DispatchAsync;
}

static ::std::string __NVSIndex__NVSModel_all[] =
{
    "checkNeedReboot",
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping"
};

::IceInternal::DispatchStatus
NVSIndex::NVSModel::__dispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair< ::std::string*, ::std::string*> r = ::std::equal_range(__NVSIndex__NVSModel_all, __NVSIndex__NVSModel_all + 5, current.operation);
    if(r.first == r.second)
    {
	return ::IceInternal::DispatchOperationNotExist;
    }

    switch(r.first - __NVSIndex__NVSModel_all)
    {
	case 0:
	{
	    return ___checkNeedReboot(in, current);
	}
	case 1:
	{
	    return ___ice_id(in, current);
	}
	case 2:
	{
	    return ___ice_ids(in, current);
	}
	case 3:
	{
	    return ___ice_isA(in, current);
	}
	case 4:
	{
	    return ___ice_ping(in, current);
	}
    }

    assert(false);
    return ::IceInternal::DispatchOperationNotExist;
}

void
NVSIndex::NVSModel::__write(::IceInternal::BasicStream* __os) const
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
NVSIndex::NVSModel::__read(::IceInternal::BasicStream* __is, bool __rid)
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
NVSIndex::NVSModel::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type NVSIndex::NVSModel was not generated with stream support";
    throw ex;
}

void
NVSIndex::NVSModel::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type NVSIndex::NVSModel was not generated with stream support";
    throw ex;
}

void 
NVSIndex::__patch__NVSModelPtr(void* __addr, ::Ice::ObjectPtr& v)
{
    ::NVSIndex::NVSModelPtr* p = static_cast< ::NVSIndex::NVSModelPtr*>(__addr);
    assert(p);
    *p = ::NVSIndex::NVSModelPtr::dynamicCast(v);
    if(v && !*p)
    {
	::Ice::NoObjectFactoryException e(__FILE__, __LINE__);
	e.type = ::NVSIndex::NVSModel::ice_staticId();
	throw e;
    }
}

bool
NVSIndex::operator==(const ::NVSIndex::NVSModel& l, const ::NVSIndex::NVSModel& r)
{
    return static_cast<const ::Ice::Object&>(l) == static_cast<const ::Ice::Object&>(r);
}

bool
NVSIndex::operator!=(const ::NVSIndex::NVSModel& l, const ::NVSIndex::NVSModel& r)
{
    return static_cast<const ::Ice::Object&>(l) != static_cast<const ::Ice::Object&>(r);
}

bool
NVSIndex::operator<(const ::NVSIndex::NVSModel& l, const ::NVSIndex::NVSModel& r)
{
    return static_cast<const ::Ice::Object&>(l) < static_cast<const ::Ice::Object&>(r);
}

bool
NVSIndex::operator<=(const ::NVSIndex::NVSModel& l, const ::NVSIndex::NVSModel& r)
{
    return l < r || l == r;
}

bool
NVSIndex::operator>(const ::NVSIndex::NVSModel& l, const ::NVSIndex::NVSModel& r)
{
    return !(l < r) && !(l == r);
}

bool
NVSIndex::operator>=(const ::NVSIndex::NVSModel& l, const ::NVSIndex::NVSModel& r)
{
    return !(l < r);
}

::Ice::ObjectPtr
NVSIndex::NVSIndexNotice::ice_clone() const
{
    throw ::Ice::CloneNotImplementedException(__FILE__, __LINE__);
    return 0; // to avoid a warning with some compilers
}

static const ::std::string __NVSIndex__NVSIndexNotice_ids[2] =
{
    "::Ice::Object",
    "::NVSIndex::NVSIndexNotice"
};

bool
NVSIndex::NVSIndexNotice::ice_isA(const ::std::string& _s, const ::Ice::Current&) const
{
    return ::std::binary_search(__NVSIndex__NVSIndexNotice_ids, __NVSIndex__NVSIndexNotice_ids + 2, _s);
}

::std::vector< ::std::string>
NVSIndex::NVSIndexNotice::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&__NVSIndex__NVSIndexNotice_ids[0], &__NVSIndex__NVSIndexNotice_ids[2]);
}

const ::std::string&
NVSIndex::NVSIndexNotice::ice_id(const ::Ice::Current&) const
{
    return __NVSIndex__NVSIndexNotice_ids[1];
}

const ::std::string&
NVSIndex::NVSIndexNotice::ice_staticId()
{
    return __NVSIndex__NVSIndexNotice_ids[1];
}

::IceInternal::DispatchStatus
NVSIndex::NVSIndexNotice::___notifyClient(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::NVSIndex::IndexNoticeInfo NoticeInfo;
    NoticeInfo.__read(__is);
    bool __ret = notifyClient(NoticeInfo, __current);
    __os->write(__ret);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
NVSIndex::NVSIndexNotice::___notifySwitched(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::Int nMonitorID;
    ::Ice::Int nPriorCameraID;
    ::Ice::Int nCameraID;
    ::std::string Description;
    __is->read(nMonitorID);
    __is->read(nPriorCameraID);
    __is->read(nCameraID);
    __is->read(Description);
    bool __ret = notifySwitched(nMonitorID, nPriorCameraID, nCameraID, Description, __current);
    __os->write(__ret);
    return ::IceInternal::DispatchOK;
}

static ::std::string __NVSIndex__NVSIndexNotice_all[] =
{
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping",
    "notifyClient",
    "notifySwitched"
};

::IceInternal::DispatchStatus
NVSIndex::NVSIndexNotice::__dispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair< ::std::string*, ::std::string*> r = ::std::equal_range(__NVSIndex__NVSIndexNotice_all, __NVSIndex__NVSIndexNotice_all + 6, current.operation);
    if(r.first == r.second)
    {
	return ::IceInternal::DispatchOperationNotExist;
    }

    switch(r.first - __NVSIndex__NVSIndexNotice_all)
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
	    return ___notifyClient(in, current);
	}
	case 5:
	{
	    return ___notifySwitched(in, current);
	}
    }

    assert(false);
    return ::IceInternal::DispatchOperationNotExist;
}

void
NVSIndex::NVSIndexNotice::__write(::IceInternal::BasicStream* __os) const
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
NVSIndex::NVSIndexNotice::__read(::IceInternal::BasicStream* __is, bool __rid)
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
NVSIndex::NVSIndexNotice::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type NVSIndex::NVSIndexNotice was not generated with stream support";
    throw ex;
}

void
NVSIndex::NVSIndexNotice::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type NVSIndex::NVSIndexNotice was not generated with stream support";
    throw ex;
}

void 
NVSIndex::__patch__NVSIndexNoticePtr(void* __addr, ::Ice::ObjectPtr& v)
{
    ::NVSIndex::NVSIndexNoticePtr* p = static_cast< ::NVSIndex::NVSIndexNoticePtr*>(__addr);
    assert(p);
    *p = ::NVSIndex::NVSIndexNoticePtr::dynamicCast(v);
    if(v && !*p)
    {
	::Ice::NoObjectFactoryException e(__FILE__, __LINE__);
	e.type = ::NVSIndex::NVSIndexNotice::ice_staticId();
	throw e;
    }
}

bool
NVSIndex::operator==(const ::NVSIndex::NVSIndexNotice& l, const ::NVSIndex::NVSIndexNotice& r)
{
    return static_cast<const ::Ice::Object&>(l) == static_cast<const ::Ice::Object&>(r);
}

bool
NVSIndex::operator!=(const ::NVSIndex::NVSIndexNotice& l, const ::NVSIndex::NVSIndexNotice& r)
{
    return static_cast<const ::Ice::Object&>(l) != static_cast<const ::Ice::Object&>(r);
}

bool
NVSIndex::operator<(const ::NVSIndex::NVSIndexNotice& l, const ::NVSIndex::NVSIndexNotice& r)
{
    return static_cast<const ::Ice::Object&>(l) < static_cast<const ::Ice::Object&>(r);
}

bool
NVSIndex::operator<=(const ::NVSIndex::NVSIndexNotice& l, const ::NVSIndex::NVSIndexNotice& r)
{
    return l < r || l == r;
}

bool
NVSIndex::operator>(const ::NVSIndex::NVSIndexNotice& l, const ::NVSIndex::NVSIndexNotice& r)
{
    return !(l < r) && !(l == r);
}

bool
NVSIndex::operator>=(const ::NVSIndex::NVSIndexNotice& l, const ::NVSIndex::NVSIndexNotice& r)
{
    return !(l < r);
}

::Ice::ObjectPtr
NVSIndex::NVSIndex4Monitor::ice_clone() const
{
    throw ::Ice::CloneNotImplementedException(__FILE__, __LINE__);
    return 0; // to avoid a warning with some compilers
}

static const ::std::string __NVSIndex__NVSIndex4Monitor_ids[2] =
{
    "::Ice::Object",
    "::NVSIndex::NVSIndex4Monitor"
};

bool
NVSIndex::NVSIndex4Monitor::ice_isA(const ::std::string& _s, const ::Ice::Current&) const
{
    return ::std::binary_search(__NVSIndex__NVSIndex4Monitor_ids, __NVSIndex__NVSIndex4Monitor_ids + 2, _s);
}

::std::vector< ::std::string>
NVSIndex::NVSIndex4Monitor::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&__NVSIndex__NVSIndex4Monitor_ids[0], &__NVSIndex__NVSIndex4Monitor_ids[2]);
}

const ::std::string&
NVSIndex::NVSIndex4Monitor::ice_id(const ::Ice::Current&) const
{
    return __NVSIndex__NVSIndex4Monitor_ids[1];
}

const ::std::string&
NVSIndex::NVSIndex4Monitor::ice_staticId()
{
    return __NVSIndex__NVSIndex4Monitor_ids[1];
}

::IceInternal::DispatchStatus
NVSIndex::NVSIndex4Monitor::___registerMe(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::NVSIndex::NVSMonitorInfo outInfo;
    outInfo.__read(__is);
    ::NVSIndex::NVSMonitorInfo backInfo;
    bool __ret = registerMe(outInfo, backInfo, __current);
    backInfo.__write(__os);
    __os->write(__ret);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
NVSIndex::NVSIndex4Monitor::___getStreamService(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::Int MonitorID;
    ::Ice::Int cameraID;
    __is->read(MonitorID);
    __is->read(cameraID);
    ::std::string sSSProxy;
    ::Ice::Int serviceKey;
    ::Ice::Byte __ret = getStreamService(MonitorID, cameraID, sSSProxy, serviceKey, __current);
    __os->write(sSSProxy);
    __os->write(serviceKey);
    __os->write(__ret);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
NVSIndex::NVSIndex4Monitor::___getExternalStreamService(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::Int MonitorID;
    ::Ice::Int cameraID;
    __is->read(MonitorID);
    __is->read(cameraID);
    ::std::string sSSProxy;
    ::Ice::Int serviceKey;
    ::Ice::Byte __ret = getExternalStreamService(MonitorID, cameraID, sSSProxy, serviceKey, __current);
    __os->write(sSSProxy);
    __os->write(serviceKey);
    __os->write(__ret);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
NVSIndex::NVSIndex4Monitor::___heartBeat(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::Ice::Int nID;
    __is->read(nID);
    heartBeat(nID, __current);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
NVSIndex::NVSIndex4Monitor::___getDvrInfo(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::Int nID;
    __is->read(nID);
    ::NVSIndex::NVSDVRInfo backInfo;
    bool __ret = getDvrInfo(nID, backInfo, __current);
    backInfo.__write(__os);
    __os->write(__ret);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
NVSIndex::NVSIndex4Monitor::___getStreamOnline(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __os = __inS.os();
    ::NVSIndex::NVSConnectStrPool backInfo;
    getStreamOnline(backInfo, __current);
    if(backInfo.size() == 0)
    {
	__os->writeSize(0);
    }
    else
    {
	__os->write(&backInfo[0], &backInfo[0] + backInfo.size());
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
NVSIndex::NVSIndex4Monitor::___getControlService(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::Int cameraID;
    __is->read(cameraID);
    ::std::string sSSProxy;
    ::Ice::Int serviceKey;
    ::Ice::Int __ret = getControlService(cameraID, sSSProxy, serviceKey, __current);
    __os->write(sSSProxy);
    __os->write(serviceKey);
    __os->write(__ret);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
NVSIndex::NVSIndex4Monitor::___getStreamMonitorNum(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::Int nStreamNum;
    ::Ice::Int nMonitorNum;
    getStreamMonitorNum(nStreamNum, nMonitorNum, __current);
    __os->write(nStreamNum);
    __os->write(nMonitorNum);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
NVSIndex::NVSIndex4Monitor::___reSetServer(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __os = __inS.os();
    bool __ret = reSetServer(__current);
    __os->write(__ret);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
NVSIndex::NVSIndex4Monitor::___checkNeedRebootSyn(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::Int nUID;
    ::Ice::Int nOrgID;
    ::std::string sLastLoginTime;
    __is->read(nUID);
    __is->read(nOrgID);
    __is->read(sLastLoginTime);
    bool __ret = checkNeedRebootSyn(nUID, nOrgID, sLastLoginTime, __current);
    __os->write(__ret);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
NVSIndex::NVSIndex4Monitor::___NoticeReady(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::Int nID;
    ::Ice::Identity id;
    __is->read(nID);
    id.__read(__is);
    bool __ret = NoticeReady(nID, id, __current);
    __os->write(__ret);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
NVSIndex::NVSIndex4Monitor::___UpdateClientID(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::Int nNewID;
    ::Ice::Int nPriorID;
    __is->read(nNewID);
    __is->read(nPriorID);
    bool __ret = UpdateClientID(nNewID, nPriorID, __current);
    __os->write(__ret);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
NVSIndex::NVSIndex4Monitor::___NoticeReleaseUser(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::Int nID;
    ::Ice::Int nCameraID;
    __is->read(nID);
    __is->read(nCameraID);
    bool __ret = NoticeReleaseUser(nID, nCameraID, __current);
    __os->write(__ret);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
NVSIndex::NVSIndex4Monitor::___NoticeReleaseUserAll(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::Int nUserID;
    __is->read(nUserID);
    bool __ret = NoticeReleaseUserAll(nUserID, __current);
    __os->write(__ret);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
NVSIndex::NVSIndex4Monitor::___ConvertCameraID(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::Int nCameraID;
    __is->read(nCameraID);
    ::std::string __ret = ConvertCameraID(nCameraID, __current);
    __os->write(__ret);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
NVSIndex::NVSIndex4Monitor::___getSystemRunState(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __os = __inS.os();
    ::NVSIndex::SystemState ss;
    getSystemRunState(ss, __current);
    ss.__write(__os);
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
NVSIndex::NVSIndex4Monitor::___heartBeatRetVaule(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::Int nID;
    ::Ice::Int nRight;
    __is->read(nID);
    __is->read(nRight);
    bool __ret = heartBeatRetVaule(nID, nRight, __current);
    __os->write(__ret);
    return ::IceInternal::DispatchOK;
}

static ::std::string __NVSIndex__NVSIndex4Monitor_all[] =
{
    "ConvertCameraID",
    "NoticeReady",
    "NoticeReleaseUser",
    "NoticeReleaseUserAll",
    "UpdateClientID",
    "checkNeedRebootSyn",
    "getControlService",
    "getDvrInfo",
    "getExternalStreamService",
    "getStreamMonitorNum",
    "getStreamOnline",
    "getStreamService",
    "getSystemRunState",
    "heartBeat",
    "heartBeatRetVaule",
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping",
    "reSetServer",
    "registerMe"
};

::IceInternal::DispatchStatus
NVSIndex::NVSIndex4Monitor::__dispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair< ::std::string*, ::std::string*> r = ::std::equal_range(__NVSIndex__NVSIndex4Monitor_all, __NVSIndex__NVSIndex4Monitor_all + 21, current.operation);
    if(r.first == r.second)
    {
	return ::IceInternal::DispatchOperationNotExist;
    }

    switch(r.first - __NVSIndex__NVSIndex4Monitor_all)
    {
	case 0:
	{
	    return ___ConvertCameraID(in, current);
	}
	case 1:
	{
	    return ___NoticeReady(in, current);
	}
	case 2:
	{
	    return ___NoticeReleaseUser(in, current);
	}
	case 3:
	{
	    return ___NoticeReleaseUserAll(in, current);
	}
	case 4:
	{
	    return ___UpdateClientID(in, current);
	}
	case 5:
	{
	    return ___checkNeedRebootSyn(in, current);
	}
	case 6:
	{
	    return ___getControlService(in, current);
	}
	case 7:
	{
	    return ___getDvrInfo(in, current);
	}
	case 8:
	{
	    return ___getExternalStreamService(in, current);
	}
	case 9:
	{
	    return ___getStreamMonitorNum(in, current);
	}
	case 10:
	{
	    return ___getStreamOnline(in, current);
	}
	case 11:
	{
	    return ___getStreamService(in, current);
	}
	case 12:
	{
	    return ___getSystemRunState(in, current);
	}
	case 13:
	{
	    return ___heartBeat(in, current);
	}
	case 14:
	{
	    return ___heartBeatRetVaule(in, current);
	}
	case 15:
	{
	    return ___ice_id(in, current);
	}
	case 16:
	{
	    return ___ice_ids(in, current);
	}
	case 17:
	{
	    return ___ice_isA(in, current);
	}
	case 18:
	{
	    return ___ice_ping(in, current);
	}
	case 19:
	{
	    return ___reSetServer(in, current);
	}
	case 20:
	{
	    return ___registerMe(in, current);
	}
    }

    assert(false);
    return ::IceInternal::DispatchOperationNotExist;
}

void
NVSIndex::NVSIndex4Monitor::__write(::IceInternal::BasicStream* __os) const
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
NVSIndex::NVSIndex4Monitor::__read(::IceInternal::BasicStream* __is, bool __rid)
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
NVSIndex::NVSIndex4Monitor::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type NVSIndex::NVSIndex4Monitor was not generated with stream support";
    throw ex;
}

void
NVSIndex::NVSIndex4Monitor::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type NVSIndex::NVSIndex4Monitor was not generated with stream support";
    throw ex;
}

void 
NVSIndex::__patch__NVSIndex4MonitorPtr(void* __addr, ::Ice::ObjectPtr& v)
{
    ::NVSIndex::NVSIndex4MonitorPtr* p = static_cast< ::NVSIndex::NVSIndex4MonitorPtr*>(__addr);
    assert(p);
    *p = ::NVSIndex::NVSIndex4MonitorPtr::dynamicCast(v);
    if(v && !*p)
    {
	::Ice::NoObjectFactoryException e(__FILE__, __LINE__);
	e.type = ::NVSIndex::NVSIndex4Monitor::ice_staticId();
	throw e;
    }
}

bool
NVSIndex::operator==(const ::NVSIndex::NVSIndex4Monitor& l, const ::NVSIndex::NVSIndex4Monitor& r)
{
    return static_cast<const ::Ice::Object&>(l) == static_cast<const ::Ice::Object&>(r);
}

bool
NVSIndex::operator!=(const ::NVSIndex::NVSIndex4Monitor& l, const ::NVSIndex::NVSIndex4Monitor& r)
{
    return static_cast<const ::Ice::Object&>(l) != static_cast<const ::Ice::Object&>(r);
}

bool
NVSIndex::operator<(const ::NVSIndex::NVSIndex4Monitor& l, const ::NVSIndex::NVSIndex4Monitor& r)
{
    return static_cast<const ::Ice::Object&>(l) < static_cast<const ::Ice::Object&>(r);
}

bool
NVSIndex::operator<=(const ::NVSIndex::NVSIndex4Monitor& l, const ::NVSIndex::NVSIndex4Monitor& r)
{
    return l < r || l == r;
}

bool
NVSIndex::operator>(const ::NVSIndex::NVSIndex4Monitor& l, const ::NVSIndex::NVSIndex4Monitor& r)
{
    return !(l < r) && !(l == r);
}

bool
NVSIndex::operator>=(const ::NVSIndex::NVSIndex4Monitor& l, const ::NVSIndex::NVSIndex4Monitor& r)
{
    return !(l < r);
}
