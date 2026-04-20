// M6Lab2- Using Data Structures 
// Blue 
// 4-20-26

// I might add a short script for why we enter the palace 
// Throughout, I want to add more promps to make it more storylike 

// ============================================================================
//  M6LAB2: The Palace Map — Adjacency List Starter
//  CSC 134 — Module 6: Arrays
// ============================================================================
//
//  THE BIG IDEA
//  ------------
//  Our palace has 5 rooms. Rooms connect to neighbors via N / E / S / W.
//  We need a way to answer: "If I'm in room X and I move north, where do I
//  end up?"
//
//  The answer: an ADJACENCY LIST stored as a 2D array.
//      connections[fromRoom][direction] = destination room
//
//  We ALSO use PARALLEL ARRAYS to hold each room's name and description —
//  same index in every array points to the same room.
//
//
//  THE MAP
//  -------
//                          [ Garden ]
//                              |
//                              N
//                              |
//    [Dining Hall] --E-- [ Throne Room ] --E--> [ Sleeping Chambers ]
//                              |                    |
//                              W                    S
//                           (Entry)                 |
//                                               [ Batheing Chambers ]
//
//  Start: ENTRY. Explore with n / e / s / w. Type 'look' or 'quit'.
//
//
//  FUTURE REFACTOR NOTE
//  --------------------
//  Once we learn structs, rooms become a single struct with fields for
//  name, description, and exits. For now, parallel arrays keep everything
//  out in the open where we can see it.
// ============================================================================

#include <iostream>
#include <string>
using namespace std;

// ---------------------------------------------------------------------------
//  Named constants (enums). These make indexing READ like English:
//      connections[ENTRY][NORTH]   not   connections[0][0]
// ---------------------------------------------------------------------------
enum Direction {
    NORTH = 0,
    EAST  = 1,
    SOUTH = 2,
    WEST  = 3,
    NUM_DIRECTIONS = 4
};

enum Room {
    Throne_Room  = 0,
    Garden = 1,
    Sleeping_Chambers = 2,
    Dining_Hall  = 3,
    Washing_Chambers   = 4,
    NUM_ROOMS = 5
};

// Sentinel for "there is no room that way." We use -1 because valid
// room indices are always 0 or higher.
const int NO_CONNECTION = -1;

// ---------------------------------------------------------------------------
//  Function prototypes (the course convention: prototypes at the top,
//  main in the middle, full definitions at the bottom).
// ---------------------------------------------------------------------------
void printRoom(const string names[], const string descriptions[], int room);
void printExits(int connections[][NUM_DIRECTIONS], int room);
int  commandToDirection(const string& command);

