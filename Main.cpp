#include <iostream>
#include <stdexcept>

#include "LinkedList.h"

int main() {
    setlocale(LC_ALL, "Russian");

    std::cout << "=== Демонстрация работы линейного односвязного списка ===\n\n";

    std::cout << "1. Создание списка через initializer_list:\n";
    LinkedList numbers = { 12, 24, 36, 48 };
    std::cout << "numbers = " << numbers << '\n';
    std::cout << "Размер: " << numbers.getSize() << '\n';
    std::cout << "Пустой список? " << (numbers.isEmpty() ? "да" : "нет") << "\n\n";

    std::cout << "2. Конструктор копирования:\n";
    LinkedList copiedNumbers(numbers);
    std::cout << "copiedNumbers = " << copiedNumbers << "\n\n";

    std::cout << "3. Оператор присваивания:\n";
    LinkedList assignedNumbers;
    assignedNumbers = numbers;
    std::cout << "assignedNumbers = " << assignedNumbers << "\n\n";

    std::cout << "4. Вставка элементов:\n";
    numbers.push_front(6);
    numbers.push_back(60);
    numbers.insert(3, 30);
    std::cout << "После вставок: " << numbers << "\n\n";

    std::cout << "5. Удаление элементов:\n";
    numbers.pop_front();
    numbers.pop_back();
    numbers.erase(2);
    numbers.remove(36);
    std::cout << "После удалений: " << numbers << "\n\n";

    std::cout << "6. Поиск и изменение значения:\n";
    const int searchedValue = 24;
    const int foundIndex = numbers.find(searchedValue);

    if (foundIndex != -1) {
        std::cout << "Значение " << searchedValue << " найдено на позиции " << foundIndex << '\n';
    } else {
        std::cout << "Значение " << searchedValue << " не найдено\n";
    }

    numbers.modify(1, 99);
    std::cout << "После modify(1, 99): " << numbers << "\n\n";

    std::cout << "7. Доступ по индексу:\n";
    std::cout << "numbers[0] = " << numbers[0] << '\n';
    numbers[0] = 111;
    std::cout << "После numbers[0] = 111: " << numbers << "\n\n";

    std::cout << "8. Сериализация через ToString():\n";
    std::cout << numbers.ToString() << "\n\n";

    std::cout << "9. Проверка исключения:\n";
    try {
        std::cout << numbers[100] << '\n';
    } catch (const std::out_of_range& error) {
        std::cout << "Поймано исключение: " << error.what() << '\n';
    }

    std::cout << "\nПрограмма завершена успешно.\n";
    return 0;
}
