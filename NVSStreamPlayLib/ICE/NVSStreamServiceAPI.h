// **********************************************************************
//
// Copyright (c) 2003-2006 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************

// Ice version 3.1.1
// Generated from file `NVSStreamServiceAPI.ice'

#ifndef __NVSStreamServiceAPI_h__
#define __NVSStreamServiceAPI_h__

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
#include <Ice/StreamF.h>
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

namespace IceProxy
{

namespace NVSStreamService
{

class NVSStreamDataReceiver;
bool operator==(const NVSStreamDataReceiver&, const NVSStreamDataReceiver&);
bool operator!=(const NVSStreamDataReceiver&, const NVSStreamDataReceiver&);
bool operator<(const NVSStreamDataReceiver&, const NVSStreamDataReceiver&);
bool operator<=(const NVSStreamDataReceiver&, const NVSStreamDataReceiver&);
bool operator>(const NVSStreamDataReceiver&, const NVSStreamDataReceiver&);
bool operator>=(const NVSStreamDataReceiver&, const NVSStreamDataReceiver&);

class NVSStreamServiceAPI;
bool operator==(const NVSStreamServiceAPI&, const NVSStreamServiceAPI&);
bool operator!=(const NVSStreamServiceAPI&, const NVSStreamServiceAPI&);
bool operator<(const NVSStreamServiceAPI&, const NVSStreamServiceAPI&);
bool operator<=(const NVSStreamServiceAPI&, const NVSStreamServiceAPI&);
bool operator>(const NVSStreamServiceAPI&, const NVSStreamServiceAPI&);
bool operator>=(const NVSStreamServiceAPI&, const NVSStreamServiceAPI&);

}

}

namespace NVSStreamService
{

class NVSStreamDataReceiver;
bool operator==(const NVSStreamDataReceiver&, const NVSStreamDataReceiver&);
bool operator!=(const NVSStreamDataReceiver&, const NVSStreamDataReceiver&);
bool operator<(const NVSStreamDataReceiver&, const NVSStreamDataReceiver&);
bool operator<=(const NVSStreamDataReceiver&, const NVSStreamDataReceiver&);
bool operator>(const NVSStreamDataReceiver&, const NVSStreamDataReceiver&);
bool operator>=(const NVSStreamDataReceiver&, const NVSStreamDataReceiver&);

class NVSStreamServiceAPI;
bool operator==(const NVSStreamServiceAPI&, const NVSStreamServiceAPI&);
bool operator!=(const NVSStreamServiceAPI&, const NVSStreamServiceAPI&);
bool operator<(const NVSStreamServiceAPI&, const NVSStreamServiceAPI&);
bool operator<=(const NVSStreamServiceAPI&, const NVSStreamServiceAPI&);
bool operator>(const NVSStreamServiceAPI&, const NVSStreamServiceAPI&);
bool operator>=(const NVSStreamServiceAPI&, const NVSStreamServiceAPI&);

}

namespace IceInternal
{

void incRef(::NVSStreamService::NVSStreamDataReceiver*);
void decRef(::NVSStreamService::NVSStreamDataReceiver*);

void incRef(::IceProxy::NVSStreamService::NVSStreamDataReceiver*);
void decRef(::IceProxy::NVSStreamService::NVSStreamDataReceiver*);

void incRef(::NVSStreamService::NVSStreamServiceAPI*);
void decRef(::NVSStreamService::NVSStreamServiceAPI*);

void incRef(::IceProxy::NVSStreamService::NVSStreamServiceAPI*);
void decRef(::IceProxy::NVSStreamService::NVSStreamServiceAPI*);

}

