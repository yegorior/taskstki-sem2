#pragma once

#include <iostream>

class Point
{
private:
    /**
     * @brief coordinateX - координата точки по оси OX
     */
    double coordinateX;

    /**
     * @brief coordinateY - координата точки по оси OY
     */
    double coordinateY;

public:
    /**
     * @brief конструктор точки
     * @param xValue - значение координаты по оси OX
     * @param yValue - значение координаты по оси OY
     */
    Point(const double xValue = 0, const double yValue = 0);

    /**
     * @brief возвращает координату x
     * @return coordinateX
     */
    double getX() const;

    /**
     * @brief возвращает координату y
     * @return coordinateY
     */
    double getY() const;

    /**
     * @brief вычисляет расстояние до другой точки
     * @param anotherPoint - вторая точка
     * @return расстояние между двумя точками
     */
    double distanceTo(const Point& anotherPoint) const;

    /**
     * @brief оператор вывода точки
     */
    friend std::ostream& operator<<(std::ostream& outputStream, const Point& currentPoint);

    /**
     * @brief оператор ввода точки
     */
    friend std::istream& operator>>(std::istream& inputStream, Point& currentPoint);
};
