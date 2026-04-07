// CSC 134
// M5HW1
// Blue
// 4-7-26
// Question 2
// Gold 

// For this question I want to play around with some if/while loops 
// During our last assignment I had came across some examples and thought they would be fun to try when I had more time 
#include <iostream>
using namespace std; 

// Prorotypes 
void question1(); 
void question2 (); 

// main
int main() {
    // I want to call them one-by-one 
    // question1(); 
    question2();

    return 0; 
}

// Full questions 
void question1 () {
    cout << "Question 1 (Rainfall Logic)" << endl; 
}

void question2 () {
    // Block Variables 
    double width, length, height, volume; 

    cout << "--- Block Volume Calculator ---" << endl; 

    // User Input
    cout << "Please enter the Width: "; 
    cin >> width; 
    cout << "Now enter a length: ";
    cin >> length; 
    cout << "Fianlly enter the height: "; 
    cin >> height; 

    // Input Validation (I dont want a side to be 0 or less)
    if (width <= 0 || length <=0 || height <=0) {
        cout << "Error: Please ensure all dementions are greater than zero." << endl; 
    }
    else {
        // Calculating the Volume 
        volume = length*width*height; 

        cout << "The volume of the block is: " << volume << endl; 
    }
}

