// M6HW1
// Blue 
// 5-29-26
// ============================================================================
//  STORY: A traveler seeks shelter from a magical rainstorm and finds 
//  an abandoned palace that whispers of ancient secrets.
// ============================================================================
// Gemini assisted in correcting and helping add my storyline into the code 



#include <iostream>
#include <string>
#include <limits>
#include <ios>

using namespace std;

enum Direction { NORTH = 0, EAST = 1, SOUTH = 2, WEST = 3, NUM_DIRECTIONS = 4 };
enum Room { ENTRY = 0, THRONE = 1, GARDEN = 2, DINING = 3, SLEEPING = 4, BATHING = 5, TREASURY = 6, NUM_ROOMS = 7 };

const int NO_CONNECTION = -1;

void printRoom(const string names[], const string descriptions[], int room, bool hasItem, string itemName);
void printExits(int connections[][NUM_DIRECTIONS], int room);
int  commandToDirection(const string& command);

int main() {
    // --- INTRO STORY ---
    cout << "==================================================================" << endl;
    cout << "You wake up on the cold ground of an unfamiliar land, surrounded" << endl;
    cout << "by towering, ancient trees." << endl;
    cout << "\nSuddenly, a massive rumble of thunder shakes the earth. You look" << endl;
    cout << "overhead to see clouds turning purple. In what feels" << endl;
    cout << "like seconds, you are being drenched with freezing, magical rain." << endl;
    cout << "\nPanic sets in as the rain begins to sting. You run blindly through" << endl;
    cout << "the treeline looking for cover until you see it: a massive, " << endl;
    cout << "abandoned palace looming in the mist. You dive through the heavy" << endl;
    cout << "doors just as the storm reaches its peak." << endl;
    cout << "==================================================================" << endl;
   
    // --- DATA SETUP ---
    string roomNames[NUM_ROOMS] = {
        "The Rain-Drenched Entry", "The Echoing Throne Room", "The Overgrown Garden", 
        "The Dust-Covered Dining Hall", "The Silent Sleeping Chambers", "The Steaming Bathing Chambers", "The Heart of the Palace"
    };

    string roomDescriptions[NUM_ROOMS] = {
        "Marble pillars reach toward a dark ceiling. A stone tablet reads: 'Bring the Scepter to the Heart to end the storm.'",
        "A massive gold throne sits empty. The shadows here seem to move when you aren't looking.",
        "Magical flowers glow faintly through the rain. The smell of ozone and roses is thick here.",
        "A long table is set for a feast that never happened. The air is stale and cold.",
        "Silk curtains flutter. A silver chest lies open at the foot of the bed.",
        "Steam fills the air from a large stone basin. To the East, a heavy door hums with visible purple energy.",
        "The room is filled with a warm, blinding light. The pedestal in the center is waiting."
    };

    bool roomHasItem[NUM_ROOMS] = {false, false, false, false, true, false, false}; 
    string itemNames[NUM_ROOMS] = {"", "", "", "", "Whispering Scepter", "", ""};
    bool inventoryHasScepter = false;

    int connections[NUM_ROOMS][NUM_DIRECTIONS];
    for (int r = 0; r < NUM_ROOMS; r++) {
        for (int d = 0; d < NUM_DIRECTIONS; d++) connections[r][d] = NO_CONNECTION;
    }

    // Wiring
    connections[ENTRY][NORTH]    = THRONE;
    connections[THRONE][SOUTH]   = ENTRY;
    connections[THRONE][NORTH]   = GARDEN;
    connections[GARDEN][SOUTH]   = THRONE;
    connections[THRONE][WEST]    = DINING;
    connections[DINING][EAST]    = THRONE;
    connections[THRONE][EAST]    = SLEEPING;
    connections[SLEEPING][WEST]  = THRONE;
    connections[SLEEPING][SOUTH] = BATHING;
    connections[BATHING][NORTH]  = SLEEPING;
    connections[BATHING][EAST]   = TREASURY; 
    connections[TREASURY][WEST]  = BATHING;

    int currentRoom = ENTRY;
    bool running = true;
    string command;

    cout << "\nCommands: n, s, e, w, take, look, quit" << endl;

    while (running) {
        printRoom(roomNames, roomDescriptions, currentRoom, roomHasItem[currentRoom], itemNames[currentRoom]);
        
        // --- WIN CONDITION ---
        if (currentRoom == TREASURY) {
            cout << "\nAs you step forward, the Scepter pulses with light." << endl;
            cout << "You place it upon the pedestal. The whispering stops, and the storm outside clears." << endl;
            cout << "\n*** MISSION COMPLETE: THE PALACE IS AT PEACE ***" << endl;
            break; 
        }

        printExits(connections, currentRoom);

        cout << "\n> ";
        cin >> command;

        if (command == "quit" || command == "q") {
            running = false;
        } else if (command == "take" || command == "t") {
            if (roomHasItem[currentRoom]) {
                cout << "\n>> You pick up the " << itemNames[currentRoom] << "!" << endl;
                cout << ">> It feels warm. A faint whisper echoes: '...the Heart... unlock the door...'" << endl;
                inventoryHasScepter = true;
                roomHasItem[currentRoom] = false;
            } else {
                cout << "\n>> There is nothing here to take." << endl;
            }
        } else if (command == "look" || command == "l") {
            continue; 
        } else {
            int dir = commandToDirection(command);
            if (dir == -1) {
                cout << "\n>> I don't understand that command." << endl;
            } else {
                int next = connections[currentRoom][dir];
                if (next == NO_CONNECTION) {
                    cout << "\n>> You cannot go that way." << endl;
                } else if (next == TREASURY && !inventoryHasScepter) {
                    cout << "\n>> The door is sealed by a magical barrier. It rejects you." << endl;
                    cout << ">> You feel a powerful energy. It seems to require a key..." << endl;
                } else {
                    currentRoom = next;
                }
            }
        }
    }

    cout << "\nFarewell, traveler." << endl;
    return 0;
}

void printRoom(const string names[], const string descriptions[], int room, bool hasItem, string itemName) {
    cout << "\n------------------------------------------------------------------" << endl;
    cout << "LOCATION: " << names[room] << endl;
    cout << descriptions[room] << endl;
    
    if (hasItem) {
        cout << "\n[!] Something glitters on the floor: A " << itemName << "." << endl;
        // NEW HINT ADDED HERE
        cout << ">> (Type 't' or 'take' to pick up the " << itemName << "!)" << endl;
    }
}

void printExits(int connections[][NUM_DIRECTIONS], int room) {
    const string dirNames[NUM_DIRECTIONS] = {"north", "east", "south", "west"};
    cout << "EXITS: ";
    bool first = true;
    for (int d = 0; d < NUM_DIRECTIONS; d++) {
        if (connections[room][d] != NO_CONNECTION) {
            if (!first) cout << ", ";
            cout << dirNames[d];
            first = false;
        }
    }
    cout << endl;
}

int commandToDirection(const string& command) {
    if (command == "n" || command == "north") return NORTH;
    if (command == "e" || command == "east")  return EAST;
    if (command == "s" || command == "south") return SOUTH;
    if (command == "w" || command == "west")  return WEST;
    return -1;
}