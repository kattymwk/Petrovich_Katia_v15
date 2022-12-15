#include "Chief.h"

work::Chief::Chief()
{
	cout << "конструктор Chief" << endl;
}

work::Chief::Chief(string name, int age, int salary, int yearOnPost, string speciality,
	string placeOfStudy, string nameOfDeparment, int workingArea) :
	Employee(name, age, salary, "руководитель", speciality, placeOfStudy, nameOfDeparment, workingArea)
{
	cout << "конструктор Chief" << endl;
	if (yearOnPost < 0) {
		throw exception("неверный ввод!");
	}
	this->yearsOnPost = yearOnPost;
}

work::Chief::~Chief()
{
	cout << "деструктор Chief" << endl;
}

void work::Chief::showInfo()
{
	Employee::showInfo();
	cout << "срок на посте = " << yearsOnPost << endl;
}