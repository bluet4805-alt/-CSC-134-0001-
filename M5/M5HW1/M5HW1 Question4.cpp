// CSC 134
// M5HW1
// Blue
// 4-7-26
// Question 4- Geometry Calculator 
// Gold 

#include <iostream>
#include <cmath> // My calculations kept making errord so I used Youtube to find some example code and I saw this function and wanted to play with it 
using namespace std;

// At another time I will play with more calling functions to shorten codes with longer functions 
// Question Prototypes
void question1(); 
void question2(); 
void question3(); 
void question4(); // Geomrtry Calculator 

int main () {
    // calling question 4
    question4();
    return 0;
}

void question4 () {
    int choice;
    
    cout << "Geometry Calculator" << endl; 
    cout << "1. Calculate the Area of a Circle" << endl; 
    cout << "2. Calculate the Area of a Rectangle" << endl; 
    cout << "3. Calculate the Area of a Triangle" << endl; 
    cout << "4. Quit" << endl; 
    cout << "\nPlease enter your choice (1-4): "; 
    cin >> choice;

    switch (choice) {
        case 1: {
            double radius, area;
            cout << "Enter the circle's radius: "; 
            cin >> radius; 
            if (radius < 0) {
                cout << "The radius cannot be less than 0." << endl; 
            } else {
                area = M_PI * (radius * radius);
                cout << "\nThe area is " << area << endl; 
            }
            break;
        }
        case 2: {
            double length, width, area; 
            cout << "Please enter a length: "; 
            cin >> length; 
            cout << "Now enter a width: "; 
            cin >> width;
            if (length < 0 || width < 0) {
                cout << "Please ensure only positive values are entered for the length and width." << endl; 
            } else {
                area = length * width; 
                cout << "\nThe area is " << area << endl; 
            }
            break; 
        }
        case 3: {
            double base, height, area; 
            cout << "Please enter the base number: "; 
            cin >> base; 
            cout << "Now enter the height: ";
            cin >> height; 
            if (base < 0 || height < 0) {
                cout << "Only enter positive values for base and height." << endl;
            } else {
                area = base * height * 0.5;
                cout << "\nThe area is " << area << endl;
            }
            break; 
        }
        case 4: 
            cout << "Now Quitting..." << endl; 
            break;
        default: // Im doing some testing with this 
        cout << "The value choices are 1-4. Please try again" << endl;     
    }
}

// Placeholders for the other functions
// I am going to make this all one code later when I have more freetime 
void question1() { cout << "Question 1" << endl; }
void question2() { cout << "Question 2" << endl; }
void question3() { cout << "Question 3" << endl; }