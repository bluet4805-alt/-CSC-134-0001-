/*
CSC 134
M2T2 - Receipt calculator 
Blue 
1-26-26
Goal: A correct looking recept that handles sales tax. 
Assumption: Sales tax is 8% 
*/

#include <iostream>
using namespace std;
// if you don't use namespace, type std:: cout evrey time instead of cout (alsp cin)

int main () {
    // We are making a recept printer for a bookstore 
// Declare all variables 
string book_name = "Books R Us      "; // change to anything 
int num_books;                        // how many they buy 
double book_price = 5.99;             // $5.99
double sub_total;                     // price before tax/tips
double tax_rate = 0.08;               // 8% is 8/100 ("per cent")
double tip_amount;
double tax_amount;                    // $ of the actual tax
double total_price;                   // subtotal + tip + tax       


// Get user iuput 
cout << "Welcome to the CSC 134 Book Store." << endl; 
cout << "Today's Discount: " << book_name << endl; 
cout << endl; 
cout << "How many would you like? ";
cin >> num_books; 
cout << "Tip ammount? (min 0)? ";
cin >> tip_amount; 

// Do the calculations 
sub_total = book_price * num_books; 
tax_amount = sub_total * tax_rate; // this much is ADDED to the bill
// add tax and tips 
total_price = sub_total + tip_amount +tax_amount; 

// Present the output
cout << endl; 
cout << "Your Order" << endl << "-----------------------------" << endl; 
cout << num_books << "x" << book_name << "\t$" << book_price << endl;
cout << "Subtotal: \t\t$" << sub_total << endl;  
cout << "Tip: \t\t\t$" << tip_amount << endl;
cout << "Tax: \t\t\t$" << tax_amount << endl; 
cout << "-----------------------------" << endl; 
    return 0; // no errors
}