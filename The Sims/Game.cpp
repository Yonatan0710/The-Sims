#include "Game.h"
#include <iostream>
#include<stdlib.h>
#include <cstdlib>
#include <ctime>


using namespace std;

// constructors //
Game::Game(int MaxSims)
{
	this->NumOfSims = 0;
	this->MaxSims = MaxSims;
	simsList = new Sim * [MaxSims];
}
Game::Game(const Game& game)
{
	simsList = game.simsList;
	MaxSims = game.MaxSims;
	NumOfSims = game.NumOfSims;
}
Game::~Game()
{
	cout << "i am in the ~Game" << endl;
	int i;
	for (i = 0; i < MaxSims; i++) {
		delete simsList[i];
	}
	delete[] simsList;
}
// methods //

void Game::addSim(const Sim& sim)
{
	if ((1 + NumOfSims) <= MaxSims) {

		simsList[NumOfSims] = new Sim();
		*(simsList[NumOfSims]) = sim;
		NumOfSims++;

	}
	else { cout << "not enough space" << endl; }
}

void Game::passTime()
{
	srand(time(0));
	for (int i = 0; i < NumOfSims; i++)
	{
		simsList[i]->AgeUp();
		simsList[i]->setEnergy(simsList[i]->getEnergy() - (rand() % 15 + 1));
		simsList[i]->setHunger(simsList[i]->getHunger() - (rand() % 15 + 1));
	}
}


void Game::printSims() const
{
	cout << "In the city Allowed only " << MaxSims << " sims" << endl;
	for (int i = 0; i < NumOfSims; i++)
	{
		simsList[i]->print();
	}

}
