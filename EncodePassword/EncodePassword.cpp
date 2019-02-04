#include "EncodePassword.hpp"

EncodePassword::EncodePassword() {}

EncodePassword::~EncodePassword() {}

std::size_t EncodePassword::encode(
	const std::string &username,
	const std::string &pass) {
		std::hash<std::string> toHash;
		std::size_t hashUsername = toHash(username);
		std::size_t hashPassword = toHash(pass);
		std::size_t hash = hashPassword & hashUsername >> 8;
		return hash;
}
