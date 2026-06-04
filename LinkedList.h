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
    /**
     * @brief Указатель на первый узел списка.
     */
    Node* first;

    /**
     * @brief Количество элементов в списке.
     */
    std::size_t count;

    /**
     * @brief Возвращает узел списка по индексу.
     * @param index - индекс узла.
     * @return Указатель на найденный узел.
     */
    Node* getNode(const std::size_t index) const;

    /**
     * @brief Копирует содержимое другого списка в текущий список.
     * @param source - список, из которого копируются элементы.
     */
    void copyFrom(const LinkedList& source);

    /**
     * @brief Освобождает память, занятую узлами списка.
     */
    void release();

public:
    /**
     * @brief Конструктор пустого списка.
     */
    LinkedList();

    /**
     * @brief Конструктор списка на основе списка инициализации.
     * @param values - значения, которые нужно добавить в список.
     */
    LinkedList(const std::initializer_list<int> values);

    /**
     * @brief Конструктор копирования.
     * @param other - список, который нужно скопировать.
     */
    LinkedList(const LinkedList& other);

    /**
     * @brief Конструктор перемещения.
     * @param other - список, ресурсы которого нужно переместить.
     */
    LinkedList(LinkedList&& other) noexcept;

    /**
     * @brief Деструктор списка.
     */
    ~LinkedList();

    /**
     * @brief Оператор копирующего присваивания.
     * @param other - список, который нужно скопировать.
     * @return Ссылка на текущий список.
     */
    LinkedList& operator=(const LinkedList& other);

    /**
     * @brief Оператор перемещающего присваивания.
     * @param other - список, ресурсы которого нужно переместить.
     * @return Ссылка на текущий список.
     */
    LinkedList& operator=(LinkedList&& other) noexcept;

    /**
     * @brief Добавляет элемент в конец списка.
     * @param value - значение добавляемого элемента.
     */
    void push_back(const int value);

    /**
     * @brief Добавляет элемент в начало списка.
     * @param value - значение добавляемого элемента.
     */
    void push_front(const int value);

    /**
     * @brief Вставляет элемент в список по индексу.
     * @param index - позиция вставки.
     * @param value - значение добавляемого элемента.
     */
    void insert(const std::size_t index, const int value);

    /**
     * @brief Удаляет последний элемент списка.
     */
    void pop_back();

    /**
     * @brief Удаляет первый элемент списка.
     */
    void pop_front();

    /**
     * @brief Удаляет элемент списка по индексу.
     * @param index - индекс удаляемого элемента.
     */
    void erase(const std::size_t index);

    /**
     * @brief Удаляет первое найденное значение из списка.
     * @param value - значение, которое нужно удалить.
     * @return true, если элемент был найден и удалён, иначе false.
     */
    bool remove(const int value);

    /**
     * @brief Ищет элемент в списке по значению.
     * @param value - искомое значение.
     * @return Индекс найденного элемента или -1, если элемент не найден.
     */
    int find(const int value) const;

    /**
     * @brief Проверяет наличие элемента в списке.
     * @param value - искомое значение.
     * @return true, если элемент есть в списке, иначе false.
     */
    bool contains(const int value) const;

    /**
     * @brief Изменяет значение элемента по индексу.
     * @param index - индекс изменяемого элемента.
     * @param value - новое значение элемента.
     */
    void modify(const std::size_t index, const int value);

    /**
     * @brief Возвращает изменяемую ссылку на элемент по индексу.
     * @param index - индекс элемента.
     * @return Изменяемая ссылка на элемент списка.
     */
    int& operator[](const std::size_t index);

    /**
     * @brief Возвращает неизменяемую ссылку на элемент по индексу.
     * @param index - индекс элемента.
     * @return Неизменяемая ссылка на элемент списка.
     */
    const int& operator[](const std::size_t index) const;

    /**
     * @brief Возвращает количество элементов списка.
     * @return Количество элементов списка.
     */
    std::size_t getSize() const;

    /**
     * @brief Проверяет, пуст ли список.
     * @return true, если список пустой, иначе false.
     */
    bool isEmpty() const;

    /**
     * @brief Удаляет все элементы списка.
     */
    void clear();

    /**
     * @brief Возвращает строковое представление списка.
     * @return Строка с элементами списка.
     */
    std::string ToString() const;

    /**
     * @brief Оператор вывода списка в поток.
     * @param out - поток вывода.
     * @param list - список, который нужно вывести.
     * @return Ссылка на поток вывода.
     */
    friend std::ostream& operator<<(std::ostream& out, const LinkedList& list);

    /**
     * @brief Оператор чтения списка из потока.
     * @param in - поток ввода.
     * @param list - список, в который нужно записать данные.
     * @return Ссылка на поток ввода.
     */
    friend std::istream& operator>>(std::istream& in, LinkedList& list);
};
