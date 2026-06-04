#pragma once

#include "Point.h"

#include <iostream>
#include <string>
#include <vector>

namespace geometry {

/**
 * @brief Абстрактный базовый класс правильного многоугольника.
 */
class Polygon {
protected:
    /**
     * @brief Вершины многоугольника.
     */
    std::vector<Point> vertices;

public:
    /**
     * @brief Конструктор по умолчанию.
     */
    Polygon() = default;

    /**
     * @brief Виртуальный деструктор по умолчанию.
     */
    virtual ~Polygon() = default;

    /**
     * @brief Сериализует объект в строку.
     * @return Строковое представление многоугольника.
     */
    virtual std::string ToString() const = 0;

    /**
     * @brief Вычисляет площадь многоугольника.
     * @return Площадь многоугольника.
     */
    virtual double getArea() const = 0;

    /**
     * @brief Вычисляет периметр многоугольника.
     * @return Периметр многоугольника.
     */
    virtual double getPerimeter() const = 0;

    /**
     * @brief Вычисляет радиус описанной окружности.
     * @return Радиус описанной окружности.
     */
    virtual double getCircumradius() const = 0;

    /**
     * @brief Считывает многоугольник из потока ввода.
     * @param is Поток ввода.
     */
    virtual void read(std::istream& is) = 0;

    /**
     * @brief Оператор вывода многоугольника в поток.
     * @param os Поток вывода.
     * @param polygon Многоугольник для вывода.
     * @return Поток вывода.
     */
    friend std::ostream& operator<<(std::ostream& os, const Polygon& polygon);

    /**
     * @brief Оператор ввода многоугольника из потока.
     * @param is Поток ввода.
     * @param polygon Многоугольник для ввода.
     * @return Поток ввода.
     */
    friend std::istream& operator>>(std::istream& is, Polygon& polygon);

    /**
     * @brief Сериализует многоугольник в строку.
     * @param polygon Многоугольник для сериализации.
     * @return Строковое представление многоугольника.
     */
    static std::string ToString(const Polygon& polygon);
};

}
