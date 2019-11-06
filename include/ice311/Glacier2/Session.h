// **********************************************************************
//
// Copyright (c) 2003-2006 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************

// Ice version 3.1.1
// Generated from file `Session.ice'

#ifndef __Glacier2_Session_h__
#define __Glacier2_Session_h__

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
#include <Ice/Direct.h>
#include <Ice/UserExceptionFactory.h>
#include <Ice/FactoryTable.h>
#include <Ice/StreamF.h>
#include <Ice/BuiltinSequences.h>
#include <Ice/Identity.h>
#include <Glacier2/SSLInfo.h>
#include <Ice/UndefSysMacros.h>

#ifndef ICE_IGNORE_VERSION
#   if ICE_INT_VERSION / 100 != 301
#       error Ice version mismatch!
#   endif
#   if ICE_INT_VERSION % 100 < 1
#       error Ice patch level mismatch!
#   endif
#endif

#ifndef GLACIER2_API
#   ifdef GLACIER2_API_EXPORTS
#       define GLACIER2_API ICE_DECLSPEC_EXPORT
#   else
#       define GLACIER2_API ICE_DECLSPEC_IMPORT
#   endif
#endif

namespace IceProxy
{

namespace Glacier2
{

class Session;
GLACIER2_API bool operator==(const Session&, const Session&);
GLACIER2_API bool operator!=(const Session&, const Session&);
GLACIER2_API bool operator<(const Session&, const Session&);
GLACIER2_API bool operator<=(const Session&, const Session&);
GLACIER2_API bool operator>(const Session&, const Session&);
GLACIER2_API bool operator>=(const Session&, const Session&);

class StringSet;
GLACIER2_API bool operator==(const StringSet&, const StringSet&);
GLACIER2_API bool operator!=(const StringSet&, const StringSet&);
GLACIER2_API bool operator<(const StringSet&, const StringSet&);
GLACIER2_API bool operator<=(const StringSet&, const StringSet&);
GLACIER2_API bool operator>(const StringSet&, const StringSet&);
GLACIER2_API bool operator>=(const StringSet&, const StringSet&);

class IdentitySet;
GLACIER2_API bool operator==(const IdentitySet&, const IdentitySet&);
GLACIER2_API bool operator!=(const IdentitySet&, const IdentitySet&);
GLACIER2_API bool operator<(const IdentitySet&, const IdentitySet&);
GLACIER2_API bool operator<=(const IdentitySet&, const IdentitySet&);
GLACIER2_API bool operator>(const IdentitySet&, const IdentitySet&);
GLACIER2_API bool operator>=(const IdentitySet&, const IdentitySet&);

class SessionControl;
GLACIER2_API bool operator==(const SessionControl&, const SessionControl&);
GLACIER2_API bool operator!=(const SessionControl&, const SessionControl&);
GLACIER2_API bool operator<(const SessionControl&, const SessionControl&);
GLACIER2_API bool operator<=(const SessionControl&, const SessionControl&);
GLACIER2_API bool operator>(const SessionControl&, const SessionControl&);
GLACIER2_API bool operator>=(const SessionControl&, const SessionControl&);

class SessionManager;
GLACIER2_API bool operator==(const SessionManager&, const SessionManager&);
GLACIER2_API bool operator!=(const SessionManager&, const SessionManager&);
GLACIER2_API bool operator<(const SessionManager&, const SessionManager&);
GLACIER2_API bool operator<=(const SessionManager&, const SessionManager&);
GLACIER2_API bool operator>(const SessionManager&, const SessionManager&);
GLACIER2_API bool operator>=(const SessionManager&, const SessionManager&);

class SSLSessionManager;
GLACIER2_API bool operator==(const SSLSessionManager&, const SSLSessionManager&);
GLACIER2_API bool operator!=(const SSLSessionManager&, const SSLSessionManager&);
GLACIER2_API bool operator<(const SSLSessionManager&, const SSLSessionManager&);
GLACIER2_API bool operator<=(const SSLSessionManager&, const SSLSessionManager&);
GLACIER2_API bool operator>(const SSLSessionManager&, const SSLSessionManager&);
GLACIER2_API bool operator>=(const SSLSessionManager&, const SSLSessionManager&);

}

}

