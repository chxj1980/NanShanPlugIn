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

#ifndef _____ICE_NVSIndex4Monitor_h__
#define _____ICE_NVSIndex4Monitor_h__

#include <Ice/LocalObjectF.h>
#include <Ice/ProxyF.h>
#include <Ice/ObjectF.h>
#include <Ice/Exception.h>
#include <Ice/LocalObject.h>
#include <Ice/Proxy.h>
#include <Ice/Object.h>
#include <Ice/Outgoing.h>
#include <Ice/OutgoingAsync.h>
#include <Ice/Incoming.h>
#include <Ice/IncomingAsync.h>
#include <Ice/Direct.h>
#include <Ice/UserExceptionFactory.h>
#include <Ice/FactoryTable.h>
#include <Ice/StreamF.h>
#include <Ice/Identity.h>
#include <Ice/UndefSysMacros.h>
#include "NVSIndexData.h"

#ifndef ICE_IGNORE_VERSION
#   if ICE_INT_VERSION / 100 != 301
#       error Ice version mismatch!
#   endif
#   if ICE_INT_VERSION % 100 < 1
#       error Ice patch level mismatch!
#   endif
#endif

namespace IceProxy
{

namespace NVSIndex
{

class NVSModel;
bool operator==(const NVSModel&, const NVSModel&);
bool operator!=(const NVSModel&, const NVSModel&);
bool operator<(const NVSModel&, const NVSModel&);
bool operator<=(const NVSModel&, const NVSModel&);
bool operator>(const NVSModel&, const NVSModel&);
bool operator>=(const NVSModel&, const NVSModel&);

class NVSIndexNotice;
bool operator==(const NVSIndexNotice&, const NVSIndexNotice&);
bool operator!=(const NVSIndexNotice&, const NVSIndexNotice&);
bool operator<(const NVSIndexNotice&, const NVSIndexNotice&);
bool operator<=(const NVSIndexNotice&, const NVSIndexNotice&);
bool operator>(const NVSIndexNotice&, const NVSIndexNotice&);
bool operator>=(const NVSIndexNotice&, const NVSIndexNotice&);

class NVSIndex4Monitor;
bool operator==(const NVSIndex4Monitor&, const NVSIndex4Monitor&);
bool operator!=(const NVSIndex4Monitor&, const NVSIndex4Monitor&);
bool operator<(const NVSIndex4Monitor&, const NVSIndex4Monitor&);
bool operator<=(const NVSIndex4Monitor&, const NVSIndex4Monitor&);
bool operator>(const NVSIndex4Monitor&, const NVSIndex4Monitor&);
bool operator>=(const NVSIndex4Monitor&, const NVSIndex4Monitor&);

}

}

namespace NVSIndex
{

class NVSModel;
bool operator==(const NVSModel&, const NVSModel&);
bool operator!=(const NVSModel&, const NVSModel&);
bool operator<(const NVSModel&, const NVSModel&);
bool operator<=(const NVSModel&, const NVSModel&);
bool operator>(const NVSModel&, const NVSModel&);
bool operator>=(const NVSModel&, const NVSModel&);

class NVSIndexNotice;
bool operator==(const NVSIndexNotice&, const NVSIndexNotice&);
bool operator!=(const NVSIndexNotice&, const NVSIndexNotice&);
bool operator<(const NVSIndexNotice&, const NVSIndexNotice&);
bool operator<=(const NVSIndexNotice&, const NVSIndexNotice&);
bool operator>(const NVSIndexNotice&, const NVSIndexNotice&);
bool operator>=(const NVSIndexNotice&, const NVSIndexNotice&);

class NVSIndex4Monitor;
bool operator==(const NVSIndex4Monitor&, const NVSIndex4Monitor&);
bool operator!=(const NVSIndex4Monitor&, const NVSIndex4Monitor&);
bool operator<(const NVSIndex4Monitor&, const NVSIndex4Monitor&);
bool operator<=(const NVSIndex4Monitor&, const NVSIndex4Monitor&);
bool operator>(const NVSIndex4Monitor&, const NVSIndex4Monitor&);
bool operator>=(const NVSIndex4Monitor&, const NVSIndex4Monitor&);

}

