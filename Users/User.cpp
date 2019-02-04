#include "User.hpp"

User::User()
{
	_logged = false;
	_ePass = std::make_shared<EncodePassword>();
}

User::~User() {}

bool User::checkLogIn(uInfosPtr &myUInfos) {
	if ((myUInfos->getUsername() == "") || (myUInfos->getPasswordOne() == "")) {
		ERREMPTYUSERPASS
	}
	return true;
}

bool User::logIn(uInfosPtr &myUInfos, sqlPtr &mySql) {
	if (!this->checkLogIn(myUInfos))
		return false;

	std::string whereCondition = "username='"
	+ myUInfos->getUsername()
	+ "' AND password='"
	+ std::to_string(
		this->_ePass->encode(
			myUInfos->getUsername(),
			myUInfos->getPasswordOne()
		)
	) + "'";
	std::map<std::string,std::string> param = {
		{"toSelect", "*"},
		{"where", whereCondition}
	};

	RequestBuilder rb(param, RequestType::SELECT, "users");
	rb.buildRequest();
	std::string request = rb.getFinalRequest();

	if (!mySql->SqlQuery(request)) {
		ERRQUERYSQL
	} if (!mySql->fetchResult()) {
		ERRFETCHRESULTS
	} if (mySql->getTabFetchResults().empty()) {
		ERREMPTYRESTAB
	}
	this->_logged = true;
	return true;
}

bool User::checkSignUp(uInfosPtr &myUInfos) {
	if (!myUInfos->isSignIn()) {
		ERRINFOSNOTOBJMODE
	}
	if ((myUInfos->getUsername() == "")
	|| (myUInfos->getPasswordOne() == "")
	|| (myUInfos->getPasswordTwo() == "")) {
		ERREMPTYUSERPASS
	}
	if (myUInfos->getPasswordOne() != myUInfos->getPasswordTwo()) {
		ERRNOTSAMEPASS
	}
	return true;
}

bool User::signUp(uInfosPtr &myUInfos, sqlPtr &mySql) {
	if (!this->checkSignUp(myUInfos))
		return false;

	std::map<std::string,std::string> param = {
		{"id", "NULL"},
		{"username", myUInfos->getUsername()},
		{"password", std::to_string(this->_ePass->encode(
			myUInfos->getUsername(),
			myUInfos->getPasswordOne()
		))},
		{"mail", myUInfos->getMail()}
	};

	RequestBuilder rb(param, RequestType::INSERT, "users");
	rb.buildRequest();

	std::string request = rb.getFinalRequest();

	if (!mySql->SqlQuery(request)) {
		ERRQUERYSQL
	}
	this->_logged = true;
	return true;
}