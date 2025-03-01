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
		
		for (int i = ++first_arg; i < sec_arg; i++) {
			bool s = 1;
			if (i < 2) {
				s = 0;
			}
			for (int j = 2; j < i; j++) {
				if (i % j == 0) {
					s = 0;
				}	
			}
			if (s) {
				std::cout << i << " ";
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