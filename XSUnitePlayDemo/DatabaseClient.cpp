#include "stdafx.h"
#include "DatabaseClient.h"
#include <direct.h>

DatabaseClient::DatabaseClient()
{
	m_pool = NULL;
}


DatabaseClient::~DatabaseClient()
{
	m_pool = NULL;
}

void OCI_ERROR_CB(OCI_Error *err)
{
	unsigned int err_type = OCI_ErrorGetType(err);
	const char *err_msg = OCI_ErrorGetString(err);
	if (err_type == OCI_ERR_WARNING)
	{
		printf("DB Waring:%s\n", err_msg);
	}
	else
	{
		printf("DB Error:%s\n", err_msg);
		printf("%s\n", OCI_GetSql(OCI_ErrorGetStatement(err)));
	}
}

bool DatabaseClient::Connect(int driver, const char * addr, const char * server, const char * user, const char * pwd, int thdnum)
{
	if (addr == NULL || server == NULL || user == NULL || pwd == NULL || 
		addr[0] == '\0' || server[0] == '\0' || user[0] == '\0' || pwd[0] == '\0')
	{
		printf("DB Connect Param Is Invalid!\n");
		return false;
	}
	m_driver = driver;
	if (driver == DB_ORACLE)
	{
		char szLibPath[256] = { 0 };
		_getcwd(szLibPath, sizeof(szLibPath));
		if (!OCI_Initialize(OCI_ERROR_CB, szLibPath, OCI_ENV_DEFAULT | OCI_ENV_THREADED))
		{
			printf("DB Initialize Failure!\n");
			return false;
		}
		char szAddr[1024] = { 0 };
		sprintf(szAddr, "%s/%s", addr, server);
		m_pool = OCI_PoolCreate(szAddr, user, pwd, OCI_POOL_CONNECTION, OCI_SESSION_DEFAULT, 0, thdnum, 1);
		if (!m_pool)
		{
			printf("DB Pool Create Failure!\n");
			return false;
		}
	}
	else if (driver = DB_MYSQL)
	{

	}
	else if (driver = DB_SQLITE)
	{

	}
	else
	{
		return false;
	}
	return true;
}

void DatabaseClient::Disconnect()
{
	if (m_driver == DB_ORACLE)
	{
		if (m_pool)
		{
			OCI_PoolFree(m_pool);
			m_pool = NULL;
			OCI_Cleanup();
		}
	}
}

bool DatabaseClient::GetHighPointChannels(const char * localcode, vector<int> &chanlist)
{
	if (m_driver == DB_ORACLE)
	{
		OCI_Connection *ocn = OCI_PoolGetConnection(m_pool, NULL);
		if (!ocn)
			return false;
		OCI_Statement *ost = OCI_StatementCreate(ocn);
		if (!ost)
			return false;
		char sqlstr[1024] = { 0 };
		sprintf(sqlstr, "select chanid from changrouptochan where changroupid in (select id from changroupinfo where parentid = £¨select id from changroupinfo where nodename like 'ÄÏÉ½Ö®ÑÛ'£©)");
		int nRet = OCI_ExecuteStmt(ost, sqlstr);
		//if (nRet != 1)
		//	return false;
		OCI_Resultset *ors = OCI_GetResultset(ost);
		if (!ors)
			return false;
		while (OCI_FetchNext(ors))
		{
			int nChanId = OCI_GetInt(ors, 1);
			if (nChanId > 0)
			{
				chanlist.push_back(nChanId);
			}
		}
		OCI_ReleaseResultsets(ost);
		OCI_StatementFree(ost);
		OCI_ConnectionFree(ocn);
		ost = NULL;
		ocn = NULL;
	}
	return false;
}
