#include <iostream>

int main()
{
	int N;
	std::cin >> N;
	int sum = 0;
	for (int i = 1; i <= N; i++)
	{
		int k = i;
		for (int j = i+1; j <= i * 2; j++)
		{
			k *= j;
		}
		sum += k;
	}
	std::cout << sum;
	return 0;
}