#pragma once
#include "iContainer.h"
#include "Data.h"
#include "Date.h"
#include "Publication.h"
#include "Rubric.h"
#include <vector>

class Site
{
private:
	class Accounts : public iContainer <Data>
	{
	public:
		int howManyInside()
		{
			return data.size();
		}
		bool registerNew(std::string login, std::string password)		//вернет 0, если такой аккаунт уже зарегистрирован, 1 - если успешно
		{
			for (int i = 0; i < (int)data.size(); i++)
				if (data.at(i).loginIsValid(login))
					return 0;

			Data newAccount(login, password);
			data.push_back(newAccount);
			return 1;
		}

		bool loginExists(std::string login)
		{
			if (login == "")
				return 0;
			else
			{
				for (int i = 0; i < (int)data.size(); i++)
				{
					if (data.at(i).loginIsValid(login))
						return 1;
				}
				return 0;
			}
		}
		bool passwordCheck(std::string login, std::string password)
		{
			if (!loginExists(login) || login == "" || password == "")
				return 0;
			else
			{
				for (int i = 0; i < (int)data.size(); i++)
				{
					if (data.at(i).loginIsValid(login))
					{
						if (data.at(i).passwordIsValid(password))
							return 1;
						else
							return 0;
					}
				}
				return 0;
			}
		}
	};
	class Games : public Rubric
	{};
	class Films : public Rubric
	{};
	class Music : public Rubric
	{};
	Accounts accounts;
public:
	Games* games = new Games();
	Films* films = new Films();
	Music* music = new Music();

	int howManyRegistered();
	bool signUp(std::string login, std::string password);
	bool signIn(std::string login, std::string password);
	bool userExists(std::string login);
	bool publish(std::string _name, std::string _content, std::string _author, std::string _rubric, std::vector<std::string> _tags, Date _date);

	~Site();
};