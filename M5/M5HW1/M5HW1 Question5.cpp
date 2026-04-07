// CSC 134
// M5HW1
// Blue
// 4-1-26
// Question 5 - Distance travled 
// Gold 

#include <iostream> 
using namespace std; 

// Prototypes 
void question1(); 
void question2(); 
void question3(); 
void question4(); 
void question5(); // Distance Loop 

int main() {
    // Calling Question 5
    question5(); 

    return 0; 
}

void question5() {
    double speed; 
    int hours; 

    // User Input
    cout << "What is the speed of the vehicle in mph? ";
    cin >> speed; 
    cout << "How many hours has it traveled? "; 
    cin >> hours; 

    // Input Validation 
    if (speed < 0 || hours < 1) {
        cout << "Error: Please ensure both inputs are greater than 0" << endl; 
    }
    else {
        // Table Header
        cout << "\nHour   Distance Traveled" << endl;
        cout << "----------------------------" << endl; 

        // The Loop (It starts at 1hr and stops at the total hours)
        for (int i=1; i <= hours; i++) {
            double distance = speed * i; 
            cout << " " << i << "            " << distance << endl; 
        }
    }
}

// Placeholders 
void question1() { cout << "Question 1" << endl; }
void question2() { cout << "Question 2" << endl; }
void question3() { cout << "Question 3" << endl; }
void question4() { cout << "Question 4" << endl; }