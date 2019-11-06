// **********************************************************************
//
// Copyright (c) 2003-2006 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************

// Ice version 3.1.1
// Generated from file `Observer.ice'

#ifndef __icegrid_Observer_h__
#define __icegrid_Observer_h__

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
#include <Glacier2/Session.h>
#include <IceGrid/Exception.h>
#include <IceGrid/Descriptor.h>
#include <IceGrid/Admin.h>
#include <Ice/UndefSysMacros.h>

#ifndef ICE_IGNORE_VERSION
#   if ICE_INT_VERSION / 100 != 301
#       error Ice version mismatch!
#   endif
#   if ICE_INT_VERSION % 100 < 1
#       error Ice patch level mismatch!
#   endif
#endif

#ifndef ICE_GRID_API
#   ifdef ICE_GRID_API_EXPORTS
#       define ICE_GRID_API ICE_DECLSPEC_EXPORT
#   else
#       define ICE_GRID_API ICE_DECLSPEC_IMPORT
#   endif
#endif

namespace IceProxy
{

namespace IceGrid
{

class NodeObserver;
ICE_GRID_API bool operator==(const NodeObserver&, const NodeObserver&);
ICE_GRID_API bool operator!=(const NodeObserver&, const NodeObserver&);
ICE_GRID_API bool operator<(const NodeObserver&, const NodeObserver&);
ICE_GRID_API bool operator<=(const NodeObserver&, const NodeObserver&);
ICE_GRID_API bool operator>(const NodeObserver&, const NodeObserver&);
ICE_GRID_API bool operator>=(const NodeObserver&, const NodeObserver&);

class RegistryObserver;
ICE_GRID_API bool operator==(const RegistryObserver&, const RegistryObserver&);
ICE_GRID_API bool operator!=(const RegistryObserver&, const RegistryObserver&);
ICE_GRID_API bool operator<(const RegistryObserver&, const RegistryObserver&);
ICE_GRID_API bool operator<=(const RegistryObserver&, const RegistryObserver&);
ICE_GRID_API bool operator>(const RegistryObserver&, const RegistryObserver&);
ICE_GRID_API bool operator>=(const RegistryObserver&, const RegistryObserver&);

}

}

namespace IceGrid
{

class NodeObserver;
ICE_GRID_API bool operator==(const NodeObserver&, const NodeObserver&);
ICE_GRID_API bool operator!=(const NodeObserver&, const NodeObserver&);
ICE_GRID_API bool operator<(const NodeObserver&, const NodeObserver&);
ICE_GRID_API bool operator<=(const NodeObserver&, const NodeObserver&);
ICE_GRID_API bool operator>(const NodeObserver&, const NodeObserver&);
ICE_GRID_API bool operator>=(const NodeObserver&, const NodeObserver&);

class RegistryObserver;
ICE_GRID_API bool operator==(const RegistryObserver&, const RegistryObserver&);
ICE_GRID_API bool operator!=(const RegistryObserver&, const RegistryObserver&);
ICE_GRID_API bool operator<(const RegistryObserver&, const RegistryObserver&);
ICE_GRID_API bool operator<=(const RegistryObserver&, const RegistryObserver&);
ICE_GRID_API bool operator>(const RegistryObserver&, const RegistryObserver&);
ICE_GRID_API bool operator>=(const RegistryObserver&, const RegistryObserver&);

}

namespace IceInternal
{

ICE_GRID_API void incRef(::IceGrid::NodeObserver*);
ICE_GRID_API void decRef(::IceGrid::NodeObserver*);

ICE_GRID_API void incRef(::IceProxy::IceGrid::NodeObserver*);
ICE_GRID_API void decRef(::IceProxy::IceGrid::NodeObserver*);

ICE_GRID_API void incRef(::IceGrid::RegistryObserver*);
ICE_GRID_API void decRef(::IceGrid::RegistryObserver*);

ICE_GRID_API void incRef(::IceProxy::IceGrid::RegistryObserver*);
ICE_GRID_API void decRef(::IceProxy::IceGrid::RegistryObserver*);

}

