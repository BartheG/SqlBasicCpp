#ifndef CORE_HPP_
	#define CORE_HPP_

#include <iostream>
#include <map>
#include <functional>
#include <iostream>
#include <string>

#include "User.hpp"
#include "ReadInput.hpp"
#include "UnconnectedCmd.hpp"
#include "SqlWrap.hpp"

#define RUNCO_LOGINSIGNIN "Enter \"login\" or \"signin\" to enter in the interactive shell"
#define RUNCO_EXIT "Enter exit to quit the program"

enum State {
	CONNECTED,
	UNCONNECTED,
	QUIT
};

class Core {
	public:
		Core(std::shared_ptr<SqlWrap> &WSql);
		~Core();
		bool shellExecution();
		void runConnected();
		void runUnConnected();
	private:
		State _ActualState;
		std::string _userInput;
		std::map<State, std::function<void(void)> > _MapState;

		std::shared_ptr<SqlWrap> _WSql;
		std::shared_ptr<UnconnectedCmd> _UCmd;
		std::shared_ptr<ReadInput> _Shell;
};

#endif /* !CORE_HPP_ */
