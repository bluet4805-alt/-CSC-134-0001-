// M7HW1
// Blue 
// 5-4-26

// I used my codes of the palace exploration and my adventure story as the base codes and worked with Gemini to 
// combine the two into a storymode gameplay

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// --- CONSTANTS & ENUMS ---
enum Direction { NORTH, EAST, SOUTH, WEST, NUM_DIRECTIONS };
const int NO_CONNECTION = -1;

// System Prompt Helper
void systemPrompt(string msg) {
    cout << "\n[SYSTEM]: " << msg << endl;
}

// Navigation Helper
int commandToDirection(const string& command) {
    if (command == "north" || command == "n") return NORTH;
    if (command == "east"  || command == "e") return EAST;
    if (command == "south" || command == "s") return SOUTH;
    if (command == "west"  || command == "w") return WEST;
    return -1;
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
    cout << endl;
}

// --- STORY AREA 1: THE MAGIC FOREST ---
void exploreForest() {
    cout << "\nYour heavy armor clanks as you step onto the soft moss of the Whispering Woods." << endl;
    cout << "The canopy is so thick that it feels like twilight, even at noon." << endl;

    const int NUM_FOREST_ROOMS = 4;
    string names[NUM_FOREST_ROOMS] = {"Forest Entrance", "Overgrown Thicket", "Ancient Clearing", "Wizard's Hut"};
    string desc[NUM_FOREST_ROOMS] = {
        "The trees are dense here. You hear faint whispering in the wind.",
        "Thorny vines block the light. A glint of polished wood catches your eye.",
        "A circle of glowing mushrooms. The air smells of ozone and ancient magic.",
        "A crooked shack made of living oak. Smoke curls from the chimney."
    };

    bool hasWand[NUM_FOREST_ROOMS] = {false, true, false, false};
    bool inventoryHasWand = false;
    int connections[NUM_FOREST_ROOMS][NUM_DIRECTIONS];

    // Wire Forest
    for(int i=0; i<4; i++) for(int j=0; j<4; j++) connections[i][j] = NO_CONNECTION;
    connections[0][NORTH] = 1; connections[1][SOUTH] = 0;
    connections[1][EAST]  = 2; connections[2][WEST]  = 1;
    connections[2][NORTH] = 3; connections[3][SOUTH] = 2;

    int current = 0;
    while (true) {
        cout << "\n--- " << names[current] << " ---" << endl;
        cout << desc[current] << endl;
        printExits(connections, current);
        if (hasWand[current]) cout << "Resting in the thorns is a Wizard's Wand!" << endl;

        cout << "\n(n/s/e/w/take) > ";
        string cmd; cin >> cmd;

        if (cmd == "take" || cmd == "t") {
            if (hasWand[current]) {
                systemPrompt("You just picked up a Wand");
                inventoryHasWand = true;
                hasWand[current] = false;
            } else cout << "There is nothing here to take." << endl;
        } else {
            int d = commandToDirection(cmd);
            if (d != -1 && connections[current][d] != NO_CONNECTION) {
                current = connections[current][d];
                if (current == 3 && inventoryHasWand) break; 
            } else cout << "The trees seem to block your path that way." << endl;
        }

        if (current == 3 && !inventoryHasWand) {
            cout << "The hut is locked by a magical seal. You sense you need an offering to enter." << endl;
            current = 2; 
        }
    }

    // Wizard Interaction
    cout << "\nYou enter the hut. A Wizard with a beard down to his knees looks up." << endl;
    cout << "'My wand!' he cries. 'I feared it was lost to the brambles forever!'" << endl;
    cout << "\nDo you:\n1. Hand over the wand with honor.\n2. Attempt to steal the wand from the old man." << endl;
    cout << "> ";
    int choice; cin >> choice;

    if (choice == 2) {
        cout << "\nThe Wizard's eyes glow blue. 'You chose poorly, Knight!'" << endl;
        cout << "Your feet sink into the dirt. Your arms become branches." << endl;
        cout << "You are now a tree, guarding this forest until the end of time." << endl;
        cout << "\n--- GAME OVER ---" << endl;
        exit(0);
    } 

    cout << "\n'For your honesty, I shall give you what I have guarded for centuries,' the Wizard says." << endl;
    cout << "He reaches into his robes and pulls out a shimmering gold pendant." << endl;
    
    systemPrompt("You just picked up a Magic Pendant");
    cout << "The Wizard smiles. 'This pendant holds the power of the stars. It grants three wishes.'" << endl;
    cout << "You thank the Wizard and depart the forest, the pendant glowing warmly against your armor." << endl;
}

