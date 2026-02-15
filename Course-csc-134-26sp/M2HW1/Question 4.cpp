#include <iostream>
#include <string> 
using namespace std; 

int main() {
    // Variables
    string cheer = "Let's go "; // I did use youtube to get a clear understanding of how the "string" lines work 
    string school = "FTCC";
    string mascot = "Trojans";

    cout << endl;

    // Output (Lets Go FTCC)
cout << "--- Final Cheer ---" << endl; 
cout << cheer << school << "!" << endl; 
cout << cheer << school << "!" << endl; 
cout << cheer << school << "!" << endl; 

// Output (Let's go Trojans )
cout << cheer << mascot << "!" << endl; 

return 0;

}