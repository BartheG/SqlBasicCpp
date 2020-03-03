#ifndef USER_HPP_
	#define USER_HPP_

#include "SqlWrap.hpp"
#include "UsersInfos.hpp"
#include "RequestBuilder.hpp"
#include "EncodePassword.hpp"

#define ERRQUERYSQL std::cout << "Error: SqlQuery not working" << std::endl; return false;
#define ERRFETCHRESULTS std::cout << "Error: fetch results" << std::endl; return false;
#define ERREMPTYRESTAB std::cout << "Error: incorrect username/password" << std::endl; return false;
#define ERREMPTYUSERPASS std::cout << "Error: Empty Username/Pasword" << std::endl; return false;
#define ERRNOTSAMEPASS std::cout << "Error: Different passwords" << std::endl; return false;
#define ERRINFOSNOTOBJMODE std::cout << "Error: User OBJECT not in signIn mode" << std::endl; return false;

typedef std::shared_ptr<SqlWrap> sqlPtr;
typedef std::shared_ptr<UsersInfos> uInfosPtr;

class User {
	public:
		User();
		~User();
		bool logIn(uInfosPtr &myUInfos, sqlPtr &mySql);
		bool signUp(uInfosPtr &myUInfos, sqlPtr &mySql);
		bool isLogged() const { return this->_logged; };
	private:
		bool checkLogIn(uInfosPtr &myUInfos);
		bool checkSignUp(uInfosPtr &myUInfos);

		std::shared_ptr<EncodePassword> _ePass;
		bool _logged;
};

#endif /* !USER_HPP_ */