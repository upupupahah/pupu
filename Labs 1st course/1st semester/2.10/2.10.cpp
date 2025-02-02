#include <iostream>
int main()
{
	int N, a, max = 0;
	std::cin >> N;
	for (int i = 1; i <= N; i++)
	{
		std::cin >> a;
		if (a > max)
		{
			max = a;
		}
	}
	std::cout << "max: " << max;
	return 0;
}