namespace IceInternal
{

void incRef(::NVSIndex::NVSModel*);
void decRef(::NVSIndex::NVSModel*);

void incRef(::IceProxy::NVSIndex::NVSModel*);
void decRef(::IceProxy::NVSIndex::NVSModel*);

void incRef(::NVSIndex::NVSIndexNotice*);
void decRef(::NVSIndex::NVSIndexNotice*);

void incRef(::IceProxy::NVSIndex::NVSIndexNotice*);
void decRef(::IceProxy::NVSIndex::NVSIndexNotice*);

void incRef(::NVSIndex::NVSIndex4Monitor*);
void decRef(::NVSIndex::NVSIndex4Monitor*);

void incRef(::IceProxy::NVSIndex::NVSIndex4Monitor*);
void decRef(::IceProxy::NVSIndex::NVSIndex4Monitor*);

}

namespace NVSIndex
{

typedef ::IceInternal::Handle< ::NVSIndex::NVSModel> NVSModelPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::NVSIndex::NVSModel> NVSModelPrx;

void __write(::IceInternal::BasicStream*, const NVSModelPrx&);
void __read(::IceInternal::BasicStream*, NVSModelPrx&);
void __write(::IceInternal::BasicStream*, const NVSModelPtr&);
void __patch__NVSModelPtr(void*, ::Ice::ObjectPtr&);

typedef ::IceInternal::Handle< ::NVSIndex::NVSIndexNotice> NVSIndexNoticePtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::NVSIndex::NVSIndexNotice> NVSIndexNoticePrx;

void __write(::IceInternal::BasicStream*, const NVSIndexNoticePrx&);
void __read(::IceInternal::BasicStream*, NVSIndexNoticePrx&);
void __write(::IceInternal::BasicStream*, const NVSIndexNoticePtr&);
void __patch__NVSIndexNoticePtr(void*, ::Ice::ObjectPtr&);

typedef ::IceInternal::Handle< ::NVSIndex::NVSIndex4Monitor> NVSIndex4MonitorPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::NVSIndex::NVSIndex4Monitor> NVSIndex4MonitorPrx;

void __write(::IceInternal::BasicStream*, const NVSIndex4MonitorPrx&);
void __read(::IceInternal::BasicStream*, NVSIndex4MonitorPrx&);
void __write(::IceInternal::BasicStream*, const NVSIndex4MonitorPtr&);
void __patch__NVSIndex4MonitorPtr(void*, ::Ice::ObjectPtr&);

}

namespace NVSIndex
{

class RangeError : public ::Ice::UserException
{
public:

    RangeError() {}

    virtual const ::std::string ice_name() const;
    virtual ::Ice::Exception* ice_clone() const;
    virtual void ice_throw() const;

    static const ::IceInternal::UserExceptionFactoryPtr& ice_factory();

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);

    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

static RangeError __RangeError_init;

struct IndexNoticeInfo
{
    ::Ice::Int nUserID;
    ::Ice::Int nChangeType;
    ::Ice::Int nLimitTime;

    bool operator==(const IndexNoticeInfo&) const;
    bool operator!=(const IndexNoticeInfo&) const;
    bool operator<(const IndexNoticeInfo&) const;
    bool operator<=(const IndexNoticeInfo& __rhs) const
    {
	return operator<(__rhs) || operator==(__rhs);
    }
    bool operator>(const IndexNoticeInfo& __rhs) const
    {
	return !operator<(__rhs) && !operator==(__rhs);
    }
    bool operator>=(const IndexNoticeInfo& __rhs) const
    {
	return !operator<(__rhs);
    }

    void __write(::IceInternal::BasicStream*) const;
    void __read(::IceInternal::BasicStream*);
};

}

namespace NVSIndex
{

class AMI_NVSModel_checkNeedReboot : public ::IceInternal::OutgoingAsync
{
public:

    virtual void ice_response(::Ice::Int) = 0;
    virtual void ice_exception(const ::Ice::Exception&) = 0;

