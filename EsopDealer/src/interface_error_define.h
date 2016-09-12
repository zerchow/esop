/*
 * interface_error_define.h
 *
 *  Created on: 2016-9-1
 *      Author: sean
 */
#ifndef INTERFACE_ERROR_DEFINE_H_
#define INTERFACE_ERROR_DEFINE_H_


enum INTERFACE_ERROR
{
	SUCCEED = 0, 							//成功
	ERR_ILLEGAL_JSON_DATA = -4001,  			//无法解析的JSON数据
	ERR_SERVER_INTERNAL_ERROR = -4002,  		//服务器内部错误

	ERR_USER_NOT_EXIST = -4003,					//不存在此用户
	ERR_COMPANYID_OR_RECORDID_ERROR = -4004,	//公司ID或者记录ID错误
	ERR_USERID_OR_COMPANYID_ERROR = -4005,  	//用户ID或公司ID错误
	ERR_COMPANY_NOT_EXIST = -4006,  			//不存在的公司ID
	ERR_PERMISSION_DENIED = -4007,  			//没有权限
	ERR_DUPLICATE_EGISTRATION = -4008,  		//重复报名

	ERR_DATA_FIELD_LACK = -4009,  				//字段缺失
	ERR_DATA_FIELD_ILLEGAL = -4010,  			//字段非法
	ERR_RECORD_NOT_EXIST = -4011,  				//不存在对应的数据记录
	ERR_ONLINE_UNREVIEWS_DATA = -4012,			//对未审核通过的数据执行上线操作

	ERR_REPORT_NOT_EXIST = -4013,  				//报告不存在
	ERR_DATA_OVERDUE = -4014,  					//授予数据过期
	ERR_DATA_NOT_PASS = -4015,  				//公司资料还未审核通过

	ERR_SUBMIT_TYPE_ERROR = -4016,  			//错误的提交类型
	ERR_TIMES_INSUFFICIENT = -4017,  			//没有查询次数

	ERR_REQUEST_KEY_ERROR = -4018,               //请求命令字错误

	ERR_VERSION_NUMBER_ERROR = -4019,               //请求命令字错误


};

enum INNER_ERROR
{
	ERR_INNER_DATABASE_CONNECTION_ERROR = -4020,       //数据库连接错误
	ERR_INNER_DATABASE_CLOSE_ERROR = -4021			 //关闭数据库错误
};
#endif