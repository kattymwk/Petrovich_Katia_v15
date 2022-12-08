#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>
#include <stdio.h>

#define FNAME "tourist.txt"
#define FNAME_BINARY "tourist.bin"

#define ERROR "Ошибка открытия файла!!!"
#define LENGTH 20

using namespace std;

bool FlagBin = 0;
bool FileBinQuest = 0;

class MyException : public exception
{
public:
	static void Error()
	{
		cout << "Возникла неизвестная ошибка!" << endl;
		exit(1);
	}
};

class Tourist {
private:
	string name;
	string city;
	string amountCountries;
	string lastCountry;
public:
	Tourist() {}
	Tourist(string _name, string _city, string _amountCountrues, string _lastCountry)
	{
		name = _name;
		city = _city;
		amountCountries = _amountCountrues;
		lastCountry = _lastCountry;
	}
	~Tourist() {}

	friend class AllTourists;
};

class AllTourists
{
public:
	vector<Tourist> tour;

	AllTourists() {}

	void addTourist() {
		Tourist t;
		try
		{
			cout << "\n\n\t[ Добавление новой записи ]\n\n";

			cout << "Введите имя туриста: ";
			if (!(cin >> t.name)) throw MyException();

			cout << "Введите город проживания туриста: ";
			if (!(cin >> t.city)) throw MyException();

			cout << "Введите количество посещенных стран: ";
			if (!(cin >> t.amountCountries)) throw MyException();

			cout << "Введите последнюю посещенную страну: ";
			if (!(cin >> t.lastCountry)) throw MyException();

			tour.push_back(t);
			cout << "Новая запись с порядковым номером "
				<< tour.size() << " добавлена!" << endl << endl;
			cin.get();
		}
		catch (const MyException& ex)
		{
			MyException::Error();
		}

		if (FlagBin) {
			try {
				ofstream fout(FileBinQuest ? FNAME_BINARY : FNAME, ios::binary | ios::app);

				if (fout.bad() || !fout.is_open()) {
					fout.close();
					throw ERROR;
				}

				fout.write(t.name.c_str(), t.name.size());
				fout.write("\n", 1);
				fout.write(t.city.c_str(), t.city.size());
				fout.write("\n", 1);
				fout.write(t.amountCountries.c_str(), t.amountCountries.size());
				fout.write("\n", 1);
				fout.write(t.lastCountry.c_str(), t.lastCountry.size());
				fout.write("\n", 1);

				fout.close();
			}
			catch (string e) {
				cout << e;
			}
		}

		!FlagBin && this->saveToFile();
	}

	void _delete() {
		cout << "\n\n\t[ Удаление записи ]\n\n";

		int ans;
		int id = this->find();

		if (id == -1)
		{
			cout << "Удаление не удалось!" << endl;
			return;
		}

		cout << endl;

		try
		{
			cout << "Вы уверены, что хотите удалить запись? (да - 1 / нет - 2)? " << endl << endl;
			if (!(cin >> ans)) throw 1;
			if (ans != 1 && ans != 2) {
				do {
					cout << "Повторите ввод!" << endl;
					if (!(cin >> ans)) throw 1;
				} while (ans != 1 && ans != 2);
			}

			if (ans == 1)
			{
				tour.erase(tour.begin() + id);
				cout << "Запись с порядковым номером "
					<< id + 1 << " удалена!" << endl << endl;
				cin.get();

				FlagBin ? this->saveToBFile() : this->saveToFile();
			}
		}
		catch (...)
		{
			MyException::Error();
		}

	}

	int find() {
		int sel;

		cout << "Вы хотите найти запись, выберите способ поиска:" << endl
			<< "1. По порядковому номеру" << endl
			<< "2. По имени" << endl
			<< "\n\n > ";

		try
		{
			if (!(cin >> sel)) throw 1;
			if (sel != 1 && sel != 2) {
				do {
					cout << "Повторите ввод!" << endl;
					if (!(cin >> sel)) throw 1;
				} while (sel != 1 && sel != 2);
			}
			cout << endl;

			if (sel == 2) {
				string val;

				bool isFind = false;

				while (!isFind) {
					cout << "Введите имя для поиска: ";
					cin.clear();
					rewind(stdin);
					getline(cin, val);

					for (int i = 0; i < tour.size(); i++) {
						if (tour[i].name == val) {
							isFind = true;
							this->readFromFile(i);
							return i;
						}
					}
					!isFind && cout << endl << "Турист не найден! " << endl << endl;
				}

				cout << endl;
			}

			int number;
			bool fail = false;

			cout << "Введите порядковый номер записи: ";
			if (!(cin >> number)) throw 1;;

			if (number < 1 || number > tour.size()) {
				this->notFound();
				return -1;
			}
			else this->readFromFile(number - 1);

			return number - 1;
		}
		catch (...)
		{
			MyException::Error();
		}

	}

	void readFromFile(int index = -1) {

		if (index == -1) {
			cout << "Всего " << tour.size() << " записей:" << endl << endl;

			for (int i = 0; i < tour.size(); i++) {
				cout << i + 1 << ". "
					<< tour[i].name << "  "
					<< tour[i].city << "  "
					<< tour[i].amountCountries << "  "
					<< tour[i].lastCountry << endl;
			}
		}
		else {
			cout << index + 1 << ". "
				<< tour[index].name << "  "
				<< tour[index].city << "  "
				<< tour[index].amountCountries << "  "
				<< tour[index].lastCountry << endl;
		}
	}

