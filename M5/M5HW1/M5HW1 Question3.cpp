// CSC 134
// M5HW1
// Blue
// 4-7-26
// Question 3 - Roman Numeral Generator 
// Gold 

#include <iostream>
using namespace std; 

// List question prototypes 
void question1 (); 
void question2 (); 
void question3 (); // New Question 

int main () {
    // Calling them one at a time 
    // question1(); 
    // question2(); 
    question3(); 

    return 0; 
}

// Full question definition 
void question1() {
    cout << "Question 1 (Rainfall)" << endl; 
}

void question2() {
    cout << "Question2 (Block Volume)" << endl; 
}

void question3() {
    int number; 
    
    cout << "Please enter a number (1 - 10): "; 
    cin >> number; 
    
    // Input Validation 
    if (number < 1 || number > 10) {
        cout << "Error: Ensure your input is not less than 1 or greater than 10" << endl; 
    }
    else {
        cout << "The Roman numeral version of " << number << " is "; 
    
        // I wanted to play around with the switch function so I used google to get a better understanding 
        switch (number) {
            case 1: cout << "I"; break; 
            case 2: cout << "II"; break; 
            case 3: cout << "III"; break; 
            case 4: cout << "IV"; break; 
            case 5: cout << "V"; break; 
            case 6: cout << "VI"; break; 
            case 7: cout << "VII"; break; 
            case 8: cout << "VIII"; break; 
            case 9: cout << "IX"; break; 
            case 10: cout << "X"; break; 
        }
        cout << "." << endl; 
    }
}