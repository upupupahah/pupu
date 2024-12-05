#include <iostream>
#include <cmath>
int main()
{
	int N, k;
	float max = 0;
	std::cout << "enter N: ";
	std::cin >> N;
	for (int i = 1; i <= N; i++)
	{
		float a = sin(i + i / N);
		if (a > max)
			{
				max = a;
				k = i;
			}
	}
	std::cout << "max = " << max << "; i = " << k << std::endl;
	return 0;
}