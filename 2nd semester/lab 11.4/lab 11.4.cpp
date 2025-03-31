/*
Очередь

Записи в очереди содержат ключевое поле типа *char(строка символов).
Сформировать структуру.
Удалить элемент с заданным номером.
Добавить К элементов в начало очереди.
*/

#include <iostream>

struct Node {
	char data;
	Node* next;
};

struct Queue {
	int size = 0; // пустая очередь
	Node* head = nullptr;
	Node* tail = nullptr;

	void add(char data) {
		Node* node = new Node;
		node->data = data;
		node->next = nullptr;
		if (tail == nullptr) {
			head = tail = node;
		}
		else {
			tail->next = node;
			tail = node;
		}
		size++;
	}

	void pushFront(char data) {
		// связь со старой головой
		Node* node = new Node;
		node->data = data;
		node->next = head;

		head = node; // указание на новый узел
		if (tail == nullptr) {
			tail = node;
		}
		size++;
	}

	void remove(int pos) {
		if (pos == 1) {
			Node* tmp = head;
			head = head->next;
			if (head == nullptr) {
				tail = nullptr;
			}
			delete tmp;
			size--;
			return;
		}
		Node* curr = head;
		for (int i = 1; i < pos - 1; i++) {
			curr = curr->next;
		}
		Node* tmp = curr->next;
		curr->next = tmp->next;
		if (tmp == tail) {
			tail = curr;
		}
		delete tmp;
		size--;
	}

	void print() {
		Node* tmp = head;
		while (tmp != nullptr) {
			std::cout << tmp->data << ' ';
			tmp = tmp->next;
		}
		std::cout << std::endl;
	}
};


int main() {
	Queue queue;
	int l, pos, k;
	char tmp;

	std::cout << "enter length of queue: ";
	std::cin >> l;
	for (int i = 1; i <= l; i++) {
		std::cout << "enter " << i << " element of list: ";
		std::cin >> tmp;
		queue.add(tmp);
	}
	std::cout << std::endl;
	std::cout << "your queue is: ";
	queue.print();

	std::cout << "enter position of element to delete: ";
	std::cin >> pos;
	queue.remove(pos);
	std::cout << "new queue: ";
	queue.print();

	std::cout << std::endl << "now add some elements to front. enter count of elements: ";
	std::cin >> k;
	for (int i = 0; i < k; i++) {
		std::cout << "enter " << i + 1 << " new element: ";
		std::cin >> tmp;
		queue.pushFront(tmp);
	}
	std::cout << std::endl;
	std::cout << "new list with your added elements: ";
	queue.print();

	return 0;
}