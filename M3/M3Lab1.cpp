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
    cout << "Welcome to Farming Life Storymode! " << endl << endl;
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
        cout << "You answer is not one of the options given." << endl; 
        cout << "Grandpa's ghost disaproves and you are forever haunted by his disaproving frown." << endl; // This will prompt if there is an error
    }
    cout << "Game Over" << endl << endl; // I want this to prompt something more story related 

    return 0; // End of game 
}
// List full functions of all choices at the bottom 
void do_choice_1 () {
    cout << "As you make your way around the farm you find some tools laying around." << endl;
    cout << " You see a Hammer and a Sword"<< endl; 
    cout << "Which do you pick?" << endl; 
     // I need add the choices code:
     // If they choose the sword I want them to wander the farm and enter a cave of dangerous slimes where they can decide weather to fight or run.
     // If they choose to run then they get lost in the cave and starve. If they defeat the slimes they are able to tame the others and now have a slime army. This also introduces carisma stats and the user is told they have +1 carisma 
    
     // If they choose the hammer then I want them to find a rundown barn and they can decide to fix it or not. 
     // If they do then they are awarded with the ability to befriend animals and have them live in the barn. If not then they continue to explore the farm)
}
void do_choice_2() {
    cout << "You make your way to the town and are greeted by Mayor Sam who claims to be your grandfater's best friend." << endl; 
    cout << "He tells you that he has a welcome gift for you" << endl; 
    cout << "He hands you a box holding some seeds" << endl; 
    cout << "Which do you say? " << endl;
 cout << "1. WoW! This is so thoughtful. Thank you so much!" << endl; 
 cout << "2. SEEDS?! I JUST GOT HERE AND YOU ALREADY WANT ME TO WORK?!" << endl;
 cout << "> ";
// I need to add more choice code
 // If you thank Sam then you will gain access charisma stats and told that your carisma is +1.
 // If you  choose the second option then Sam scoffs and says that you are ungrateful and the user is told they have gaied an ememy
 // After a decision is made then the story continues as the user continues exploring the town. 
 // As they look around they see a beach and a market and they are prompted to choose
 // If they choose the beach then they meet a pirate captain who makes the user their second in command and the code ends
 // If they choose the market then they are pulled into a modern shop where the owner notes that they are the new owners of the farm and tries to covimce the user to become business partners to help him take over the town for his greed.
 // The user is prompted to choose to either help the shop owner or to refuse. 
 // If they agree to help the shop owner then there is a 2 month timeskip and the once humble town is changed into a large city where the user is rich at the expense of the former towns people hate them forever and the code ends
 // If they choose to not help the owner then he scoffs and lets you go. The townspeople overhear and the user gain +20 charisma and are invited to the town summer festival and the code ends
 
}
// Use the other choices in 1 or 2

// We will do a short story with around 3-4 choiced events 