#include <iostream>

const int CHAR_NUM = 256;

void calcCharTable(std::string pat, int size, int charTable[CHAR_NUM])
{
	for (int i = 0; i < CHAR_NUM; i++) {
		charTable[i] = -1;
	}
	for (int i = 0; i < size; i++) {
		charTable[(int)pat[i]] = i;
	}
}

void BoyerMooreSearch(std::string str, std::string pat) {
    int strSize = str.size();
    int patSize = pat.size();
    int shiftTable[CHAR_NUM];
    calcCharTable(pat, patSize, shiftTable);
    int shift = 0;

    while (shift <= (strSize - patSize)) {
        int j = patSize - 1;
        while (j >= 0 && pat[j] == str[shift + j]) {
            j--;
        }

        if (j < 0) {
            std::cout << "founded: " << shift << std::endl;
            shift += (shift + patSize < strSize) ?
                patSize - shiftTable[(int)str[shift + patSize]] : 1;
        }
        else {
            int tableVal = shiftTable[(int)str[shift + j]];
            shift += (j - tableVal > 0) ? j - tableVal : 1;
        }
    }
}

int main() {
	std::string inputStr, searchStr;
	std::cin >> inputStr;
	std::cin >> searchStr;
	BoyerMooreSearch(inputStr, searchStr);
	return 0;
}