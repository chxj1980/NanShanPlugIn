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

#ifndef _____ICE_NVSIndex4Stream_h__
#define _____ICE_NVSIndex4Stream_h__

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

class NVSIndex4Stream;
bool operator==(const NVSIndex4Stream&, const NVSIndex4Stream&);
bool operator!=(const NVSIndex4Stream&, const NVSIndex4Stream&);
bool operator<(const NVSIndex4Stream&, const NVSIndex4Stream&);
bool operator<=(const NVSIndex4Stream&, const NVSIndex4Stream&);
bool operator>(const NVSIndex4Stream&, const NVSIndex4Stream&);
bool operator>=(const NVSIndex4Stream&, const NVSIndex4Stream&);

class NVSIndex4StreamSend;
bool operator==(const NVSIndex4StreamSend&, const NVSIndex4StreamSend&);
bool operator!=(const NVSIndex4StreamSend&, const NVSIndex4StreamSend&);
bool operator<(const NVSIndex4StreamSend&, const NVSIndex4StreamSend&);
bool operator<=(const NVSIndex4StreamSend&, const NVSIndex4StreamSend&);
bool operator>(const NVSIndex4StreamSend&, const NVSIndex4StreamSend&);
bool operator>=(const NVSIndex4StreamSend&, const NVSIndex4StreamSend&);

}

}

namespace NVSIndex
{

class NVSIndex4Stream;
bool operator==(const NVSIndex4Stream&, const NVSIndex4Stream&);
bool operator!=(const NVSIndex4Stream&, const NVSIndex4Stream&);
bool operator<(const NVSIndex4Stream&, const NVSIndex4Stream&);
bool operator<=(const NVSIndex4Stream&, const NVSIndex4Stream&);
bool operator>(const NVSIndex4Stream&, const NVSIndex4Stream&);
bool operator>=(const NVSIndex4Stream&, const NVSIndex4Stream&);

class NVSIndex4StreamSend;
bool operator==(const NVSIndex4StreamSend&, const NVSIndex4StreamSend&);
bool operator!=(const NVSIndex4StreamSend&, const NVSIndex4StreamSend&);
bool operator<(const NVSIndex4StreamSend&, const NVSIndex4StreamSend&);
bool operator<=(const NVSIndex4StreamSend&, const NVSIndex4StreamSend&);
bool operator>(const NVSIndex4StreamSend&, const NVSIndex4StreamSend&);
bool operator>=(const NVSIndex4StreamSend&, const NVSIndex4StreamSend&);

}

namespace IceInternal
{

void incRef(::NVSIndex::NVSIndex4Stream*);
void decRef(::NVSIndex::NVSIndex4Stream*);

void incRef(::IceProxy::NVSIndex::NVSIndex4Stream*);
void decRef(::IceProxy::NVSIndex::NVSIndex4Stream*);

void incRef(::NVSIndex::NVSIndex4StreamSend*);
void decRef(::NVSIndex::NVSIndex4StreamSend*);

void incRef(::IceProxy::NVSIndex::NVSIndex4StreamSend*);
void decRef(::IceProxy::NVSIndex::NVSIndex4StreamSend*);

}

namespace NVSIndex
{

typedef ::IceInternal::Handle< ::NVSIndex::NVSIndex4Stream> NVSIndex4StreamPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::NVSIndex::NVSIndex4Stream> NVSIndex4StreamPrx;

void __write(::IceInternal::BasicStream*, const NVSIndex4StreamPrx&);
void __read(::IceInternal::BasicStream*, NVSIndex4StreamPrx&);
void __write(::IceInternal::BasicStream*, const NVSIndex4StreamPtr&);
void __patch__NVSIndex4StreamPtr(void*, ::Ice::ObjectPtr&);

typedef ::IceInternal::Handle< ::NVSIndex::NVSIndex4StreamSend> NVSIndex4StreamSendPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::NVSIndex::NVSIndex4StreamSend> NVSIndex4StreamSendPrx;

void __write(::IceInternal::BasicStream*, const NVSIndex4StreamSendPrx&);
void __read(::IceInternal::BasicStream*, NVSIndex4StreamSendPrx&);
void __write(::IceInternal::BasicStream*, const NVSIndex4StreamSendPtr&);
void __patch__NVSIndex4StreamSendPtr(void*, ::Ice::ObjectPtr&);

}

namespace NVSIndex
{

}

namespace IceProxy
{

namespace NVSIndex
{

class NVSIndex4Stream : virtual public ::IceProxy::Ice::Object
{
public:

    bool registerMe(const ::NVSIndex::NVSStreamServiceInfo& frontInfo, const ::Ice::Identity& ident, ::NVSIndex::NVSStreamServiceInfo& backInfo)
    {
	return registerMe(frontInfo, ident, backInfo, __defaultContext());
    }
    bool registerMe(const ::NVSIndex::NVSStreamServiceInfo&, const ::Ice::Identity&, ::NVSIndex::NVSStreamServiceInfo&, const ::Ice::Context&);

