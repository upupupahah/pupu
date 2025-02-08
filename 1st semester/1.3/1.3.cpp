#include <iostream>

int main()
{
	float a;
	std::cin >> a;
	if (a < 5)
	{
		std::cout << a * 3;
	}
	else if (a > 7)
		{
			std::cout << a + 3;
		}
		else
		{
			std::cout << a / 10;
		}
	return 0;
}