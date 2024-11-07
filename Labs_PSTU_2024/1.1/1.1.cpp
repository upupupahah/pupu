#include <iostream>

int main()
{
	int a, b, c, max;
	std::cin >> a >> b >> c;
	if (a >= b)
	{
		max = a;
	}
	else
	{
		max = b;
	}
	if (c > max)
	{
		max = c;
	}
	std::cout << max << std::endl;
	return 0;
}
