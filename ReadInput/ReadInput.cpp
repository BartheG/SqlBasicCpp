#include "ReadInput.hpp"

ReadInput::ReadInput()
{
	_input = "";
}

ReadInput::~ReadInput() {}

void ReadInput::readInput() {
	std::cin >> this->_input;
}

std::string ReadInput::wrapInputCmd() {
	this->readInput();
	return this->_input;
}