#ifndef DATABASEINFOS_HPP_
	#define DATABASEINFOS_HPP_

#include <string>

class DatabaseInfos {
	public:
		DatabaseInfos(
			const std::string &url,
			const std::string &username,
			const std::string &password);
		~DatabaseInfos();
		void setUrl(const std::string &url) { this->_url = url; };
		void setUsername(const std::string &username) { this->_username = username; };
		void setPassword(const std::string &password) { this->_password = password; };
		std::string getUrl() const {return this->_url;};
		std::string getUsername() const {return this->_username;};
		std::string getPassword() const {return this->_password;};
	private:
		std::string _url;
		std::string _username;
		std::string _password;
};

#endif /* !DATABASEINFOS_HPP_ */
