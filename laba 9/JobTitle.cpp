#include "JobTitle.h"

work::JobTitle::JobTitle()
{
	cout << "����������� JobTitle" << endl;
	jobTitle = "��� ������";
}

work::JobTitle::JobTitle(string jobTitle)
{
	cout << "���������� JobTitle" << endl;
	this->jobTitle = jobTitle;
}

work::JobTitle::~JobTitle()
{
	cout << "���������� JobTitle" << endl;
}

void work::JobTitle::setJobTitle(string jobTitle)
{
	this->jobTitle = jobTitle;
}
void work::JobTitle::showInfo()
{
	cout << "���������: " << jobTitle << endl;
}

