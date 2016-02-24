#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include "Map.h"
#include "Player.h"

using namespace std;

class Game
{
private:
	Map gameMap;

public:
	Game();

	void setupMap(bool defaultMap);
	void setupGame();
	void startGame(Player* player);

	void displayMenu();
	string getPlayerInput();

};

#endif