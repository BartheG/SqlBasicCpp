#include <iostream>
#include "Core.hpp"

#include "SqlWrap.hpp"
#include "DatabaseInfos.hpp"

int main() {
	std::shared_ptr<DatabaseInfos> dbInfos = std::make_shared<DatabaseInfos>("127.0.0.1","root","root");
	SqlWrap s1(dbInfos);

	if (!s1.SqlConnexionToDatabase("interactiveshell")) {
		std::cout << "ERROR: MySql connexion" << std::endl;
	} else {
		std::cout << "Connected" << std::endl;
	}
	if (!s1.SqlQuery("SELECT * FROM `users`"))
		std::cout << "ERROR: MySql Query" << std::endl;
	else
		std::cout << "Query works" << std::endl;
	std::vector<std::map<std::string,std::string>> res = s1.fetchResult();
	displayMap(res);
}