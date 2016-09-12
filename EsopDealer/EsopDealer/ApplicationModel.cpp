#include "ApplicationModel.h"
#include<cstdio>
using namespace std;
using namespace Json;

ApplicationModel::ApplicationModel()
{
}
//ApplicationModel::ApplicationModel(int _idesop_application_form,
//						int _company_id,
//						int _company_stauff_number,
//						std::string _mobile,
//						std::string _company_name_short,
//						std::string _linkman_position,
//						std::string _linkman_email,
//						short int _status,
//						std::string _linkman_name,
//						time_t  _application_time,
//						std::string  _headoffice,
//						std::string  _company_name,
//						short int  _industry,
//						short int  _register_,
//						short int  _is_deleted,
//						std::string  _industry_other)
//{
//	idesop_application_form = _idesop_application_form;
//	company_id = _company_id;
//	company_stauff_number = _company_stauff_number;
//	mobile = _mobile;
//	company_name_short = _company_name_short;
//	linkman_position = _linkman_position;
//	linkman_email = _linkman_email;
//	status = _status;
//	linkman_name = _linkman_name;
//	application_time = _application_time;
//	headoffice = _headoffice;
//	company_name = _company_name;
//	industry = _industry;
//	register_ = _register_;
//	is_deleted = _is_deleted;
//	industry_other = _industry_other;
//
//}

ApplicationModel::~ApplicationModel()
{
}


int ApplicationModel::initAndValidate(Json::Value &_json_obj){

	bool _is_complete = true;
	if (_json_obj.isNull()){
		return ERR_ILLEGAL_JSON_DATA;
	}
	if (_json_obj["company_name"].isNull()){
		_is_complete = false;
	}
	if (!_json_obj["company_name"].isString()){
		return ERR_DATA_FIELD_ILLEGAL;
	}
	company_name = _json_obj["company_name"].asString();
	if (_json_obj["company_name_short"].isNull()){
		_is_complete = false;
	}
	if (!_json_obj["company_name_short"].isString()){
		return ERR_DATA_FIELD_ILLEGAL;
	}
	company_name_short = _json_obj["company_name_short"].asString();
	if (_json_obj["company_stauff_number"].isNull()){
		_is_complete = false;
	}
	if (!_json_obj["company_stauff_number"].isInt()){
		return ERR_DATA_FIELD_ILLEGAL;
	}
	company_stauff_number = _json_obj["company_stauff_number"].asInt();
	if (_json_obj["head_office"].isNull()){
		_is_complete = false;
	}
	if (!_json_obj["head_office"].isString()){
		return ERR_DATA_FIELD_ILLEGAL;
	}
	headoffice = _json_obj["head_office"].asString();
	if (_json_obj["industry"].isNull()){
		_is_complete = false;
	}
	if (!_json_obj["industry"].isInt()){
		return ERR_DATA_FIELD_ILLEGAL;
	}
	industry = _json_obj["industry"].asInt();
	/*if (_json_obj["is_deleted"].isNull){
		is_complete = false;
	}
	if (!_json_obj["is_deleted"].isString()){
		return ERR_DATA_FIELD_ILLEGAL;
	}*/
	is_deleted = 0;
	if (_json_obj["contact_email"].isNull()){
		_is_complete = false;
	}
	if (!_json_obj["contact_email"].isString()){
		return ERR_DATA_FIELD_ILLEGAL;
	}
	linkman_email = _json_obj["contact_email"].asString();
	if (_json_obj["contact_name"].isNull()){
		_is_complete = false;
	}
	if (!_json_obj["contact_name"].isString()){
		return ERR_DATA_FIELD_ILLEGAL;
	}
	linkman_name = _json_obj["contact_name"].asString();
	if (_json_obj["contact_position"].isNull()){
		_is_complete = false;
	}
	if (!_json_obj["contact_position"].isString()){
		return ERR_DATA_FIELD_ILLEGAL;
	}
	linkman_position = _json_obj["contact_position"].asString();
	if (_json_obj["contact_phone"].isNull()){
		_is_complete = false;
	}
	if (!_json_obj["contact_phone"].isString()){
		return ERR_DATA_FIELD_ILLEGAL;
	}
	mobile = _json_obj["contact_phone"].asString();
	if (_json_obj["register"].isNull()){
		_is_complete = false;
	}
	if (!_json_obj["register"].isInt()){
		return ERR_DATA_FIELD_ILLEGAL;
	}
	register_ = _json_obj["register"].asInt();

	/*std::stringstream strApplication_time;
	time_t  tApplication_time;
	time(&tApplication_time);
	strApplication_time << tApplication_time;

	app.application_time = strApplication_time.str();*/
	application_time = "2015.09.16";

	this->is_complete = _is_complete;

	return SUCCEED;
}