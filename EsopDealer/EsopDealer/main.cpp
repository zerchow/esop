#pragma execution_character_set("utf-8")
#include <iostream>
#include <json\json.h>
#include <mysql.h>
#include "clib_mysql.h"
#include <string>

using namespace std;

#define HOST "localhost"
#define PORT 3306
#define USER "root"
#define PASS "root"
#define DB "db_tencent_esop"

int main()
{
	clib_mysql * obj = clib_mysql::get_instance(HOST, PORT, USER, PASS);
	obj->db_connect();
	obj->set_db(DB);
	obj->set_character_set("utf8");
	int ret;
	/*string sql = "insert into log(operator, operator_id, operated_object, operate_time, operate_ip, operate_explanation, application, sensitivity_level) values('程序员', 1, '操作对象', '2016-09-12', '192.168.0.1', '测试插入', 'ESOP', 4);";

	obj->set_character_set("utf8");
	ret = obj->query(sql.c_str());
	cout << ret << endl;*/

	//sql = "INSERT INTO esop_application_form(company_stauff_number,mobile,company_name_short,linkman_position,linkman_name,	application_time,headoffice,company_name,industry,register,is_deleted,industry_other) VALUES(30000, '15023333333', '腾讯', 'CEO', 'Pony', '2015.09.16', '深圳', '腾讯公司',1, 1, 0, '');";
	char templatesql[] = "INSERT INTO esop_application_form(company_stauff_number,mobile,company_name_short,linkman_position,linkman_name,application_time,headoffice,company_name,industry,register,is_deleted,industry_other) VALUES(%d, '%s', '%s', '%s', '%s', '%s', '%s', '%s', %d, %d, %d, '%s');";
	string stringsql = "INSERT INTO esop_application_form(company_stauff_number,mobile,company_name_short,linkman_position,linkman_name,application_time,headoffice,company_name,industry,register,is_deleted,industry_other) VALUES(%d, '%s', '%s', '%s', '%s', '%s', '%s', '%s', %d, %d, %d, '%s');";
	char testsql[1024] = "";
	snprintf(testsql, 1024, stringsql.c_str(), 30000, "15023333333", "腾讯", "CEO", "Pony", "2015.09.16", "深圳", "腾讯公司", 1, 1, 0, "");
	//cout << testsql << endl;
	ret = obj->query(testsql);
	cout << ret << endl;

	return 0;
}