#include "Speciality.h"

work::Speciality::Speciality() {
	cout << "����������� Speciality" << endl;
	speciality = "��� ������";
	placeOfStudy = "��� ������";
}

work::Speciality::Speciality(string speciality, string placeOfStudy)
{
	cout << "����������� Speciality" << endl;
	this->speciality = speciality;
	this->placeOfStudy = placeOfStudy;
}

work::Speciality::~Speciality()
{
	cout << "���������� Speciality" << endl;
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
	cout << "�������������: " << speciality << "\n����� ��������: " << placeOfStudy << endl;
}
