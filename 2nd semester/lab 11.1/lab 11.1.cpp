/*
Односвязный список

Записи в линейном списке содержат ключевое поле типа *char(строка символов).
Сформировать структуру.
Удалить элемент с заданным номером.
Добавить К элементов в начало списка.
*/

#include <iostream>

//структура узла
struct Node {
	char data;
	Node* next;

	void add(char Data) {
		data = Data;
		next = nullptr;
	}
};

//структура списка
struct singleList {
	Node* head = nullptr;
	Node* tail = nullptr;

	void pushFront(char data) {
		Node* node = new Node; //создание нового узла для элемента
		node->add(data);
		node->next = head;
		head = node;
		if (tail == nullptr) {
			tail = node;
		}
	}

	void pushBack(char data) {
		Node* node = new Node;
		node->add(data);
		if (head == nullptr) {
			head = node;
		}
		else {
			tail->next = node;
		}
		tail = node;
	}

	void Delete(int k) {
		if (k == 0) {
			Node* temp = head;
			head = head->next;
			delete temp;
			return;
		}

		Node* current = head;
		for (int i = 0; current != nullptr && i < k - 1; i++) {
			current = current->next;
		}
		Node* tmp = current->next;
		current->next = tmp->next;

		if (tmp == tail) {
			tail = current;
		}

		delete tmp;
	}
};

int main() {
	singleList list;
	int l;
	std::cout << "enter length of list: ";
	std::cin >> l;
	for (int i = 0; i < l; i++) {
		char tmp;
		std::cout << "enter " << i + 1 << " element of list: ";
		std::cin >> tmp;
		list.pushBack(tmp);
	}

	std::cout << "\nyour list is: ";
	Node* node = list.head;
	while (node != nullptr) {
		std::cout << node->data << ' ';
		node = node->next;
	}
	std::cout << std::endl;

	int k;
	std::cout << "\nenter index of element to delete: ";
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

	node = list.head;
	for (int i = 0; i < k; i++) {
		char tmp;
		std::cout << "enter " << i + 1 << " new element: ";
		std::cin >> tmp;
		list.pushFront(tmp);
	}
	std::cout << std::endl;

	node = list.head;
	std::cout << "new list with your added elements: ";
	while (node != nullptr) {
		std::cout << node->data << ' ';
		node = node->next;
	}
	std::cout << std::endl;

	return 0;
}