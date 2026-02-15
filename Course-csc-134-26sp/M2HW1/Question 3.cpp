#include <iostream>
using namespace std; 

int main() {
    // Variables 
    int numPizzas, slicesperPizza, numGuest, totalSlices, slicesEaten, slicesLeft; 

    cout << "--- Pizza Party Calculator ---" << endl; 

    // Inputs 
    cout << "How many pizzas did you order?: "; 
    cin >> numPizzas; 
    cout << "How many slices are in each pizza?: ";
    cin >> slicesperPizza; 
    cout << "How many guests are you expecting?: "; 
    cin >> numGuest;

    // Math 
    totalSlices = numPizzas * slicesperPizza; 
    slicesEaten = numGuest * 3; 
    slicesLeft = totalSlices - slicesEaten; 

    // Output
    cout << "Total slices avalable: " << totalSlices << endl; 
    cout << "Total slices eaten: " << slicesEaten << endl; 
    cout << "Slices left over " << slicesLeft << endl; 
}