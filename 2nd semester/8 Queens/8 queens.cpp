#include <iostream>

const int size = 8;
int board[size][size];
int count = 0;

// вывод доски
void show() { 
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (board[i][j]) { 
                std::cout << "# ";
            }
            else {
                std::cout << ". ";
            }
        }
        std::cout << std::endl;
    }
}

// бьется ли ячейка
int check(int i, int j) {
    // проверка столбца
    for (int c = 0; c < i; c++) {
        if (board[c][j]) {
            return 0;
        }
    }

    // проверка диагонали влево вверх
    for (int c = 1; c <= i && j - c >= 0; c++) {
        if (board[i - c][j - c]) {
            return 0;
        }
    }

    // проверка диагонали вправо вверх
    for (int c = 1; c <= i && j + c < size; c++) {
        if (board[i - c][j + c]) {
            return 0;
        }
    }
    return 1;
}

// i - номер строки
void set(int i) {
    if (i == size) {
        std::cout << "Variation " << ++count << ":" << std::endl;
        show();
        std::cout << std::endl << std::endl;
        return;
    }
    for (int ii = 0; ii < size; ii++) {
        // проверка строки
        if (check(i, ii)) {
            board[i][ii] = 1;
            set(i + 1);
            board[i][ii] = 0; // обнуление доски
        }
        // else - откат к предыдущей строке со смещением ферзя
    }
}

int main() {
    set(0);
    return 0;
} 