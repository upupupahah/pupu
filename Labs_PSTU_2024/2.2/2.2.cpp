#include <iostream>
int main()
{
	int N, pr = 1, x;
	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		std::cin >> x;
		pr *= x;
	}
	std::cout << pr << std::endl;
	return 0;
}