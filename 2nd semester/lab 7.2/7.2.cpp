#include <iostream>
#include <cstdarg>

void prost(int k, ...) {
	// va_list a; - список аргументов
	// va_start(a, k); - инициализация кол-ва аргументов
	// va_arg(a, int) - извлечение аргумента
	// va_end(a) - выход из списка

	va_list a; // список аргументов
	va_start(a, k); // инициализация кол-ва аргументов

	int first_arg = va_arg(a, int);
	for (int i = 1; i < k; i++) {
		int sec_arg = va_arg(a, int);
		std::cout << "interval: (" << first_arg << "; " << sec_arg << "): ";

		for (int num = ++first_arg; num < sec_arg; num++) {
			bool is_prost = 1;
			if (num < 2) {
				is_prost = 0;
			}
			for (int j = 2; j < num; j++) {
				if (num % j == 0) {
					is_prost = 0;
				}
			}
			if (is_prost) {
				std::cout << num << " ";
			}
		}
		std::cout << std::endl;
		first_arg = sec_arg;
	}
	va_end(a);
}

int main() {
	prost(3, 10, 20, 30);
	std::cout << std::endl;
	prost(5, 40, 50, 60, 70, 80);
	std::cout << std::endl;
	prost(6, 90, 100, 110, 120, 130, 140);

	return 0;
}