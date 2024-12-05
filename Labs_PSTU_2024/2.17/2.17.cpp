#include <iostream>
#include <cmath>
int main()
{
	int N, fact = 1, x;
	float sum = 1;
	std::cout << "enter x: ";
	std::cin >> x;
	std::cout << "enter N: ";
	std::cin >> N;
	for (int i = 1; i <= N; i++)
	{
		fact *= i;
		float m = pow(x, i) / fact;
		sum += m;
	}
	std::cout << sum;
	return 0;
}