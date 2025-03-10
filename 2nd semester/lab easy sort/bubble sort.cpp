#include <iostream>

void bubbleSort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
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
	bubbleSort(arr, n);
	std::cout << std::endl << std::endl;
	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << ' ';
	}
	return 0;
}