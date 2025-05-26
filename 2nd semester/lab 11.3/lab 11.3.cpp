#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node* next;
};

struct Stack {
    Node* top = nullptr;

    void push(const string& str) {
        Node* newNode = new Node;
        newNode->data = str;
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if(top == nullptr) return;
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    void print() {
        Node* current = top;
        while(current != nullptr) {
            cout << current->data << endl;
            current = current->next;
        }
    }

    void del(int pos) {
        if(pos == 1) {
            pop();
            return;
        }
        Node* prev = nullptr;
        Node* current = top;
        for(int i = 1; current != nullptr && i < pos; i++) {
            prev = current;
            current = current->next;
        }
        if(current == nullptr) return;
        prev->next = current->next;
        delete current;
    }
};

int main() {
    Stack s;
    s.push("а");
    s.push("бб");
    s.push("ввв");
    s.del(2);
    s.push("г");
    s.push("д");
    s.print();
    return 0;
}
