// **********************************************************************
//
// Copyright (c) 2003-2006 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************

// Ice version 3.1.1
// Generated from file `IceStorm.ice'

#ifndef __icestorm_IceStorm_h__
#define __icestorm_IceStorm_h__

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
#include <Ice/UserExceptionFactory.h>
#include <Ice/FactoryTable.h>
#include <Ice/StreamF.h>
#include <Ice/SliceChecksumDict.h>
#include <Ice/Identity.h>
#include <Ice/UndefSysMacros.h>

#ifndef ICE_IGNORE_VERSION
#   if ICE_INT_VERSION / 100 != 301
#       error Ice version mismatch!
#   endif
#   if ICE_INT_VERSION % 100 < 1
#       error Ice patch level mismatch!
#   endif
#endif

#ifndef ICE_STORM_API
#   ifdef ICE_STORM_API_EXPORTS
#       define ICE_STORM_API ICE_DECLSPEC_EXPORT
#   else
#       define ICE_STORM_API ICE_DECLSPEC_IMPORT
#   endif
#endif

namespace IceProxy
{

namespace IceStorm
{

class Topic;
ICE_STORM_API bool operator==(const Topic&, const Topic&);
ICE_STORM_API bool operator!=(const Topic&, const Topic&);
ICE_STORM_API bool operator<(const Topic&, const Topic&);
ICE_STORM_API bool operator<=(const Topic&, const Topic&);
ICE_STORM_API bool operator>(const Topic&, const Topic&);
ICE_STORM_API bool operator>=(const Topic&, const Topic&);

class TopicManager;
ICE_STORM_API bool operator==(const TopicManager&, const TopicManager&);
ICE_STORM_API bool operator!=(const TopicManager&, const TopicManager&);
ICE_STORM_API bool operator<(const TopicManager&, const TopicManager&);
ICE_STORM_API bool operator<=(const TopicManager&, const TopicManager&);
ICE_STORM_API bool operator>(const TopicManager&, const TopicManager&);
ICE_STORM_API bool operator>=(const TopicManager&, const TopicManager&);

}

}

namespace IceStorm
{

class Topic;
ICE_STORM_API bool operator==(const Topic&, const Topic&);
ICE_STORM_API bool operator!=(const Topic&, const Topic&);
ICE_STORM_API bool operator<(const Topic&, const Topic&);
ICE_STORM_API bool operator<=(const Topic&, const Topic&);
ICE_STORM_API bool operator>(const Topic&, const Topic&);
ICE_STORM_API bool operator>=(const Topic&, const Topic&);

class TopicManager;
ICE_STORM_API bool operator==(const TopicManager&, const TopicManager&);
ICE_STORM_API bool operator!=(const TopicManager&, const TopicManager&);
ICE_STORM_API bool operator<(const TopicManager&, const TopicManager&);
ICE_STORM_API bool operator<=(const TopicManager&, const TopicManager&);
ICE_STORM_API bool operator>(const TopicManager&, const TopicManager&);
ICE_STORM_API bool operator>=(const TopicManager&, const TopicManager&);

}

namespace IceInternal
{

ICE_STORM_API void incRef(::IceStorm::Topic*);
ICE_STORM_API void decRef(::IceStorm::Topic*);

ICE_STORM_API void incRef(::IceProxy::IceStorm::Topic*);
ICE_STORM_API void decRef(::IceProxy::IceStorm::Topic*);

ICE_STORM_API void incRef(::IceStorm::TopicManager*);
ICE_STORM_API void decRef(::IceStorm::TopicManager*);

ICE_STORM_API void incRef(::IceProxy::IceStorm::TopicManager*);
ICE_STORM_API void decRef(::IceProxy::IceStorm::TopicManager*);

}

