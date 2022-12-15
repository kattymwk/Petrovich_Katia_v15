#pragma once
#include "Human.h"
#include "Department.h"
#include "Speciality.h"
#include "JobTitle.h"
namespace work
{
	class Employee : public Human
	{
	private:
		int salary;
		JobTitle jobTitle;
		Speciality speciality;
		Department department;
	public:
		Employee();
		Employee(string _name, int _age, int _salary, string _jobTitle, string _speciality, string _placeOfStudy,
			string _nameOfDeparment, int _workingArea);
		~Employee();
		void showInfo();

	};
}