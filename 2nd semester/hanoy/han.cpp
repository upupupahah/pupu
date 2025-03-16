#include <iostream>

void Han (int n, int start = 1, int temp = 2, int point = 3) {
	if (n > 0) {
		Han(n - 1, start, point, temp);
		std::cout << "disk " << n << ": " << start << " ---> " << point << std::endl;
		Han(n - 1, temp, start, point);
	}
}

int main() {
	int n;
	std::cout << "enter count of circles: ";
	std::cin >> n;
	Han(n);
	return 0;
}