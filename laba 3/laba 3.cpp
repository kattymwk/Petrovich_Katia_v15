#include <iostream>
using namespace std;

class Fungus
{
protected:
    string Kingdom;
public:
    Fungus() {}
    Fungus(string _Kingdom) { Kingdom = _Kingdom; }
    void GetKingdom()
    {
        cout << "Царство гриба - " << this->Kingdom << endl;
    }
};

class Lamellar :public virtual Fungus
{
protected:
    string SubKingdom;
public:
    Lamellar(string _SubKingdom,string _Kingdom) :Fungus(_Kingdom)
    { 
        Kingdom = _Kingdom;
        SubKingdom = _SubKingdom;
    }
    ~Lamellar(){}
        void GetLam()
        {
            cout << "Подцарство - " << this->SubKingdom << endl;
        }
};

class Parasite :public Lamellar
{
protected:
    string Reproduction;
public:
    Parasite(string _Kingdom, string _SubKingdom, string _Reproduction) :Lamellar(_Kingdom, _SubKingdom)
    {
        Kingdom = _Kingdom;
            SubKingdom = _SubKingdom;
        Reproduction = _Reproduction;
    }
    ~Parasite (){}
    void GetRepr()
    {
        cout << "Способ размножения - " << this->Reproduction << endl;
    }
};

class Edible :public virtual Fungus
{
protected:
    string Habitat;
public:
    Edible(string _Kingdom, string _Habitat):Fungus(_Kingdom)
    {
        Kingdom = _Kingdom;
        Habitat = _Habitat;
    }
    ~Edible(){}
    void GetEd()
    {
        cout << "Среда обитания - " << this->Habitat << endl;
    }
};

class Drug :public Edible
{
protected:
    string BenFeatures;
public:
    Drug(string _Kingdom, string _Habitat, string _BenFeatures) :Edible(_Habitat, _Kingdom)
    {
        Kingdom = _Kingdom;
        Habitat = _Habitat;
        BenFeatures = _BenFeatures;
    }
    ~Drug() {}
    void GetFeat()
    {
        cout << "Полезные свойства - " << this->BenFeatures << endl;
    }
};

class TinderFungus :public Parasite, public Drug
{
protected:
    string Place;
public:
    TinderFungus(string _Kingdom, string _SubKingdom, string _Reproduction, string _Habitat, string _BenFeatures, string _Place)
        :Parasite(_Kingdom, _SubKingdom, _Reproduction), Drug(_Kingdom, _Habitat, _BenFeatures)
    {
        Place = _Place;
    }
    ~TinderFungus() {}
    void GetFunInf()
    {
        cout << "Царство гриба - " << this->Kingdom << endl;
        cout << "Подцарство - " << this->SubKingdom << endl;
        cout << "Способ размножения - " << this->Reproduction << endl;
        cout << "Среда обитания - " << this->Habitat << endl;
        cout << "Полезные свойства - " << this->BenFeatures << endl;
        cout << "Места произрастания - " << this->Place << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    TinderFungus TF("Базидиомицеты","Высшие грибы","Бесполое","Живые деревья","Бактерицидное, противовирусное","Европа и Азия");
    TF.GetFunInf();
    return 0;
}
