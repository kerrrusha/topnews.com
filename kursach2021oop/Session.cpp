#include "Frontend.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <time.h>
using namespace std;

Session::Session()						//начальная страница - рубрика игр
{
	loadData();
	GamesPage();
}

void Session::MenuPage()
{
	if (authorized)
	{
		int answer = menu.user_is_logged_in();

		switch (answer)
		{
		case 0:
			exit(0);
			break;
		case 1:
			GamesPage();
			break;
		case 2:
			SearchPage("rubric");
			break;
		case 3:
			SearchPage("tags");
			break;
		case 4:
			SearchPage("author");
			break;
		case 5:
			SearchPage("period");
			break;
		case 6:
			MakeNewPostPage();
			break;
		}
	}
	else
	{
		int answer = menu.start();

		switch (answer)
		{
		case 0:
			exit(0);
			break;
		case 1:
			GamesPage();
			break;
		case 2:
			SearchPage("rubric");
			break;
		case 3:
			SearchPage("tags");
			break;
		case 4:
			SearchPage("author");
			break;
		case 5:
			SearchPage("period");
			break;
		case 6:
			SignIn();
			break;
		case 7:
			SignUp();
			break;
		}
	}
}
void Session::GamesPage()
{
	system("cls");
	Alerts::make(MessageType::URLGames);			//link
	if (authorized)
		Alerts::make(MessageType::Greeting, user);		//приветствие авторизованного пользователя
	else
		Alerts::make(MessageType::GuestGreeting);		//приветствие гостя
	cout << "Loaded at:\t" << currentDateTime() << "\n\n";
	Alerts::make(MessageType::PanelGames);			//панель рубрик
	cout << "\n";
	int maxPostsOnPage = 3;			//максимальное количество одновременно отображаемых постов
	int postsToPrint = site.games->howManyInside() > maxPostsOnPage ? maxPostsOnPage : site.games->howManyInside();
	for (int id = 0; id < postsToPrint; id++)
	{
		cout << "\t" << site.games->getNameAt(id) << "   (author - " << site.games->getAuthorAt(id) << ")\n";
		cout << site.games->getContentAt(id) << "\n";
		cout << "Published:\t" << site.games->getDateAt(id) << "\n";
		for (int i = 0; i < (int)site.games->getTagsAt(id).size(); i++)
			cout << "#" << site.games->getTagsAt(id).at(i) << "  ";
		cout << "\n\n\n\n";
	}
	cout << ">> ";
	int answer = getKeyPressed(0, 3);

	switch (answer)
	{
	case 0:
		MenuPage();
		break;
	case 1:
		GamesPage();
		break;
	case 2:
		FilmsPage();
		break;
	case 3:
		MusicPage();
		break;
	}
}
void Session::FilmsPage()		//отобразить раздел новостей о фильмах
{
	system("cls");
	Alerts::make(MessageType::URLFilms);			//link
	if (authorized)
		Alerts::make(MessageType::Greeting, user);		//приветствие авторизованного пользователя
	else
		Alerts::make(MessageType::GuestGreeting);		//приветствие гостя
	cout << "Loaded at:\t" << currentDateTime() << "\n\n";
	Alerts::make(MessageType::PanelFilms);			//панель рубрик
	cout << "\n";
	int maxPostsOnPage = 3;			//максимальное количество одновременно отображаемых постов
	int postsToPrint = site.films->howManyInside() > maxPostsOnPage ? maxPostsOnPage : site.films->howManyInside();
	for (int id = 0; id < postsToPrint; id++)
	{
		cout << "\t" << site.films->getNameAt(id) << "   (author - " << site.films->getAuthorAt(id) << ")\n";
		cout << site.films->getContentAt(id) << "\n";
		cout << "Published:\t" << site.films->getDateAt(id) << "\n";
		for (int i = 0; i < (int)site.films->getTagsAt(id).size(); i++)
			cout << "#" << site.films->getTagsAt(id).at(i) << "  ";
		cout << "\n\n\n\n";
	}
	cout << ">> ";
	int answer = getKeyPressed(0, 3);

	switch (answer)
	{
	case 0:
		MenuPage();
		break;
	case 1:
		GamesPage();
		break;
	case 2:
		FilmsPage();
		break;
	case 3:
		MusicPage();
		break;
	}
}
void Session::MusicPage()		//отобразить раздел новостей о музыке
{
	system("cls");
	Alerts::make(MessageType::URLMusic);			//link
	if (authorized)
		Alerts::make(MessageType::Greeting, user);		//приветствие авторизованного пользователя
	else
		Alerts::make(MessageType::GuestGreeting);		//приветствие гостя
	cout << "Loaded at:\t" << currentDateTime() << "\n\n";
	Alerts::make(MessageType::PanelMusic);			//панель рубрик
	cout << "\n";
	int maxPostsOnPage = 3;			//максимальное количество одновременно отображаемых постов
	int postsToPrint = site.music->howManyInside() > maxPostsOnPage ? maxPostsOnPage : site.music->howManyInside();
	for (int id = 0; id < postsToPrint; id++)
	{
		cout << "\t" << site.music->getNameAt(id) << "   (author - " << site.music->getAuthorAt(id) << ")\n";
		cout << site.music->getContentAt(id) << "\n";
		cout << "Published:\t" << site.music->getDateAt(id) << "\n";
		for (int i = 0; i < (int)site.music->getTagsAt(id).size(); i++)
			cout << "#" << site.music->getTagsAt(id).at(i) << "  ";
		cout << "\n\n\n\n";
	}
	cout << ">> ";
	int answer = getKeyPressed(0, 3);

	switch (answer)
	{
	case 0:
		MenuPage();
		break;
	case 1:
		GamesPage();
		break;
	case 2:
		FilmsPage();
		break;
	case 3:
		MusicPage();
		break;
	}
}
void Session::MakeNewPostPage()
{
	system("cls");
	Alerts::make(MessageType::URLMakeNewPost);						//link

	string name = "unknown", content = "unknown", author = "unknown", rubric = "Games";
	vector<string> tags;
	int day = 1, month = 1, year = 0;
	string d = currentDateTime();
	string day_(""), month_(""), year_("");
	day_ += d.substr(0, 2);
	month_ += d.substr(3, 2);
	year_ += d.substr(6, 4);
	day = stoi(day_);
	month = stoi(month_);
	year = stoi(year_);
	Date date(day, month, year);

	author = user;
	cout << "Name of your publication:\t";

	cin.clear();
	cin.ignore(8196, '\n');

	getline(cin, name);

	cout << "\n\nEnter content:\n\t";
	getline(cin, content);

	cout << "\n\nChoose a rubric:\t1. Games\t2. Films\t3.Music\n>> ";
	int answer = getKeyPressed(1, 3);

	switch (answer)
	{
	case 1:
		rubric = "Games";
		break;
	case 2:
		rubric = "Films";
		break;
	case 3:
		rubric = "Music";
		break;
	}

	cout << "\n\nEnter list of tags, separated by ', ':\n\t";
	string temp(""), one_tag("");
	getline(cin, temp);
	for (size_t i = 0; i < temp.size(); i++)
	{
		if (temp[i] == ',')
		{
			tags.push_back(one_tag);
			one_tag = "";
			continue;
		}
		if (temp[i] == ' ')
			continue;
		if (i == temp.size() - 1)
		{
			one_tag += temp[i];
			tags.push_back(one_tag);
		}
		one_tag += temp[i];
	}

	site.publish(name, content, author, rubric, tags, date);
	GamesPage();
}
void Session::SignIn()
{
	system("cls");
	Alerts::make(MessageType::URLMakeSignIn);						//link

	string login(""), password("");

	cout << "Login (or enter 0 to quit):\t";
	cin >> login;

	if(login == "0")
		GamesPage();

	cout << "Password:\t\t\t";
	cin >> password;

	if (site.signIn(login, password))
	{
		authorized = 1;
		user = login;
		GamesPage();
	}
	else
		SignIn();
}
void Session::SignUp()
{
	system("cls");
	Alerts::make(MessageType::URLMakeSignUp);						//link

	string login(""), password(""), password1("");

	cout << "Login:\t\t";
	cin >> login;

	cout << "Password:\t";
	cin >> password;

	cout << "Repeat passwd:\t";
	cin >> password1;

	if (password != password1)
		SignUp();

	if (site.signUp(login, password))
	{
		authorized = 1;
		user = login;
		GamesPage();
	}
	else
		SignUp();
}
void Session::SearchPage(string what)
{
	system("cls");
	Alerts::make(MessageType::URLMakeSearch);						//link

	if (what == "rubric")
	{
		cout << "Select a rubric to see news for:\t1. Games\t2. Films\t3.Music\n>> ";
		int answer = getKeyPressed(1, 3);
		cout << "\n\n========================================================================================================================================================\n\n";
		Rubric* rubrics[] = { site.games, site.films, site.music };
		--answer;
		int maxPostsOnPage = 3;			//максимальное количество одновременно отображаемых постов
			
		int postsToPrint = rubrics[answer]->howManyInside() > maxPostsOnPage ? maxPostsOnPage : rubrics[answer]->howManyInside();
		for (int id = 0; id < postsToPrint; id++)
		{
			cout << "\t" << rubrics[answer]->getNameAt(id) << "   (author - " << rubrics[answer]->getAuthorAt(id) << ")\n";
			cout << rubrics[answer]->getContentAt(id) << "\n";
			cout << "Published:\t" << rubrics[answer]->getDateAt(id) << "\n";
			for (int i = 0; i < (int)rubrics[answer]->getTagsAt(id).size(); i++)
				cout << "#" << rubrics[answer]->getTagsAt(id).at(i) << "  ";
			cout << "\n\n\n\n";
		}
		cout << "\n\nPress 0 to quit:\n";
		cout << ">> ";
		answer = getKeyPressed(0, 0);
		GamesPage();
	}
	if (what == "tags")
	{
		cin.clear();

		string key("");
		cout << "Enter a tag to search news for:\t";
		cin >> key;
		cout << "\n\n========================================================================================================================================================\n\n";
		Rubric* rubrics[] = { site.games, site.films, site.music };				//динамический полиморфизм
		for (int z = 0; z < 3; z++)
		{
			for (int i = 0; i < rubrics[z]->howManyInside(); i++)
			{
				bool match(0);
				for (size_t j = 0; j < rubrics[z]->getTagsAt(i).size(); j++)
				{
					if (rubrics[z]->getTagsAt(i).at(j) == key)
					{
						match = 1;
						break;
					}
				}
				if (match)
				{
					cout << "\t" << rubrics[z]->getNameAt(i) << "   (author - " << rubrics[z]->getAuthorAt(i) << ")\n";
					cout << rubrics[z]->getContentAt(i) << "\n";
					cout << "Published:\t" << rubrics[z]->getDateAt(i) << "\n";
					for (int x = 0; x < (int)rubrics[z]->getTagsAt(i).size(); x++)
						cout << "#" << rubrics[z]->getTagsAt(i).at(x) << "  ";
					cout << "\n\n\n\n";
				}
			}
		}
		cout << "\n\nPress 0 to quit:\n";
		cout << ">> ";
		int answer = getKeyPressed(0, 0);
		GamesPage();
	}
	if (what == "author")
	{
		cin.clear();

		string key("");
		cout << "Author to see news for:\t";
		cin >> key;
		cout << "\n\n========================================================================================================================================================\n\n";
		Rubric* rubrics[] = { site.games, site.films, site.music };				//динамический полиморфизм
		for (int z = 0; z < 3; z++)
			for (int i = 0; i < rubrics[z]->howManyInside(); i++)
			{
				if (rubrics[z]->getAuthorAt(i) == key)
				{
					cout << "\t" << rubrics[z]->getNameAt(i) << "   (author - " << rubrics[z]->getAuthorAt(i) << ")\n";
					cout << rubrics[z]->getContentAt(i) << "\n";
					cout << "Published:\t" << rubrics[z]->getDateAt(i) << "\n";
					for (int x = 0; x < (int)rubrics[z]->getTagsAt(i).size(); x++)
						cout << "#" << rubrics[z]->getTagsAt(i).at(x) << "  ";
					cout << "\n\n\n\n";
				}
			}

		cout << "\n\nPress 0 to quit:\n";
		cout << ">> ";
		int answer = getKeyPressed(0, 0);
		GamesPage();
	}
	if (what == "period")
	{
		cin.clear();

		int dayF(1), monthF(1), yearF(0);
		int dayTo(1), monthTo(1), yearTo(0);

		cout << "Searching for period:\n\n";

		try
		{
			cout << "Day from:\t";
			cin >> dayF;
			if (dayF > 31 || dayF < 1)
				throw exception("Bad day format.");
		}
		catch (exception e)
		{
			SearchPage("period");
		}
		

		try
		{
			cout << "Month from:\t";
			cin >> monthF;
			if (monthF > 12 || monthF < 1)
				throw exception("Bad month format.");
		}
		catch (exception e)
		{
			SearchPage("period");
		}

		try
		{
			cout << "Year from:\t";
			cin >> yearF;
			if (yearF > 2222 || yearF < 1)
				throw exception("Bad year format.");
		}
		catch (exception e)
		{
			SearchPage("period");
		}

		try
		{
			cout << "Day from:\t";
			cin >> dayTo;
			if (dayTo > 31 || dayTo < 1)
				throw exception("Bad day format.");
		}
		catch (exception e)
		{
			SearchPage("period");
		}


		try
		{
			cout << "Month from:\t";
			cin >> monthTo;
			if (monthTo > 12 || monthTo < 1)
				throw exception("Bad month format.");
		}
		catch (exception e)
		{
			SearchPage("period");
		}

		try
		{
			cout << "Year from:\t";
			cin >> yearTo;
			if (yearTo > 2222 || yearTo < 1)
				throw exception("Bad year format.");
		}
		catch (exception e)
		{
			SearchPage("period");
		}

		cout << "\n\n========================================================================================================================================================\n\n";
		Date from, to;
		try
		{
			from(dayF, monthF, yearF);
			to(dayTo, monthTo, yearTo);
			if (from > to)
				throw exception("Date TO cannot be less than FROM");
		}
		catch(exception e)
		{
			SearchPage("period");
		}
		

		Rubric* rubrics[] = { site.games, site.films, site.music };				//динамический полиморфизм
		for (int z = 0; z < 3; z++)
			for (int i = 0; i < rubrics[z]->howManyInside(); i++)
			{
				if (rubrics[z]->getDateObjAt(i) >= from && rubrics[z]->getDateObjAt(i) <= to)
				{
					cout << "\t" << rubrics[z]->getNameAt(i) << "   (author - " << rubrics[z]->getAuthorAt(i) << ")\n";
					cout << rubrics[z]->getContentAt(i) << "\n";
					cout << "Published:\t" << rubrics[z]->getDateAt(i) << "\n";
					for (int x = 0; x < (int)rubrics[z]->getTagsAt(i).size(); x++)
						cout << "#" << rubrics[z]->getTagsAt(i).at(x) << "  ";
					cout << "\n\n\n\n";
				}
			}

		cout << "\n\nPress 0 to quit:\n";
		cout << ">> ";
		int answer = getKeyPressed(0, 0);
		GamesPage();
	}

	GamesPage();
}

