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
	*Description:		����Json Value�������ݶ���,����֤����
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
	int company_id;						//��˾ID
	int company_stauff_number;			//Ա��������
	std::string mobile;					//��ϵ����
	std::string company_name_short;		//��˾���
	std::string linkman_position;	    //��ϵ��ְλ
	std::string linkman_email;		    //��ϵ������
	short int status;				    //���״̬��δ��ˡ�����С����ͨ����
	std::string linkman_name;		    //��ϵ������
	std::string  application_time;		    //����ʱ��
	std::string  headoffice;			//�ܲ����ڵ�
	std::string  company_name;			//��˾����
	short int  industry;				//��ҵ��1��������2�����3���������ڣ�4O2O��5�Ʒ���6����/ƽ̨/����; 7��Ƶ/ý��/���;8��Ϸ��9����Ӳ����0������
	short int  register_;				//ע��أ�1����2���⣩
	short int  is_deleted;				//�Ƿ�ɾ��
	std::string  industry_other;		//�����������ҵ
};

