#include <iostream>
#include <exception>
using namespace std;
#define LEN 10

class MyException : public exception
{
public:
    static void stackEmpty()
    {
        cout << "Стек пуст!" << endl;
        terminate();
    }
    static void stackFull() 
    {
        cout << "Ошибка: стек заполнен!" << endl;
        terminate();
    }
    static void Error()
    {
        cout << "Что-то пошло не так..." << endl;
        exit(1);
    }
};

template <class T>
class Stack 
{
public:
    inline static T StackArr[LEN] = { 0 };

    T* begin = StackArr;
    T* end = StackArr;
    int k = 0;
    Stack() {}

    void print() 
    {
        try 
        {
            if (end == begin)
                throw MyException();
            cout << endl << "Стек:" << endl;
            for (int i = 0; i < LEN; i++)
            {
                cout << StackArr[i] << " ";
            }
            cout << endl << endl;
        }
        catch (const MyException &ex)
        {
            MyException::stackEmpty();
        }

    }

    void push()
    {
        T a;
        try
        {
                if (!(cin >> a))
                {
                    throw MyException();
                }
                *(end++) = a;
                k++;
        }
        catch (const MyException& ex)
        {
            MyException::Error();
        }
    }

    void pop() 
    {
        try 
        {
            if (end == begin)
                throw MyException();
       
           T a = *(--end);
           cout <<"Верхний элемент стека: " << a << endl;
           StackArr[--k] = 0;
           cout <<"Количество элементов в стеке после pop(): " << k << endl;
        }
        catch (const MyException& ex) 
        {
            MyException::stackEmpty();
        }
    }

    void top() 
    {
        try 
        {
            if (end == begin)
                throw MyException();

            cout << "Последний элемент стека: " << *(end - 1);
            cout << endl << endl;
        }
        catch (const MyException& ex) 
        {
            MyException::stackEmpty();
        }
    }

    void Compare()
    {
        try
        {
            int index1, index2;
            cout << "Введите индексы элементов для сравнения: " << endl;
            if (!(cin >> index1)) throw MyException();
            if (!(cin >> index2)) throw MyException();
            if (index1 > k  || index2 > k ) throw 1;
            if (StackArr[index1] > StackArr[index2]) cout << "Больше" << endl;
            if(StackArr[index1] < StackArr[index2]) cout << "Меньше" << endl;
            if (StackArr[index1] == StackArr[index2]) cout << "Равны" << endl;
        }
        catch (const MyException& ex)
        {
            MyException::Error();
        }
        catch (...)
        {
            cout << "Вы ввели несуществующий индекс!" << endl;
        }
    }
};

int main()
{
    setlocale(LC_ALL,"ru");
    Stack<int> Stc;

    cout << "Введите элементы стека: " << endl;
        for (int i = 0; i < 7; i++)
        {
            Stc.push();
        }
        Stc.print();
        Stc.pop();
        Stc.print();
        Stc.pop();
        Stc.print();
        cout << "Введите элемент: " << endl;
        Stc.push(); 
        Stc.print();
        Stc.Compare();
        Stc.top();
  
    return 0;
}
