#pragma once

#include <iostream>

namespace geometry {

class Point {
private:
    double x;
    double y;

public:
    Point(double x = 0.0, double y = 0.0);

    double getX() const;
    double getY() const;

    bool operator==(const Point& other) const;
    bool operator!=(const Point& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Point& point);
    friend std::istream& operator>>(std::istream& is, Point& point);
};

}
