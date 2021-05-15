#include "Alerts.h"
#include <iostream>
using namespace std;


void Alerts::make(MessageType code) 
{
	if (static_cast<int>(code) < 0 || static_cast<int>(code) > 15)
	cout << "\nOops, there is no such text message.\n";
	else
	{
		switch (code)
		{
		case MessageType::ChooseNumber:
			cout << "Choose number.\n";
			break;
		case MessageType::UnauthorizedUserMenu:
			cout << "1. Main page\n";
			cout << "2. See news by rubric\n";
			cout << "3. See news by tags\n";
			cout << "4. See news by author\n";
			cout << "5. See news by date period\n";
			cout << "6. Sign in\n";
			cout << "7. Sign up\n";
			cout << "\n0. Quit\n";
			break;
		case MessageType::AuthorizedUserMenu:
			cout << "1. Main page\n";
			cout << "2. See news by rubric\n";
			cout << "3. See news by tags\n";
			cout << "4. See news by author\n";
			cout << "5. See news by date period\n";
			cout << "6. Post a new\n";
			cout << "\n0. Quit\n";
			break;
		case MessageType::GuestGreeting:
			cout << "Hello, Guest! To post news, you should be authorized.\t\t\t\t\t\t\t\t";
			break;
		case MessageType::PanelGames:
			cout << "========================================================================================================================================================\n";
			cout << "=         ------>   1. Games     <------              =                    2. Films                    =                     3. Music                  =\n";
			cout << "========================================================================================================================================================\n";
			break;
		case MessageType::PanelFilms:
			cout << "========================================================================================================================================================\n";
			cout << "=                   1. Games                          =        ------>     2. Films      <------       =                     3. Music                  =\n";
			cout << "========================================================================================================================================================\n";
			break;
		case MessageType::PanelMusic:
			cout << "========================================================================================================================================================\n";
			cout << "=                   1. Games                          =                    2. Films                    =         ------>     3. Music     <------      =\n";
			cout << "========================================================================================================================================================\n";
			break;
		case MessageType::URLMenu:
			cout << "======================================\n";
			cout << "=                                    =\n";
			cout << "=        topnews.com/menu            =\n";
			cout << "=                                    =\n";
			cout << "======================================\n\n";
			break;
		case MessageType::URLGames:
			cout << "======================================\n";
			cout << "=                                    =\n";
			cout << "=        topnews.com/games           =       0. Menu\n";
			cout << "=                                    =\n";
			cout << "======================================\n\n";
			break;
		case MessageType::URLFilms:
			cout << "======================================\n";
			cout << "=                                    =\n";
			cout << "=        topnews.com/films           =       0. Menu\n";
			cout << "=                                    =\n";
			cout << "======================================\n\n";
			break;
		case MessageType::URLMusic:
			cout << "======================================\n";
			cout << "=                                    =\n";
			cout << "=        topnews.com/music           =       0. Menu\n";
			cout << "=                                    =\n";
			cout << "======================================\n\n";
			break;
		case MessageType::Greeting:
			cout << "Welcome back!\t\t\t\t\t\t\t\t\t\t\t\t\t";
			break;
		case MessageType::URLMakeNewPost:
			cout << "======================================\n";
			cout << "=                                    =\n";
			cout << "=        topnews.com/makenew         =\n";
			cout << "=                                    =\n";
			cout << "======================================\n\n";
			break;
		case MessageType::URLMakeSignIn:
			cout << "======================================\n";
			cout << "=                                    =\n";
			cout << "=        topnews.com/signin          =\n";
			cout << "=                                    =\n";
			cout << "======================================\n\n";
			break;
		case MessageType::URLMakeSignUp:
			cout << "======================================\n";
			cout << "=                                    =\n";
			cout << "=        topnews.com/signup          =\n";
			cout << "=                                    =\n";
			cout << "======================================\n\n";
			break;
		case MessageType::URLMakeSearch:
			cout << "======================================\n";
			cout << "=                                    =\n";
			cout << "=        topnews.com/search          =\n";
			cout << "=                                    =\n";
			cout << "======================================\n\n";
			break;
		}
	}
}

void Alerts::make(MessageType code, string name)
{
	if (static_cast<int>(code) != 11)
		std::cout << "\nOops, there is no such text message.\n";
	else
	{
		switch (code)
		{
		case MessageType::Greeting:
			std::cout << name << ", welcome back!\t\t\t\t\t\t\t\t\t\t\t\t\t";
			break;
		}
	}
}