// ===========================================================================
//  main — sets up the world and runs the game loop.
// ===========================================================================
int main()
{
    // ----- Parallel arrays: both indexed by Room -----
    // roomNames[CRYPT] and roomDescriptions[CRYPT] describe the same place.
    string roomNames[NUM_ROOMS] = {
        "Throne Room",
        "Enchanted Gardens",
        "Sleeping Chambers",
        "Dining Hall",
        "Batheing Chambers"
    };

    string roomDescriptions[NUM_ROOMS] = { // Im going to add more info for all of this
        "A grand hall. A cracked chandelier creaks overhead.",
        "Shelves of rotting books. The air tastes like dust.",
        "A long kitchen. The stove is cold. Someone left a plate.",
        "Stone paths snake through weeds. A fountain gurgles weakly.",
        "A soothing marble chamber with luxury tubs and fragrences." 
    };

    // ----- The adjacency table (a 2D array) -----
    // connections[fromRoom][direction] = destination room (or NO_CONNECTION).
    int connections[NUM_ROOMS][NUM_DIRECTIONS];

    // Step 1: fill every cell with NO_CONNECTION. Clean slate.
    //         (Nested loops — the classic 2D-array pattern.)
    for (int r = 0; r < NUM_ROOMS; r++)
    {
        for (int d = 0; d < NUM_DIRECTIONS; d++)
        {
            connections[r][d] = NO_CONNECTION;
        }
    }

    // Step 2: wire up the connections shown in the map at the top of the file.
    connections[Throne_Room ][NORTH]   = Gardens;
    connections[Throne_Room][EAST]    = Sleeping Chambers;
    connections[Throne_Room][WEST]    = Dining Hall;

    connections[Garden][SOUTH] = Throne Room;

    connections[Sleeping Chambers][WEST]  = Throne Room;
    connections[Sleeping Chambers][SOUTH] = Batheing Chambers;

    connections[Dining Hall][EAST]  = Throne Room;

    connections[Batheing Chambers][NORTH]  = Sleeping Chambers;

    // ----- Game state -----
    int  currentRoom = Throne Room;
    bool running = true;

    cout << "=============================" << endl;
    cout << "    THE PALACE MAP" << endl;
    cout << "=============================" << endl;
    cout << "Commands: north / south / east / west   (or n/s/e/w)" << endl;
    cout << "          look   — re-describe this room" << endl;
    cout << "          quit   — leave the dungeon" << endl;

    // ----- Game loop -----
    while (running)
    {
        printRoom(roomNames, roomDescriptions, currentRoom);
        printExits(connections, currentRoom);

        cout << "\n> ";
        string command;
        cin >> command;

        // Handle non-movement commands first.
        if (command == "quit" || command == "q")
        {
            running = false;
            continue;
        }
        if (command == "look" || command == "l")
        {
            // Loop back around; the top of the loop re-prints the room.
            continue;
        }

        // Translate the command into a direction index (0-3), or -1 if
        // it isn't a direction.
        int direction = commandToDirection(command);
        if (direction == -1)
        {
            cout << "I don't know how to '" << command << "'." << endl; // I want this to be something different 
            continue;
        }

        // Look up where that direction leads from the current room.
        // THIS IS THE POINT OF THE ADJACENCY LIST — one array lookup.
        int next = connections[currentRoom][direction];
        if (next == NO_CONNECTION)
        {
            cout << "A wall blocks you." << endl; // I might keep this but I could also make it more story-like 
        }
        else
        {
            currentRoom = next;
        }
    }

    cout << "\nYou step back into the light. Thanks for playing." << endl; // I want to change or add a resoning for leaving. (They leave feeling refreshed) or somthing like that
    return 0;
}

// ===========================================================================
//  Function definitions
// ===========================================================================

// Print the current room's name and description.
// Arrays come in "by reference" even though the syntax hides it — the
// function can read them but we treat them as const to make that clear.
void printRoom(const string names[], const string descriptions[], int room)
{
    cout << "\n[ " << names[room] << " ]" << endl;
    cout << descriptions[room] << endl;
}

// Print the list of exits from a room. Walks the direction axis of the
// 2D array and skips any NO_CONNECTION entries.
//
// 2D-array parameter note: when a function takes a 2D array, you must tell
// the compiler the SIZE of every dimension except the first. That's why
// the parameter reads [][NUM_DIRECTIONS] — the compiler needs to know how
// wide each row is to do the math.
void printExits(int connections[][NUM_DIRECTIONS], int room)
{
    const string dirNames[NUM_DIRECTIONS] = { "north", "east", "south", "west" };

    cout << "Exits: "; // I might add a discriptions when the "Exit" action is called 
    bool any = false;
    for (int d = 0; d < NUM_DIRECTIONS; d++)
    {
        if (connections[room][d] != NO_CONNECTION)
        {
            if (any) cout << ", ";
            cout << dirNames[d];
            any = true;
        }
    }
    if (!any) cout << "(none)";
    cout << endl;
}

// Turn a typed command into a direction index, or -1 if it isn't a direction.
// Keeping this in its own function means the game loop doesn't drown in
// four near-identical if/else branches.
int commandToDirection(const string& command)
{
    if (command == "north" || command == "n") return NORTH;
    if (command == "east"  || command == "e") return EAST;
    if (command == "south" || command == "s") return SOUTH;
    if (command == "west"  || command == "w") return WEST;
    return -1;
}
