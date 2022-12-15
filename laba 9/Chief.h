#pragma once
#include "Employee.h"

namespace work
{
    class Chief : public Employee {
    private:
        int yearsOnPost;
    public:
        Chief();
        Chief(string name, int age, int salary, int yearOnPost, string speciality, string placeOfStudy,
            string nameOfDeparment, int workingArea);
        ~Chief();
        void showInfo();
    };
}