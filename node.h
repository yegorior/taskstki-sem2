#pragma once

/**
 * @brief Узел линейного односвязного списка целых чисел.
 */
class Node {
public:
    /**
     * @brief Значение, хранящееся в узле.
     */
    int value;

    /**
     * @brief Указатель на следующий узел списка.
     */
    Node* next;

    /**
     * @brief Создаёт узел списка с заданным значением.
     * @param newValue Значение, которое будет сохранено в узле.
     */
    explicit Node(const int newValue);
};
