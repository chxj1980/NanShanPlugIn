// **********************************************************************
//
// Copyright (c) 2003-2006 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************

// Ice version 3.1.1
// Generated from file `Admin.ice'

#ifndef __icegrid_Admin_h__
#define __icegrid_Admin_h__

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
#include <Ice/BuiltinSequences.h>
#include <Ice/SliceChecksumDict.h>
#include <Glacier2/Session.h>
#include <IceGrid/Exception.h>
#include <IceGrid/Descriptor.h>
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

class Admin;
ICE_GRID_API bool operator==(const Admin&, const Admin&);
ICE_GRID_API bool operator!=(const Admin&, const Admin&);
ICE_GRID_API bool operator<(const Admin&, const Admin&);
ICE_GRID_API bool operator<=(const Admin&, const Admin&);
ICE_GRID_API bool operator>(const Admin&, const Admin&);
ICE_GRID_API bool operator>=(const Admin&, const Admin&);

class RegistryObserver;
ICE_GRID_API bool operator==(const RegistryObserver&, const RegistryObserver&);
ICE_GRID_API bool operator!=(const RegistryObserver&, const RegistryObserver&);
ICE_GRID_API bool operator<(const RegistryObserver&, const RegistryObserver&);
ICE_GRID_API bool operator<=(const RegistryObserver&, const RegistryObserver&);
ICE_GRID_API bool operator>(const RegistryObserver&, const RegistryObserver&);
ICE_GRID_API bool operator>=(const RegistryObserver&, const RegistryObserver&);

class NodeObserver;
ICE_GRID_API bool operator==(const NodeObserver&, const NodeObserver&);
ICE_GRID_API bool operator!=(const NodeObserver&, const NodeObserver&);
ICE_GRID_API bool operator<(const NodeObserver&, const NodeObserver&);
ICE_GRID_API bool operator<=(const NodeObserver&, const NodeObserver&);
ICE_GRID_API bool operator>(const NodeObserver&, const NodeObserver&);
ICE_GRID_API bool operator>=(const NodeObserver&, const NodeObserver&);

class AdminSession;
ICE_GRID_API bool operator==(const AdminSession&, const AdminSession&);
ICE_GRID_API bool operator!=(const AdminSession&, const AdminSession&);
ICE_GRID_API bool operator<(const AdminSession&, const AdminSession&);
ICE_GRID_API bool operator<=(const AdminSession&, const AdminSession&);
ICE_GRID_API bool operator>(const AdminSession&, const AdminSession&);
ICE_GRID_API bool operator>=(const AdminSession&, const AdminSession&);

}

}

namespace IceGrid
{

class Admin;
ICE_GRID_API bool operator==(const Admin&, const Admin&);
ICE_GRID_API bool operator!=(const Admin&, const Admin&);
ICE_GRID_API bool operator<(const Admin&, const Admin&);
ICE_GRID_API bool operator<=(const Admin&, const Admin&);
ICE_GRID_API bool operator>(const Admin&, const Admin&);
ICE_GRID_API bool operator>=(const Admin&, const Admin&);

class RegistryObserver;
ICE_GRID_API bool operator==(const RegistryObserver&, const RegistryObserver&);
ICE_GRID_API bool operator!=(const RegistryObserver&, const RegistryObserver&);
ICE_GRID_API bool operator<(const RegistryObserver&, const RegistryObserver&);
ICE_GRID_API bool operator<=(const RegistryObserver&, const RegistryObserver&);
ICE_GRID_API bool operator>(const RegistryObserver&, const RegistryObserver&);
ICE_GRID_API bool operator>=(const RegistryObserver&, const RegistryObserver&);

class NodeObserver;
ICE_GRID_API bool operator==(const NodeObserver&, const NodeObserver&);
ICE_GRID_API bool operator!=(const NodeObserver&, const NodeObserver&);
ICE_GRID_API bool operator<(const NodeObserver&, const NodeObserver&);
ICE_GRID_API bool operator<=(const NodeObserver&, const NodeObserver&);
ICE_GRID_API bool operator>(const NodeObserver&, const NodeObserver&);
ICE_GRID_API bool operator>=(const NodeObserver&, const NodeObserver&);

class AdminSession;
ICE_GRID_API bool operator==(const AdminSession&, const AdminSession&);
ICE_GRID_API bool operator!=(const AdminSession&, const AdminSession&);
ICE_GRID_API bool operator<(const AdminSession&, const AdminSession&);
ICE_GRID_API bool operator<=(const AdminSession&, const AdminSession&);
ICE_GRID_API bool operator>(const AdminSession&, const AdminSession&);
ICE_GRID_API bool operator>=(const AdminSession&, const AdminSession&);

}

namespace IceInternal
{

ICE_GRID_API void incRef(::IceGrid::Admin*);
ICE_GRID_API void decRef(::IceGrid::Admin*);

ICE_GRID_API void incRef(::IceProxy::IceGrid::Admin*);
ICE_GRID_API void decRef(::IceProxy::IceGrid::Admin*);

ICE_GRID_API void incRef(::IceGrid::RegistryObserver*);
ICE_GRID_API void decRef(::IceGrid::RegistryObserver*);

ICE_GRID_API void incRef(::IceProxy::IceGrid::RegistryObserver*);
ICE_GRID_API void decRef(::IceProxy::IceGrid::RegistryObserver*);

ICE_GRID_API void incRef(::IceGrid::NodeObserver*);
ICE_GRID_API void decRef(::IceGrid::NodeObserver*);

ICE_GRID_API void incRef(::IceProxy::IceGrid::NodeObserver*);
ICE_GRID_API void decRef(::IceProxy::IceGrid::NodeObserver*);

ICE_GRID_API void incRef(::IceGrid::AdminSession*);
ICE_GRID_API void decRef(::IceGrid::AdminSession*);

ICE_GRID_API void incRef(::IceProxy::IceGrid::AdminSession*);
ICE_GRID_API void decRef(::IceProxy::IceGrid::AdminSession*);

}