namespace Glacier2
{

class Session;
GLACIER2_API bool operator==(const Session&, const Session&);
GLACIER2_API bool operator!=(const Session&, const Session&);
GLACIER2_API bool operator<(const Session&, const Session&);
GLACIER2_API bool operator<=(const Session&, const Session&);
GLACIER2_API bool operator>(const Session&, const Session&);
GLACIER2_API bool operator>=(const Session&, const Session&);

class StringSet;
GLACIER2_API bool operator==(const StringSet&, const StringSet&);
GLACIER2_API bool operator!=(const StringSet&, const StringSet&);
GLACIER2_API bool operator<(const StringSet&, const StringSet&);
GLACIER2_API bool operator<=(const StringSet&, const StringSet&);
GLACIER2_API bool operator>(const StringSet&, const StringSet&);
GLACIER2_API bool operator>=(const StringSet&, const StringSet&);

class IdentitySet;
GLACIER2_API bool operator==(const IdentitySet&, const IdentitySet&);
GLACIER2_API bool operator!=(const IdentitySet&, const IdentitySet&);
GLACIER2_API bool operator<(const IdentitySet&, const IdentitySet&);
GLACIER2_API bool operator<=(const IdentitySet&, const IdentitySet&);
GLACIER2_API bool operator>(const IdentitySet&, const IdentitySet&);
GLACIER2_API bool operator>=(const IdentitySet&, const IdentitySet&);

class SessionControl;
GLACIER2_API bool operator==(const SessionControl&, const SessionControl&);
GLACIER2_API bool operator!=(const SessionControl&, const SessionControl&);
GLACIER2_API bool operator<(const SessionControl&, const SessionControl&);
GLACIER2_API bool operator<=(const SessionControl&, const SessionControl&);
GLACIER2_API bool operator>(const SessionControl&, const SessionControl&);
GLACIER2_API bool operator>=(const SessionControl&, const SessionControl&);

class SessionManager;
GLACIER2_API bool operator==(const SessionManager&, const SessionManager&);
GLACIER2_API bool operator!=(const SessionManager&, const SessionManager&);
GLACIER2_API bool operator<(const SessionManager&, const SessionManager&);
GLACIER2_API bool operator<=(const SessionManager&, const SessionManager&);
GLACIER2_API bool operator>(const SessionManager&, const SessionManager&);
GLACIER2_API bool operator>=(const SessionManager&, const SessionManager&);

class SSLSessionManager;
GLACIER2_API bool operator==(const SSLSessionManager&, const SSLSessionManager&);
GLACIER2_API bool operator!=(const SSLSessionManager&, const SSLSessionManager&);
GLACIER2_API bool operator<(const SSLSessionManager&, const SSLSessionManager&);
GLACIER2_API bool operator<=(const SSLSessionManager&, const SSLSessionManager&);
GLACIER2_API bool operator>(const SSLSessionManager&, const SSLSessionManager&);
GLACIER2_API bool operator>=(const SSLSessionManager&, const SSLSessionManager&);

}

namespace IceInternal
{

GLACIER2_API void incRef(::Glacier2::Session*);
GLACIER2_API void decRef(::Glacier2::Session*);

GLACIER2_API void incRef(::IceProxy::Glacier2::Session*);
GLACIER2_API void decRef(::IceProxy::Glacier2::Session*);

GLACIER2_API void incRef(::Glacier2::StringSet*);
GLACIER2_API void decRef(::Glacier2::StringSet*);

GLACIER2_API void incRef(::IceProxy::Glacier2::StringSet*);
GLACIER2_API void decRef(::IceProxy::Glacier2::StringSet*);

GLACIER2_API void incRef(::Glacier2::IdentitySet*);
GLACIER2_API void decRef(::Glacier2::IdentitySet*);

GLACIER2_API void incRef(::IceProxy::Glacier2::IdentitySet*);
GLACIER2_API void decRef(::IceProxy::Glacier2::IdentitySet*);

GLACIER2_API void incRef(::Glacier2::SessionControl*);
GLACIER2_API void decRef(::Glacier2::SessionControl*);

GLACIER2_API void incRef(::IceProxy::Glacier2::SessionControl*);
GLACIER2_API void decRef(::IceProxy::Glacier2::SessionControl*);

GLACIER2_API void incRef(::Glacier2::SessionManager*);
GLACIER2_API void decRef(::Glacier2::SessionManager*);

GLACIER2_API void incRef(::IceProxy::Glacier2::SessionManager*);
GLACIER2_API void decRef(::IceProxy::Glacier2::SessionManager*);

GLACIER2_API void incRef(::Glacier2::SSLSessionManager*);
GLACIER2_API void decRef(::Glacier2::SSLSessionManager*);

GLACIER2_API void incRef(::IceProxy::Glacier2::SSLSessionManager*);
GLACIER2_API void decRef(::IceProxy::Glacier2::SSLSessionManager*);

}