namespace IceGrid
{

typedef ::IceInternal::Handle< ::IceGrid::NodeObserver> NodeObserverPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::IceGrid::NodeObserver> NodeObserverPrx;

ICE_GRID_API void __write(::IceInternal::BasicStream*, const NodeObserverPrx&);
ICE_GRID_API void __read(::IceInternal::BasicStream*, NodeObserverPrx&);
ICE_GRID_API void __write(::IceInternal::BasicStream*, const NodeObserverPtr&);
ICE_GRID_API void __patch__NodeObserverPtr(void*, ::Ice::ObjectPtr&);

typedef ::IceInternal::Handle< ::IceGrid::RegistryObserver> RegistryObserverPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::IceGrid::RegistryObserver> RegistryObserverPrx;

ICE_GRID_API void __write(::IceInternal::BasicStream*, const RegistryObserverPrx&);
ICE_GRID_API void __read(::IceInternal::BasicStream*, RegistryObserverPrx&);
ICE_GRID_API void __write(::IceInternal::BasicStream*, const RegistryObserverPtr&);
ICE_GRID_API void __patch__RegistryObserverPtr(void*, ::Ice::ObjectPtr&);

}

namespace IceGrid
{

struct ServerDynamicInfo
{
    ::std::string id;
    ::IceGrid::ServerState state;
    ::Ice::Int pid;
    bool enabled;

    ICE_GRID_API bool operator==(const ServerDynamicInfo&) const;
    ICE_GRID_API bool operator!=(const ServerDynamicInfo&) const;
    ICE_GRID_API bool operator<(const ServerDynamicInfo&) const;
    ICE_GRID_API bool operator<=(const ServerDynamicInfo& __rhs) const
    {
	return operator<(__rhs) || operator==(__rhs);
    }
    ICE_GRID_API bool operator>(const ServerDynamicInfo& __rhs) const
    {
	return !operator<(__rhs) && !operator==(__rhs);
    }
    ICE_GRID_API bool operator>=(const ServerDynamicInfo& __rhs) const
    {
	return !operator<(__rhs);
    }

    ICE_GRID_API void __write(::IceInternal::BasicStream*) const;
    ICE_GRID_API void __read(::IceInternal::BasicStream*);
};

typedef ::std::vector< ::IceGrid::ServerDynamicInfo> ServerDynamicInfoSeq;

class __U__ServerDynamicInfoSeq { };
ICE_GRID_API void __write(::IceInternal::BasicStream*, const ::IceGrid::ServerDynamicInfo*, const ::IceGrid::ServerDynamicInfo*, __U__ServerDynamicInfoSeq);
ICE_GRID_API void __read(::IceInternal::BasicStream*, ServerDynamicInfoSeq&, __U__ServerDynamicInfoSeq);

struct AdapterDynamicInfo
{
    ::std::string id;
    ::Ice::ObjectPrx proxy;

    ICE_GRID_API bool operator==(const AdapterDynamicInfo&) const;
    ICE_GRID_API bool operator!=(const AdapterDynamicInfo&) const;
    ICE_GRID_API bool operator<(const AdapterDynamicInfo&) const;
    ICE_GRID_API bool operator<=(const AdapterDynamicInfo& __rhs) const
    {
	return operator<(__rhs) || operator==(__rhs);
    }
    ICE_GRID_API bool operator>(const AdapterDynamicInfo& __rhs) const
    {
	return !operator<(__rhs) && !operator==(__rhs);
    }
    ICE_GRID_API bool operator>=(const AdapterDynamicInfo& __rhs) const
    {
	return !operator<(__rhs);
    }

