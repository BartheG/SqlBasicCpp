#include "UnconnectedCmd.hpp"

UnconnectedCmd::UnconnectedCmd(std::shared_ptr<SqlWrap> &mySql)
{
	_User = std::make_shared<User>();
	_Shell = std::make_shared<ReadInput>();
	_mySql = mySql;
	_selectCmd["login"] = std::bind(&UnconnectedCmd::loginCmd, this);
	_selectCmd["signup"] = std::bind(&UnconnectedCmd::signUpCmd, this);
}

UnconnectedCmd::~UnconnectedCmd()
{
}

bool UnconnectedCmd::makeCmd(const std::string &cmd) {
	if (cmd == "exit")
		return false;
	if (this->_selectCmd.find(cmd) == this->_selectCmd.end())
		return false;
	return this->_selectCmd[cmd]();
}

bool UnconnectedCmd::loginCmd() {
	std::string login, password;

	std::cout << "Enter login: ";
	login = this->_Shell->wrapInputCmd();
	std::cout << "Enter password: ";
	password = this->_Shell->wrapInputCmd();

	std::shared_ptr<UsersInfos> uif = std::make_shared<UsersInfos>(
		login,
		password
	);

	return this->_User->logIn(uif, this->_mySql);
}

bool UnconnectedCmd::signUpCmd() {
	std::string login, passwordOne, passwordTwo, mail;

	std::cout << "Enter login: ";
	login = this->_Shell->wrapInputCmd();
	std::cout << "Enter password: ";
	passwordOne = this->_Shell->wrapInputCmd();
	std::cout << "Retype password: ";
	passwordTwo = this->_Shell->wrapInputCmd();
	std::cout << "Enter mail address: ";
	mail = this->_Shell->wrapInputCmd();

	std::shared_ptr<UsersInfos> uif = std::make_shared<UsersInfos>(
		login,
		passwordOne,
		passwordTwo,
		mail
	);

	return this->_User->signUp(uif, this->_mySql);
}