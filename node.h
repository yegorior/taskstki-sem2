#pragma once

/**
 * @brief Узел линейного односвязного списка целых чисел.
 */
class Node {
public:
    /**
     * @brief Значение, которое хранится в узле списка.
     */
    int value;

    /**
     * @brief Указатель на следующий узел списка.
     */
    Node* next;

    /**
     * @brief Конструктор узла списка.
     * @param newValue - значение, которое будет записано в узел.
     */
    explicit Node(const int newValue);
};
