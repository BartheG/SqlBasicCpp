#ifndef USER_HPP_
	#define USER_HPP_

#include "SqlWrap.hpp"
#include "UsersInfos.hpp"

typedef std::shared_ptr<SqlWrap> sqlPtr;
typedef std::shared_ptr<UsersInfos> uInfosPtr;

class User {
	public:
		User();
		~User();
		bool checkLogIn(uInfosPtr &myUInfos);
		bool logIn(uInfosPtr &myUInfos, sqlPtr &mySql);
		bool checkSignIn(uInfosPtr &myUInfos);
		bool signIn(uInfosPtr &myUInfos, sqlPtr &mySql);
	private:
		bool _isLogged;
};

#endif /* !USER_HPP_ */