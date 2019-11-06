#ifndef CLOG_RECORDER_H_
#define CLOG_RECORDER_H_

#include <log4cxx\log4cxx.h>
#include <log4cxx\propertyconfigurator.h>
#include <log4cxx\xml\domconfigurator.h>
#include <log4cxx\helpers\loglog.h>

using namespace std;
using namespace log4cxx;
using namespace log4cxx::helpers;
using namespace log4cxx::xml;

/**
* Ȩ�޼��𣺷ֱ��ӦLog4cxx�еģ�TRACE, DEBUG, INFO, WARN, ERROR, FATAL
* ʹ�ý��飺1.���õ�Ȩ�޼���ΪDEBUG, INFO, WARN, ERROR
*			2.�����ڵ���ʱ��ϵͳ���������н׶���Ҫ��¼����Ϣ������DEBUG����
*			3.������ϵͳ������ʱҲ��Ҫ��¼����־��Ϣ������INFO����
*			4.���ڿ��ܴ�������ĵط�������WARN���𣬲�������ܵ��³����������Ϣ
*			5.���ڷ����������Ϣ������WARN����
*/
enum LoggerLevel{TRACELEVEL, DEBUGLEVEL, INFOLEVEL, WARNLEVEL, ERRORLEVEL, FATALLEVEL};

class CLogRecorder
{
public:
	CLogRecorder(){ m_logger = NULL; }
	~CLogRecorder() {}

	// ��ʼ��Logger
	bool InitLogger(const char *pszLogConfigPath, const char *pszLoggerName, const char *pszModuleName);
	// ��־��¼�Ļ���������������������ͨ������ʵ��
	void WriteLog(const char *pszFunction, const char *pszLogContent, LoggerLevel nLevel=INFOLEVEL);
	// ��ͨ����־��¼����
	void WriteDebugLog(const char *pszFunction, const char *pszLogContent);
	void WriteInfoLog(const char *pszFunction, const char *pszLogContent);
	void WriteWarnLog(const char *pszFunction, const char *pszLogContent);
	void WriteErrorLog(const char *pszFunction, const char *pszLogContent);
	void WriteFatalLog(const char *pszFunction, const char *pszLogContent);
	
	// ��չ����־��¼������֧�ֿɱ���������ӷ���Ϳ�ݣ�����ʹ�ô��麯��
	void WriteLogEx(LoggerLevel nLevel, const char *pszFunction, const char *pszFormat, ...);
	void WriteDebugLogEx(const char *pszFunction,const char *pszFormat, ...);
	void WriteInfoLogEx(const char *pszFunction, const char *pszFormat, ...);
	void WriteWarnLogEx(const char *pszFunction, const char *pszFormat, ...);
	void WriteErrorLogEx(const char *pszFunction, const char *pszForamt, ...);
	void WriteFatalLogEx(const char *pszFunction, const char *pszFormat, ...);

private:
	char m_szModuleName[MAX_PATH];	// ģ�����֣���־�ļ�¼��ģ��Ϊ��λ
	LoggerPtr m_logger;	// ��־��¼��������
};

#endif	// CLOG_RECORDER_H_