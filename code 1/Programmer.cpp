#include "Programmer.h"

void Programmer::show()
{
	Employee::show();
	cout << "I am programmer, i write code: " << m_ProgrammingLanguage << endl;
}

void Programmer::input()
{
	cout << "I am programmer: " << '\n';
	Employee::input();

	cout << "Enter programmer language: ";
	getline(cin, m_ProgrammingLanguage);
}