namespace IceGrid
{

typedef ::IceInternal::Handle< ::IceGrid::Admin> AdminPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::IceGrid::Admin> AdminPrx;

ICE_GRID_API void __write(::IceInternal::BasicStream*, const AdminPrx&);
ICE_GRID_API void __read(::IceInternal::BasicStream*, AdminPrx&);
ICE_GRID_API void __write(::IceInternal::BasicStream*, const AdminPtr&);
ICE_GRID_API void __patch__AdminPtr(void*, ::Ice::ObjectPtr&);

typedef ::IceInternal::Handle< ::IceGrid::RegistryObserver> RegistryObserverPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::IceGrid::RegistryObserver> RegistryObserverPrx;

ICE_GRID_API void __write(::IceInternal::BasicStream*, const RegistryObserverPrx&);
ICE_GRID_API void __read(::IceInternal::BasicStream*, RegistryObserverPrx&);
ICE_GRID_API void __write(::IceInternal::BasicStream*, const RegistryObserverPtr&);
ICE_GRID_API void __patch__RegistryObserverPtr(void*, ::Ice::ObjectPtr&);

typedef ::IceInternal::Handle< ::IceGrid::NodeObserver> NodeObserverPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::IceGrid::NodeObserver> NodeObserverPrx;

ICE_GRID_API void __write(::IceInternal::BasicStream*, const NodeObserverPrx&);
ICE_GRID_API void __read(::IceInternal::BasicStream*, NodeObserverPrx&);
ICE_GRID_API void __write(::IceInternal::BasicStream*, const NodeObserverPtr&);
ICE_GRID_API void __patch__NodeObserverPtr(void*, ::Ice::ObjectPtr&);

typedef ::IceInternal::Handle< ::IceGrid::AdminSession> AdminSessionPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::IceGrid::AdminSession> AdminSessionPrx;

ICE_GRID_API void __write(::IceInternal::BasicStream*, const AdminSessionPrx&);
ICE_GRID_API void __read(::IceInternal::BasicStream*, AdminSessionPrx&);
ICE_GRID_API void __write(::IceInternal::BasicStream*, const AdminSessionPtr&);
ICE_GRID_API void __patch__AdminSessionPtr(void*, ::Ice::ObjectPtr&);

}

namespace IceGrid
{

enum ServerState
{
    Inactive,
    Activating,
    Active,
    Deactivating,
    Destroying,
    Destroyed
};

ICE_GRID_API void __write(::IceInternal::BasicStream*, ServerState);
ICE_GRID_API void __read(::IceInternal::BasicStream*, ServerState&);

typedef ::std::map< ::std::string, ::Ice::ObjectPrx> StringObjectProxyDict;

class __U__StringObjectProxyDict { };
ICE_GRID_API void __write(::IceInternal::BasicStream*, const StringObjectProxyDict&, __U__StringObjectProxyDict);
ICE_GRID_API void __read(::IceInternal::BasicStream*, StringObjectProxyDict&, __U__StringObjectProxyDict);

struct ObjectInfo
{
    ::Ice::ObjectPrx proxy;
    ::std::string type;

    ICE_GRID_API bool operator==(const ObjectInfo&) const;
    ICE_GRID_API bool operator!=(const ObjectInfo&) const;
    ICE_GRID_API bool operator<(const ObjectInfo&) const;
    ICE_GRID_API bool operator<=(const ObjectInfo& __rhs) const
    {
	return operator<(__rhs) || operator==(__rhs);
    }
    ICE_GRID_API bool operator>(const ObjectInfo& __rhs) const
    {
	return !operator<(__rhs) && !operator==(__rhs);
    }
    ICE_GRID_API bool operator>=(const ObjectInfo& __rhs) const
    {
	return !operator<(__rhs);
    }

    ICE_GRID_API void __write(::IceInternal::BasicStream*) const;
    ICE_GRID_API void __read(::IceInternal::BasicStream*);
};

typedef ::std::vector< ::IceGrid::ObjectInfo> ObjectInfoSeq;

class __U__ObjectInfoSeq { };
ICE_GRID_API void __write(::IceInternal::BasicStream*, const ::IceGrid::ObjectInfo*, const ::IceGrid::ObjectInfo*, __U__ObjectInfoSeq);
ICE_GRID_API void __read(::IceInternal::BasicStream*, ObjectInfoSeq&, __U__ObjectInfoSeq);

struct AdapterInfo
{
    ::std::string id;
    ::Ice::ObjectPrx proxy;
    ::std::string replicaGroupId;

    ICE_GRID_API bool operator==(const AdapterInfo&) const;
    ICE_GRID_API bool operator!=(const AdapterInfo&) const;
    ICE_GRID_API bool operator<(const AdapterInfo&) const;
    ICE_GRID_API bool operator<=(const AdapterInfo& __rhs) const
    {
	return operator<(__rhs) || operator==(__rhs);
    }
    ICE_GRID_API bool operator>(const AdapterInfo& __rhs) const
    {
	return !operator<(__rhs) && !operator==(__rhs);
    }
    ICE_GRID_API bool operator>=(const AdapterInfo& __rhs) const
    {
	return !operator<(__rhs);
    }

    ICE_GRID_API void __write(::IceInternal::BasicStream*) const;
    ICE_GRID_API void __read(::IceInternal::BasicStream*);
};

typedef ::std::vector< ::IceGrid::AdapterInfo> AdapterInfoSeq;

class __U__AdapterInfoSeq { };
ICE_GRID_API void __write(::IceInternal::BasicStream*, const ::IceGrid::AdapterInfo*, const ::IceGrid::AdapterInfo*, __U__AdapterInfoSeq);
ICE_GRID_API void __read(::IceInternal::BasicStream*, AdapterInfoSeq&, __U__AdapterInfoSeq);

struct ServerInfo
{
    ::std::string application;
    ::std::string node;
    ::IceGrid::ServerDescriptorPtr descriptor;

    ICE_GRID_API bool operator==(const ServerInfo&) const;
    ICE_GRID_API bool operator!=(const ServerInfo&) const;
    ICE_GRID_API bool operator<(const ServerInfo&) const;
    ICE_GRID_API bool operator<=(const ServerInfo& __rhs) const
    {
	return operator<(__rhs) || operator==(__rhs);
    }
    ICE_GRID_API bool operator>(const ServerInfo& __rhs) const
    {
	return !operator<(__rhs) && !operator==(__rhs);
    }
    ICE_GRID_API bool operator>=(const ServerInfo& __rhs) const
    {
	return !operator<(__rhs);
    }

    ICE_GRID_API void __write(::IceInternal::BasicStream*) const;
    ICE_GRID_API void __read(::IceInternal::BasicStream*);
};

struct NodeInfo
{
    ::std::string os;
    ::std::string hostname;
    ::std::string release;
    ::std::string version;
    ::std::string machine;
    ::Ice::Int nProcessors;
    ::std::string dataDir;

    ICE_GRID_API bool operator==(const NodeInfo&) const;
    ICE_GRID_API bool operator!=(const NodeInfo&) const;
    ICE_GRID_API bool operator<(const NodeInfo&) const;
    ICE_GRID_API bool operator<=(const NodeInfo& __rhs) const
    {
	return operator<(__rhs) || operator==(__rhs);
    }
    ICE_GRID_API bool operator>(const NodeInfo& __rhs) const
    {
	return !operator<(__rhs) && !operator==(__rhs);
    }
    ICE_GRID_API bool operator>=(const NodeInfo& __rhs) const
    {
	return !operator<(__rhs);
    }

    ICE_GRID_API void __write(::IceInternal::BasicStream*) const;
    ICE_GRID_API void __read(::IceInternal::BasicStream*);
};

struct LoadInfo
{
    ::Ice::Float avg1;
    ::Ice::Float avg5;
    ::Ice::Float avg15;

