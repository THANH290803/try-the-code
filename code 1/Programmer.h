#pragma once

#include "Employee.h"
class Programmer : public Employee
{
private:
	string m_ProgrammingLanguage;

public:
	Programmer() {}

	Programmer(int id, string name)
		: Employee{ id, name }
	{}

	virtual void show();
	virtual void input();


};


