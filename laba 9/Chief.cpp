#include "Chief.h"

work::Chief::Chief()
{
	cout << "����������� Chief" << endl;
}

work::Chief::Chief(string name, int age, int salary, int yearOnPost, string speciality,
	string placeOfStudy, string nameOfDeparment, int workingArea) :
	Employee(name, age, salary, "������������", speciality, placeOfStudy, nameOfDeparment, workingArea)
{
	cout << "����������� Chief" << endl;
	if (yearOnPost < 0) {
		throw exception("�������� ����!");
	}
	this->yearsOnPost = yearOnPost;
}

work::Chief::~Chief()
{
	cout << "���������� Chief" << endl;
}

void work::Chief::showInfo()
{
	Employee::showInfo();
	cout << "���� �� ����� = " << yearsOnPost << endl;
}