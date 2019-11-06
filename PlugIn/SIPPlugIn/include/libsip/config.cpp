#include "config.h"

static char *var_local_addr;
static int var_local_port;
static char *var_local_code;
static int var_log_level;
static char *var_log_path;
static int var_db_drver;
static char *var_db_addr;
static char *var_db_name;
static char *var_db_user;
static char *var_db_pwd;
static int var_db_pool;
static int var_srv_pool;
static int var_srv_role;
static int var_clnt_tranfer;
static int var_rtp_port;
static int var_rtp_check_ssrc;
static int var_specify_declib;

static char *var_kfk_brokers;
static char *var_kfk_topic;
static char *var_kfk_group;

static ACL_CFG_STR_TABLE s_cfg_str_tab[] = 
{
	{ "local_addr", "127.0.0.1",  &var_local_addr },
	{ "local_code", "44030000002000000003", &var_local_code },
	{ "log_path", "", &var_log_path },
	{ "db_addr", "", &var_db_addr },
	{ "db_name", "", &var_db_name },
	{ "db_user", "XY_BASE", &var_db_user },
	{ "db_pwd", "XY_BASE", &var_db_pwd },
	{ "kfk_brokers", "", &var_kfk_brokers },
	{ "kfk_topic", "", &var_kfk_topic },
	{ "kfk_group", "", &var_kfk_group },
	{ 0, 0, 0 }
};

static ACL_CFG_INT_TABLE s_cfg_int_tab[] = 
{
	{ "local_port", 5063, &var_local_port, 0, 0 },
	{ "log_level", LOG_CLOSE, &var_log_level, 0, 0 },
	{ "db_driver", DB_NONE, &var_db_drver, 0, 0 },
	{ "db_pool", 16, &var_db_pool, 0, 0 },
	{ "srv_pool", 100, &var_srv_pool, 0, 0},
	{ "srv_role", 1, &var_srv_pool, 0, 0 },
	{ "clnt_tranfer", 0, &var_clnt_tranfer , 0, 0 },
	{ "rtp_port", 6000, &var_rtp_port , 0, 0 },
	{ "rtp_check_ssrc", 1, &var_rtp_check_ssrc , 0, 0 },
	{ "specify_declib", 0, &var_specify_declib , 0, 0 },
	{ 0, 0, 0, 0, 0 }
};


config::config()
{
	memset(cwd, 0, sizeof(cwd));
	memset(local_addr, 0, sizeof(local_addr));
	memset(local_code, 0, sizeof(local_code));
	memset(log_path, 0, sizeof(log_path));
	memset(db_addr, 0, sizeof(db_addr));
	memset(db_name, 0, sizeof(db_name));
	memset(db_user, 0, sizeof(db_user));
	memset(db_pwd, 0, sizeof(db_pwd));

	memset(kfk_brokers, 0, sizeof(kfk_brokers));
	memset(kfk_topic, 0, sizeof(kfk_topic));
	memset(kfk_brokers, 0, sizeof(kfk_group));

	local_port = 0;
	db_driver = 0;
	db_pool = 0;
	srv_pool = 0;
	srv_role = 0;
	log_level = LOG_CLOSE;
	rtp_port = 0;
	rtp_check_ssrc = 0;
	specify_declib = 0;
}

config::~config()
{
	logger_close();
}

