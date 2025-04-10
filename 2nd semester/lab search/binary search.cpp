#include <iostream>

int binarySearch(int arr[], int low, int high, int x) {
	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (arr[mid] == x) {
			return mid;
		}
		if (arr[mid] < x) {
			low = ++mid;
		}
		else {
			high = --mid;
		}
	}
	return -1;
}

int main() {
	const int n = 20;
	int x, arr[n] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
	std::cin >> x;
	int result = binarySearch(arr, 0, n-1, x);
	if (result == -1) {
		std::cout << "not founded.";
	}
	else {
		std::cout << "index of " << x << ": " << result;
	}
	return 0;
}