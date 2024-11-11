#include <iostream>
int main()
{
	int N;
	std::cin >> N;
	if (N % 2 == 0 or N < 3)
	{
		std::cout << "error";
		return 0;
	}
	for (int i = 0; i <= N; i++)
	{
		if (i % 2 != 0)
		{
			for (int q = 0; q <= (N - i) / 2; q++)
			{
				std::cout << " ";
			}
			for (int j = 0; j < i; j++)
				std::cout << "*";
			std::cout << std::endl;
		}
	}
	return 0;
}