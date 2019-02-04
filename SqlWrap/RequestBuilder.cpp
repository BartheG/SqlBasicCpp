#include "RequestBuilder.hpp"

RequestBuilder::RequestBuilder(
	const std::map<std::string,std::string> &param,
	RequestType type,
	const std::string &tableName) :
	_param(param),
	_type(type),
	_tableName(tableName) {
	_selectRequest[RequestType::INSERT] = std::bind(&RequestBuilder::buildInsertRequest, this);
}

RequestBuilder::~RequestBuilder() {}

void RequestBuilder::buildRequest() {
	this->_selectRequest[this->_type]();
}

std::string RequestBuilder::formatWithQuote(const std::string &toFormat) {
	return std::string("`"+toFormat+"`");
}

std::string RequestBuilder::formatAsChar(const std::string &toFormat) {
	return (toFormat == "NULL") ? toFormat : std::string("'"+toFormat+"'");
}


void RequestBuilder::buildInsertRequest() {
	std::map<std::string, std::string>::iterator itParam = this->_param.begin();

	std::string fPartOfRequest = "INSERT INTO `";
	fPartOfRequest+=this->_tableName;
	fPartOfRequest+="` (";

	std::string sPartOfRequest = " VALUES (";

	for (; itParam != this->_param.end(); itParam++) {
		fPartOfRequest+=this->formatWithQuote(itParam->first);
		fPartOfRequest+=", ";

		sPartOfRequest+=this->formatAsChar(itParam->second);
		sPartOfRequest+=", ";
	}
	fPartOfRequest = fPartOfRequest.substr(0, (fPartOfRequest.size() - 2));
	sPartOfRequest = sPartOfRequest.substr(0, (sPartOfRequest.size() - 2));
	this->_finalRequest = fPartOfRequest+")"+sPartOfRequest+");";
}