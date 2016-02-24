#include "Player.h"
#include "Room.h"

Player::Player(string playerName)
{
	name = new string;
	*name = playerName;
};

string Player::getName()
{
	return *name;
};

void Player::setName(string playerName)
{
	*name = playerName;
};

Room* Player::getRoom()
{
	return currentRoom;
};

void Player::setRoom(Room* room)
{
	currentRoom = room;
};

string Player::getRoomName()
{
	return currentRoom->getName();
};

/*
Changes the players objects currentRoom variable and validates the movement direction
Parameters: directon (string) - The direction the new room will be from the existing room
*/
void Player::moveRoom(string direction)
{
	transform(direction.begin(), direction.end(), direction.begin(), toupper);

	if (direction == "N" && currentRoom->getNorth() != NULL)
	{
		cout << "You move North on the map." << endl;
		Room* tempRoom = currentRoom;
		currentRoom = tempRoom->getNorth();
	}
	else if (direction == "E" && currentRoom->getEast() != NULL)
	{
		cout << "You move East on the map." << endl;
		Room* tempRoom = currentRoom;
		currentRoom = tempRoom->getEast();
	}
	else if (direction == "S" && currentRoom->getSouth() != NULL)
	{
		cout << "You move South on the map." << endl;
		Room* tempRoom = currentRoom;
		currentRoom = tempRoom->getSouth();
	}
	else if (direction == "W" && currentRoom->getWest() != NULL)
	{
		cout << "You move West on the map." << endl;
		Room* tempRoom = currentRoom;
		currentRoom = tempRoom->getWest();
	}
	else
	{
		cout << "Cannot move that direction!" << endl;
	}
};