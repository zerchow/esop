#pragma execution_character_set("utf-8")
#include <iostream>
#include <json\json.h>
#include <mysql.h>
#include "clib_mysql.h"
#include <string>
#include <clocale>

using namespace std;

#define HOST "localhost"
#define PORT 3306
#define USER "root"
#define PASS "root"
#define DB "db_tencent_esop"

int main()
{
	//char * pTest = "����1ge�����ַ���abc";
	//char * pGbk = NULL;
	//uint iErr;

	////1��GBK����תutf-8���3��ascii�ַ�
	//char *pTestUtf8 = (char*)malloc(strlen(pTest) * 3 + 1);
	//uint32 iRealLen = gbk2utf8(pTestUtf8, strlen(pTest) * 3, pTest, strlen(pTest), &iErr);
	//pTestUtf8[iRealLen] = '\0';
	//printf("len=%d,%s\n", iRealLen, pTestUtf8);

	//pGbk = (char*)malloc(iRealLen + 1);
	//iRealLen = utf82gbk(pGbk, iRealLen, pTestUtf8, iRealLen, &iErr);
	//pGbk[iRealLen] = '\0';
	//printf("len=%d,%s\n", iRealLen, pGbk);

	//free(pTestUtf8);
	//free(pGbk);

	//return 0;

	clib_mysql * obj = clib_mysql::get_instance(HOST, PORT, USER, PASS);
	obj->db_connect();
	obj->set_db(DB);
	string sql = "insert into log values(1, '����Ա', 1, '��������', '2016-09-12', '192.168.0.1', '���Բ���', 'ESOP', 4);";
	obj->set_character_set("utf8");
	int ret = obj->query(sql.c_str());
	cout << ret << endl;

	return 0;
}