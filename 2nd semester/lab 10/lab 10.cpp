// Сформировать массив строк. Удалить из него самую длинную строку.
#include <iostream>

void delete_longest(std::string*& array, int& size) {
	int index = 0;
	for (int i = 0; i < size; i++) {
		if (array[i].length() > array[index].length()) {
			index = i;
		}
	}
	for (int i = index; i < size - 1; i++) {
		array[i] = array[i + 1];
	}
	size--;

}

int main()
{
	int size = 5;
	
	std::string* array = new std::string[size]{ "apple", "banana", "grape", "melon", "orange" };

	std::cout << "original array: " << size << " items" << std::endl;
	for (int i = 0; i < size; ++i) {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl << std::endl;

	delete_longest(array, size);

	std::cout << "new array: " <<size << " items" << std::endl;
	for (int i = 0; i < size; ++i) {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;

	delete[] array;
	return 0;
}
