#include "Core.hpp"

Core::Core()
{
	_ActualState = State::UNCONNECTED;
	_MapState[State::CONNECTED] = std::bind(&Core::runConnected, this);
	_MapState[State::UNCONNECTED] = std::bind(&Core::runUnConnected, this);
}

Core::~Core()
{
}

void Core::runConnected() {
	std::cout << "Run connected" << std::endl;
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