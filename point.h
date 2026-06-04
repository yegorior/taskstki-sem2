#pragma once

#include <iostream>

/**
 * @brief Класс точки на плоскости.
 */
class Point {
private:
    /**
     * @brief coordinateX - координата точки по оси OX.
     */
    double coordinateX;

    /**
     * @brief coordinateY - координата точки по оси OY.
     */
    double coordinateY;

public:
    /**
     * @brief Конструктор, создающий точку с заданными координатами.
     * @param xValue - значение координаты точки по оси OX.
     * @param yValue - значение координаты точки по оси OY.
     */
    Point(const double xValue = 0, const double yValue = 0);

    /**
     * @brief Получение координаты точки по оси OX.
     * @return Значение координаты coordinateX.
     */
    double getX() const;

    /**
     * @brief Получение координаты точки по оси OY.
     * @return Значение координаты coordinateY.
     */
    double getY() const;

    /**
     * @brief Вычисление расстояния до другой точки.
     * @param anotherPoint - точка, до которой вычисляется расстояние.
     * @return Расстояние между текущей точкой и другой точкой.
     */
    double distanceTo(const Point& anotherPoint) const;

    /**
     * @brief Оператор вывода точки в поток.
     * @param outputStream - поток вывода.
     * @param currentPoint - точка, которую нужно вывести.
     * @return Ссылка на поток вывода.
     */
    friend std::ostream& operator<<(std::ostream& outputStream, const Point& currentPoint);

    /**
     * @brief Оператор ввода точки из потока.
     * @param inputStream - поток ввода.
     * @param currentPoint - точка, в которую записываются введённые координаты.
     * @return Ссылка на поток ввода.
     */
    friend std::istream& operator>>(std::istream& inputStream, Point& currentPoint);
};
