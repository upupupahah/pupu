#include <iostream>

int main()
{
	float a, b;
	std::cin >> a >> b;
	if (b == 0)
	{
		std::cout << "error, b = 0.";
	}
	else
	{
		std::cout << a / b;
	}
	return 0;
}
