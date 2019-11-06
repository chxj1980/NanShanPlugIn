#pragma once

#pragma comment(lib, "ociliba.lib")
#include "ocilib.h"
#include "config.h"



class DatabaseClient
{
public:
	DatabaseClient();
	~DatabaseClient();
public:
	bool Connect(int driver, const char *addr, const char *server, const char *user, const char *pwd, int thdnum=16);
	void Disconnect();

	bool GetSuperiorRegister(const char *localcode, register_map &regmap);
private:
	int m_driver;
public:
	//oracle
	OCI_Pool *m_pool;
};

