#include <iostream>
//#include "Core.hpp"

#include "SqlWrap.hpp"
#include "DatabaseInfos.hpp"
#include "RequestBuilder.hpp"

int main() {
	std::shared_ptr<DatabaseInfos> dbInfos = std::make_shared<DatabaseInfos>("127.0.0.1","root","@8Felhdqb");
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
	std::map<std::string,std::string> param;
	param["id"] = "NULL";
	param["username"] = "test";
	param["password"] = "p2";
	param["mail"] = "monmailouais";
	RequestBuilder r1(param, RequestType::INSERT, "users");
	r1.buildRequest();
	std::cout << r1.getFinalRequest() << std::endl;
}
//INSERT INTO `users` (`id`, `username`, `password`, `mail`) VALUES (NULL, 'sioj', 'dofivjdovji', 'maitets@djhf.fr');
