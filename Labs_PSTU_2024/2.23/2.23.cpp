#include <iostream>
#include <cmath>
int main()
{
	int N, count = 0;
	float max = 0, min;
	std::cout << "enter N: ";
	std::cin >> N;
	for (int i = 1; i <= N; i++)
	{
		float a = sin(i + i / N);
		if (i == 1)
		{
			min = a;
		}
		else
		{
			if (a > max)
			{
				max = a;
			}
		}
	}
	std::cout << "max = " << max << std::endl;
	for (int i = 1; i <= N; i++)
	{
		float a = sin(i + i / N);
		if (a == max)
		{
			count++;
		}
	}
	std::cout << count;
	return 0;
}