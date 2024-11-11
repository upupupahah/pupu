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
		for (int i = N - 1; i >= 0 ; i--)
		{
			for (int x = 1; x < N - i; x++)
			{
				std::cout << " ";
			}
			for (int j = 0; j <= i; j++)
			{
				std::cout << "*";
			}
			std::cout << std::endl;
		}
	}
	return 0;
}