#include "square.h"

#include <cmath>
#include <limits>
#include <sstream>
#include <stdexcept>
#include <vector>

namespace geometry {

Square::Square(const Point& first, const Point& second, const Point& third, const Point& fourth) {
    vertices = { first, second, third, fourth };

    if (!isValidSquare()) {
        throw std::invalid_argument("Некорректные вершины для квадрата");
    }
}

Square::Square(const double x1, const double y1,
               const double x2, const double y2,
               const double x3, const double y3,
               const double x4, const double y4) {
    vertices = {
        Point(x1, y1),
        Point(x2, y2),
        Point(x3, y3),
        Point(x4, y4)
    };

    if (!isValidSquare()) {
        throw std::invalid_argument("Некорректные вершины для квадрата");
    }
}

double Square::getDistance(const Point& first, const Point& second) {
    const double dx = second.getX() - first.getX();
    const double dy = second.getY() - first.getY();

    return std::sqrt(dx * dx + dy * dy);
}

bool Square::isValidSquare() const {
    if (vertices.size() != VERTEX_COUNT) {
        return false;
    }

    const double eps = std::numeric_limits<double>::epsilon();
    const double side = getDistance(vertices[0], vertices[1]);

    if (side <= eps) {
        return false;
    }

    for (std::size_t i = 0; i < VERTEX_COUNT; ++i) {
        const Point& current = vertices[i];
        const Point& next = vertices[(i + 1) % VERTEX_COUNT];
        const Point& afterNext = vertices[(i + 2) % VERTEX_COUNT];

        const double currentSide = getDistance(current, next);

        if (std::abs(currentSide - side) > eps) {
            return false;
        }

        const double firstVectorX = next.getX() - current.getX();
        const double firstVectorY = next.getY() - current.getY();
        const double secondVectorX = afterNext.getX() - next.getX();
        const double secondVectorY = afterNext.getY() - next.getY();
        const double scalarProduct = firstVectorX * secondVectorX + firstVectorY * secondVectorY;

        if (std::abs(scalarProduct) > eps) {
            return false;
        }
    }

    return true;
}

std::string Square::ToString() const {
    std::stringstream stream;
    stream << "Square: ";

    for (std::size_t i = 0; i < vertices.size(); ++i) {
        stream << "v" << (i + 1) << "=" << vertices[i];

        if (i + 1 < vertices.size()) {
            stream << ", ";
        }
    }

    return stream.str();
}

double Square::getArea() const {
    const double side = getPerimeter() / VERTEX_COUNT;
    return side * side;
}

double Square::getPerimeter() const {
    if (vertices.size() != VERTEX_COUNT) {
        return 0.0;
    }

    double perimeter = 0.0;

    for (std::size_t i = 0; i < VERTEX_COUNT; ++i) {
        perimeter += getDistance(vertices[i], vertices[(i + 1) % VERTEX_COUNT]);
    }

    return perimeter;
}

double Square::getCircumradius() const {
    const double side = getPerimeter() / VERTEX_COUNT;
    return side * std::sqrt(2.0) / 2.0;
}

void Square::read(std::istream& is) {
    std::vector<Point> enteredVertices(VERTEX_COUNT);

    for (std::size_t i = 0; i < VERTEX_COUNT; ++i) {
        is >> enteredVertices[i];
    }

    vertices = enteredVertices;

    if (!isValidSquare()) {
        throw std::invalid_argument("Некорректные вершины для квадрата при чтении");
    }
}

bool Square::operator==(const Square& other) const {
    return vertices == other.vertices;
}

bool Square::operator!=(const Square& other) const {
    return !(*this == other);
}

std::string Square::ToString(const Square& square) {
    return square.ToString();
}

Square Square::readFromStream(std::istream& is) {
    std::vector<Point> readVertices(VERTEX_COUNT);

    for (std::size_t i = 0; i < VERTEX_COUNT; ++i) {
        is >> readVertices[i];
    }

    return Square(readVertices[0], readVertices[1], readVertices[2], readVertices[3]);
}

}
