#include <iostream>
#include <set>
#include <numeric>
#include <vector>

using namespace std;

void task1_addMaxToEnd(set<double>& s) {
    if (s.empty()) return;
    s.insert(*s.rbegin());
}

void task1_removeInRange(set<double>& s, double start, double end) {
    auto it_start = s.lower_bound(start);
    auto it_end = s.upper_bound(end);
    s.erase(it_start, it_end);
}

void task1_addAverage(set<double>& s) {
    if (s.empty()) return;
    double avg = accumulate(s.begin(), s.end(), 0.0) / static_cast<double>(s.size());
    set<double> new_set;
    for (auto elem : s) {
        new_set.insert(elem + avg);
    }
    s = new_set;
}
// 2
struct Pair {
    int first;
    double second;
    Pair(int f = 0, double s = 0.0) : first(f), second(s) {}
    bool operator<(const Pair& other) const {
        return (first < other.first) || (first == other.first && second < other.second);
    }
    Pair operator+(const Pair& other) const {
        return { first + other.first, second + other.second };
    }
    Pair operator/(int divisor) const {
        return { first, second / static_cast<double>(divisor) };
    }
};

void task2_addMaxToEnd(set<Pair>& s) {
    if (s.empty()) return;
    s.insert(*s.rbegin());
}

void task2_removeInRange(set<Pair>& s, const Pair& start, const Pair& end) {
    auto it_start = s.lower_bound(start);
    auto it_end = s.upper_bound(end);
    s.erase(it_start, it_end);
}

void task2_addAverage(set<Pair>& s) {
    if (s.empty()) return;
    Pair sum = accumulate(s.begin(), s.end(), Pair());
    Pair avg = sum / static_cast<int>(s.size());

    set<Pair> new_set;
    for (const auto& elem : s) {
        new_set.insert({ elem.first + avg.first, elem.second + avg.second });
    }
    s = new_set;
}

// 3
template <typename T>
class CustomList {
private:
    set<T> elements;
public:
    void add(const T& elem) { elements.insert(elem); }
    void print() const {
        for (const auto& elem : elements)
            cout << elem << " ";
        cout << endl;
    }

    // Методы заданий
    void task3_addMax() {
        if (elements.empty()) return;
        elements.insert(*elements.rbegin());
    }

    void task3_removeRange(const T& start, const T& end) {
        auto it_start = elements.lower_bound(start);
        auto it_end = elements.upper_bound(end);
        elements.erase(it_start, it_end);
    }

    void task3_addAverage() {
        if (elements.empty()) return;
        T sum = accumulate(elements.begin(), elements.end(), T());
        T avg = sum / static_cast<int>(elements.size());

        set<T> new_set;
        for (const auto& elem : elements) {
            new_set.insert(elem + avg);
        }
        elements = new_set;
    }
};

ostream& operator<<(ostream& os, const Pair& p) {
    return os << "(" << p.first << ", " << p.second << ")";
}

int main() {
    cout << "=== task 1 ===" << endl;
    set<double> s1 = { 1.2, 3.4, 5.6, 7.8, 9.0 };
    task1_addMaxToEnd(s1);
    task1_removeInRange(s1, 4.0, 8.0);
    task1_addAverage(s1);
    for (auto x : s1) cout << x << " ";

    cout << "\n\n=== task 2 ===" << endl;
    set<Pair> s2 = { Pair(1, 1.1), Pair(2, 2.2), Pair(3, 3.3) };
    task2_addMaxToEnd(s2);
    task2_removeInRange(s2, Pair(2, 0.0), Pair(3, 4.0));
    task2_addAverage(s2);
    for (const auto& x : s2) cout << x << " ";

    cout << "\n\n=== task 3 ===" << endl;
    CustomList<double> list3;
    for (double x : {1.2, 3.4, 5.6, 7.8, 9.0}) list3.add(x);
    list3.task3_addMax();
    list3.task3_removeRange(4.0, 8.0);
    list3.task3_addAverage();
    list3.print();

    return 0;
}