// CSC 134
// M3HW1 - Question 4
// Gold 
// Blue 
// 3-7-26
// Goal: Math practice 

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // 1. Seed the number generator
    srand(time(0)); // I used youtube to help me understand the rand function 

    // 2. Generating the two random single-digit numbers
    int num1 = rand() % 10; 
    int num2 = rand() % 10; 
    int correctAnswer = num1 + num2;
    int userAnswer; 

    // 3. Ask the user questions 
    cout << "What is " << num1 << " plus " << num2 << "?" << endl; 
    cin >> userAnswer;

    // 4. Checking
    if (userAnswer == correctAnswer) {
        cout << "Correct!" << endl; 
    } else {
        cout << "Incorrect." << endl; 
        cout << "The correct answer was " << correctAnswer << "." << endl; 
    }
    return 0;
}