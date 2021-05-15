#include "Data.h"
using namespace std;

Data::Data(string _login, string _password)
{
	login = _login;
	password = _password;
}

bool Data::loginIsValid(string input)
{
	if (input == login)
		return 1;
	else
		return 0;
}
bool Data::passwordIsValid(string input)
{
	if (input == password)
		return 1;
	else
		return 0;
}