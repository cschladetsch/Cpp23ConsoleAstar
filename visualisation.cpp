#include "visualisation.hpp"
#include "rang.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

const int GRID_SIZE = 10;

void visualise_grid(const std::vector<std::vector<int>>& grid, const std::vector<Point>& path, 
                    const Point& current, const Point& start, const Point& goal,
                    const std::unordered_set<Point>& visited) {
    std::vector<std::vector<char>> visual(GRID_SIZE, std::vector<char>(GRID_SIZE, '.'));

    // Mark obstacles
    for (int y = 0; y < GRID_SIZE; ++y) {
        for (int x = 0; x < GRID_SIZE; ++x) {
            if (grid[y][x] == 1) visual[y][x] = '#';
        }
    }

    // Mark visited nodes
    for (const auto& p : visited) {
        if (visual[p.y][p.x] == '.') visual[p.y][p.x] = 'v';
    }

    // Mark path
    for (const auto& p : path) {
        visual[p.y][p.x] = '*';
    }

    // Mark start, current, and goal
    visual[start.y][start.x] = 'S';
    visual[current.y][current.x] = 'C';
    visual[goal.y][goal.x] = 'G';

    // Move cursor to the top-left corner of the screen
    std::cout << "\033[H";

    // Print the grid
    std::cout << std::string(GRID_SIZE * 2 + 1, '-') << std::endl;
    for (const auto& row : visual) {
        std::cout << "|";
        for (char cell : row) {
            switch(cell) {
                case '.':
                    std::cout << rang::fg::gray << cell << ' ' << rang::fg::reset;
                    break;
                case '#':
                    std::cout << rang::fg::red << cell << ' ' << rang::fg::reset;
                    break;
                case '*':
                    std::cout << rang::fg::green << cell << ' ' << rang::fg::reset;
                    break;
                case 'v':
                    std::cout << rang::fg::cyan << cell << ' ' << rang::fg::reset;
                    break;
                case 'S':
                    std::cout << rang::fg::blue << cell << ' ' << rang::fg::reset;
                    break;
                case 'C':
                    std::cout << rang::fg::yellow << cell << ' ' << rang::fg::reset;
                    break;
                case 'G':
                    std::cout << rang::fg::magenta << cell << ' ' << rang::fg::reset;
                    break;
                default:
                    std::cout << cell << ' ';
            }
        }
        std::cout << "|" << std::endl;
    }
    std::cout << std::string(GRID_SIZE * 2 + 1, '-') << std::endl;

    // Print some stats
    std::cout << "Path length: " << path.size() << std::endl;
    std::cout << "Current position: (" << current.x << ", " << current.y << ")" << std::endl;
    std::cout << "Visited nodes: " << visited.size() << std::endl;
}
