#include"ModelBase.h"
#include"interface_error_define.h"
#include<json/json.h>
class ApplicationModel :
	public ModelBase
{
public:
	ApplicationModel();

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
	virtual int initAndValidate(Json::Value &_json_obj);


	~ApplicationModel();

//public:
	int idesop_application_form;
	int company_id;						//公司ID
	int company_stauff_number;			//员工总人数
	std::string mobile;					//联系号码
	std::string company_name_short;		//公司简称
	std::string linkman_position;	    //联系人职位
	std::string linkman_email;		    //联系人邮箱
	short int status;				    //审核状态（未审核、审核中、审核通过）
	std::string linkman_name;		    //联系人姓名
	std::string  application_time;		    //报名时间
	std::string  headoffice;			//总部所在地
	std::string  company_name;			//公司名称
	short int  industry;				//行业（1电子商务；2软件；3互联网金融；4O2O；5云服务；6搜索/平台/社区; 7视频/媒体/广告;8游戏；9智能硬件；0其他）
	short int  register_;				//注册地（1境内2境外）
	short int  is_deleted;				//是否删除
	std::string  industry_other;		//具体的其他行业
};

