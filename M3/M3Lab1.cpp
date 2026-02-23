// M3Lab1
// Blue
//2-23-26

#include <iostream>
using namespace std; 

// List Prototypes of all choices

void do_choice_1();
void do_choice_2();
void do_choice_3();
void do_choice_4();

// main() is here
int main() {

    int choice;
    // starts the game
    cout << "Farming Tails" << endl << endl;
    cout << "You are working in your cubical and realize that you want more from your life." << endl; //intro and something happens...
    cout << "You get a call from your mother saying that your grandfather had passed and is giving you his farm!" << endl; 
    cout << "You quit your job and make your way to the given address." << endl; 
    cout << "When you arrive you realize how rundowm the farm is." << endl; 
    cout << "You also notice a small town in the distance." << endl; 
    // First Choice 
    cout << "What is your first decision?" << endl; 
    cout << "Do You: " << endl; 
    cout << "1. Explore the Farm?" << endl; 
    cout << "2. Go to the Town?" << endl; 

    cout << "> "; // Give a prompt to type
    // Change the names of the choices to make this more organized as we add more 
    cin >> choice; 

    if (1 == choice) {
        do_choice_1();
    }
    else if (2 == choice) { 
        do_choice_2();
    }
    else {
        cout << "Grandpa's ghost disaproves and you are forever haunted by his disaproving frown." << endl; // This will prompt if there is an error 
    }
    cout << "Game Over" << endl << endl; // I want this to prompt something more story related 

    return 0; // End of game 
}
// List full functions of all choices at the bottom 
void do_choice_1 () {
    cout << "As you make your way around the farm you find some tools laying around." << endl;
    cout << " You see a Hammer, Axe, Watering can and Sword."
    cout << "Which do you pick?"
     // I need add the choices code here 
}
void do_choice_2() {
    cout << "You make your way to the town and are greeted by Mayor Sam who claims to be your grandfater's best friend." << endl; 
    cout << "He tells you that he has a welcome gift for you" << endl; 
    cout << "He hands you a box holding some seeds" << endl; 
    cout << "Do You: " << endl;
    // I want the choices to be either be happy about the gift or angry that it wasnt something more interesting 
}
// Use the other choices in 1 or 2

// We will do a short story with around 3-4 choiced events 