    ICE_GRID_API void __write(::IceInternal::BasicStream*) const;
    ICE_GRID_API void __read(::IceInternal::BasicStream*);
};

typedef ::std::vector< ::IceGrid::AdapterDynamicInfo> AdapterDynamicInfoSeq;

class __U__AdapterDynamicInfoSeq { };
ICE_GRID_API void __write(::IceInternal::BasicStream*, const ::IceGrid::AdapterDynamicInfo*, const ::IceGrid::AdapterDynamicInfo*, __U__AdapterDynamicInfoSeq);
ICE_GRID_API void __read(::IceInternal::BasicStream*, AdapterDynamicInfoSeq&, __U__AdapterDynamicInfoSeq);

struct NodeDynamicInfo
{
    ::std::string name;
    ::IceGrid::NodeInfo info;
    ::IceGrid::ServerDynamicInfoSeq servers;
    ::IceGrid::AdapterDynamicInfoSeq adapters;

    ICE_GRID_API bool operator==(const NodeDynamicInfo&) const;
    ICE_GRID_API bool operator!=(const NodeDynamicInfo&) const;
    ICE_GRID_API bool operator<(const NodeDynamicInfo&) const;
    ICE_GRID_API bool operator<=(const NodeDynamicInfo& __rhs) const
    {
	return operator<(__rhs) || operator==(__rhs);
    }
    ICE_GRID_API bool operator>(const NodeDynamicInfo& __rhs) const
    {
	return !operator<(__rhs) && !operator==(__rhs);
    }
    ICE_GRID_API bool operator>=(const NodeDynamicInfo& __rhs) const
    {
	return !operator<(__rhs);
    }

    ICE_GRID_API void __write(::IceInternal::BasicStream*) const;
    ICE_GRID_API void __read(::IceInternal::BasicStream*);
};

typedef ::std::vector< ::IceGrid::NodeDynamicInfo> NodeDynamicInfoSeq;

class __U__NodeDynamicInfoSeq { };
ICE_GRID_API void __write(::IceInternal::BasicStream*, const ::IceGrid::NodeDynamicInfo*, const ::IceGrid::NodeDynamicInfo*, __U__NodeDynamicInfoSeq);
ICE_GRID_API void __read(::IceInternal::BasicStream*, NodeDynamicInfoSeq&, __U__NodeDynamicInfoSeq);

}

namespace IceGrid
{

class ICE_GRID_API AMI_NodeObserver_init : public ::IceInternal::OutgoingAsync
{
public:

    virtual void ice_response() = 0;
    virtual void ice_exception(const ::Ice::Exception&) = 0;

    void __invoke(const ::IceGrid::NodeObserverPrx&, const ::IceGrid::NodeDynamicInfoSeq&, const ::Ice::Context&);

protected:

    virtual void __response(bool);
};

typedef ::IceUtil::Handle< ::IceGrid::AMI_NodeObserver_init> AMI_NodeObserver_initPtr;

class ICE_GRID_API AMI_RegistryObserver_init : public ::IceInternal::OutgoingAsync
{
public:

    virtual void ice_response() = 0;
    virtual void ice_exception(const ::Ice::Exception&) = 0;

    void __invoke(const ::IceGrid::RegistryObserverPrx&, ::Ice::Int, const ::IceGrid::ApplicationDescriptorSeq&, const ::IceGrid::AdapterInfoSeq&, const ::IceGrid::ObjectInfoSeq&, const ::Ice::Context&);

protected:

    virtual void __response(bool);
};

typedef ::IceUtil::Handle< ::IceGrid::AMI_RegistryObserver_init> AMI_RegistryObserver_initPtr;

}

namespace IceAsync
{

}

namespace IceProxy
{

namespace IceGrid
{

class ICE_GRID_API NodeObserver : virtual public ::IceProxy::Ice::Object
{
public:

