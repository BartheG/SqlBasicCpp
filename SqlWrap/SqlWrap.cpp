#include "SqlWrap.hpp"

SqlWrap::SqlWrap(std::shared_ptr<DatabaseInfos> &dbInfos) {
	if (mysql_init(&_mysql) == NULL)
		std::cout << "ERROR: mysql_init()" << std::endl;
	_result = NULL;
	_row = NULL;
	_nbFields = 0;
	_dbInfos = dbInfos;
	_colLen = NULL;
}

SqlWrap::~SqlWrap() {
	mysql_close(&(this->_mysql));
}

bool SqlWrap::SqlConnexionToDatabase(const std::string &dbName) {
	std::string url = this->_dbInfos->getUrl();
	std::string username = this->_dbInfos->getUsername();
	std::string password = this->_dbInfos->getPassword();

	if (mysql_real_connect(
		&(this->_mysql),
		url.c_str(),
		username.c_str(),
		password.c_str(),
		dbName.c_str(),
		0,NULL,0)
	)
		return true;
	return false;
}

bool SqlWrap::SqlQuery(const std::string &myQuery) {
	if (mysql_query(
		&(this->_mysql),
		myQuery.c_str()
	) != 0)
		return false;
	if ((this->_result = mysql_use_result(&(this->_mysql))) == NULL)
		return false;
	return true;
}

void displayVector(std::vector<std::string> v) {
	for (std::vector<std::string>::iterator itB = v.begin(); itB != v.end(); itB++) {
		std::cout << *itB << std::endl;
	}
}

void displayMap(std::vector<std::map<std::string,std::string>> result) {
	std::vector<std::map<std::string,std::string>>::iterator itVector = result.begin();
	for (; itVector != result.end(); itVector++) {
		std::cout << "Only Password: " << (*itVector)["password"] << std::endl;
		for (std::map<std::string,std::string>::iterator itMap = itVector->begin(); itMap != itVector->end(); itMap++) {
			std::cout << "ColName: " << itMap->first << " Value: " << itMap->second << std::endl;
		}
		std::cout << std::endl;
	}
}

void SqlWrap::getColNameFromLastResult() {
	MYSQL_FIELD *field;

	while((field = mysql_fetch_field(this->_result)) != NULL) {
		this->_colNames.push_back(field->name);
	}
}


std::vector<std::map<std::string,std::string>> SqlWrap::fetchResult() {
	this->_nbFields = mysql_num_fields(this->_result);
	std::vector<std::map<std::string,std::string>> result;
	std::map<std::string, std::string> tpsData;

	this->getColNameFromLastResult();
	while (this->_row = mysql_fetch_row(this->_result)) {
		if ((this->_colLen = mysql_fetch_lengths(this->_result)) == NULL)
			return {};
		for(int i = 0; i < this->_nbFields; i++) {
			if ((int)this->_colLen[i] != 0) {
				if ((int)(this->_colNames.size()) < i)
					return {};
				tpsData[this->_colNames.at(i)] = std::string(this->_row[i]);
			}
		}
		result.push_back(tpsData);
		tpsData.clear();
	}
	return result;
}



void SqlWrap::clearResults() {
	mysql_free_result(this->_result);
	this->_colNames.clear();
	this->_colLen = NULL;
	this->_nbFields = 0;
}