    void __invoke(const ::NVSIndex::NVSModelPrx&, ::Ice::Int, ::Ice::Int, const ::std::string&, const ::Ice::Context&);

protected:

    virtual void __response(bool);
};

typedef ::IceUtil::Handle< ::NVSIndex::AMI_NVSModel_checkNeedReboot> AMI_NVSModel_checkNeedRebootPtr;

class AMD_NVSModel_checkNeedReboot : virtual public ::IceUtil::Shared
{
public:

    virtual void ice_response(::Ice::Int) = 0;
    virtual void ice_exception(const ::Ice::Exception&) = 0;
    virtual void ice_exception(const ::std::exception&) = 0;
    virtual void ice_exception() = 0;
};

typedef ::IceUtil::Handle< ::NVSIndex::AMD_NVSModel_checkNeedReboot> AMD_NVSModel_checkNeedRebootPtr;

class AMI_NVSIndexNotice_notifyClient : public ::IceInternal::OutgoingAsync
{
public:

    virtual void ice_response(bool) = 0;
    virtual void ice_exception(const ::Ice::Exception&) = 0;

    void __invoke(const ::NVSIndex::NVSIndexNoticePrx&, const ::NVSIndex::IndexNoticeInfo&, const ::Ice::Context&);

protected:

    virtual void __response(bool);
};

typedef ::IceUtil::Handle< ::NVSIndex::AMI_NVSIndexNotice_notifyClient> AMI_NVSIndexNotice_notifyClientPtr;

class AMI_NVSIndexNotice_notifySwitched : public ::IceInternal::OutgoingAsync
{
public:

    virtual void ice_response(bool) = 0;
    virtual void ice_exception(const ::Ice::Exception&) = 0;

    void __invoke(const ::NVSIndex::NVSIndexNoticePrx&, ::Ice::Int, ::Ice::Int, ::Ice::Int, const ::std::string&, const ::Ice::Context&);

protected:

    virtual void __response(bool);
};

typedef ::IceUtil::Handle< ::NVSIndex::AMI_NVSIndexNotice_notifySwitched> AMI_NVSIndexNotice_notifySwitchedPtr;

}

namespace IceAsync
{

namespace NVSIndex
{

class AMD_NVSModel_checkNeedReboot : public ::NVSIndex::AMD_NVSModel_checkNeedReboot, public ::IceInternal::IncomingAsync
{
public:

    AMD_NVSModel_checkNeedReboot(::IceInternal::Incoming&);

    virtual void ice_response(::Ice::Int);
    virtual void ice_exception(const ::Ice::Exception&);
    virtual void ice_exception(const ::std::exception&);
    virtual void ice_exception();
};

}

}

namespace IceProxy
{

namespace NVSIndex
{

class NVSModel : virtual public ::IceProxy::Ice::Object
{
public:

    ::Ice::Int checkNeedReboot(::Ice::Int nUID, ::Ice::Int nOrgID, const ::std::string& sLastLoginTime)
    {
	return checkNeedReboot(nUID, nOrgID, sLastLoginTime, __defaultContext());
    }
    ::Ice::Int checkNeedReboot(::Ice::Int, ::Ice::Int, const ::std::string&, const ::Ice::Context&);
    void checkNeedReboot_async(const ::NVSIndex::AMI_NVSModel_checkNeedRebootPtr&, ::Ice::Int, ::Ice::Int, const ::std::string&);
    void checkNeedReboot_async(const ::NVSIndex::AMI_NVSModel_checkNeedRebootPtr&, ::Ice::Int, ::Ice::Int, const ::std::string&, const ::Ice::Context&);
    
    static const ::std::string& ice_staticId();

private: 

    virtual ::IceInternal::Handle< ::IceDelegateM::Ice::Object> __createDelegateM();
    virtual ::IceInternal::Handle< ::IceDelegateD::Ice::Object> __createDelegateD();
};

class NVSIndexNotice : virtual public ::IceProxy::Ice::Object
{
public:

