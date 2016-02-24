#include "Map.h"
#include "Room.h"

Map::Map()
{
	start = NULL;
	end   = NULL;
};

Room* Map::getStart()
{
	return start;
};

void Map::setStart(Room* room)
{
	start = room;
};

Room* Map::getEnd()
{
	return end;
};

void Map::setEnd(Room* room)
{
	end = room;
};

void Map::addStartRoom(Room* newRoom)
{
	start = newRoom;
	end = newRoom;
};

/*
Sets up the game map
Parameters: source      (Room*)  - The 'source' room object the link originates from
			destination (Room*)  - The 'destination' room object that the link will lead to
			direction   (string) - The direction the new room will be from the source room 
*/
void Map::addLink(Room* source, Room* destination, string direction)
{
	if (direction == "NORTH")
	{
		source->setNorth(destination);
		destination->setSouth(source);
	}
	else if (direction == "EAST")
	{
		source->setEast(destination);
		destination->setWest(source);
	}
	else if (direction == "SOUTH")
	{
		source->setSouth(destination);
		destination->setNorth(source);
	}
	else if (direction == "WEST")
	{
		source->setWest(destination);
		destination->setEast(source);
	}
};