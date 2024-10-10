#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include "ida_star.hpp"
#include "visualisation.hpp"

int main() {
    const int GRID_SIZE = 10;
    
    // Create a sample grid (0 for open, 1 for obstacle)
    std::vector<std::vector<int>> grid(GRID_SIZE, std::vector<int>(GRID_SIZE, 0));
    
    // Add some obstacles
    for (int i = 2; i < 8; ++i) grid[i][5] = 1;
    for (int i = 3; i < 7; ++i) grid[3][i] = 1;

    Point start(0, 0);
    Point goal(9, 9);

    std::cout << "Finding path from (" << start.x << "," << start.y << ") to ("
         << goal.x << "," << goal.y << ")..." << std::endl;

    auto path = ida_star(grid, start, goal);

    if (path.empty()) {
        std::cout << "No path found!" << std::endl;
        return 0;
    }

    std::cout << "Path found! Visualising..." << std::endl;

    // Visualise the path step by step
    for (size_t i = 0; i < path.size(); ++i) {
        visualise_grid(grid, path, path[i], start, goal);
        std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Delay for visualisation
        std::cout << "\033[" << GRID_SIZE + 3 << "A"; // Move cursor up
    }

    std::cout << "Path length: " << path.size() - 1 << std::endl;

    return 0;
}
