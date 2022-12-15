#include "Department.h"

work::Department::Department() 
{
	cout << "����������� Department" << endl;
	nameOfDeparment = "��� ������";
}

work::Department::Department(string nameOfDeparment, int workingArea)
{
	cout << "����������� Department" << endl;
	if (workingArea <= 0) {
		throw exception("�������� ����!");
	}
	this->nameOfDeparment = nameOfDeparment;
	this->workingPlace.setWorkingArea(workingArea);
}

work::Department::~Department()
{
	cout << "���������� Department" << endl;
}

void work::Department::setNameOfDepartment(string nameOfDepartment)
{
	this->nameOfDeparment = nameOfDepartment;
}

void work::Department::setWorkingPlace(int workingArea)
{
	if (workingArea <= 0) {
		throw exception("�������� ����!");
	}
	this->workingPlace.setWorkingArea(workingArea);
}

void work::Department::showInfo()
{

	cout << "�������� ������: " << nameOfDeparment << endl;
	workingPlace.showInfo();
}

work::Department::WorkingPlace::WorkingPlace() {
	cout << "����������� WorkingPlace" << endl;
	workingArea = 0;
}
work::Department::WorkingPlace::WorkingPlace(int workingArea)
{
	cout << "����������� WorkingPlace" << endl;
	if (workingArea <= 0) {
		throw exception("�������� ����!");
	}
	this->workingArea = workingArea;
}

work::Department::WorkingPlace::~WorkingPlace()
{
	cout << "���������� Working Place" << endl;
}

void work::Department::WorkingPlace::setWorkingArea(int workingArea)
{
	this->workingArea = workingArea;
}

void work::Department::WorkingPlace::showInfo()
{
	cout << "������� ����: " << workingArea << endl;
}