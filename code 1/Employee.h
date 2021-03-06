#pragma once
#include <iostream>
#include <string>

using namespace std;
class Employee
{
protected:
	string m_name;
	int m_id{ 0 };
	string m_email;

public:
	// constructors
	Employee() {};

	Employee(int id, string name)
		: m_id{ id }, m_name{ name }
	{}

	// 
	virtual void show();

	virtual void input();

	// getters, setters
	string getName();

};