namespace IceStorm
{

typedef ::IceInternal::Handle< ::IceStorm::Topic> TopicPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::IceStorm::Topic> TopicPrx;

ICE_STORM_API void __write(::IceInternal::BasicStream*, const TopicPrx&);
ICE_STORM_API void __read(::IceInternal::BasicStream*, TopicPrx&);
ICE_STORM_API void __write(::IceInternal::BasicStream*, const TopicPtr&);
ICE_STORM_API void __patch__TopicPtr(void*, ::Ice::ObjectPtr&);

typedef ::IceInternal::Handle< ::IceStorm::TopicManager> TopicManagerPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::IceStorm::TopicManager> TopicManagerPrx;

ICE_STORM_API void __write(::IceInternal::BasicStream*, const TopicManagerPrx&);
ICE_STORM_API void __read(::IceInternal::BasicStream*, TopicManagerPrx&);
ICE_STORM_API void __write(::IceInternal::BasicStream*, const TopicManagerPtr&);
ICE_STORM_API void __patch__TopicManagerPtr(void*, ::Ice::ObjectPtr&);

}

namespace IceStorm
{

struct LinkInfo
{
    ::IceStorm::TopicPrx theTopic;
    ::std::string name;
    ::Ice::Int cost;

    ICE_STORM_API bool operator==(const LinkInfo&) const;
    ICE_STORM_API bool operator!=(const LinkInfo&) const;
    ICE_STORM_API bool operator<(const LinkInfo&) const;
    ICE_STORM_API bool operator<=(const LinkInfo& __rhs) const
    {
	return operator<(__rhs) || operator==(__rhs);
    }
    ICE_STORM_API bool operator>(const LinkInfo& __rhs) const
    {
	return !operator<(__rhs) && !operator==(__rhs);
    }
    ICE_STORM_API bool operator>=(const LinkInfo& __rhs) const
    {
	return !operator<(__rhs);
    }

    ICE_STORM_API void __write(::IceInternal::BasicStream*) const;
    ICE_STORM_API void __read(::IceInternal::BasicStream*);
};

typedef ::std::vector< ::IceStorm::LinkInfo> LinkInfoSeq;

class __U__LinkInfoSeq { };
ICE_STORM_API void __write(::IceInternal::BasicStream*, const ::IceStorm::LinkInfo*, const ::IceStorm::LinkInfo*, __U__LinkInfoSeq);
ICE_STORM_API void __read(::IceInternal::BasicStream*, LinkInfoSeq&, __U__LinkInfoSeq);

typedef ::std::map< ::std::string, ::std::string> QoS;

class __U__QoS { };
ICE_STORM_API void __write(::IceInternal::BasicStream*, const QoS&, __U__QoS);
ICE_STORM_API void __read(::IceInternal::BasicStream*, QoS&, __U__QoS);

class ICE_STORM_API LinkExists : public ::Ice::UserException
{
public:

    LinkExists() {}
    explicit LinkExists(const ::std::string&);

    virtual const ::std::string ice_name() const;
    virtual ::Ice::Exception* ice_clone() const;
    virtual void ice_throw() const;

    static const ::IceInternal::UserExceptionFactoryPtr& ice_factory();

    ::std::string name;

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);

    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

static LinkExists __LinkExists_init;

class ICE_STORM_API NoSuchLink : public ::Ice::UserException
{
public:

    NoSuchLink() {}
    explicit NoSuchLink(const ::std::string&);

    virtual const ::std::string ice_name() const;
    virtual ::Ice::Exception* ice_clone() const;
    virtual void ice_throw() const;

    static const ::IceInternal::UserExceptionFactoryPtr& ice_factory();

    ::std::string name;

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);

    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

typedef ::std::map< ::std::string, ::IceStorm::TopicPrx> TopicDict;

class __U__TopicDict { };
ICE_STORM_API void __write(::IceInternal::BasicStream*, const TopicDict&, __U__TopicDict);
ICE_STORM_API void __read(::IceInternal::BasicStream*, TopicDict&, __U__TopicDict);

class ICE_STORM_API TopicExists : public ::Ice::UserException
{
public:

