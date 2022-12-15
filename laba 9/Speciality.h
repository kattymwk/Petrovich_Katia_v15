#pragma once
#include <iostream>
#include <string>
using namespace std;
namespace work
{

	class Speciality
	{
	private:
		string speciality;
		string placeOfStudy;
	public:
		Speciality();
		Speciality(string speciality, string placeOfStudy);
		~Speciality();
		void setSpeciality(string speciality);
		void setPlaceOfStudy(string placeOfStudy);
		void showInfo();
	};

}