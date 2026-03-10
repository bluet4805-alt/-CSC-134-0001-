// CSC 134
// M3HW1 - Gold 
// Blue 
// 3-2-26
// Goal: Simple chat bot

#include <iostream>
#include <string>
using namespace std; 

int main() {
    string responce; 

    cout << "Hello, I'm a C++ program!" << endl; 
    cout << "You seem like a great person." << endl; 
    cout << "Do you want to be besties?!" << endl; 
    cout << "Please type yes or no." << endl; 

    cin >> responce;

    if (responce == "yes") {
        cout << "YAY!! Lets have a BEST FRIEND PARTY!!" << endl; 
    }
    else if (responce == "no") {
        cout << "Well, maybe we can hang out more and you will learn to like me." << endl; 
    }
    else {
        cout << "I'm not sure I understand your input." << endl; 
        cout << "Can you try again please?" << endl;
    }
    return 0;
}