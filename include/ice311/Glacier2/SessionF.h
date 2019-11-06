// **********************************************************************
//
// Copyright (c) 2003-2006 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************

// Ice version 3.1.1
// Generated from file `SessionF.ice'

#ifndef __Glacier2_SessionF_h__
#define __Glacier2_SessionF_h__

#include <Ice/LocalObjectF.h>
#include <Ice/ProxyF.h>
#include <Ice/ObjectF.h>
#include <Ice/Exception.h>
#include <Ice/LocalObject.h>
#include <Ice/Proxy.h>
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

}

namespace IceProxy
{

namespace Glacier2
{

}

}

namespace IceDelegate
{

namespace Glacier2
{

}

}

namespace IceDelegateM
{

namespace Glacier2
{

}

}

namespace IceDelegateD
{

namespace Glacier2
{

}

}

#endif
