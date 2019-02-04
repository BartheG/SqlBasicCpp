#include "User.hpp"

User::User()
{
	_isLogged = false;
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
}
