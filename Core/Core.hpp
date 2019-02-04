#ifndef CORE_HPP_
	#define CORE_HPP_

#include <iostream>
#include <map>
#include <functional>
#include <iostream>
#include <string>

#include "User.hpp"

#define RUNCO_LOGINSIGNIN "Enter \"login\" or \"signin\" to enter in the interactive shell"
#define RUNCO_EXIT "Enter exit to quit the program"

enum State {
	CONNECTED,
	UNCONNECTED,
	QUIT
};

class Core {
	public:
		Core();
		~Core();
		bool shellExecution();
		void runConnected();
		void runUnConnected();
	private:
		State _ActualState;
		std::string _userInput;
		std::shared_ptr<User> _User;
		std::map<State, std::function<void(void)>> _MapState;
		std::map<std::string, std::function<void(void)>> _MapUser;
};

#endif /* !CORE_HPP_ */
