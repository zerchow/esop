#include<map>
/*
 * interface_command_key_define.h
 *
 *  Created on: 2016-9-1
 *      Author: sean
 */
#ifndef INTERFACE_COMMAND_KEY_DEFINE_H_
#define INTERFACE_COMMAND_KEY_DEFINE_H_


enum INTERFACE_COMMAND_KEY
{
	KEY_SIGN_UP = 1001,  							//提交报名
	KEY_USER_SIGN_UP_INFO_REVIEW = 1002,			//查看报名信息
	KEY_MCD_SIGN_UP_INFO_REVIEW = 1003,
	KEY_MODIFY_SIGN_UP_INFO = 1004,  				//修改报名信息
	KEY_GET_MCDID = 1005,					        //微信ID反转		
	
	KEY_CENTRALIZED_GRANT_DATA_SAVE = 1006, 		//esop调研保存
	KEY_CENTRALIZED_GRANT_DATA_SUBMIT = 1007,  		//esop调研提交(集中数据)
	KEY_GET_DATA_SUBMIT_SCHEDULE = 1008,			//查看数据提交进度		

	KEY_GET_COMPANY_SUBMIT_DATA_LIST = 1009,  		//获取指定公司提交数据列表
	KEY_VIEW_RETRIEVE_HISTORY = 1010,				//查看历史记录			
	KEY_GET_DATA_SUBMIT_RECORDS = 1011,				//查看ESOP调研更新记录	
	KEY_CENTRALIZED_GRANT_DATA_REVIEW = 1012,  		//查看esop调研提交(集中数据)
	KEY_MODIFY_GRANT = 1013,						//权限修改申请		
	
	KEY_VIEW_REPORT = 1014,  						//查看报告
	KEY_RETRIEVE_STOCK_OWNERSHIPT_INCENTIVE = 1015,	//查询股权激励
	KEY_INCREASE_POSITION_DATA = 1016,				//新增岗位		
	KEY_GET_RETRIEVE_TIMES = 1017,					//获取查询次数	
	
	KEY_REVIEW_SIGN_UP = 1018,						//审核报名信息			
	KEY_GET_COMPANY_LIST = 1019,  					//(查询)获取公司列表
	KEY_GET_COMPANY_USER_LIST = 1020, 				//获取指定公司填答人和查看人信息
	KEY_ON_OR_OFF_LINE_COMPANY_DATA = 1021,   		//上下线指定公司提交数据
	KEY_PREVIEW_REPORT = 1022,				       	//预览报告								
	KEY_REVIEW_SUBMIT_DATA = 1023  					//审核指定公司提交数据

};


#endif