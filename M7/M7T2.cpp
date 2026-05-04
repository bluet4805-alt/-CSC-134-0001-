// M7T2 - Rectangles 
// with some pointer examples 
// Blue 
// 4-29-26
// Gemini helped make corrections
// Silver

#include <iostream>
using namespace std;

// Rectangle class declaration (from Program 13-1)
class Rectangle {
private:
    double width;
    double length;
public:
    // Mutators (Setters)
    void setWidth(double w) { width = w; }
    void setLength(double len) { length = len; }

    // Accessors (Getters)
    double getWidth() const { return width; }
    double getLength() const { return length; }
    
    // Member function to calculate area
    double getArea() const { return width * length; }
};

int main() {
    Rectangle box;
    double rectWidth, rectLength;

    cout << "This program will calculate the area of a rectangle.\n";

    // Silver Tier: Input Validation for Width
    cout << "What is the width? ";
    cin >> rectWidth;
    while (rectWidth <= 0) {
        cout << "Invalid. Width must be greater than zero. Re-enter: ";
        cin >> rectWidth;
    }

    // Silver Tier: Input Validation for Length
    cout << "What is the length? ";
    cin >> rectLength;
    while (rectLength <= 0) {
        cin.clear(); // Good practice to clear potential input errors
        cout << "Invalid. Length must be greater than zero. Re-enter: ";
        cin >> rectLength;
    }

    // Store the validated values in the box object
    box.setWidth(rectWidth);
    box.setLength(rectLength);

    // Display the results
    cout << "\nHere is the rectangle's data:\n";
    cout << "Width: " << box.getWidth() << endl;
    cout << "Length: " << box.getLength() << endl;
    cout << "Area: " << box.getArea() << endl;

    return 0;
}