// CSC 134
// M5HW1
// Blue
// 4-1-26

// I originally used the starter code to do this assignment before I began to play with other layouts and found this one helped me understand the process better 
#include <iostream>
#include <string> 
#include <iomanip> // I had looked into the setprecision function on a previous assignment and I wanted to play around with it for this one.
// I did use youtube and google to help me make some notes about its benefits
using namespace; 

// Prototype
void question(); 

int main () {
  question1(); 
  return 0; 
}

void question1 () {
    // Declare Variables 
    string month1, month2, month3; 
    double rain1, rain2, rain3, average; 

    // Get user input 
    cout << "Please enter a Month: "; 
    cin >> month1
    cout << "Now enter rainfall for " << month1 << ": ";
    cin >> rain1; 

    cout << "Please enter a  second Month: ";
    cin >> month2; 
    cout << "Now enter rainfall for " << month2 << ": "; 
    cin >> rain2; 
    
    cout << "Please enter a third month: "; 
    cin >> month3; 
    cout << "Now enter rainfall for " << month3 << ": ";
    cin >> rain3; 

    // Calculate the average 
    average = (rain1 + rain2 + rain3) 3.0; 

    // Display an output with 2 decimal places 
    cout << fixed << setprecision (2); 
// I still dont completely understand the "fixed" and "setprecision" funstions so I am using my time now to play around with them 
    cout << "The average rainfall for " << month1 << ", " << month2 << ", and " << month3 << " is " << average << " inches." << endl; 
}
