// **********************************************************************
//
// Copyright (c) 2003-2006 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************

// Ice version 3.1.1
// Generated from file `Query.ice'

#ifndef __icegrid_Query_h__
#define __icegrid_Query_h__

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
#include <IceGrid/Exception.h>
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

class Query;
ICE_GRID_API bool operator==(const Query&, const Query&);
ICE_GRID_API bool operator!=(const Query&, const Query&);
ICE_GRID_API bool operator<(const Query&, const Query&);
ICE_GRID_API bool operator<=(const Query&, const Query&);
ICE_GRID_API bool operator>(const Query&, const Query&);
ICE_GRID_API bool operator>=(const Query&, const Query&);

}

}

namespace IceGrid
{

class Query;
ICE_GRID_API bool operator==(const Query&, const Query&);
ICE_GRID_API bool operator!=(const Query&, const Query&);
ICE_GRID_API bool operator<(const Query&, const Query&);
ICE_GRID_API bool operator<=(const Query&, const Query&);
ICE_GRID_API bool operator>(const Query&, const Query&);
ICE_GRID_API bool operator>=(const Query&, const Query&);

}

namespace IceInternal
{

ICE_GRID_API void incRef(::IceGrid::Query*);
ICE_GRID_API void decRef(::IceGrid::Query*);

ICE_GRID_API void incRef(::IceProxy::IceGrid::Query*);
ICE_GRID_API void decRef(::IceProxy::IceGrid::Query*);

}

namespace IceGrid
{

typedef ::IceInternal::Handle< ::IceGrid::Query> QueryPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::IceGrid::Query> QueryPrx;

ICE_GRID_API void __write(::IceInternal::BasicStream*, const QueryPrx&);
ICE_GRID_API void __read(::IceInternal::BasicStream*, QueryPrx&);
ICE_GRID_API void __write(::IceInternal::BasicStream*, const QueryPtr&);
ICE_GRID_API void __patch__QueryPtr(void*, ::Ice::ObjectPtr&);

}

namespace IceGrid
{

enum LoadSample
{
    LoadSample1,
    LoadSample5,
    LoadSample15
};

ICE_GRID_API void __write(::IceInternal::BasicStream*, LoadSample);
ICE_GRID_API void __read(::IceInternal::BasicStream*, LoadSample&);

}

namespace IceGrid
{

class ICE_GRID_API AMI_Query_findObjectById : public ::IceInternal::OutgoingAsync
{
public:

    virtual void ice_response(const ::Ice::ObjectPrx&) = 0;
    virtual void ice_exception(const ::Ice::Exception&) = 0;

    void __invoke(const ::IceGrid::QueryPrx&, const ::Ice::Identity&, const ::Ice::Context&);

protected:

    virtual void __response(bool);
};

typedef ::IceUtil::Handle< ::IceGrid::AMI_Query_findObjectById> AMI_Query_findObjectByIdPtr;

class ICE_GRID_API AMD_Query_findObjectById : virtual public ::IceUtil::Shared
{
public:

    virtual void ice_response(const ::Ice::ObjectPrx&) = 0;
    virtual void ice_exception(const ::Ice::Exception&) = 0;
    virtual void ice_exception(const ::std::exception&) = 0;
    virtual void ice_exception() = 0;
};

typedef ::IceUtil::Handle< ::IceGrid::AMD_Query_findObjectById> AMD_Query_findObjectByIdPtr;

class ICE_GRID_API AMI_Query_findObjectByType : public ::IceInternal::OutgoingAsync
{
public:

    virtual void ice_response(const ::Ice::ObjectPrx&) = 0;
    virtual void ice_exception(const ::Ice::Exception&) = 0;

    void __invoke(const ::IceGrid::QueryPrx&, const ::std::string&, const ::Ice::Context&);

protected:

