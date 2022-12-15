#include "Department.h"

work::Department::Department() 
{
	cout << "конструктор Department" << endl;
	nameOfDeparment = "нет данных";
}

work::Department::Department(string nameOfDeparment, int workingArea)
{
	cout << "конструктор Department" << endl;
	if (workingArea <= 0) {
		throw exception("неверный ввод!");
	}
	this->nameOfDeparment = nameOfDeparment;
	this->workingPlace.setWorkingArea(workingArea);
}

work::Department::~Department()
{
	cout << "деструктор Department" << endl;
}

void work::Department::setNameOfDepartment(string nameOfDepartment)
{
	this->nameOfDeparment = nameOfDepartment;
}

void work::Department::setWorkingPlace(int workingArea)
{
	if (workingArea <= 0) {
		throw exception("неверный ввод!");
	}
	this->workingPlace.setWorkingArea(workingArea);
}

void work::Department::showInfo()
{

	cout << "название отдела: " << nameOfDeparment << endl;
	workingPlace.showInfo();
}

work::Department::WorkingPlace::WorkingPlace() {
	cout << "конструктор WorkingPlace" << endl;
	workingArea = 0;
}
work::Department::WorkingPlace::WorkingPlace(int workingArea)
{
	cout << "конструктор WorkingPlace" << endl;
	if (workingArea <= 0) {
		throw exception("неверный ввод!");
	}
	this->workingArea = workingArea;
}

work::Department::WorkingPlace::~WorkingPlace()
{
	cout << "деструктор Working Place" << endl;
}

void work::Department::WorkingPlace::setWorkingArea(int workingArea)
{
	this->workingArea = workingArea;
}

void work::Department::WorkingPlace::showInfo()
{
	cout << "рабочая зона: " << workingArea << endl;
}