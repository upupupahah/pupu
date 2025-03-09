/*
1) Скопировать из файла F1 в файл F2 все строки,
начинающиеся на букву «А» расположенные между строками
с номерами N1 и N2, а затем все строки от N2 + 3 и до
последней.
2) Определить количество слов в последней строке файла
F2.
*/

#include <cstdio>
#include <iostream>

int countLines(FILE* file) {
	int count = 0, t;
	while ((t = fgetc(file)) != EOF) {
		if (t == '\n') {
			count++;
		}
	}
	if (t != '\n') {
		count++;
	}
	return count;
}

void copyToF2(std::string line, bool is_last) {
	FILE* F2 = fopen("F2.txt", "a");
	for (int i = 0; i < line.length(); i++) {
		char t = line[i];
		fputc(t, F2);
	}
	if (!is_last) {
		fputc('\n', F2);
	}
	fclose(F2);
}

int count_of_words(std::string line) {
	int count = 1;
	if (line == "\n") {
		return 0;
	}
	for (int i = 0; i < line.length(); i++) {
		if (line[i] == ' ') {
			count++;
		}
	}
	return count;
}

int main() {
	FILE* F1 = fopen("F1.txt", "r");
	int lenF1 = countLines(F1);
	rewind(F1); // возвращение указателя в начало файла
	// блок "визуализации"
	std::cout << "count of lines in F1: " << lenF1 << std::endl;
	int N1, N2;
	std::cout << "enter N1, N2:" << std::endl;
	std::cin >> N1;
	std::cin >> N2;
	std::cout << std::endl;
	// выполнение задания
	if (N1 < 1 || N2 < 1 || N1 > lenF1 || N2 > lenF1 || N1 > N2 || N2 + 3 > lenF1) {
		std::cout << "ERROR. wrong values.";
	}
	else {
		int t;
		int num_of_string = 0;
		std::string line = "";
		while (true) {
			t = fgetc(F1);
			if (t == EOF) {
				std::cout << std::endl;
				std::cout << "number of words in last F2 line = " << count_of_words(line) << std::endl;
				copyToF2(line, true);
				break;
			}
			else {
				// получение строки
				if ((char)t == '\n') {
					num_of_string++;
					if (N1 < num_of_string && num_of_string < N2) {
						if (line[0] == 'A') {
							std::cout << "line #" << num_of_string << ": " << line << std::endl;
							copyToF2(line, false);
						}
					}
					if (num_of_string > N2 + 3) {
						copyToF2(line, false);
					}
					line = "";
				}
				else {
					line += char(t);
				}
			}
		}
	}
	fclose(F1);
	return 0;
}