    virtual void __response(bool);
};

typedef ::IceUtil::Handle< ::IceGrid::AMI_Query_findObjectByType> AMI_Query_findObjectByTypePtr;

class ICE_GRID_API AMD_Query_findObjectByType : virtual public ::IceUtil::Shared
{
public:

    virtual void ice_response(const ::Ice::ObjectPrx&) = 0;
    virtual void ice_exception(const ::Ice::Exception&) = 0;
    virtual void ice_exception(const ::std::exception&) = 0;
    virtual void ice_exception() = 0;
};

typedef ::IceUtil::Handle< ::IceGrid::AMD_Query_findObjectByType> AMD_Query_findObjectByTypePtr;

class ICE_GRID_API AMI_Query_findObjectByTypeOnLeastLoadedNode : public ::IceInternal::OutgoingAsync
{
public:

    virtual void ice_response(const ::Ice::ObjectPrx&) = 0;
    virtual void ice_exception(const ::Ice::Exception&) = 0;

    void __invoke(const ::IceGrid::QueryPrx&, const ::std::string&, ::IceGrid::LoadSample, const ::Ice::Context&);

protected:

    virtual void __response(bool);
};

typedef ::IceUtil::Handle< ::IceGrid::AMI_Query_findObjectByTypeOnLeastLoadedNode> AMI_Query_findObjectByTypeOnLeastLoadedNodePtr;

class ICE_GRID_API AMD_Query_findObjectByTypeOnLeastLoadedNode : virtual public ::IceUtil::Shared
{
public:

    virtual void ice_response(const ::Ice::ObjectPrx&) = 0;
    virtual void ice_exception(const ::Ice::Exception&) = 0;
    virtual void ice_exception(const ::std::exception&) = 0;
    virtual void ice_exception() = 0;
};

typedef ::IceUtil::Handle< ::IceGrid::AMD_Query_findObjectByTypeOnLeastLoadedNode> AMD_Query_findObjectByTypeOnLeastLoadedNodePtr;

class ICE_GRID_API AMI_Query_findAllObjectsByType : public ::IceInternal::OutgoingAsync
{
public:

    virtual void ice_response(const ::Ice::ObjectProxySeq&) = 0;
    virtual void ice_exception(const ::Ice::Exception&) = 0;

    void __invoke(const ::IceGrid::QueryPrx&, const ::std::string&, const ::Ice::Context&);

protected:

    virtual void __response(bool);
};

typedef ::IceUtil::Handle< ::IceGrid::AMI_Query_findAllObjectsByType> AMI_Query_findAllObjectsByTypePtr;

class ICE_GRID_API AMD_Query_findAllObjectsByType : virtual public ::IceUtil::Shared
{
public:

    virtual void ice_response(const ::Ice::ObjectProxySeq&) = 0;
    virtual void ice_exception(const ::Ice::Exception&) = 0;
    virtual void ice_exception(const ::std::exception&) = 0;
    virtual void ice_exception() = 0;
};

typedef ::IceUtil::Handle< ::IceGrid::AMD_Query_findAllObjectsByType> AMD_Query_findAllObjectsByTypePtr;

}

namespace IceAsync
{

namespace IceGrid
{

class ICE_GRID_API AMD_Query_findObjectById : public ::IceGrid::AMD_Query_findObjectById, public ::IceInternal::IncomingAsync
{
public:

    AMD_Query_findObjectById(::IceInternal::Incoming&);

    virtual void ice_response(const ::Ice::ObjectPrx&);
    virtual void ice_exception(const ::Ice::Exception&);
    virtual void ice_exception(const ::std::exception&);
    virtual void ice_exception();
};

class ICE_GRID_API AMD_Query_findObjectByType : public ::IceGrid::AMD_Query_findObjectByType, public ::IceInternal::IncomingAsync
{
public:

    AMD_Query_findObjectByType(::IceInternal::Incoming&);

