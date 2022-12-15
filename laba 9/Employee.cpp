#include "Employee.h"

work::Employee::Employee()
{
	cout << "����������� Employee" << endl;
	salary = 0;
}

work::Employee::Employee(string name, int age, int salary, string jobTitle, string speciality, string placeOfStudy,
	string nameOfDeparment, int workingArea) : Human(name, age)
{

	cout << "����������� Employee" << endl;
	if (salary < 0) 
	{
		throw exception("�������� ����!");
	}
	this->salary = salary;
	this->speciality.setSpeciality(speciality);
	this->speciality.setPlaceOfStudy(placeOfStudy);
	this->department.setNameOfDepartment(nameOfDeparment);
	this->department.setWorkingPlace(workingArea);
	this->jobTitle.setJobTitle(jobTitle);
}

work::Employee::~Employee()
{
	cout << "���������� Employee" << endl;
}

void work::Employee::showInfo()
{
	Human::showInfo();
	cout << "�������� = " << salary << endl;
	jobTitle.showInfo();
	speciality.showInfo();
	department.showInfo();
}