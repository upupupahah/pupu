#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

// Слияние двух упорядоченных файлов в один
void merge(const string& output, const string& input1, const string& input2) {
    ifstream in1(input1), in2(input2);
    ofstream out(output);

    int val1, val2;
    bool hasVal1 = !!(in1 >> val1), hasVal2 = !!(in2 >> val2);

    while (hasVal1 && hasVal2) {
        if (val1 <= val2) {
            out << val1 << " ";
            hasVal1 = !!(in1 >> val1);
        }
        else {
            out << val2 << " ";
            hasVal2 = !!(in2 >> val2);
        }
    }

    // Дописываем оставшиеся элементы
    while (hasVal1) { out << val1 << " "; hasVal1 = !!(in1 >> val1); }
    while (hasVal2) { out << val2 << " "; hasVal2 = !!(in2 >> val2); }

    in1.close(); in2.close(); out.close();
}

// Распределение серий по лентам (естественное разбиение)
void distribute(const string& input, const vector<string>& tapes) {
    ifstream in(input);
    if (!in.is_open()) {
        cerr << "Error" << endl;
        return;
    }

    vector<ofstream> outs;
    for (const auto& tape : tapes) {
        outs.emplace_back(tape);
        if (!outs.back().is_open()) {
            cerr << "Error" << endl;
            return;
        }
    }

    int current, next;
    if (!(in >> current)) return;  

    size_t tapeIdx = 0;
    outs[tapeIdx] << current << " ";

    while (in >> next) {
        if (next < current) {  // Конец серии
            tapeIdx = (tapeIdx + 1) % tapes.size();
        }
        outs[tapeIdx] << next << " ";
        current = next;
    }
    for (auto& out : outs) out.close();
    in.close();
}

// Многофазная сортировка слиянием
void naturalMergeSort(const string& inputFile, const string& outputFile, int k = 3) {
    if (k < 2) {
        cerr << "Error" << endl;
        return;
    }

    // Создаём имена для временных файлов
    vector<string> tapes(k);
    for (int i = 0; i < k; ++i) {
        tapes[i] = "temp_tape_" + to_string(i) + ".txt";
    }

    // 1. Распределяем серии по лентам
    distribute(inputFile, tapes);

    // 2. Многофазное слияние
    string tempFile = "temp_merge.txt";
    int activeTapes = k;

    while (activeTapes > 1) {
        int tape1 = -1, tape2 = -1;
        for (int i = 0; i < k; ++i) {
            ifstream f(tapes[i]);
            if (f.peek() != EOF) {
                if (tape1 == -1) tape1 = i;
                else if (tape2 == -1) tape2 = i;
                else break;
            }
            f.close();
        }

        if (tape2 == -1) break; 
        // Сливаем их во временный файл
        merge(tempFile, tapes[tape1], tapes[tape2]);

        // Удаляем исходные ленты и переименовываем временный файл
        remove(tapes[tape1].c_str());
        remove(tapes[tape2].c_str());
        rename(tempFile.c_str(), tapes[tape1].c_str());
        activeTapes--;
    }

    // 3. Переименовываем результат в выходной файл
    for (int i = 0; i < k; ++i) {
        ifstream f(tapes[i]);
        if (f.peek() != EOF) {
            f.close();
            remove(outputFile.c_str());
            rename(tapes[i].c_str(), outputFile.c_str());
            break;
        }
        f.close();
    }

    // 4. Удаляем временные файлы
    for (const auto& tape : tapes) {
        remove(tape.c_str());
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    srand(unsigned(time(nullptr)));
    const int n = 20;
    int mas[n];
    ofstream file("D:\\2 сем\\Естественная сортировка\\input.txt");
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
    string inputFile = "input.txt";
    string outputFile = "output_sorted.txt";

    naturalMergeSort(inputFile, outputFile, 10);

    cout << "Результат выведен в файл " << outputFile << endl;
    ifstream sort("D:\\2 сем\\Естественная сортировка\\output_sorted.txt");
    cout << "Результат" << endl;
    int k;
    while (sort >> k)
    {
        cout << k << ' ';

    }
    cout << endl << endl;
    return 0;
}