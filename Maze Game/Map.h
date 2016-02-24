#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <string>
#include "Room.h"

using namespace std;

class Map
{
private:
	Room* start;
	Room* end;

public:
	Map();

	Room* getStart();
	void setStart(Room* room);
	Room* getEnd();
	void setEnd(Room* room);

	void addStartRoom(Room* newRoom);
	void addRoom(Room* newRoom, Room* existingRoom, string direction);
	void addLink(Room* source, Room* destination, string direction);

};

#endif