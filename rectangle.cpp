#define _USE_MATH_DEFINES

#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <vector>

#include "rectangle.h"

using namespace std;

Rectangle::Rectangle()
    : firstVertex(0, 0), secondVertex(1, 0), thirdVertex(1, 1), fourthVertex(0, 1) {
}

Rectangle::Rectangle(const Point& pointA, const Point& pointB, const Point& pointC, const Point& pointD)
    : firstVertex(pointA), secondVertex(pointB), thirdVertex(pointC), fourthVertex(pointD) {
    sortPoints();

    if (!isRectangle()) {
        cout << "Ошибка: точки не образуют прямоугольник!" << endl;
        exit(EXIT_FAILURE);
    }
}

bool Rectangle::isRectangle() const {
    double sideOne = firstVertex.distanceTo(secondVertex);
    double sideTwo = secondVertex.distanceTo(thirdVertex);
    double sideThree = thirdVertex.distanceTo(fourthVertex);
    double sideFour = fourthVertex.distanceTo(firstVertex);

    double diagonalOne = firstVertex.distanceTo(thirdVertex);
    double diagonalTwo = secondVertex.distanceTo(fourthVertex);

    bool allSidesExist = sideOne > std::numeric_limits<double>::epsilon()
        && sideTwo > std::numeric_limits<double>::epsilon()
        && sideThree > std::numeric_limits<double>::epsilon()
        && sideFour > std::numeric_limits<double>::epsilon();

    bool oppositeSidesEqual = fabs(sideOne - sideThree) < std::numeric_limits<double>::epsilon()
        && fabs(sideTwo - sideFour) < std::numeric_limits<double>::epsilon();

    bool diagonalsEqual = fabs(diagonalOne - diagonalTwo) < std::numeric_limits<double>::epsilon();

    return allSidesExist && oppositeSidesEqual && diagonalsEqual;
}

void Rectangle::sortPoints() {
    double middleX = (firstVertex.getX() + secondVertex.getX() + thirdVertex.getX() + fourthVertex.getX()) / 4.0;
    double middleY = (firstVertex.getY() + secondVertex.getY() + thirdVertex.getY() + fourthVertex.getY()) / 4.0;

    Point middlePoint(middleX, middleY);

    vector<Point> rectanglePoints = { firstVertex, secondVertex, thirdVertex, fourthVertex };

    sort(rectanglePoints.begin(), rectanglePoints.end(), [middlePoint](const Point& leftPoint, const Point& rightPoint) {
        double leftAngle = atan2(leftPoint.getY() - middlePoint.getY(), leftPoint.getX() - middlePoint.getX());
        double rightAngle = atan2(rightPoint.getY() - middlePoint.getY(), rightPoint.getX() - middlePoint.getX());

        if (leftAngle < 0) {
            leftAngle += 2 * M_PI;
        }

        if (rightAngle < 0) {
            rightAngle += 2 * M_PI;
        }

        return leftAngle < rightAngle;
    });

    firstVertex = rectanglePoints[0];
    secondVertex = rectanglePoints[1];
    thirdVertex = rectanglePoints[2];
    fourthVertex = rectanglePoints[3];
}

Point Rectangle::getP1() const {
    return firstVertex;
}

Point Rectangle::getP2() const {
    return secondVertex;
}

Point Rectangle::getP3() const {
    return thirdVertex;
}

Point Rectangle::getP4() const {
    return fourthVertex;
}

vector<Point> Rectangle::getAllPoints() const {
    return { firstVertex, secondVertex, thirdVertex, fourthVertex };
}

double Rectangle::getWidth() const {
    return firstVertex.distanceTo(secondVertex);
}

double Rectangle::getHeight() const {
    return secondVertex.distanceTo(thirdVertex);
}

double Rectangle::getS() const {
    return getWidth() * getHeight();
}

double Rectangle::getPerimeter() const {
    return 2 * (getWidth() + getHeight());
}

std::ostream& operator<<(std::ostream& outputStream, const Rectangle& currentRectangle) {
    outputStream << currentRectangle.firstVertex << " "
        << currentRectangle.secondVertex << " "
        << currentRectangle.thirdVertex << " "
        << currentRectangle.fourthVertex;

    return outputStream;
}

std::istream& operator>>(std::istream& inputStream, Rectangle& currentRectangle) {
    inputStream >> currentRectangle.firstVertex
        >> currentRectangle.secondVertex
        >> currentRectangle.thirdVertex
        >> currentRectangle.fourthVertex;

    currentRectangle.sortPoints();

    if (!currentRectangle.isRectangle()) {
        cout << "Ошибка: точки не образуют прямоугольник!" << endl;
        exit(EXIT_FAILURE);
    }

    return inputStream;
}