int Session::getKeyPressed(int from, int to)
{
	int result = -1;

	while (result < from || result > to)
	{
		char keyIsPressed;
		keyIsPressed = _getch();

		if (keyIsPressed == '1')
			result = 1;
		if (keyIsPressed == '2')
			result = 2;
		if (keyIsPressed == '3')
			result = 3;
		if (keyIsPressed == '4')
			result = 4;
		if (keyIsPressed == '5')
			result = 5;
		if (keyIsPressed == '6')
			result = 6;
		if (keyIsPressed == '7')
			result = 7;
		if (keyIsPressed == '8')
			result = 8;
		if (keyIsPressed == '9')
			result = 9;
		if (keyIsPressed == '0')
			result = 0;
	}

	return result;
}
void Session::loadData()					//подгрузить содержимое сайта из файлов
{
	ifstream file("C:\\Users\\Fossa\\source\\repos\\kursach2021oop\\kursach2021oop\\resources\\publications\\content.txt");
	bool workingZone = false;			//находится ли каретка в нужной зоне для считывания

	string name;
	string author;
	string content;
	string rubric;
	string tags_row;
	vector <string> tags;
	int day = 0, month = 0, year = 0;

	if (file.is_open())
	{
		cout << "File opened.\n\n";

		while (!file.eof())
		{
			string s;
			getline(file, s);

			if (s == "")
				continue;
			else if (s == "/*")
				workingZone = true;
			else if (s == "*/")
				break;
			else if (s == "*")		//новый пост
			{
				name = "";
				author = "";
				content = "";
				rubric = "";
				tags.clear();
				day = 0;
				month = 0;
				year = 0;
			}
			else if (workingZone)				//считывание одной новости
			{
				name = s;

				getline(file, s);
				author = s;

				getline(file, s);
				content = s;
				//тут может быть случай если в тексте присутствуют абзацы - смотрим на пустые строки
				//ОБЯЗАТЕЛЬНО после контента в файле должно находиться название одной из 3 рубрик
				getline(file, s);
				while (true)
				{
					if (s == "Games" || s == "Films" || s == "Music")
						break;
					else if (s == "")
						content += "\n\n";
					else
						content += s;
					getline(file, s);
				}

				rubric = s;

				getline(file, s);
				tags_row = s;

				file >> day >> month >> year;
				Date date(day, month, year);

				string tag_buffer = "";		//сюда побуквенно выделяем каждый тег из строки
				for (int i = 0; i < (int)tags_row.size(); i++)
				{
					if (tags_row.substr(i, 1) != " ")
						tag_buffer += tags_row.substr(i, 1);
					else
					{
						tags.push_back(tag_buffer);
						tag_buffer = "";
					}
				}

				//тест = смотрим что насобирали
				cout << "That's what i've catched:\n\n";
				cout << name << endl;
				cout << author << endl;
				cout << content << endl;
				cout << rubric << endl;
				for (int i = 0; i < (int)tags.size(); i++)
					cout << "#" << tags.at(i) << "  ";
				cout << endl;
				cout << day << endl;
				cout << month << endl;
				cout << year << endl << endl;

				if (!site.publish(name, content, author, rubric, tags, date))
					cout << "Something get wrong :(\n\n";
				else
					cout << "Published.\n\n";
			}
		}
		file.close();
	}
	else
		cout << "Error: cant find content file.\n\n" << endl;

	file.open("C:\\Users\\Fossa\\source\\repos\\kursach2021oop\\kursach2021oop\\resources\\accounts\\login_data.txt");
	while (!file.eof())
	{
		string login(""), password("");

		getline(file, login);
		getline(file, password);
		site.signUp(login, password);

		getline(file, login);
	}
	file.close();
}
const string Session::currentDateTime()
{
	time_t     now = time(0);
	struct tm  tstruct;
	char       buf[80];
	errno_t err = localtime_s(&tstruct, &now);
	err = asctime_s(buf, 26, &tstruct);
	strftime(buf, sizeof(buf), "%d.%m.%Y %X", &tstruct);

	return buf;
}