    ICE_GRID_API bool operator==(const LoadInfo&) const;
    ICE_GRID_API bool operator!=(const LoadInfo&) const;
    ICE_GRID_API bool operator<(const LoadInfo&) const;
    ICE_GRID_API bool operator<=(const LoadInfo& __rhs) const
    {
	return operator<(__rhs) || operator==(__rhs);
    }
    ICE_GRID_API bool operator>(const LoadInfo& __rhs) const
    {
	return !operator<(__rhs) && !operator==(__rhs);
    }
    ICE_GRID_API bool operator>=(const LoadInfo& __rhs) const
    {
	return !operator<(__rhs);
    }

    ICE_GRID_API void __write(::IceInternal::BasicStream*) const;
    ICE_GRID_API void __read(::IceInternal::BasicStream*);
};

}

namespace IceGrid
{

class ICE_GRID_API AMI_Admin_patchApplication : public ::IceInternal::OutgoingAsync
{
public:

    virtual void ice_response() = 0;
    virtual void ice_exception(const ::Ice::Exception&) = 0;

    void __invoke(const ::IceGrid::AdminPrx&, const ::std::string&, bool, const ::Ice::Context&);

protected:

    virtual void __response(bool);
};

typedef ::IceUtil::Handle< ::IceGrid::AMI_Admin_patchApplication> AMI_Admin_patchApplicationPtr;

class ICE_GRID_API AMD_Admin_patchApplication : virtual public ::IceUtil::Shared
{
public:

    virtual void ice_response() = 0;
    virtual void ice_exception(const ::Ice::Exception&) = 0;
    virtual void ice_exception(const ::std::exception&) = 0;
    virtual void ice_exception() = 0;
};

typedef ::IceUtil::Handle< ::IceGrid::AMD_Admin_patchApplication> AMD_Admin_patchApplicationPtr;

class ICE_GRID_API AMI_Admin_enableServer : public ::IceInternal::OutgoingAsync
{
public:

    virtual void ice_response() = 0;
    virtual void ice_exception(const ::Ice::Exception&) = 0;

    void __invoke(const ::IceGrid::AdminPrx&, const ::std::string&, bool, const ::Ice::Context&);

protected:

    virtual void __response(bool);
};

typedef ::IceUtil::Handle< ::IceGrid::AMI_Admin_enableServer> AMI_Admin_enableServerPtr;

class ICE_GRID_API AMI_Admin_startServer : public ::IceInternal::OutgoingAsync
{
public:

    virtual void ice_response() = 0;
    virtual void ice_exception(const ::Ice::Exception&) = 0;

    void __invoke(const ::IceGrid::AdminPrx&, const ::std::string&, const ::Ice::Context&);

protected:

    virtual void __response(bool);
};

typedef ::IceUtil::Handle< ::IceGrid::AMI_Admin_startServer> AMI_Admin_startServerPtr;

class ICE_GRID_API AMI_Admin_stopServer : public ::IceInternal::OutgoingAsync
{
public:

    virtual void ice_response() = 0;
    virtual void ice_exception(const ::Ice::Exception&) = 0;

    void __invoke(const ::IceGrid::AdminPrx&, const ::std::string&, const ::Ice::Context&);

protected:

    virtual void __response(bool);
};

typedef ::IceUtil::Handle< ::IceGrid::AMI_Admin_stopServer> AMI_Admin_stopServerPtr;

class ICE_GRID_API AMI_Admin_patchServer : public ::IceInternal::OutgoingAsync
{
public:

    virtual void ice_response() = 0;
    virtual void ice_exception(const ::Ice::Exception&) = 0;

    void __invoke(const ::IceGrid::AdminPrx&, const ::std::string&, bool, const ::Ice::Context&);

protected:

    virtual void __response(bool);
};

typedef ::IceUtil::Handle< ::IceGrid::AMI_Admin_patchServer> AMI_Admin_patchServerPtr;

class ICE_GRID_API AMD_Admin_patchServer : virtual public ::IceUtil::Shared
{
public:

    virtual void ice_response() = 0;
    virtual void ice_exception(const ::Ice::Exception&) = 0;
    virtual void ice_exception(const ::std::exception&) = 0;
    virtual void ice_exception() = 0;
};

typedef ::IceUtil::Handle< ::IceGrid::AMD_Admin_patchServer> AMD_Admin_patchServerPtr;

class ICE_GRID_API AMI_Admin_removeAdapter : public ::IceInternal::OutgoingAsync
{
public:

    virtual void ice_response() = 0;
    virtual void ice_exception(const ::Ice::Exception&) = 0;

    void __invoke(const ::IceGrid::AdminPrx&, const ::std::string&, const ::Ice::Context&);

protected:

    virtual void __response(bool);
};

typedef ::IceUtil::Handle< ::IceGrid::AMI_Admin_removeAdapter> AMI_Admin_removeAdapterPtr;

class ICE_GRID_API AMI_Admin_removeObject : public ::IceInternal::OutgoingAsync
{
public:

    virtual void ice_response() = 0;
    virtual void ice_exception(const ::Ice::Exception&) = 0;

    void __invoke(const ::IceGrid::AdminPrx&, const ::Ice::Identity&, const ::Ice::Context&);

protected:

    virtual void __response(bool);
};

typedef ::IceUtil::Handle< ::IceGrid::AMI_Admin_removeObject> AMI_Admin_removeObjectPtr;

class ICE_GRID_API AMI_Admin_getNodeLoad : public ::IceInternal::OutgoingAsync
{
public:

    virtual void ice_response(const ::IceGrid::LoadInfo&) = 0;
    virtual void ice_exception(const ::Ice::Exception&) = 0;

    void __invoke(const ::IceGrid::AdminPrx&, const ::std::string&, const ::Ice::Context&);

protected:

    virtual void __response(bool);
};

typedef ::IceUtil::Handle< ::IceGrid::AMI_Admin_getNodeLoad> AMI_Admin_getNodeLoadPtr;

class ICE_GRID_API AMI_Admin_shutdownNode : public ::IceInternal::OutgoingAsync
{
public:

    virtual void ice_response() = 0;
    virtual void ice_exception(const ::Ice::Exception&) = 0;

    void __invoke(const ::IceGrid::AdminPrx&, const ::std::string&, const ::Ice::Context&);

protected:

    virtual void __response(bool);
};

typedef ::IceUtil::Handle< ::IceGrid::AMI_Admin_shutdownNode> AMI_Admin_shutdownNodePtr;

}

namespace IceAsync
{

namespace IceGrid
{

class ICE_GRID_API AMD_Admin_patchApplication : public ::IceGrid::AMD_Admin_patchApplication, public ::IceInternal::IncomingAsync
{
public:

    AMD_Admin_patchApplication(::IceInternal::Incoming&);

    virtual void ice_response();
    virtual void ice_exception(const ::Ice::Exception&);
    virtual void ice_exception(const ::std::exception&);
    virtual void ice_exception();
};

class ICE_GRID_API AMD_Admin_patchServer : public ::IceGrid::AMD_Admin_patchServer, public ::IceInternal::IncomingAsync
{
public:

    AMD_Admin_patchServer(::IceInternal::Incoming&);

    virtual void ice_response();
    virtual void ice_exception(const ::Ice::Exception&);
    virtual void ice_exception(const ::std::exception&);
    virtual void ice_exception();
};

}

}