namespace Glacier2
{

typedef ::IceInternal::Handle< ::Glacier2::Session> SessionPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::Glacier2::Session> SessionPrx;

GLACIER2_API void __write(::IceInternal::BasicStream*, const SessionPrx&);
GLACIER2_API void __read(::IceInternal::BasicStream*, SessionPrx&);
GLACIER2_API void __write(::IceInternal::BasicStream*, const SessionPtr&);
GLACIER2_API void __patch__SessionPtr(void*, ::Ice::ObjectPtr&);

typedef ::IceInternal::Handle< ::Glacier2::StringSet> StringSetPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::Glacier2::StringSet> StringSetPrx;

GLACIER2_API void __write(::IceInternal::BasicStream*, const StringSetPrx&);
GLACIER2_API void __read(::IceInternal::BasicStream*, StringSetPrx&);
GLACIER2_API void __write(::IceInternal::BasicStream*, const StringSetPtr&);
GLACIER2_API void __patch__StringSetPtr(void*, ::Ice::ObjectPtr&);

typedef ::IceInternal::Handle< ::Glacier2::IdentitySet> IdentitySetPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::Glacier2::IdentitySet> IdentitySetPrx;

GLACIER2_API void __write(::IceInternal::BasicStream*, const IdentitySetPrx&);
GLACIER2_API void __read(::IceInternal::BasicStream*, IdentitySetPrx&);
GLACIER2_API void __write(::IceInternal::BasicStream*, const IdentitySetPtr&);
GLACIER2_API void __patch__IdentitySetPtr(void*, ::Ice::ObjectPtr&);

typedef ::IceInternal::Handle< ::Glacier2::SessionControl> SessionControlPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::Glacier2::SessionControl> SessionControlPrx;

GLACIER2_API void __write(::IceInternal::BasicStream*, const SessionControlPrx&);
GLACIER2_API void __read(::IceInternal::BasicStream*, SessionControlPrx&);
GLACIER2_API void __write(::IceInternal::BasicStream*, const SessionControlPtr&);
GLACIER2_API void __patch__SessionControlPtr(void*, ::Ice::ObjectPtr&);

typedef ::IceInternal::Handle< ::Glacier2::SessionManager> SessionManagerPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::Glacier2::SessionManager> SessionManagerPrx;

GLACIER2_API void __write(::IceInternal::BasicStream*, const SessionManagerPrx&);
GLACIER2_API void __read(::IceInternal::BasicStream*, SessionManagerPrx&);
GLACIER2_API void __write(::IceInternal::BasicStream*, const SessionManagerPtr&);
GLACIER2_API void __patch__SessionManagerPtr(void*, ::Ice::ObjectPtr&);

typedef ::IceInternal::Handle< ::Glacier2::SSLSessionManager> SSLSessionManagerPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::Glacier2::SSLSessionManager> SSLSessionManagerPrx;

GLACIER2_API void __write(::IceInternal::BasicStream*, const SSLSessionManagerPrx&);
GLACIER2_API void __read(::IceInternal::BasicStream*, SSLSessionManagerPrx&);
GLACIER2_API void __write(::IceInternal::BasicStream*, const SSLSessionManagerPtr&);
GLACIER2_API void __patch__SSLSessionManagerPtr(void*, ::Ice::ObjectPtr&);

}

namespace Glacier2
{

class GLACIER2_API CannotCreateSessionException : public ::Ice::UserException
{
public:

    CannotCreateSessionException() {}
    explicit CannotCreateSessionException(const ::std::string&);

    virtual const ::std::string ice_name() const;
    virtual ::Ice::Exception* ice_clone() const;
    virtual void ice_throw() const;

