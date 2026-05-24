#include <cmath>
#include "point.h"

Point::Point(const double xValue, const double yValue)
    : coordinateX(xValue), coordinateY(yValue)
{
}

double Point::getX() const
{
    return coordinateX;
}

double Point::getY() const
{
    return coordinateY;
}

double Point::distanceTo(const Point& anotherPoint) const
{
    double differenceX = coordinateX - anotherPoint.coordinateX;
    double differenceY = coordinateY - anotherPoint.coordinateY;

    return sqrt(differenceX * differenceX + differenceY * differenceY);
}

std::ostream& operator<<(std::ostream& outputStream, const Point& currentPoint)
{
    outputStream << "(" << currentPoint.coordinateX << ";" << currentPoint.coordinateY << ")";
    return outputStream;
}

std::istream& operator>>(std::istream& inputStream, Point& currentPoint)
{
    inputStream >> currentPoint.coordinateX >> currentPoint.coordinateY;
    return inputStream;
}
