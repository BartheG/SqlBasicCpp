/*
** EPITECH PROJECT, 2019
** interactiveshell
** File description:
** DatabaseInfos
*/

#include "DatabaseInfos.hpp"

DatabaseInfos::DatabaseInfos(
	const std::string &url,
	const std::string &username,
	const std::string &password) :
	_url(url),
	_username(username),
	_password(password) {}

DatabaseInfos::~DatabaseInfos() {}