#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
class List {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;
        Node(const T& val) : data(val), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int size;

public:
    List() : head(nullptr), tail(nullptr), size(0) {}

    List(const List& other) : head(nullptr), tail(nullptr), size(0) {
        Node* current = other.head;
        while (current) {
            pushBack(current->data);
            current = current->next;
        }
    }

    ~List() {}

    int getSize() const { return size; }


    void clear() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = tail = nullptr;
        size = 0;
    }

    List& operator=(const List& other) {
        if (this != &other) {
            clear();
            Node* current = other.head;
            while (current) {
                pushBack(current->data);
                current = current->next;
            }
        }
        return *this;
    }

    void pushBack(const T& val) {
        Node* newNode = new Node(val);
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

    T& operator[](int index) {
        Node* curr = head;
        for (int i = 0; i < index; ++i) {
            curr = curr->next;
        }
        return curr->data;
    }

    const T& operator[](int index) const {
        Node* curr = head;
        for (int i = 0; i < index; ++i) {
            curr = curr->next;
        }
        return curr->data;
    }

    List operator+(const List& other) const {
        List result;
        int minSize = min(size, other.size);
        for (int i = 0; i < minSize; ++i) {
            result.pushBack((*this)[i] + other[i]);
        }
        return result;
    }

    List operator+(const T& constant) const {
        List result;
        Node* current = head;
        while (current) {
            result.pushBack(current->data + constant);
            current = current->next;
        }
        return result;
    }

    class Iterator {
        Node* current;
    public:
        Iterator(Node* n) : current(n) {}

        Iterator& operator--() {
            current = current->prev;
            return *this;
        }

        Iterator operator--(int) {
            Iterator tmp = *this;
            current = current->prev;
            return tmp;
        }

        T& operator*() { return current->data; }

        bool operator!=(const Iterator& other) const {
            return current != other.current;
        }
    };

    Iterator begin() { return Iterator(head); }
    Iterator end() { return Iterator(nullptr); }
    Iterator last() { return Iterator(tail); }
};

class Pair {
public:
    int first;
    double second;

    Pair(int f = 0, double s = 0.0) : first(f), second(s) {}

    Pair operator+(const Pair& other) const {
        return Pair(first + other.first, second + other.second);
    }

    Pair operator+(int val) const {
        return Pair(first + val, second);
    }
};

ostream& operator<<(ostream& os, const Pair& p) {
    os << p.first << ":" << p.second;
    return os;
}

template <typename T>
void print(List<T>& list) {
    for (int i = 0; i < list.getSize(); ++i) {
        cout << list[i] << " ";
    }
    cout << endl;
}

int main() {
    List<int> intList1;
    intList1.pushBack(1);
    intList1.pushBack(2);
    intList1.pushBack(3);
    cout << "intList1: ";
    print(intList1);

    List<int> intList2;
    intList2.pushBack(4);
    intList2.pushBack(5);
    intList2.pushBack(6);
    cout << "intList2: ";
    print(intList2);

    cout << "intList1[1] = " << intList1[1] << endl;

    List<int> intSum = intList1 + intList2;
    cout << "intList1 + intList2: ";
    print(intSum);

    List<int> intAdded = intList1 + 10;
    cout << "intList1 + 10: ";
    print(intAdded);

    List<Pair> pairList1;
    pairList1.pushBack(Pair(1, 1.1));
    pairList1.pushBack(Pair(2, 2.2));
    cout << "pairList1: ";
    print(pairList1);

    List<Pair> pairList2;
    pairList2.pushBack(Pair(3, 3.3));
    pairList2.pushBack(Pair(4, 4.4));
    cout << "pairList2: ";
    print(pairList2);

    List<Pair> pairSum = pairList1 + pairList2;
    cout << "pairList1 + pairList2: ";
    print(pairSum);

    List<Pair> pairAdded = pairList1 + 5;
    cout << "pairList1 + 5: ";
    print(pairAdded);

    return 0;
}