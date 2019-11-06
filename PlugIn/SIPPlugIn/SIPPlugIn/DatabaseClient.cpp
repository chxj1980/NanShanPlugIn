#include "stdafx.h"
#include "DatabaseClient.h"
#include "SipService.h"

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

bool DatabaseClient::GetSuperiorRegister(const char * localcode, register_map &regmap)
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
		sprintf(sqlstr, "SELECT NAME,SIPCODE,BINDIP,USERDESC,SIPPASSWORD,ISVALID FROM USERINFO WHERE EMAIL = '%s'", localcode);
		int nRet = OCI_ExecuteStmt(ost, sqlstr);
		//if (nRet != 1)
		//	return false;
		OCI_Resultset *ors = OCI_GetResultset(ost);
		if (!ors)
			return false;
		while (OCI_FetchNext(ors))
		{
			const char *sName = OCI_GetString(ors, 1);
			const char *sSipCode = OCI_GetString(ors, 2);
			const char *sBindIp = OCI_GetString(ors, 3);
			const char *sUser = OCI_GetString(ors, 4);
			const char *sPwd = OCI_GetString(ors, 5);
			int nValid = OCI_GetInt(ors, 6);
			regmap_iter riter = regmap.find(sBindIp);
			if (riter != regmap.end())
			{
				riter->second.vaild = nValid ? true : false;
			}
			else
			{
				if (nValid == 1)
				{
					register_info rinfo;
					memset(&rinfo, 0, sizeof(register_info));
					strcpy(rinfo.name, sName);
					strcpy(rinfo.addr, sBindIp);
					strcpy(rinfo.user, sSipCode);
					strcpy(rinfo.pwd, sPwd);
					rinfo.role = SIP_ROLE_SUPERIOR;
					rinfo.expires = 3600;
					rinfo.vaild = true;
					regmap.insert(register_map::value_type(sBindIp, rinfo));
				}
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
