#pragma once

#include <iostream>
#include <vector>
#include "point.h"

class Rectangle
{
private:
    /**
     * @brief вершины прямоугольника
     */
    Point firstVertex, secondVertex, thirdVertex, fourthVertex;

    /**
     * @brief проверяет, образуют ли точки прямоугольник
     * @return true, если точки образуют прямоугольник
     */
    bool isRectangle() const;

    /**
     * @brief упорядочивает вершины вокруг центра фигуры
     */
    void sortPoints();

public:
    /**
     * @brief конструктор прямоугольника по умолчанию
     */
    Rectangle();

    /**
     * @brief конструктор прямоугольника по четырем точкам
     * @param pointA - первая точка
     * @param pointB - вторая точка
     * @param pointC - третья точка
     * @param pointD - четвертая точка
     */
    Rectangle(const Point& pointA, const Point& pointB, const Point& pointC, const Point& pointD);

    /**
     * @brief возвращает первую вершину
     */
    Point getP1() const;

    /**
     * @brief возвращает вторую вершину
     */
    Point getP2() const;

    /**
     * @brief возвращает третью вершину
     */
    Point getP3() const;

    /**
     * @brief возвращает четвертую вершину
     */
    Point getP4() const;

    /**
     * @brief возвращает все вершины прямоугольника
     */
    std::vector<Point> getAllPoints() const;

    /**
     * @brief вычисляет ширину прямоугольника
     */
    double getWidth() const;

    /**
     * @brief вычисляет высоту прямоугольника
     */
    double getHeight() const;

    /**
     * @brief вычисляет площадь прямоугольника
     */
    double getS() const;

    /**
     * @brief вычисляет периметр прямоугольника
     */
    double getPerimeter() const;

    friend std::ostream& operator<<(std::ostream& outputStream, const Rectangle& currentRectangle);
    friend std::istream& operator>>(std::istream& inputStream, Rectangle& currentRectangle);
};
