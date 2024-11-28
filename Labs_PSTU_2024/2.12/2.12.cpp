#include <iostream>
int main()
{
	int N, a, max = 0, min = 10 * 10 * 10 * 10 * 10 * 10 * 10 * 10 * 10;
	std::cin >> N;
	for (int i = 1; i <= N; i++)
	{
		std::cin >> a;
		if (a > max)
		{
			max = a;
		}
		if (a < min)
		{
			min = a;
		}
	}
	std::cout << "sum = " << max + min;
	return 0;
}