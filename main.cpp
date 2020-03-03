#include <iostream>

#include "Core.hpp"
#include "SqlWrap.hpp"

int main(int ac, char **av) {
	std::shared_ptr<DatabaseInfos> dbInfos = std::make_shared<DatabaseInfos>("127.0.0.1","username","password");
	std::shared_ptr<SqlWrap> s1 = std::make_shared<SqlWrap>(dbInfos);

	if (!s1->SqlConnexionToDatabase("interactiveshell")) {
		std::cout << "ERROR: MySql connexion" << std::endl;
		return 1;
	}
	std::cout << "Connected" << std::endl;
	std::shared_ptr<Core> mCore = std::make_shared<Core>(s1);
	mCore->shellExecution();
}