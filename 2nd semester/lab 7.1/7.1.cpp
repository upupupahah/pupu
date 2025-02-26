#include <iostream>

// 7.1 
// а) для массива целых чисел находит среднее арифметическое;
// б) для строки находит количество букв, содержащихся в ней.

int Func(int* ptr, int i) {
	float sum = 0;
	for (int j = 0; j < i; j++)
	{
		sum += *(ptr + j);
	}
	
	std::cout << "It`s int function.\nArithmetic = ";
	std::cout << sum / i << std::endl;

	return 0;
}

std::string Func(std::string message, int i) {
	int count = 0;
	for (int j = 0; j < i; j++) {
		if (message[j] != ' ') count++;
	}
	std::cout << "there is " << count << " letters.";

	return 0;
}

int main() {
	int i = 10;
	int arr[i];
	std::cout << "Your array is:\n";
	for (int j = 0; j < i; j++) {
		arr[j] = j;
	}
	for (int o = 0; o < i; o++) {
		std::cout << arr[o] << "  ";
	}
	Func(arr, i);

    std::cout <<std::endl << "*********************************" << std::endl;

	std::string message = "Hello, amigo! Welcome to PNIPU, we are good!";
	std::cout << "Your string is: " << message << std::endl;
	i = message.length();
	Func(message, i);

	return 0;
}