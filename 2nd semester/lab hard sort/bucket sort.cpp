#include <iostream>

const int BUCKET_NUM = 10, BUCKET_SIZE = 10;

int* bucketSort(int arr[], int n)
{
	int buckets[BUCKET_NUM][BUCKET_SIZE];
	int bucketSizes[BUCKET_NUM] = { 0 };

	for (int i = 0; i < n; i++)
	{
		int bucketIndex = arr[i] / BUCKET_NUM;
		buckets[bucketIndex][bucketSizes[bucketIndex]] = arr[i];
		bucketSizes[bucketIndex]++;
	}

	for (int i = 0; i < BUCKET_NUM; i++)
	{
		for (int j = 0; j < bucketSizes[i]; j++)
		{
			int tmp = buckets[i][j];
			int k = j - 1;
			while (k >= 0 && buckets[i][k] > tmp)
			{
				buckets[i][k + 1] = buckets[i][k];
				k--;
			}
			buckets[i][k + 1] = tmp;
		}
	}

	int idx = 0;
	for (int i = 0; i < BUCKET_NUM; i++)
	{
		for (int j = 0; j < bucketSizes[i]; j++)
		{
			arr[idx++] = buckets[i][j];
		}
	}
	return arr;
}

int main() {
	const int n = 50;
	int rMax = 100, rMin = 0;
	int arr[n];
	for (int i = 0; i < n; i++) {
		arr[i] = ((double)rand() / RAND_MAX) * (rMax - rMin) + rMin;
	}
	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << ' ';
	}
	std::cout << std::endl << std::endl;

	bucketSort(arr, n);

	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << ' ';
	}
	std::cout << std::endl << std::endl;

	return 0;
}