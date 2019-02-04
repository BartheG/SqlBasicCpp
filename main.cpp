#include <iostream>
//#include "Core.hpp"

#include "SqlWrap.hpp"
#include "DatabaseInfos.hpp"
#include "RequestBuilder.hpp"
#include "User.hpp"

int main() {
	std::shared_ptr<DatabaseInfos> dbInfos = std::make_shared<DatabaseInfos>("127.0.0.1","root","@8Felhdqb");
	std::shared_ptr<SqlWrap> s1 = std::make_shared<SqlWrap>(dbInfos);

	if (!s1->SqlConnexionToDatabase("interactiveshell")) {
		std::cout << "ERROR: MySql connexion" << std::endl;
	} else {
		std::cout << "Connected" << std::endl;
	}
	std::shared_ptr<UsersInfos> myui = std::make_shared<UsersInfos>(
		"Bonjour",
		"Sevran",
		"Sevran",
		"Mail@test.epi.test"
	);

	User u1;
	u1.signIn(myui, s1);
/* 	s1->SqlQuery("SELECT * FROM `users`;");
	if (!s1->fetchResult()) {
		std::cout << "error result" << std::endl;
		return 0;
	}

	std::vector<std::map<std::string,std::string>> res = s1->getTabFetchResults();
	displayMap(res); */

}
