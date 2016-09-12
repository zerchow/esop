#include "process_message.h"
#include"ProtocolData.h"

using namespace Json;
using namespace std;


std::map<int, std::string> map_version;
int process_message(const std::string &request, std::string &response){
	
	ProtocolData protocol_data;
	int ret = parseDataFromString(request, protocol_data);
	if (ret != SUCCEED){
		response = parseDataFail(protocol_data.get_protocol_header(), ret);//错误提示回包
		return ret;
	}

	if (protocol_data.get_protocol_header().get_version() != map_version[protocol_data.get_protocol_header().get_req_key()]){  //版本号验证
		response = parseDataFail(protocol_data.get_protocol_header(), ERR_VERSION_NUMBER_ERROR);//错误提示回包
		return ERR_VERSION_NUMBER_ERROR;
	}
	ControllerBase* controller_base = ControllerFactory::createController(protocol_data.get_protocol_header().get_req_key(),&protocol_data);
	if (controller_base == NULL){
		//写入敏感日志
		response = parseDataFail(protocol_data.get_protocol_header(), ERR_REQUEST_KEY_ERROR);//错误提示回包
		return ERR_REQUEST_KEY_ERROR;
	}
	controller_base->init();  //输入传入Model
	controller_base->process();  //业务处理及回包数据封装
	ret = controller_base->getReturnMsg(response);  //返回回包数据
	if (ret != SUCCEED){
		response = parseDataFail(protocol_data.get_protocol_header(), ERR_SERVER_INTERNAL_ERROR);//错误提示回包
	}
	if (controller_base != NULL){
		delete controller_base;
		controller_base = NULL;
	}
	return SUCCEED;
	
}

int parseDataFromString(const std::string &src, Json::Value &root, int &req_key, std::string &device_number){
	Reader reader(Features::strictMode());
	if (!reader.parse(src, root)){
		return ERR_ILLEGAL_JSON_DATA;
	}
	if (root.isNull()){
		return ERR_ILLEGAL_JSON_DATA;
	}
	if (root[HEADER].isNull()){
		return ERR_ILLEGAL_JSON_DATA;
	}
	if (root[HEADER][REQKEY].isNull() || !root[HEADER][REQKEY].isInt()){
		return ERR_ILLEGAL_JSON_DATA;
	}
	if (root[HEADER][DEVNUM].isNull() || !root[HEADER][DEVNUM].isString()){
		return ERR_ILLEGAL_JSON_DATA;
	}
	req_key = root[HEADER][REQKEY].asInt();
	device_number = root[HEADER][DEVNUM].asString();
	return SUCCEED;
}

int parseDataFromString(const std::string &src, ProtocolData &_protocol_data){
	Value root;
	Reader reader(Features::strictMode());
	if (!reader.parse(src, root)){
		return ERR_ILLEGAL_JSON_DATA;
	}
	if (root.isNull()){
		return ERR_ILLEGAL_JSON_DATA;
	}
	if (root[HEADER].isNull()){
		return ERR_ILLEGAL_JSON_DATA;
	}
	/*
	//数据格式
	#define REQKEY "req_key"
	#define DEVNUM "device_mac"
	#define DEVNAME "device_name"
	#define RETURNCODE "return_code"
	#define ERRMSG "error_msg"
	#define VERSION "version"
	#define MCDID "mcd_id"
	#define COMPANYID "company_id"
	*/
	if (root[HEADER][VERSION].isNull() || !root[HEADER][VERSION].isString()){
		return ERR_ILLEGAL_JSON_DATA;
	}
	if (root[HEADER][REQKEY].isNull() || !root[HEADER][REQKEY].isInt()){
		return ERR_ILLEGAL_JSON_DATA;
	}
	if (root[HEADER][DEVNUM].isNull() || !root[HEADER][DEVNUM].isString()){
		return ERR_ILLEGAL_JSON_DATA;
	}
	if (root[HEADER][DEVNAME].isNull() || !root[HEADER][DEVNAME].isString()){
		return ERR_ILLEGAL_JSON_DATA;
	}
	if (root[HEADER][MCDID].isNull() || !root[HEADER][MCDID].isInt()){
		return ERR_ILLEGAL_JSON_DATA;
	}
	if (root[HEADER][COMPANYID].isNull() || !root[HEADER][COMPANYID].isInt()){
		return ERR_ILLEGAL_JSON_DATA;
	}
	/*if (root[HEADER][RETURNCODE].isNull() || !root[HEADER][RETURNCODE].isString()){
		return ERR_ILLEGAL_JSON_DATA;
	}
	if (root[HEADER][ERRMSG].isNull() || !root[HEADER][ERRMSG].isString()){
		return ERR_ILLEGAL_JSON_DATA;
	}*/
	ProtocolHeader protocol_header;
	protocol_header.set_version(root[HEADER][VERSION].asString());
	protocol_header.set_device_mac(root[HEADER][DEVNUM].asString());
	protocol_header.set_device_name(root[HEADER][DEVNAME].asString());
	protocol_header.set_req_key(root[HEADER][REQKEY].asInt());
	protocol_header.set_mcd_id(root[HEADER][MCDID].asInt());
	protocol_header.set_company_id(root[HEADER][COMPANYID].asInt());
	
	if (root[BODY].isNull()){
		return ERR_ILLEGAL_JSON_DATA;
	}
	_protocol_data.set_protocol_header(protocol_header);
	_protocol_data.set_protocol_request_body(root[BODY]);
	return SUCCEED;
}

