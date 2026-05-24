#include "LinkedList.h"

#include <sstream>
#include <stdexcept>

Node* LinkedList::getNode(std::size_t index) const {
    if (index >= count) {
        throw std::out_of_range("Индекс выходит за границы списка");
    }

    Node* current = first;
    for (std::size_t i = 0; i < index; ++i) {
        current = current->next;
    }

    return current;
}

void LinkedList::copyFrom(const LinkedList& source) {
    Node* current = source.first;
    while (current != nullptr) {
        push_back(current->value);
        current = current->next;
    }
}

void LinkedList::release() {
    while (first != nullptr) {
        Node* nextNode = first->next;
        delete first;
        first = nextNode;
    }
    count = 0;
}

LinkedList::LinkedList() : first(nullptr), count(0) {}

LinkedList::LinkedList(std::initializer_list<int> values) : first(nullptr), count(0) {
    for (int value : values) {
        push_back(value);
    }
}

LinkedList::LinkedList(const LinkedList& other) : first(nullptr), count(0) {
    copyFrom(other);
}

LinkedList::LinkedList(LinkedList&& other) noexcept : first(other.first), count(other.count) {
    other.first = nullptr;
    other.count = 0;
}

LinkedList::~LinkedList() {
    release();
}

LinkedList& LinkedList::operator=(const LinkedList& other) {
    if (this != &other) {
        release();
        copyFrom(other);
    }
    return *this;
}

LinkedList& LinkedList::operator=(LinkedList&& other) noexcept {
    if (this != &other) {
        release();
        first = other.first;
        count = other.count;
        other.first = nullptr;
        other.count = 0;
    }
    return *this;
}

void LinkedList::push_back(int value) {
    Node* createdNode = new Node(value);

    if (first == nullptr) {
        first = createdNode;
    } else {
        Node* current = first;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = createdNode;
    }

    ++count;
}

void LinkedList::push_front(int value) {
    Node* createdNode = new Node(value);
    createdNode->next = first;
    first = createdNode;
    ++count;
}

void LinkedList::insert(std::size_t index, int value) {
    if (index > count) {
        throw std::out_of_range("Позиция вставки выходит за границы списка");
    }

    if (index == 0) {
        push_front(value);
        return;
    }

    if (index == count) {
        push_back(value);
        return;
    }

    Node* previous = getNode(index - 1);
    Node* createdNode = new Node(value);
    createdNode->next = previous->next;
    previous->next = createdNode;
    ++count;
}

void LinkedList::pop_back() {
    if (isEmpty()) {
        throw std::out_of_range("Нельзя удалить элемент из пустого списка");
    }

    if (count == 1) {
        delete first;
        first = nullptr;
    } else {
        Node* previous = getNode(count - 2);
        delete previous->next;
        previous->next = nullptr;
    }

    --count;
}

void LinkedList::pop_front() {
    if (isEmpty()) {
        throw std::out_of_range("Нельзя удалить элемент из пустого списка");
    }

    Node* oldFirst = first;
    first = first->next;
    delete oldFirst;
    --count;
}

void LinkedList::erase(std::size_t index) {
    if (index >= count) {
        throw std::out_of_range("Индекс удаления выходит за границы списка");
    }

    if (index == 0) {
        pop_front();
        return;
    }

    Node* previous = getNode(index - 1);
    Node* removedNode = previous->next;
    previous->next = removedNode->next;
    delete removedNode;
    --count;
}

bool LinkedList::remove(int value) {
    int position = find(value);
    if (position == -1) {
        return false;
    }

    erase(static_cast<std::size_t>(position));
    return true;
}

int LinkedList::find(int value) const {
    Node* current = first;
    std::size_t index = 0;

    while (current != nullptr) {
        if (current->value == value) {
            return static_cast<int>(index);
        }
        current = current->next;
        ++index;
    }

    return -1;
}

bool LinkedList::contains(int value) const {
    return find(value) != -1;
}

void LinkedList::modify(std::size_t index, int value) {
    getNode(index)->value = value;
}

int& LinkedList::operator[](std::size_t index) {
    return getNode(index)->value;
}

const int& LinkedList::operator[](std::size_t index) const {
    return getNode(index)->value;
}

std::size_t LinkedList::getSize() const {
    return count;
}

bool LinkedList::isEmpty() const {
    return count == 0;
}

void LinkedList::clear() {
    release();
}

std::string LinkedList::ToString() const {
    std::ostringstream result;
    result << "[";

    Node* current = first;
    while (current != nullptr) {
        result << current->value;
        if (current->next != nullptr) {
            result << ", ";
        }
        current = current->next;
    }

    result << "]";
    return result.str();
}

std::ostream& operator<<(std::ostream& out, const LinkedList& list) {
    out << list.ToString();
    return out;
}

std::istream& operator>>(std::istream& in, LinkedList& list) {
    std::size_t amount;
    in >> amount;

    list.clear();

    for (std::size_t i = 0; i < amount; ++i) {
        int value;
        in >> value;
        list.push_back(value);
    }

    return in;
}
