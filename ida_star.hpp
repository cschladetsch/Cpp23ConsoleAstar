#pragma once

#include <vector>
#include "point.hpp"

std::vector<Point> ida_star(const std::vector<std::vector<int>>& grid, const Point& start, const Point& goal);
