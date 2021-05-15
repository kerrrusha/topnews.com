#pragma once
#include <string>
#include <vector>
#include "Date.h"

class Publication
{
private:
	class PublicationInfo			//композиция
	{
	public:
		std::string name;
		std::string author;
		std::vector<std::string> tags;
		Date date;
		PublicationInfo()
		{
			name = "unknown";
			author = "unknown";
		}

		void updateInfo(std::string _name, std::string _author, std::vector<std::string> _tags, Date _date)
		{
			name = _name;
			author = _author;
			tags.swap(_tags);
			date = _date;
		}

		~PublicationInfo()
		{
			tags.clear();
		}
	};

	PublicationInfo info;
	std::string content;
public:
	Publication(std::string _name, std::string _content, std::string _author, std::vector<std::string> _tags, Date _date);

	std::string getName();
	std::string getAuthor();
	std::vector<std::string> getTags();
	std::string getDate();
	std::string getContent();
	Date getDateObj();
};