// M3Lab1
// Blue
// Goal: Choose your own adventure with Input Validation
// 2-23-26

#include <iostream>
using namespace std; 

// List Prototypes
void do_choice_1();
void do_choice_2();

int main() {
    int choice;
    bool valid_input = false; // We use this to track if the user picked right

    // Starts the game
    cout << "Welcome to Farming Life Storymode! " << endl << endl;
    cout << "You are working in your cubical and realize that you want more from your life." << endl;
    cout << "You get a call from your mother saying that your grandfather had passed and is giving you his farm!" << endl; 
    cout << "You quit your job and make your way to the given address." << endl; 
    cout << "When you arrive you realize how rundown the farm is." << endl; 
    cout << "You also notice a small town in the distance." << endl; 

    // --- PART 1: INPUT VALIDATION LOOP ---
    while (!valid_input) {
        cout << "What is your first decision?" << endl; 
        cout << "1. Explore the Farm?" << endl; 
        cout << "2. Go to the Town?" << endl; 
        cout << "> "; 
        
        cin >> choice; 

        if (1 == choice) {
            valid_input = true; // Break the loop
            do_choice_1();
        }
        else if (2 == choice) { 
            valid_input = true; // Break the loop
            do_choice_2();
        }
        else {
            // Instead of ending the game, we clear the error and loop back
            cout << "\n[ERROR]: That is not a valid option." << endl;
            cout << "Grandpa's ghost is watching... try again!" << endl;
            
            cin.clear();           // Resets the input flag if they typed a letter
            cin.ignore(100, '\n'); // Flushes the bad input out of the system
        }
    }

    cout << "---Game Over---" << endl; 
    return 0; 
}

// Your existing functions stay below
void do_choice_1 () {
    int sub_choice; 
    cout << "As you make your way around the farm you find some tools laying around." << endl;
    cout << "You see a Hammer and a Sword"<< endl; 
    cout << "1. Pick up the Sword?\n2. Pick up the Hammer?\n> ";
    cin >> sub_choice; 

    if (1 == sub_choice) {
        cout << "[SYSTEM]: You have added a sword to your inventory" << endl; 
        cout << "You defeat the giant slimes and tame the remaining ones!" << endl; 
        cout << "You now have a slime army! [SYSTEM]: +5 Charisma." << endl; 
    } else {
        cout << "[SYSTEM]: You added a Hammer. You fix the barn and animals move in!" << endl;
        cout << "[SYSTEM]: +8 Charisma" << endl;
    }
}

void do_choice_2() {
    int sub_choice; 
    cout << "Mayor Sam hands you a box of seeds." << endl; 
    cout << "1. 'Thank you!'\n2. 'I hate seeds!'\n> "; 
    cin >> sub_choice; 

    if (1 == sub_choice) {
        cout << "Sam smiles. [SYSTEM]: +20 Charisma." << endl; 
    } else {
        cout << "Sam storms off. [SYSTEM]: -20 Charisma" << endl; 
    }
}
