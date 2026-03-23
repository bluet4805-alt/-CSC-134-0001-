// M4Lab1
// Blue
//3-17-26

#include <iostream>
using namespace std; 

int main() {
    cout << "M4LAB\n";

    // Variables 
    int height, width; 

    // set the size 
    height = 5; 
    width = 5; 


    // nested loop
    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {
            cout << "* ";
        }
        cout << endl; // ends the newer line 
    }
    return 0;
}