#include <iostream>
int main() {
	int N;
	std::cin >> N;
	int f = N/2;
	std::cout << f<< std::endl;
	for (int i = 1; i<=f; i++)
	{
	    for (int h = f; h>0; h = h - i)
	    {
	       std::cout << "p"; 
	    }
	    if (i == 1)
	    {
	        for (int u = 1; u<= N; u++)
	        {
	            std::cout << "*";
	        }
	        std::cout << std::endl;
	    }
	    else 
	    {
	        for (int j = 1; j <= N; j++)
	        {
	            if (j==1 or j==N)
	            {
	                std::cout << "*";
	            }
	            else
	            {
	                std::cout << " ";
	            }
	        }
	        std::cout << std::endl;
	    }
	}
	return 0;

}