namespace IceProxy
{

namespace IceGrid
{

class ICE_GRID_API Admin : virtual public ::IceProxy::Ice::Object
{
public:

    void addApplication(const ::IceGrid::ApplicationDescriptor& descriptor)
    {
	addApplication(descriptor, __defaultContext());
    }
    void addApplication(const ::IceGrid::ApplicationDescriptor&, const ::Ice::Context&);

    void syncApplication(const ::IceGrid::ApplicationDescriptor& descriptor)
    {
	syncApplication(descriptor, __defaultContext());
    }
    void syncApplication(const ::IceGrid::ApplicationDescriptor&, const ::Ice::Context&);

    void updateApplication(const ::IceGrid::ApplicationUpdateDescriptor& descriptor)
    {
	updateApplication(descriptor, __defaultContext());
    }
    void updateApplication(const ::IceGrid::ApplicationUpdateDescriptor&, const ::Ice::Context&);

    void removeApplication(const ::std::string& name)
    {
	removeApplication(name, __defaultContext());
    }
    void removeApplication(const ::std::string&, const ::Ice::Context&);

    void instantiateServer(const ::std::string& application, const ::std::string& node, const ::IceGrid::ServerInstanceDescriptor& desc)
    {
	instantiateServer(application, node, desc, __defaultContext());
    }
    void instantiateServer(const ::std::string&, const ::std::string&, const ::IceGrid::ServerInstanceDescriptor&, const ::Ice::Context&);

    void patchApplication(const ::std::string& name, bool shutdown)
    {
	patchApplication(name, shutdown, __defaultContext());
    }
    void patchApplication(const ::std::string&, bool, const ::Ice::Context&);
    void patchApplication_async(const ::IceGrid::AMI_Admin_patchApplicationPtr&, const ::std::string&, bool);
    void patchApplication_async(const ::IceGrid::AMI_Admin_patchApplicationPtr&, const ::std::string&, bool, const ::Ice::Context&);

    ::IceGrid::ApplicationDescriptor getApplicationDescriptor(const ::std::string& name)
    {
	return getApplicationDescriptor(name, __defaultContext());
    }
    ::IceGrid::ApplicationDescriptor getApplicationDescriptor(const ::std::string&, const ::Ice::Context&);

    ::IceGrid::ApplicationDescriptor getDefaultApplicationDescriptor()
    {
	return getDefaultApplicationDescriptor(__defaultContext());
    }
    ::IceGrid::ApplicationDescriptor getDefaultApplicationDescriptor(const ::Ice::Context&);

    ::Ice::StringSeq getAllApplicationNames()
    {
	return getAllApplicationNames(__defaultContext());
    }
    ::Ice::StringSeq getAllApplicationNames(const ::Ice::Context&);

    ::IceGrid::ServerInfo getServerInfo(const ::std::string& id)
    {
	return getServerInfo(id, __defaultContext());
    }
    ::IceGrid::ServerInfo getServerInfo(const ::std::string&, const ::Ice::Context&);

    ::IceGrid::ServerState getServerState(const ::std::string& id)
    {
	return getServerState(id, __defaultContext());
    }
    ::IceGrid::ServerState getServerState(const ::std::string&, const ::Ice::Context&);

    ::Ice::Int getServerPid(const ::std::string& id)
    {
	return getServerPid(id, __defaultContext());
    }
    ::Ice::Int getServerPid(const ::std::string&, const ::Ice::Context&);

    void enableServer(const ::std::string& id, bool enabled)
    {
	enableServer(id, enabled, __defaultContext());
    }
    void enableServer(const ::std::string&, bool, const ::Ice::Context&);
    void enableServer_async(const ::IceGrid::AMI_Admin_enableServerPtr&, const ::std::string&, bool);
    void enableServer_async(const ::IceGrid::AMI_Admin_enableServerPtr&, const ::std::string&, bool, const ::Ice::Context&);

    bool isServerEnabled(const ::std::string& id)
    {
	return isServerEnabled(id, __defaultContext());
    }
    bool isServerEnabled(const ::std::string&, const ::Ice::Context&);

    void startServer(const ::std::string& id)
    {
	startServer(id, __defaultContext());
    }
    void startServer(const ::std::string&, const ::Ice::Context&);
    void startServer_async(const ::IceGrid::AMI_Admin_startServerPtr&, const ::std::string&);
    void startServer_async(const ::IceGrid::AMI_Admin_startServerPtr&, const ::std::string&, const ::Ice::Context&);

    void stopServer(const ::std::string& id)
    {
	stopServer(id, __defaultContext());
    }
    void stopServer(const ::std::string&, const ::Ice::Context&);
    void stopServer_async(const ::IceGrid::AMI_Admin_stopServerPtr&, const ::std::string&);
    void stopServer_async(const ::IceGrid::AMI_Admin_stopServerPtr&, const ::std::string&, const ::Ice::Context&);

    void patchServer(const ::std::string& id, bool shutdown)
    {
	patchServer(id, shutdown, __defaultContext());
    }
    void patchServer(const ::std::string&, bool, const ::Ice::Context&);
    void patchServer_async(const ::IceGrid::AMI_Admin_patchServerPtr&, const ::std::string&, bool);
    void patchServer_async(const ::IceGrid::AMI_Admin_patchServerPtr&, const ::std::string&, bool, const ::Ice::Context&);

    void sendSignal(const ::std::string& id, const ::std::string& signal)
    {
	sendSignal(id, signal, __defaultContext());
    }
    void sendSignal(const ::std::string&, const ::std::string&, const ::Ice::Context&);

    void writeMessage(const ::std::string& id, const ::std::string& message, ::Ice::Int fd)
    {
	writeMessage(id, message, fd, __defaultContext());
    }
    void writeMessage(const ::std::string&, const ::std::string&, ::Ice::Int, const ::Ice::Context&);

    ::Ice::StringSeq getAllServerIds()
    {
	return getAllServerIds(__defaultContext());
    }
    ::Ice::StringSeq getAllServerIds(const ::Ice::Context&);

    ::IceGrid::AdapterInfoSeq getAdapterInfo(const ::std::string& id)
    {
	return getAdapterInfo(id, __defaultContext());
    }
    ::IceGrid::AdapterInfoSeq getAdapterInfo(const ::std::string&, const ::Ice::Context&);

    void removeAdapter(const ::std::string& adapterId)
    {
	removeAdapter(adapterId, __defaultContext());
    }
    void removeAdapter(const ::std::string&, const ::Ice::Context&);
    void removeAdapter_async(const ::IceGrid::AMI_Admin_removeAdapterPtr&, const ::std::string&);
    void removeAdapter_async(const ::IceGrid::AMI_Admin_removeAdapterPtr&, const ::std::string&, const ::Ice::Context&);

    ::Ice::StringSeq getAllAdapterIds()
    {
	return getAllAdapterIds(__defaultContext());
    }
    ::Ice::StringSeq getAllAdapterIds(const ::Ice::Context&);

    void addObject(const ::Ice::ObjectPrx& obj)
    {
	addObject(obj, __defaultContext());
    }
    void addObject(const ::Ice::ObjectPrx&, const ::Ice::Context&);