namespace NVSStreamService
{

typedef ::IceInternal::Handle< ::NVSStreamService::NVSStreamDataReceiver> NVSStreamDataReceiverPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::NVSStreamService::NVSStreamDataReceiver> NVSStreamDataReceiverPrx;

void __write(::IceInternal::BasicStream*, const NVSStreamDataReceiverPrx&);
void __read(::IceInternal::BasicStream*, NVSStreamDataReceiverPrx&);
void __write(::IceInternal::BasicStream*, const NVSStreamDataReceiverPtr&);
void __patch__NVSStreamDataReceiverPtr(void*, ::Ice::ObjectPtr&);

typedef ::IceInternal::Handle< ::NVSStreamService::NVSStreamServiceAPI> NVSStreamServiceAPIPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::NVSStreamService::NVSStreamServiceAPI> NVSStreamServiceAPIPrx;

void __write(::IceInternal::BasicStream*, const NVSStreamServiceAPIPrx&);
void __read(::IceInternal::BasicStream*, NVSStreamServiceAPIPrx&);
void __write(::IceInternal::BasicStream*, const NVSStreamServiceAPIPtr&);
void __patch__NVSStreamServiceAPIPtr(void*, ::Ice::ObjectPtr&);

}

namespace NVSStreamService
{

typedef ::std::vector< ::Ice::Byte> StreamContent;

class __U__StreamContent { };

struct PieceInfo
{
    ::std::string sCameraID;
    ::std::string sDVRKey;
    ::Ice::Long TimeStampX;

    bool operator==(const PieceInfo&) const;
    bool operator!=(const PieceInfo&) const;
    bool operator<(const PieceInfo&) const;
    bool operator<=(const PieceInfo& __rhs) const
    {
	return operator<(__rhs) || operator==(__rhs);
    }
    bool operator>(const PieceInfo& __rhs) const
    {
	return !operator<(__rhs) && !operator==(__rhs);
    }
    bool operator>=(const PieceInfo& __rhs) const
    {
	return !operator<(__rhs);
    }

    void __write(::IceInternal::BasicStream*) const;
    void __read(::IceInternal::BasicStream*);
};

struct DeviceInfo
{
    ::std::string sIP;
    ::std::string sUser;
    ::std::string sPassword;
    ::Ice::Int nPort;
    ::Ice::Int nChannel;
    ::std::string sChannel;
    ::std::string sType;

    bool operator==(const DeviceInfo&) const;
    bool operator!=(const DeviceInfo&) const;
    bool operator<(const DeviceInfo&) const;
    bool operator<=(const DeviceInfo& __rhs) const
    {
	return operator<(__rhs) || operator==(__rhs);
    }
    bool operator>(const DeviceInfo& __rhs) const
    {
	return !operator<(__rhs) && !operator==(__rhs);
    }
    bool operator>=(const DeviceInfo& __rhs) const
    {
	return !operator<(__rhs);
    }

    void __write(::IceInternal::BasicStream*) const;
    void __read(::IceInternal::BasicStream*);
};

struct StreamPiece
{
    ::NVSStreamService::PieceInfo Description;
    ::NVSStreamService::StreamContent Data;

    bool operator==(const StreamPiece&) const;
    bool operator!=(const StreamPiece&) const;
    bool operator<(const StreamPiece&) const;
    bool operator<=(const StreamPiece& __rhs) const
    {
	return operator<(__rhs) || operator==(__rhs);
    }
    bool operator>(const StreamPiece& __rhs) const
    {
	return !operator<(__rhs) && !operator==(__rhs);
    }
    bool operator>=(const StreamPiece& __rhs) const
    {
	return !operator<(__rhs);
    }

    void __write(::IceInternal::BasicStream*) const;
    void __read(::IceInternal::BasicStream*);
};

typedef ::std::vector< ::NVSStreamService::StreamPiece> StreamData;

class __U__StreamData { };
void __write(::IceInternal::BasicStream*, const ::NVSStreamService::StreamPiece*, const ::NVSStreamService::StreamPiece*, __U__StreamData);
void __read(::IceInternal::BasicStream*, StreamData&, __U__StreamData);

struct WorkState
{
    ::Ice::Int DvrLoad;
    ::Ice::Int ChannelLoad;
    ::Ice::Int MonitorLoad;
    ::Ice::Int SendLoad;
    ::Ice::Int MaxSendCount;
    ::Ice::Int MaxChannel;

    bool operator==(const WorkState&) const;
    bool operator!=(const WorkState&) const;
    bool operator<(const WorkState&) const;
    bool operator<=(const WorkState& __rhs) const
    {
	return operator<(__rhs) || operator==(__rhs);
    }
    bool operator>(const WorkState& __rhs) const
    {
	return !operator<(__rhs) && !operator==(__rhs);
    }
    bool operator>=(const WorkState& __rhs) const
    {
	return !operator<(__rhs);
    }

