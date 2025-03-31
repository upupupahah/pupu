/*
Двусвязный список

Записи в линейном списке содержат ключевое поле типа *char(строка символов). 
Сформировать структуру.
Удалить элемент с заданным номером.
Добавить К элементов в начало списка.
*/


#include <iostream>

//структура узла
struct Node {
	char data;
	Node* prev = nullptr;
	Node* next = nullptr;

	void add(char Data) {
		data = Data;
	}
};

//структура списка
struct doubleList {
	Node* head = nullptr;
	Node* tail = nullptr;

	void pushFront(char data) {
		Node* node = new Node;
		node->add(data);
		if (head == nullptr) {
			head = node;
			tail = node;
		}
		else {
			node->next = head;
			head->prev = node;
			head = node;
		}
	}

	void pushBack(char data) {
		Node* node = new Node;
		node->add(data);
		node->prev = tail;
		if (tail != nullptr) {
			tail->next = node;
		}
		if (head == nullptr) {
			head = node;
		}
		tail = node;
	}

	void Delete(int k) {
		Node* current = head;
		int count = 0;
		
		while (current != nullptr && count < k) {
			current = current->next;
			count++;
		}

		if (current->prev != nullptr) {
			current->prev->next = current->next;
		}
		else {
			head = current->next;
		}
		if (current->next != nullptr) {
			current->next->prev = current->prev;
		}
		else {
			tail = current->prev;
		}

		delete current;
	}
};

int main() {
	doubleList list;

	int l;
	std::cout << "enter length of list: ";
	std::cin >> l;

	for (int i = 0; i < l; i++) {
		char tmp;
		std::cout << "enter " << i + 1 << " element of list: ";
		std::cin >> tmp;
		list.pushBack(tmp);
	}
	std::cout << std::endl;

	std::cout << "your list is: ";
	Node* node = list.head;
	while (node != nullptr) {
		std::cout << node->data << ' ';
		node = node->next;
	}
	std::cout << std::endl << std::endl;

	int k;
	std::cout << "enter index of element to delete: ";
	std::cin >> k;
	list.Delete(k);
	std::cout << std::endl;

	node = list.head;
	std::cout << "new list: ";
	while (node != nullptr) {
		std::cout << node->data << ' ';
		node = node->next;
	}
	std::cout << std::endl;

	std::cout << std::endl << "now add some elements to front. enter count of elements: ";
	std::cin >> k;
	for (int i = 0; i < k; i++) {
		char tmp;
		std::cout << "enter " << i + 1 << " new element: ";
		std::cin >> tmp;
		list.pushFront(tmp);
	}
	std::cout << std::endl;

	std::cout << "new list with your added elements: ";
	node = list.head;
	while (node != nullptr) {
		std::cout << node->data << ' ';
		node = node->next;
	}
	std::cout << std::endl;

	return 0;
}
