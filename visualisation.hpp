#pragma once

#include <vector>
#include "point.hpp"

void visualise_grid(const std::vector<std::vector<int>>& grid, const std::vector<Point>& path, 
                    const Point& current, const Point& start, const Point& goal);