    void heartBeat(::Ice::Int nID)
    {
	heartBeat(nID, __defaultContext());
    }
    void heartBeat(::Ice::Int, const ::Ice::Context&);

    bool getDvrInfo(::Ice::Int nCameraID, ::NVSIndex::NVSDVRInfo& backInfo)
    {
	return getDvrInfo(nCameraID, backInfo, __defaultContext());
    }
    bool getDvrInfo(::Ice::Int, ::NVSIndex::NVSDVRInfo&, const ::Ice::Context&);

    ::Ice::Byte getSouceStreamService(::Ice::Int cameraID, ::std::string& sSSProxy, ::Ice::Int& serviceKey)
    {
	return getSouceStreamService(cameraID, sSSProxy, serviceKey, __defaultContext());
    }
    ::Ice::Byte getSouceStreamService(::Ice::Int, ::std::string&, ::Ice::Int&, const ::Ice::Context&);

    void transferLoad(const ::std::string& sServerKey, const ::NVSIndex::NVSCameraPool& vCameraPool, ::Ice::Int nMonitorLoad)
    {
	transferLoad(sServerKey, vCameraPool, nMonitorLoad, __defaultContext());
    }
    void transferLoad(const ::std::string&, const ::NVSIndex::NVSCameraPool&, ::Ice::Int, const ::Ice::Context&);

    void getDvrPools(const ::std::string& sKey, ::NVSIndex::NVSDVRPool& backInfo)
    {
	getDvrPools(sKey, backInfo, __defaultContext());
    }
    void getDvrPools(const ::std::string&, ::NVSIndex::NVSDVRPool&, const ::Ice::Context&);

    bool getDvrInfoEx(::Ice::Int nCameraID, ::NVSIndex::NVSDVRInfoEx& backInfo)
    {
	return getDvrInfoEx(nCameraID, backInfo, __defaultContext());
    }
    bool getDvrInfoEx(::Ice::Int, ::NVSIndex::NVSDVRInfoEx&, const ::Ice::Context&);
    
    static const ::std::string& ice_staticId();

private: 

    virtual ::IceInternal::Handle< ::IceDelegateM::Ice::Object> __createDelegateM();
    virtual ::IceInternal::Handle< ::IceDelegateD::Ice::Object> __createDelegateD();
};

class NVSIndex4StreamSend : virtual public ::IceProxy::Ice::Object
{
public:

    void notifyControlReload()
    {
	notifyControlReload(__defaultContext());
    }
    void notifyControlReload(const ::Ice::Context&);

    void notifyServiceConnect()
    {
	notifyServiceConnect(__defaultContext());
    }
    void notifyServiceConnect(const ::Ice::Context&);
    
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

class NVSIndex4Stream : virtual public ::IceDelegate::Ice::Object
{
public:

    virtual bool registerMe(const ::NVSIndex::NVSStreamServiceInfo&, const ::Ice::Identity&, ::NVSIndex::NVSStreamServiceInfo&, const ::Ice::Context&) = 0;

    virtual void heartBeat(::Ice::Int, const ::Ice::Context&) = 0;

    virtual bool getDvrInfo(::Ice::Int, ::NVSIndex::NVSDVRInfo&, const ::Ice::Context&) = 0;

    virtual ::Ice::Byte getSouceStreamService(::Ice::Int, ::std::string&, ::Ice::Int&, const ::Ice::Context&) = 0;

    virtual void transferLoad(const ::std::string&, const ::NVSIndex::NVSCameraPool&, ::Ice::Int, const ::Ice::Context&) = 0;

    virtual void getDvrPools(const ::std::string&, ::NVSIndex::NVSDVRPool&, const ::Ice::Context&) = 0;

    virtual bool getDvrInfoEx(::Ice::Int, ::NVSIndex::NVSDVRInfoEx&, const ::Ice::Context&) = 0;
};

class NVSIndex4StreamSend : virtual public ::IceDelegate::Ice::Object
{
public:

    virtual void notifyControlReload(const ::Ice::Context&) = 0;

