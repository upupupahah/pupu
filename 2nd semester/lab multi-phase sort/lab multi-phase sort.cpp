#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

void merge(const string& output, const string& tape1, const string& tape2)
{
    ifstream in1(tape1), in2(tape2);
    ofstream out(output);
    int val1, val2;
    bool hasVal1 = static_cast<bool>(in1 >> val1), hasVal2 = static_cast<bool>(in2 >> val2);

    while (hasVal1 && hasVal2)
    {
        if (val1 <= val2) {
            out << val1 << " ";
            hasVal1 = !!(in1 >> val1);
        }
        else {
            out << val2 << " ";
            hasVal2 = !!(in2 >> val2);
        }
    }
    while (hasVal1) { out << val1 << ' '; hasVal1 = static_cast<bool>(in1 >> val1); }
    while (hasVal2) { out << val2 << ' '; hasVal2 = static_cast<bool>(in2 >> val2); }

    in1.close(); in2.close(); out.close();
}
// Распределение серий по лентам с оптимизацией Фибоначчи
void distrub(const string& input, const string* tapes, int k)
{
    ifstream in(input);
    if (!in.is_open()) return;

    // Генерация чисел Фибоначчи
    int* fib = new int[k + 1] {0, 1};
    for (int i = 2; i <= k; ++i)
        fib[i] = fib[i - 1] + fib[i - 2];

    ofstream* outs = new ofstream[k];
    for (int i = 0; i < k; ++i) {
        outs[i].open(tapes[i]);
        if (!outs[i].is_open()) {
            cout << "Ошибка";
            // Освобождаем ресурсы при ошибке
            for (int j = 0; j < i; ++j) outs[j].close();
            delete[] outs;
            delete[] fib;
            in.close();
            return;
        }
    }

    int current, next, tapeIdx = 0;
    int* runsPerTape = new int[k] {0};
    if (in >> current)
    {
        outs[tapeIdx] << current << " ";
        runsPerTape[tapeIdx]++;
        while (in >> next)
        {
            if (next < current)
            {
                // Выбираем ленту с наименьшим числом серий
                tapeIdx = (tapeIdx + 1) % k;
            }
            outs[tapeIdx] << next << " ";
            current = next;
        }
    }
    for (int i = 0; i < k; ++i) outs[i].close();
    delete[] outs;
    in.close();
}
// Основная функция сортировки
void multi(const string& inputFile, int k = 3)
{
    if (k < 2) return; // ошибка

    string* tapes = new string[k];
    for (int i = 0; i < k; ++i)
        tapes[i] = "C:\\labs_2sem\\mnogofaz\\int" + to_string(i) + ".txt";

    distrub(inputFile, tapes, k);
    string tempFile = "C:\\labs_2sem\\mnogofaz\\inp.txt";
    int activTape = k;

    while (activTape > 1)
    {
        // Находим непустые ленты
        int nonEmpty1 = -1, nonEmpty2 = -1;
        for (int i = 0; i < k; ++i) {
            ifstream f(tapes[i]);
            if (f.peek() != ifstream::traits_type::eof()) {
                if (nonEmpty1 == -1) nonEmpty1 = i;
                else if (nonEmpty2 == -1) nonEmpty2 = i;
                else break;
            }
            f.close();
        }

        if (nonEmpty2 == -1) break; // Осталась одна лента с данными

        merge(tempFile, tapes[nonEmpty1], tapes[nonEmpty2]);
        remove(tapes[nonEmpty1].c_str());
        remove(tapes[nonEmpty2].c_str());
        rename(tempFile.c_str(), tapes[nonEmpty1].c_str());
        activTape--;
    }

    // Определяем файл с результатом
    for (int i = 0; i < k; ++i) {
        ifstream f(tapes[i]);
        if (f.peek() != ifstream::traits_type::eof()) {
            f.close();
            remove("C:\\labs_2sem\\mnogofaz\\in_sorted.txt");
            if (rename(tapes[i].c_str(), "C:\\labs_2sem\\mnogofaz\\in_sorted.txt") != 0)
                perror("Failed to rename result file");
            break;
        }
        f.close();
    }

    // Удаляем временные файлы
    for (int i = 0; i < k; ++i)
        remove(tapes[i].c_str());
    delete[] tapes;
}
int main()
{
    setlocale(LC_ALL, "ru");
    srand(unsigned(time(nullptr)));
    const int n = 20;
    int mas[n];
    ofstream file("C:\\labs_2sem\\mnogofaz\\in.txt");
    for (int i = 0; i < n; i++)
    {
        mas[i] = rand() % 100 - 50;
        file << mas[i] << endl;
    }
   
    cout << "Массив: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << mas[i] << ' ';
    }
    cout << endl << endl;
    multi("C:\\labs_2sem\\mnogofaz\\in.txt", 15);
    ifstream sort("C:\\labs_2sem\\mnogofaz\\in_sorted.txt");
    cout << "Результат" << endl;
    int k;
    while (sort >> k)
    {
        cout << k << ' ';

    }
    cout << endl <<endl;
    return 0;
}