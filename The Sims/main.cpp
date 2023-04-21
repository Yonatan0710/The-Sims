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
		case 1:  // case 1: Add new Sim to the game
		{
			if (Sims.getNumOfSims() < Sims.getMaxSims()) //checking if there enough space in Sims
			{
				cout << "Enter new Sim Name:" << endl;
				cin >> name;
				Sim* newSim = new Sim(name);
				Sims.addSim(newSim);
			}
			else
			{
				cout << "not enough space" << endl;
			}
			break;
		}
		case 2:  // case 2: Perform actions on existing Sims
		{
			int action;
			cout << "Choose Sim by name:" << endl;
			cin >> name;
			Sim* toFind = Sims.findSim(name);
			if (toFind != nullptr)
			{
				
					cout << "Choose action:" << endl;
					cout << "1.eat" << endl
						<< "2.sleep" << endl
						<< "3.age up" << endl
						<< "4.go back to previous menu" << endl;

					cin >> action;
					switch (action)
					{
					case 1:  // Perform the "eat" action on a Sim
					{
						toFind->eat();
						cout << toFind->getName() << " ate" << endl;
						Sims.printSims();
						break;
					}
					case 2:  // Perform the "sleep" action on a Sim
					{
						toFind->sleep();
						cout << toFind->getName() << " slept" << endl;
						Sims.printSims();
						break;
					}

					case 3:  // Advance the age of a Sim by one year
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
				
				break;
			}
			else
			{
				break;
			}
			break;
		}
		case 3: // case 3: Pass time in the game

		{
			Sims.passTime();
			break;
		}
		case 4:  // case 4: Print status of all Sims in the game
		{
			Sims.printSims();
			break;
		}
		case 5:  // case 5: Exit the game
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