    TopicExists() {}
    explicit TopicExists(const ::std::string&);

    virtual const ::std::string ice_name() const;
    virtual ::Ice::Exception* ice_clone() const;
    virtual void ice_throw() const;

    static const ::IceInternal::UserExceptionFactoryPtr& ice_factory();

    ::std::string name;

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);

    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

class ICE_STORM_API NoSuchTopic : public ::Ice::UserException
{
public:

    NoSuchTopic() {}
    explicit NoSuchTopic(const ::std::string&);

    virtual const ::std::string ice_name() const;
    virtual ::Ice::Exception* ice_clone() const;
    virtual void ice_throw() const;

    static const ::IceInternal::UserExceptionFactoryPtr& ice_factory();

    ::std::string name;

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);

    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

}

namespace IceProxy
{

namespace IceStorm
{

class ICE_STORM_API Topic : virtual public ::IceProxy::Ice::Object
{
public:

    ::std::string getName()
    {
	return getName(__defaultContext());
    }
    ::std::string getName(const ::Ice::Context&);

    ::Ice::ObjectPrx getPublisher()
    {
	return getPublisher(__defaultContext());
    }
    ::Ice::ObjectPrx getPublisher(const ::Ice::Context&);

    void subscribe(const ::IceStorm::QoS& theQoS, const ::Ice::ObjectPrx& subscriber)
    {
	subscribe(theQoS, subscriber, __defaultContext());
    }
    void subscribe(const ::IceStorm::QoS&, const ::Ice::ObjectPrx&, const ::Ice::Context&);

    void unsubscribe(const ::Ice::ObjectPrx& subscriber)
    {
	unsubscribe(subscriber, __defaultContext());
    }
    void unsubscribe(const ::Ice::ObjectPrx&, const ::Ice::Context&);

    void link(const ::IceStorm::TopicPrx& linkTo, ::Ice::Int cost)
    {
	link(linkTo, cost, __defaultContext());
    }
    void link(const ::IceStorm::TopicPrx&, ::Ice::Int, const ::Ice::Context&);

    void unlink(const ::IceStorm::TopicPrx& linkTo)
    {
	unlink(linkTo, __defaultContext());
    }
    void unlink(const ::IceStorm::TopicPrx&, const ::Ice::Context&);

    ::IceStorm::LinkInfoSeq getLinkInfoSeq()
    {
	return getLinkInfoSeq(__defaultContext());
    }
    ::IceStorm::LinkInfoSeq getLinkInfoSeq(const ::Ice::Context&);

    void destroy()
    {
	destroy(__defaultContext());
    }
    void destroy(const ::Ice::Context&);
    
    static const ::std::string& ice_staticId();

private: 

    virtual ::IceInternal::Handle< ::IceDelegateM::Ice::Object> __createDelegateM();
    virtual ::IceInternal::Handle< ::IceDelegateD::Ice::Object> __createDelegateD();
};

class ICE_STORM_API TopicManager : virtual public ::IceProxy::Ice::Object
{
public:

    ::IceStorm::TopicPrx create(const ::std::string& name)
    {
	return create(name, __defaultContext());
    }
    ::IceStorm::TopicPrx create(const ::std::string&, const ::Ice::Context&);

    ::IceStorm::TopicPrx retrieve(const ::std::string& name)
    {
	return retrieve(name, __defaultContext());
    }
    ::IceStorm::TopicPrx retrieve(const ::std::string&, const ::Ice::Context&);

    ::IceStorm::TopicDict retrieveAll()
    {
	return retrieveAll(__defaultContext());
    }
    ::IceStorm::TopicDict retrieveAll(const ::Ice::Context&);

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

}

}

namespace IceDelegate
{

namespace IceStorm
{

class ICE_STORM_API Topic : virtual public ::IceDelegate::Ice::Object
{
public:

