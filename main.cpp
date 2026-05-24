#include <clocale>
#include <iostream>
#include "point.h"
#include "rectangle.h"

using namespace std;

/**
 * @brief точка входа в программу
 * @return 0 при корректном завершении программы
 */
int main()
{
    setlocale(LC_ALL, "Russian");

    Point leftBottomPoint(0, 0);
    Point rightBottomPoint(3, 0);
    Point rightTopPoint(3, 4);
    Point leftTopPoint(0, 4);

    Rectangle firstRectangle(leftBottomPoint, rightBottomPoint, rightTopPoint, leftTopPoint);

    cout << "Прямоугольник 1: " << firstRectangle << endl;
    cout << "Площадь: " << firstRectangle.getS() << endl;
    cout << "Периметр: " << firstRectangle.getPerimeter() << endl;
    cout << "Ширина: " << firstRectangle.getWidth() << ", Высота: " << firstRectangle.getHeight() << endl;

    cout << endl;

    Rectangle secondRectangle;

    cout << "Введите 4 точки прямоугольника (x y для каждой точки):" << endl;
    cin >> secondRectangle;

    cout << "Вы ввели: " << secondRectangle << endl;
    cout << "Площадь: " << secondRectangle.getS() << endl;
    cout << "Периметр: " << secondRectangle.getPerimeter() << endl;

    return 0;
}
