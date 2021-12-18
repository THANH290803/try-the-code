#include "Manager.h"

Manager::Manager()
    : Employee{}
{
}

Manager::Manager(int id, string name)
    : Employee{ id, name }
{
}

void Manager::input()
{
    cout << "I am manager: " << '\n';
    Employee::input();

    cout << "Enter year of experience: " << '\n';
    cin >> m_yoe;
}

void Manager::show()
{

    Employee::show();

    cout << "I am manager, i have " << m_yoe << " year of experience" << '\n';
}
