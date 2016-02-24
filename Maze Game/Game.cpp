#include "Game.h"
#include "Player.h"
#include "Map.h"
#include "Room.h"
#include "FileController.h"

Game::Game()
{
	gameMap = Map();
};

/*
Sets up the game map
Parameters: defaultMap (bool) - If false custom map loading will be used
*/
void Game::setupMap(bool defaultMap)
{
	if (defaultMap)
	{
		Room* tempArray[12];
		string name = "Room ";
		// Holds the different letters for each room in the default maze
		string names[12] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L"};

		// Create each of the needed rooms
		for (int i = 0; i < 12; i++)
		{
			name = name.append(names[i]);
			Room* tempRoom = new Room(name);
			tempArray[i] = tempRoom;
			name = "Room ";
		}

		//add the start and end room
		gameMap.addStartRoom(tempArray[0]);
		gameMap.setEnd(tempArray[11]);

		//add  links between rooms
		gameMap.addLink(tempArray[0], tempArray[4], "SOUTH");  // a-e
		gameMap.addLink(tempArray[4], tempArray[8], "SOUTH");  // e-i
		gameMap.addLink(tempArray[8], tempArray[9], "EAST");   // i-j
		gameMap.addLink(tempArray[0], tempArray[1], "EAST");   // a-b
		gameMap.addLink(tempArray[1], tempArray[5], "SOUTH");  // b-f
		gameMap.addLink(tempArray[5], tempArray[6], "EAST");   // f-g
		gameMap.addLink(tempArray[6], tempArray[10], "SOUTH"); // g-k
		gameMap.addLink(tempArray[6], tempArray[2], "NORTH");  // g-c
		gameMap.addLink(tempArray[2], tempArray[3], "EAST");   // c-d
		gameMap.addLink(tempArray[6], tempArray[7], "EAST");   // g-h
		gameMap.addLink(tempArray[7], tempArray[11], "SOUTH"); // h-l
	}
	else
	{
		// Create a FileController object and parse the map.txt data, populates private vectors inside the object with data
		FileController controller;
		controller.parseFileData();

		// Get the data from the controller vector variables
		vector<string> nameVect = controller.getRoomNames();
		vector<string> connectionsVect = controller.getConnections();

		// Used to store the room objects for inital setup before creating a linked list
		vector<Room*> tempRoomVect;

		// Create empty room objects, nameVect.size() is used to determine how many rooms are needed
		for (int i = 0; i < nameVect.size(); i++)
		{
			Room* currentRoom = new Room(nameVect.at(i));
			tempRoomVect.push_back(currentRoom);
		}

		// Create the start and end of the maze
		gameMap.setStart(tempRoomVect.at(0));
		gameMap.setEnd(tempRoomVect.at(tempRoomVect.size() - 1));

		size_t position;
		string valueSeperator = "-";

		// Loop through each connection string inside the connectionsVect variable and parse each string
		for (int i = 0; i < connectionsVect.size(); i++)
		{
			string currentConnection = connectionsVect.at(i);
			
			// Find the first room name
			position = currentConnection.find(valueSeperator);
			string firstRoom = currentConnection.substr(0, position);
			currentConnection.erase(0, position + valueSeperator.length());

			// Fine the second room name
			position = currentConnection.find(valueSeperator);
			string secondRoom = currentConnection.substr(0, position);
			currentConnection.erase(0, position + valueSeperator.length());

			// The remaining string only contains the direction section of the string now
			string direction = currentConnection;

			int firstRoomIndex; 
			int secondRoomIndex;

			// Find the index of the rooms in the tempRoomVect variable
			for (int index = 0; index < tempRoomVect.size(); index++)
			{
				if (tempRoomVect.at(index)->getName() == firstRoom)
				{
					firstRoomIndex = index;
				}
				else if (tempRoomVect.at(index)->getName() == secondRoom)
				{
					secondRoomIndex = index;
				}
			}

			// Create a link between the two identified rooms 
			gameMap.addLink(tempRoomVect.at(firstRoomIndex), tempRoomVect.at(secondRoomIndex), direction);
		}
	}
};

void Game::setupGame()
{
	displayMenu();
};

/*
Contains Main game loop
Parameters: player (Player*) - The player object that will be used to interact with the game
*/
void Game::startGame(Player* player)
{
	bool playing = true;

	// Set the players start position to the start of the maze
	player->setRoom(gameMap.getStart());
	string currentMove;

	while (playing)
	{
		cout << "\nYou are currently standing in: " << player->getRoomName() << endl;
		cout << player->getRoom()->getConnectionString() << endl;
		cout << "Where would you like to move?: ";

		currentMove = getPlayerInput();
		if (currentMove == "q" || currentMove == "Q")
		{
			cout << "Quitting Game!" << endl;
			playing = false;
		}
		else
		{
			player->moveRoom(currentMove);

			// Checks if the player has finished the maze
			if (player->getRoom() == gameMap.getEnd())
			{
				cout << "\nWell done " << player->getName() << " you reached the end of the maze!" << endl;

				cout << "Would you like to play again? ";
				string playAgain = getPlayerInput();
				if (playAgain != "y")
				{
					playing = false;
				}
				else
				{
					player->setRoom(gameMap.getStart());
				}
			}
		}
	}
};

/*
Displays the main menu and handles the users input
Parameters: None
*/
void Game::displayMenu()
{
	cout << "Welcome to the maze game!\n" << endl;
	string name;
	cout << "Enter your name: ";
	cin >> name;
	Player* player = new Player(name);
	cout << "\nMenu:" << endl;
	cout << "1. Play (default map)\n2. Load Map" << endl;

	string menuInput = getPlayerInput();
	if (menuInput == "1")
	{
		setupMap(true);
		startGame(player);
	}
	else if (menuInput == "2")
	{
		setupMap(false);
		startGame(player);
	}
};

/*
Generic user input method to reduce code clutter
Parameters: None
*/
string Game::getPlayerInput()
{
	string input;
	cout << "> ";
	cin >> input;
	return input;
};

