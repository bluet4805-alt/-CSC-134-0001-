// M5LAB2
// Fixing someones code 
// Blue 
// 3-30-26

#include <iostream>
using namespace std;

// Declare (Write the prototypes for)
// the getLength,
// getWidth, getArea, and displayData
// functions here.
double getLength(); 
double getWidth(); 
double getArea(double length, double width);
void displayData(double length, double width, double area); 

int main()
{
	// This program calculates the area of a rectangle.
	// TODO: fix any syntax errors
	
   double length,    // The rectangle's length
          width,     // The rectangle's width
          area;      // The rectangle's area
          
   // Get the rectangle's length.
   length = getLength();
   
   // Get the rectangle's width.
    width = getWidth();
   
   // Get the rectangle's area.
   area = getArea(length, width);
   
   // Display the rectangle's data.
   // **** displayData(length, width, area);
          
   return 0;
}

//***************************************************
// TODO: write the getLength, getWidth, getArea,    *
// and displayData functions below.                 *
//***************************************************

double getLength() { 
// Ask for rectangle length, width, and area 
   double length; 
   cout << "Please enter rectangle length: "; 
   cin >> length; 
   return length; 
   
}

double getWidth  () {
   double width;
   cout << "Please enter the width of the rectangle: "; 
   cin >> width;
   return width; 
}

double getArea (double length, double width) {
   double area = (length * width); 
   cout << "The area of the rectangle is: " << area << endl; 
   return area; 
   cout << " The area of the rectangle is " << displayData  << endl; 
}

