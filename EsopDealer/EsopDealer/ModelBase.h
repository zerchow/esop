#include<string>
#include <time.h>
#include"clib_mysql.h"
#ifdef WIN32
#include "json/json.h"
#else
#include <json/json.h>
#endif
#include"interface_error_define.h"
class ModelBase{

public:
	ModelBase();
	~ModelBase();
	///**
	//*Function:			JsonObj2Attribute
	//*Description:		Json 对象转为模型属性
	//*Input:
	//*
	//*Output:
	//*
	//*Return
	//*Author:			sean
	//*Date:				2016-09-07
	//*/
	//template<typename T>
	//int JsonObj2Attribute(T &attri, Json::Value &jObj);

	/**
	*Function:			init
	*Description:		利用Json Value构造数据对象,并验证数据
	*Input:
	*
	*Output:
	*
	*Return
	*Author:			sean
	*Date:				2016-09-07
	*/
	virtual int initAndValidate(Json::Value &jvData);

	bool is_complete;
};