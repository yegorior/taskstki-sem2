#pragma once

#include "polygon.h"

namespace geometry {

class Square : public Polygon {
private:
    static const int VERTEX_COUNT = 4;

    bool isValidSquare() const;
    static double getDistance(const Point& first, const Point& second);

public:
    Square(const Point& first, const Point& second, const Point& third, const Point& fourth);
    Square(double x1, double y1,
           double x2, double y2,
           double x3, double y3,
           double x4, double y4);

    std::string ToString() const override;
    double getArea() const override;
    double getPerimeter() const override;
    double getCircumradius() const override;
    void read(std::istream& is) override;

    bool operator==(const Square& other) const;
    bool operator!=(const Square& other) const;

    static std::string ToString(const Square& square);
    static Square readFromStream(std::istream& is);
};

}
