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
    // Ask for number 
    cout << "Please enter a number from 1-12: ";
    cin >> tableNum; 
    // Validation Loop
    while (tableNum < 1 || tableNum > 12) { // I used google to understand true/false functions and I used the || function
        cout << "Input is not valid. Please enter a number from 1 to 12: ";
        cin >> tableNum;
    }
    // Loop
    while (counter <= 12) {
        final = tableNum * counter;
        cout << tableNum << " times " << counter << " is " << final << "." << endl; 
        counter ++;
    }
    return 0;
}