    void init(const ::IceGrid::NodeDynamicInfoSeq& nodes)
    {
	init(nodes, __defaultContext());
    }
    void init(const ::IceGrid::NodeDynamicInfoSeq&, const ::Ice::Context&);
    void init_async(const ::IceGrid::AMI_NodeObserver_initPtr&, const ::IceGrid::NodeDynamicInfoSeq&);
    void init_async(const ::IceGrid::AMI_NodeObserver_initPtr&, const ::IceGrid::NodeDynamicInfoSeq&, const ::Ice::Context&);

    void nodeUp(const ::IceGrid::NodeDynamicInfo& node)
    {
	nodeUp(node, __defaultContext());
    }
    void nodeUp(const ::IceGrid::NodeDynamicInfo&, const ::Ice::Context&);

    void nodeDown(const ::std::string& name)
    {
	nodeDown(name, __defaultContext());
    }
    void nodeDown(const ::std::string&, const ::Ice::Context&);

    void updateServer(const ::std::string& node, const ::IceGrid::ServerDynamicInfo& updatedInfo)
    {
	updateServer(node, updatedInfo, __defaultContext());
    }
    void updateServer(const ::std::string&, const ::IceGrid::ServerDynamicInfo&, const ::Ice::Context&);

    void updateAdapter(const ::std::string& node, const ::IceGrid::AdapterDynamicInfo& updatedInfo)
    {
	updateAdapter(node, updatedInfo, __defaultContext());
    }
    void updateAdapter(const ::std::string&, const ::IceGrid::AdapterDynamicInfo&, const ::Ice::Context&);
    
    static const ::std::string& ice_staticId();

private: 

    virtual ::IceInternal::Handle< ::IceDelegateM::Ice::Object> __createDelegateM();
    virtual ::IceInternal::Handle< ::IceDelegateD::Ice::Object> __createDelegateD();
};

class ICE_GRID_API RegistryObserver : virtual public ::IceProxy::Ice::Object
{
public:

    void init(::Ice::Int serial, const ::IceGrid::ApplicationDescriptorSeq& applications, const ::IceGrid::AdapterInfoSeq& adpts, const ::IceGrid::ObjectInfoSeq& objects)
    {
	init(serial, applications, adpts, objects, __defaultContext());
    }
    void init(::Ice::Int, const ::IceGrid::ApplicationDescriptorSeq&, const ::IceGrid::AdapterInfoSeq&, const ::IceGrid::ObjectInfoSeq&, const ::Ice::Context&);
    void init_async(const ::IceGrid::AMI_RegistryObserver_initPtr&, ::Ice::Int, const ::IceGrid::ApplicationDescriptorSeq&, const ::IceGrid::AdapterInfoSeq&, const ::IceGrid::ObjectInfoSeq&);
    void init_async(const ::IceGrid::AMI_RegistryObserver_initPtr&, ::Ice::Int, const ::IceGrid::ApplicationDescriptorSeq&, const ::IceGrid::AdapterInfoSeq&, const ::IceGrid::ObjectInfoSeq&, const ::Ice::Context&);

    void applicationAdded(::Ice::Int serial, const ::IceGrid::ApplicationDescriptor& desc)
    {
	applicationAdded(serial, desc, __defaultContext());
    }
    void applicationAdded(::Ice::Int, const ::IceGrid::ApplicationDescriptor&, const ::Ice::Context&);

    void applicationRemoved(::Ice::Int serial, const ::std::string& name)
    {
	applicationRemoved(serial, name, __defaultContext());
    }
    void applicationRemoved(::Ice::Int, const ::std::string&, const ::Ice::Context&);

    void applicationUpdated(::Ice::Int serial, const ::IceGrid::ApplicationUpdateDescriptor& desc)
    {
	applicationUpdated(serial, desc, __defaultContext());
    }
    void applicationUpdated(::Ice::Int, const ::IceGrid::ApplicationUpdateDescriptor&, const ::Ice::Context&);

    void adapterAdded(::Ice::Int serial, const ::IceGrid::AdapterInfo& info)
    {
	adapterAdded(serial, info, __defaultContext());
    }
    void adapterAdded(::Ice::Int, const ::IceGrid::AdapterInfo&, const ::Ice::Context&);