    static const ::IceInternal::UserExceptionFactoryPtr& ice_factory();

    ::std::string reason;

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);

    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

static CannotCreateSessionException __CannotCreateSessionException_init;

}

namespace Glacier2
{

class GLACIER2_API AMI_SessionControl_destroy : public ::IceInternal::OutgoingAsync
{
public:

    virtual void ice_response() = 0;
    virtual void ice_exception(const ::Ice::Exception&) = 0;

    void __invoke(const ::Glacier2::SessionControlPrx&, const ::Ice::Context&);

protected:

    virtual void __response(bool);
};

typedef ::IceUtil::Handle< ::Glacier2::AMI_SessionControl_destroy> AMI_SessionControl_destroyPtr;

}

namespace IceProxy
{

namespace Glacier2
{

class GLACIER2_API Session : virtual public ::IceProxy::Ice::Object
{
public:

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

class GLACIER2_API StringSet : virtual public ::IceProxy::Ice::Object
{
public:

    void add(const ::Ice::StringSeq& additions)
    {
	add(additions, __defaultContext());
    }
    void add(const ::Ice::StringSeq&, const ::Ice::Context&);

    void remove(const ::Ice::StringSeq& deletions)
    {
	remove(deletions, __defaultContext());
    }
    void remove(const ::Ice::StringSeq&, const ::Ice::Context&);

    ::Ice::StringSeq get()
    {
	return get(__defaultContext());
    }
    ::Ice::StringSeq get(const ::Ice::Context&);
    
    static const ::std::string& ice_staticId();

private: 

    virtual ::IceInternal::Handle< ::IceDelegateM::Ice::Object> __createDelegateM();
    virtual ::IceInternal::Handle< ::IceDelegateD::Ice::Object> __createDelegateD();
};

class GLACIER2_API IdentitySet : virtual public ::IceProxy::Ice::Object
{
public:

    void add(const ::Ice::IdentitySeq& additions)
    {
	add(additions, __defaultContext());
    }
    void add(const ::Ice::IdentitySeq&, const ::Ice::Context&);

    void remove(const ::Ice::IdentitySeq& deletions)
    {
	remove(deletions, __defaultContext());
    }
    void remove(const ::Ice::IdentitySeq&, const ::Ice::Context&);

    ::Ice::IdentitySeq get()
    {
	return get(__defaultContext());
    }
    ::Ice::IdentitySeq get(const ::Ice::Context&);
    
    static const ::std::string& ice_staticId();

private: 

    virtual ::IceInternal::Handle< ::IceDelegateM::Ice::Object> __createDelegateM();
    virtual ::IceInternal::Handle< ::IceDelegateD::Ice::Object> __createDelegateD();
};

class GLACIER2_API SessionControl : virtual public ::IceProxy::Ice::Object
{
public:

    ::Glacier2::StringSetPrx categories()
    {
	return categories(__defaultContext());
    }
    ::Glacier2::StringSetPrx categories(const ::Ice::Context&);

    ::Glacier2::StringSetPrx adapterIds()
    {
	return adapterIds(__defaultContext());
    }
    ::Glacier2::StringSetPrx adapterIds(const ::Ice::Context&);

    ::Glacier2::IdentitySetPrx identities()
    {
	return identities(__defaultContext());
    }
    ::Glacier2::IdentitySetPrx identities(const ::Ice::Context&);

    void destroy()
    {
	destroy(__defaultContext());
    }
    void destroy(const ::Ice::Context&);
    void destroy_async(const ::Glacier2::AMI_SessionControl_destroyPtr&);
    void destroy_async(const ::Glacier2::AMI_SessionControl_destroyPtr&, const ::Ice::Context&);
    
    static const ::std::string& ice_staticId();

private: 

    virtual ::IceInternal::Handle< ::IceDelegateM::Ice::Object> __createDelegateM();
    virtual ::IceInternal::Handle< ::IceDelegateD::Ice::Object> __createDelegateD();
};

class GLACIER2_API SessionManager : virtual public ::IceProxy::Ice::Object
{
public:

