#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <random>
#include <ctime>

using namespace std;

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

struct Cell {
    int ring, col;
    bool joined_inward = false;
    bool joined_cw = false; // Clockwise link
};

class PolarMaze {
private:
    int num_rings;
    vector<vector<Cell>> rings;
    mt19937 rng;

public:
    PolarMaze(int rings_count) : num_rings(rings_count) {
        rng.seed(static_cast<unsigned int>(time(nullptr)));
        setup_cells();
    }

    void setup_cells() {
        double row_height = 1.0 / num_rings;
        rings.push_back({Cell{0, 0}}); // Center cell

        for (int r = 1; r < num_rings; r++) {
            double radius = (double)r / num_rings;
            double circumference = 2 * M_PI * radius;
            int prev_count = rings[r - 1].size();
            int estimated_count = circumference / row_height;
            
            // Doubling logic to keep cells square-ish
            int count = prev_count * (estimated_count / prev_count);
            vector<Cell> current_ring;
            for (int c = 0; c < count; c++) {
                current_ring.push_back(Cell{r, c});
            }
            rings.push_back(current_ring);
        }
    }

    void generate() {
        // Binary Tree Algorithm adapted for Polar coordinates
        for (int r = 1; r < num_rings; r++) {
            for (int c = 0; c < rings[r].size(); c++) {
                int ratio = rings[r].size() / rings[r - 1].size();
                
                uniform_int_distribution<int> dist(0, 1);
                if (dist(rng) == 0 || r == 0) {
                    rings[r][c].joined_inward = true;
                } else {
                    // Link to next cell in ring (with wrap-around)
                    rings[r][c].joined_cw = true;
                }
            }
        }
    }

    void save_svg(string filename) {
        ofstream file(filename);
        int size = 800;
        int center = size / 2;
        double unit = (size / 2.0) / num_rings;

        file << "<svg width=\"" << size << "\" height=\"" << size << "\" xmlns=\"http://www.w3.org/2000/svg\">" << endl;
        file << "<rect width=\"100%\" height=\"100%\" fill=\"white\"/>" << endl;

        for (auto& ring : rings) {
            for (auto& cell : ring) {
                if (cell.ring == 0) continue;

                double theta = 2 * M_PI / ring.size();
                double angle_start = cell.col * theta;
                double angle_end = (cell.col + 1) * theta;
                
                int r_inner = cell.ring * unit;
                int r_outer = (cell.ring + 1) * unit;

                // Draw the inward wall (circular arc) if not joined
                if (!cell.joined_inward) {
                    file << "<path d=\"M " << center + r_inner * cos(angle_start) << " " << center + r_inner * sin(angle_start)
                         << " A " << r_inner << " " << r_inner << " 0 0 1 " 
                         << center + r_inner * cos(angle_end) << " " << center + r_inner * sin(angle_end)
                         << "\" stroke=\"black\" fill=\"none\" stroke-width=\"2\"/>" << endl;
                }

                // Draw the Clockwise wall (radial line) if not joined
                if (!cell.joined_cw) {
                    file << "<line x1=\"" << center + r_inner * cos(angle_end) << "\" y1=\"" << center + r_inner * sin(angle_end)
                         << "\" x2=\"" << center + r_outer * cos(angle_end) << "\" y2=\"" << center + r_outer * sin(angle_end)
                         << "\" stroke=\"black\" stroke-width=\"2\"/>" << endl;
                }
            }
        }
        // Draw the outermost boundary
        file << "<circle cx=\"" << center << "\" cy=\"" << center << "\" r=\"" << num_rings * unit << "\" stroke=\"black\" fill=\"none\" stroke-width=\"2\"/>" << endl;
        file << "</svg>" << endl;
        file.close();
        cout << "Maze saved to " << filename << endl;
    }
};

int main() {
    PolarMaze maze(20); // 20 concentric rings
    maze.generate();
    maze.save_svg("maze.svg");
    return 0;
}
