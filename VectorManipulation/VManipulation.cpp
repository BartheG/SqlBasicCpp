#include "VManipulation.hpp"

VManipulation::VManipulation()
{
}

VManipulation::~VManipulation()
{
}

std::string VManipulation::getSpecificField(std::map<std::string, std::string> res, const std::string &field) {
	return res[field];
}