    bool notifyClient(const ::NVSIndex::IndexNoticeInfo& NoticeInfo)
    {
	return notifyClient(NoticeInfo, __defaultContext());
    }
    bool notifyClient(const ::NVSIndex::IndexNoticeInfo&, const ::Ice::Context&);
    void notifyClient_async(const ::NVSIndex::AMI_NVSIndexNotice_notifyClientPtr&, const ::NVSIndex::IndexNoticeInfo&);
    void notifyClient_async(const ::NVSIndex::AMI_NVSIndexNotice_notifyClientPtr&, const ::NVSIndex::IndexNoticeInfo&, const ::Ice::Context&);

    bool notifySwitched(::Ice::Int nMonitorID, ::Ice::Int nPriorCameraID, ::Ice::Int nCameraID, const ::std::string& Description)
    {
	return notifySwitched(nMonitorID, nPriorCameraID, nCameraID, Description, __defaultContext());
    }
    bool notifySwitched(::Ice::Int, ::Ice::Int, ::Ice::Int, const ::std::string&, const ::Ice::Context&);
    void notifySwitched_async(const ::NVSIndex::AMI_NVSIndexNotice_notifySwitchedPtr&, ::Ice::Int, ::Ice::Int, ::Ice::Int, const ::std::string&);
    void notifySwitched_async(const ::NVSIndex::AMI_NVSIndexNotice_notifySwitchedPtr&, ::Ice::Int, ::Ice::Int, ::Ice::Int, const ::std::string&, const ::Ice::Context&);
    
    static const ::std::string& ice_staticId();

private: 

    virtual ::IceInternal::Handle< ::IceDelegateM::Ice::Object> __createDelegateM();
    virtual ::IceInternal::Handle< ::IceDelegateD::Ice::Object> __createDelegateD();
};

class NVSIndex4Monitor : virtual public ::IceProxy::Ice::Object
{
public:

    bool registerMe(const ::NVSIndex::NVSMonitorInfo& outInfo, ::NVSIndex::NVSMonitorInfo& backInfo)
    {
	return registerMe(outInfo, backInfo, __defaultContext());
    }
    bool registerMe(const ::NVSIndex::NVSMonitorInfo&, ::NVSIndex::NVSMonitorInfo&, const ::Ice::Context&);

    ::Ice::Byte getStreamService(::Ice::Int MonitorID, ::Ice::Int cameraID, ::std::string& sSSProxy, ::Ice::Int& serviceKey)
    {
	return getStreamService(MonitorID, cameraID, sSSProxy, serviceKey, __defaultContext());
    }
    ::Ice::Byte getStreamService(::Ice::Int, ::Ice::Int, ::std::string&, ::Ice::Int&, const ::Ice::Context&);

    ::Ice::Byte getExternalStreamService(::Ice::Int MonitorID, ::Ice::Int cameraID, ::std::string& sSSProxy, ::Ice::Int& serviceKey)
    {
	return getExternalStreamService(MonitorID, cameraID, sSSProxy, serviceKey, __defaultContext());
    }
    ::Ice::Byte getExternalStreamService(::Ice::Int, ::Ice::Int, ::std::string&, ::Ice::Int&, const ::Ice::Context&);

    void heartBeat(::Ice::Int nID)
    {
	heartBeat(nID, __defaultContext());
    }
    void heartBeat(::Ice::Int, const ::Ice::Context&);

    bool getDvrInfo(::Ice::Int nID, ::NVSIndex::NVSDVRInfo& backInfo)
    {
	return getDvrInfo(nID, backInfo, __defaultContext());
    }
    bool getDvrInfo(::Ice::Int, ::NVSIndex::NVSDVRInfo&, const ::Ice::Context&);

    void getStreamOnline(::NVSIndex::NVSConnectStrPool& backInfo)
    {
	getStreamOnline(backInfo, __defaultContext());
    }
    void getStreamOnline(::NVSIndex::NVSConnectStrPool&, const ::Ice::Context&);

    ::Ice::Int getControlService(::Ice::Int cameraID, ::std::string& sSSProxy, ::Ice::Int& serviceKey)
    {
	return getControlService(cameraID, sSSProxy, serviceKey, __defaultContext());
    }
    ::Ice::Int getControlService(::Ice::Int, ::std::string&, ::Ice::Int&, const ::Ice::Context&);

