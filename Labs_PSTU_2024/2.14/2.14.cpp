#include <iostream>
int main()
{
	int N, sum = 0;
	std::cin >> N;
	while (N > 9)
	{
		sum += N % 10;
		N /= 10;
	}
	sum += N;

	std::cout << "summa = " << sum;
	return 0;
}