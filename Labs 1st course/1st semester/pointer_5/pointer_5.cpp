#include <iostream>

int main()
{
	unsigned int N, fact = 1;
	unsigned int* f = &fact;
	std::cin >> N;
	for (int i = 1; i <= N; i++)
	{
		*f *= i;
	}
	std::cout << *f;
	return 0;
}