    void __write(::IceInternal::BasicStream*) const;
    void __read(::IceInternal::BasicStream*);
};

}

namespace NVSStreamService
{

class AMI_NVSStreamDataReceiver_sendStreamBody : public ::IceInternal::OutgoingAsync
{
public:

    virtual void ice_response(bool) = 0;
    virtual void ice_exception(const ::Ice::Exception&) = 0;

    void __invoke(const ::NVSStreamService::NVSStreamDataReceiverPrx&, const ::NVSStreamService::StreamPiece&, const ::Ice::Context&);

protected:

    virtual void __response(bool);
};

typedef ::IceUtil::Handle< ::NVSStreamService::AMI_NVSStreamDataReceiver_sendStreamBody> AMI_NVSStreamDataReceiver_sendStreamBodyPtr;

class AMI_NVSStreamDataReceiver_sendStreamHead : public ::IceInternal::OutgoingAsync
{
public:

    virtual void ice_response(bool) = 0;
    virtual void ice_exception(const ::Ice::Exception&) = 0;

    void __invoke(const ::NVSStreamService::NVSStreamDataReceiverPrx&, const ::NVSStreamService::StreamPiece&, const ::Ice::Context&);

protected:

    virtual void __response(bool);
};

typedef ::IceUtil::Handle< ::NVSStreamService::AMI_NVSStreamDataReceiver_sendStreamHead> AMI_NVSStreamDataReceiver_sendStreamHeadPtr;

}

namespace IceProxy
{

namespace NVSStreamService
{

class NVSStreamDataReceiver : virtual public ::IceProxy::Ice::Object
{
public:

    bool sendStreamBody(const ::NVSStreamService::StreamPiece& sd)
    {
	return sendStreamBody(sd, __defaultContext());
    }
    bool sendStreamBody(const ::NVSStreamService::StreamPiece&, const ::Ice::Context&);
    void sendStreamBody_async(const ::NVSStreamService::AMI_NVSStreamDataReceiver_sendStreamBodyPtr&, const ::NVSStreamService::StreamPiece&);
    void sendStreamBody_async(const ::NVSStreamService::AMI_NVSStreamDataReceiver_sendStreamBodyPtr&, const ::NVSStreamService::StreamPiece&, const ::Ice::Context&);

    bool sendStreamHead(const ::NVSStreamService::StreamPiece& sd)
    {
	return sendStreamHead(sd, __defaultContext());
    }
    bool sendStreamHead(const ::NVSStreamService::StreamPiece&, const ::Ice::Context&);
    void sendStreamHead_async(const ::NVSStreamService::AMI_NVSStreamDataReceiver_sendStreamHeadPtr&, const ::NVSStreamService::StreamPiece&);
    void sendStreamHead_async(const ::NVSStreamService::AMI_NVSStreamDataReceiver_sendStreamHeadPtr&, const ::NVSStreamService::StreamPiece&, const ::Ice::Context&);
    
    static const ::std::string& ice_staticId();

private: 

    virtual ::IceInternal::Handle< ::IceDelegateM::Ice::Object> __createDelegateM();
    virtual ::IceInternal::Handle< ::IceDelegateD::Ice::Object> __createDelegateD();
};

class NVSStreamServiceAPI : virtual public ::IceProxy::Ice::Object
{
public:

    ::Ice::Int startPlayer(const ::NVSStreamService::DeviceInfo& connectInfo, const ::Ice::Identity& ident, ::std::string& sKey)
    {
	return startPlayer(connectInfo, ident, sKey, __defaultContext());
    }
    ::Ice::Int startPlayer(const ::NVSStreamService::DeviceInfo&, const ::Ice::Identity&, ::std::string&, const ::Ice::Context&);

    ::Ice::Int stopVideo(const ::std::string& sKeyID)
    {
	return stopVideo(sKeyID, __defaultContext());
    }
    ::Ice::Int stopVideo(const ::std::string&, const ::Ice::Context&);

    void getWorkState(::NVSStreamService::WorkState& wkState)
    {
	getWorkState(wkState, __defaultContext());
    }
    void getWorkState(::NVSStreamService::WorkState&, const ::Ice::Context&);

