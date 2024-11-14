#include <iostream>

int main()
{
	int N, x, *aPtr = &x, max, min;
	std::cin >> N;
	std::cout << "enter first number:\n";
	std::cin >> *aPtr;
	min = *aPtr;
	max = *aPtr;
	for (int i = 2; i <= N; i++)
	{
		std::cin >> *aPtr;
		if (*aPtr > max)
		{
			max = *aPtr;
		}
		else if (*aPtr < min)
		{
			min = *aPtr;
		}
	}
	std::cout << "max: " << max << std::endl;
	std::cout << "min: " << min << std::endl;
	return 0;
}