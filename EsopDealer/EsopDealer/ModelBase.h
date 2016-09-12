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
	//*Description:		Json ����תΪģ������
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
	*Description:		����Json Value�������ݶ���,����֤����
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