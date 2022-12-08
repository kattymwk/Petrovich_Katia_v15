#include <iostream>
#include <windows.h>
#include "Container.h"

using namespace std;

int main()
{
    bool Contin = true;
    try
    {
    while (Contin)
    {
        setlocale(LC_ALL, "ru");
        system("cls");

            int sel = 0;
            while (sel != 1 && sel != 2 && sel != 3)
            {
                cout << "\tВыберите тип для продолжения: " << endl
                    << "1. Int" << endl << "2. Float" << endl
                    << "3. Char" << endl << endl;
                cin >> sel;
            }
            switch (sel)
            {
            case 1:
            {
                int nod;
                List<int> listInt;
                cout << "Введите первый узел: " << endl;
                cin >> nod;
                listInt.OneN(nod);
                bool FlagCont = true;
                while (FlagCont)
                {
                    cout << "Хотите добавить еще один узел? (1 - да | 2 -  нет)" << endl;
                    int ans = 0;
                    while (ans != 1 && ans != 2) { cin >> ans; }
                    if (ans == 1)
                    {
                        int a;
                        cout << "Введите число: " << endl;
                        cin >> a;
                        listInt.Push_front(a);

                        FlagCont = true;
                    }
                    if (ans == 2) FlagCont = false;
                }
                listInt.Print();
                int s;
                cout << "Введите число для поиска: " << endl;
                cin >> s;
                cout << "Найдено: " << listInt.Find(s)->data << endl;
                int d;
                cout << "Введите число для удаления: " << endl;
                cin >> d;
                listInt.Remove(d);
                int s2;
                cout << "Введите число для поиска: " << endl;
                cin >> s2;
                cout << "Найдено: " << listInt.Find(s2)->data << endl;
                listInt.Print();

                cout << "Хотите продолжить работу с другим типом? (1 - да | 2 - нет)" << endl;
                int p = 0;
                while (p != 1 && p != 2)
                {
                    cin >> p;
                }
                if (p == 1) Contin = 1;
                else Contin = 0;

                    break;
            }
            case 2:
            {
                List<float> listFloat;
                float nod;

                cout << "Введите первый узел: " << endl;
                cin >> nod;
                listFloat.OneN(nod);
                bool FlagCont = true;
                while (FlagCont)
                {
                    cout << "Хотите добавить еще один узел? (1 - да | 2 -  нет)" << endl;
                    int ans = 0;
                    while (ans != 1 && ans != 2) { cin >> ans; }
                    if (ans == 1)
                    {
                        float a;
                        cout << "Введите число: " << endl;
                        cin >> a;
                        listFloat.Push_front(a);
                        FlagCont = true;
                    }
                    if (ans == 2) FlagCont = false;
                }
                listFloat.Print();
                float s;
                cout << "Введите число для поиска: " << endl;
                cin >> s;
                cout << "Найдено: " << listFloat.Find(s)->data << endl;
                float d;
                cout << "Введите число для удаления: " << endl;
                cin >> d;
                listFloat.Remove(d);
                float s2;
                cout << "Введите число для поиска: " << endl;
                cin >> s2;
                cout << "Найдено: " << listFloat.Find(s2)->data << endl;
                listFloat.Print();

                cout << "Хотите продолжить работу с другим типом? (1 - да | 2 - нет)" << endl;
                int p = 0;
                while (p != 1 && p != 2)
                {
                    cin >> p;
                }
                if (p == 1) Contin = 1;
                else Contin = 0;

                break;
            }
            case 3:
            {
                List<char> listChar;
                char nod;

                cout << "Введите первый узел: " << endl;
                cin >> nod;
                listChar.OneN(nod);
                bool FlagCont = true;
                while (FlagCont)
                {
                    cout << "Хотите добавить еще один узел? (1 - да | 2 -  нет)" << endl;
                    int ans = 0;
                    while (ans != 1 && ans != 2) { cin >> ans; }
                    if (ans == 1)
                    {
                        char a;
                        cout << "Введите символ: " << endl;
                        cin >> a;
                        listChar.Push_front(a);
                        FlagCont = true;
                    }
                    if (ans == 2) FlagCont = false;
                }
                listChar.Print();
                char s;
                cout << "Введите символ для поиска: " << endl;
                cin >> s;
                cout << "Найдено: " << listChar.Find(s)->data << endl;
                char d;
                cout << "Введите символ для удаления: " << endl;
                cin >> d;
                listChar.Remove(d);
                char s2;
                cout << "Введите символ для поиска: " << endl;
                cin >> s2;
                cout << "Найдено: " << listChar.Find(s2)->data << endl;
                listChar.Print();

                cout << "Хотите продолжить работу с другим типом? (1 - да | 2 - нет)" << endl;
                int p = 0;
                while (p != 1 && p != 2)
                {
                    cin >> p;
                }
                if (p == 1) Contin = 1;
                else Contin = 0;

                break;
            }
            }
    }
    }
    catch (MyException ex)
    {
        cout << ex.what();
    }
    return 0;
}

