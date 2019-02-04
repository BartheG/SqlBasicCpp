#ifndef USER_HPP_
	#define USER_HPP_

#include "SqlWrap.hpp"
#include "UsersInfos.hpp"
#include "RequestBuilder.hpp"

typedef std::shared_ptr<SqlWrap> sqlPtr;
typedef std::shared_ptr<UsersInfos> uInfosPtr;

class User {
	public:
		User();
		~User();
		bool logIn(uInfosPtr &myUInfos, sqlPtr &mySql);
		bool signIn(uInfosPtr &myUInfos, sqlPtr &mySql);
		bool isLogged() const { return this->_logged; };
	private:
		bool checkLogIn(uInfosPtr &myUInfos);
		bool checkSignIn(uInfosPtr &myUInfos);

		bool _logged;
};

#endif /* !USER_HPP_ */