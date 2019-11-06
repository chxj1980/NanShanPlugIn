#include "librtp.h"

#include "config.h"


#ifdef _WIN32
#pragma comment(lib, "ws2_32.lib")
#endif

static std::map<int, bool> port_map;


int sip_get_media_port(int start_port)
{
	int port = start_port;
	std::map<int, bool>::iterator itor;
	while (true)
	{
		itor = port_map.find(port);
		if (itor != port_map.end())
		{
			if (itor->second)	//端口被占用
			{
				port += 2;
			}
			else                //端口空闲
			{
				itor->second = true;
				return itor->first;
			}
		}
		else                    //新增端口
		{
			port_map[port] = true;
			return port;
		}
	}
	return 0;
}

void sip_free_media_port(int media_port)
{
	std::map<int, bool>::iterator itor = port_map.find(media_port);
	if (itor != port_map.end())
	{
		itor->second = false;
	}
}

class sip_stream_thread : public acl::thread
{
public:
	sip_stream_thread(int media_mode, void *stream, media_stream_cb stream_cb, void *user, void *session)
	{
		m_mode = media_mode;
		m_stream = stream;
		m_stream_cb = stream_cb;
		m_user = user;
		m_session = (session_info *)session;
		m_ssrc = 0;
		if (m_session)
			m_ssrc = atoi(m_session->ssrc);
		m_stop = false;
	}
	~sip_stream_thread()
	{
		stop();
	}
protected:
	virtual void *run()
	{
		int ret = -1;
		unsigned char buffer[1024*6] = { 0 };
		unsigned char tbuffer[1024*100] = { 0 };
		int tbufsize = 0;
		acl::socket_stream *client = NULL;
		while (!m_stop)
		{
			if (client == NULL)
			{
				if (m_mode == RTP_UDP)
					client = (acl::socket_stream *)m_stream;
				else if (m_mode == RTP_TCP_A)
					client = (acl::socket_stream *)m_stream;
				else
					client = ((acl::server_socket *)m_stream)->accept(RTP_ACPT_TIMEOUT);
			}
			if (client == NULL)
			{
				logger_warn("\nrtp:no recv client!\n");
				if (m_stream_cb && m_user)
				{
					m_stream_cb(403, NULL, 0, m_user);
				}
				break;
			}
			memset(buffer, 0, sizeof(buffer));
			ret = client->read(buffer, sizeof(buffer), false);
			if (m_stop)
			{
				break;
			}
			if (ret > 0)
			{
				//logger_warn("\nrtp:recv buffer size:%d\n", ret);
				if (m_mode == RTP_UDP)
				{
					if (m_stream_cb && m_user)
						m_stream_cb(0, buffer, ret, m_user);
				}
				else
				{
					if (tbufsize + ret > 102400)
					{
						logger_warn("\nrtp:recv tcp buffer out of range!\n");
						tbufsize = 0;
					}
					memcpy(tbuffer + tbufsize, buffer, ret);
					tbufsize += ret;
					int i = 0;
					while (tbufsize > 14)	//TCP RTP HEADER SIZE
					{
						if (((unsigned char)tbuffer[i+2] == 0x80 || (unsigned char)tbuffer[i+2] == 0x90) &&
							((unsigned char)tbuffer[i+3] == 0x60 || (unsigned char)tbuffer[i+3] == 0xE0 || 
							 (unsigned char)tbuffer[i+3] == 0xA8)) //海康头
						{
							unsigned int ssrc = ntohl(*((unsigned int *)&tbuffer[i+10]));
							if (m_ssrc <= 0)
							{
								logger_warn("\nrtp:tcp[%s] ssrc is %d!\n", client->get_peer(true), ssrc);
								m_ssrc = ssrc;
							}
							if (ssrc == m_ssrc)
							{
								int packlen = tbuffer[i]*256 + tbuffer[i+1];
								if (packlen + 2 > tbufsize)
									break;
								else
								{
									if (m_stream_cb && m_user)
										m_stream_cb(0, tbuffer+i+2, packlen, m_user);
									i += packlen - 1;
									tbufsize -= packlen - 1;
								}
							}
						}
						i++;
						tbufsize--;
					}
					if (tbufsize > 0)
						memcpy(tbuffer, tbuffer + i, tbufsize);
				}
			}
			else if (ret == 0)
			{
				logger_warn("\nrtp:recv buffer timeout! %d:%s\n", acl::last_error(), acl::last_serror());
				if (m_session)
					m_session->mediaover = time(NULL);
				if (m_stream_cb && m_user)
					m_stream_cb(408, NULL, 0, m_user);
			}
			else
			{
				logger_warn("\nrtp:recv buffer error!\n");
				if (m_session)
					m_session->mediaover = time(NULL);
				if (m_stream_cb && m_user)
					m_stream_cb(487, NULL, 0, m_user);
				break;
			}
		}
		if (m_mode == RTP_UDP)
		{ 
			client->close();
			delete ((acl::socket_stream *)m_stream);
		}
		else if (m_mode == RTP_TCP_A)
		{
#ifdef _WINDOWS
			SOCKET sock = client->sock_handle();
			if (sock != INVALID_SOCKET)
			{
				closesocket(sock);
				sock = INVALID_SOCKET;
			}
#endif
			client->close();
			delete ((acl::socket_stream *)m_stream);
		}
		else
		{
			client->close();
			((acl::server_socket *)m_stream)->close();
			delete ((acl::server_socket *)m_stream);
		}
		memset(buffer, 0, sizeof(buffer));
		memset(tbuffer, 0, sizeof(tbuffer));
		tbufsize = 0;
		client = NULL;
		m_stream = NULL;
		delete this;
		return NULL;
	}
public:
	void stop()
	{
		m_stream_cb = NULL;
		m_user = NULL;
		m_stop = true;
	}
private:
	int				m_mode;
	void*			m_stream;
	media_stream_cb m_stream_cb;
	void			*m_user;
	session_info	*m_session;
	int				m_ssrc;
	bool			m_stop;
};

