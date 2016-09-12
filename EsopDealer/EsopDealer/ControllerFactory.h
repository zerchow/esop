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
	*Description:    创建控制器实例
	*Input:
	*	req_key      请求接口命令字
	*Output:
	*	response     输出的响应Json串
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

