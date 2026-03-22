// M4HW1
// Blue
//3-16-26
// Gold 


#include <iostream>
using namespace std;
int main () {
    //Variables
    int tableNum; 
    int counter = 1; 
    int final; 
    // Ask for a number
    cout << "Enter a number from 1 to 12: ";
    cin >> tableNum; 
    //Loop
    while (counter <= 12) {
        final = tableNum * counter; 
        cout << tableNum << " times " << counter << " is " << final << "." << endl;
        // Function moves to the next number 
        counter ++;
    } 
    return 0;
}
