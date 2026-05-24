#include <cassert>
#include "LinkedList.h"

/**
 * @brief Простая функция с проверками для демонстрации тестов библиотеки.
 * Файл не содержит main(), поэтому его можно компилировать вместе с Demo.
 */
void RunLinkedListTests() {
    LinkedList list = { 1, 2, 3 };

    assert(list.getSize() == 3);
    assert(!list.isEmpty());
    assert(list[0] == 1);
    assert(list[2] == 3);

    list.push_front(0);
    list.push_back(4);
    assert(list.ToString() == "[0, 1, 2, 3, 4]");

    list.insert(2, 10);
    assert(list[2] == 10);

    list.modify(2, 20);
    assert(list[2] == 20);

    assert(list.find(20) == 2);
    assert(list.remove(20));
    assert(list.find(20) == -1);

    list.pop_front();
    list.pop_back();
    assert(list.ToString() == "[1, 2, 3]");

    LinkedList copy(list);
    copy[0] = 100;
    assert(list[0] == 1);
    assert(copy[0] == 100);

    LinkedList assigned;
    assigned = list;
    assert(assigned.ToString() == list.ToString());

    assigned.clear();
    assert(assigned.isEmpty());
}
