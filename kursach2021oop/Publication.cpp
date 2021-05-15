#include "Publication.h"
using namespace std;

Publication::Publication(string _name, string _content, string _author, vector<string> _tags, Date _date)
{
	info.updateInfo(_name, _author, _tags, _date);
	content = _content;
}

string Publication::getName()
{
	return info.name;
}
string Publication::getAuthor()
{
	return info.author;
}
vector<string> Publication::getTags()
{
	return info.tags;
}
string Publication::getDate()
{
	string result = "";
	if (info.date.day < 10)
		result += ("0" + to_string(info.date.day));
	else
		result += to_string(info.date.day);

	result += ".";

	if (info.date.month < 10)
		result += ("0" + to_string(info.date.month));
	else
		result += to_string(info.date.month);

	result += ("." + to_string(info.date.year));
	return result;
}
string Publication::getContent()
{
	return content;
}
Date Publication::getDateObj()
{
	return info.date;
}