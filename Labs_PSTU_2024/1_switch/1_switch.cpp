#include <iostream>
#include <cmath>
int main()
{
	float a, b;
	int c;
	std::cin >> a >> b;
	std::cout << "\n1: a + b\n2: a - b\n3: a * b\n4: a / b\n\nenter operation code (1-4): ";
	std::cin >> c;
	switch (c)
	{
	case 1: std::cout << a << " " << "+ " << b << " = " << a + b; break;
	case 2: std::cout << a << " " << "- " << b << " = " << a - b; break;
	case 3: std::cout << a << " " << "* " << b << " = " << a * b; break;
	case 4:
	{
		if (b == 0)
		{
			std::cout << "error, b = 0.";
		}
		else
		{
			std::cout << a << " " << "/ " << b << " = " << a / b;
		}
		break;
	}
	default: std::cout << "error";
	}
	return 0;
}