    ::Ice::Int getCompress(const ::std::string& sKeyID, ::std::string& sInfo)
    {
	return getCompress(sKeyID, sInfo, __defaultContext());
    }
    ::Ice::Int getCompress(const ::std::string&, ::std::string&, const ::Ice::Context&);

    void setCompress(const ::std::string& sKeyID, const ::std::string& sInfo)
    {
	setCompress(sKeyID, sInfo, __defaultContext());
    }
    void setCompress(const ::std::string&, const ::std::string&, const ::Ice::Context&);

    ::Ice::Int getVideoEffect(const ::std::string& sKeyID, ::Ice::Int& dwBrightValue, ::Ice::Int& dwContrastValue, ::Ice::Int& dwSaturationValue, ::Ice::Int& dwHueValue)
    {
	return getVideoEffect(sKeyID, dwBrightValue, dwContrastValue, dwSaturationValue, dwHueValue, __defaultContext());
    }
    ::Ice::Int getVideoEffect(const ::std::string&, ::Ice::Int&, ::Ice::Int&, ::Ice::Int&, ::Ice::Int&, const ::Ice::Context&);

    void setVideoEffect(const ::std::string& sKeyID, ::Ice::Int dwBrightValue, ::Ice::Int dwContrastValue, ::Ice::Int dwSaturationValue, ::Ice::Int dwHueValue)
    {
	setVideoEffect(sKeyID, dwBrightValue, dwContrastValue, dwSaturationValue, dwHueValue, __defaultContext());
    }
    void setVideoEffect(const ::std::string&, ::Ice::Int, ::Ice::Int, ::Ice::Int, ::Ice::Int, const ::Ice::Context&);

    ::Ice::Int requestControlCamera(const ::std::string& sKeyID)
    {
	return requestControlCamera(sKeyID, __defaultContext());
    }
    ::Ice::Int requestControlCamera(const ::std::string&, const ::Ice::Context&);

    ::Ice::Int controlCameraSpeed(const ::std::string& sKeyID, ::Ice::Int nCmd, bool bEnable, ::Ice::Int nSpeed)
    {
	return controlCameraSpeed(sKeyID, nCmd, bEnable, nSpeed, __defaultContext());
    }
    ::Ice::Int controlCameraSpeed(const ::std::string&, ::Ice::Int, bool, ::Ice::Int, const ::Ice::Context&);

    ::Ice::Int cancelControlCamera(const ::std::string& sKeyID)
    {
	return cancelControlCamera(sKeyID, __defaultContext());
    }
    ::Ice::Int cancelControlCamera(const ::std::string&, const ::Ice::Context&);

    ::Ice::Int presetPTZ(const ::std::string& sKeyID, ::Ice::Int nCmd, ::Ice::Int nIndex)
    {
	return presetPTZ(sKeyID, nCmd, nIndex, __defaultContext());
    }
    ::Ice::Int presetPTZ(const ::std::string&, ::Ice::Int, ::Ice::Int, const ::Ice::Context&);

    void HeartBeat()
    {
	HeartBeat(__defaultContext());
    }
    void HeartBeat(const ::Ice::Context&);
    
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

class NVSStreamDataReceiver : virtual public ::IceDelegate::Ice::Object
{
public:

    virtual bool sendStreamBody(const ::NVSStreamService::StreamPiece&, const ::Ice::Context&) = 0;

    virtual bool sendStreamHead(const ::NVSStreamService::StreamPiece&, const ::Ice::Context&) = 0;
};

class NVSStreamServiceAPI : virtual public ::IceDelegate::Ice::Object
{
public:

    virtual ::Ice::Int startPlayer(const ::NVSStreamService::DeviceInfo&, const ::Ice::Identity&, ::std::string&, const ::Ice::Context&) = 0;

    virtual ::Ice::Int stopVideo(const ::std::string&, const ::Ice::Context&) = 0;

    virtual void getWorkState(::NVSStreamService::WorkState&, const ::Ice::Context&) = 0;

    virtual ::Ice::Int getCompress(const ::std::string&, ::std::string&, const ::Ice::Context&) = 0;

