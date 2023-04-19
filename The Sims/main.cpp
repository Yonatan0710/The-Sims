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
			if (Sims.getNumOfSims() >= Sims.getMaxSims())
			{
				cout << "not enough space" << endl;
			}
			else
			{
				cout << "Enter Sim Name:" << endl;
				cin >> name;
				Sim* newSim = new Sim(name);
				Sims.addSim(newSim);
			}
			break;
		}
		case 2:
		{
			int action;
			cout << "Choose Sim by name:" << endl;
			cin >> name;

			Sim* toFind = Sims.findSim(name);
			if (toFind != nullptr)
			{
				do
				{
					cout << "Choose action:" << endl;
					cout << "1.eat" << endl
						<< "2.sleep" << endl
						<< "3.age up" << endl
						<< "4.go back to previous menu"<<endl;

					cin >> action;
					switch (action)
					{
					case 1:
					{
						toFind->eat();
						cout << toFind->getName() << " ate" << endl;
						Sims.printSims();
						break;
					}
					case 2:
					{
						toFind->sleep();
						cout << toFind->getName() << " slept" << endl;
						Sims.printSims();
						break;
					}
					case 3:
					{
						toFind->AgeUp();
						cout << toFind->getName() << " aged up by 1 year" << endl;
						Sims.printSims();
						break;
					}
					case 4:
					{
						break;
					}
					default:
					{
						cout << "Invalid choice Please enter a number from 1 to 4." << endl;
						break;;
					}
					}
				} while (action != 4);
			}
			else
			{
				break;
			}
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
			break;
		}
		case 5:
		{
			return 0;
		}
		default:
		{
			cout << "Invalid choice Please enter a number from 1 to 5." << endl;
			break;
		}
		}
	} while (choice != 5);
}