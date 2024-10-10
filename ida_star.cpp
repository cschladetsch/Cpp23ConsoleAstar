
#include "ida_star.hpp"
#include <limits>
#include <cmath>
#include <algorithm>

const int GRID_SIZE = 10;

double heuristic(const Point& a, const Point& b) {
    return std::sqrt(std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2));
}

bool is_valid(const Point& p) {
    return p.x >= 0 && p.x < GRID_SIZE && p.y >= 0 && p.y < GRID_SIZE;
}

std::pair<std::vector<Point>, std::unordered_set<Point>> ida_star(
    const std::vector<std::vector<int>>& grid, 
    const Point& start, 
    const Point& goal
) {
    double f_limit = heuristic(start, goal);
    std::vector<Node> heap;
    std::unordered_set<Point> visited;

    heap.emplace_back(start, 0, f_limit, std::vector<Point>{start});
    std::make_heap(heap.begin(), heap.end(), CompareNode());

    std::vector<std::pair<int, int>> directions = {
        {0, 1}, {1, 0}, {0, -1}, {-1, 0},  // Cardinal directions
        {1, 1}, {1, -1}, {-1, 1}, {-1, -1}  // Diagonal directions
    };

    while (!heap.empty()) {
        std::pop_heap(heap.begin(), heap.end(), CompareNode());
        Node current = heap.back();
        heap.pop_back();

        if (current.point == goal) {
            return {current.path, visited};
        }

        if (current.f > f_limit) {
            f_limit = current.f;
            heap.clear();
            visited.clear();
            heap.emplace_back(start, 0, f_limit, std::vector<Point>{start});
            std::make_heap(heap.begin(), heap.end(), CompareNode());
            continue;
        }

        visited.insert(current.point);

        for (const auto& [dx, dy] : directions) {
            Point next(current.point.x + dx, current.point.y + dy);
            if (!is_valid(next) || grid[next.y][next.x] == 1) continue;

            double move_cost = (dx == 0 || dy == 0) ? 1.0 : std::sqrt(2);
            double new_g = current.g + move_cost;
            double new_f = new_g + heuristic(next, goal);

            std::vector<Point> new_path = current.path;
            new_path.push_back(next);

            heap.emplace_back(next, new_g, new_f, std::move(new_path));
            std::push_heap(heap.begin(), heap.end(), CompareNode());
        }
    }

    return {{}, visited};  // No path found
}
