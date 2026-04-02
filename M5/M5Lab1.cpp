// CSC 143
// M5Lab1 
// Blue 
//3-25-26
// I used Google Gemini to help me adapt my original code to the examples 


#include <iostream>
#include <string>

using namespace std;

// --- Function Prototypes ---
int getPlayerChoice(int maxChoice);
void showChoices(string c1, string c2 = "", string c3 = "");
void game_start();
void explore_farm();
void go_to_town();
void choice_market();
void choice_slime_pit();

// Global Data
int charisma = 0; 

int main() {
    cout << "Welcome to Farming Life Storymode!" << endl;
    cout << "Charisma represents how much the world likes you." << endl << endl;

    game_start();

    cout << "\n--- FINAL STATS ---" << endl;
    cout << "Final Charisma Score: " << charisma << endl;
    cout << "--- Game Over ---" << endl;

    return 0;
}

// Helper Functions

int getPlayerChoice(int maxChoice) {
    int choice;
    while (true) {
        cout << "Your choice (1-" << maxChoice << "): ";
        if (!(cin >> choice)) { 
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }
        if (choice >= 1 && choice <= maxChoice) {
            return choice;
        }
        cout << "That's not an option. Try again!" << endl;
    }
}

void showChoices(string c1, string c2, string c3) {
    cout << "\n---- WHAT DO YOU DO? ----" << endl;
    cout << "1. " << c1 << endl;
    if (c2 != "") cout << "2. " << c2 << endl;
    if (c3 != "") cout << "3. " << c3 << endl;
}

// Story Branch Definitions 

void game_start() {
    
    cout << "You stand at the gate of your new farm. It's a mess, but it's yours." << endl;
    showChoices("Work on the farm", "Visit the town", "Quit and go home");
    
    int choice = getPlayerChoice(3);

    if (choice == 1) explore_farm();
    else if (choice == 2) go_to_town();
    else cout << "You decide the city life wasn't so bad after all." << endl;
}

void explore_farm() {
    cout << "\nYou find a rusty sword near a glowing hole in the ground." << endl;
    showChoices("Enter the glowing hole", "Go back to the gate");

    int choice = getPlayerChoice(2);
    if (choice == 1) choice_slime_pit();
    else game_start();
}

void go_to_town() {
    cout << "\nThe town is bustling with people. You see a market nearby." << endl;
    showChoices("Go to the Market", "Talk to the Mayor", "Go back to the farm");

    int choice = getPlayerChoice(3);
    if (choice == 1) choice_market();
    else if (choice == 2) {
        cout << "The Mayor gives you a warm welcome! +10 Charisma." << endl;
        charisma += 10;
        go_to_town();
    }
    else game_start();
}

void choice_market() {
    
    cout << "\nThe Market is full of exotic goods. A merchant offers you\n"
         << "a \"Mystery Box\" for free if you help him move some crates.\n" << endl;
    
    showChoices("Help the merchant", "Ignore him and browse");

    int choice = getPlayerChoice(2);
    if (choice == 1) {
        cout << "You help out. Inside the box was a fancy hat! +15 Charisma." << endl;
        charisma += 15;
    } else {
        cout << "You wander around but realize you have no money yet." << endl;
    }
    go_to_town();
}

void choice_slime_pit() {
    
    cout << "\nYou drop into the hole and find a pit of friendly green slimes.\n"
         << "They seem to be dancing to a rhythmic dripping sound.\n" << endl;

    showChoices("Dance with the slimes", "Attack the slimes");

    int choice = getPlayerChoice(2);
    if (choice == 1) {
        cout << "The slimes love your moves! They give you a slime-pearl. +20 Charisma." << endl;
        charisma += 20;
    } else {
        cout << "The slimes are upset. They bounce you out of the hole! -5 Charisma." << endl;
        charisma -= 5;
    }
    explore_farm();
}