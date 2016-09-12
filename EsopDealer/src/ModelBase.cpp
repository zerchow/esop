#include"ModelBase.h"



ModelBase::ModelBase()
{
	//mysql_set_character_set(&db, "utf8");
	is_complete = false;
}
ModelBase::~ModelBase()
{
}

int ModelBase::initAndValidate(Json::Value &_json_obj){
	return SUCCEED;
}
//template<typename T>
//int ModelBase::JsonObj2Attribute(T &attri, Json::Value &jObj){
//	
//}