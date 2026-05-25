#pragma once

#include "Point.h"

#include <iostream>
#include <string>
#include <vector>

namespace geometry {

class Polygon {
protected:
    std::vector<Point> vertices;

public:
    Polygon() = default;
    virtual ~Polygon() = default;

    virtual std::string ToString() const = 0;
    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual double getCircumradius() const = 0;
    virtual void read(std::istream& is) = 0;

    friend std::ostream& operator<<(std::ostream& os, const Polygon& polygon);
    friend std::istream& operator>>(std::istream& is, Polygon& polygon);

    static std::string ToString(const Polygon& polygon);
};

}
