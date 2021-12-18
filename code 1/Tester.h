#pragma once

#include "Employee.h"

class Tester : public Employee
{
private:
	string m_Category;
public:
	Tester() {};

	Tester(int id, string name)
		: Employee{ id, name }
	{}

	void show() override;

	void input() override;
};
