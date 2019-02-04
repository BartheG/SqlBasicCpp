#include "User.hpp"

User::User()
{
	_logged = false;
}

User::~User() {}

bool User::checkLogIn(uInfosPtr &myUInfos) {
	if ((myUInfos->getUsername() == "") || (myUInfos->getPasswordOne() == "")) {
		std::cout << "Error: Empty Username/Pasword" << std::endl;
		return false;
	}
	return true;
}

bool User::logIn(uInfosPtr &myUInfos, sqlPtr &mySql) {
	if (!this->checkLogIn(myUInfos))
		return false;

	std::string whereCondition = "username='"
	+ myUInfos->getUsername()
	+ "' AND password='"
	+ myUInfos->getPasswordOne()
	+ "'";
	std::map<std::string,std::string> param = {
		{"toSelect", "*"},
		{"where", whereCondition}
	};

	RequestBuilder rb(param, RequestType::SELECT, "users");
	rb.buildRequest();
	std::string request = rb.getFinalRequest();

	if (!mySql->SqlQuery(request)) {
		std::cout << "Error: SqlQuery not working" << std::endl;
		return false;
	}
	if (!mySql->fetchResult()) {
		std::cout << "Error: fetch results" << std::endl;
		return false;
	}
	if (mySql->getTabFetchResults().empty()) {
		std::cout << "Error: incorrect username/password" << std::endl;
		return false;
	}
	this->_logged = true;
	return true;
}

bool User::checkSignIn(uInfosPtr &myUInfos) {
	if (!myUInfos->isSignIn()) {
		std::cout << "Error: User OBJECT not in signIn mode" << std::endl;
		return false;
	}
	if ((myUInfos->getUsername() == "")
	|| (myUInfos->getPasswordOne() == "")
	|| (myUInfos->getPasswordTwo() == "")) {
		std::cout << "Error: Empty Username/Pasword" << std::endl;
		return false;
	}
	if (myUInfos->getPasswordOne() != myUInfos->getPasswordTwo()) {
		std::cout << "Error: Different passwords" << std::endl;
		return false;
	}
	return true;
}

bool User::signIn(uInfosPtr &myUInfos, sqlPtr &mySql) {
	if (!this->checkSignIn(myUInfos))
		return false;

	std::map<std::string,std::string> param = {
		{"id", "NULL"},
		{"username", myUInfos->getUsername()},
		{"password", myUInfos->getPasswordOne()},
		{"mail", myUInfos->getMail()}
	};

	RequestBuilder rb(param, RequestType::INSERT, "users");
	rb.buildRequest();

	std::string request = rb.getFinalRequest();

	if (!mySql->SqlQuery(request)) {
		std::cout << "Error: SqlQuery not working" << std::endl;
		return false;
	}
	this->_logged = true;
	return true;
}