    void updateObject(const ::Ice::ObjectPrx& obj)
    {
	updateObject(obj, __defaultContext());
    }
    void updateObject(const ::Ice::ObjectPrx&, const ::Ice::Context&);

    void addObjectWithType(const ::Ice::ObjectPrx& obj, const ::std::string& type)
    {
	addObjectWithType(obj, type, __defaultContext());
    }
    void addObjectWithType(const ::Ice::ObjectPrx&, const ::std::string&, const ::Ice::Context&);

    void removeObject(const ::Ice::Identity& id)
    {
	removeObject(id, __defaultContext());
    }
    void removeObject(const ::Ice::Identity&, const ::Ice::Context&);
    void removeObject_async(const ::IceGrid::AMI_Admin_removeObjectPtr&, const ::Ice::Identity&);
    void removeObject_async(const ::IceGrid::AMI_Admin_removeObjectPtr&, const ::Ice::Identity&, const ::Ice::Context&);

    ::IceGrid::ObjectInfo getObjectInfo(const ::Ice::Identity& id)
    {
	return getObjectInfo(id, __defaultContext());
    }
    ::IceGrid::ObjectInfo getObjectInfo(const ::Ice::Identity&, const ::Ice::Context&);

    ::IceGrid::ObjectInfoSeq getObjectInfosByType(const ::std::string& type)
    {
	return getObjectInfosByType(type, __defaultContext());
    }
    ::IceGrid::ObjectInfoSeq getObjectInfosByType(const ::std::string&, const ::Ice::Context&);

    ::IceGrid::ObjectInfoSeq getAllObjectInfos(const ::std::string& expr)
    {
	return getAllObjectInfos(expr, __defaultContext());
    }
    ::IceGrid::ObjectInfoSeq getAllObjectInfos(const ::std::string&, const ::Ice::Context&);

    bool pingNode(const ::std::string& name)
    {
	return pingNode(name, __defaultContext());
    }
    bool pingNode(const ::std::string&, const ::Ice::Context&);

    ::IceGrid::LoadInfo getNodeLoad(const ::std::string& name)
    {
	return getNodeLoad(name, __defaultContext());
    }
    ::IceGrid::LoadInfo getNodeLoad(const ::std::string&, const ::Ice::Context&);
    void getNodeLoad_async(const ::IceGrid::AMI_Admin_getNodeLoadPtr&, const ::std::string&);
    void getNodeLoad_async(const ::IceGrid::AMI_Admin_getNodeLoadPtr&, const ::std::string&, const ::Ice::Context&);

    ::IceGrid::NodeInfo getNodeInfo(const ::std::string& name)
    {
	return getNodeInfo(name, __defaultContext());
    }
    ::IceGrid::NodeInfo getNodeInfo(const ::std::string&, const ::Ice::Context&);

    void shutdownNode(const ::std::string& name)
    {
	shutdownNode(name, __defaultContext());
    }
    void shutdownNode(const ::std::string&, const ::Ice::Context&);
    void shutdownNode_async(const ::IceGrid::AMI_Admin_shutdownNodePtr&, const ::std::string&);
    void shutdownNode_async(const ::IceGrid::AMI_Admin_shutdownNodePtr&, const ::std::string&, const ::Ice::Context&);

    ::std::string getNodeHostname(const ::std::string& name)
    {
	return getNodeHostname(name, __defaultContext());
    }
    ::std::string getNodeHostname(const ::std::string&, const ::Ice::Context&);

    ::Ice::StringSeq getAllNodeNames()
    {
	return getAllNodeNames(__defaultContext());
    }
    ::Ice::StringSeq getAllNodeNames(const ::Ice::Context&);

    void shutdown()
    {
	shutdown(__defaultContext());
    }
    void shutdown(const ::Ice::Context&);

    ::Ice::SliceChecksumDict getSliceChecksums()
    {
	return getSliceChecksums(__defaultContext());
    }
    ::Ice::SliceChecksumDict getSliceChecksums(const ::Ice::Context&);
    
    static const ::std::string& ice_staticId();

private: 

    virtual ::IceInternal::Handle< ::IceDelegateM::Ice::Object> __createDelegateM();
    virtual ::IceInternal::Handle< ::IceDelegateD::Ice::Object> __createDelegateD();
};

class ICE_GRID_API AdminSession : virtual public ::IceProxy::Glacier2::Session
{
public:

    void keepAlive()
    {
	keepAlive(__defaultContext());
    }
    void keepAlive(const ::Ice::Context&);

    ::IceGrid::AdminPrx getAdmin()
    {
	return getAdmin(__defaultContext());
    }
    ::IceGrid::AdminPrx getAdmin(const ::Ice::Context&);

    void setObservers(const ::IceGrid::RegistryObserverPrx& registryObs, const ::IceGrid::NodeObserverPrx& nodeObs)
    {
	setObservers(registryObs, nodeObs, __defaultContext());
    }
    void setObservers(const ::IceGrid::RegistryObserverPrx&, const ::IceGrid::NodeObserverPrx&, const ::Ice::Context&);

    void setObserversByIdentity(const ::Ice::Identity& registryObs, const ::Ice::Identity& nodeObs)
    {
	setObserversByIdentity(registryObs, nodeObs, __defaultContext());
    }
    void setObserversByIdentity(const ::Ice::Identity&, const ::Ice::Identity&, const ::Ice::Context&);

    ::Ice::Int startUpdate()
    {
	return startUpdate(__defaultContext());
    }
    ::Ice::Int startUpdate(const ::Ice::Context&);

    void finishUpdate()
    {
	finishUpdate(__defaultContext());
    }
    void finishUpdate(const ::Ice::Context&);
    
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

class ICE_GRID_API Admin : virtual public ::IceDelegate::Ice::Object
{
public:

    virtual void addApplication(const ::IceGrid::ApplicationDescriptor&, const ::Ice::Context&) = 0;

    virtual void syncApplication(const ::IceGrid::ApplicationDescriptor&, const ::Ice::Context&) = 0;

    virtual void updateApplication(const ::IceGrid::ApplicationUpdateDescriptor&, const ::Ice::Context&) = 0;

    virtual void removeApplication(const ::std::string&, const ::Ice::Context&) = 0;

    virtual void instantiateServer(const ::std::string&, const ::std::string&, const ::IceGrid::ServerInstanceDescriptor&, const ::Ice::Context&) = 0;

    virtual void patchApplication(const ::std::string&, bool, const ::Ice::Context&) = 0;

    virtual ::IceGrid::ApplicationDescriptor getApplicationDescriptor(const ::std::string&, const ::Ice::Context&) = 0;

    virtual ::IceGrid::ApplicationDescriptor getDefaultApplicationDescriptor(const ::Ice::Context&) = 0;

    virtual ::Ice::StringSeq getAllApplicationNames(const ::Ice::Context&) = 0;

    virtual ::IceGrid::ServerInfo getServerInfo(const ::std::string&, const ::Ice::Context&) = 0;

