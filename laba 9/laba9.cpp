#include <iostream>
#include <windows.h>
#include "Chief.h"
using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	using namespace work;
	try 
	{
		cout << "Введите срок на посте руководителя: " << endl;
		int srok;
		cin >> srok;
		Chief chief = Chief("Алексей", 44, 2500, srok, "программист", "бгу", "отдел QRR", 1);
		cout << endl;
		chief.showInfo();
		cout << endl;

		cout << "Нужно добавить сотрудника в отдел QRR" << endl;

		string name, jobTitle, speciality, study;
		int age, sal, place;
		cout << "Введите имя сотрудника: " << endl;
		cin>>name;
		cout << "Введите возраст: " << endl;
		cin >> age;
		cout << "Зарплата: " << endl;
		cin >> sal;
		cout << "Введите должность:" << endl;
		cin>>jobTitle;
		cout << "Специализация:" << endl;;
		cin>> speciality;
		cout << "Введите место обучения:" << endl;
		cin>> study;
		cout << "Рабочее место номер:" << endl;
		cin >> place;
		Employee em = Employee(name, age, sal, jobTitle, speciality, study, "отдел QRR", place);
		cout << endl;
		system("cls");
		em.showInfo();
		cout << endl;
	}
	catch (exception ex) {
		cout << ex.what() << endl;
	}

}