    virtual void setCompress(const ::std::string&, const ::std::string&, const ::Ice::Context&) = 0;

    virtual ::Ice::Int getVideoEffect(const ::std::string&, ::Ice::Int&, ::Ice::Int&, ::Ice::Int&, ::Ice::Int&, const ::Ice::Context&) = 0;

    virtual void setVideoEffect(const ::std::string&, ::Ice::Int, ::Ice::Int, ::Ice::Int, ::Ice::Int, const ::Ice::Context&) = 0;

    virtual ::Ice::Int requestControlCamera(const ::std::string&, const ::Ice::Context&) = 0;

    virtual ::Ice::Int controlCameraSpeed(const ::std::string&, ::Ice::Int, bool, ::Ice::Int, const ::Ice::Context&) = 0;

    virtual ::Ice::Int cancelControlCamera(const ::std::string&, const ::Ice::Context&) = 0;

    virtual ::Ice::Int presetPTZ(const ::std::string&, ::Ice::Int, ::Ice::Int, const ::Ice::Context&) = 0;

    virtual void HeartBeat(const ::Ice::Context&) = 0;
};

}

}

namespace IceDelegateM
{

namespace NVSStreamService
{

class NVSStreamDataReceiver : virtual public ::IceDelegate::NVSStreamService::NVSStreamDataReceiver,
			      virtual public ::IceDelegateM::Ice::Object
{
public:

    virtual bool sendStreamBody(const ::NVSStreamService::StreamPiece&, const ::Ice::Context&);

    virtual bool sendStreamHead(const ::NVSStreamService::StreamPiece&, const ::Ice::Context&);
};

class NVSStreamServiceAPI : virtual public ::IceDelegate::NVSStreamService::NVSStreamServiceAPI,
			    virtual public ::IceDelegateM::Ice::Object
{
public:

    virtual ::Ice::Int startPlayer(const ::NVSStreamService::DeviceInfo&, const ::Ice::Identity&, ::std::string&, const ::Ice::Context&);

    virtual ::Ice::Int stopVideo(const ::std::string&, const ::Ice::Context&);

    virtual void getWorkState(::NVSStreamService::WorkState&, const ::Ice::Context&);

    virtual ::Ice::Int getCompress(const ::std::string&, ::std::string&, const ::Ice::Context&);

    virtual void setCompress(const ::std::string&, const ::std::string&, const ::Ice::Context&);

    virtual ::Ice::Int getVideoEffect(const ::std::string&, ::Ice::Int&, ::Ice::Int&, ::Ice::Int&, ::Ice::Int&, const ::Ice::Context&);

    virtual void setVideoEffect(const ::std::string&, ::Ice::Int, ::Ice::Int, ::Ice::Int, ::Ice::Int, const ::Ice::Context&);

    virtual ::Ice::Int requestControlCamera(const ::std::string&, const ::Ice::Context&);

    virtual ::Ice::Int controlCameraSpeed(const ::std::string&, ::Ice::Int, bool, ::Ice::Int, const ::Ice::Context&);

    virtual ::Ice::Int cancelControlCamera(const ::std::string&, const ::Ice::Context&);

    virtual ::Ice::Int presetPTZ(const ::std::string&, ::Ice::Int, ::Ice::Int, const ::Ice::Context&);

    virtual void HeartBeat(const ::Ice::Context&);
};

}

}

namespace IceDelegateD
{

namespace NVSStreamService
{

class NVSStreamDataReceiver : virtual public ::IceDelegate::NVSStreamService::NVSStreamDataReceiver,
			      virtual public ::IceDelegateD::Ice::Object
{
public:

    virtual bool sendStreamBody(const ::NVSStreamService::StreamPiece&, const ::Ice::Context&);

    virtual bool sendStreamHead(const ::NVSStreamService::StreamPiece&, const ::Ice::Context&);
};

class NVSStreamServiceAPI : virtual public ::IceDelegate::NVSStreamService::NVSStreamServiceAPI,
			    virtual public ::IceDelegateD::Ice::Object
{
public:

    virtual ::Ice::Int startPlayer(const ::NVSStreamService::DeviceInfo&, const ::Ice::Identity&, ::std::string&, const ::Ice::Context&);

    virtual ::Ice::Int stopVideo(const ::std::string&, const ::Ice::Context&);

    virtual void getWorkState(::NVSStreamService::WorkState&, const ::Ice::Context&);

    virtual ::Ice::Int getCompress(const ::std::string&, ::std::string&, const ::Ice::Context&);

    virtual void setCompress(const ::std::string&, const ::std::string&, const ::Ice::Context&);

    virtual ::Ice::Int getVideoEffect(const ::std::string&, ::Ice::Int&, ::Ice::Int&, ::Ice::Int&, ::Ice::Int&, const ::Ice::Context&);

    virtual void setVideoEffect(const ::std::string&, ::Ice::Int, ::Ice::Int, ::Ice::Int, ::Ice::Int, const ::Ice::Context&);

    virtual ::Ice::Int requestControlCamera(const ::std::string&, const ::Ice::Context&);

    virtual ::Ice::Int controlCameraSpeed(const ::std::string&, ::Ice::Int, bool, ::Ice::Int, const ::Ice::Context&);

    virtual ::Ice::Int cancelControlCamera(const ::std::string&, const ::Ice::Context&);

    virtual ::Ice::Int presetPTZ(const ::std::string&, ::Ice::Int, ::Ice::Int, const ::Ice::Context&);

    virtual void HeartBeat(const ::Ice::Context&);
};

}

}

namespace NVSStreamService
{

class NVSStreamDataReceiver : virtual public ::Ice::Object
{
public:

