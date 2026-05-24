#pragma once

/**
 * @brief Узел линейного односвязного списка целых чисел.
 */
class Node {
public:
    int value;
    Node* next;

    explicit Node(int newValue);
};
