#include <iostream>

int partition(int arr[], int low, int high) {
	int point = arr[high];
	int i = low - 1;
	for (int j = low; j <= high - 1; j++) {
		if (arr[j] <= point) {
			i++;
			std::swap(arr[i], arr[j]);
		}
	}
	std::swap(arr[i + 1], arr[high]);
	return i + 1;
}

void sortLomuto(int arr[], int low, int high) {
	if (low >= high) {
		return;
	}
	int ind = partition(arr, low, high);
	sortLomuto(arr, low, ind - 1);
	sortLomuto(arr, ind + 1, high);


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

	std::cout << std::endl << std::endl;

	sortLomuto(arr, 0, n - 1);
	
	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << ' ';
	}

	return 0;
}