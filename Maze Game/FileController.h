#ifndef FILECONTROLLER_H
#define FILECONTROLLER_H

#include <iostream>
#include <string>
#include <vector>
#include "Room.h"

using namespace std;

class FileController
{
private:
	vector<string> roomNames;
	vector<string> connections;

public:
	FileController();

	vector<string> getRoomNames();
	vector<string> getConnections();

	void parseFileData();

};

#endif