#include <iostream>
//#include "Core.hpp"

#include "SqlWrap.hpp"
#include "DatabaseInfos.hpp"
#include "RequestBuilder.hpp"
#include "User.hpp"
#include "EncodePassword.hpp"

int main(int ac, char **av) {
	std::shared_ptr<DatabaseInfos> dbInfos = std::make_shared<DatabaseInfos>("127.0.0.1","root","@8Felhdqb");
	std::shared_ptr<SqlWrap> s1 = std::make_shared<SqlWrap>(dbInfos);

	if (!s1->SqlConnexionToDatabase("interactiveshell")) {
		std::cout << "ERROR: MySql connexion" << std::endl;
	} else {
		std::cout << "Connected" << std::endl;
	}

	std::shared_ptr<UsersInfos> myui = std::make_shared<UsersInfos>(
		av[1],
		av[2],
		av[2],
		"mail@test.fr"
	);

	User u1;
	u1.signUp(myui, s1);
	u1.logIn(myui, s1);
	std::cout << u1.isLogged() << std::endl;
}