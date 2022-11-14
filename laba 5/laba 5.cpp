#include <iostream>
#include <string>
using namespace std;

template<class T>
void revers(T* mas, int dl)
{
    int len = dl;
    cout << "Исходный массив:" << endl;
    for (int i = 0; i < len; i++)
    {  cout << mas[i]<<"   "; }
    cout << endl;
    for (int i = 0; i < len/2; i++)
    {
        T temp = mas[i];
        mas[i] = mas[len - 1 - i];
        mas[len - 1 - i] = temp;
    }
    cout << "Массив после перестановки:" << endl;
    for (int i = 0; i < len; i++)
    {  cout << mas[i]<<"   "; }
    cout << endl << endl;
}

template<>
void revers<char>(char* mas, int dl)
{
    int len = dl;
    cout << "Исходный массив:" << endl;
    for (int i = 0; i < len; i++)
    {
        cout << mas[i] << " ___ ";
    }
    cout << endl;
    for (int i = 0; i < len / 2; i++)
    {
        char temp = mas[i];
        mas[i] = mas[len - 1 - i];
        mas[len - 1 - i] = temp;
    }
    cout << "Массив после перестановки:" << endl;
    for (int i = 0; i < len; i++)
    {
        cout << mas[i] << " ___ ";
    }
    cout << endl << endl;
}

template<>
void revers<string>(string* mas, int dl)
{
    int len = dl;
    cout << "Исходный массив:" << endl;
    for (int i = 0; i < len; i++)
    {
        cout << mas[i] << "/ /";
    }
    cout << endl;
    for (int i = 0; i < len / 2; i++)
    {
        string temp = mas[i];
        mas[i] = mas[len - 1 - i];
        mas[len - 1 - i] = temp;
    }
    cout << "Массив после перестановки:" << endl;
    for (int i = 0; i < len; i++)
    {
        cout << mas[i] << "/ /";
    }
    cout << endl << endl;
}

int main()
{
    setlocale(LC_ALL, "ru");
    int a[] = { 2,45,65,7,10,87,456,11};
    double b[] = { 2.3,1.5,15.4,12.4 };
    char c[] = { '%','5','*','х','%','д','8','ф',')'};
    string d[] = { "лаба 1", "лаба 2","лаба 3","лаба 4","лаба 5" };

    revers(a, sizeof(a) / sizeof(*a));
    revers(b, sizeof(b) / sizeof(*b));
    revers(c, sizeof(c) / sizeof(*c));
    revers(d, sizeof(d) / sizeof(*d));

    return 0;
}
