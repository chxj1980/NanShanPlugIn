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

#ifndef _____ICE_NVSMonitorNotifier_h__
#define _____ICE_NVSMonitorNotifier_h__

#include <Ice/LocalObjectF.h>
#include <Ice/ProxyF.h>
#include <Ice/ObjectF.h>
#include <Ice/Exception.h>
#include <Ice/LocalObject.h>
#include <Ice/Proxy.h>
#include <Ice/Object.h>
#include <Ice/Outgoing.h>
#include <Ice/Incoming.h>
#include <Ice/Direct.h>
#include <Ice/StreamF.h>
#include <Ice/UndefSysMacros.h>

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

namespace NVSStreamService
{

class NVSMonitorNotifier;
bool operator==(const NVSMonitorNotifier&, const NVSMonitorNotifier&);
bool operator!=(const NVSMonitorNotifier&, const NVSMonitorNotifier&);
bool operator<(const NVSMonitorNotifier&, const NVSMonitorNotifier&);
bool operator<=(const NVSMonitorNotifier&, const NVSMonitorNotifier&);
bool operator>(const NVSMonitorNotifier&, const NVSMonitorNotifier&);
bool operator>=(const NVSMonitorNotifier&, const NVSMonitorNotifier&);

}

}

namespace NVSStreamService
{

class NVSMonitorNotifier;
bool operator==(const NVSMonitorNotifier&, const NVSMonitorNotifier&);
bool operator!=(const NVSMonitorNotifier&, const NVSMonitorNotifier&);
bool operator<(const NVSMonitorNotifier&, const NVSMonitorNotifier&);
bool operator<=(const NVSMonitorNotifier&, const NVSMonitorNotifier&);
bool operator>(const NVSMonitorNotifier&, const NVSMonitorNotifier&);
bool operator>=(const NVSMonitorNotifier&, const NVSMonitorNotifier&);

}

namespace IceInternal
{

void incRef(::NVSStreamService::NVSMonitorNotifier*);
void decRef(::NVSStreamService::NVSMonitorNotifier*);

void incRef(::IceProxy::NVSStreamService::NVSMonitorNotifier*);
void decRef(::IceProxy::NVSStreamService::NVSMonitorNotifier*);

}

namespace NVSStreamService
{

typedef ::IceInternal::Handle< ::NVSStreamService::NVSMonitorNotifier> NVSMonitorNotifierPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::NVSStreamService::NVSMonitorNotifier> NVSMonitorNotifierPrx;

void __write(::IceInternal::BasicStream*, const NVSMonitorNotifierPrx&);
void __read(::IceInternal::BasicStream*, NVSMonitorNotifierPrx&);
void __write(::IceInternal::BasicStream*, const NVSMonitorNotifierPtr&);
void __patch__NVSMonitorNotifierPtr(void*, ::Ice::ObjectPtr&);

}

namespace NVSStreamService
{

struct NotifierData
{
    ::Ice::Int nCameraID;
    ::Ice::Int nErr;

    bool operator==(const NotifierData&) const;
    bool operator!=(const NotifierData&) const;
    bool operator<(const NotifierData&) const;
    bool operator<=(const NotifierData& __rhs) const
    {
	return operator<(__rhs) || operator==(__rhs);
    }
    bool operator>(const NotifierData& __rhs) const
    {
	return !operator<(__rhs) && !operator==(__rhs);
    }
    bool operator>=(const NotifierData& __rhs) const
    {
	return !operator<(__rhs);
    }

    void __write(::IceInternal::BasicStream*) const;
    void __read(::IceInternal::BasicStream*);
};

}

namespace IceProxy
{

namespace NVSStreamService
{

class NVSMonitorNotifier : virtual public ::IceProxy::Ice::Object
{
public:

    void monitorNotify(const ::NVSStreamService::NotifierData& NData)
    {
	monitorNotify(NData, __defaultContext());
    }
    void monitorNotify(const ::NVSStreamService::NotifierData&, const ::Ice::Context&);
    
    static const ::std::string& ice_staticId();

private: 

    virtual ::IceInternal::Handle< ::IceDelegateM::Ice::Object> __createDelegateM();
    virtual ::IceInternal::Handle< ::IceDelegateD::Ice::Object> __createDelegateD();
};

}

}

namespace IceDelegate
{

namespace NVSStreamService
{

class NVSMonitorNotifier : virtual public ::IceDelegate::Ice::Object
{
public:

    virtual void monitorNotify(const ::NVSStreamService::NotifierData&, const ::Ice::Context&) = 0;
};

}

}

namespace IceDelegateM
{

namespace NVSStreamService
{

class NVSMonitorNotifier : virtual public ::IceDelegate::NVSStreamService::NVSMonitorNotifier,
			   virtual public ::IceDelegateM::Ice::Object
{
public:

    virtual void monitorNotify(const ::NVSStreamService::NotifierData&, const ::Ice::Context&);
};

}

}

namespace IceDelegateD
{

namespace NVSStreamService
{

class NVSMonitorNotifier : virtual public ::IceDelegate::NVSStreamService::NVSMonitorNotifier,
			   virtual public ::IceDelegateD::Ice::Object
{
public:

    virtual void monitorNotify(const ::NVSStreamService::NotifierData&, const ::Ice::Context&);
};

}

}

namespace NVSStreamService
{

class NVSMonitorNotifier : virtual public ::Ice::Object
{
public:

    typedef NVSMonitorNotifierPrx ProxyType;
    typedef NVSMonitorNotifierPtr PointerType;
    
    virtual ::Ice::ObjectPtr ice_clone() const;

    virtual bool ice_isA(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const;
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& = ::Ice::Current()) const;
    virtual const ::std::string& ice_id(const ::Ice::Current& = ::Ice::Current()) const;
    static const ::std::string& ice_staticId();

    virtual void monitorNotify(const ::NVSStreamService::NotifierData&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___monitorNotify(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::IceInternal::DispatchStatus __dispatch(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);
    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

void __patch__NVSMonitorNotifierPtr(void*, ::Ice::ObjectPtr&);

}

#endif
