// CSC 134
// M1Lab - The Apple Orchard 
// Blue 
// 1-28-26

#include <iostream> 
using namespace std; 

int main() {


    // Apple sale program
    // Variables are like mailboxes
    string name = "Trinity's "; 
    int num_apples = 7;
    double cost_each = 0.25;
    
    cout << "Welcome to the " << name << "Apples Farm!" << endl;

    // User input 
    cout << "Please enter your name: "; 
    cin >> name; 

    cout << "Hello " << name << endl; 
    cout << "There are " << num_apples << " apples in stock." << endl; 
    cout << "They cost $" << cost_each << " each." << endl;

    // Find out the total price 
    double total_cost = num_apples * cost_each;
    cout << "The price for all of them is: $" << total_cost << endl;
    cout << endl; 

    return 0;
}