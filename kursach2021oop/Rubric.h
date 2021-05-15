#pragma once
#include "Publication.h"
#include "iContainer.h"

class Rubric : public iContainer <Publication>
{
public:
	void makePublication(std::string _name, std::string _content, std::string _author, std::vector<std::string> _tags, Date _date);
	int howManyInside();
	std::string getContentAt(int id);
	std::string getNameAt(int id);
	std::string getAuthorAt(int id);
	std::vector <std::string> getTagsAt(int id);
	std::string getDateAt(int id);
	Date getDateObjAt(int id);
};