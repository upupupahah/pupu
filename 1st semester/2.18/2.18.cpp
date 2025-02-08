#include <iostream>
int main()
{
	int N, r = 0;
	std::cin >> N;
	while (N > 0)
	{
		r = r * 10 + N % 10;
		N /= 10;
	}
	std::cout << r;
	return 0;
}