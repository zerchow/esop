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
*Description:		һЩ��Ҫ�ĳ�ʼ������
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
*Description:		����ʱ��һЩ��β����
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
*Description:		��ʼ���汾������
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
*Description:		��SPP���ã���������Ŀ�����
*Input:
*	request			���������Json��
*Output:
*	response		�������ӦJson��
*Author:			sean
*Date:				2016-09-06
*/
int process_message(const std::string &request,std::string &response);

/**
*Function:			parseDataFromString
*Description:		����Json��
*Input:
*	src				����Json��
*Output:
*	root			����������Json����
*   req_key			���ؽ�������������������
*	device_number	�豸��
*
*Author:			sean
*Date:				2016-09-06
*/
int parseDataFromString(const std::string &src, Json::Value &root, int &req_key, std::string &device_number);

/**
*Function:			parseDataFromString
*Description:		����Json��
*Input:
*	src				����Json��
*Output:
*	_protocol_data	����������Json����
*
*Author:			sean
*Date:				2016-09-06
*/
int parseDataFromString(const std::string &src, ProtocolData &_protocol_data);

/**
*Function:			parseDataFail
*Description:		Json������������󴮴���
*Input:
*   req_key			���ؽ�������������������
*	device_number	�豸��
*Output:
*
*Return				���ػذ����ַ���
*Author:			sean
*Date:				2016-09-06
*/
std::string parseDataFail(const int req_key, const std::string device_number,const int error_code,const std::string error_message="");

/**
*Function:			parseDataFail
*Description:		Json������������󴮴���
*Input:
*   protocol_header	
*Output:
*
*Return				���ػذ����ַ���
*Author:			sean
*Date:				2016-09-06
*/
std::string parseDataFail(ProtocolHeader protocol_header , const int error_code, const std::string error_message = "");