#include <iostream>

int main()
{
	float a, b, c;
	float* aPtr;
	float* bPtr;
	a = 15.51;
	b = 51.5;
	std::cout << a << " " << b << std::endl;
	aPtr = &a;
	bPtr = &b;
	c = *aPtr + *bPtr;
	std::cout << c << std::endl;
	return 0;
}