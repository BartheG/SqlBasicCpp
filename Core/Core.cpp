#include "Core.hpp"

Core::Core()
{
	_ActualState = State::UNCONNECTED;
	_MapState[State::CONNECTED] = std::bind(&Core::runConnected, this);
	_MapState[State::UNCONNECTED] = std::bind(&Core::runUnConnected, this);
	_User = std::make_shared<User>();
	_MapUser["login"] = std::bind(&User::logIn, &_User);
	_MapUser["signin"] = std::bind(&User::logIn, &_User);
}

Core::~Core() {}

void Core::runConnected() {
	std::cout << RUNCO_LOGINSIGNIN << std::endl;
	std::cout << RUNCO_EXIT << std::endl;

	std::cin >> this->_userInput;
	this->_MapUser[this->_userInput]();
	this->_ActualState = State::CONNECTED;
}

void Core::runUnConnected() {
	std::cout << "Run unconnected" << std::endl;
}

bool Core::shellExecution() {
	while (this->_ActualState != State::QUIT) {
		std::cout << "CoreLoop" << std::endl;
		this->_MapState[this->_ActualState]();
	}
	return true;
}