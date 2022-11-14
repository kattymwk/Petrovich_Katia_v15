#include <iostream>
#include <cmath>
using namespace std;
class ComplexSquare
{
private:
    double real;
    double ireal;

public:
    ComplexSquare(double _real, double _ireal)
    {
        real = _real;
        ireal = _ireal;
    }

    friend ostream& operator << (ostream& out, ComplexSquare a);
};

class ComplexNumber
{
private:
    double real;
    double ireal;
public:
    ComplexNumber(double _real = 0, double _ireal = 0)
    {
        real = _real;
        ireal = _ireal;
    }

    double Pow_()
    {
        return pow((pow(real, 3) + pow(ireal, 3)), 1 / 3.);
    }

    ComplexSquare Square()
    {
        return ComplexSquare(pow(real, 3), pow(ireal, 3));
    }

    friend void operator -- (ComplexNumber& num, int);
    friend ComplexNumber operator - (ComplexNumber a1, ComplexNumber a2);
    friend ostream& operator << (ostream& out, ComplexNumber a);

    ComplexNumber& operator = (ComplexNumber a1)
    {
        real = a1.real;
        ireal = a1.ireal;
        return *this;
    }

    void operator()(double _real, double _ireal)
    {
        real = _real;
        ireal = _ireal;
    }

    void operator ++ (int) { real++; }

    ComplexNumber& operator + (ComplexNumber a2)
    {
        real += a2.real;
        ireal += a2.ireal;
        return *this;
    }

    bool operator == (ComplexNumber a2)
    {
        return real == a2.real && ireal == a2.ireal;
    }
};

void operator -- (ComplexNumber& num, int) { num.real--; }

ComplexNumber operator - (ComplexNumber a1, ComplexNumber a2)
{
    return  ComplexNumber(a1.real - a2.real, a1.ireal - a2.ireal);
}

ostream& operator << (std::ostream& out, ComplexNumber a)
{
    return out << a.real << " " << a.ireal << "i";
}
ostream& operator << (std::ostream& out, ComplexSquare a)
{
    return out << a.real << " " << a.ireal << "i";
}


int main()
{

    ComplexNumber a(19, 3.8);

    ComplexNumber b(9, 5.5);

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    a--;
    cout << "(--) a = " << a << endl;
    a++;
    cout << "(++) a = " << a << endl;

    a = a + b;
    cout << "(+b) a = " << a << endl;
    a = a - b;
    cout << "(-b) a = " << a << endl << endl;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    a = b;
    cout << "(a = b) a = " << a << endl;

    a = ComplexNumber(10, 17.3);
    cout << "a = " << a << endl;
    bool tr = b == b;
    cout << "b == b " << tr << endl;
    bool fl = a == b;
    cout << "a == b " << fl << endl << endl;

    ComplexNumber c;
    c(15, 10.1);
    cout << "c = " << c << endl;

    cout << "c Pow_() = " << c.Pow_() << endl;
    cout << "c to Square = " << c.Square() << endl;

    return 0;
}