    ::Glacier2::SessionPrx create(const ::std::string& userId, const ::Glacier2::SessionControlPrx& control)
    {
	return create(userId, control, __defaultContext());
    }
    ::Glacier2::SessionPrx create(const ::std::string&, const ::Glacier2::SessionControlPrx&, const ::Ice::Context&);
    
    static const ::std::string& ice_staticId();

private: 

    virtual ::IceInternal::Handle< ::IceDelegateM::Ice::Object> __createDelegateM();
    virtual ::IceInternal::Handle< ::IceDelegateD::Ice::Object> __createDelegateD();
};

class GLACIER2_API SSLSessionManager : virtual public ::IceProxy::Ice::Object
{
public:

    ::Glacier2::SessionPrx create(const ::Glacier2::SSLInfo& info, const ::Glacier2::SessionControlPrx& control)
    {
	return create(info, control, __defaultContext());
    }
    ::Glacier2::SessionPrx create(const ::Glacier2::SSLInfo&, const ::Glacier2::SessionControlPrx&, const ::Ice::Context&);
    
    static const ::std::string& ice_staticId();

private: 

    virtual ::IceInternal::Handle< ::IceDelegateM::Ice::Object> __createDelegateM();
    virtual ::IceInternal::Handle< ::IceDelegateD::Ice::Object> __createDelegateD();
};

}

}

namespace IceDelegate
{

namespace Glacier2
{

class GLACIER2_API Session : virtual public ::IceDelegate::Ice::Object
{
public:

    virtual void destroy(const ::Ice::Context&) = 0;
};

class GLACIER2_API StringSet : virtual public ::IceDelegate::Ice::Object
{
public:

    virtual void add(const ::Ice::StringSeq&, const ::Ice::Context&) = 0;

    virtual void remove(const ::Ice::StringSeq&, const ::Ice::Context&) = 0;

    virtual ::Ice::StringSeq get(const ::Ice::Context&) = 0;
};

class GLACIER2_API IdentitySet : virtual public ::IceDelegate::Ice::Object
{
public:

    virtual void add(const ::Ice::IdentitySeq&, const ::Ice::Context&) = 0;

    virtual void remove(const ::Ice::IdentitySeq&, const ::Ice::Context&) = 0;

    virtual ::Ice::IdentitySeq get(const ::Ice::Context&) = 0;
};

class GLACIER2_API SessionControl : virtual public ::IceDelegate::Ice::Object
{
public:

    virtual ::Glacier2::StringSetPrx categories(const ::Ice::Context&) = 0;

    virtual ::Glacier2::StringSetPrx adapterIds(const ::Ice::Context&) = 0;

    virtual ::Glacier2::IdentitySetPrx identities(const ::Ice::Context&) = 0;

    virtual void destroy(const ::Ice::Context&) = 0;
};

class GLACIER2_API SessionManager : virtual public ::IceDelegate::Ice::Object
{
public:

    virtual ::Glacier2::SessionPrx create(const ::std::string&, const ::Glacier2::SessionControlPrx&, const ::Ice::Context&) = 0;
};

class GLACIER2_API SSLSessionManager : virtual public ::IceDelegate::Ice::Object
{
public:

