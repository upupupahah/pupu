#include <iostream>

void insertSort(int arr[], int n) {
	int tmp;
	for (int i = 0; i < n; i++) {
		tmp = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > tmp) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = tmp;
	}
}

int main() {
	const int n = 50;
	int rMax = 1000000, rMin = 0;
	int arr[n];
	for (int i = 0; i < n; i++) {
		arr[i] = ((double)rand() / RAND_MAX) * (rMax - rMin) + rMin;
	}
	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << ' ';
	}
	insertSort(arr, n);
	std::cout << std::endl << std::endl;
	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << ' ';
	}
	return 0;
}