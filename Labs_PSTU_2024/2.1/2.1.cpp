#include <iostream>
int main()
{
	int N, sum = 0, x = 0;
	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		std::cin >> x;
		sum = sum + x;
	}
	std::cout << sum << std::endl;
	return 0;
}