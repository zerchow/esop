/**************************************************************************
*Copyright:tencent MCD
*Author:
*Date:2016-09-06
*Description:
**************************************************************************/
#include"ControllerBase.h"
#include"interface_command_key_define.h"
#include"interface_error_define.h"
#include"ApplicationController.h"
class ControllerFactory
{
public:
	/**
	*Function:       createController
	*Description:    ����������ʵ��
	*Input:
	*	req_key      ����ӿ�������
	*Output:
	*	response     �������ӦJson��
	*Author:
	*Date:2016-09-06
	*/
	static ControllerBase* createController(int req_key, ProtocolData* _protocol_data){
		switch (req_key)
		{
		case KEY_SIGN_UP:
			return new ApplicationController(_protocol_data);
		default:
				return NULL;
				break;
		}
	}
	ControllerFactory();
	~ControllerFactory();
};

