// Gemini Displays an apple 
// I gave Gemini my requirements of : 

// Image must be at least 100×100 pixels
// Must use `ofstream` to write to a `.ppm` file
// Must use nested loops to generate pixel data
// Must compile and run without errors
// Output image must be viewable
// I want the image to be an apple 

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main() {
    // 1. Open an ofstream to 'apple.ppm'
    ofstream outFile("apple.ppm");

    if (!outFile) {
        cerr << "Error: Could not open file for writing!" << endl;
        return 1;
    }

    const int width = 100;
    const int height = 100;

    // 2. Write the PPM header (P3, dimensions, max color)
    // P3 means ASCII RGB, 100 100 is the size, 255 is the max color value
    outFile << "P3" << endl;
    outFile << width << " " << height << endl;
    outFile << "255" << endl;

    // 3. Use nested for loops to write RGB values for each pixel
    for (int y = 0; y < height; y++) {        // Row loop (y-coordinate)
        for (int x = 0; x < width; x++) {    // Column loop (x-coordinate)
            
            // Define apple center and radius
            float centerX = 50.0f;
            float centerY = 55.0f;
            float radius = 30.0f;

            // Distance formula: sqrt((x-h)^2 + (y-k)^2)
            float distance = sqrt(pow(x - centerX, 2) + pow(y - centerY, 2));

            // Check if pixel is within the apple body (a slightly squashed circle)
            // We divide (y-centerY) by 0.9 to make it slightly taller/oval
            float appleShape = sqrt(pow(x - centerX, 2) + pow((y - centerY) / 0.9, 2));

            // Determine Pixel Color
            if (appleShape < radius) {
                // Apple Body: Red (255, 30, 30)
                outFile << "255 30 30 ";
            } 
            else if (x >= 48 && x <= 52 && y >= 15 && y <= 25) {
                // Stem: Brown (101, 67, 33)
                outFile << "101 67 33 ";
            }
            else if (pow(x-58, 2) + pow(y-22, 2) < 40 && x > 50 && y < 25) {
                // Leaf: Green (34, 139, 34)
                outFile << "34 139 34 ";
            }
            else {
                // Background: Light Blue (173, 216, 230)
                outFile << "173 216 230 ";
            }
        }
        outFile << endl; // New line after each row for readability
    }

    // 4. Close the file
    outFile.close();

    cout << "Image 'apple.ppm' has been generated successfully!" << endl;

    return 0;
}
