#pragma once
#include <functional>

struct Point {
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    bool operator<(const Point& other) const {
        if (x == other.x) {
            return y < other.y;
        }
        return x < other.x;
    }

    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};

namespace std {
    template <>
    struct hash<Point> {
        size_t operator()(const Point& p) const {
            return hash<int>()(p.x) ^ (hash<int>()(p.y) << 1);
        }
    };
}
