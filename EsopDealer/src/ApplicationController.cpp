#include "ApplicationController.h"
#include"interface_command_key_define.h"
#include<string>
#include<sstream>
using namespace Json;
using namespace std;

//ApplicationController::ApplicationController()
//{
//}


ApplicationController::~ApplicationController()
{
}


int ApplicationController::init(){
	int ret = model_app.initAndValidate(protocol_data->get_protocol_request_body());
	return_code = ret;
	return ret;
}

int ApplicationController::process(){
	if (return_code != SUCCEED)
		return return_code;

	int ret = insertApplicationInfo();
	return_code = ret;
	return ret;
}

//int ApplicationController::getReturnMsg(string &msg){
//	return SUCCEED;
//}

int ApplicationController::insertApplicationInfo(){
	if (model_app.is_complete == false){
		return ERR_DATA_FIELD_LACK;
	}
	char sql[1024] = "";
	/*insert INTO
	esop_application_form(company_stauff_number,
	mobile,
	company_name_short,
	linkman_position,
	linkman_name,
	application_time,
	headoffice,
	company_name,
	industry,
	register,
	is_deleted,
	industry_other)
	VALUES(1000,'12345679947','58','CEO','sean','2016.09.06',1,'58Í¬³Ç',1,1,1,'')*/
	string sqlForm = "INSERT INTO esop_application_form(company_stauff_number,mobile,company_name_short,linkman_position,linkman_name,\
					 application_time,headoffice,company_name,industry,register,is_deleted,industry_other) \
					 VALUES(%d, \'%s\', \'%s\', \'%s\', \'%s\', \'%s\', \'%s\', \'%s\',%d, %d, %d, \'%s\')";
	

#ifdef WIN32
	sprintf_s(sql, sizeof(sql), sqlForm.c_str(),
		model_app.company_stauff_number,
		model_app.mobile.c_str(),
		model_app.company_name_short.c_str(),
		model_app.linkman_position.c_str(),
		model_app.linkman_name.c_str(),
		model_app.application_time.c_str(),
		model_app.headoffice.c_str(),
		model_app.company_name.c_str(),
		model_app.industry,
		model_app.register_,
		model_app.is_deleted,
		model_app.industry_other.c_str());

#else
	snprintf(sql, sizeof(sql), sqlForm.c_str(),
		mApp.company_stauff_number,
		mApp.mobile.c_str(),
		mApp.company_name_short.c_str(),
		mApp.linkman_position.c_str(),
		mApp.linkman_name.c_str(),
		mApp.application_time.c_str(),
		mApp.headoffice.c_str(),
		mApp.company_name.c_str(),
		mApp.industry,
		mApp.register_,
		mApp.is_deleted,
		mApp.industry_other.c_str());
#endif
	obj_mysql->set_character_set("UTF-8");
	int ret = obj_mysql->query(sql);
	if (ret != 0){
		printf("fail");
	}
	return SUCCEED;
}
