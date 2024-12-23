#include <iostream>
#include <cmath>
int func(int n, float x, float sum)
{
	if (n == 0)
	{
		std::cout << sum;
		return 1;
	}
	else
	{
		std::cout << "new x =" << pow(-1, n - 1) * (pow(x, n) / n) << std::endl;
		sum += pow(-1, n - 1) * (pow(x, n) / n);
		return func(n - 1, x, sum);
	}

}
int main()
{
	int n, sum = 0;
	std::cout << "enter n: ";
	std::cin >> n;
	std::cout << "enter x: ";
	float x;
	std::cin >> x;
	func(n, x, sum);
	return 1;
}