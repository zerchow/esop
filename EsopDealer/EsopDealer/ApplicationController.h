#pragma once
#include "ControllerBase.h"
#include"interface_error_define.h"
#include"ApplicationModel.h"
#include"interface_command_key_define.h"
#include"ProtocolData.h"
class ApplicationController :
	public ControllerBase
{
public:
	ApplicationController();

	ApplicationController(ProtocolData* _protocol_data) :ControllerBase(_protocol_data){}
	~ApplicationController();


	/**
	*Function:			init
	*Description:		传入Json对象root初始化
	*Input:
	*	protocol_data
	*Output:
	*
	*Author:			sean
	*Date:				2016-09-06
	*/
	virtual int init(/*ProtocolData* _protocol_data*/);



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
	//virtual int getReturnMsg(std::string &msg);

	/**
	*Function:			insertApplicationInfo
	*Description:		添加一条报名记录
	*Input:
	*
	*Output:
	*
	*Return
	*Author:			sean
	*Date:				2016-09-06
	*/
	int insertApplicationInfo();

private:
	ApplicationModel model_app;

};

