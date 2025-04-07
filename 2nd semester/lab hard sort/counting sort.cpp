#include <iostream>

void countingSort(int arr[], int size)
{
	int* output = new int[size];
	int* count;
	int max = arr[0];

	for (int i = 0; i < size; i++)
	{
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	count = new int[max + 1];

	for (int i = 0; i <= max; ++i) {
		count[i] = 0;
	}
	for (int i = 0; i < size; i++) {
		count[arr[i]]++;
	}
	for (int i = 1; i <= max; ++i)
	{
		count[i] += count[i - 1];
	}
	for (int i = size - 1; i >= 0; i--)
	{
		output[count[arr[i]] - 1] = arr[i];
		count[arr[i]]--;
	}
	for (int i = 0; i < size; i++) {
		arr[i] = output[i];
	}

	delete[] count;
	delete[] output;

	return;
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

	countingSort(arr, n);

	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << ' ';
	}

	return 0;
}