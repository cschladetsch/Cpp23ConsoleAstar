#include "ida_star.hpp"
#include <limits>
#include <cmath>

const int GRID_SIZE = 10;

int heuristic(const Point& a, const Point& b) {
    return std::abs(a.x - b.x) + std::abs(a.y - b.y);
}

bool is_valid(const Point& p) {
    return p.x >= 0 && p.x < GRID_SIZE && p.y >= 0 && p.y < GRID_SIZE;
}

std::pair<bool, int> dls(const std::vector<std::vector<int>>& grid, Point current, const Point& goal, 
                         int g, int bound, std::vector<Point>& path) {
    int f = g + heuristic(current, goal);
    if (f > bound) return {false, f};
    if (current.x == goal.x && current.y == goal.y) return {true, f};

    int min = std::numeric_limits<int>::max();
    std::vector<Point> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    for (const auto& dir : directions) {
        Point next(current.x + dir.x, current.y + dir.y);
        if (is_valid(next) && grid[next.y][next.x] == 0) {
            path.push_back(next);
            auto [found, t] = dls(grid, next, goal, g + 1, bound, path);
            if (found) return {true, t};
            if (t < min) min = t;
            path.pop_back();
        }
    }

    return {false, min};
}

std::vector<Point> ida_star(const std::vector<std::vector<int>>& grid, const Point& start, const Point& goal) {
    int bound = heuristic(start, goal);
    std::vector<Point> path = {start};

    while (true) {
        auto [found, t] = dls(grid, start, goal, 0, bound, path);
        if (found) return path;
        if (t == std::numeric_limits<int>::max()) return {}; // No path found
        bound = t;
    }
}