    void getStreamMonitorNum(::Ice::Int& nStreamNum, ::Ice::Int& nMonitorNum)
    {
	getStreamMonitorNum(nStreamNum, nMonitorNum, __defaultContext());
    }
    void getStreamMonitorNum(::Ice::Int&, ::Ice::Int&, const ::Ice::Context&);

    bool reSetServer()
    {
	return reSetServer(__defaultContext());
    }
    bool reSetServer(const ::Ice::Context&);

    bool checkNeedRebootSyn(::Ice::Int nUID, ::Ice::Int nOrgID, const ::std::string& sLastLoginTime)
    {
	return checkNeedRebootSyn(nUID, nOrgID, sLastLoginTime, __defaultContext());
    }
    bool checkNeedRebootSyn(::Ice::Int, ::Ice::Int, const ::std::string&, const ::Ice::Context&);

    bool NoticeReady(::Ice::Int nID, const ::Ice::Identity& id)
    {
	return NoticeReady(nID, id, __defaultContext());
    }
    bool NoticeReady(::Ice::Int, const ::Ice::Identity&, const ::Ice::Context&);

    bool UpdateClientID(::Ice::Int nNewID, ::Ice::Int nPriorID)
    {
	return UpdateClientID(nNewID, nPriorID, __defaultContext());
    }
    bool UpdateClientID(::Ice::Int, ::Ice::Int, const ::Ice::Context&);

    bool NoticeReleaseUser(::Ice::Int nID, ::Ice::Int nCameraID)
    {
	return NoticeReleaseUser(nID, nCameraID, __defaultContext());
    }
    bool NoticeReleaseUser(::Ice::Int, ::Ice::Int, const ::Ice::Context&);

    bool NoticeReleaseUserAll(::Ice::Int nUserID)
    {
	return NoticeReleaseUserAll(nUserID, __defaultContext());
    }
    bool NoticeReleaseUserAll(::Ice::Int, const ::Ice::Context&);

    ::std::string ConvertCameraID(::Ice::Int nCameraID)
    {
	return ConvertCameraID(nCameraID, __defaultContext());
    }
    ::std::string ConvertCameraID(::Ice::Int, const ::Ice::Context&);

    void getSystemRunState(::NVSIndex::SystemState& ss)
    {
	getSystemRunState(ss, __defaultContext());
    }
    void getSystemRunState(::NVSIndex::SystemState&, const ::Ice::Context&);

    bool heartBeatRetVaule(::Ice::Int nID, ::Ice::Int nRight)
    {
	return heartBeatRetVaule(nID, nRight, __defaultContext());
    }
    bool heartBeatRetVaule(::Ice::Int, ::Ice::Int, const ::Ice::Context&);
    
    static const ::std::string& ice_staticId();

private: 

    virtual ::IceInternal::Handle< ::IceDelegateM::Ice::Object> __createDelegateM();
    virtual ::IceInternal::Handle< ::IceDelegateD::Ice::Object> __createDelegateD();
};

}

}

namespace IceDelegate
{

namespace NVSIndex
{

class NVSModel : virtual public ::IceDelegate::Ice::Object
{
public:

    virtual ::Ice::Int checkNeedReboot(::Ice::Int, ::Ice::Int, const ::std::string&, const ::Ice::Context&) = 0;
};

class NVSIndexNotice : virtual public ::IceDelegate::Ice::Object
{
public:

    virtual bool notifyClient(const ::NVSIndex::IndexNoticeInfo&, const ::Ice::Context&) = 0;

    virtual bool notifySwitched(::Ice::Int, ::Ice::Int, ::Ice::Int, const ::std::string&, const ::Ice::Context&) = 0;
};

class NVSIndex4Monitor : virtual public ::IceDelegate::Ice::Object
{
public:

    virtual bool registerMe(const ::NVSIndex::NVSMonitorInfo&, ::NVSIndex::NVSMonitorInfo&, const ::Ice::Context&) = 0;

