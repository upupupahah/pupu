#include <iostream>

int linearSearch(int arr[], int n, int x) {
	for (int i = 0; i < n; i++) {
		if (arr[i] == x) {
			return i;
		}
	}
	return -1;
}

int main() {
	const int n = 20;
	int x, arr[n] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
	std::cin >> x;
	int result = linearSearch(arr, n, x);
	if (result == -1) {
		std::cout << "not founded.";
	}
	else {
		std::cout << "index of " << x << ": " << result;
	}
	return 0;
}