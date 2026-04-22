#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main() {
    // 1. Open an ofstream to 'gradient.ppm'
    ofstream outFile("gradient.ppm");

    const int width = 100;
    const int height = 100;

    [span_1](start_span)// 2. Write the PPM header (P3, dimensions, max color)[span_1](end_span)
    outFile << "P3" << endl;
    outFile << width << " " << height << endl;
    outFile << "255" << endl;

    [span_2](start_span)[span_3](start_span)// 3. Nested loops to generate pixel data[span_2](end_span)[span_3](end_span)
    for (int y = 0; y < height; y++) {        // Row loop
        for (int x = 0; x < width; x++) {    // Column loop
            
            // Calculate a ratio from 0.0 to 1.0 based on x-position.
            // Because you want ROYGBIV from Right to Left, 
            // x=99 will be Red and x=0 will be Violet.
            float ratio = (float)x / (width - 1);

            int r = 0, g = 0, b = 0;

            // Simple Multi-stage Gradient Logic for ROYGBIV
            if (ratio < 0.16) { // Violet to Indigo
                r = 148; g = 0; b = 211 + (int)(ratio * 6 * 44);
            } else if (ratio < 0.33) { // Indigo to Blue
                r = 148 - (int)((ratio-0.16) * 6 * 148); g = 0; b = 255;
            } else if (ratio < 0.50) { // Blue to Green
                r = 0; g = (int)((ratio-0.33) * 6 * 255); b = 255 - (int)((ratio-0.33) * 6 * 255);
            } else if (ratio < 0.66) { // Green to Yellow
                r = (int)((ratio-0.50) * 6 * 255); g = 255; b = 0;
            } else if (ratio < 0.83) { // Yellow to Orange
                r = 255; g = 255 - (int)((ratio-0.66) * 6 * 90); b = 0;
            } else { // Orange to Red
                r = 255; g = 165 - (int)((ratio-0.83) * 6 * 165); b = 0;
            }

            [span_4](start_span)// Write RGB values to file[span_4](end_span)
            outFile << r << " " << g << " " << b << "  ";
        }
        outFile << endl; 
    }

    outFile.close();
    cout << "Rainbow gradient 'gradient.ppm' generated!" << endl;

    return 0;
}
