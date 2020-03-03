#ifndef VMANIPULATION_HPP_
	#define VMANIPULATION_HPP_

#include <string>
#include <utility>
#include <map>

class VManipulation {
	public:
		VManipulation();
		~VManipulation();
		std::string getSpecificField(std::map<std::string, std::string> res, const std::string &field);
	protected:
	private:
};

#endif /* !VMANIPULATION_HPP_ */
