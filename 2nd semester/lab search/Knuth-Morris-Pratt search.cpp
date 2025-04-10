#include <iostream>

int* calcPrefixFunc(std::string pat, int size)
{
	int* lps = new int[size]; 
	int len = 0;
	lps[0] = 0;
	int i = 1;
	while (i < size) {
		if (pat[i] == pat[len])
		{
			len++;
			lps[i] = len;
			i++;
		}
		else
		{
			if (len != 0) { len = lps[len - 1]; }
			else { lps[i] = 0; i++; }
		}
	}
	for (int i = 0; i < size; i++)
	{
		std::cout << lps[i];
	}
	std::cout << std::endl;
	return lps;
}

void knuthMorrisPrattSearch(std::string str, std::string pat)
{
	int strSize = str.size();
	int patSize = pat.size();
	int* lps = calcPrefixFunc(pat, patSize);
	int strIdx = 0;
	int patIdx = 0;
	while ((strSize - strIdx) >= (patSize - patIdx))
	{
		if (pat[patIdx] == str[strIdx])
		{
			patIdx++;
			strIdx++;
		}
		if (patIdx == patSize)
		{
			std::cout << "founded: " << strIdx - patIdx << std::endl;
			patIdx = lps[patIdx - 1];
		}
		else if (strIdx < strSize && pat[patIdx] != str[strIdx])
		{
			if (patIdx != 0) { patIdx = lps[patIdx - 1]; }
			else { strIdx++; }
		}
	}
}

int main()
{
	std::string inputStr, searchStr;
	std::cin >> inputStr;
	std::cin >> searchStr;
	knuthMorrisPrattSearch(inputStr, searchStr);
	return 0;
}