    virtual ::std::string getName(const ::Ice::Context&) = 0;

    virtual ::Ice::ObjectPrx getPublisher(const ::Ice::Context&) = 0;

    virtual void subscribe(const ::IceStorm::QoS&, const ::Ice::ObjectPrx&, const ::Ice::Context&) = 0;

    virtual void unsubscribe(const ::Ice::ObjectPrx&, const ::Ice::Context&) = 0;

    virtual void link(const ::IceStorm::TopicPrx&, ::Ice::Int, const ::Ice::Context&) = 0;

    virtual void unlink(const ::IceStorm::TopicPrx&, const ::Ice::Context&) = 0;

    virtual ::IceStorm::LinkInfoSeq getLinkInfoSeq(const ::Ice::Context&) = 0;

    virtual void destroy(const ::Ice::Context&) = 0;
};

class ICE_STORM_API TopicManager : virtual public ::IceDelegate::Ice::Object
{
public:

    virtual ::IceStorm::TopicPrx create(const ::std::string&, const ::Ice::Context&) = 0;

    virtual ::IceStorm::TopicPrx retrieve(const ::std::string&, const ::Ice::Context&) = 0;

    virtual ::IceStorm::TopicDict retrieveAll(const ::Ice::Context&) = 0;

    virtual ::Ice::SliceChecksumDict getSliceChecksums(const ::Ice::Context&) = 0;
};

}

}

namespace IceDelegateM
{

namespace IceStorm
{

class ICE_STORM_API Topic : virtual public ::IceDelegate::IceStorm::Topic,
			    virtual public ::IceDelegateM::Ice::Object
{
public:

    virtual ::std::string getName(const ::Ice::Context&);

    virtual ::Ice::ObjectPrx getPublisher(const ::Ice::Context&);

    virtual void subscribe(const ::IceStorm::QoS&, const ::Ice::ObjectPrx&, const ::Ice::Context&);

    virtual void unsubscribe(const ::Ice::ObjectPrx&, const ::Ice::Context&);

    virtual void link(const ::IceStorm::TopicPrx&, ::Ice::Int, const ::Ice::Context&);

    virtual void unlink(const ::IceStorm::TopicPrx&, const ::Ice::Context&);

    virtual ::IceStorm::LinkInfoSeq getLinkInfoSeq(const ::Ice::Context&);

    virtual void destroy(const ::Ice::Context&);
};

class ICE_STORM_API TopicManager : virtual public ::IceDelegate::IceStorm::TopicManager,
				   virtual public ::IceDelegateM::Ice::Object
{
public:

    virtual ::IceStorm::TopicPrx create(const ::std::string&, const ::Ice::Context&);

    virtual ::IceStorm::TopicPrx retrieve(const ::std::string&, const ::Ice::Context&);

    virtual ::IceStorm::TopicDict retrieveAll(const ::Ice::Context&);

    virtual ::Ice::SliceChecksumDict getSliceChecksums(const ::Ice::Context&);
};

}

}

namespace IceDelegateD
{

namespace IceStorm
{

class ICE_STORM_API Topic : virtual public ::IceDelegate::IceStorm::Topic,
			    virtual public ::IceDelegateD::Ice::Object
{
public:

    virtual ::std::string getName(const ::Ice::Context&);

    virtual ::Ice::ObjectPrx getPublisher(const ::Ice::Context&);

    virtual void subscribe(const ::IceStorm::QoS&, const ::Ice::ObjectPrx&, const ::Ice::Context&);

    virtual void unsubscribe(const ::Ice::ObjectPrx&, const ::Ice::Context&);

    virtual void link(const ::IceStorm::TopicPrx&, ::Ice::Int, const ::Ice::Context&);

    virtual void unlink(const ::IceStorm::TopicPrx&, const ::Ice::Context&);

    virtual ::IceStorm::LinkInfoSeq getLinkInfoSeq(const ::Ice::Context&);

    virtual void destroy(const ::Ice::Context&);
};

class ICE_STORM_API TopicManager : virtual public ::IceDelegate::IceStorm::TopicManager,
				   virtual public ::IceDelegateD::Ice::Object
{
public:

    virtual ::IceStorm::TopicPrx create(const ::std::string&, const ::Ice::Context&);

    virtual ::IceStorm::TopicPrx retrieve(const ::std::string&, const ::Ice::Context&);

    virtual ::IceStorm::TopicDict retrieveAll(const ::Ice::Context&);

    virtual ::Ice::SliceChecksumDict getSliceChecksums(const ::Ice::Context&);
};

}

}

namespace IceStorm
{

class ICE_STORM_API Topic : virtual public ::Ice::Object
{
public:

