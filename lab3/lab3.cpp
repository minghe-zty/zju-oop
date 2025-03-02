#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

// Structure for each room
struct Room {
    string name;
    map<string, int> exits;  // Map of exits and corresponding room index
};

// Function to print room information
void printRoomInfo(const Room& room) {
    cout << "Welcome to the " << room.name << ". There are " << room.exits.size() << " exits:";
    for (const auto& exit : room.exits) {
        cout << " " << exit.first;
    }
    cout << endl;
}

int main() {
    // Set up random seed
    srand(time(0));
	cout << "If you want to quit ,you only need to enter 'go exit'." << endl;
    // Define room types
    Room lobby {"Lobby", {{"east", 1}, {"west", 2}, {"up", 3}}};
    Room treasureRoom {"Treasure Room", {{"west", 0}, {"down", 4}}};
    Room monsterRoom {"Monster Room", {{"north", 0}, {"east", 3}}};
    Room tower {"Tower", {{"down", 0}, {"south", 2}}};
    Room dungeon {"kiwi room", {{"up", 1}}};

    // Define all rooms
    vector<Room> rooms {lobby, treasureRoom, monsterRoom, tower, dungeon};

    // Randomly assign princess and monster room
    int princessRoomIndex = rand() % rooms.size();
    int monsterRoomIndex = rand() % rooms.size();
    while (monsterRoomIndex == princessRoomIndex) {
        monsterRoomIndex = rand() % rooms.size();
    }

    // Main game loop
    int currentRoomIndex = 0; // Starting room is the lobby
    bool princessSaved = false;
    bool gameOver = false;

    while (!gameOver) {
        const Room& currentRoom = rooms[currentRoomIndex];
        printRoomInfo(currentRoom);

        // Check if princess is in the current room
        if (currentRoomIndex == princessRoomIndex && !princessSaved) {
            cout << "You found the princess! She is ready to leave with you." << endl;
            princessSaved = true;
        }

        // Check if monster is in the current room
        if (currentRoomIndex == monsterRoomIndex) {
            cout << "A monster has appeared! Game over." << endl;
            gameOver = true;
            break;
        }

        // Get user input
        string command;
        cout << "Enter your command: ";
        cin >> command;

        // Process user command
        if (command == "go") {
            string exit;
            cin >> exit;
            // Check if exit is valid
            auto it = currentRoom.exits.find(exit);
            if(exit == "exit"){
            	goto out;
			}
            if (it != currentRoom.exits.end()) {
                // Move to the next room
                currentRoomIndex = it->second;
            } else {
                cout << "Invalid exit." << endl;
            }
        } else {
            cout << "Invalid command." << endl;
        }
    }
	out:
    return 0;
}
