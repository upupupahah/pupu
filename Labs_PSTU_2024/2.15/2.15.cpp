#include <iostream>
#include <cmath>
int main()
{
	int N, S;
	bool t = 0;
	std::cout << "enter N: ";
	std::cin >> N;
	std::cout << "enter S: ";
	std::cin >> S;
	for (int i = 1; i < 100; i++)
	{
		int f = pow(10, i);
		// std::cout << f << std::endl;
		int x = (N % f) - N%(f/10);
		x = x / (f / 10);
		if (x == 0)
		{
			break;
		}
		// std::cout << "its x: " << x << std::endl;
		if (x == S)
		{
			t = 1;
			break;
		}
	}
	if (t == 1)
	{
		std::cout << "TRUE, S in N";
	}
	else
	{
		std::cout << "FALSE, S not in N";
	}
	return 0;
}