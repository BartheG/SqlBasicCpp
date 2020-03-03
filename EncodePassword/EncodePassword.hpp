#ifndef ENCODEPASSWORD_HPP_
	#define ENCODEPASSWORD_HPP_

#include <string>
#include <iostream>

class EncodePassword {
	public:
		EncodePassword();
		~EncodePassword();
		std::size_t encode(const std::string &username, const std::string &pass);
};

#endif /* !ENCODEPASSWORD_HPP_ */