    virtual ::Ice::Byte getStreamService(::Ice::Int, ::Ice::Int, ::std::string&, ::Ice::Int&, const ::Ice::Context&) = 0;

    virtual ::Ice::Byte getExternalStreamService(::Ice::Int, ::Ice::Int, ::std::string&, ::Ice::Int&, const ::Ice::Context&) = 0;

    virtual void heartBeat(::Ice::Int, const ::Ice::Context&) = 0;

    virtual bool getDvrInfo(::Ice::Int, ::NVSIndex::NVSDVRInfo&, const ::Ice::Context&) = 0;

    virtual void getStreamOnline(::NVSIndex::NVSConnectStrPool&, const ::Ice::Context&) = 0;

    virtual ::Ice::Int getControlService(::Ice::Int, ::std::string&, ::Ice::Int&, const ::Ice::Context&) = 0;

    virtual void getStreamMonitorNum(::Ice::Int&, ::Ice::Int&, const ::Ice::Context&) = 0;

    virtual bool reSetServer(const ::Ice::Context&) = 0;

    virtual bool checkNeedRebootSyn(::Ice::Int, ::Ice::Int, const ::std::string&, const ::Ice::Context&) = 0;

    virtual bool NoticeReady(::Ice::Int, const ::Ice::Identity&, const ::Ice::Context&) = 0;

    virtual bool UpdateClientID(::Ice::Int, ::Ice::Int, const ::Ice::Context&) = 0;

    virtual bool NoticeReleaseUser(::Ice::Int, ::Ice::Int, const ::Ice::Context&) = 0;

    virtual bool NoticeReleaseUserAll(::Ice::Int, const ::Ice::Context&) = 0;

    virtual ::std::string ConvertCameraID(::Ice::Int, const ::Ice::Context&) = 0;

    virtual void getSystemRunState(::NVSIndex::SystemState&, const ::Ice::Context&) = 0;

    virtual bool heartBeatRetVaule(::Ice::Int, ::Ice::Int, const ::Ice::Context&) = 0;
};

}

}

namespace IceDelegateM
{

namespace NVSIndex
{

class NVSModel : virtual public ::IceDelegate::NVSIndex::NVSModel,
		 virtual public ::IceDelegateM::Ice::Object
{
public:

    virtual ::Ice::Int checkNeedReboot(::Ice::Int, ::Ice::Int, const ::std::string&, const ::Ice::Context&);
};

class NVSIndexNotice : virtual public ::IceDelegate::NVSIndex::NVSIndexNotice,
		       virtual public ::IceDelegateM::Ice::Object
{
public:

    virtual bool notifyClient(const ::NVSIndex::IndexNoticeInfo&, const ::Ice::Context&);

    virtual bool notifySwitched(::Ice::Int, ::Ice::Int, ::Ice::Int, const ::std::string&, const ::Ice::Context&);
};

class NVSIndex4Monitor : virtual public ::IceDelegate::NVSIndex::NVSIndex4Monitor,
			 virtual public ::IceDelegateM::Ice::Object
{
public:

    virtual bool registerMe(const ::NVSIndex::NVSMonitorInfo&, ::NVSIndex::NVSMonitorInfo&, const ::Ice::Context&);

    virtual ::Ice::Byte getStreamService(::Ice::Int, ::Ice::Int, ::std::string&, ::Ice::Int&, const ::Ice::Context&);

    virtual ::Ice::Byte getExternalStreamService(::Ice::Int, ::Ice::Int, ::std::string&, ::Ice::Int&, const ::Ice::Context&);

    virtual void heartBeat(::Ice::Int, const ::Ice::Context&);

    virtual bool getDvrInfo(::Ice::Int, ::NVSIndex::NVSDVRInfo&, const ::Ice::Context&);

    virtual void getStreamOnline(::NVSIndex::NVSConnectStrPool&, const ::Ice::Context&);

    virtual ::Ice::Int getControlService(::Ice::Int, ::std::string&, ::Ice::Int&, const ::Ice::Context&);

    virtual void getStreamMonitorNum(::Ice::Int&, ::Ice::Int&, const ::Ice::Context&);

    virtual bool reSetServer(const ::Ice::Context&);

    virtual bool checkNeedRebootSyn(::Ice::Int, ::Ice::Int, const ::std::string&, const ::Ice::Context&);

    virtual bool NoticeReady(::Ice::Int, const ::Ice::Identity&, const ::Ice::Context&);

    virtual bool UpdateClientID(::Ice::Int, ::Ice::Int, const ::Ice::Context&);

    virtual bool NoticeReleaseUser(::Ice::Int, ::Ice::Int, const ::Ice::Context&);

    virtual bool NoticeReleaseUserAll(::Ice::Int, const ::Ice::Context&);

    virtual ::std::string ConvertCameraID(::Ice::Int, const ::Ice::Context&);

    virtual void getSystemRunState(::NVSIndex::SystemState&, const ::Ice::Context&);

    virtual bool heartBeatRetVaule(::Ice::Int, ::Ice::Int, const ::Ice::Context&);
};

}

}