bool sip_bind_stream(SOCKET &sock, const char * media_ip, int &media_port)
{
	sockaddr_in source = { 0 };
	source.sin_family = AF_INET;
	source.sin_addr.s_addr = inet_addr(media_ip);
	source.sin_port = htons(media_port);
	while (bind(sock, (sockaddr*)&source, sizeof(source)) != 0)
	{
		media_port = sip_get_media_port();
		memset(&source, 0, sizeof(sockaddr_in));
		source.sin_family = AF_INET;
		source.sin_addr.s_addr = inet_addr(media_ip);
		source.sin_port = htons(media_port);
		logger_error("\n绑定TCP接收地址[%s:%d]失败\n", media_ip, media_port);
	}
	return true;
}

RTP_STREAM sip_start_stream(const char * media_ip, int &media_port, int media_mode, const char * dst, media_stream_cb stream_cb, void * user, void *session)
{
	acl::string strLocalAddr;
	if (media_mode == RTP_UDP)
	{
		strLocalAddr.format("%s:%d", media_ip, media_port);
		acl::socket_stream *stream = new acl::socket_stream();
		if (!stream->bind_udp(strLocalAddr.c_str(), 10))
		{
			logger_error("\n绑定UDP接收地址[%s:%d]失败!\n", media_ip, media_port);
			if (stream_cb)
				stream_cb(487, NULL, 0, user);
			delete stream;
			stream = NULL;
			return NULL;
		}
		sip_stream_thread* thread = new sip_stream_thread(media_mode, stream, stream_cb, user, session);
		thread->set_detachable(true);
		thread->start();
		return (RTP_STREAM)thread;
	}
	else if (media_mode == RTP_TCP_A)
	{
		acl::socket_stream *stream = new acl::socket_stream();
#ifdef _WINDOWS
		acl::string strDst = dst;
		int nPos = strDst.find(':');
		acl::string strDstIp = strDst.left(nPos);
		acl::string strPort = strDst.right(nPos);
		int nDstPort = atoi(strPort);
		//setsockopt();
		SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
		u_long ul = 1;
		ioctlsocket(sock, FIONBIO, &ul);

		sip_bind_stream(sock, media_ip, media_port);

		//sockaddr_in source = { 0 };
		//source.sin_family = AF_INET;
		//source.sin_addr.s_addr = inet_addr(media_ip);
		//source.sin_port = htons(media_port);
		//if (bind(sock, (sockaddr*)&source, sizeof(source)) != 0)
		//{
		//	logger_error("\n绑定TCP接收地址[%s:%d]失败\n", media_ip, media_port);
		//	closesocket(sock);
		//	if (stream_cb)
		//		stream_cb(487, NULL, 0, user);
		//	delete stream;
		//	stream = NULL;
		//	return NULL;
		//}

		sockaddr_in destination = { 0 };
		destination.sin_family = AF_INET;
		destination.sin_addr.s_addr = inet_addr(strDstIp.c_str());
		destination.sin_port = htons(nDstPort);
		if (connect(sock, (sockaddr*)&destination, sizeof(destination)) == -1)
		{
			fd_set fds;
			FD_ZERO(&fds);
			FD_SET(sock, &fds);
			timeval tv;
			tv.tv_sec = 0;
			tv.tv_usec = RTP_CONN_TIMEOUT;
			if (select(0, NULL, &fds, NULL, &tv) <= 0)
			{
				logger_error("\n连接发送地址[%s]失败\n", dst);
				closesocket(sock);
				if (stream_cb)
					stream_cb(403, NULL, 0, user);
				delete stream;
				stream = NULL;
				return NULL;
			}
			int error = -1;
			int optLen = sizeof(error);
			getsockopt(sock, SOL_SOCKET, SO_ERROR, (char *)&error, &optLen);
			if (error != 0)
			{
				logger_error("\n连接发送地址[%s]失败,错误码:%d\n", dst, error);
				closesocket(sock);
				if (stream_cb)
					stream_cb(403, NULL, 0, user);
				delete stream;
				stream = NULL;
				return NULL;
			}
		}
		ul = 0;
		ioctlsocket(sock, FIONBIO, &ul);
		int timeout = RTP_RECV_TIMEOUT;
		setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(int));

		if (!stream->open(sock))
		{
			logger_error("连接TCP发送地址[%s:%d]失败!", media_ip, media_port);
			if (stream_cb)
				stream_cb(403, NULL, 0, user);
			delete stream;
			stream = NULL;
			return NULL;
		}
#else
		if (!stream->open(dst, RTP_CONN_TIMEOUT, RTP_RECV_TIMEOUT))
		{
			logger_error("连接TCP发送地址[%s]失败!", dst);
			if (stream_cb)
				stream_cb(403, NULL, 0, user);
			delete stream;
			stream = NULL;
			return NULL;
		}
#endif
		sip_stream_thread* thread = new sip_stream_thread(media_mode, stream, stream_cb, user, session);
		thread->set_detachable(true);
		thread->start();
		return (RTP_STREAM)thread;
	}
	else
	{
		strLocalAddr.format("%s:%d", media_ip, media_port);
		acl::server_socket *stream = new acl::server_socket();
		if (!stream->open(strLocalAddr.c_str()))
		{
			logger_error("监听TCP接收地址[%s:%d]失败!", media_ip, media_port);
			if (stream_cb)
				stream_cb(487, NULL, 0, user);
			delete stream;
			stream = NULL;
			return NULL;
		}
		sip_stream_thread* thread = new sip_stream_thread(media_mode, stream, stream_cb, user, session);
		thread->set_detachable(true);
		thread->start();
		return (RTP_STREAM)thread;
	}
	return NULL;
}

void sip_stop_stream(RTP_STREAM handle)
{
	sip_stream_thread *thread = (sip_stream_thread *)handle;
	if (thread)
	{
		thread->stop();
	}
}








