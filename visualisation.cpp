#include "visualisation.hpp"
#include <iostream>
#include <string>

const int GRID_SIZE = 10;

void visualise_grid(const std::vector<std::vector<int>>& grid, const std::vector<Point>& path, 
                    const Point& current, const Point& start, const Point& goal) {
    std::vector<std::vector<char>> visual(GRID_SIZE, std::vector<char>(GRID_SIZE, '.'));

    // Mark obstacles
    for (int y = 0; y < GRID_SIZE; ++y) {
        for (int x = 0; x < GRID_SIZE; ++x) {
            if (grid[y][x] == 1) visual[y][x] = '#';
        }
    }

    // Mark path
    for (const auto& p : path) {
        visual[p.y][p.x] = '*';
    }

    // Mark start, current, and goal
    visual[start.y][start.x] = 'S';
    visual[current.y][current.x] = 'C';
    visual[goal.y][goal.x] = 'G';

    // Print the grid
    std::cout << std::string(GRID_SIZE * 2 + 1, '-') << std::endl;
    for (const auto& row : visual) {
        std::cout << "|";
        for (char cell : row) {
            std::cout << cell << " ";
        }
        std::cout << "|" << std::endl;
    }
    std::cout << std::string(GRID_SIZE * 2 + 1, '-') << std::endl;
}