namespace IceDelegateD
{

namespace NVSIndex
{

class NVSModel : virtual public ::IceDelegate::NVSIndex::NVSModel,
		 virtual public ::IceDelegateD::Ice::Object
{
public:

    virtual ::Ice::Int checkNeedReboot(::Ice::Int, ::Ice::Int, const ::std::string&, const ::Ice::Context&);
};

class NVSIndexNotice : virtual public ::IceDelegate::NVSIndex::NVSIndexNotice,
		       virtual public ::IceDelegateD::Ice::Object
{
public:

    virtual bool notifyClient(const ::NVSIndex::IndexNoticeInfo&, const ::Ice::Context&);

    virtual bool notifySwitched(::Ice::Int, ::Ice::Int, ::Ice::Int, const ::std::string&, const ::Ice::Context&);
};

class NVSIndex4Monitor : virtual public ::IceDelegate::NVSIndex::NVSIndex4Monitor,
			 virtual public ::IceDelegateD::Ice::Object
{
public:

    virtual bool registerMe(const ::NVSIndex::NVSMonitorInfo&, ::NVSIndex::NVSMonitorInfo&, const ::Ice::Context&);

    virtual ::Ice::Byte getStreamService(::Ice::Int, ::Ice::Int, ::std::string&, ::Ice::Int&, const ::Ice::Context&);

    virtual ::Ice::Byte getExternalStreamService(::Ice::Int, ::Ice::Int, ::std::string&, ::Ice::Int&, const ::Ice::Context&);

    virtual void heartBeat(::Ice::Int, const ::Ice::Context&);

    virtual bool getDvrInfo(::Ice::Int, ::NVSIndex::NVSDVRInfo&, const ::Ice::Context&);

    virtual void getStreamOnline(::NVSIndex::NVSConnectStrPool&, const ::Ice::Context&);

    virtual ::Ice::Int getControlService(::Ice::Int, ::std::string&, ::Ice::Int&, const ::Ice::Context&);

    virtual void getStreamMonitorNum(::Ice::Int&, ::Ice::Int&, const ::Ice::Context&);

    virtual bool reSetServer(const ::Ice::Context&);

    virtual bool checkNeedRebootSyn(::Ice::Int, ::Ice::Int, const ::std::string&, const ::Ice::Context&);

    virtual bool NoticeReady(::Ice::Int, const ::Ice::Identity&, const ::Ice::Context&);

    virtual bool UpdateClientID(::Ice::Int, ::Ice::Int, const ::Ice::Context&);

    virtual bool NoticeReleaseUser(::Ice::Int, ::Ice::Int, const ::Ice::Context&);

    virtual bool NoticeReleaseUserAll(::Ice::Int, const ::Ice::Context&);

    virtual ::std::string ConvertCameraID(::Ice::Int, const ::Ice::Context&);

    virtual void getSystemRunState(::NVSIndex::SystemState&, const ::Ice::Context&);

    virtual bool heartBeatRetVaule(::Ice::Int, ::Ice::Int, const ::Ice::Context&);
};

}

}

namespace NVSIndex
{

class NVSModel : virtual public ::Ice::Object
{
public:

    typedef NVSModelPrx ProxyType;
    typedef NVSModelPtr PointerType;
    
    virtual ::Ice::ObjectPtr ice_clone() const;

    virtual bool ice_isA(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const;
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& = ::Ice::Current()) const;
    virtual const ::std::string& ice_id(const ::Ice::Current& = ::Ice::Current()) const;
    static const ::std::string& ice_staticId();

    virtual void checkNeedReboot_async(const ::NVSIndex::AMD_NVSModel_checkNeedRebootPtr&, ::Ice::Int, ::Ice::Int, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___checkNeedReboot(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::IceInternal::DispatchStatus __dispatch(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);
    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

void __patch__NVSModelPtr(void*, ::Ice::ObjectPtr&);

class NVSIndexNotice : virtual public ::Ice::Object
{
public:

    typedef NVSIndexNoticePrx ProxyType;
    typedef NVSIndexNoticePtr PointerType;
    
    virtual ::Ice::ObjectPtr ice_clone() const;

    virtual bool ice_isA(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const;
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& = ::Ice::Current()) const;
    virtual const ::std::string& ice_id(const ::Ice::Current& = ::Ice::Current()) const;
    static const ::std::string& ice_staticId();

    virtual bool notifyClient(const ::NVSIndex::IndexNoticeInfo&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___notifyClient(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual bool notifySwitched(::Ice::Int, ::Ice::Int, ::Ice::Int, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___notifySwitched(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::IceInternal::DispatchStatus __dispatch(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);
    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

void __patch__NVSIndexNoticePtr(void*, ::Ice::ObjectPtr&);

class NVSIndex4Monitor : virtual public ::Ice::Object
{
public:

    typedef NVSIndex4MonitorPrx ProxyType;
    typedef NVSIndex4MonitorPtr PointerType;
    
    virtual ::Ice::ObjectPtr ice_clone() const;

    virtual bool ice_isA(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const;
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& = ::Ice::Current()) const;
    virtual const ::std::string& ice_id(const ::Ice::Current& = ::Ice::Current()) const;
    static const ::std::string& ice_staticId();

    virtual bool registerMe(const ::NVSIndex::NVSMonitorInfo&, ::NVSIndex::NVSMonitorInfo&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___registerMe(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::Ice::Byte getStreamService(::Ice::Int, ::Ice::Int, ::std::string&, ::Ice::Int&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___getStreamService(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::Ice::Byte getExternalStreamService(::Ice::Int, ::Ice::Int, ::std::string&, ::Ice::Int&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___getExternalStreamService(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void heartBeat(::Ice::Int, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___heartBeat(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual bool getDvrInfo(::Ice::Int, ::NVSIndex::NVSDVRInfo&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___getDvrInfo(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void getStreamOnline(::NVSIndex::NVSConnectStrPool&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___getStreamOnline(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::Ice::Int getControlService(::Ice::Int, ::std::string&, ::Ice::Int&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___getControlService(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void getStreamMonitorNum(::Ice::Int&, ::Ice::Int&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___getStreamMonitorNum(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual bool reSetServer(const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___reSetServer(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual bool checkNeedRebootSyn(::Ice::Int, ::Ice::Int, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___checkNeedRebootSyn(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual bool NoticeReady(::Ice::Int, const ::Ice::Identity&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___NoticeReady(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual bool UpdateClientID(::Ice::Int, ::Ice::Int, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___UpdateClientID(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual bool NoticeReleaseUser(::Ice::Int, ::Ice::Int, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___NoticeReleaseUser(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual bool NoticeReleaseUserAll(::Ice::Int, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___NoticeReleaseUserAll(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::std::string ConvertCameraID(::Ice::Int, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___ConvertCameraID(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void getSystemRunState(::NVSIndex::SystemState&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___getSystemRunState(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual bool heartBeatRetVaule(::Ice::Int, ::Ice::Int, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___heartBeatRetVaule(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::IceInternal::DispatchStatus __dispatch(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);
    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

void __patch__NVSIndex4MonitorPtr(void*, ::Ice::ObjectPtr&);

}

#endif
