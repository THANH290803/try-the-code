#include <iostream>
#include <vector>
#include <fstream>

#include "Employee.h"
#include "Programmer.h"
#include "Tester.h"
#include "Manager.h"
#include "Utils.h"

#include <algorithm> // for std::sort()

void showMenu() {
	cout << "-------------------Menu------------------------" << '\n';
	cout << "1. Add employee" << '\n';
	cout << "2. Edit employee" << '\n';
	cout << "3. Remove employee" << '\n';
	cout << "4. Sort employee by name" << '\n';
	cout << "5. Show all employees" << '\n';
	cout << "0. Exit" << '\n';
	cout << "-----------------------------------------------" << '\n';
	cout << "Please choose: ";
}

void showAll(vector<Employee*> list) {
	for (auto e : list) {
		e->show();
	}
}

void showAddMenu() {
	cout << "----------------------staff selection------------------------" << '\n';
	cout << "1 Programming staff" << '\n';
	cout << "2 Test staff" << '\n';
	cout << "3 Management staff" << '\n';
	cout << "0 Exit" << '\n';
	cout << "-------------------------------------------------------------" << '\n';
}

void Addemployee(vector<Employee*>& list) {
	int choose;
	showAddMenu();

	bool exit{ false };

	while (true)
	{
		cin >> choose;
		switch (choose)
		{
		case 1: {
			Employee* e{ new Programmer{} };

			e->input();

			list.push_back(e);
		}
			  break;

		case 2: {
			Employee* e{ new Tester{} };

			e->input();

			list.push_back(e);
		}
			  break;

		case 3: {
			Employee* e{ new Manager{} };

			e->input();

			list.push_back(e);
		}
			  break;

		case 0:
			exit = true;
			break;
		}

		if (exit) {
			break;
		}
		showAddMenu();
	}
}

Employee* findByName(vector<Employee*>& list, string name) {
	for (auto e : list) {
		if (e->getName().compare(name) == 0) {
			return e;
		}

		return nullptr;
	}


	void editEmployee(vector<Employee*>&list, string name) {
		auto e = findByName(list, name);

		e->input();
	}


	void removeEmployee(vector<Employee*>&list, string name) {
		auto e = findByName(list, name);

		auto index = std::find(list.begin(), list.end(), e);

		list.erase(index);
	}






	int main()
	{
		//Employee* e{ new Employee() };

		//e->input();

		//e->show();

		//Employee* p{ new Programmer() };
		//Employee* t{ new Tester() };
		//Employee* m{ new Manager() };
		/*
		vector<int> numbers{ 1, 2, 3 };
		cout << numbers[0] << '\n';
		cout << numbers.at(1) << '\n';

		numbers.push_back(4);
		cout << numbers.at(3);
		*/
		//vector<Employee*> list{};

		//list.push_back(e);
		//list.push_back(p);
		//list.push_back(t);
		//list.push_back(m);

		//for (int i{ 0 }; i < list.size(); ++i) {
		//	list.at(i)->input();
		//}

		//for (Employee* e : list) {
		//for (auto e : list) {
		//	e->show();
		//}

		vector<Employee*> list{};
		ifstream fileIn{ "input.txt" };

		// doc du lieu tu file
		string line;
		while (getline(fileIn, line)) {

			auto vec = Utils::split(line, ",");

			if (vec.at(0) == "1")
			{
				list.push_back(new Programmer{ stoi(vec.at(1)), vec.at(2) });
			}
			else if (vec.at(0) == "2")
			{
				list.push_back(new Tester{ stoi(vec.at(1)), vec.at(2) });
			}
			else if (vec.at(0) == "3")
			{
				list.push_back(new Manager{ stoi(vec.at(1)), vec.at(2) });
			}
		}

		//for (auto e : list) {
		//	e->show();
		//}
		int choose;
		bool exit{ false };

		string name;

		showMenu();
		while (true)
		{
			cin >> choose;
			cin.ignore(100, '\n');
			switch (choose)
			{
			case 1:
				cout << "Add employee" << '\n';
				Addemployee(list);
				break;
			case 2:
			{
				cout << "Edit employee" << '\n';
				cout << "Enter name: ";
				getline(cin, name);
				//Editemployee(list, name);
				for (auto e : list) {
					if (e->getName().compare(name) == 0) {
						e->input();
						break;
					}
				}
			}
			break;
			case 3:
			{
				cout << "Remove employee" << '\n';
				cout << "Enter name: ";
				getline(cin, name);
				//removeEmployee(list, name);
				for (auto e : list) {
					if (e->getName().compare(name) == 0) {
						auto index = std::find(list.begin(), list.end(), e);
						list.erase(index);
						break;
					}
				}
			}
			break;
			case 4:
				cout << "Sort by name" << '\n';
				std::sort(
					list.begin(),
					list.end(),
					[](const auto& e1, const auto& e2) {return e1->getName() < e2->getName(); }
				);
				showAll(list);
				break;
			case 5:
				cout << "Show all employees" << '\n';
				showAll(list);
				break;
			case 0:
				cout << "Exit" << '\n';
				exit = true;
				break;
			}
			if (exit) {
				break;
			}
			showMenu();
		}

	}