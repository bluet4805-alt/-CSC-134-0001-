// ============================================================================
//  M6LAB2: The Royal Palace
//  CSC 134 — Module 6: Arrays
// ============================================================================
//  AI Citation: Code assisted by Gemini (Google). 
//  Prompt: "Create C++ code for a 7-room palace with a specific T-shaped layout."
//
//  THE MAP
//  -------
//                             [ GARDEN ]
//                                 |
//                                 N
//                                 |
//  [ DINING HALL ] --E--    [ THRONE ROOM ]    --E--> [ SLEEPING CHAMBERS ]
//                                 |                          |
//                                 W                          S
//                           (back to Throne)                 |
//                                                    [ BATHING CHAMBERS ]
//                                                            |
//                                                            W
//                                                            |
//                                                      [ THE ENTRY ]
//
// ============================================================================

#include <iostream>
#include <string>

using namespace std;

// Direction constants
enum Direction {
    NORTH = 0, EAST = 1, SOUTH = 2, WEST = 3, NUM_DIRECTIONS = 4
};

// Room constants (Total: 7 rooms for A-Tier)
enum Room {
    ENTRY = 0, THRONE = 1, GARDEN = 2, DINING = 3, SLEEPING = 4, BATHING = 5, TREASURY = 6, NUM_ROOMS = 7
};

const int NO_CONNECTION = -1;

// Function Prototypes
void printRoom(const string names[], const string descriptions[], int room, const bool hasItem[], const string itemNames[]);
void printExits(int connections[][NUM_DIRECTIONS], int room);
int  commandToDirection(const string& command);

int main() {
    // Parallel Arrays for Room Data
    string roomNames[NUM_ROOMS] = {
        "The Grand Entry", "The Throne Room", "The Royal Garden", 
        "The Dining Hall", "Sleeping Chambers", "Bathing Chambers", "Hidden Treasury"
    };

    string roomDescriptions[NUM_ROOMS] = {
        "High marble pillars flank the entrance. This is the start of your journey.",
        "A massive gold throne sits at the far end. The floors are polished obsidian.",
        "Beautiful roses and fountains fill the air with a sweet scent.",
        "A long oak table is set for a feast. The candles are still burning.",
        "Silk curtains surround a massive bed. It feels quiet and private.",
        "Steam fills the room. A large stone tub sits in the center.",
        "Piles of gold coins and jewels glitter in the torchlight."
    };

    // A-Tier System: Item Pickup
    bool hasItem[NUM_ROOMS] = {false, false, false, false, false, false, true};
    string itemNames[NUM_ROOMS] = {"", "", "", "", "", "", "Royal Scepter"};
    bool inventoryHasScepter = false;

    // 2D Array Adjacency List
    int connections[NUM_ROOMS][NUM_DIRECTIONS];

    // Initialize all to -1
    for (int r = 0; r < NUM_ROOMS; r++) {
        for (int d = 0; d < NUM_DIRECTIONS; d++) connections[r][d] = NO_CONNECTION;
    }

    // Wiring your specific layout
    // 1. Entry connects to Throne Room
    connections[ENTRY][NORTH] = THRONE;
    connections[THRONE][SOUTH] = ENTRY;

    // 2. Throne Room is the hub
    connections[THRONE][NORTH] = GARDEN;
    connections[GARDEN][SOUTH] = THRONE;

    connections[THRONE][WEST] = DINING;
    connections[DINING][EAST] = THRONE;

    connections[THRONE][EAST] = SLEEPING;
    connections[SLEEPING][WEST] = THRONE;

    // 3. Sleeping connects to Bathing
    connections[SLEEPING][SOUTH] = BATHING;
    connections[BATHING][NORTH] = SLEEPING;

    // 4. Bathing connects to Treasury (Hidden Room)
    connections[BATHING][EAST] = TREASURY;
    connections[TREASURY][WEST] = BATHING;

    int currentRoom = ENTRY;
    bool running = true;

    cout << "--- WELCOME TO THE PALACE ADVENTURE ---" << endl;
    cout << "Commands: n, s, e, w, look, take, quit" << endl;

    while (running) {
        printRoom(roomNames, roomDescriptions, currentRoom, hasItem, itemNames);
        printExits(connections, currentRoom);

        cout << "\n> ";
        string command;
        cin >> command;

        if (command == "quit" || command == "q") {
            running = false;
        } else if (command == "look" || command == "l") {
            continue; 
        } else if (command == "take" || command == "t") {
            if (hasItem[currentRoom]) {
                cout << "You picked up the " << itemNames[currentRoom] << "!" << endl;
                if (itemNames[currentRoom] == "Royal Scepter") inventoryHasScepter = true;
                hasItem[currentRoom] = false;
            } else {
                cout << "There is nothing here to take." << endl;
            }
        } else {
            int direction = commandToDirection(command);
            if (direction == -1) {
                cout << "Unknown command." << endl;
            } else {
                int next = connections[currentRoom][direction];
                if (next == NO_CONNECTION) {
                    cout << "You cannot go that way." << endl;
                } else {
                    currentRoom = next;
                }
            }
        }
    }

    cout << "Farewell, explorer." << endl;
    return 0;
}

// Function Definitions
void printRoom(const string names[], const string descriptions[], int room, const bool hasItem[], const string itemNames[]) {
    cout << "\n[ " << names[room] << " ]" << endl;
    cout << descriptions[room] << endl;
    if (hasItem[room]) {
        cout << "Something glitters here: A " << itemNames[room] << "." << endl;
    }
}

void printExits(int connections[][NUM_DIRECTIONS], int room) {
    const string dirNames[NUM_DIRECTIONS] = {"north", "east", "south", "west"};
    cout << "Exits: ";
    bool any = false;
    for (int d = 0; d < NUM_DIRECTIONS; d++) {
        if (connections[room][d] != NO_CONNECTION) {
            if (any) cout << ", ";
            cout << dirNames[d];
            any = true;
        }
    }
    if (!any) cout << "(none)";
    cout << endl;
}

int commandToDirection(const string& command) {
    if (command == "north" || command == "n") return NORTH;
    if (command == "east"  || command == "e") return EAST;
    if (command == "south" || command == "s") return SOUTH;
    if (command == "west"  || command == "w") return WEST;
    return -1;
}