    virtual ::IceGrid::ServerState getServerState(const ::std::string&, const ::Ice::Context&) = 0;

    virtual ::Ice::Int getServerPid(const ::std::string&, const ::Ice::Context&) = 0;

    virtual void enableServer(const ::std::string&, bool, const ::Ice::Context&) = 0;

    virtual bool isServerEnabled(const ::std::string&, const ::Ice::Context&) = 0;

    virtual void startServer(const ::std::string&, const ::Ice::Context&) = 0;

    virtual void stopServer(const ::std::string&, const ::Ice::Context&) = 0;

    virtual void patchServer(const ::std::string&, bool, const ::Ice::Context&) = 0;

    virtual void sendSignal(const ::std::string&, const ::std::string&, const ::Ice::Context&) = 0;

    virtual void writeMessage(const ::std::string&, const ::std::string&, ::Ice::Int, const ::Ice::Context&) = 0;

    virtual ::Ice::StringSeq getAllServerIds(const ::Ice::Context&) = 0;

    virtual ::IceGrid::AdapterInfoSeq getAdapterInfo(const ::std::string&, const ::Ice::Context&) = 0;

    virtual void removeAdapter(const ::std::string&, const ::Ice::Context&) = 0;

    virtual ::Ice::StringSeq getAllAdapterIds(const ::Ice::Context&) = 0;

    virtual void addObject(const ::Ice::ObjectPrx&, const ::Ice::Context&) = 0;

    virtual void updateObject(const ::Ice::ObjectPrx&, const ::Ice::Context&) = 0;

    virtual void addObjectWithType(const ::Ice::ObjectPrx&, const ::std::string&, const ::Ice::Context&) = 0;

    virtual void removeObject(const ::Ice::Identity&, const ::Ice::Context&) = 0;

    virtual ::IceGrid::ObjectInfo getObjectInfo(const ::Ice::Identity&, const ::Ice::Context&) = 0;

    virtual ::IceGrid::ObjectInfoSeq getObjectInfosByType(const ::std::string&, const ::Ice::Context&) = 0;

    virtual ::IceGrid::ObjectInfoSeq getAllObjectInfos(const ::std::string&, const ::Ice::Context&) = 0;

    virtual bool pingNode(const ::std::string&, const ::Ice::Context&) = 0;

    virtual ::IceGrid::LoadInfo getNodeLoad(const ::std::string&, const ::Ice::Context&) = 0;

    virtual ::IceGrid::NodeInfo getNodeInfo(const ::std::string&, const ::Ice::Context&) = 0;

    virtual void shutdownNode(const ::std::string&, const ::Ice::Context&) = 0;

    virtual ::std::string getNodeHostname(const ::std::string&, const ::Ice::Context&) = 0;

    virtual ::Ice::StringSeq getAllNodeNames(const ::Ice::Context&) = 0;

    virtual void shutdown(const ::Ice::Context&) = 0;

    virtual ::Ice::SliceChecksumDict getSliceChecksums(const ::Ice::Context&) = 0;
};

class ICE_GRID_API AdminSession : virtual public ::IceDelegate::Glacier2::Session
{
public:

    virtual void keepAlive(const ::Ice::Context&) = 0;

    virtual ::IceGrid::AdminPrx getAdmin(const ::Ice::Context&) = 0;

    virtual void setObservers(const ::IceGrid::RegistryObserverPrx&, const ::IceGrid::NodeObserverPrx&, const ::Ice::Context&) = 0;

    virtual void setObserversByIdentity(const ::Ice::Identity&, const ::Ice::Identity&, const ::Ice::Context&) = 0;

    virtual ::Ice::Int startUpdate(const ::Ice::Context&) = 0;

