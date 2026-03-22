// M4HW1
// Blue
//3-16-26
// Gold 


#include <iostream>
using namespace std;
int main () {
    //Variables for the table 
    int tableNum = 5; 
    int counter = 1; 
    // Loop 
    while (counter <= 12) {
        cout << tableNum << " times " << counter << " is " << (tableNum * counter) << "." << endl; 
        counter ++; // I looked on Youtube for examples of how to use the ++ function 
    }
    return 0;
}
