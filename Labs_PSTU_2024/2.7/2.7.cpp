#include <iostream>
#include <cmath>
int main()
{
	int N;
	std::cin >> N;
	auto k = sqrt(N);
	if (N == k * k or N > 1)
	{
		std::cout << "1. possible:\n";
		for (int i = 0; i < k; i++)
		{
			for (int j = 0; j < k; j++)
			{
				std::cout << "*";
			}
			std::cout << std::endl;
		}
	}
	else
	{
		std::cout << "1. impossible.\n";
	}
	if (N <= 1)
	{
		std::cout << "2. impossible.\n";
	}
	else
	{
		std::cout << "2. possible:\n";
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < N; x++)
			{
				std::cout << "*";
			}
			std::cout << std::endl;
		}
	}
	if (N <= 2)
	{
		std::cout << "3. impossible.\n";
	}
	else
	{
		std::cout << "3. possible:\n";
		for (int h = 0; h < N; h++)
		{
			for (int g = 0; g < N; g++)
			{
				if (h == 0 or h == N - 1)
				{
					std::cout << "*";
					continue;
				}
				else
				{
					if (g == 0 or g == N - 1)
					{
						std::cout << "*";
					}
					else
					{
						std::cout << " ";
					}
				}
			}
			std::cout << std::endl;
		}
	}
	return 0;
}