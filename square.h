#pragma once

#include "polygon.h"

#include <cstddef>
#include <iostream>
#include <string>

namespace geometry {

/**
 * @brief Класс квадрата.
 */
class Square : public Polygon {
private:
    /**
     * @brief Постоянное количество вершин квадрата.
     */
    static constexpr std::size_t VERTEX_COUNT = 4;

    /**
     * @brief Проверяет, образуют ли вершины корректный квадрат.
     * @return true, если вершины образуют квадрат.
     */
    bool isValidSquare() const;

    /**
     * @brief Вычисляет расстояние между двумя точками.
     * @param first Первая точка.
     * @param second Вторая точка.
     * @return Расстояние между точками.
     */
    static double getDistance(const Point& first, const Point& second);

public:
    /**
     * @brief Конструктор квадрата по четырем точкам.
     * @param first Первая вершина квадрата.
     * @param second Вторая вершина квадрата.
     * @param third Третья вершина квадрата.
     * @param fourth Четвертая вершина квадрата.
     */
    Square(const Point& first, const Point& second, const Point& third, const Point& fourth);

    /**
     * @brief Конструктор квадрата по координатам четырех вершин.
     * @param x1 Координата x первой вершины.
     * @param y1 Координата y первой вершины.
     * @param x2 Координата x второй вершины.
     * @param y2 Координата y второй вершины.
     * @param x3 Координата x третьей вершины.
     * @param y3 Координата y третьей вершины.
     * @param x4 Координата x четвертой вершины.
     * @param y4 Координата y четвертой вершины.
     */
    Square(const double x1, const double y1,
           const double x2, const double y2,
           const double x3, const double y3,
           const double x4, const double y4);

    /**
     * @brief Сериализует квадрат в строку.
     * @return Строковое представление квадрата.
     */
    std::string ToString() const override;

    /**
     * @brief Вычисляет площадь квадрата.
     * @return Площадь квадрата.
     */
    double getArea() const override;

    /**
     * @brief Вычисляет периметр квадрата.
     * @return Периметр квадрата.
     */
    double getPerimeter() const override;

    /**
     * @brief Вычисляет радиус описанной вокруг квадрата окружности.
     * @return Радиус описанной окружности.
     */
    double getCircumradius() const override;

    /**
     * @brief Считывает квадрат из потока ввода.
     * @param is Поток ввода.
     */
    void read(std::istream& is) override;

    /**
     * @brief Проверяет квадраты на равенство.
     * @param other Другой квадрат.
     * @return true, если квадраты равны.
     */
    bool operator==(const Square& other) const;

    /**
     * @brief Проверяет квадраты на неравенство.
     * @param other Другой квадрат.
     * @return true, если квадраты не равны.
     */
    bool operator!=(const Square& other) const;

    /**
     * @brief Сериализует квадрат в строку.
     * @param square Квадрат для сериализации.
     * @return Строковое представление квадрата.
     */
    static std::string ToString(const Square& square);

    /**
     * @brief Считывает квадрат из потока ввода.
     * @param is Поток ввода.
     * @return Считанный квадрат.
     */
    static Square readFromStream(std::istream& is);
};

}
