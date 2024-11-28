#include <iostream>
int main()
{
	int N, a;
	bool flagUp = 0, flagDown = 0;
	std::cin >> N;
	for (int i = 1; i <= N; i++)
	{
		std::cin >> a;
		if (!flagUp && !flagDown)
		{
			if (a > 0)
			{
				flagUp = 1;
			}
			else if (a < 0)
			{
				flagDown = 1;
			}
		}
	}
	if (flagUp)
	{
		std::cout << "the positive was first";
	}
	else if (flagDown)
	{
		std::cout << "the negative was first";
	}
	else
	{
		std::cout << "zero sequence";
	}
	return 0;
}