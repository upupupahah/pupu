#include <iostream>
int main()
{
	int N;
	std::cin >> N;
	if (N <= 2)
	{
		std::cout << "error";
		return 0;
	}
	else
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 0; j < i; j++)
			{
				std::cout << "*";
			}
			std::cout << std::endl;
		}
	}
	return 0;