#include "Human.h"

work::Human::Human()
{
	cout << endl<<"����������� Human" << endl;
	name = "��� ������";
	age = 0;
}

work::Human::Human(string name, int age)
{
	cout <<endl<< "����������� Human" << endl;
	if (age < 0) {
		throw exception("�������� ����!");
	}
	this->name = name;
	this->age = age;
}

work::Human::~Human()
{
	cout << "���������� Human" << endl;
}

void work::Human::showInfo()
{
	cout << "���: " << name << "\n�������: " << age << endl;
}