    typedef NVSStreamDataReceiverPrx ProxyType;
    typedef NVSStreamDataReceiverPtr PointerType;
    
    virtual ::Ice::ObjectPtr ice_clone() const;

    virtual bool ice_isA(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const;
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& = ::Ice::Current()) const;
    virtual const ::std::string& ice_id(const ::Ice::Current& = ::Ice::Current()) const;
    static const ::std::string& ice_staticId();

    virtual bool sendStreamBody(const ::NVSStreamService::StreamPiece&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___sendStreamBody(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual bool sendStreamHead(const ::NVSStreamService::StreamPiece&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___sendStreamHead(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::IceInternal::DispatchStatus __dispatch(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);
    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

void __patch__NVSStreamDataReceiverPtr(void*, ::Ice::ObjectPtr&);

class NVSStreamServiceAPI : virtual public ::Ice::Object
{
public:

    typedef NVSStreamServiceAPIPrx ProxyType;
    typedef NVSStreamServiceAPIPtr PointerType;
    
    virtual ::Ice::ObjectPtr ice_clone() const;

    virtual bool ice_isA(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const;
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& = ::Ice::Current()) const;
    virtual const ::std::string& ice_id(const ::Ice::Current& = ::Ice::Current()) const;
    static const ::std::string& ice_staticId();

    virtual ::Ice::Int startPlayer(const ::NVSStreamService::DeviceInfo&, const ::Ice::Identity&, ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___startPlayer(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::Ice::Int stopVideo(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___stopVideo(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void getWorkState(::NVSStreamService::WorkState&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___getWorkState(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::Ice::Int getCompress(const ::std::string&, ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___getCompress(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void setCompress(const ::std::string&, const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___setCompress(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::Ice::Int getVideoEffect(const ::std::string&, ::Ice::Int&, ::Ice::Int&, ::Ice::Int&, ::Ice::Int&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___getVideoEffect(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void setVideoEffect(const ::std::string&, ::Ice::Int, ::Ice::Int, ::Ice::Int, ::Ice::Int, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___setVideoEffect(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::Ice::Int requestControlCamera(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___requestControlCamera(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::Ice::Int controlCameraSpeed(const ::std::string&, ::Ice::Int, bool, ::Ice::Int, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___controlCameraSpeed(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::Ice::Int cancelControlCamera(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___cancelControlCamera(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::Ice::Int presetPTZ(const ::std::string&, ::Ice::Int, ::Ice::Int, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___presetPTZ(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void HeartBeat(const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___HeartBeat(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::IceInternal::DispatchStatus __dispatch(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);
    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

void __patch__NVSStreamServiceAPIPtr(void*, ::Ice::ObjectPtr&);

}

#endif