    typedef TopicPrx ProxyType;
    typedef TopicPtr PointerType;
    
    virtual ::Ice::ObjectPtr ice_clone() const;

    virtual bool ice_isA(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const;
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& = ::Ice::Current()) const;
    virtual const ::std::string& ice_id(const ::Ice::Current& = ::Ice::Current()) const;
    static const ::std::string& ice_staticId();

    virtual ::std::string getName(const ::Ice::Current& = ::Ice::Current()) const = 0;
    ::IceInternal::DispatchStatus ___getName(::IceInternal::Incoming&, const ::Ice::Current&) const;

    virtual ::Ice::ObjectPrx getPublisher(const ::Ice::Current& = ::Ice::Current()) const = 0;
    ::IceInternal::DispatchStatus ___getPublisher(::IceInternal::Incoming&, const ::Ice::Current&) const;

    virtual void subscribe(const ::IceStorm::QoS&, const ::Ice::ObjectPrx&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___subscribe(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void unsubscribe(const ::Ice::ObjectPrx&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___unsubscribe(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void link(const ::IceStorm::TopicPrx&, ::Ice::Int, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___link(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void unlink(const ::IceStorm::TopicPrx&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___unlink(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::IceStorm::LinkInfoSeq getLinkInfoSeq(const ::Ice::Current& = ::Ice::Current()) const = 0;
    ::IceInternal::DispatchStatus ___getLinkInfoSeq(::IceInternal::Incoming&, const ::Ice::Current&) const;

    virtual void destroy(const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___destroy(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::IceInternal::DispatchStatus __dispatch(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);
    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

void ICE_STORM_API __patch__TopicPtr(void*, ::Ice::ObjectPtr&);

class ICE_STORM_API TopicManager : virtual public ::Ice::Object
{
public:

    typedef TopicManagerPrx ProxyType;
    typedef TopicManagerPtr PointerType;
    
    virtual ::Ice::ObjectPtr ice_clone() const;

    virtual bool ice_isA(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const;
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& = ::Ice::Current()) const;
    virtual const ::std::string& ice_id(const ::Ice::Current& = ::Ice::Current()) const;
    static const ::std::string& ice_staticId();

    virtual ::IceStorm::TopicPrx create(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___create(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::IceStorm::TopicPrx retrieve(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const = 0;
    ::IceInternal::DispatchStatus ___retrieve(::IceInternal::Incoming&, const ::Ice::Current&) const;

    virtual ::IceStorm::TopicDict retrieveAll(const ::Ice::Current& = ::Ice::Current()) const = 0;
    ::IceInternal::DispatchStatus ___retrieveAll(::IceInternal::Incoming&, const ::Ice::Current&) const;

    virtual ::Ice::SliceChecksumDict getSliceChecksums(const ::Ice::Current& = ::Ice::Current()) const = 0;
    ::IceInternal::DispatchStatus ___getSliceChecksums(::IceInternal::Incoming&, const ::Ice::Current&) const;

    virtual ::IceInternal::DispatchStatus __dispatch(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);
    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

void ICE_STORM_API __patch__TopicManagerPtr(void*, ::Ice::ObjectPtr&);

}

#endif