    virtual void ice_response(const ::Ice::ObjectPrx&);
    virtual void ice_exception(const ::Ice::Exception&);
    virtual void ice_exception(const ::std::exception&);
    virtual void ice_exception();
};

class ICE_GRID_API AMD_Query_findObjectByTypeOnLeastLoadedNode : public ::IceGrid::AMD_Query_findObjectByTypeOnLeastLoadedNode, public ::IceInternal::IncomingAsync
{
public:

    AMD_Query_findObjectByTypeOnLeastLoadedNode(::IceInternal::Incoming&);

    virtual void ice_response(const ::Ice::ObjectPrx&);
    virtual void ice_exception(const ::Ice::Exception&);
    virtual void ice_exception(const ::std::exception&);
    virtual void ice_exception();
};

class ICE_GRID_API AMD_Query_findAllObjectsByType : public ::IceGrid::AMD_Query_findAllObjectsByType, public ::IceInternal::IncomingAsync
{
public:

    AMD_Query_findAllObjectsByType(::IceInternal::Incoming&);

    virtual void ice_response(const ::Ice::ObjectProxySeq&);
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

class ICE_GRID_API Query : virtual public ::IceProxy::Ice::Object
{
public:

    ::Ice::ObjectPrx findObjectById(const ::Ice::Identity& id)
    {
	return findObjectById(id, __defaultContext());
    }
    ::Ice::ObjectPrx findObjectById(const ::Ice::Identity&, const ::Ice::Context&);
    void findObjectById_async(const ::IceGrid::AMI_Query_findObjectByIdPtr&, const ::Ice::Identity&);
    void findObjectById_async(const ::IceGrid::AMI_Query_findObjectByIdPtr&, const ::Ice::Identity&, const ::Ice::Context&);

    ::Ice::ObjectPrx findObjectByType(const ::std::string& type)
    {
	return findObjectByType(type, __defaultContext());
    }
    ::Ice::ObjectPrx findObjectByType(const ::std::string&, const ::Ice::Context&);
    void findObjectByType_async(const ::IceGrid::AMI_Query_findObjectByTypePtr&, const ::std::string&);
    void findObjectByType_async(const ::IceGrid::AMI_Query_findObjectByTypePtr&, const ::std::string&, const ::Ice::Context&);

    ::Ice::ObjectPrx findObjectByTypeOnLeastLoadedNode(const ::std::string& type, ::IceGrid::LoadSample sample)
    {
	return findObjectByTypeOnLeastLoadedNode(type, sample, __defaultContext());
    }
    ::Ice::ObjectPrx findObjectByTypeOnLeastLoadedNode(const ::std::string&, ::IceGrid::LoadSample, const ::Ice::Context&);
    void findObjectByTypeOnLeastLoadedNode_async(const ::IceGrid::AMI_Query_findObjectByTypeOnLeastLoadedNodePtr&, const ::std::string&, ::IceGrid::LoadSample);
    void findObjectByTypeOnLeastLoadedNode_async(const ::IceGrid::AMI_Query_findObjectByTypeOnLeastLoadedNodePtr&, const ::std::string&, ::IceGrid::LoadSample, const ::Ice::Context&);

    ::Ice::ObjectProxySeq findAllObjectsByType(const ::std::string& type)
    {
	return findAllObjectsByType(type, __defaultContext());
    }
    ::Ice::ObjectProxySeq findAllObjectsByType(const ::std::string&, const ::Ice::Context&);
    void findAllObjectsByType_async(const ::IceGrid::AMI_Query_findAllObjectsByTypePtr&, const ::std::string&);
    void findAllObjectsByType_async(const ::IceGrid::AMI_Query_findAllObjectsByTypePtr&, const ::std::string&, const ::Ice::Context&);
    
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

class ICE_GRID_API Query : virtual public ::IceDelegate::Ice::Object
{
public:

    virtual ::Ice::ObjectPrx findObjectById(const ::Ice::Identity&, const ::Ice::Context&) = 0;

    virtual ::Ice::ObjectPrx findObjectByType(const ::std::string&, const ::Ice::Context&) = 0;

