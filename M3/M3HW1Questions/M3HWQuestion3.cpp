// M3Lab1
// Blue
//2-23-26
// Thank you Youtube and Gemini for helping me remember what the functions do 
#include <iostream>
using namespace std; 

// List Prototypes of all choices
void do_choice_1();
void do_choice_2();

// main() is here
int main() {

    int choice;
    // starts the game
    cout << "Welcome to Farming Life Storymode! " << endl << endl;
    cout << "You are working in your cubical and realize that you want more from your life." << endl; //intro and something happens...
    cout << "You get a call from your mother saying that your grandfather had passed and is giving you his farm!" << endl; 
    cout << "You quit your job and make your way to the given address." << endl; 
    cout << "When you arrive you realize how rundown the farm is." << endl; 
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
        cout << "Grandpa's ghost disaproves of your choice and you are forever haunted by his disaproving frown." << endl; // This will prompt if there is an error
        cout << "[SYSTEM]: You have gained the Curse Of The Grandfather!!!" << endl; 
    }

    cout << "---Game Over---" << endl << endl; // I want this to prompt something more story related 

    return 0; // End of game 
}

// List full functions of all choices at the bottom 
void do_choice_1 () {
    int sub_choice; //I did need to watch youtube vids to understand this function 
    cout << "As you make your way around the farm you find some tools laying around." << endl;
    cout << "You see a Hammer and a Sword"<< endl; 
    cout << "Do you:" << endl; 
    cout << "1. Pick up the Sword?" << endl; 
    cout << "2. Pick up the Hammer?" << endl;
    cout << "> ";
    cin >> sub_choice; 

    if (1== sub_choice) {
        cout << "[SYSTEM]: You have added a sword to your inventory" << endl; 
        cout << "You wander into a cave of dangerous slimes!" << endl; 
        cout << "Do you:" << endl; 
        cout << "1. Fight the slimes?" << endl;
        cout << "2. Run away?" << endl; 
        cout << "> ";
        cin >> sub_choice; 
        // resolve the fight/run decision
        if (1 == sub_choice) {
            cout << "You defeat the giant slimes and in doing so you tame the remaining ones!" << endl; 
            cout << "You now have a slime army!" << endl; 
            cout <<" [SYSTEM]: +5 Charisma." << endl; 
        } else {
            cout << " [SYSTEM]: You get lost in the cave and starve. OH NO!" << endl; 
        }
    }
    else if (2 == sub_choice) {
            cout << "[SYSTEM]: You have added a Hammer into your inventory." << endl; 
            cout << "As you continue your exploration you find a rundown barn." << endl; 
            cout << "Do You: " << endl; 
            cout << "1. Fix the barn?" << endl; 
            cout << "2. Keep exploring the farm?" << endl; 
            cout << "> ";
            cin >> sub_choice; 
            if (1 == sub_choice) {
                cout << "The barn is fixed!" << endl; 
                cout << "Animals begin to move in and become your friend." << endl; 
                cout << "[SYSTEM: +8 Charisma]" << endl; 
            } else {
                cout << "You leave the barn and continue wandering the land." << endl; 
                cout <<"As you wander, you begin to feel magic in the air." << endl; 
                cout << "Looking ahead you see a Unicorn looking for somewhere to keep warm, but because you dont have a barn it begins to look elsewhere as it trots back into the woods" << endl; 
                cout << "[SYSTEM]: -20 Magic" << endl; 
            }
        }
}
    void do_choice_2() {
        int sub_choice; 
        cout << "You are greeted by Mayor Sam and he hands you a box of seeds." << endl; 
        cout << "How do you reply?:" << endl; 
        cout << "1. 'WoW! This is so thoughtful. Thank you so much!'" << endl; 
        cout << "2. 'SEEDS?! I JUST GOT HERE AND YOU EXPECT ME TO ALREADY START WORKING ?!'" << endl; 
        cout << "> "; 
        cin >> sub_choice; 

        if (1 == sub_choice) {
            cout << "Sam smiles as you accept the seeds."<< endl;
            cout << "You overhear him puting in a good word for you to the rest of the townspeople as you continue walking" << endl; 
            cout << "[SYSTEM]: +20 Charisma." << endl; 
        } else {
            cout << "Sam storms off mumbling a threatening remark." << endl; 
            cout << "[SYSTEM]: You have gained an enemy.  -20 Charisma" << endl; 
        }
        cout << "You look around the town and notice two paths." << endl; 
        cout << "One leads to the town market and the other to the beach." << endl; 
        cout << "Do you go to:" << endl; 
        cout << "1. The Beach?" << endl; 
        cout << "2. The Market?" << endl;
        cout << "> ";
        cin >> sub_choice; 

        if (1 == sub_choice) {
            cout << "A Pirate Captian makes his way to you and instantly approves of you" << endl; 
            cout << "You are now the first mate to the rugged crew." << endl; 
            cout << "[SYSTEM]: +50 Bravery" << endl; 
        } else if (2 == sub_choice) {
            cout << "A greedy shop owner pulls you into his booth and asks you to help him take over the town." << endl; 
            cout << "Do You:" << endl; 
            cout << "1. Agree to help him?" << endl; 
            cout << "2. Refuse his offer?" << endl; 
            cout << "> ";
            cin >> sub_choice;
            if (1 == sub_choice) {
                cout << "TIME SKIP 3 YEARS" << endl; 
                cout << "You are rich but, the town has become a dystopian society" << endl; 
                cout << "You sit alone in your cold and empty mansion hiding because the townspeople seek revenge." << endl; 
                cout << "[SYSTEM]: -50 Bravery and -50 Charisma" << endl; 
            } else{
                cout << "The townspeople overhear and invite you the guest of honor at their summer fesival!" << endl;
                cout << "They pitch in to help fix up the farm and you begin to enjoy your new farm life." << endl; 
                cout << "[SYSTEM]: +100 Charisma and +$40,000,000 from the success of your farm" << endl; 
            }
        }
    }
// I could eventually have it keep track of different stats such as combat and charisma.