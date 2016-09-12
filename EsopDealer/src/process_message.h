/**************************************************************************
*Copyright:tencent MCD
*Author: 
*Date:2016-09-06
*Description:
**************************************************************************/

#include<string>
#include <json/json.h>
#include"ControllerBase.h"
#include"ControllerFactory.h"
#include"interface_error_define.h"
#include"interface_command_key_define.h"
#include"ProtocolHeader.h"


extern std::map<int, std::string> map_version;
/**
*Function:			init
*Description:		一些必要的初始化工作
*Input:
*
*Output:
*
*Author:			sean
*Date:				2016-09-06
*/
int init();
/**
*Function:			fini
*Description:		结束时的一些收尾工作
*Input:
*
*Output:
*
*Author:			sean
*Date:				2016-09-06
*/
int fini();

/**
*Function:			process_message
*Description:		初始化版本号数组
*Input:
*	 
*Output:
*	 
*Author:			sean
*Date:				2016-09-06
*/
void init_map_version();
/**
*Function:			process_message
*Description:		由SPP调用，是整个项目的入口
*Input:
*	request			输入的请求Json串
*Output:
*	response		输出的响应Json串
*Author:			sean
*Date:				2016-09-06
*/
int process_message(const std::string &request,std::string &response);

/**
*Function:			parseDataFromString
*Description:		解析Json串
*Input:
*	src				输入Json串
*Output:
*	root			解析出来的Json对象
*   req_key			返回解析出来的请求命令字
*	device_number	设备号
*
*Author:			sean
*Date:				2016-09-06
*/
int parseDataFromString(const std::string &src, Json::Value &root, int &req_key, std::string &device_number);

/**
*Function:			parseDataFromString
*Description:		解析Json串
*Input:
*	src				输入Json串
*Output:
*	_protocol_data	解析出来的Json对象
*
*Author:			sean
*Date:				2016-09-06
*/
int parseDataFromString(const std::string &src, ProtocolData &_protocol_data);

/**
*Function:			parseDataFail
*Description:		Json串错误或者请求串错误
*Input:
*   req_key			返回解析出来的请求命令字
*	device_number	设备号
*Output:
*
*Return				返回回包的字符串
*Author:			sean
*Date:				2016-09-06
*/
std::string parseDataFail(const int req_key, const std::string device_number,const int error_code,const std::string error_message="");

/**
*Function:			parseDataFail
*Description:		Json串错误或者请求串错误
*Input:
*   protocol_header	
*Output:
*
*Return				返回回包的字符串
*Author:			sean
*Date:				2016-09-06
*/
std::string parseDataFail(ProtocolHeader protocol_header , const int error_code, const std::string error_message = "");