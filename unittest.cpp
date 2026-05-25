#include "square.h"

#include <cassert>
#include <cmath>
#include <sstream>
#include <stdexcept>

using namespace geometry;

void runUnitTests() {
    Point pointA(0, 0);
    Point pointB(0, 2);
    Point pointC(2, 2);
    Point pointD(2, 0);

    Square square(pointA, pointB, pointC, pointD);

    assert(std::abs(square.getArea() - 4.0) < 1e-9);
    assert(std::abs(square.getPerimeter() - 8.0) < 1e-9);
    assert(std::abs(square.getCircumradius() - std::sqrt(2.0)) < 1e-9);

    Square sameSquare(0, 0, 0, 2, 2, 2, 2, 0);
    assert(square == sameSquare);

    std::stringstream input;
    input << "(1, 1) (1, 3) (3, 3) (3, 1)";
    Square readSquare = Square::readFromStream(input);
    assert(std::abs(readSquare.getArea() - 4.0) < 1e-9);

    bool exceptionThrown = false;
    try {
        Square incorrectSquare(0, 0, 0, 2, 2, 2, 3, 0);
    }
    catch (const std::invalid_argument&) {
        exceptionThrown = true;
    }

    assert(exceptionThrown);
}
