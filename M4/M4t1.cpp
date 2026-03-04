// Blue 
// 3-4-26
// M4t1

// Some While loops 

#include <iostream>
using namespace std;

int main(){
    cout << "Part 1: While Loop" << endl; 
    int i = 10; 
    while (i > 0) {
        i--; // Subtract 1
        cout << i << " "; 
    }
    cout << "Done" << endl; 
    cout << "Part 2: For Loop" << endl; 
    for (int j=0; j<10; j++) {
        cout << j << " "; 
    }
    cout << "Done" << endl; 

    cout << "Part 3: The Table" << endl; 
    const int MIN = 1; 
    const int MAX =10; 

    int num = MIN; 
    int squared;
    cout << "Number\t\tNumber Squared\n";
    cout << "-------------------------------------" << endl; 
    while (num <= MAX) {
        squared = num*num;
        cout << num << "\t\t" << squared << endl; 
        num++; // Go to the next number 
    }
}   