#include "Tester.h"

void Tester::show()
{
	Employee::show();
	cout << "try code again: " << m_Category << endl;
}

void Tester::input()
{
	cout << "I am tester: " << '\n';
	Employee::input();

	cout << "enter category name: ";
	getline(cin, m_Category);
}
