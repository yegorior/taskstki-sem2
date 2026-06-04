#include "square.h"

#include <clocale>
#include <exception>
#include <iostream>
#include <memory>
#include <vector>

/**
 * @brief Точка входа в демонстрационную программу.
 * @return 0 в случае успешного выполнения программы.
 */
int main() {
    setlocale(LC_ALL, "Russian");

    try {
        std::cout << "=== Демонстрация работы с классами Polygon и Square ===\n\n";

        std::cout << "1. Создание квадрата через точки:\n";
        geometry::Point firstPoint(0, 0);
        geometry::Point secondPoint(0, 2);
        geometry::Point thirdPoint(2, 2);
        geometry::Point fourthPoint(2, 0);

        geometry::Square firstSquare(firstPoint, secondPoint, thirdPoint, fourthPoint);

        std::cout << "Квадрат 1: " << firstSquare << "\n";
        std::cout << "Площадь: " << firstSquare.getArea() << "\n";
        std::cout << "Периметр: " << firstSquare.getPerimeter() << "\n";
        std::cout << "Радиус описанной окружности: " << firstSquare.getCircumradius() << "\n\n";

        std::cout << "2. Создание квадрата через пары чисел:\n";
        geometry::Square secondSquare(1, 1, 1, 4, 4, 4, 4, 1);

        std::cout << "Квадрат 2: " << secondSquare << "\n";
        std::cout << "Площадь: " << secondSquare.getArea() << "\n";
        std::cout << "Периметр: " << secondSquare.getPerimeter() << "\n";
        std::cout << "Радиус описанной окружности: " << secondSquare.getCircumradius() << "\n\n";

        std::cout << "3. Коллекция объектов базового типа:\n";
        std::vector<std::unique_ptr<geometry::Polygon>> polygonList;
        polygonList.push_back(std::make_unique<geometry::Square>(firstSquare));
        polygonList.push_back(std::make_unique<geometry::Square>(secondSquare));
        polygonList.push_back(std::make_unique<geometry::Square>(5, 5, 5, 8, 8, 8, 8, 5));

        std::cout << "Итерация по коллекции:\n";

        for (std::size_t index = 0; index < polygonList.size(); ++index) {
            std::cout << "Объект " << (index + 1) << ": " << *polygonList[index] << "\n";
            std::cout << "Площадь: " << polygonList[index]->getArea() << "\n";
            std::cout << "Периметр: " << polygonList[index]->getPerimeter() << "\n";
            std::cout << "Радиус описанной окружности: " << polygonList[index]->getCircumradius() << "\n\n";
        }

        std::cout << "4. Демонстрация операторов сравнения:\n";
        geometry::Square thirdSquare(0, 0, 0, 2, 2, 2, 2, 0);
        geometry::Square fourthSquare(0, 0, 0, 2, 2, 2, 2, 0);
        geometry::Square fifthSquare(0, 0, 0, 3, 3, 3, 3, 0);

        std::cout << "thirdSquare == fourthSquare: " << (thirdSquare == fourthSquare ? "true" : "false") << "\n";
        std::cout << "thirdSquare == fifthSquare: " << (thirdSquare == fifthSquare ? "true" : "false") << "\n\n";

        std::cout << "5. Демонстрация статического метода ToString:\n";
        std::cout << geometry::Square::ToString(firstSquare) << "\n\n";

        std::cout << "6. Попытка создания некорректного квадрата:\n";

        try {
            geometry::Square incorrectSquare(0, 0, 0, 2, 2, 2, 3, 0);
        }
        catch (const std::exception& exception) {
            std::cout << "Исключение: " << exception.what() << "\n";
        }
    }
    catch (const std::exception& exception) {
        std::cerr << "Ошибка: " << exception.what() << std::endl;
        return 1;
    }

    std::cout << "\nПрограмма завершена успешно.\n";

    return 0;
}
