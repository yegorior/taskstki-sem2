#pragma once

#include <iostream>
#include <vector>

#include "point.h"

/**
 * @brief Класс прямоугольника, заданного четырьмя вершинами.
 */
class Rectangle {
private:
    /**
     * @brief Вершины прямоугольника.
     */
    Point firstVertex, secondVertex, thirdVertex, fourthVertex;

    /**
     * @brief Проверка, образуют ли вершины прямоугольник.
     * @return true, если вершины образуют прямоугольник, иначе false.
     */
    bool isRectangle() const;

    /**
     * @brief Сортировка вершин вокруг центра прямоугольника.
     */
    void sortPoints();

public:
    /**
     * @brief Конструктор прямоугольника по умолчанию.
     */
    Rectangle();

    /**
     * @brief Конструктор, создающий прямоугольник по четырём точкам.
     * @param pointA - первая вершина прямоугольника.
     * @param pointB - вторая вершина прямоугольника.
     * @param pointC - третья вершина прямоугольника.
     * @param pointD - четвёртая вершина прямоугольника.
     */
    Rectangle(const Point& pointA, const Point& pointB, const Point& pointC, const Point& pointD);

    /**
     * @brief Получение первой вершины прямоугольника.
     * @return Первая вершина прямоугольника.
     */
    Point getP1() const;

    /**
     * @brief Получение второй вершины прямоугольника.
     * @return Вторая вершина прямоугольника.
     */
    Point getP2() const;

    /**
     * @brief Получение третьей вершины прямоугольника.
     * @return Третья вершина прямоугольника.
     */
    Point getP3() const;

    /**
     * @brief Получение четвёртой вершины прямоугольника.
     * @return Четвёртая вершина прямоугольника.
     */
    Point getP4() const;

    /**
     * @brief Получение всех вершин прямоугольника.
     * @return Вектор, содержащий четыре вершины прямоугольника.
     */
    std::vector<Point> getAllPoints() const;

    /**
     * @brief Вычисление ширины прямоугольника.
     * @return Ширина прямоугольника.
     */
    double getWidth() const;

    /**
     * @brief Вычисление высоты прямоугольника.
     * @return Высота прямоугольника.
     */
    double getHeight() const;

    /**
     * @brief Вычисление площади прямоугольника.
     * @return Площадь прямоугольника.
     */
    double getS() const;

    /**
     * @brief Вычисление периметра прямоугольника.
     * @return Периметр прямоугольника.
     */
    double getPerimeter() const;

    /**
     * @brief Оператор вывода прямоугольника в поток.
     * @param outputStream - поток вывода.
     * @param currentRectangle - прямоугольник, который нужно вывести.
     * @return Ссылка на поток вывода.
     */
    friend std::ostream& operator<<(std::ostream& outputStream, const Rectangle& currentRectangle);

    /**
     * @brief Оператор ввода прямоугольника из потока.
     * @param inputStream - поток ввода.
     * @param currentRectangle - прямоугольник, в который записываются введённые вершины.
     * @return Ссылка на поток ввода.
     */
    friend std::istream& operator>>(std::istream& inputStream, Rectangle& currentRectangle);
};
