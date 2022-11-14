// 6
#include <iostream>
#include <string>
using namespace std;

class Fungus
{
protected:
    bool isUnicellular;
public:
    Fungus() {}

    Fungus(bool _isUnicellular)
    {
        isUnicellular = _isUnicellular;
    }

    void virtual Eat() = 0;

    void virtual Info() = 0;

    virtual ~Fungus() {}
};

class UnicellularFungus : public Fungus
{
protected:
    string area;
public:
    UnicellularFungus() {}

    UnicellularFungus(string _area, bool isUnicellular = false) : Fungus(isUnicellular)
    {
        area = _area;
    }

    void Eat() override { cout << " - Возможно, все будет хорошо" << endl << endl; }

    void Info() override { cout << "Название: Одноклеточный гриб" << "\n\tОбласть: " << area << "\n\tОдноклеточный(?): " << isUnicellular; }

    virtual ~UnicellularFungus() {}
};

class Penicillium : public UnicellularFungus
{
private:
    int group;
public:
    Penicillium() {}

    Penicillium(int _group, string area, bool isUnicellular = false) : UnicellularFungus(area, isUnicellular)
    {
        group = _group;
    }

    void Eat() override { cout << " - Вы выздоровели!" << endl<<endl; }

    void Info() override { cout << "Название: Пенициллин" << "\n\tГруппа: " << group << "\n\tОбласть: " << area << "\n\tОдноклеточный(?): " << isUnicellular; }


    virtual ~Penicillium() {}
};


class FlyAgaric : public Fungus
{
private:
    string type;
public:
    FlyAgaric() {}

    FlyAgaric(string _type, bool isUnicellular = false) : Fungus(isUnicellular)
    {
        type = _type;
    }

    void Eat() override { cout << " - Вы мертвы..." << endl<<endl; }

    void Info() override { cout << "Название: Мухомор" << "\n\tТип: " << type << "\n\tОдноклеточный(?): " << isUnicellular; }

    virtual ~FlyAgaric() {}
};


int main()
{
    setlocale(LC_ALL,"ru");
    Fungus** af = new Fungus* [3];
    af[0] = new UnicellularFungus("Сибирь", true);
    af[1] = new Penicillium(4, "США", true);
    af[2] = new FlyAgaric("Базидиомикота", false);

    cout << "pov: Вы съели эти грибы" <<endl<<endl;
    for (int i = 0; i < 3; i++)
    {
        af[i]->Info();
        af[i]->Eat();

        delete af[i];
    }

    return 0;
}