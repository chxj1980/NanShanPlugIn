// **********************************************************************
//
// Copyright (c) 2003-2006 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************

// Ice version 3.1.1
// Generated from file `PermissionsVerifierF.ice'

#ifndef __Glacier2_PermissionsVerifierF_h__
#define __Glacier2_PermissionsVerifierF_h__

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

class PermissionsVerifier;
GLACIER2_API bool operator==(const PermissionsVerifier&, const PermissionsVerifier&);
GLACIER2_API bool operator!=(const PermissionsVerifier&, const PermissionsVerifier&);
GLACIER2_API bool operator<(const PermissionsVerifier&, const PermissionsVerifier&);
GLACIER2_API bool operator<=(const PermissionsVerifier&, const PermissionsVerifier&);
GLACIER2_API bool operator>(const PermissionsVerifier&, const PermissionsVerifier&);
GLACIER2_API bool operator>=(const PermissionsVerifier&, const PermissionsVerifier&);

class SSLPermissionsVerifier;
GLACIER2_API bool operator==(const SSLPermissionsVerifier&, const SSLPermissionsVerifier&);
GLACIER2_API bool operator!=(const SSLPermissionsVerifier&, const SSLPermissionsVerifier&);
GLACIER2_API bool operator<(const SSLPermissionsVerifier&, const SSLPermissionsVerifier&);
GLACIER2_API bool operator<=(const SSLPermissionsVerifier&, const SSLPermissionsVerifier&);
GLACIER2_API bool operator>(const SSLPermissionsVerifier&, const SSLPermissionsVerifier&);
GLACIER2_API bool operator>=(const SSLPermissionsVerifier&, const SSLPermissionsVerifier&);

}

}

namespace Glacier2
{

class PermissionsVerifier;
GLACIER2_API bool operator==(const PermissionsVerifier&, const PermissionsVerifier&);
GLACIER2_API bool operator!=(const PermissionsVerifier&, const PermissionsVerifier&);
GLACIER2_API bool operator<(const PermissionsVerifier&, const PermissionsVerifier&);
GLACIER2_API bool operator<=(const PermissionsVerifier&, const PermissionsVerifier&);
GLACIER2_API bool operator>(const PermissionsVerifier&, const PermissionsVerifier&);
GLACIER2_API bool operator>=(const PermissionsVerifier&, const PermissionsVerifier&);

class SSLPermissionsVerifier;
GLACIER2_API bool operator==(const SSLPermissionsVerifier&, const SSLPermissionsVerifier&);
GLACIER2_API bool operator!=(const SSLPermissionsVerifier&, const SSLPermissionsVerifier&);
GLACIER2_API bool operator<(const SSLPermissionsVerifier&, const SSLPermissionsVerifier&);
GLACIER2_API bool operator<=(const SSLPermissionsVerifier&, const SSLPermissionsVerifier&);
GLACIER2_API bool operator>(const SSLPermissionsVerifier&, const SSLPermissionsVerifier&);
GLACIER2_API bool operator>=(const SSLPermissionsVerifier&, const SSLPermissionsVerifier&);

}

namespace IceInternal
{

GLACIER2_API void incRef(::Glacier2::PermissionsVerifier*);
GLACIER2_API void decRef(::Glacier2::PermissionsVerifier*);

GLACIER2_API void incRef(::IceProxy::Glacier2::PermissionsVerifier*);
GLACIER2_API void decRef(::IceProxy::Glacier2::PermissionsVerifier*);

GLACIER2_API void incRef(::Glacier2::SSLPermissionsVerifier*);
GLACIER2_API void decRef(::Glacier2::SSLPermissionsVerifier*);

GLACIER2_API void incRef(::IceProxy::Glacier2::SSLPermissionsVerifier*);
GLACIER2_API void decRef(::IceProxy::Glacier2::SSLPermissionsVerifier*);

}

namespace Glacier2
{

typedef ::IceInternal::Handle< ::Glacier2::PermissionsVerifier> PermissionsVerifierPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::Glacier2::PermissionsVerifier> PermissionsVerifierPrx;

GLACIER2_API void __write(::IceInternal::BasicStream*, const PermissionsVerifierPrx&);
GLACIER2_API void __read(::IceInternal::BasicStream*, PermissionsVerifierPrx&);
GLACIER2_API void __write(::IceInternal::BasicStream*, const PermissionsVerifierPtr&);
GLACIER2_API void __patch__PermissionsVerifierPtr(void*, ::Ice::ObjectPtr&);

typedef ::IceInternal::Handle< ::Glacier2::SSLPermissionsVerifier> SSLPermissionsVerifierPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::Glacier2::SSLPermissionsVerifier> SSLPermissionsVerifierPrx;

GLACIER2_API void __write(::IceInternal::BasicStream*, const SSLPermissionsVerifierPrx&);
GLACIER2_API void __read(::IceInternal::BasicStream*, SSLPermissionsVerifierPrx&);
GLACIER2_API void __write(::IceInternal::BasicStream*, const SSLPermissionsVerifierPtr&);
GLACIER2_API void __patch__SSLPermissionsVerifierPtr(void*, ::Ice::ObjectPtr&);

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