// --- STORY AREA 2: THE DISTANT REALM ---
void exploreRealm() {
    cout << "\nYou charter a ship and sail beyond the maps of men." << endl;
    cout << "The sky turns purple as you enter the Dangerous Waters." << endl;

    const int NUM_WATER_ROOMS = 3;
    string names[NUM_WATER_ROOMS] = {"The Open Sea", "The Jagged Reef", "The Hidden Portal"};
    string desc[NUM_WATER_ROOMS] = {
        "The waves are high here. You must find the runes to reveal the path.",
        "The rocks here look like dragon teeth. Runes are carved into the salt-crusted stone.",
        "A wall of shimmering mist stands before you, blocking the way to the Realm."
    };

    bool hasWords[NUM_WATER_ROOMS] = {false, true, false};
    bool inventoryHasWords = false;
    int connections[NUM_WATER_ROOMS][NUM_DIRECTIONS];

    for(int i=0; i<3; i++) for(int j=0; j<4; j++) connections[i][j] = NO_CONNECTION;
    connections[0][EAST] = 1; connections[1][WEST] = 0;
    connections[1][NORTH] = 2; connections[2][SOUTH] = 1;

    int current = 0;
    while (true) {
        cout << "\n--- " << names[current] << " ---" << endl;
        cout << desc[current] << endl;
        printExits(connections, current);
        if (hasWords[current]) cout << "Glowing Magic Words are etched into the reef!" << endl;

        cout << "\n(n/s/e/w/take) > ";
        string cmd; cin >> cmd;

        if (cmd == "take" || cmd == "t") {
            if (hasWords[current]) {
                systemPrompt("You just picked up the Magic Words");
                inventoryHasWords = true;
                hasWords[current] = false;
            }
        } else {
            int d = commandToDirection(cmd);
            if (d != -1 && connections[current][d] != NO_CONNECTION) {
                current = connections[current][d];
                if (current == 2 && inventoryHasWords) break;
            } else cout << "The treacherous currents push you back." << endl;
        }

        if (current == 2 && !inventoryHasWords) {
            cout << "The mist is impenetrable. You need the words to clear the fog." << endl;
            current = 1; 
        }
    }

    cout << "\nYou speak the Magic Words. The mist parts, revealing a kingdom of glass and light!" << endl;
    cout << "An intimidating team of armored Guardians meets you at the gate." << endl;
    cout << "\nDo you:\n1. Fight the Guardians to take what you came for.\n2. Tell them the truth: you seek the treasure to save the kingdom." << endl;
    cout << "> ";
    int choice; cin >> choice;

    if (choice == 1) {
        cout << "\nYou are a great warrior, but the Guardians are legion." << endl;
        cout << "You are overwhelmed and thrown into a cold dungeon." << endl;
        cout << "\n--- GAME OVER ---" << endl;
        exit(0);
    }

    cout << "\nThe Guardians lower their spears. 'Truth is rare in this world. Follow us.'" << endl;
    cout << "They lead you to the heart of the realm where the treasure waits." << endl;
    systemPrompt("You just picked up the Magical Treasure");

    cout << "\nOne final test remains. Do you:\n1. Steal the treasure and flee into the night.\n2. Vow to be their ally and protect the peace together." << endl;
    cout << "> ";
    cin >> choice;

    if (choice == 1) {
        systemPrompt("You have gained the most powerful enemies you have ever faced.");
    } else {
        cout << "You return home as a hero with a powerful alliance!" << endl;
    }
}

// --- MAIN STORY CONTROLLER ---
int main() {
    cout << "--- THE KNIGHT'S QUEST ---" << endl << endl;
    cout << "You are a Knight, respected by the Kingdom and feared by your foes." << endl;
    cout << "News of a magical treasure has reached your ears. You must find it before evil does." << endl; 

    cout << "\nWhere will your journey lead you first?" << endl;
    cout << "1. The Magic Forest" << endl;
    cout << "2. The Distant Realm" << endl;
    cout << "\nChoice > ";
    int start; cin >> start;

    if (start == 1) {
        exploreForest();
    } else if (start == 2) {
        exploreRealm();
    } else {
        cout << "\nYou hesitated too long. The kingdom falls." << endl;
    }

    cout << "\n--- MISSION COMPLETE ---" << endl;
    return 0;
}