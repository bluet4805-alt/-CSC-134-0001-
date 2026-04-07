// CSC 143
// M5Lab1 
// Blue 
//3-25-26
// I used Google Gemini to help me adapt my original code to the examples 

#include <iostream> 
#include <string> 
using namespace std; 

// Function Prototypes 
int getPlayerChoice (int maxChoice); 
void main_menu(); 
void explore_farm(); 
void go_to_town();
void handle_market(); 

// Main 
int main () {
    cout <<"M5Lab1 - Farming Life Storymode" << endl; 
    main_menu(); 
    cout << " --- Game Over ---" << endl; 
    cout << "Thanks for playing!" << endl; 
    return 0; 
}

// Code For Error 
int getPlayerChoice (int maxChoice) {
    int choice;
    while (true) {
        cout << "Selection (1-" << maxChoice << "): "; 
        if (!(cin >> choice)) {
            cout << "[SYSTEM]: Your input is invalid. Please try again." << endl; 
            cin.clear(); 
            cin.ignore(1000, '\n');
            continue; 
        }
        if (choice >= 1 && choice <= maxChoice) {
            return choice;
        }
        cout << "That is not a valid option. Please try again." << endl; 
    }
}

// Story Functions 

void main_menu () {
    bool running = true; 
    while (running) {
        cout << "==========================================" << endl;
        cout << "You are at the gates of your new Farm." << endl;
        cout << "1. Explore the Farm" << endl;
        cout << "2. Go to the Town" << endl;
        cout << "3. Quit Game" << endl;
        
        int choice = getPlayerChoice(3);

        if (choice == 1) {
            explore_farm();
        } else if (choice == 2) {
            go_to_town();
        } else {
            cout << "Quitting to desktop..." << endl;
            running = false; 
        }
    }
}

void explore_farm() {
    cout << "\nYou find a Hammer and a Sword laying in the dirt." << endl;
    cout << "1. Pick up the Sword" << endl;
    cout << "2. Pick up the Hammer" << endl;
    
    int choice = getPlayerChoice(2);

    if (choice == 1) {
        cout << "\n[SYSTEM]: Sword added. You find a cave of slimes!" << endl;
        cout << "1. Fight them" << endl;
        cout << "2. Run away" << endl;
        if (getPlayerChoice(2) == 1) {
            cout << "You now lead a slime army! +5 Charisma." << endl;
        } else {
            cout << "You got lost and hungry. Not your best day." << endl;
        }
    } else {
        cout << "\n[SYSTEM]: Hammer added. You see a rundown barn." << endl;
        cout << "1. Fix it" << endl;
        cout << "2. Ignore it" << endl;
        if (getPlayerChoice(2) == 1) {
            cout << "The barn is beautiful! Animals move in. +8 Charisma." << endl;
        } else {
            cout << "A magical unicorn passes by but keeps going because you have no shelter." << endl;
        }
    }
}

void go_to_town() {
    cout << "\nMayor Sam offers you a box of seeds." << endl;
    cout << "1. 'Thank you!'" << endl;
    cout << "2. 'I'm not working today!'" << endl;
    
    int reply = getPlayerChoice(2);
    if (reply == 1) cout << "Sam likes you! +20 Charisma." << endl;
    else cout << "Sam is offended. -20 Charisma." << endl;

    cout << "\nWhere to next?" << endl;
    cout << "1. The Beach" << endl;
    cout << "2. The Market" << endl;

    int path = getPlayerChoice(2);
    if (path == 1) {
        cout << "A Pirate Captain makes you his first mate! +50 Bravery." << endl;
    } else {
        handle_market();
    }
}

void handle_market() {
    cout << "\nA shady shop owner wants to help you take over the town." << endl;
    cout << "1. Agree to his evil plan" << endl;
    cout << "2. Refuse and tell the Mayor" << endl;
    
    if (getPlayerChoice(2) == 1) {
        cout << "Years pass. You are rich but hated by everyone." << endl;
    } else {
        cout << "The town throws a festival in your honor! +$40,000,000!" << endl;
    }
}