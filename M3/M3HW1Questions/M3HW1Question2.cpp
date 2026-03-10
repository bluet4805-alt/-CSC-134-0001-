/*
CSC 134
M3HW1- Question 2 
Goal: Calculating a recept with conditional tips
Blue 
3-4-26
Gold 
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main () {
    // Declaring variables
    double meal_price;
    int order_type; // 1 for dine in and 2 for takeaway
    double tax_rate = 0.08;
    double tax_amount; 
    double tip_amount = 0.0; // I asked google gemini to explane the functions of the code and it recomended to make the tip ammount default to 0
    double total_price; 

    // User input
    cout << "Welcome to the CSC Restaurant!" << endl;
    cout << "Please enter the price of the meal ($): ";
    cin >> meal_price; 

    cout << "Is the order dine in or takeaway?" << endl;
    cout << "Please enter 1 if the order is dine in and 2 if it is a takeaway." << endl; 
    cin >> order_type; 

    // Do the calculations 
    // Calculating tax
    tax_amount = meal_price * tax_rate; 

    // Path for conditional tip (15%)
    if (order_type == 1) {
        tip_amount = meal_price * 0.15;
    } else {
        tip_amount = 0.0; // No takeaway tip
    }
    total_price = meal_price + tax_amount + tip_amount;

    // Present the output 
    // I used youtube and gemini to make sure my functions were correct
    cout << setprecision(2) << fixed; // ($0.00)
    cout << endl; 
    cout << "Your Recept" << endl; 
    cout << "-------------------------------- " << endl;
    cout << "Meal Price: \t\t$" << meal_price << endl; 
    cout << "Tax (8%): \t\t$" << tax_amount << endl; 

    //Dine in tip
    if (order_type == 1) {
        cout << "Tip (15%): \t\t$" << tip_amount << endl; 
    } else {
        cout << "Tip: \t\t\t$0.00 (Takeaway)" << endl; 
    }
    cout << "-------------------------------------- " << endl;
    cout << "Total Amount Due: \t$" << total_price << endl; 
    cout << "THANK YOU! PLEASE COME AGAIN!!" << endl; 

    return 0;
}