    void adapterUpdated(::Ice::Int serial, const ::IceGrid::AdapterInfo& info)
    {
	adapterUpdated(serial, info, __defaultContext());
    }
    void adapterUpdated(::Ice::Int, const ::IceGrid::AdapterInfo&, const ::Ice::Context&);

    void adapterRemoved(::Ice::Int serial, const ::std::string& id)
    {
	adapterRemoved(serial, id, __defaultContext());
    }
    void adapterRemoved(::Ice::Int, const ::std::string&, const ::Ice::Context&);

    void objectAdded(::Ice::Int serial, const ::IceGrid::ObjectInfo& info)
    {
	objectAdded(serial, info, __defaultContext());
    }
    void objectAdded(::Ice::Int, const ::IceGrid::ObjectInfo&, const ::Ice::Context&);

    void objectUpdated(::Ice::Int serial, const ::IceGrid::ObjectInfo& info)
    {
	objectUpdated(serial, info, __defaultContext());
    }
    void objectUpdated(::Ice::Int, const ::IceGrid::ObjectInfo&, const ::Ice::Context&);

    void objectRemoved(::Ice::Int serial, const ::Ice::Identity& id)
    {
	objectRemoved(serial, id, __defaultContext());
    }
    void objectRemoved(::Ice::Int, const ::Ice::Identity&, const ::Ice::Context&);
    
    static const ::std::string& ice_staticId();

private: 

    virtual ::IceInternal::Handle< ::IceDelegateM::Ice::Object> __createDelegateM();
    virtual ::IceInternal::Handle< ::IceDelegateD::Ice::Object> __createDelegateD();
};

}

}

namespace IceDelegate
{

namespace IceGrid
{

class ICE_GRID_API NodeObserver : virtual public ::IceDelegate::Ice::Object
{
public:

    virtual void init(const ::IceGrid::NodeDynamicInfoSeq&, const ::Ice::Context&) = 0;

    virtual void nodeUp(const ::IceGrid::NodeDynamicInfo&, const ::Ice::Context&) = 0;

    virtual void nodeDown(const ::std::string&, const ::Ice::Context&) = 0;

    virtual void updateServer(const ::std::string&, const ::IceGrid::ServerDynamicInfo&, const ::Ice::Context&) = 0;

    virtual void updateAdapter(const ::std::string&, const ::IceGrid::AdapterDynamicInfo&, const ::Ice::Context&) = 0;
};

class ICE_GRID_API RegistryObserver : virtual public ::IceDelegate::Ice::Object
{
public:

    virtual void init(::Ice::Int, const ::IceGrid::ApplicationDescriptorSeq&, const ::IceGrid::AdapterInfoSeq&, const ::IceGrid::ObjectInfoSeq&, const ::Ice::Context&) = 0;

    virtual void applicationAdded(::Ice::Int, const ::IceGrid::ApplicationDescriptor&, const ::Ice::Context&) = 0;

    virtual void applicationRemoved(::Ice::Int, const ::std::string&, const ::Ice::Context&) = 0;

    virtual void applicationUpdated(::Ice::Int, const ::IceGrid::ApplicationUpdateDescriptor&, const ::Ice::Context&) = 0;

    virtual void adapterAdded(::Ice::Int, const ::IceGrid::AdapterInfo&, const ::Ice::Context&) = 0;

    virtual void adapterUpdated(::Ice::Int, const ::IceGrid::AdapterInfo&, const ::Ice::Context&) = 0;

    virtual void adapterRemoved(::Ice::Int, const ::std::string&, const ::Ice::Context&) = 0;

    virtual void objectAdded(::Ice::Int, const ::IceGrid::ObjectInfo&, const ::Ice::Context&) = 0;

    virtual void objectUpdated(::Ice::Int, const ::IceGrid::ObjectInfo&, const ::Ice::Context&) = 0;