	int readReverse() {
		for (int i = tour.size() - 1; i >= 0; i--) {
			cout << i + 1 << ". "
				<< tour[i].name << "  "
				<< tour[i].city << "  "
				<< tour[i].amountCountries << "  "
				<< tour[i].lastCountry << endl;
		}

		return 1;
	}

	void notFound() {
		cout << endl << "Записи с данным порядковым номером не существует" << endl;
	}

	bool saveToFile() {
		try {
			ofstream fout(FNAME);

			if (fout.bad() || !fout.is_open())
			{
				throw ERROR;
				fout.close();
			}

			for (int i = 0; i < tour.size(); i++)
			{
				fout << tour[i].name << endl
					<< tour[i].city << endl
					<< tour[i].amountCountries << endl
					<< tour[i].lastCountry << endl;
			}

			fout.close();
			return true;
		}
		catch (string e) {
			cout << e;
			return false;
		}
	}

	bool saveToBFile() {
		try {
			ofstream fout(FileBinQuest ? FNAME_BINARY : FNAME, ios::binary | ios::trunc); // open and clear file
			fout.close();

			fout.open(FileBinQuest ? FNAME_BINARY : FNAME, ios::binary | ios::app);

			if (fout.bad() || !fout.is_open()) {
				fout.close();

				throw ERROR;
			}

			for (int i = 0; i < tour.size(); i++)
			{
				fout.write(tour[i].name.c_str(), tour[i].name.size());
				fout.write("\n", 1);
				fout.write(tour[i].city.c_str(), tour[i].city.size());
				fout.write("\n", 1);
				fout.write(tour[i].amountCountries.c_str(), tour[i].amountCountries.size());
				fout.write("\n", 1);
				fout.write(tour[i].lastCountry.c_str(), tour[i].lastCountry.size());
				fout.write("\n", 1);
			}

			fout.close();
			return true;
		}
		catch (string e) {
			cout << e;
			return false;
		}
	}


	bool load() {
		try {
			ifstream fin(FileBinQuest ? FNAME_BINARY : FNAME);

			if (fin.bad() || !fin.is_open()) {
				fin.close();

				throw ERROR;
			}

			tour.clear();

			while (!fin.eof()) {
				Tourist t;
				if (!getline(fin, t.name) ||
					!getline(fin, t.city) ||
					!getline(fin, t.amountCountries) ||
					!getline(fin, t.lastCountry))
					break;

				tour.push_back(t);
			}

			fin.close();
			return true;
		}
		catch (string e) {
			cout << e;
			return false;
		}
	}

	bool loadBinary() {
		ifstream fin;
		Tourist st;

		fin.open(FileBinQuest ? FNAME_BINARY : FNAME, ios::binary);

		while (getline(fin, st.name, FileBinQuest ? '\n' : '\r')) {
			if (fin.eof())
				break;

			!FileBinQuest && fin.get();
			getline(fin, st.city, FileBinQuest ? '\n' : '\r');

			!FileBinQuest && fin.get();
			getline(fin, st.amountCountries, FileBinQuest ? '\n' : '\r');

			!FileBinQuest && fin.get();
			getline(fin, st.lastCountry, FileBinQuest ? '\n' : '\r');

			!FileBinQuest && fin.get();

			tour.push_back(st);
		}
		fin.close();
		return true;
	}
};

AllTourists Box;


bool menu() {
	int sel;
	try
	{
		cout << "\n\n\t[ Главное меню ]\n\n";

		cout
			<< "1. Посмотреть список записей (" << Box.tour.size() << ")" << endl
			<< "2. Добавить новую запись" << endl
			<< "3. Удалить запись" << endl
			<< "4. Найти запись" << endl
			<< "5. Реверсивный вывод" << endl
			<< "6. Выход" << endl;

		cin.clear();
		rewind(stdin);
		cout << endl << " > ";
		if (!(cin >> sel)) throw 1;;


		switch (sel) {
		case 1: Box.readFromFile(); break;
		case 2: Box.addTourist(); break;
		case 3: Box._delete(); break;
		case 4: Box.find(); break;
		case 5: Box.readReverse(); break;
		case 6: return false; break;
		default: break;
		}

		return true;
	}
	catch (...)
	{
		MyException::Error();
	}

}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	try
	{
		int f;
		cout << "Хотите продолжить в бинарном режиме? (да - 1 / нет - 2): ";
		if (!(cin >> f)) throw 1;
		if (f != 1 && f != 2) {
			do {
				cout << "Повторите ввод!" << endl;
				if (!(cin >> f)) throw 1;
			} while (f != 1 && f != 2);
		}
		FlagBin = bool(f == 1);

		cout << "Работа с бинарным файлом? (да - 1 / нет - 2): ";
		if (!(cin >> f)) throw 1;
		if (f != 1 && f != 2) {
			do {
				cout << "Повторите ввод!" << endl;
				if (!(cin >> f)) throw 1;
			} while (f != 1 && f != 2);
		}
		if (bool(f == 1)) {
			FileBinQuest = true;

			if (!FlagBin) {
				cout << endl <<
					"Будет установлен бинарный режим для работы с бинарным файлом."
					<< endl;

				FlagBin = true;
			}
		}

		FlagBin ? Box.loadBinary() : Box.load();

		while (menu()) {};

	}
	catch (...)
	{
		MyException::Error();
	}

	return 0;
}
