#include "ida_star.hpp"
#include <limits>
#include <cmath>
#include <algorithm>

const int GRID_SIZE = 10;

// Euclidean distance heuristic
double heuristic(const Point& a, const Point& b) {
    return std::sqrt(std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2));
}

bool is_valid(const Point& p) {
    return p.x >= 0 && p.x < GRID_SIZE && p.y >= 0 && p.y < GRID_SIZE;
}

double dls(const std::vector<std::vector<int>>& grid, Point current, const Point& goal, 
           double g, double bound, std::vector<Point>& path, std::vector<Point>& best_path) {
    double f = g + heuristic(current, goal);
    if (f > bound) return f;
    if (current.x == goal.x && current.y == goal.y) {
        best_path = path;
        return -1; // Goal found
    }

    double min = std::numeric_limits<double>::infinity();
    std::vector<std::pair<int, int>> directions = {
        {0, 1}, {1, 0}, {0, -1}, {-1, 0},  // Cardinal directions
        {1, 1}, {1, -1}, {-1, 1}, {-1, -1}  // Diagonal directions
    };

    for (const auto& [dx, dy] : directions) {
        Point next(current.x + dx, current.y + dy);
        if (is_valid(next) && grid[next.y][next.x] == 0) {
            // Use 1.0 for cardinal moves, sqrt(2) for diagonal moves
            double move_cost = (dx == 0 || dy == 0) ? 1.0 : std::sqrt(2);
            path.push_back(next);
            double t = dls(grid, next, goal, g + move_cost, bound, path, best_path);
            if (t == -1) return -1; // Goal found
            if (t < min) min = t;
            path.pop_back();
        }
    }

    return min;
}

std::vector<Point> ida_star(const std::vector<std::vector<int>>& grid, const Point& start, const Point& goal) {
    double bound = heuristic(start, goal);
    std::vector<Point> path = {start};
    std::vector<Point> best_path;

    while (bound < std::numeric_limits<double>::infinity()) {
        double t = dls(grid, start, goal, 0, bound, path, best_path);
        if (t == -1) return best_path; // Shortest path found
        if (t == std::numeric_limits<double>::infinity()) return {}; // No path found
        bound = t;
    }

    return {}; // No path found
}
