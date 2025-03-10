#include <iostream>

void choiceSort(int arr[], int n) {
	int tmp, minIndex;
	for (int i = 0; i < n - 1; i++) {
		minIndex = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[minIndex]) {
				minIndex = j;
			}
		}
		tmp = arr[minIndex];
		arr[minIndex] = arr[i];
		arr[i] = tmp;
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
	choiceSort(arr, n);
	std::cout << std::endl << std::endl;
	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << ' ';
	}
	return 0;
}