    virtual ::Ice::ObjectPrx findObjectByTypeOnLeastLoadedNode(const ::std::string&, ::IceGrid::LoadSample, const ::Ice::Context&) = 0;

    virtual ::Ice::ObjectProxySeq findAllObjectsByType(const ::std::string&, const ::Ice::Context&) = 0;
};

}

}

namespace IceDelegateM
{

namespace IceGrid
{

class ICE_GRID_API Query : virtual public ::IceDelegate::IceGrid::Query,
			   virtual public ::IceDelegateM::Ice::Object
{
public:

    virtual ::Ice::ObjectPrx findObjectById(const ::Ice::Identity&, const ::Ice::Context&);

    virtual ::Ice::ObjectPrx findObjectByType(const ::std::string&, const ::Ice::Context&);

    virtual ::Ice::ObjectPrx findObjectByTypeOnLeastLoadedNode(const ::std::string&, ::IceGrid::LoadSample, const ::Ice::Context&);

    virtual ::Ice::ObjectProxySeq findAllObjectsByType(const ::std::string&, const ::Ice::Context&);
};

}

}

namespace IceDelegateD
{

namespace IceGrid
{

class ICE_GRID_API Query : virtual public ::IceDelegate::IceGrid::Query,
			   virtual public ::IceDelegateD::Ice::Object
{
public:

    virtual ::Ice::ObjectPrx findObjectById(const ::Ice::Identity&, const ::Ice::Context&);

    virtual ::Ice::ObjectPrx findObjectByType(const ::std::string&, const ::Ice::Context&);

    virtual ::Ice::ObjectPrx findObjectByTypeOnLeastLoadedNode(const ::std::string&, ::IceGrid::LoadSample, const ::Ice::Context&);

    virtual ::Ice::ObjectProxySeq findAllObjectsByType(const ::std::string&, const ::Ice::Context&);
};

}

}

namespace IceGrid
{

class ICE_GRID_API Query : virtual public ::Ice::Object
{
public:

    typedef QueryPrx ProxyType;
    typedef QueryPtr PointerType;
    
    virtual ::Ice::ObjectPtr ice_clone() const;

    virtual bool ice_isA(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const;
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& = ::Ice::Current()) const;
    virtual const ::std::string& ice_id(const ::Ice::Current& = ::Ice::Current()) const;
    static const ::std::string& ice_staticId();

    virtual void findObjectById_async(const ::IceGrid::AMD_Query_findObjectByIdPtr&, const ::Ice::Identity&, const ::Ice::Current& = ::Ice::Current()) const = 0;
    ::IceInternal::DispatchStatus ___findObjectById(::IceInternal::Incoming&, const ::Ice::Current&) const;

    virtual void findObjectByType_async(const ::IceGrid::AMD_Query_findObjectByTypePtr&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const = 0;
    ::IceInternal::DispatchStatus ___findObjectByType(::IceInternal::Incoming&, const ::Ice::Current&) const;

    virtual void findObjectByTypeOnLeastLoadedNode_async(const ::IceGrid::AMD_Query_findObjectByTypeOnLeastLoadedNodePtr&, const ::std::string&, ::IceGrid::LoadSample, const ::Ice::Current& = ::Ice::Current()) const = 0;
    ::IceInternal::DispatchStatus ___findObjectByTypeOnLeastLoadedNode(::IceInternal::Incoming&, const ::Ice::Current&) const;

    virtual void findAllObjectsByType_async(const ::IceGrid::AMD_Query_findAllObjectsByTypePtr&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const = 0;
    ::IceInternal::DispatchStatus ___findAllObjectsByType(::IceInternal::Incoming&, const ::Ice::Current&) const;

    virtual ::IceInternal::DispatchStatus __dispatch(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);
    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

void ICE_GRID_API __patch__QueryPtr(void*, ::Ice::ObjectPtr&);

}

#endif
