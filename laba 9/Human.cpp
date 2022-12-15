#include "Human.h"

work::Human::Human()
{
	cout << endl<<"конструктор Human" << endl;
	name = "нет данных";
	age = 0;
}

work::Human::Human(string name, int age)
{
	cout <<endl<< "конструктор Human" << endl;
	if (age < 0) {
		throw exception("неверный ввод!");
	}
	this->name = name;
	this->age = age;
}

work::Human::~Human()
{
	cout << "деструктор Human" << endl;
}

void work::Human::showInfo()
{
	cout << "имя: " << name << "\nвозраст: " << age << endl;
}