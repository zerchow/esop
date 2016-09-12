#include"ProtocolHeader.h"
#include<json/json.h>
#ifndef _PROTOCOLDATA_DEFINE_H_
#define _PROTOCOLDATA_DEFINE_H_
class ProtocolData
{
public:
	ProtocolData();
	~ProtocolData();

	void set_protocol_header(const ProtocolHeader _protocol_header){
		protocol_header = _protocol_header;
	}
	ProtocolHeader& get_protocol_header(){
		return protocol_header;
	}

	void set_protocol_request_body(const Json::Value _protocol_request_body){
		protocol_request_body = _protocol_request_body;
	}
	Json::Value& get_protocol_request_body(){
		return protocol_request_body;

	}

	void set_response_body(const Json::Value _protocol_response_body){
		protocol_response_body = _protocol_response_body;
	}
	Json::Value& get_response_body(){
		return protocol_response_body;
	}
private:
	ProtocolHeader protocol_header;        //数据头
	Json::Value protocol_request_body;	   //请求数据体
	Json::Value protocol_response_body;	   //请求数据体
};
#endif