    virtual void notifyServiceConnect(const ::Ice::Context&) = 0;
};

}

}

namespace IceDelegateM
{

namespace NVSIndex
{

class NVSIndex4Stream : virtual public ::IceDelegate::NVSIndex::NVSIndex4Stream,
			virtual public ::IceDelegateM::Ice::Object
{
public:

    virtual bool registerMe(const ::NVSIndex::NVSStreamServiceInfo&, const ::Ice::Identity&, ::NVSIndex::NVSStreamServiceInfo&, const ::Ice::Context&);

    virtual void heartBeat(::Ice::Int, const ::Ice::Context&);

    virtual bool getDvrInfo(::Ice::Int, ::NVSIndex::NVSDVRInfo&, const ::Ice::Context&);

    virtual ::Ice::Byte getSouceStreamService(::Ice::Int, ::std::string&, ::Ice::Int&, const ::Ice::Context&);

    virtual void transferLoad(const ::std::string&, const ::NVSIndex::NVSCameraPool&, ::Ice::Int, const ::Ice::Context&);

    virtual void getDvrPools(const ::std::string&, ::NVSIndex::NVSDVRPool&, const ::Ice::Context&);

    virtual bool getDvrInfoEx(::Ice::Int, ::NVSIndex::NVSDVRInfoEx&, const ::Ice::Context&);
};

class NVSIndex4StreamSend : virtual public ::IceDelegate::NVSIndex::NVSIndex4StreamSend,
			    virtual public ::IceDelegateM::Ice::Object
{
public:

    virtual void notifyControlReload(const ::Ice::Context&);

    virtual void notifyServiceConnect(const ::Ice::Context&);
};

}

}

namespace IceDelegateD
{

namespace NVSIndex
{

class NVSIndex4Stream : virtual public ::IceDelegate::NVSIndex::NVSIndex4Stream,
			virtual public ::IceDelegateD::Ice::Object
{
public:

    virtual bool registerMe(const ::NVSIndex::NVSStreamServiceInfo&, const ::Ice::Identity&, ::NVSIndex::NVSStreamServiceInfo&, const ::Ice::Context&);

    virtual void heartBeat(::Ice::Int, const ::Ice::Context&);

    virtual bool getDvrInfo(::Ice::Int, ::NVSIndex::NVSDVRInfo&, const ::Ice::Context&);

    virtual ::Ice::Byte getSouceStreamService(::Ice::Int, ::std::string&, ::Ice::Int&, const ::Ice::Context&);

    virtual void transferLoad(const ::std::string&, const ::NVSIndex::NVSCameraPool&, ::Ice::Int, const ::Ice::Context&);

    virtual void getDvrPools(const ::std::string&, ::NVSIndex::NVSDVRPool&, const ::Ice::Context&);

    virtual bool getDvrInfoEx(::Ice::Int, ::NVSIndex::NVSDVRInfoEx&, const ::Ice::Context&);
};

class NVSIndex4StreamSend : virtual public ::IceDelegate::NVSIndex::NVSIndex4StreamSend,
			    virtual public ::IceDelegateD::Ice::Object
{
public:

    virtual void notifyControlReload(const ::Ice::Context&);

    virtual void notifyServiceConnect(const ::Ice::Context&);
};

}

}

namespace NVSIndex
{

class NVSIndex4Stream : virtual public ::Ice::Object
{
public:

    typedef NVSIndex4StreamPrx ProxyType;
    typedef NVSIndex4StreamPtr PointerType;
    
    virtual ::Ice::ObjectPtr ice_clone() const;

    virtual bool ice_isA(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const;
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& = ::Ice::Current()) const;
    virtual const ::std::string& ice_id(const ::Ice::Current& = ::Ice::Current()) const;
    static const ::std::string& ice_staticId();

    virtual bool registerMe(const ::NVSIndex::NVSStreamServiceInfo&, const ::Ice::Identity&, ::NVSIndex::NVSStreamServiceInfo&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___registerMe(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void heartBeat(::Ice::Int, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___heartBeat(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual bool getDvrInfo(::Ice::Int, ::NVSIndex::NVSDVRInfo&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___getDvrInfo(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::Ice::Byte getSouceStreamService(::Ice::Int, ::std::string&, ::Ice::Int&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___getSouceStreamService(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void transferLoad(const ::std::string&, const ::NVSIndex::NVSCameraPool&, ::Ice::Int, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___transferLoad(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void getDvrPools(const ::std::string&, ::NVSIndex::NVSDVRPool&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___getDvrPools(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual bool getDvrInfoEx(::Ice::Int, ::NVSIndex::NVSDVRInfoEx&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___getDvrInfoEx(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::IceInternal::DispatchStatus __dispatch(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);
    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

void __patch__NVSIndex4StreamPtr(void*, ::Ice::ObjectPtr&);

class NVSIndex4StreamSend : virtual public ::Ice::Object
{
public:

    typedef NVSIndex4StreamSendPrx ProxyType;
    typedef NVSIndex4StreamSendPtr PointerType;
    
    virtual ::Ice::ObjectPtr ice_clone() const;

    virtual bool ice_isA(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const;
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& = ::Ice::Current()) const;
    virtual const ::std::string& ice_id(const ::Ice::Current& = ::Ice::Current()) const;
    static const ::std::string& ice_staticId();

    virtual void notifyControlReload(const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___notifyControlReload(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void notifyServiceConnect(const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___notifyServiceConnect(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::IceInternal::DispatchStatus __dispatch(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);
    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

void __patch__NVSIndex4StreamSendPtr(void*, ::Ice::ObjectPtr&);

}

#endif
