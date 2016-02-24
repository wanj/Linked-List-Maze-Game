#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <algorithm>
#include "Room.h"

using namespace std;

class Player
{
	private:
		string* name;
		Room* currentRoom;

	public:
		Player(string playerName);

		string getName();
		void setName(string playerName);

		Room* getRoom();
		void setRoom(Room* room);

		string getRoomName();

		void moveRoom(string direction);

};

#endif