    virtual void objectRemoved(::Ice::Int, const ::Ice::Identity&, const ::Ice::Context&) = 0;
};

}

}

namespace IceDelegateM
{

namespace IceGrid
{

class ICE_GRID_API NodeObserver : virtual public ::IceDelegate::IceGrid::NodeObserver,
				  virtual public ::IceDelegateM::Ice::Object
{
public:

    virtual void init(const ::IceGrid::NodeDynamicInfoSeq&, const ::Ice::Context&);

    virtual void nodeUp(const ::IceGrid::NodeDynamicInfo&, const ::Ice::Context&);

    virtual void nodeDown(const ::std::string&, const ::Ice::Context&);

    virtual void updateServer(const ::std::string&, const ::IceGrid::ServerDynamicInfo&, const ::Ice::Context&);

    virtual void updateAdapter(const ::std::string&, const ::IceGrid::AdapterDynamicInfo&, const ::Ice::Context&);
};

class ICE_GRID_API RegistryObserver : virtual public ::IceDelegate::IceGrid::RegistryObserver,
				      virtual public ::IceDelegateM::Ice::Object
{
public:

    virtual void init(::Ice::Int, const ::IceGrid::ApplicationDescriptorSeq&, const ::IceGrid::AdapterInfoSeq&, const ::IceGrid::ObjectInfoSeq&, const ::Ice::Context&);

    virtual void applicationAdded(::Ice::Int, const ::IceGrid::ApplicationDescriptor&, const ::Ice::Context&);

    virtual void applicationRemoved(::Ice::Int, const ::std::string&, const ::Ice::Context&);

    virtual void applicationUpdated(::Ice::Int, const ::IceGrid::ApplicationUpdateDescriptor&, const ::Ice::Context&);

    virtual void adapterAdded(::Ice::Int, const ::IceGrid::AdapterInfo&, const ::Ice::Context&);

    virtual void adapterUpdated(::Ice::Int, const ::IceGrid::AdapterInfo&, const ::Ice::Context&);

    virtual void adapterRemoved(::Ice::Int, const ::std::string&, const ::Ice::Context&);

    virtual void objectAdded(::Ice::Int, const ::IceGrid::ObjectInfo&, const ::Ice::Context&);

    virtual void objectUpdated(::Ice::Int, const ::IceGrid::ObjectInfo&, const ::Ice::Context&);

    virtual void objectRemoved(::Ice::Int, const ::Ice::Identity&, const ::Ice::Context&);
};

}

}

namespace IceDelegateD
{

namespace IceGrid
{

class ICE_GRID_API NodeObserver : virtual public ::IceDelegate::IceGrid::NodeObserver,
				  virtual public ::IceDelegateD::Ice::Object
{
public:

    virtual void init(const ::IceGrid::NodeDynamicInfoSeq&, const ::Ice::Context&);

    virtual void nodeUp(const ::IceGrid::NodeDynamicInfo&, const ::Ice::Context&);

    virtual void nodeDown(const ::std::string&, const ::Ice::Context&);

    virtual void updateServer(const ::std::string&, const ::IceGrid::ServerDynamicInfo&, const ::Ice::Context&);

    virtual void updateAdapter(const ::std::string&, const ::IceGrid::AdapterDynamicInfo&, const ::Ice::Context&);
};

class ICE_GRID_API RegistryObserver : virtual public ::IceDelegate::IceGrid::RegistryObserver,
				      virtual public ::IceDelegateD::Ice::Object
{
public:

    virtual void init(::Ice::Int, const ::IceGrid::ApplicationDescriptorSeq&, const ::IceGrid::AdapterInfoSeq&, const ::IceGrid::ObjectInfoSeq&, const ::Ice::Context&);

    virtual void applicationAdded(::Ice::Int, const ::IceGrid::ApplicationDescriptor&, const ::Ice::Context&);

    virtual void applicationRemoved(::Ice::Int, const ::std::string&, const ::Ice::Context&);

    virtual void applicationUpdated(::Ice::Int, const ::IceGrid::ApplicationUpdateDescriptor&, const ::Ice::Context&);

    virtual void adapterAdded(::Ice::Int, const ::IceGrid::AdapterInfo&, const ::Ice::Context&);

    virtual void adapterUpdated(::Ice::Int, const ::IceGrid::AdapterInfo&, const ::Ice::Context&);

    virtual void adapterRemoved(::Ice::Int, const ::std::string&, const ::Ice::Context&);

    virtual void objectAdded(::Ice::Int, const ::IceGrid::ObjectInfo&, const ::Ice::Context&);

    virtual void objectUpdated(::Ice::Int, const ::IceGrid::ObjectInfo&, const ::Ice::Context&);

    virtual void objectRemoved(::Ice::Int, const ::Ice::Identity&, const ::Ice::Context&);
};

}

}

