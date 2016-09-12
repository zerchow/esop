#include<json/json.h>
#include"interface_error_define.h"
#include"interface_command_key_define.h"
#include"ProtocolData.h"
#include"clib_mysql.h"

#define HOST "localhost"
#define PORT 3306
#define USER "sean"
#define PASS "sean123"

#ifndef _CONTROLLERBASE_DEFINE_H_
#define _CONTROLLERBASE_DEFINE_H_
class ControllerBase
{
public:
	ControllerBase(){
		obj_mysql = clib_mysql::get_instance(HOST, PORT, USER, PASS);
	}

	ControllerBase(ProtocolData* _protocol_data){
		obj_mysql = clib_mysql::get_instance(HOST, PORT, USER, PASS);
		protocol_data = _protocol_data;
	}
	~ControllerBase(){}
	/**
	*Function:			init
	*Description:		初始化Model
	*Input:
	*	protocol_data	
	*Output:
	*
	*Author:			sean
	*Date:				2016-09-06
	*/
	virtual int init();

	/**
	*Function:			process
	*Description:		进行数据处理
	*Input:
	*	
	*Output:
	*
	*Author:			sean
	*Date:				2016-09-06
	*/
	virtual int process();

	/**
	*Function:			process
	*Description:		进行数据处理
	*Input:
	*
	*Output:
	*
	*Author:			sean
	*Date:				2016-09-06
	*/
	int getReturnMsg(std::string &msg);

	/*std::string DataFail(const int req_key, const std::string device_number, const int error_code, const std::string error_message){
		Value root, header, body;
		header[REQKEY] = req_key;
		header[DEVNUM] = device_number;
		header[RETURNCODE] = error_code;
		header[ERRMSG] = error_message;
		root[HEADER] = header;
		root[BODY] = body;
		return root.toStyledString();
	}*/

protected:
	clib_mysql* obj_mysql;
	ProtocolData* protocol_data;
	int return_code;					//状态码，如果为0表示处理流程暂时没有错误，非0表示已出现错误
	std::string error_message;			//错误信息,用于返回给PHP端
	std::string log_message;			//日志信息，用于记录日志
};
#endif 
