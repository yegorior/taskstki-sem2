#pragma once

#include <cstddef>
#include <initializer_list>
#include <iostream>
#include <string>
#include "node.h"

/**
 * @brief Линейный односвязный список целых чисел.
 */
class LinkedList {
private:
    Node* first;
    std::size_t count;

    Node* getNode(std::size_t index) const;
    void copyFrom(const LinkedList& source);
    void release();

public:
    LinkedList();
    LinkedList(std::initializer_list<int> values);
    LinkedList(const LinkedList& other);
    LinkedList(LinkedList&& other) noexcept;
    ~LinkedList();

    LinkedList& operator=(const LinkedList& other);
    LinkedList& operator=(LinkedList&& other) noexcept;

    void push_back(int value);
    void push_front(int value);
    void insert(std::size_t index, int value);

    void pop_back();
    void pop_front();
    void erase(std::size_t index);
    bool remove(int value);

    int find(int value) const;
    bool contains(int value) const;
    void modify(std::size_t index, int value);

    int& operator[](std::size_t index);
    const int& operator[](std::size_t index) const;

    std::size_t getSize() const;
    bool isEmpty() const;
    void clear();

    std::string ToString() const;

    friend std::ostream& operator<<(std::ostream& out, const LinkedList& list);
    friend std::istream& operator>>(std::istream& in, LinkedList& list);
};
