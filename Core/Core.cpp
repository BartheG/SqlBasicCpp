#include "Core.hpp"

Core::Core(std::shared_ptr<SqlWrap> &WSql) : _WSql(WSql)
{
	_ActualState = State::UNCONNECTED;

	_MapState[State::CONNECTED] = std::bind(&Core::runConnected, this);
	_MapState[State::UNCONNECTED] = std::bind(&Core::runUnConnected, this);

	_Shell = std::make_shared<ReadInput>();
	_UCmd = std::make_shared<UnconnectedCmd>(_WSql);
}

Core::~Core() {}

void Core::runConnected() {
}

void Core::runUnConnected() {
	std::cout << RUNCO_LOGINSIGNIN << std::endl;
	std::cout << RUNCO_EXIT << std::endl;

	std::string shellRt = this->_Shell->wrapInputCmd();
	if (shellRt == "exit") {
		this->_ActualState = State::QUIT;
	} else {
		this->_ActualState = (this->_UCmd->makeCmd(shellRt)) ? State::CONNECTED : State::UNCONNECTED;
	}
}

bool Core::shellExecution() {
	while (this->_ActualState != State::QUIT) {
		std::cout << "CoreLoop" << std::endl;
		this->_MapState[this->_ActualState]();
	}
	return true;
}