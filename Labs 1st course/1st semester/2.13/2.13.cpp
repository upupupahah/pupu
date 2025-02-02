#include <iostream>
#include <cmath>
int main()
{
	int a, b, c; 
	float D, x1, x2;
	std::cout << "enter coefficient a: ";
	std::cin >> a;
	std::cout << "enter coefficient b: ";
	std::cin >> b;
	std::cout << "enter coefficient c: ";
	std::cin >> c;
	D = b * b - 4 * a * c;
	if (D == 0)
	{
		std::cout << "x = " << (-1 * b) / (2 * a);
	}
	else if (D > 0)
	{
		std::cout << "x1 = " << ((-1 * b) + sqrt(D)) / (2 * a) << std::endl;
		std::cout << "x2 = " << ((-1 * b) - sqrt(D)) / (2 * a);
	}
	else
	{
		std::cout << "D < 0";
	}
	return 0;
}