namespace IceGrid
{

class ICE_GRID_API NodeObserver : virtual public ::Ice::Object
{
public:

    typedef NodeObserverPrx ProxyType;
    typedef NodeObserverPtr PointerType;
    
    virtual ::Ice::ObjectPtr ice_clone() const;

    virtual bool ice_isA(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const;
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& = ::Ice::Current()) const;
    virtual const ::std::string& ice_id(const ::Ice::Current& = ::Ice::Current()) const;
    static const ::std::string& ice_staticId();

    virtual void init(const ::IceGrid::NodeDynamicInfoSeq&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___init(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void nodeUp(const ::IceGrid::NodeDynamicInfo&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___nodeUp(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void nodeDown(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___nodeDown(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void updateServer(const ::std::string&, const ::IceGrid::ServerDynamicInfo&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___updateServer(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void updateAdapter(const ::std::string&, const ::IceGrid::AdapterDynamicInfo&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___updateAdapter(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::IceInternal::DispatchStatus __dispatch(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);
    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

void ICE_GRID_API __patch__NodeObserverPtr(void*, ::Ice::ObjectPtr&);

class ICE_GRID_API RegistryObserver : virtual public ::Ice::Object
{
public:

    typedef RegistryObserverPrx ProxyType;
    typedef RegistryObserverPtr PointerType;
    
    virtual ::Ice::ObjectPtr ice_clone() const;

    virtual bool ice_isA(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const;
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& = ::Ice::Current()) const;
    virtual const ::std::string& ice_id(const ::Ice::Current& = ::Ice::Current()) const;
    static const ::std::string& ice_staticId();

    virtual void init(::Ice::Int, const ::IceGrid::ApplicationDescriptorSeq&, const ::IceGrid::AdapterInfoSeq&, const ::IceGrid::ObjectInfoSeq&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___init(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void applicationAdded(::Ice::Int, const ::IceGrid::ApplicationDescriptor&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___applicationAdded(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void applicationRemoved(::Ice::Int, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___applicationRemoved(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void applicationUpdated(::Ice::Int, const ::IceGrid::ApplicationUpdateDescriptor&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___applicationUpdated(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void adapterAdded(::Ice::Int, const ::IceGrid::AdapterInfo&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___adapterAdded(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void adapterUpdated(::Ice::Int, const ::IceGrid::AdapterInfo&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___adapterUpdated(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void adapterRemoved(::Ice::Int, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___adapterRemoved(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void objectAdded(::Ice::Int, const ::IceGrid::ObjectInfo&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___objectAdded(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void objectUpdated(::Ice::Int, const ::IceGrid::ObjectInfo&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___objectUpdated(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void objectRemoved(::Ice::Int, const ::Ice::Identity&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___objectRemoved(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::IceInternal::DispatchStatus __dispatch(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);
    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

void ICE_GRID_API __patch__RegistryObserverPtr(void*, ::Ice::ObjectPtr&);

}

#endif
