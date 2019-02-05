#ifndef ReadInput_HPP_
	#define ReadInput_HPP_

#include <string>
#include <iostream>

class ReadInput {
	public:
		ReadInput();
		~ReadInput();
		void readInput();
		std::string wrapInputCmd();
	private:
		std::string _input;
};

#endif /* !ReadInput_HPP_ */
