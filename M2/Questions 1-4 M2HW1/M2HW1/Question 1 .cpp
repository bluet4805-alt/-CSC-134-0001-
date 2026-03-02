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
int accountNum = 8392;

// User Input 
cout << "Welcome to the Bank of Money!" << endl; 
cout << "Please enter the first name that your account is under: " << endl; 
cin >> name; 
cout << endl; // line for spacing 
cout << "Welcome " << name << "!" << endl; 
cout << "Please enter your starting balance:$ ";
cin >> balance;
cout << "Perfect! How much would you like to deposit?:$ ";
cin >> deposit;
cout << "Now we just need your widthdrawl amount: ";
cin >> withdrawl; 

// Math
finalBalance = balance + deposit - withdrawl;

// Display
cout << endl;
cout << "Your Bank Info:";
cout << endl; 
cout << "________________________" << endl;
cout << "Name on account: " << name << endl;
cout << "Account Number: " << accountNum << endl; 
cout << "Final Balance: $" << finalBalance << endl;

return 0;
}