    virtual void finishUpdate(const ::Ice::Context&) = 0;
};

}

}

namespace IceDelegateM
{

namespace IceGrid
{

class ICE_GRID_API Admin : virtual public ::IceDelegate::IceGrid::Admin,
			   virtual public ::IceDelegateM::Ice::Object
{
public:

    virtual void addApplication(const ::IceGrid::ApplicationDescriptor&, const ::Ice::Context&);

    virtual void syncApplication(const ::IceGrid::ApplicationDescriptor&, const ::Ice::Context&);

    virtual void updateApplication(const ::IceGrid::ApplicationUpdateDescriptor&, const ::Ice::Context&);

    virtual void removeApplication(const ::std::string&, const ::Ice::Context&);

    virtual void instantiateServer(const ::std::string&, const ::std::string&, const ::IceGrid::ServerInstanceDescriptor&, const ::Ice::Context&);

    virtual void patchApplication(const ::std::string&, bool, const ::Ice::Context&);

    virtual ::IceGrid::ApplicationDescriptor getApplicationDescriptor(const ::std::string&, const ::Ice::Context&);

    virtual ::IceGrid::ApplicationDescriptor getDefaultApplicationDescriptor(const ::Ice::Context&);

    virtual ::Ice::StringSeq getAllApplicationNames(const ::Ice::Context&);

    virtual ::IceGrid::ServerInfo getServerInfo(const ::std::string&, const ::Ice::Context&);

    virtual ::IceGrid::ServerState getServerState(const ::std::string&, const ::Ice::Context&);

    virtual ::Ice::Int getServerPid(const ::std::string&, const ::Ice::Context&);

    virtual void enableServer(const ::std::string&, bool, const ::Ice::Context&);

    virtual bool isServerEnabled(const ::std::string&, const ::Ice::Context&);

    virtual void startServer(const ::std::string&, const ::Ice::Context&);

    virtual void stopServer(const ::std::string&, const ::Ice::Context&);

    virtual void patchServer(const ::std::string&, bool, const ::Ice::Context&);

    virtual void sendSignal(const ::std::string&, const ::std::string&, const ::Ice::Context&);

    virtual void writeMessage(const ::std::string&, const ::std::string&, ::Ice::Int, const ::Ice::Context&);

    virtual ::Ice::StringSeq getAllServerIds(const ::Ice::Context&);

    virtual ::IceGrid::AdapterInfoSeq getAdapterInfo(const ::std::string&, const ::Ice::Context&);

    virtual void removeAdapter(const ::std::string&, const ::Ice::Context&);

    virtual ::Ice::StringSeq getAllAdapterIds(const ::Ice::Context&);

    virtual void addObject(const ::Ice::ObjectPrx&, const ::Ice::Context&);

    virtual void updateObject(const ::Ice::ObjectPrx&, const ::Ice::Context&);

    virtual void addObjectWithType(const ::Ice::ObjectPrx&, const ::std::string&, const ::Ice::Context&);

    virtual void removeObject(const ::Ice::Identity&, const ::Ice::Context&);

    virtual ::IceGrid::ObjectInfo getObjectInfo(const ::Ice::Identity&, const ::Ice::Context&);

    virtual ::IceGrid::ObjectInfoSeq getObjectInfosByType(const ::std::string&, const ::Ice::Context&);

    virtual ::IceGrid::ObjectInfoSeq getAllObjectInfos(const ::std::string&, const ::Ice::Context&);

    virtual bool pingNode(const ::std::string&, const ::Ice::Context&);

    virtual ::IceGrid::LoadInfo getNodeLoad(const ::std::string&, const ::Ice::Context&);

    virtual ::IceGrid::NodeInfo getNodeInfo(const ::std::string&, const ::Ice::Context&);

    virtual void shutdownNode(const ::std::string&, const ::Ice::Context&);

    virtual ::std::string getNodeHostname(const ::std::string&, const ::Ice::Context&);

    virtual ::Ice::StringSeq getAllNodeNames(const ::Ice::Context&);

    virtual void shutdown(const ::Ice::Context&);

    virtual ::Ice::SliceChecksumDict getSliceChecksums(const ::Ice::Context&);
};

class ICE_GRID_API AdminSession : virtual public ::IceDelegate::IceGrid::AdminSession,
				  virtual public ::IceDelegateM::Glacier2::Session
{
public:

    virtual void keepAlive(const ::Ice::Context&);

    virtual ::IceGrid::AdminPrx getAdmin(const ::Ice::Context&);

    virtual void setObservers(const ::IceGrid::RegistryObserverPrx&, const ::IceGrid::NodeObserverPrx&, const ::Ice::Context&);

    virtual void setObserversByIdentity(const ::Ice::Identity&, const ::Ice::Identity&, const ::Ice::Context&);

    virtual ::Ice::Int startUpdate(const ::Ice::Context&);

    virtual void finishUpdate(const ::Ice::Context&);
};

}

}

namespace IceDelegateD
{

namespace IceGrid
{

class ICE_GRID_API Admin : virtual public ::IceDelegate::IceGrid::Admin,
			   virtual public ::IceDelegateD::Ice::Object
{
public:

    virtual void addApplication(const ::IceGrid::ApplicationDescriptor&, const ::Ice::Context&);

    virtual void syncApplication(const ::IceGrid::ApplicationDescriptor&, const ::Ice::Context&);

    virtual void updateApplication(const ::IceGrid::ApplicationUpdateDescriptor&, const ::Ice::Context&);

    virtual void removeApplication(const ::std::string&, const ::Ice::Context&);

    virtual void instantiateServer(const ::std::string&, const ::std::string&, const ::IceGrid::ServerInstanceDescriptor&, const ::Ice::Context&);

    virtual void patchApplication(const ::std::string&, bool, const ::Ice::Context&);

    virtual ::IceGrid::ApplicationDescriptor getApplicationDescriptor(const ::std::string&, const ::Ice::Context&);

    virtual ::IceGrid::ApplicationDescriptor getDefaultApplicationDescriptor(const ::Ice::Context&);

    virtual ::Ice::StringSeq getAllApplicationNames(const ::Ice::Context&);

    virtual ::IceGrid::ServerInfo getServerInfo(const ::std::string&, const ::Ice::Context&);

    virtual ::IceGrid::ServerState getServerState(const ::std::string&, const ::Ice::Context&);

    virtual ::Ice::Int getServerPid(const ::std::string&, const ::Ice::Context&);

    virtual void enableServer(const ::std::string&, bool, const ::Ice::Context&);

    virtual bool isServerEnabled(const ::std::string&, const ::Ice::Context&);

    virtual void startServer(const ::std::string&, const ::Ice::Context&);

    virtual void stopServer(const ::std::string&, const ::Ice::Context&);

    virtual void patchServer(const ::std::string&, bool, const ::Ice::Context&);

    virtual void sendSignal(const ::std::string&, const ::std::string&, const ::Ice::Context&);

    virtual void writeMessage(const ::std::string&, const ::std::string&, ::Ice::Int, const ::Ice::Context&);

    virtual ::Ice::StringSeq getAllServerIds(const ::Ice::Context&);

    virtual ::IceGrid::AdapterInfoSeq getAdapterInfo(const ::std::string&, const ::Ice::Context&);

    virtual void removeAdapter(const ::std::string&, const ::Ice::Context&);

    virtual ::Ice::StringSeq getAllAdapterIds(const ::Ice::Context&);

    virtual void addObject(const ::Ice::ObjectPrx&, const ::Ice::Context&);

    virtual void updateObject(const ::Ice::ObjectPrx&, const ::Ice::Context&);

    virtual void addObjectWithType(const ::Ice::ObjectPrx&, const ::std::string&, const ::Ice::Context&);

    virtual void removeObject(const ::Ice::Identity&, const ::Ice::Context&);

    virtual ::IceGrid::ObjectInfo getObjectInfo(const ::Ice::Identity&, const ::Ice::Context&);

    virtual ::IceGrid::ObjectInfoSeq getObjectInfosByType(const ::std::string&, const ::Ice::Context&);

    virtual ::IceGrid::ObjectInfoSeq getAllObjectInfos(const ::std::string&, const ::Ice::Context&);

    virtual bool pingNode(const ::std::string&, const ::Ice::Context&);

    virtual ::IceGrid::LoadInfo getNodeLoad(const ::std::string&, const ::Ice::Context&);

    virtual ::IceGrid::NodeInfo getNodeInfo(const ::std::string&, const ::Ice::Context&);

    virtual void shutdownNode(const ::std::string&, const ::Ice::Context&);

    virtual ::std::string getNodeHostname(const ::std::string&, const ::Ice::Context&);

    virtual ::Ice::StringSeq getAllNodeNames(const ::Ice::Context&);

    virtual void shutdown(const ::Ice::Context&);

    virtual ::Ice::SliceChecksumDict getSliceChecksums(const ::Ice::Context&);
};

class ICE_GRID_API AdminSession : virtual public ::IceDelegate::IceGrid::AdminSession,
				  virtual public ::IceDelegateD::Glacier2::Session
{
public:

    virtual void keepAlive(const ::Ice::Context&);

    virtual ::IceGrid::AdminPrx getAdmin(const ::Ice::Context&);

    virtual void setObservers(const ::IceGrid::RegistryObserverPrx&, const ::IceGrid::NodeObserverPrx&, const ::Ice::Context&);

    virtual void setObserversByIdentity(const ::Ice::Identity&, const ::Ice::Identity&, const ::Ice::Context&);

    virtual ::Ice::Int startUpdate(const ::Ice::Context&);

    virtual void finishUpdate(const ::Ice::Context&);
};

}

}

namespace IceGrid
{

class ICE_GRID_API Admin : virtual public ::Ice::Object
{
public:

    typedef AdminPrx ProxyType;
    typedef AdminPtr PointerType;
    
    virtual ::Ice::ObjectPtr ice_clone() const;

    virtual bool ice_isA(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const;
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& = ::Ice::Current()) const;
    virtual const ::std::string& ice_id(const ::Ice::Current& = ::Ice::Current()) const;
    static const ::std::string& ice_staticId();

