#pragma warning (disable: 4996)

#include "Sim.h"
#include "Game.h"
#include <iostream>
#include <cstring>
using namespace std;
char name[20];

int main()
{
	// first question checking
//Sim Jane, Dan("Dan"), Alona("Alona", 27, 90, 20);
//Jane.print(), Dan.print(), Alona.print();
	Game Sims(5);
	cout << "------Welcome to Sims Game------";
	int choice = 0;

	do
	{
		cout << endl;
		cout << "Choose your action:" << endl;
		cout << "1. Add New Sim" << endl
			<< "2. Action on existing Sim" << endl
			<< "3. Pass time" << endl
			<< "4. Print status" << endl
			<< "5. Exit" << endl
			<< endl;

		cin >> choice;
		switch (choice) {
		case 1:
		{
			cout << "Enter Sim Name:" << endl;
			cin >> name;
			Sim NewSim(name);
			Sims.addSim(NewSim);
			break;
		}
		case 2:
		{
			break;
		}
		case 3:
		{
			Sims.passTime();
			break;
		}
		case 4:
		{
			Sims.printSims();
		}
		case 5:
		{
			exit;
		}
		default:
		{
			cout << "Invalid choice." << endl;
			break;
		}
		}

		/*if (choice == 1)
		{
			cout << "Enter Sim Name:" << endl;

			cin >> name;
			Sim NewSim(name);
			Sims.addSim(NewSim);
		}
		if (choice == 3)
		{
			Sims.passTime();
		}
		if (choice == 4)
		{
			Sims.printSims();
		}*/

	} while (choice != 5);

		system("pause");
}