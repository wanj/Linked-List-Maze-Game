#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Room
{
	private:
		string* name;

		Room* north;
		Room* east;
		Room* south;
		Room* west;
		
	public:
		Room();
		Room(string roomName);
		
		string getName();
		void setName(string roomName);
		
		Room* getNorth();
		void setNorth(Room* roomP);
		
		Room* getEast();
		void setEast(Room* roomP);

		Room* getSouth();
		void setSouth(Room* roomP);

		Room* getWest();
		void setWest(Room* roomP);

		string getConnectionString();
};

#endif