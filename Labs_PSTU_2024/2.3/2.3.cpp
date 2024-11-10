#include <iostream>
int main()
{
	int S = 0, N, x;
	std::cin >> N;
	for (int i = 1; i <= N; i++)
	{
		x = 1;
		for (int ii = i; ii <= 2*i; ii++)
		{
			x *= ii;
		}
		S = S + x;
	}
	std::cout << S;
	return 0;
}