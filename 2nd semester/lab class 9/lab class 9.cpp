/*
Класс-контейнер СПИСОК с ключевыми значениями типа int
Реализовать операции:
	[] - доступа по индексу
	+вектор - добавление списка b к списку a (a + b)
	+число - добавляет элемент в начало списка
*/
#include <iostream>

const int SIZE = 30;

class Error {
	std::string message;
public:
	Error(const std::string& msg) : message(msg) {}
	void what() const { std::cout << "Error: " << message << std::endl; }
};

class Vector {
	int size;
	int* data;
public:
	Vector() :size(0), data(nullptr) {}
	Vector(int s) {
		if (s > SIZE) throw Error("wrong size");
		size = s;
		data = new int[s] {};
	}
	Vector(const Vector& other) : size(other.size) {
		data = new int[size];
		for (int i = 0; i < size; i++) data[i] = other.data[i];
	}
	~Vector() { delete[] data; }

	int& operator[](int index) {
		if (index < 0 || index >= size) throw Error("invalid index");
		return data[index];
	}

	Vector operator+(int value) {
		if (size + 1 > SIZE) throw Error("max size reached");
		Vector newVector(size + 1);
		newVector[0] = value;
		for (int i = 0; i < size; i++) newVector[i + 1] = data[i];
		return newVector;
	}

	Vector operator--() {
		if (size == 0) throw Error("Vector is empty");
		Vector newVector(size - 1);
		for (int i = 0; i < size - 1; i++) newVector[i] = data[i + 1];
		return newVector;
	}

	friend std::ostream& operator<<(std::ostream& os, const Vector& v) {
		if (v.size == 0) return os << "Empty";
		for (int i = 0; i < v.size; i++) os << v.data[i] << " ";
		return os;
	}

	friend std::istream& operator>>(std::istream& is, Vector& v) {
		for (int i = 0; i < v.size; i++) {
			std::cout << "Element " << i << ": ";
			is >> v.data[i];
		}
		return is;
	}
};

int main() {
	try {
		Vector a(3);
		std::cout << "enter 3 el:\n";
		std::cin >> a;
		std::cout << "Vector a: " << a << std::endl;

		Vector b = a + 10;
		std::cout << "added: " << b << std::endl;

		Vector c = --b;
		std::cout << "first el deleted: " << c << std::endl;

		std::cout << "el with ind 1: " << c[1] << std::endl;
		c[5] = 10;
	}
	catch (const Error& e) {
		e.what();
	}
	return 0;
}