#include "ControllerBase.h"
using namespace Json;

int ControllerBase::init(/*ProtocolData* _protocol_data*/){

	return SUCCEED;
}

int ControllerBase::process(){
	return SUCCEED;
}

int ControllerBase::getReturnMsg(std::string &msg){
	Value root, header;

	header[VERSION] = protocol_data->get_protocol_header().get_version();
	header[REQKEY] = protocol_data->get_protocol_header().get_req_key();
	header[DEVNUM] = protocol_data->get_protocol_header().get_device_mac();
	header[DEVNAME] = protocol_data->get_protocol_header().get_device_name();
	header[DEVNAME] = protocol_data->get_protocol_header().get_mcd_id();
	header[DEVNAME] = protocol_data->get_protocol_header().get_company_id();
	header[RETURNCODE] = return_code;
	header[ERRMSG] = error_message;

	root[HEADER] = header;
	root[BODY] = protocol_data->get_response_body();
	msg =  root.toStyledString();

	return SUCCEED;
}

