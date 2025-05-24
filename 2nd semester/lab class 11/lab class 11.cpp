/*
В.13
	Задача 1
		1. Контейнер: двунаправленная очередь.
		2. Тип элементов: double.
	--------------------------------------------------
	Создать, заполнить, добавить, удалить

	Задача 2
		Тип элементов Pair
	--------------------------------------------------
	Создать, заполнить, добавить, удалить

	Задача 3
		Параметризированный класс - Список
	--------------------------------------------------
	Создать, заполнить, удалить
	Найти максимальный элемент и добавить в конец контейнера

	Задача 4
		Адаптер контейнера - стек
	--------------------------------------------------
	Создать, заполнить
	Найти элементы ключами из заданного диапазона и удалить из контейнера

	Задача 5
		Параметризированный класс - Список
		Адаптер контейнера - стек
	--------------------------------------------------
	Создать, заполнить, удалить
	К каждому элементу добавить среднее арифметическое контейнера
	*/


#include <iostream>
#include <deque>
#include <list>
#include <algorithm>
#include <numeric>
#include <stack>
#include <vector>
// 2
class Pair {
	int first;
	int second;
public:
	Pair(int f, int s) : first(f), second(s) {}
	~Pair() {}

	Pair& operator=(const Pair& a) {
		if (this != &a) {
			first = a.first;
			second = a.second;
		}
		return *this;
	}

	bool operator>(const Pair& a) const { return (first + second) > (a.first + a.second); }
	bool operator<(const Pair& a) const { return (first + second) < (a.first + a.second); }
	bool operator==(const Pair& a) const { return first == a.first && second == a.second; }
	
	Pair& operator--() {
		--first;
		return *this;
	}

	Pair operator--(int) {
		Pair tmp(*this);
		--second;
		return tmp;
	}

	friend std::ostream& operator<<(std::ostream& os, const Pair& a) {
		os << a.first << ':' << a.second;
		return os;
	}
	friend std::istream& operator>>(std::istream& is, Pair& a) {
		char tmp;
		is >> a.first >> tmp >> a.second;
		if (tmp != ':') {
			is.setstate(std::ios::failbit);
		}
		return is;
	}

	int getFirst() const { return first; }
	double getSecond() const { return second; }
};

// 3
template<typename T>
class List {
protected:
	std::list<T> data;
public:
	void add(const T& value) { data.push_back(value); }
	void remove(const T& value) { data.remove(value); }

	void filling_example() {
		for (int i = 1; i <= 5; ++i) {
			add(T(i));
		}
	}

	T findMax() const {
		return *std::max_element(data.begin(), data.end());
	}

	void appendMax() { add(findMax()); }

	void print() const {
		for (const auto& x : data) std::cout << x << ' ';
		std::cout << std::endl;
	}
};

// 5
template<typename T>
class AdvancedList : public List<T> {
public:
	void addAverage() {
		if (this->data.empty()) return;

		T sum = std::accumulate(this->data.begin(), this->data.end(), T());
		T avg = sum / this->data.size();

		for (auto& x : this->data) x += avg;
	}
};

void task1() {
	int k, counter = 0;
	std::deque<double> dq;
	std::cout << "enter len of deque: ";
	std::cin >> k;
	while (counter != k) {
		double tmp;
		std::cout << "enter new el of deque: ";
		std::cin >> tmp;
		dq.push_back(tmp);
		counter++;
	}
	std::cout << "your deque: ";
	for (double i : dq) std::cout << i << ' ';
	std::cout << "\n\n";

	dq.pop_front();
	dq.pop_back();
	std::cout << "after deleting first and last el: ";
	for (double i : dq) std::cout << i << ' ';
	std::cout << "\n\n";

}

void task2() {
	int x, y;
	std::cout << "enter first pair:\n";
	std::cin >> x;
	std::cin >> y;

	Pair a(x, y);

	std::cout << "enter second pair:\n";
	std::cin >> x;
	std::cin >> y;

	Pair b(x, y);
	--b;
	a = b;

	std::cout << "new pairs: " << a << ' ' << b << '\n';
}

void task3() {
	List<int> list;
	list.filling_example();
	std::cout << "list: ";
	list.print();
	list.appendMax();
	std::cout << "after finding max: ";
	list.print();
}

void task4() {
	std::stack<int> s;
	for (int i = 1; i <= 10; ++i) s.push(i);
	std::cout << "your stack: ";
	std::stack<int> temp_print = s;
	while (!temp_print.empty()) {
		std::cout << temp_print.top() << " ";
		temp_print.pop();
	}
	std::cout << "\n";
	std::stack<int> temp;
	while (!s.empty()) {
		int val = s.top();
		s.pop();
		if (val < 4 || val > 7) temp.push(val);
	}

	while (!temp.empty()) {
		s.push(temp.top());
		temp.pop();
	}

	std::cout << "after deleting [4-7]: ";
	while (!s.empty()) {
		std::cout << s.top() << " ";
		s.pop();
	}
	std::cout << "\n\n";
}

void task5() {
	AdvancedList<double> list;
	list.filling_example();

	std::cout << "your list: ";
	list.print();

	list.addAverage();
	std::cout << "after adding avg: ";
	list.print();
	std::cout << "\n";
}

void segment(std::string text) {
	for (int i = 0; i < 50; i++) std::cout << '#';
	std::cout << "\n" << text << '\n';
	for (int i = 0; i < 50; i++) std::cout << '#';
	std::cout << '\n';
}


int main() {
	segment("task 1");
	task1();
	
	segment("task 2");
	task2();

	segment("task 3");
	task3();

	segment("task 4");
	task4();

	segment("task 5");
	task5();

	return 0;
}