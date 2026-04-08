// CSC 134
// M5HW1 - Master Menu (Final)
// Blue
// 4/1/26
#include <iostream>
#include <string> 
#include <iomanip> 
#include <cmath> 
using namespace std;

// --- Prototypes ---
void question1();
void question2();
void question3();
void question4();
void question5();

int main() {
    int choice = 0; 

    // Main program loop
    while (choice != 6) {
        cout << "\n---------- Main Menu ----------" << endl;
        cout << "1. Average Rainfall" << endl;
        cout << "2. Block Volume" << endl;
        cout << "3. Roman Numerals" << endl;
        cout << "4. Geometry Calculator" << endl;
        cout << "5. Distance Traveled" << endl;
        cout << "6. Exit" << endl;
        cout << "-------------------------------" << endl;
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        if (choice == 1) {
            question1();
        } 
        else if (choice == 2) {
            question2();
        } 
        else if (choice == 3) {
            question3();
        } 
        else if (choice == 4) {
            question4();
        } 
        else if (choice == 5) {
            question5();
        } 
        else if (choice == 6) {
            cout << "Exiting the program. Goodbye!" << endl;
        } 
        else {
            cout << "Error: Invalid choice. Please select 1 through 6." << endl;
        }
    }
    return 0;
}

// --- Question 1: Average Rainfall ---
void question1() {
    string month1, month2, month3; 
    double rain1, rain2, rain3, average; 

    cout << "\nPlease enter a Month: "; 
    cin >> month1;
    cout << "Now enter the number of rain in inches for " << month1 << ": ";
    cin >> rain1; 

    cout << "Please enter a second Month: ";
    cin >> month2; 
    cout << "Now enter the number of rain in inches for " << month2 << ": "; 
    cin >> rain2; 
    
    cout << "Please enter a third month: "; 
    cin >> month3; 
    cout << "Now enter the number of rain in inches for " << month3 << ": ";
    cin >> rain3; 

    average = (rain1 + rain2 + rain3) / 3.0; 

    cout << fixed << setprecision(2); 
    cout << "The average rainfall for " << month1 << ", " << month2 << ", and " << month3 << " is " << average << " inches." << endl; 
}

// --- Question 2: Block Volume ---
void question2() {
    double width, length, height, volume; 
    cout << "\n--- Block Volume Calculator ---" << endl; 
    cout << "Please enter the Width: "; cin >> width; 
    cout << "Now enter a length: "; cin >> length; 
    cout << "Finally enter the height: "; cin >> height; 

    if (width <= 0 || length <= 0 || height <= 0) {
        cout << "Error: Please ensure all dimensions are greater than zero." << endl; 
    }
    else {
        volume = length * width * height; 
        cout << "The volume of the block is: " << volume << endl; 
    }
}

// --- Question 3: Roman Numerals ---
void question3() {
    int number; 
    cout << "\nPlease enter a number (1 - 10): "; cin >> number; 
    
    if (number < 1 || number > 10) {
        cout << "Error: Ensure your input is not less than 1 or greater than 10" << endl; 
    }
    else {
        cout << "The Roman numeral version of " << number << " is "; 
        switch (number) {
            case 1:  cout << "I";    break; 
            case 2:  cout << "II";   break; 
            case 3:  cout << "III";  break; 
            case 4:  cout << "IV";   break; 
            case 5:  cout << "V";    break; 
            case 6:  cout << "VI";   break; 
            case 7:  cout << "VII";  break; 
            case 8:  cout << "VIII"; break; 
            case 9:  cout << "IX";   break; 
            case 10: cout << "X";    break; 
        }
        cout << "." << endl; 
    }
}

// --- Question 4: Geometry Calculator ---
void question4() {
    int choice;
    const double PI = 3.14159; 

    cout << "\n--- Geometry Calculator ---" << endl; 
    cout << "1. Calculate the Area of a Circle" << endl; 
    cout << "2. Calculate the Area of a Rectangle" << endl; 
    cout << "3. Calculate the Area of a Triangle" << endl; 
    cout << "4. Return to Main Menu" << endl; 
    cout << "\nPlease enter your choice (1-4): "; 
    cin >> choice;

    switch (choice) {
        case 1: {
            double radius, area;
            cout << "Enter the circle's radius: "; cin >> radius; 
            if (radius < 0) { cout << "The radius cannot be less than 0." << endl; } 
            else {
                area = PI * (radius * radius);
                cout << "\nThe area is " << area << endl; 
            }
            break;
        }
        case 2: {
            double length, width, area; 
            cout << "Please enter a length: "; cin >> length; 
            cout << "Now enter a width: "; cin >> width;
            if (length < 0 || width < 0) { cout << "Error: positive values only." << endl; } 
            else {
                area = length * width; 
                cout << "\nThe area is " << area << endl; 
            }
            break; 
        }
        case 3: {
            double base, height, area; 
            cout << "Please enter the base: "; cin >> base; 
            cout << "Now enter the height: "; cin >> height; 
            if (base < 0 || height < 0) { cout << "Error: positive values only." << endl; } 
            else {
                area = base * height * 0.5;
                cout << "\nThe area is " << area << endl;
            }
            break; 
        }
        case 4: break; // Returns to main menu loop
        default: cout << "The valid choices are 1-4." << endl;     
    }
}

// --- Question 5: Distance Traveled ---
void question5() {
    double speed; 
    int hours; 

    cout << "\nWhat is the speed of the vehicle in mph? "; cin >> speed; 
    cout << "How many hours has it traveled? "; cin >> hours; 

    if (speed < 0 || hours < 1) {
        cout << "Error: Please ensure both inputs are greater than 0" << endl; 
    }
    else {
        cout << "\nHour   Distance Traveled" << endl;
        cout << "----------------------------" << endl; 
        for (int i = 1; i <= hours; i++) {
            double distance = speed * i; 
            cout << " " << i << "            " << distance << endl; 
        }
    }
}