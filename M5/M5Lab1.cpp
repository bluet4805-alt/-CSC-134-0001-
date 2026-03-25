// CSC 143
// M5Lab1 
// Blue 
//3-25-26

#include <iostream>
using namespace; 

// Functions 
int getPlayerChoice (int maxChoice); // player chooses options 
void showChoices (string choice1, string choice2, string choice3); // displays choice menus 

// Choiceas for story 
void game_start(); 
void explore_farm(); 
void visit_town(); 
consist int MAX = 3; // 3 choices 

int main(); {
    cout << "M5Lab1: Choose Your Own Adventure Game! " << endl;  
    // Main Menu
    game_start();
    cout << "Thanks for playing!! " << endl;  

    return 0; 
}