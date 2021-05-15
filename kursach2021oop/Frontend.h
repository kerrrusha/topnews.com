#pragma once
#include "Alerts.h"
#include "Backend.h"

class Session
{
private:
	class Menu
	{
	public:
		int start()
		{
			system("cls");
			Alerts::make(MessageType::URLMenu);						//link
			Alerts::make(MessageType::UnauthorizedUserMenu);		//start_menu

			int answer = getKeyPressed(0, 7);

			return answer;
		}
		int user_is_logged_in()
		{
			system("cls");
			Alerts::make(MessageType::URLMenu);					//link
			Alerts::make(MessageType::AuthorizedUserMenu);		//user_is_logged_in_menu

			int answer = getKeyPressed(0, 6);

			return answer;
		}
	};

	bool authorized = false;		//авторизован пользователь или нет
	std::string user = "";
public:
	Menu menu;
	Site site;

	Session();

	void MenuPage();
	void GamesPage();
	void FilmsPage();
	void MusicPage();
	void MakeNewPostPage();
	void SignIn();
	void SignUp();
	void SearchPage(std::string what);

	static int getKeyPressed(int from, int to);
	void loadData();
	const std::string currentDateTime();
};