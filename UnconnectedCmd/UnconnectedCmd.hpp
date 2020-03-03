#ifndef UNCONNECTEDCMD_HPP_
	#define UNCONNECTEDCMD_HPP_

#include <string>
#include <map>

#include "ReadInput.hpp"
#include "User.hpp"

class UnconnectedCmd {
	public:
		UnconnectedCmd(std::shared_ptr<SqlWrap> &mySql);
		~UnconnectedCmd();
		bool makeCmd(const std::string &cmd);
		bool loginCmd();
		bool signUpCmd();
	private:
		std::shared_ptr<ReadInput> _Shell;
		std::shared_ptr<User> _User;
		std::shared_ptr<SqlWrap> _mySql;
		std::map<std::string, std::function<bool(void) > > _selectCmd;
};

#endif /* !UNCONNECTEDCMD_HPP_ */
