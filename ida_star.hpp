#pragma once

#include <vector>
#include <unordered_set>
#include "point.hpp"

struct Node {
    Point point;
    double g;
    double f;
    std::vector<Point> path;

    Node(Point p, double g_cost, double f_cost, std::vector<Point> path)
        : point(p), g(g_cost), f(f_cost), path(std::move(path)) {}
};

struct CompareNode {
    bool operator()(const Node& lhs, const Node& rhs) const {
        return lhs.f > rhs.f;  // For min-heap
    }
};

std::pair<std::vector<Point>, std::unordered_set<Point>> ida_star(
    const std::vector<std::vector<int>>& grid, 
    const Point& start, 
    const Point& goal
);
