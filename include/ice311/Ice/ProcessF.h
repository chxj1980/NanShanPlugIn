// **********************************************************************
//
// Copyright (c) 2003-2006 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************

// Ice version 3.1.1
// Generated from file `ProcessF.ice'

#ifndef __Ice_ProcessF_h__
#define __Ice_ProcessF_h__

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

#ifndef ICE_API
#   ifdef ICE_API_EXPORTS
#       define ICE_API ICE_DECLSPEC_EXPORT
#   else
#       define ICE_API ICE_DECLSPEC_IMPORT
#   endif
#endif

namespace IceProxy
{

namespace Ice
{

class Process;
ICE_API bool operator==(const Process&, const Process&);
ICE_API bool operator!=(const Process&, const Process&);
ICE_API bool operator<(const Process&, const Process&);
ICE_API bool operator<=(const Process&, const Process&);
ICE_API bool operator>(const Process&, const Process&);
ICE_API bool operator>=(const Process&, const Process&);

}

}

namespace Ice
{

class Process;
ICE_API bool operator==(const Process&, const Process&);
ICE_API bool operator!=(const Process&, const Process&);
ICE_API bool operator<(const Process&, const Process&);
ICE_API bool operator<=(const Process&, const Process&);
ICE_API bool operator>(const Process&, const Process&);
ICE_API bool operator>=(const Process&, const Process&);

}

namespace IceInternal
{

ICE_API void incRef(::Ice::Process*);
ICE_API void decRef(::Ice::Process*);

ICE_API void incRef(::IceProxy::Ice::Process*);
ICE_API void decRef(::IceProxy::Ice::Process*);

}

namespace Ice
{

typedef ::IceInternal::Handle< ::Ice::Process> ProcessPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::Ice::Process> ProcessPrx;

ICE_API void __write(::IceInternal::BasicStream*, const ProcessPrx&);
ICE_API void __read(::IceInternal::BasicStream*, ProcessPrx&);
ICE_API void __write(::IceInternal::BasicStream*, const ProcessPtr&);
ICE_API void __patch__ProcessPtr(void*, ::Ice::ObjectPtr&);

}

namespace Ice
{

}

namespace IceProxy
{

namespace Ice
{

}

}

namespace IceDelegate
{

namespace Ice
{

}

}

namespace IceDelegateM
{

namespace Ice
{

}

}

namespace IceDelegateD
{

namespace Ice
{

}

}

#endif
