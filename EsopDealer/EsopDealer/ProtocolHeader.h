#include<string>
#ifndef _PROTOCOLHEADER_DEFINE_H_
#define _PROTOCOLHEADER_DEFINE_H_
class ProtocolHeader
{
public:
	ProtocolHeader();
	~ProtocolHeader();

	void set_version(const std::string _version){
		version = _version;
	}
	std::string get_version(){
		return version;
	}

	void set_req_key(const int _req_key){
		req_key = _req_key;
	}
	int get_req_key(){
		return req_key;
	}

	void set_mcd_id(const int _mcd_id){
		mcd_id = _mcd_id;
	}
	int get_mcd_id(){
		return mcd_id;
	}

	void set_company_id(const int _company_id){
		company_id = _company_id;
	}
	int get_company_id(){
		return company_id;
	}

	void set_return_code(const int _return_code){
		return_code = _return_code;
	}
	int get_return_code(){
		return return_code;
	}

	void set_device_mac(const std::string _device_mac){
		device_mac = _device_mac;
	}
	std::string get_device_mac(){
		return device_mac;
	}
	
	void set_device_name(const std::string _device_name){
		device_name = _device_name;
	}
	std::string get_device_name(){
		return device_name;
	}

	void set_error_msg(const std::string _error_msg){
		error_msg = _error_msg;
	}
	std::string get_error_msg(){
		return error_msg;
	}


private:
	std::string version;		//版本号
	int req_key;				//请求码
	int mcd_id;		
	int company_id;

	std::string  device_mac;
	std::string device_name;

	int return_code;			//返回状态码
	std::string error_msg;       //错误信息
};

//数据格式
#define HEADER "header"
#define BODY "body"
#define REQKEY "req_key"
#define DEVNUM "device_mac"
#define DEVNAME "device_name"
#define RETURNCODE "return_code"
#define ERRMSG "error_msg"
#define VERSION "version"
#define MCDID "mcd_id"
#define COMPANYID "company_id"

#endif

