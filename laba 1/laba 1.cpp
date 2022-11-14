#include <iostream>
#include <string>
using namespace std;

class employee
{
private:
	static int id;
	int m_id;
	string m_name;
	double m_salary;

public:
	employee()
	{
		m_id = id++;
		m_name = { "Олег" };
		m_salary = 333;
	}
	friend void print(employee& employee);
	employee(string name, double salary = 0) :m_name(name), m_id(id++), m_salary(salary) {}
	~employee() {}
	friend class accountant;
};

int employee::id = 1;

void print(employee& emp)
{
	cout << "Имя:" << emp.m_name << "\nId: " << emp.m_id << "\nЗарплата в прошлом месяце: " << emp.m_salary << " б.р." << endl;
}

class accountant
{
public:
	void newSalary(employee& e)
	{
		cout << "Введите текущую зарплату для " << e.m_name << endl;
		cin >> e.m_salary;
		if (e.m_salary < 0)
		{
			do
			{
				cout << "Повторите ввод!:\n" << endl;
				cin >> e.m_salary;
			} while (e.m_salary < 0);
		}
		cout << "Зарплата после прибавки y " << e.m_name << ":" << e.m_salary * 1.15 << "\n" << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "ru");
	accountant acc;

	employee a("Иван Голицын", 2500);
	print(a);
	acc.newSalary(a);

	employee aa("Ольга Фурса");
	print(aa);
	acc.newSalary(aa);

	employee aaa("Петр Иванов", 1203);
	print(aaa);
	acc.newSalary(aaa);

	const int size = 3;
	employee massiv[size] = {
	employee("Тимофей Иванов", 200),
	employee("Алексей Дулько", 5050),
	employee("Вероника Шишкина", 990) };

	for (int i = 0; i < size; i++)
	{
		print(massiv[i]);
		acc.newSalary(massiv[i]);
	}
	return 0;
}

