/*
Класс контейнер СПИСОК с ключевыми значениями типа int
реализовать операции:
[] - доступ по индексу
+ вектор - сложение элементов списков a[i] + b[i]
+ число - добавляет константу ко всем элементам списка
-- - переход к предыдущему элементу (с помощью класса-итератора)
*/

#include <iostream>

class LIST {
    struct node {
        int data;
        node* prev;
        node* next;
        node(int val) : data(val), prev(nullptr), next(nullptr) {}
    };

    node* head;
    node* tail;
    int size;

public:
    LIST() : head(nullptr), tail(nullptr), size(0) {}

    int getSize() { return size; }

    LIST(const LIST& other) : head(nullptr), tail(nullptr), size(0) {
        node* current = other.head;
        while (current) {
            pushBack(current->data);
            current = current->next;
        }
    }

    ~LIST() {
        node* current = head;
        while (current) {
            node* next = current->next;
            delete current;
            current = next;
        }
    }

    LIST& operator=(const LIST& other) {
        if (this != &other) {
            while (head) {
                node* temp = head;
                head = head->next;
                delete temp;
            }
            tail = nullptr;
            size = 0;

            node* current = other.head;
            while (current) {
                pushBack(current->data);
                current = current->next;
            }
        }
        return *this;
    }

    void pushBack(int val) {
        node* newNode = new node(val);
        if (!tail) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    int& operator[](int index) {
        node* curr = head;
        for (int i = 0; i < index; ++i)
            curr = curr->next;
        return curr->data;
    }

    const int& operator[](int index) const {
        node* curr = head;
        for (int i = 0; i < index; ++i)
            curr = curr->next;
        return curr->data;
    }

    LIST operator+(const LIST& other) const {
        LIST result;
        int minSize = std::min(size, other.size);
        for (int i = 0; i < minSize; ++i)
            result.pushBack((*this)[i] + other[i]);
        return result;
    }

    LIST operator+(int constant) const {
        LIST result;
        node* current = head;
        while (current) {
            result.pushBack(current->data + constant);
            current = current->next;
        }
        return result;
    }

    class iterator {
        node* current;
    public:
        iterator(node* n) : current(n) {}

        iterator& operator--() {
            current = current->prev;
            return *this;
        }

        iterator operator--(int) {
            iterator tmp = *this;
            --(*this);
            return tmp;
        }

        int& operator*() {
            return current->data;
        }

        bool operator!=(const iterator& other) const {
            return current != other.current;
        }
    };

    iterator begin() { return iterator(head); }
    iterator end() { return iterator(nullptr); }
    iterator last() { return iterator(tail); }
};


void print(LIST& a) {
    for (int i = 0; i < a.getSize(); i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}



int main() {
    LIST list1;
    list1.pushBack(1);
    list1.pushBack(2);
    list1.pushBack(3);

    std::cout << "list1: ";
    print(list1);

    LIST list2;
    list2.pushBack(4);
    list2.pushBack(5);
    list2.pushBack(6);

    std::cout << "list2: ";
    print(list2);

    // [i]
    std::cout << "list1[1] = " << list1[1] << std::endl;

    // list + list
    LIST sumList = list1 + list2;
    std::cout << "sum list (reverse): ";
    if (sumList.begin() != sumList.end()) {
        auto i = sumList.last();
        while (i != sumList.begin()) {
            std::cout << *i << " ";
            --i;
        }
        std::cout << *i << std::endl;
    }

    // + int
    LIST addedList = list1 + 10;
    std::cout << "sist1 + 10 (reverse): ";
    if (addedList.begin() != addedList.end()) {
        auto it = addedList.last();
        while (it != addedList.begin()) {
            std::cout << *it << " ";
            --it;
        }
        std::cout << *it << std::endl;
    }

    return 0;
}