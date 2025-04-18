/*
поле first - положительное целое число, целая часть числа, поле second - положительное дробное число, дробная часть числа
реализовать метод multiply(int k) - умножение на целое число k
*/

#include <iostream>

class num {
public:
    int first;
    float second;

    void multiply(int k) {
        std::cout << (first + second) << " * " << k << " = ";

        first *= k;
        second *= k;

        std::cout <<std::endl << (first + second) << std::endl;
    }
};

int main() {
    num task;
    int k;

    std::cout << "Enter k: ";
    std::cin >> k;
    std::cout << "Enter first and second:" << std::endl;
    std::cin >> task.first >> task.second;

    task.multiply(k);

    return 0;
}