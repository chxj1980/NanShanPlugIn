#pragma once
#include "StdAfx.h"
#include <direct.h>
#include <io.h>   
#include <fcntl.h>


class LoggerFile
{
public:
	LoggerFile(void);
public:
	~LoggerFile(void);

private:
	//日志文件句柄
	static HANDLE m_hFileHandle;
	//日志文件全路径名
	static char m_sFileName[64];
	//日志文件目录
	static char m_sFilePath[128];
	//日志文件全路径名
	static char m_sPathFileName[256];


public:
	//创建日志文件
	//char* sFilePath 子目录
	//char* sFileName 文件名
	//unsigned short nLogSign 写日志文件标志 1--写日志  0--不写日志 默认为1
	//char* sDisc 盘符 默认为C盘
	//char* sSystemPath 根目录 默认是NVSLog
	static void CreateSysLog(char* sFilePath, char* sFileName, unsigned short nLogSign = 1, char* sDisc = "C:", char* sSystemPath = "\\NVSLog");
	
	//写日志文件
	//char* sLongText 写入日志文件内容
	static void WriteLogMsg(char* sLongText);

};


HANDLE LoggerFile::m_hFileHandle = NULL;
char LoggerFile::m_sFileName[64] = {0};
char LoggerFile::m_sFilePath[128] = {0};
char LoggerFile::m_sPathFileName[256] = {0};


LoggerFile::LoggerFile(void)
{
}

LoggerFile::~LoggerFile(void)
{
}

void LoggerFile::CreateSysLog(char* sFilePath, char* sFileName, unsigned short nLogSign, char* sDisc, char* sSystemPath)
{
	if(nLogSign == 0)
		return;

	char sSysPath[128]={0};
	char sChildPath[256]={0};
	char sPathFileName[512]={0};

	//盘符
	strcpy_s(sSysPath,sizeof(sSysPath),sDisc);
	//建立日志文件根目录
	strcat_s(sSysPath,sizeof(sSysPath),sSystemPath);
	_mkdir(sSysPath);
	
	//日志文件分目录
	strcpy_s(sChildPath,sizeof(sChildPath),sSysPath);
	strcat_s(sChildPath,sizeof(sChildPath),"\\");
	strcat_s(sChildPath,sizeof(sChildPath),sFilePath);
	
	//将日志文件的路径保存
	strcpy_s(m_sFilePath,sizeof(m_sFilePath),sChildPath);

	//建立日志文件分目录
	_mkdir(sChildPath);

	//获取日志文件名
	strcpy_s(sPathFileName,sizeof(sPathFileName),sChildPath);
	strcat_s(sPathFileName,sizeof(sPathFileName),"\\");
	strcat_s(sPathFileName,sizeof(sPathFileName),sFileName);
	strcat_s(sPathFileName,sizeof(sPathFileName),".log");

	//将日志文件名保存
	strcpy_s(m_sFileName,sizeof(m_sFileName),sFileName);
	strcpy_s(m_sPathFileName,sizeof(m_sPathFileName),sPathFileName);

	m_hFileHandle = ::CreateFile(sPathFileName,GENERIC_READ|GENERIC_WRITE,FILE_SHARE_READ|FILE_SHARE_WRITE,NULL,OPEN_ALWAYS,FILE_ATTRIBUTE_NORMAL,NULL);
	if (m_hFileHandle == INVALID_HANDLE_VALUE)
	{
		return;
	}
	//::SetEndOfFile(m_hFileHandle);//清空现在的日志文件//屏蔽则保留原来的日志
}


void LoggerFile::WriteLogMsg(char* sLongText)
{
	if (m_hFileHandle == INVALID_HANDLE_VALUE)
	{
		return;
	}

	char strtime[64]={0};
	char sTotalLog[1024]={0};
	SYSTEMTIME t;

	::GetLocalTime(&t);
	sprintf_s(strtime,sizeof(strtime) ,"%04d-%02d-%02d %02d:%02d:%02d:%03d ",t.wYear,t.wMonth,t.wDay,t.wHour,t.wMinute,t.wSecond,t.wMilliseconds);
	
	strcpy_s(sTotalLog,sizeof(sTotalLog),strtime);
	strcat_s(sTotalLog,sizeof(sTotalLog),sLongText);
	strcat_s(sTotalLog,sizeof(sTotalLog),"\r\n");

	DWORD nWritten;
	
	SetFilePointer(m_hFileHandle,0,0,FILE_END);
	::WriteFile(m_hFileHandle, sTotalLog, (DWORD)strlen(sTotalLog), &nWritten, NULL);

	DWORD lpSizeHigh;
	DWORD dwLen = GetFileSize(m_hFileHandle,&lpSizeHigh);
	if(dwLen >= 1024*1024*2)
	{
		char sNewFilePath[512] = {0};
		char _szDir1[128] = {0};

		sprintf_s(_szDir1,"\\%s_%04d-%02d-%02d_%02d-%02d-%02d.log",m_sFileName,t.wYear,t.wMonth,t.wDay,t.wHour,t.wMinute,t.wSecond);

		//获取新文件名
		strcpy_s(sNewFilePath,sizeof(sNewFilePath),m_sFilePath);
		strcat_s(sNewFilePath,sizeof(sNewFilePath),_szDir1);

		//拷贝日志文件
		CopyFile(m_sPathFileName,sNewFilePath, false);

		//清空现在的日志文件
		SetFilePointer(m_hFileHandle,0,0,FILE_BEGIN);
		SetEndOfFile(m_hFileHandle);
	}
}
