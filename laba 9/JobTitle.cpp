#include "JobTitle.h"

work::JobTitle::JobTitle()
{
	cout << "конструктор JobTitle" << endl;
	jobTitle = "нет данных";
}

work::JobTitle::JobTitle(string jobTitle)
{
	cout << "конструтор JobTitle" << endl;
	this->jobTitle = jobTitle;
}

work::JobTitle::~JobTitle()
{
	cout << "деструктор JobTitle" << endl;
}

void work::JobTitle::setJobTitle(string jobTitle)
{
	this->jobTitle = jobTitle;
}
void work::JobTitle::showInfo()
{
	cout << "должность: " << jobTitle << endl;
}