    virtual ::Glacier2::SessionPrx create(const ::Glacier2::SSLInfo&, const ::Glacier2::SessionControlPrx&, const ::Ice::Context&) = 0;
};

}

}

namespace IceDelegateM
{

namespace Glacier2
{

class GLACIER2_API Session : virtual public ::IceDelegate::Glacier2::Session,
			     virtual public ::IceDelegateM::Ice::Object
{
public:

    virtual void destroy(const ::Ice::Context&);
};

class GLACIER2_API StringSet : virtual public ::IceDelegate::Glacier2::StringSet,
			       virtual public ::IceDelegateM::Ice::Object
{
public:

    virtual void add(const ::Ice::StringSeq&, const ::Ice::Context&);

    virtual void remove(const ::Ice::StringSeq&, const ::Ice::Context&);

    virtual ::Ice::StringSeq get(const ::Ice::Context&);
};

class GLACIER2_API IdentitySet : virtual public ::IceDelegate::Glacier2::IdentitySet,
				 virtual public ::IceDelegateM::Ice::Object
{
public:

    virtual void add(const ::Ice::IdentitySeq&, const ::Ice::Context&);

    virtual void remove(const ::Ice::IdentitySeq&, const ::Ice::Context&);

    virtual ::Ice::IdentitySeq get(const ::Ice::Context&);
};

class GLACIER2_API SessionControl : virtual public ::IceDelegate::Glacier2::SessionControl,
				    virtual public ::IceDelegateM::Ice::Object
{
public:

    virtual ::Glacier2::StringSetPrx categories(const ::Ice::Context&);

    virtual ::Glacier2::StringSetPrx adapterIds(const ::Ice::Context&);

    virtual ::Glacier2::IdentitySetPrx identities(const ::Ice::Context&);

    virtual void destroy(const ::Ice::Context&);
};

class GLACIER2_API SessionManager : virtual public ::IceDelegate::Glacier2::SessionManager,
				    virtual public ::IceDelegateM::Ice::Object
{
public:

    virtual ::Glacier2::SessionPrx create(const ::std::string&, const ::Glacier2::SessionControlPrx&, const ::Ice::Context&);
};

class GLACIER2_API SSLSessionManager : virtual public ::IceDelegate::Glacier2::SSLSessionManager,
				       virtual public ::IceDelegateM::Ice::Object
{
public:

    virtual ::Glacier2::SessionPrx create(const ::Glacier2::SSLInfo&, const ::Glacier2::SessionControlPrx&, const ::Ice::Context&);
};

}

}

namespace IceDelegateD
{

namespace Glacier2
{

class GLACIER2_API Session : virtual public ::IceDelegate::Glacier2::Session,
			     virtual public ::IceDelegateD::Ice::Object
{
public:

    virtual void destroy(const ::Ice::Context&);
};

class GLACIER2_API StringSet : virtual public ::IceDelegate::Glacier2::StringSet,
			       virtual public ::IceDelegateD::Ice::Object
{
public:

    virtual void add(const ::Ice::StringSeq&, const ::Ice::Context&);

    virtual void remove(const ::Ice::StringSeq&, const ::Ice::Context&);

    virtual ::Ice::StringSeq get(const ::Ice::Context&);
};

class GLACIER2_API IdentitySet : virtual public ::IceDelegate::Glacier2::IdentitySet,
				 virtual public ::IceDelegateD::Ice::Object
{
public:

    virtual void add(const ::Ice::IdentitySeq&, const ::Ice::Context&);

    virtual void remove(const ::Ice::IdentitySeq&, const ::Ice::Context&);

    virtual ::Ice::IdentitySeq get(const ::Ice::Context&);
};

class GLACIER2_API SessionControl : virtual public ::IceDelegate::Glacier2::SessionControl,
				    virtual public ::IceDelegateD::Ice::Object
{
public:

    virtual ::Glacier2::StringSetPrx categories(const ::Ice::Context&);

    virtual ::Glacier2::StringSetPrx adapterIds(const ::Ice::Context&);

    virtual ::Glacier2::IdentitySetPrx identities(const ::Ice::Context&);

    virtual void destroy(const ::Ice::Context&);
};

class GLACIER2_API SessionManager : virtual public ::IceDelegate::Glacier2::SessionManager,
				    virtual public ::IceDelegateD::Ice::Object
{
public:

    virtual ::Glacier2::SessionPrx create(const ::std::string&, const ::Glacier2::SessionControlPrx&, const ::Ice::Context&);
};

class GLACIER2_API SSLSessionManager : virtual public ::IceDelegate::Glacier2::SSLSessionManager,
				       virtual public ::IceDelegateD::Ice::Object
{
public:

    virtual ::Glacier2::SessionPrx create(const ::Glacier2::SSLInfo&, const ::Glacier2::SessionControlPrx&, const ::Ice::Context&);
};

}

}

namespace Glacier2
{

class GLACIER2_API Session : virtual public ::Ice::Object
{
public:

    typedef SessionPrx ProxyType;
    typedef SessionPtr PointerType;
    
    virtual ::Ice::ObjectPtr ice_clone() const;

    virtual bool ice_isA(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const;
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& = ::Ice::Current()) const;
    virtual const ::std::string& ice_id(const ::Ice::Current& = ::Ice::Current()) const;
    static const ::std::string& ice_staticId();

