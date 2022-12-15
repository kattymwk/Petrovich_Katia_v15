#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string path_in = "inFile.txt";
string path_out = "outFile.txt";
string subStr;

int search(string str);

void readAndWrite() {
	try {
		fstream file_in;
		fstream file_out;
		file_in.open(path_in);
		cout <<endl<< path_in << " успешно открыт" << endl;
		//file2.open(path2, ios::app );
		file_out.open(path_out, std::ios::in | std::ios::out);
		cout << path_out << " успешно открыт" << endl<<endl;

		string str;
		int countStr = 1;

		while (getline(file_in, str)) {
			cout << "Считана строка " << countStr++ << " : " << str << endl;

			int count = search(str);

			file_out << count << "\n";
			cout << "записано в файл " << count << endl;
		}
		file_in.close();
		cout <<endl<< path_in << " успешно закрыт" << endl;

		file_out.close();
		cout << path_out << " успешно закрыт" << endl;
	}
	catch (exception ex) {
		cout << ex.what() << endl;
		cout << "ошибка открытия файла" << endl;
	}
}

int search(string str) 
{
	int count = 0;

	for (int i = 0; i < str.length();)
	{
		int ind1;

		if ((ind1 = str.rfind(" ")) == -1) 
		{
			break;
		}

		auto s1 = str.substr(ind1 + 1);

		if (s1.find(subStr) != -1) 
		{
			count++;
			cout << "найдено вхождение подстроки " << subStr << " в строке " << s1 << endl;
		}
		str.erase(ind1);
	}
	if (str.find(subStr) != -1) {
		count++;
		cout << "найдено вхождение подстроки " << subStr << " в строке " << str << endl;
	}
	return count;
}

int main() {
	setlocale(LC_ALL, "rus");
	cout << "Введите подстроку для поиска: " << endl;
	cin >> subStr;
	readAndWrite();
}