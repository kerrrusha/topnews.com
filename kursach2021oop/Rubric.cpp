#include "Rubric.h"
using namespace std;


void Rubric::makePublication(string _name, string _content, string _author, vector<string> _tags, Date _date)
{
	Publication newPost(_name, _content, _author, _tags, _date);
	data.push_back(newPost);
}
int Rubric::howManyInside()
{
	return data.size();
}
string Rubric::getContentAt(int id)
{
	string result = "";
	if (id >= 0 && id < (int)data.size())
	{
		result += data.at(id).getContent();
	}
	return result;
}
string Rubric::getNameAt(int id)
{
	string result = "";
	if (id >= 0 && id < (int)data.size())
	{
		result += data.at(id).getName();
	}
	return result;
}
string Rubric::getAuthorAt(int id)
{
	string result = "";
	if (id >= 0 && id < (int)data.size())
	{
		result += data.at(id).getAuthor();
	}
	return result;
}
vector <string> Rubric::getTagsAt(int id)
{
	vector <string> result;
	if (id >= 0 && id < (int)data.size())
	{
		result = data.at(id).getTags();
	}
	return result;
}
string Rubric::getDateAt(int id)
{
	string result = "";
	if (id >= 0 && id < (int)data.size())
	{
		result += data.at(id).getDate();
	}
	return result;
}
Date Rubric::getDateObjAt(int id)
{
	return data.at(id).getDateObj();
}