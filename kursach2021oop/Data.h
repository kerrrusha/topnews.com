#pragma once
#include <string>

class Data
{
public:
	Data(std::string _login, std::string _password);

	bool loginIsValid(std::string input);
	bool passwordIsValid(std::string input);
private:
	std::string login;
	std::string password;
};