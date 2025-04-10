#include <iostream>

int interpolationSearch(int arr[], int low, int high, int x) {
	while (low <= high && x >= arr[low] && x <= arr[high])
	{
		if (low == high)
		{
			if (arr[low] == x) {
				return low;
			}
			return -1;
		}
		int pos = low + (((x - arr[low]) * (high - low)) / (arr[high] - arr[low]));
		if (arr[pos] == x) {
			return pos;
		}
		if (arr[pos] < x) {
			low = pos + 1;
		}
		else {
			high = pos - 1;
		}
	}
	return -1;
}

int main() {
	const int n = 20;
	int x, arr[n] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
	std::cin >> x;
	int result = interpolationSearch(arr, 0, n-1, x);
	if (result == -1) {
		std::cout << "not founded.";
	}
	else {
		std::cout << "index of " << x << ": " << result;
	}
	return 0;
}