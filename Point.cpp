#include "Point.h"

#include <cmath>
#include <limits>

namespace geometry {

Point::Point(double x, double y) : x(x), y(y) {}

double Point::getX() const {
    return x;
}

double Point::getY() const {
    return y;
}

bool Point::operator==(const Point& other) const {
    return std::abs(x - other.x) < std::numeric_limits<double>::epsilon() &&
           std::abs(y - other.y) < std::numeric_limits<double>::epsilon();
}

bool Point::operator!=(const Point& other) const {
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& os, const Point& point) {
    os << "(" << point.x << ", " << point.y << ")";
    return os;
}

std::istream& operator>>(std::istream& is, Point& point) {
    char firstChar;
    is >> firstChar;

    if (firstChar == '(') {
        char comma;
        char lastChar;
        is >> point.x >> comma >> point.y >> lastChar;
    } else {
        is.unget();
        is >> point.x >> point.y;
    }

    return is;
}

}
