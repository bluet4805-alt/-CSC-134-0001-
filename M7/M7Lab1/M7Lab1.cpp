#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <cstring>
#include <queue>
#include <unordered_map>
#include <limits>
#include <algorithm>
#include <string>

using namespace std;

// --- Direction Handling ---

enum Direction {
    NORTH = 1,
    SOUTH = 2,
    EAST = 4,
    WEST = 8
};

const std::pair<int, int> DIRECTION_OFFSETS[] = {
    {0, 0},     // Placeholder 0
    {0, -1},    // NORTH
    {0, 1},     // SOUTH
    {0, 0},     // Placeholder 3
    {1, 0},     // EAST
    {0, 0},     // Placeholder 5-7
    {0, 0},
    {0, 0},
    {-1, 0}     // WEST
};

const Direction OPPOSITES[] = {
    (Direction)0,
    SOUTH, NORTH, (Direction)0,
    WEST, (Direction)0, (Direction)0, (Direction)0,
    EAST
};

// --- Core Classes ---

class Cell {
private:
    int row, col, links;
public:
    Cell(int r, int c) : row(r), col(c), links(0) {}
    int getRow() const { return row; }
    int getCol() const { return col; }
    bool linked(Direction dir) const { return (links & dir) != 0; }
    void link(Direction dir) { links |= dir; }
    std::vector<Direction> getLinks() const {
        std::vector<Direction> res;
        if (linked(NORTH)) res.push_back(NORTH);
        if (linked(SOUTH)) res.push_back(SOUTH);
        if (linked(EAST)) res.push_back(EAST);
        if (linked(WEST)) res.push_back(WEST);
        return res;
    }
};

class Grid {
private:
    int rows, cols;
    std::vector<std::vector<Cell>> cells;
    std::mt19937 rng;
public:
    Grid(int r, int c) : rows(r), cols(c) {
        rng.seed(static_cast<unsigned int>(std::time(nullptr)));
        for (int i = 0; i < rows; i++) {
            std::vector<Cell> row;
            for (int j = 0; j < cols; j++) row.emplace_back(i, j);
            cells.push_back(row);
        }
    }
    int getRows() const { return rows; }
    int getCols() const { return cols; }
    bool isValid(int r, int c) const { return r >= 0 && r < rows && c >= 0 && c < cols; }
    Cell& at(int r, int c) { return cells[r][c]; }
    const Cell& at(int r, int c) const { return cells[r][c]; }
    int random(int min, int max) { return std::uniform_int_distribution<int>(min, max)(rng); }

    void linkCells(int r1, int c1, Direction dir) {
        int r2 = r1 + DIRECTION_OFFSETS[dir].second;
        int c2 = c1 + DIRECTION_OFFSETS[dir].first;
        if (isValid(r1, c1) && isValid(r2, c2)) {
            at(r1, c1).link(dir);
            at(r2, c2).link(OPPOSITES[dir]);
        }
    }

    void display(const std::vector<Cell*>& path = {}) const {
        auto isOnPath = [&](const Cell* c) {
            for (auto p : path) if (p == c) return true;
            return false;
        };

        std::cout << "+";
        for (int c = 0; c < cols; c++) std::cout << "---+";
        std::cout << "\n";

        for (int r = 0; r < rows; r++) {
            std::cout << "|";
            for (int c = 0; c < cols; c++) {
                std::cout << (isOnPath(&at(r, c)) ? " X " : "   ");
                std::cout << (c < cols - 1 && at(r, c).linked(EAST) ? " " : "|");
            }
            std::cout << "\n+";
            for (int c = 0; c < cols; c++) {
                std::cout << (r < rows - 1 && at(r, c).linked(SOUTH) ? "   +" : "---++");
            }
            std::cout << "\n";
        }
    }
};

// --- Algorithm Classes ---

class BinaryTreeMaze {
public:
    static void generate(Grid& grid) {
        for (int r = 0; r < grid.getRows(); r++) {
            for (int c = 0; c < grid.getCols(); c++) {
                std::vector<Direction> neighbors;
                if (r > 0) neighbors.push_back(NORTH);
                if (c < grid.getCols() - 1) neighbors.push_back(EAST);
                if (!neighbors.empty()) {
                    grid.linkCells(r, c, neighbors[grid.random(0, neighbors.size() - 1)]);
                }
            }
        }
    }
};

class Distances {
private:
    std::unordered_map<std::string, int> dists;
    std::string key(const Cell& c) const { return std::to_string(c.getRow()) + "," + std::to_string(c.getCol()); }
public:
    void set(const Cell& c, int d) { dists[key(c)] = d; }
    int get(const Cell& c) const {
        auto it = dists.find(key(c));
        return (it != dists.end()) ? it->second : std::numeric_limits<int>::max();
    }
    Cell* getMaxCell(Grid& grid) const {
        Cell* maxC = &grid.at(0,0);
        int maxD = -1;
        for (auto const& [k, v] : dists) {
            if (v > maxD) {
                int r = std::stoi(k.substr(0, k.find(',')));
                int c = std::stoi(k.substr(k.find(',') + 1));
                maxC = &grid.at(r, c);
                maxD = v;
            }
        }
        return maxC;
    }
};

class Dijkstra {
public:
    static Distances calculate(Grid& grid, Cell& start) {
        Distances d;
        d.set(start, 0);
        std::priority_queue<std::pair<int, Cell*>, std::vector<std::pair<int, Cell*>>, std::greater<>> pq;
        pq.push({0, &start});

        while (!pq.empty()) {
            Cell* curr = pq.top().second; pq.pop();
            for (Direction dir : curr->getLinks()) {
                Cell& nb = grid.at(curr->getRow() + DIRECTION_OFFSETS[dir].second, curr->getCol() + DIRECTION_OFFSETS[dir].first);
                int newD = d.get(*curr) + 1;
                if (newD < d.get(nb)) {
                    d.set(nb, newD);
                    pq.push({newD, &nb});
                }
            }
        }
        return d;
    }

    static std::vector<Cell*> solve(Grid& grid) {
        Distances d1 = calculate(grid, grid.at(0, 0));
        Cell* start = d1.getMaxCell(grid);
        Distances d2 = calculate(grid, *start);
        Cell* end = d2.getMaxCell(grid);

        std::vector<Cell*> path;
        Cell* curr = end;
        while (curr != start) {
            path.push_back(curr);
            for (Direction dir : curr->getLinks()) {
                Cell& nb = grid.at(curr->getRow() + DIRECTION_OFFSETS[dir].second, curr->getCol() + DIRECTION_OFFSETS[dir].first);
                if (d2.get(nb) < d2.get(*curr)) { curr = &nb; break; }
            }
        }
        path.push_back(start);
        return path;
    }
};

// --- Main Execution ---

int main(int argc, char* argv[]) {
    int r = (argc > 1) ? stoi(argv[1]) : 10;
    int c = (argc > 2) ? stoi(argv[2]) : 10;

    Grid grid(r, c);
    BinaryTreeMaze::generate(grid);
    
    std::cout << "Maze with Longest Path Solution:\n";
    std::vector<Cell*> path = Dijkstra::solve(grid);
    grid.display(path);
    
    std::cout << "Path Length: " << path.size() << " cells.\n";
    return 0;
}