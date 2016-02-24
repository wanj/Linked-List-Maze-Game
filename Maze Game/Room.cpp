#include "Room.h"

Room::Room()
{

};

Room::Room(string roomName)
{
	name = new string;
	*name = roomName;

	north = NULL;
	east  = NULL;
	south = NULL;
	west  = NULL;
};

string Room::getName()
{
	return *name;
};

void Room::setName(string roomName)
{
	*name = roomName;
};

Room* Room::getNorth()
{
	return north;
};

void Room::setNorth(Room* roomP)
{
	north = roomP;
};

Room* Room::getEast()
{
	return east;
};

void Room::setEast(Room* roomP)
{
	east = roomP;
};

Room* Room::getSouth()
{
	return south;
};

void Room::setSouth(Room* roomP)
{
	south = roomP;
};

Room* Room::getWest()
{
	return west;
};

void Room::setWest(Room* roomP)
{
	west = roomP;
};

/*
Generates the Rooms that are connection the current room, used to output the available moveable directions to the player
Parameters: None
*/
string Room::getConnectionString()
{
	vector<string> connections;
	string connectionsString = "There appears to be a passage: ";

	if (north != NULL)
	{
		connections.push_back("North");
	}
	if (east != NULL)
	{
		connections.push_back("East");
	}
	if (south != NULL)
	{
		connections.push_back("South");
	}
	if (west != NULL)
	{
		connections.push_back("West");
	}

	for (int i = 0; i < connections.size(); i++)
	{
		string temp;

		if (i == connections.size() - 1 || connections.size() == 1)
		{
			temp = connections.at(i) + ".";
		}
		else
		{
			temp = connections.at(i) + ", ";
		}
		
		connectionsString.append(temp);
	}
	
	return connectionsString;
};
