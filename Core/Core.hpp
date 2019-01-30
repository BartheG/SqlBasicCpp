#ifndef CORE_HPP_
	#define CORE_HPP_

#include <iostream>
#include <map>
#include <functional>

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
		std::map<State, std::function<void(void)>> _MapState;
};

#endif /* !CORE_HPP_ */
