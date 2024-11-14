#include <iostream>

int main()
{
	int a, b, c;
	int* aPtr;
	int* bPtr;
	a = 15;
	b = 51;
	std::cout << a << " " << b << std::endl;
	aPtr = &a;
	bPtr = &b;
	c = *aPtr;
	a = *bPtr;
	b = c;
	std::cout << a << " " << b << std::endl;
	return 0;
}