    virtual void addApplication(const ::IceGrid::ApplicationDescriptor&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___addApplication(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void syncApplication(const ::IceGrid::ApplicationDescriptor&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___syncApplication(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void updateApplication(const ::IceGrid::ApplicationUpdateDescriptor&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___updateApplication(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void removeApplication(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___removeApplication(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void instantiateServer(const ::std::string&, const ::std::string&, const ::IceGrid::ServerInstanceDescriptor&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___instantiateServer(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void patchApplication_async(const ::IceGrid::AMD_Admin_patchApplicationPtr&, const ::std::string&, bool, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___patchApplication(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::IceGrid::ApplicationDescriptor getApplicationDescriptor(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const = 0;
    ::IceInternal::DispatchStatus ___getApplicationDescriptor(::IceInternal::Incoming&, const ::Ice::Current&) const;

    virtual ::IceGrid::ApplicationDescriptor getDefaultApplicationDescriptor(const ::Ice::Current& = ::Ice::Current()) const = 0;
    ::IceInternal::DispatchStatus ___getDefaultApplicationDescriptor(::IceInternal::Incoming&, const ::Ice::Current&) const;

    virtual ::Ice::StringSeq getAllApplicationNames(const ::Ice::Current& = ::Ice::Current()) const = 0;
    ::IceInternal::DispatchStatus ___getAllApplicationNames(::IceInternal::Incoming&, const ::Ice::Current&) const;

    virtual ::IceGrid::ServerInfo getServerInfo(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const = 0;
    ::IceInternal::DispatchStatus ___getServerInfo(::IceInternal::Incoming&, const ::Ice::Current&) const;

    virtual ::IceGrid::ServerState getServerState(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const = 0;
    ::IceInternal::DispatchStatus ___getServerState(::IceInternal::Incoming&, const ::Ice::Current&) const;

    virtual ::Ice::Int getServerPid(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const = 0;
    ::IceInternal::DispatchStatus ___getServerPid(::IceInternal::Incoming&, const ::Ice::Current&) const;

    virtual void enableServer(const ::std::string&, bool, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___enableServer(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual bool isServerEnabled(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const = 0;
    ::IceInternal::DispatchStatus ___isServerEnabled(::IceInternal::Incoming&, const ::Ice::Current&) const;

    virtual void startServer(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___startServer(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void stopServer(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___stopServer(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void patchServer_async(const ::IceGrid::AMD_Admin_patchServerPtr&, const ::std::string&, bool, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___patchServer(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void sendSignal(const ::std::string&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___sendSignal(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void writeMessage(const ::std::string&, const ::std::string&, ::Ice::Int, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___writeMessage(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::Ice::StringSeq getAllServerIds(const ::Ice::Current& = ::Ice::Current()) const = 0;
    ::IceInternal::DispatchStatus ___getAllServerIds(::IceInternal::Incoming&, const ::Ice::Current&) const;

    virtual ::IceGrid::AdapterInfoSeq getAdapterInfo(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const = 0;
    ::IceInternal::DispatchStatus ___getAdapterInfo(::IceInternal::Incoming&, const ::Ice::Current&) const;

    virtual void removeAdapter(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___removeAdapter(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::Ice::StringSeq getAllAdapterIds(const ::Ice::Current& = ::Ice::Current()) const = 0;
    ::IceInternal::DispatchStatus ___getAllAdapterIds(::IceInternal::Incoming&, const ::Ice::Current&) const;

    virtual void addObject(const ::Ice::ObjectPrx&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___addObject(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void updateObject(const ::Ice::ObjectPrx&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___updateObject(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void addObjectWithType(const ::Ice::ObjectPrx&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___addObjectWithType(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void removeObject(const ::Ice::Identity&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___removeObject(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::IceGrid::ObjectInfo getObjectInfo(const ::Ice::Identity&, const ::Ice::Current& = ::Ice::Current()) const = 0;
    ::IceInternal::DispatchStatus ___getObjectInfo(::IceInternal::Incoming&, const ::Ice::Current&) const;

    virtual ::IceGrid::ObjectInfoSeq getObjectInfosByType(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const = 0;
    ::IceInternal::DispatchStatus ___getObjectInfosByType(::IceInternal::Incoming&, const ::Ice::Current&) const;

    virtual ::IceGrid::ObjectInfoSeq getAllObjectInfos(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const = 0;
    ::IceInternal::DispatchStatus ___getAllObjectInfos(::IceInternal::Incoming&, const ::Ice::Current&) const;

    virtual bool pingNode(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const = 0;
    ::IceInternal::DispatchStatus ___pingNode(::IceInternal::Incoming&, const ::Ice::Current&) const;

    virtual ::IceGrid::LoadInfo getNodeLoad(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const = 0;
    ::IceInternal::DispatchStatus ___getNodeLoad(::IceInternal::Incoming&, const ::Ice::Current&) const;

    virtual ::IceGrid::NodeInfo getNodeInfo(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const = 0;
    ::IceInternal::DispatchStatus ___getNodeInfo(::IceInternal::Incoming&, const ::Ice::Current&) const;

    virtual void shutdownNode(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___shutdownNode(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::std::string getNodeHostname(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const = 0;
    ::IceInternal::DispatchStatus ___getNodeHostname(::IceInternal::Incoming&, const ::Ice::Current&) const;

    virtual ::Ice::StringSeq getAllNodeNames(const ::Ice::Current& = ::Ice::Current()) const = 0;
    ::IceInternal::DispatchStatus ___getAllNodeNames(::IceInternal::Incoming&, const ::Ice::Current&) const;

    virtual void shutdown(const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___shutdown(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::Ice::SliceChecksumDict getSliceChecksums(const ::Ice::Current& = ::Ice::Current()) const = 0;
    ::IceInternal::DispatchStatus ___getSliceChecksums(::IceInternal::Incoming&, const ::Ice::Current&) const;

    virtual ::IceInternal::DispatchStatus __dispatch(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);
    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

void ICE_GRID_API __patch__AdminPtr(void*, ::Ice::ObjectPtr&);

class ICE_GRID_API AdminSession : virtual public ::Glacier2::Session
{
public:

    typedef AdminSessionPrx ProxyType;
    typedef AdminSessionPtr PointerType;
    
    virtual ::Ice::ObjectPtr ice_clone() const;

    virtual bool ice_isA(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const;
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& = ::Ice::Current()) const;
    virtual const ::std::string& ice_id(const ::Ice::Current& = ::Ice::Current()) const;
    static const ::std::string& ice_staticId();

    virtual void keepAlive(const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___keepAlive(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::IceGrid::AdminPrx getAdmin(const ::Ice::Current& = ::Ice::Current()) const = 0;
    ::IceInternal::DispatchStatus ___getAdmin(::IceInternal::Incoming&, const ::Ice::Current&) const;

    virtual void setObservers(const ::IceGrid::RegistryObserverPrx&, const ::IceGrid::NodeObserverPrx&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___setObservers(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void setObserversByIdentity(const ::Ice::Identity&, const ::Ice::Identity&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___setObserversByIdentity(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::Ice::Int startUpdate(const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___startUpdate(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void finishUpdate(const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___finishUpdate(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::IceInternal::DispatchStatus __dispatch(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);
    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

void ICE_GRID_API __patch__AdminSessionPtr(void*, ::Ice::ObjectPtr&);

}

#endif
