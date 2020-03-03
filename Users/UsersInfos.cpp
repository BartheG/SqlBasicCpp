#include "UsersInfos.hpp"

UsersInfos::UsersInfos(
	const std::string &username,
	const std::string &passwordOne,
	const std::string &passwordTwo,
	const std::string &mail
) :
_username(username),
_passwordOne(passwordOne),
_passwordTwo(passwordTwo),
_mail(mail) {
	_signIn = (!_mail.empty() && !_passwordTwo.empty()) ? true : false;
}

UsersInfos::~UsersInfos() {}
