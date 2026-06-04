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
     * @brief Возвращает указатель на узел по индексу.
     * @param index Индекс искомого узла.
     * @return Указатель на узел списка.
     */
    Node* getNode(const std::size_t index) const;

    /**
     * @brief Копирует элементы из другого списка.
     * @param source Список, из которого копируются элементы.
     */
    void copyFrom(const LinkedList& source);

    /**
     * @brief Освобождает память, занятую узлами списка.
     */
    void release();

public:
    /**
     * @brief Создаёт пустой список.
     */
    LinkedList();

    /**
     * @brief Создаёт список из списка инициализации.
     * @param values Значения, которые будут добавлены в список.
     */
    LinkedList(const std::initializer_list<int> values);

    /**
     * @brief Конструктор копирования.
     * @param other Список, из которого создаётся копия.
     */
    LinkedList(const LinkedList& other);

    /**
     * @brief Конструктор перемещения.
     * @param other Список, ресурсы которого будут перемещены.
     */
    LinkedList(LinkedList&& other) noexcept;

    /**
     * @brief Деструктор списка.
     */
    ~LinkedList();

    /**
     * @brief Оператор присваивания копированием.
     * @param other Список, из которого копируются данные.
     * @return Ссылка на текущий список.
     */
    LinkedList& operator=(const LinkedList& other);

    /**
     * @brief Оператор присваивания перемещением.
     * @param other Список, ресурсы которого будут перемещены.
     * @return Ссылка на текущий список.
     */
    LinkedList& operator=(LinkedList&& other) noexcept;

    /**
     * @brief Добавляет элемент в конец списка.
     * @param value Добавляемое значение.
     */
    void push_back(const int value);

    /**
     * @brief Добавляет элемент в начало списка.
     * @param value Добавляемое значение.
     */
    void push_front(const int value);

    /**
     * @brief Вставляет элемент в заданную позицию.
     * @param index Индекс позиции вставки.
     * @param value Добавляемое значение.
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
     * @brief Удаляет элемент по индексу.
     * @param index Индекс удаляемого элемента.
     */
    void erase(const std::size_t index);

    /**
     * @brief Удаляет первый элемент с заданным значением.
     * @param value Значение удаляемого элемента.
     * @return true, если элемент был найден и удалён, иначе false.
     */
    bool remove(const int value);

    /**
     * @brief Ищет индекс первого элемента с заданным значением.
     * @param value Значение для поиска.
     * @return Индекс найденного элемента или -1, если элемент не найден.
     */
    int find(const int value) const;

    /**
     * @brief Проверяет наличие значения в списке.
     * @param value Значение для проверки.
     * @return true, если значение есть в списке, иначе false.
     */
    bool contains(const int value) const;

    /**
     * @brief Изменяет значение элемента по индексу.
     * @param index Индекс изменяемого элемента.
     * @param value Новое значение элемента.
     */
    void modify(const std::size_t index, const int value);

    /**
     * @brief Возвращает ссылку на элемент по индексу.
     * @param index Индекс элемента.
     * @return Ссылка на элемент списка.
     */
    int& operator[](const std::size_t index);

    /**
     * @brief Возвращает константную ссылку на элемент по индексу.
     * @param index Индекс элемента.
     * @return Константная ссылка на элемент списка.
     */
    const int& operator[](const std::size_t index) const;

    /**
     * @brief Возвращает количество элементов списка.
     * @return Количество элементов списка.
     */
    std::size_t getSize() const;

    /**
     * @brief Проверяет, является ли список пустым.
     * @return true, если список пустой, иначе false.
     */
    bool isEmpty() const;

    /**
     * @brief Удаляет все элементы списка.
     */
    void clear();

    /**
     * @brief Возвращает строковое представление списка.
     * @return Строка с содержимым списка.
     */
    std::string ToString() const;

    /**
     * @brief Выводит список в поток.
     * @param out Поток вывода.
     * @param list Список для вывода.
     * @return Ссылка на поток вывода.
     */
    friend std::ostream& operator<<(std::ostream& out, const LinkedList& list);

    /**
     * @brief Считывает список из потока.
     * @param in Поток ввода.
     * @param list Список для заполнения.
     * @return Ссылка на поток ввода.
     */
    friend std::istream& operator>>(std::istream& in, LinkedList& list);
};
