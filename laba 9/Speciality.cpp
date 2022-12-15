#include "Speciality.h"

work::Speciality::Speciality() {
	cout << "конструктор Speciality" << endl;
	speciality = "нет данных";
	placeOfStudy = "нет данных";
}

work::Speciality::Speciality(string speciality, string placeOfStudy)
{
	cout << "конструктор Speciality" << endl;
	this->speciality = speciality;
	this->placeOfStudy = placeOfStudy;
}

work::Speciality::~Speciality()
{
	cout << "деструктор Speciality" << endl;
}

void work::Speciality::setSpeciality(string speciality)
{
	this->speciality = speciality;
}

void work::Speciality::setPlaceOfStudy(string placeOfStudy)
{
	this->placeOfStudy = placeOfStudy;
}

void work::Speciality::showInfo()
{
	cout << "специализация: " << speciality << "\nместо обучения: " << placeOfStudy << endl;
}
