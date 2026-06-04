#pragma once

#include <iostream>

namespace geometry {

/**
 * @brief Класс точки на плоскости.
 */
class Point {
private:
    /**
     * @brief Координата точки по оси OX.
     */
    double x;

    /**
     * @brief Координата точки по оси OY.
     */
    double y;

public:
    /**
     * @brief Конструктор точки.
     * @param x Координата точки по оси OX.
     * @param y Координата точки по оси OY.
     */
    Point(const double x = 0.0, const double y = 0.0);

    /**
     * @brief Возвращает координату точки по оси OX.
     * @return Координата x.
     */
    double getX() const;

    /**
     * @brief Возвращает координату точки по оси OY.
     * @return Координата y.
     */
    double getY() const;

    /**
     * @brief Проверяет точки на равенство.
     * @param other Другая точка.
     * @return true, если точки равны.
     */
    bool operator==(const Point& other) const;

    /**
     * @brief Проверяет точки на неравенство.
     * @param other Другая точка.
     * @return true, если точки не равны.
     */
    bool operator!=(const Point& other) const;

    /**
     * @brief Оператор вывода точки в поток.
     * @param os Поток вывода.
     * @param point Точка для вывода.
     * @return Поток вывода.
     */
    friend std::ostream& operator<<(std::ostream& os, const Point& point);

    /**
     * @brief Оператор ввода точки из потока.
     * @param is Поток ввода.
     * @param point Точка для ввода.
     * @return Поток ввода.
     */
    friend std::istream& operator>>(std::istream& is, Point& point);
};

}
