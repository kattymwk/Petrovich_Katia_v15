#pragma once
#include <iostream>
#include <string>

using namespace std;

namespace work
{
	class JobTitle
	{
	private:
		string jobTitle;
	public:
		JobTitle();
		JobTitle(string jobTitle);
		~JobTitle();
		void setJobTitle(string jobTitle);
		void showInfo();
	};
}