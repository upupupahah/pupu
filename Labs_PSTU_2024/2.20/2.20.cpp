#include <iostream>
#include <cmath>
int main()
{
	int N;
	float S;
	bool t = 0;
	std::cout << "enter N: ";
	std::cin >> N;
	std::cout << "enter S: ";
	std::cin >> S;
	for (int i = 1; i <= N; i++)
	{
		float a;
		a = sin(i + i / N);
		if (a == S)
		{
			t = 1;
			break;
		}
	}
	if (t == 1)
	{
		std::cout << "TRUE, S in N";
	}
	else
	{
		std::cout << "FALSE, S not in N";
	}
	return 0;
}