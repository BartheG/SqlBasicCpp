#ifndef USER_HPP_
	#define USER_HPP_

#include <string>

class User {
	public:
		User();
		~User();
		void userConnexion(std::string username,std::string mail,std::string password);
	private:
		std::string _username;
		std::string _mail;
};

#endif /* !USER_HPP_ */
