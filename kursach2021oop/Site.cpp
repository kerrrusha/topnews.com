#include "Backend.h"
using namespace std;

int Site::howManyRegistered()
{
	return accounts.howManyInside();
}
bool Site::signUp(string login, string password)
{
	return accounts.registerNew(login, password);
}
bool Site::signIn(string login, string password)
{
	if (accounts.loginExists(login) && accounts.passwordCheck(login, password))
		return 1;
	return 0;
}
bool Site::userExists(string login)
{
	if (accounts.loginExists(login))
		return 1;
	return 0;
}
bool Site::publish(string _name, string _content, string _author, string _rubric, vector<string> _tags, Date _date)
{
	if (_rubric == "Games")
	{
		games->makePublication(_name, _content, _author, _tags, _date);
		return 1;
	}
	if (_rubric == "Films")
	{
		films->makePublication(_name, _content, _author, _tags, _date);
		return 1;
	}
	if (_rubric == "Music")
	{
		music->makePublication(_name, _content, _author, _tags, _date);
		return 1;
	}

	return 0;
}

Site::~Site()
{
	delete games, films, music;
}