// Emoji checker board 
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

const int WIDTH = 800;
const int HEIGHT = 800;
const int CHECK_SIZE = 100;

struct Color {
    int r, g, b;
};

// Helper function to check if a point is inside a circle
bool isInsideCircle(int x, int y, int cx, int cy, int radius) {
    return (pow(x - cx, 2) + pow(y - cy, 2)) <= pow(radius, 2);
}

int main() {
    ofstream img("emoji_checkerboard.ppm");
    img << "P3" << endl; // PPM Magic Number
    img << WIDTH << " " << HEIGHT << endl;
    img << "255" << endl; // Max color value

    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            Color pixel;

            // 1. Create Checkerboard Background (Light/Dark Grey)
            if ((x / CHECK_SIZE + y / CHECK_SIZE) % 2 == 0) {
                pixel = {200, 200, 200};
            } else {
                pixel = {150, 150, 150};
            }

            // 2. Draw Laughing Emoji (Yellow Circle)
            int centerX = WIDTH / 2;
            int centerY = HEIGHT / 2;
            int headRadius = 300;

            if (isInsideCircle(x, y, centerX, centerY, headRadius)) {
                pixel = {255, 204, 0}; // Yellow face

                // Eyes (Squinting "> <" style for laughing)
                // Left Eye
                if (abs((y - (centerY - 80)) + (x - (centerX - 120))) < 10 && x < centerX - 80 && x > centerX - 160 && y < centerY - 40 && y > centerY - 120) pixel = {102, 51, 0};
                if (abs((y - (centerY - 80)) - (x - (centerX - 120))) < 10 && x < centerX - 80 && x > centerX - 160 && y < centerY - 40 && y > centerY - 120) pixel = {102, 51, 0};
                
                // Right Eye
                if (abs((y - (centerY - 80)) + (x - (centerX + 120))) < 10 && x > centerX + 80 && x < centerX + 160 && y < centerY - 40 && y > centerY - 120) pixel = {102, 51, 0};
                if (abs((y - (centerY - 80)) - (x - (centerX + 120))) < 10 && x > centerX + 80 && x < centerX + 160 && y < centerY - 40 && y > centerY - 120) pixel = {102, 51, 0};

                // Mouth (Big Open Semi-circle)
                if (isInsideCircle(x, y, centerX, centerY + 50, 150) && y > centerY + 50) {
                    pixel = {255, 255, 255}; // White teeth/mouth
                }
            }

            img << pixel.r << " " << pixel.g << " " << pixel.b << " ";
        }
        img << endl;
    }

    img.close();
    cout << "Image generated: emoji_checkerboard.ppm" << endl;
    return 0;
}