    virtual void destroy(const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___destroy(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::IceInternal::DispatchStatus __dispatch(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);
    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

void GLACIER2_API __patch__SessionPtr(void*, ::Ice::ObjectPtr&);

class GLACIER2_API StringSet : virtual public ::Ice::Object
{
public:

    typedef StringSetPrx ProxyType;
    typedef StringSetPtr PointerType;
    
    virtual ::Ice::ObjectPtr ice_clone() const;

    virtual bool ice_isA(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const;
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& = ::Ice::Current()) const;
    virtual const ::std::string& ice_id(const ::Ice::Current& = ::Ice::Current()) const;
    static const ::std::string& ice_staticId();

    virtual void add(const ::Ice::StringSeq&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___add(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void remove(const ::Ice::StringSeq&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___remove(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::Ice::StringSeq get(const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___get(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::IceInternal::DispatchStatus __dispatch(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);
    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

void GLACIER2_API __patch__StringSetPtr(void*, ::Ice::ObjectPtr&);

class GLACIER2_API IdentitySet : virtual public ::Ice::Object
{
public:

    typedef IdentitySetPrx ProxyType;
    typedef IdentitySetPtr PointerType;
    
    virtual ::Ice::ObjectPtr ice_clone() const;

    virtual bool ice_isA(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const;
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& = ::Ice::Current()) const;
    virtual const ::std::string& ice_id(const ::Ice::Current& = ::Ice::Current()) const;
    static const ::std::string& ice_staticId();

    virtual void add(const ::Ice::IdentitySeq&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___add(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void remove(const ::Ice::IdentitySeq&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___remove(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::Ice::IdentitySeq get(const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___get(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::IceInternal::DispatchStatus __dispatch(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);
    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

void GLACIER2_API __patch__IdentitySetPtr(void*, ::Ice::ObjectPtr&);

class GLACIER2_API SessionControl : virtual public ::Ice::Object
{
public:

    typedef SessionControlPrx ProxyType;
    typedef SessionControlPtr PointerType;
    
    virtual ::Ice::ObjectPtr ice_clone() const;

    virtual bool ice_isA(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const;
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& = ::Ice::Current()) const;
    virtual const ::std::string& ice_id(const ::Ice::Current& = ::Ice::Current()) const;
    static const ::std::string& ice_staticId();

    virtual ::Glacier2::StringSetPrx categories(const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___categories(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::Glacier2::StringSetPrx adapterIds(const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___adapterIds(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::Glacier2::IdentitySetPrx identities(const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___identities(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void destroy(const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___destroy(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::IceInternal::DispatchStatus __dispatch(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);
    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

void GLACIER2_API __patch__SessionControlPtr(void*, ::Ice::ObjectPtr&);

class GLACIER2_API SessionManager : virtual public ::Ice::Object
{
public:

    typedef SessionManagerPrx ProxyType;
    typedef SessionManagerPtr PointerType;
    
    virtual ::Ice::ObjectPtr ice_clone() const;

    virtual bool ice_isA(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const;
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& = ::Ice::Current()) const;
    virtual const ::std::string& ice_id(const ::Ice::Current& = ::Ice::Current()) const;
    static const ::std::string& ice_staticId();

    virtual ::Glacier2::SessionPrx create(const ::std::string&, const ::Glacier2::SessionControlPrx&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___create(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::IceInternal::DispatchStatus __dispatch(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);
    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

void GLACIER2_API __patch__SessionManagerPtr(void*, ::Ice::ObjectPtr&);

class GLACIER2_API SSLSessionManager : virtual public ::Ice::Object
{
public:

    typedef SSLSessionManagerPrx ProxyType;
    typedef SSLSessionManagerPtr PointerType;
    
    virtual ::Ice::ObjectPtr ice_clone() const;

    virtual bool ice_isA(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const;
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& = ::Ice::Current()) const;
    virtual const ::std::string& ice_id(const ::Ice::Current& = ::Ice::Current()) const;
    static const ::std::string& ice_staticId();

    virtual ::Glacier2::SessionPrx create(const ::Glacier2::SSLInfo&, const ::Glacier2::SessionControlPrx&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___create(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::IceInternal::DispatchStatus __dispatch(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);
    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

void GLACIER2_API __patch__SSLSessionManagerPtr(void*, ::Ice::ObjectPtr&);

}

#endif
