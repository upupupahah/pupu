/*
Создать класс Pair (пара чисел). Пара должна быть представлено двумя полями:
типа int для первого числа и типа double для второго.
Первое число при выводе на экран должно быть отделено от второго числа двоеточием.
Реализовать:
	- операции сравнения (<, >).
	- операция --, которая работает следующим образом: если форма операции префиксная,
то уменьшается первое число, если форма операции постфиксная, то уменьшается второе число.
*/

#include <iostream>

class Pair {
	int first;
	double second;

public:
	Pair(int f = 0, double s = 0.0) : first(f), second(s) {}
	~Pair() {}

	Pair& operator=(Pair& a) {
		if (this != &a) {
			first = a.first;
			second = a.second;
		}
		return *this;
	}

	bool operator>(Pair& a) { return (first + second) > (a.first + a.second); }
	bool operator<(Pair& a) { return (first + second) < (a.first + a.second); }

	Pair& operator--() {
		--first;
		return *this;
	}
	Pair operator--(int) {
		Pair tmp(*this);
		--second;
		return tmp;
	}

	friend std::ostream& operator<<(std::ostream& os, Pair& a) {
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
};

int main() {
	Pair a(1, 0.128);
	Pair b;

	std::cout << "pair a: " << a << std::endl;
	std::cout << "enter new pair: ";
	std::cin >> b;
	std::cout << "pair b: " << b << std::endl;

	if (a > b) std::cout << "a > b" << std::endl;
	else std::cout << "a < b" << std::endl;
	
	--a;
	b--;
	std::cout << "prefix a: " << a << std::endl;
	std::cout << "postfix b: " << b << std::endl;

	a = b;
	std::cout << "after assignment a = b: a = " << a << ", b = " << b << std::endl;

	return 0;
}