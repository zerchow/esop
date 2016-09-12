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
	*Description:		����Json����root��ʼ��
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
	*Description:		�������ݴ���
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
	*Description:		�������ݴ���
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
	*Description:		���һ��������¼
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

