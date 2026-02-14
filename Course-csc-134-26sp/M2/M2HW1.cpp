/*
CSC 134
M2HW1- Gold
Trinity 
2-11-26
*/

// Question 1

#include <iostream>
#include <string>

using namespace std; 
int main () {
    // Variables
string name;
double balance, deposit, withdrawl, finalBalance; 

// User Input 
cout << "Welcome to the Bank of Money!" << endl; 
cout << "Please enter the name your accout is under: " << endl; 
cin >> name; 
cout << "Please enter your starting balance:$ ";
cin >> balance;
cout << "Perfect! How much would you like to deposit?:$ ";
cin >> deposit;
cout << "Now we just need your widthdrawl amount: ";
cin >> withdrawl; 

// Math
finalBalance = balance + deposit - withdrawl;

// Display
cout << "Your Bank Info.";
cout << endl;
cout << "_______________________________";
cout << "Name on account: " << name << endl;
cout << "Final Balance: $" <<finalBalance << endl;

return 0;
}