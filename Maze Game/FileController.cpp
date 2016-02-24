#include "FileController.h"
#include <fstream>
#include <sstream>

FileController::FileController()
{

};

vector<string> FileController::getRoomNames()
{
	return roomNames;
};

vector<string> FileController::getConnections()
{
	return connections;
};

/*
Loads and parses data from the map.txt file, parsed data is stored in the roomNames and connections private variables
Parameters: None
*/
void FileController::parseFileData()
{
	string currLine;
	size_t position;
	string valueSeperator = ",";
	string linkSeperator = "-";

	try 
	{
		ifstream file("map.txt");
		if (file.is_open())
		{
			// Get line with each of the room names
			getline(file, currLine);
			string currRoom;
			// While the value seperating value can be found in the current line
			while ((position = currLine.find(valueSeperator)) != string::npos)
			{
				currRoom = currLine.substr(0, position); //cut out the name of the current room
				currLine.erase(0, position + valueSeperator.length()); //delete the current name from the full line
				roomNames.push_back(currRoom);
			}

			// Get line with each room link
			getline(file, currLine);
			while ((position = currLine.find(valueSeperator)) != string::npos)
			{
				string currLink = currLine.substr(0, position); //cut out the full link data
				currLine.erase(0, position + valueSeperator.length()); //delete the current link data from the full line
				connections.push_back(currLink);
			}

			file.close();
		}
	}
	catch (exception& e)
	{
		cout << "File could not be found! Ensure map.txt of the correct syntax is inside the working directory of the game!" << endl;
	}	
};