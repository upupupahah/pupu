#include <iostream>

int partition(int arr[], int low, int high) {
	int point = arr[low];
	int num = 0;
	for (int i = low + 1; i <= high; i++)
	{
		if (arr[i] < point) {
			num++;
		}
	}

	int pos = low + num;
	std::swap(arr[pos], arr[low]);
	int i = low, j = high;

	while (i<pos && j>pos) {
		while (arr[i] < point) {
			i++;
		}
		while (arr[j] > point) {
			j--;
		}
		if (i < pos && j > pos) {
			std::swap(arr[i++], arr[j--]);
		}
	}
	return pos;	
}

void sortHoare(int arr[], int low, int high) {
	if (low >= high) {
		return;
	}
	int ind = partition(arr, low, high);
	sortHoare(arr, low, ind - 1);
	sortHoare(arr, ind + 1, high);
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

	sortHoare(arr, 0, n - 1);
	
	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << ' ';
	}

	return 0;
}