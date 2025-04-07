#include <iostream>

void shellSort(int arr[], int n)
{
	for (int h = n / 2; h > 0; h /= 2)
	{
		for (int i = h; i < n; i++)
		{
			int tmp = arr[i];
			int j;
			for (j = i; j >= h && arr[j - h] > tmp; j -= h)
			{
				arr[j] = arr[j - h];
			}
			arr[j] = tmp;
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

	std::cout << std::endl << std::endl;

	shellSort(arr, n);

	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << ' ';
	}

	return 0;
}