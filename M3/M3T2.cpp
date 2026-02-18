// CSC 134
// M3T2 - Craps!
// Blue 
// 2-16-26
// Start game of craps. 
#include <iostream>
#include <cstdlib> // for random
#include <ctime> // for time
using namespace std; 

// Functio declarations 
// (Tell the program what the function will be!) 
int roll();

//main() goes here
int main() {
    //Seed the random number generator
    int seed = time (0);
    srand (seed);

// Roll 2 dice and show the results 
int first, second, total;
string result; 
first = roll();
second = roll ();
total = first + second; 
cout << "You rolled  " << first << " + " << second << " = " << total << endl; 

// How did we do?
if (total == 7) {
    result = "Win!";
}
else if (total == 11){
    result = "Wim!";
}
else if (total == 2) {
    result = "lose";
}
else if (total == 3) {
    result = "lose";
}
else if (total == 12) {
    result = "lose";
}
else {
    // must be a point roll
    result = "point";
}
cout << "Roll results: " << result << endl; 

    return 0;
}

// Functions definitions 
// (Actually write the ENTIRE function)
int roll () {
    //rand () gives a large random number
    // % 6 divides by six, and keeps the remainder
    //fianlly, add 1 so it is 1 and 6 and not 0 to 5
    int my_roll = rand() % 6 + 1;
    return my_roll;
}