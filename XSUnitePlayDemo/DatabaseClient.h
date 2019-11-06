#pragma once


#pragma comment(lib, "ociliba.lib")
#include "ocilib.h"

#include <vector>
#include <string>
using namespace std;

#define DB_NONE		0
#define DB_ORACLE	1
#define DB_MYSQL	2
#define DB_SQLITE	3


class DatabaseClient
{
public:
	DatabaseClient();
	~DatabaseClient();
public:
	bool Connect(int driver, const char *addr, const char *server, const char *user, const char *pwd, int thdnum=16);
	void Disconnect();

	bool GetHighPointChannels(const char *localcode, vector<int> &chanlist);
private:
	int m_driver;
public:
	//oracle
	OCI_Pool *m_pool;
};

