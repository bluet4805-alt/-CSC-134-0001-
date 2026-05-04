// M7Lab1
// Blue 
// 5-4-26
// I used differnt codes written by gemini
// until I found one that was the least messy 
// easy to read and follow allong 


#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <algorithm>
#include <map>
#include <queue>
#include <string>

using namespace std;

// --- 1. CONFIGURATION & DIRECTIONS ---
enum Direction { NORTH = 1, SOUTH = 2, EAST = 4, WEST = 8 };

// Maps directions to coordinate changes {x, y}
const pair<int, int> OFFSETS[] = {
    {0, 0}, {0, -1}, {0, 1}, {0, 0}, {1, 0}, {0, 0}, {0, 0}, {0, 0}, {-1, 0}
};

const Direction OPPOSITE[] = {
    (Direction)0, SOUTH, NORTH, (Direction)0, WEST, (Direction)0, (Direction)0, (Direction)0, EAST
};

// --- 2. CORE DATA STRUCTURES ---
class Cell {
public:
    int r, c, links = 0;
    Cell(int row, int col) : r(row), c(col) {}
    bool linked(Direction d) const { return (links & d) != 0; }
    void link(Direction d) { links |= d; }
};

class Grid {
public:
    int rows, cols;
    vector<vector<Cell>> cells;
    mt19937 rng{unsigned(time(nullptr))};

    Grid(int r, int c) : rows(r), cols(c) {
        for (int i = 0; i < rows; ++i) {
            vector<Cell> row_vec;
            for (int j = 0; j < cols; ++j) row_vec.emplace_back(i, j);
            cells.push_back(row_vec);
        }
    }

    void link(int r1, int c1, Direction d) {
        int r2 = r1 + OFFSETS[d].second;
        int c2 = c1 + OFFSETS[d].first;
        if (r2 >= 0 && r2 < rows && c2 >= 0 && c2 < cols) {
            cells[r1][c1].link(d);
            cells[r2][c2].link(OPPOSITE[d]);
        }
    }

    // CLEAN GRID RENDERER
    void display(const vector<Cell*>& path = {}) const {
        auto onPath = [&](const Cell* target) {
            for (auto p : path) if (p == target) return true;
            return false;
        };

        // Render top wall
        cout << "+";
        for (int j = 0; j < cols; ++j) cout << "---+";
        cout << "\n";

        for (int i = 0; i < rows; ++i) {
            string mid = "|";   // Walls and Path
            string bottom = "+"; // Floors

            for (int j = 0; j < cols; ++j) {
                const Cell& cell = cells[i][j];
                
                // Path Indicator (centered X)
                mid += (onPath(&cell) ? " X " : "   ");
                
                // East wall logic
                mid += (cell.linked(EAST) ? " " : "|");

                // South wall logic
                bottom += (cell.linked(SOUTH) ? "   +" : "---+");
            }
            cout << mid << "\n" << bottom << "\n";
        }
    }
};

// --- 3. ALGORITHMS ---
void binary_tree(Grid& g) {
    for (int i = 0; i < g.rows; ++i) {
        for (int j = 0; j < g.cols; ++j) {
            vector<Direction> neighbors;
            if (i > 0) neighbors.push_back(NORTH);
            if (j < g.cols - 1) neighbors.push_back(EAST);
            
            if (!neighbors.empty()) {
                Direction d = neighbors[uniform_int_distribution<int>(0, neighbors.size()-1)(g.rng)];
                g.link(i, j, d);
            }
        }
    }
}

// Simplified Dijkstra implementation for the "Solution"
vector<Cell*> solve(Grid& g) {
    auto bfs = [&](Cell* start) {
        map<Cell*, int> dists;
        queue<Cell*> q;
        dists[start] = 0;
        q.push(start);
        while(!q.empty()){
            Cell* curr = q.front(); q.pop();
            for(Direction d : {NORTH, SOUTH, EAST, WEST}){
                if(curr->linked(d)){
                    Cell* next = &g.cells[curr->r + OFFSETS[d].second][curr->c + OFFSETS[d].first];
                    if(dists.find(next) == dists.end()){
                        dists[next] = dists[curr] + 1;
                        q.push(next);
                    }
                }
            }
        }
        return dists;
    };

    // Find the longest path (the "ideal" solution)
    auto d1 = bfs(&g.cells[0][0]);
    Cell* start_node = max_element(d1.begin(), d1.end(), [](auto& a, auto& b){return a.second < b.second;})->first;
    auto d2 = bfs(start_node);
    Cell* end_node = max_element(d2.begin(), d2.end(), [](auto& a, auto& b){return a.second < b.second;})->first;

    // Backtrack to build path
    vector<Cell*> path;
    Cell* curr = end_node;
    while(curr != start_node){
        path.push_back(curr);
        for(Direction d : {NORTH, SOUTH, EAST, WEST}){
            if(curr->linked(d)){
                Cell* next = &g.cells[curr->r + OFFSETS[d].second][curr->c + OFFSETS[d].first];
                if(d2[next] < d2[curr]) { curr = next; break; }
            }
        }
    }
    path.push_back(start_node);
    return path;
}

// --- 4. MAIN ---
int main() {
    // 5x5 is small enough to look perfect in a terminal/GitHub README
    Grid maze(5, 5); 
    binary_tree(maze);
    vector<Cell*> solution = solve(maze);
    
    cout << "  --- MINI MAZE SOLUTION ---\n";
    maze.display(solution);
    
    return 0;
}