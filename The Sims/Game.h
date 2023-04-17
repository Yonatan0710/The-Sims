#ifndef __GAME_H
#define __GAME_H

#include "Sim.h"
#include <iostream>

class Game
{
	Sim** simsList;
	int MaxSims;
	int	NumOfSims;
public:
	// constructor
	Game(int MaxSims);
	Game(const Game& game);
	~Game();
	// setters 

	// getters

	// methods
	void addSim(const Sim& sim);
	void passTime();
	void printSims() const;
};


#endif