std::string parseDataFail(const int req_key, const std::string device_number,const int error_code, const std::string error_message){
	Value root, header, body;
	header[REQKEY] = req_key;
	header[DEVNUM] = device_number;
	header[RETURNCODE] = error_code;
	header[ERRMSG] = error_message;
	root[HEADER] = header;
	root[BODY] = body;
	return root.toStyledString();
}


std::string parseDataFail(ProtocolHeader protocol_header, const int error_code, const std::string error_message){
	Value root, header, body;
	header[VERSION] = protocol_header.get_version();
	header[REQKEY] = protocol_header.get_req_key();
	header[DEVNUM] = protocol_header.get_device_mac();
	header[DEVNAME] = protocol_header.get_device_name();
	header[DEVNAME] = protocol_header.get_mcd_id();
	header[DEVNAME] = protocol_header.get_company_id();
	header[RETURNCODE] = error_code;
	header[ERRMSG] = error_message;

	root[HEADER] = header;
	root[BODY] = body;
	return root.toStyledString();
}


void init_map_version(){
	map_version[KEY_SIGN_UP] = "2016090500"; 							//提交报名
	map_version[KEY_USER_SIGN_UP_INFO_REVIEW] = "2016090500";			//查看报名信息
	map_version[KEY_MCD_SIGN_UP_INFO_REVIEW] = "2016090500";
	map_version[KEY_MODIFY_SIGN_UP_INFO] = "2016090500";  				//修改报名信息
	map_version[KEY_GET_MCDID] = "2016090500";					        //微信ID反转		
	
	map_version[KEY_CENTRALIZED_GRANT_DATA_SAVE] = "2016090500"; 		//esop调研保存
	map_version[KEY_CENTRALIZED_GRANT_DATA_SUBMIT] = "2016090500";  		//esop调研提交(集中数据)
	map_version[KEY_GET_DATA_SUBMIT_SCHEDULE] = "2016090500";			//查看数据提交进度		
	
	map_version[KEY_GET_COMPANY_SUBMIT_DATA_LIST] = "2016090500";  		//获取指定公司提交数据列表
	map_version[KEY_VIEW_RETRIEVE_HISTORY] = "2016090500";				//查看历史记录			
	map_version[KEY_GET_DATA_SUBMIT_RECORDS] = "2016090500";				//查看ESOP调研更新记录	
	map_version[KEY_CENTRALIZED_GRANT_DATA_REVIEW] = "2016090500";  		//查看esop调研提交(集中数据)
	map_version[KEY_MODIFY_GRANT] = "2016090500";						//权限修改申请		
	
	map_version[KEY_VIEW_REPORT] = "2016090500";  						//查看报告
	map_version[KEY_RETRIEVE_STOCK_OWNERSHIPT_INCENTIVE] = "2016090500";	//查询股权激励
	map_version[KEY_INCREASE_POSITION_DATA] = "2016090500";				//新增岗位		
	map_version[KEY_GET_RETRIEVE_TIMES] = "2016090500";					//获取查询次数	
	
	map_version[KEY_REVIEW_SIGN_UP] = "2016090500";						//审核报名信息			
	map_version[KEY_GET_COMPANY_LIST] = "2016090500";  					//(查询)获取公司列表
	map_version[KEY_GET_COMPANY_USER_LIST] = "2016090500"; 				//获取指定公司填答人和查看人信息
	map_version[KEY_ON_OR_OFF_LINE_COMPANY_DATA] = "2016090500";   		//上下线指定公司提交数据
	map_version[KEY_PREVIEW_REPORT] = "2016090500";				       	//预览报告								
	map_version[KEY_REVIEW_SUBMIT_DATA] = "2016090500";  							//审核指定公司提交数据
}


int init(){
	//初始化数组
	init_map_version();

	//初始化数据库
	#define HOST "localhost"
	#define PORT 3306
	#define USER "sean"
	#define PASS "sean123"
	clib_mysql*  obj_mysql = clib_mysql::get_instance(HOST, PORT, USER, PASS);
	int iret = obj_mysql->db_connect();
	if (iret != 0){
		//TODO: 错误日志
		return ERR_INNER_DATABASE_CONNECTION_ERROR;
	}
	iret = obj_mysql->set_db("db_tencent_esop");
	if (iret != 0){
		//TODO: 错误日志
		return ERR_INNER_DATABASE_CONNECTION_ERROR;
	}
	//数据库初始化及选着数据库
	
	return SUCCEED;
}

int fini(){
	#define HOST "localhost"
	#define PORT 3306
	#define USER "sean"
	#define PASS "sean123"
	clib_mysql*  obj_mysql = clib_mysql::get_instance(HOST, PORT, USER, PASS);
	int ret = obj_mysql->db_close();
	if (ret != SUCCEED){
		//TODO: 错误日志
		return ERR_INNER_DATABASE_CLOSE_ERROR;
	}
}