bool config::read()
{
	acl::acl_cpp_init();

	char szPath[256] = { 0 };
#ifdef _USRDLL
	_getcwd(szPath, sizeof(szPath));
	memcpy(cwd, szPath, strlen(szPath));
#ifdef _FOR_RTS_USE
	strcat(szPath, "/QTSSModules/PlugIn/SIPPlugIn/sipparm.cf");
#else
	strcat(szPath, "/PlugIn/SIPPlugIn/sipparm.cf");
#endif
#else
	strcpy(szPath, "sipparm.cf");
#endif
	acl::log::stdout_open(true);
	ACL_XINETD_CFG_PARSER *cfg = acl_xinetd_cfg_load(szPath);
	if (cfg == NULL)
	{
		printf("配置文件读取失败!\n");
		return false;
	}
	acl_xinetd_params_str_table(cfg, s_cfg_str_tab);
	acl_xinetd_params_int_table(cfg, s_cfg_int_tab);

	memcpy(local_addr, var_local_addr, strlen(var_local_addr));
	local_port = var_local_port;
	memcpy(local_code, var_local_code, strlen(var_local_code));
	srv_pool = var_srv_pool;
	srv_role = var_srv_role;
	clnt_tranfer = var_clnt_tranfer;
	rtp_port = var_rtp_port;
	rtp_check_ssrc = var_rtp_check_ssrc;
	specify_declib = var_specify_declib;
	log_level = var_log_level;
    memcpy(log_path, var_log_path, strlen(var_log_path));
	db_driver = var_db_drver;
	memcpy(db_addr, var_db_addr, strlen(var_db_addr));
	memcpy(db_name, var_db_name, strlen(var_db_name));
	memcpy(db_user, var_db_user, strlen(var_db_user));
	memcpy(db_pwd, var_db_pwd, strlen(var_db_pwd));
	db_pool = var_db_pool;
	memcpy(kfk_brokers, var_kfk_brokers, strlen(var_kfk_brokers));
	memcpy(kfk_topic, var_kfk_topic, strlen(var_kfk_topic));
	memcpy(kfk_group, var_kfk_group, strlen(var_kfk_group));
	acl_xinetd_cfg_free(cfg);
	cfg = NULL;

	if (strcmp(local_addr, "127.0.0.1") == 0 || local_addr[0] == '\0')
	{
		char szAddr[32] = { 0 };
		ACL_IFCONF *ifconf = acl_get_ifaddrs();
		if (ifconf)
		{
			ACL_ITER iter;
			acl_foreach(iter, ifconf)
			{
				ACL_IFADDR *ifaddr = (ACL_IFADDR *)iter.data;
				memset(szAddr, 0, sizeof(szAddr));
				memcpy(szAddr, ifaddr->addr, strlen(ifaddr->addr));
				if (strcmp(szAddr, "0.0.0.0") != 0 &&
					strncmp(szAddr,"0.", strlen("0.")) != 0 &&
					strncmp(szAddr, "169.254", strlen("169.254")) != 0)
				{
					break;
				}
			}
			acl_free_ifaddrs(ifconf);
			memcpy(local_addr, szAddr, strlen(szAddr));
		}
	}
	if (db_driver > 0)
	{
		if (db_addr[0] == '\0' || db_name[0] == '\0')
		{
			printf("数据库配置项无效！\n");
			return false;
		}
	}
	char szLogPath[256] = { 0 };
	if (log_path[0] != '\0')
	{
		acl_make_dirs(log_path, 0777);
		strcpy(szLogPath, log_path);
		if (srv_role == 0)
		{
			strcat(szLogPath, "/SIPNetPlugIn.log");
		}
		else
		{
			strcat(szLogPath, "/siprun.log");
		}
	}
	else
	{
		if (srv_role == 0)
		{
			strcpy(szLogPath, "SIPNetPlugIn.log");
		}
		else
		{
			strcpy(szLogPath, "siprun.log");
		}
	}
	FILE *fp = fopen(szLogPath, "w");
	if (fp)
		fclose(fp);
	logger_open(szLogPath, "sip");
	return true;
}

void config::log(int level, const char *fmt, ...)
{
	if (log_level == LOG_CLOSE)
	{
		return;
	}
	acl::string strLog = Line;
	va_list args;
	va_start(args, fmt);
	strLog.vformat_append(fmt, args);
	va_end(args);
	strLog.append(Line);
#ifdef _WIN32
	if (level >= log_level)
	{
		switch (level)
		{
		case LOG_INFO:
			logger(strLog.c_str());
			break;
		case LOG_WARN:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x06);
			logger_warn(strLog.c_str());
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
			break;
		case LOG_ERROR:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY|FOREGROUND_RED);
			logger_error(strLog.c_str());
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
			break;
		}
	}
#else
	if (level >= log_level)
	{
		switch (level)
		{
		case LOG_INFO:
			logger(strLog.c_str());
			break;
		case LOG_WARN:
			logger_warn(strLog.c_str());
			break;
		case LOG_ERROR:
			logger_error(strLog.c_str());
			break;
		}
	}
#endif
}

