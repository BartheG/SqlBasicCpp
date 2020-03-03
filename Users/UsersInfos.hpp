#ifndef USERSINFOS_HPP_
	#define USERSINFOS_HPP_

#include <string>

class UsersInfos {
	public:
		UsersInfos(
			const std::string &username,
			const std::string &passwordOne,
			const std::string &passwordTwo = "",
			const std::string &mail = ""
		);
		~UsersInfos();
		std::string getUsername() const { return this->_username; }
		std::string getPasswordOne() const { return this->_passwordOne; }
		std::string getPasswordTwo() const { return this->_passwordTwo; }
		std::string getMail() const { return this->_mail; }
		bool isSignIn() const { return this->_signIn; }
	private:
		bool _signIn;
		std::string _username;
		std::string _passwordOne;
		std::string _passwordTwo;
		std::string _mail;
};

#endif /* !USERSINFOS_HPP_ */
