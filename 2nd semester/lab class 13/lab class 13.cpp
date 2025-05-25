#include <iostream>
#include <deque>
#include <stack>
#include <set>
#include <algorithm>
#include <numeric>

using namespace std;

struct Pair {
    int f;
    int s;

    Pair(int first = 0, int second = 0) : f(first), s(second) {}

    bool operator<(const Pair& other) const { return (f + s) < (other.f + other.s); }
    bool operator==(const Pair& other) const { return f == other.f && s == other.s; }
};

ostream& operator<<(ostream& os, const Pair& p) {
    return os << "(" << p.f << ", " << p.s << ")";
}

void task1() {
    cout << "=== task1 ===" << endl;
    deque<Pair> dq;

    dq.emplace_back(1, 2);
    dq.emplace_back(3, 1);
    dq.emplace_back(2, 3);
    dq.emplace_back(0, 4);
    cout << "original deque: ";
    for_each(dq.begin(), dq.end(), [](const Pair& p) { cout << p << " "; });
    cout << endl;

    replace_if(dq.begin(), dq.end(),
        [](const Pair& p) { return p.f + p.s == 4; }, Pair(5, 0));
    cout << "after replace: ";
    for_each(dq.begin(), dq.end(), [](const Pair& p) { cout << p << " "; });
    cout << endl;

    dq.erase(remove_if(dq.begin(), dq.end(),
        [](const Pair& p) { return p.f + p.s == 5; }), dq.end());
    cout << "after remove: ";
    for_each(dq.begin(), dq.end(), [](const Pair& p) { cout << p << " "; });
    cout << endl;

    sort(dq.begin(), dq.end());
    cout << "sorted: ";
    for_each(dq.begin(), dq.end(), [](const Pair& p) { cout << p << " "; });
    cout << endl;

    sort(dq.rbegin(), dq.rend());
    cout << "sorted 2: ";
    for_each(dq.begin(), dq.end(), [](const Pair& p) { cout << p << " "; });
    cout << endl;

    auto max_it = max_element(dq.begin(), dq.end());
    if (max_it != dq.end()) {
        dq.push_back(*max_it);
        cout << "after adding max: ";
        for_each(dq.begin(), dq.end(), [](const Pair& p) { cout << p << " "; });
        cout << endl;
    }
}

void task2() {
    cout << "\n=== task2 ===" << endl;
    stack<Pair> st;
    st.push(Pair(2, 3));
    st.push(Pair(1, 1));
    st.push(Pair(4, 0));
    st.push(Pair(0, 5));

    deque<Pair> temp;
    while (!st.empty()) {
        temp.push_back(st.top());
        st.pop();
    }

    temp.erase(remove_if(temp.begin(), temp.end(),
        [](const Pair& p) { return (p.f + p.s) >= 3 && (p.f + p.s) <= 6; }), temp.end());

    for (const auto& p : temp) st.push(p);

    cout << "stack after remove: ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

void task3() {
    cout << "\n=== task3 ===" << endl;
    set<Pair> s;
    s.insert(Pair(1, 2));
    s.insert(Pair(3, 3));
    s.insert(Pair(0, 4));
    s.insert(Pair(2, 1));

    auto low = s.lower_bound(Pair(3, 0));
    auto high = s.upper_bound(Pair(5, 0));
    s.erase(low, high);

    cout << "set after erase: ";
    for_each(s.begin(), s.end(), [](const Pair& p) { cout << p << " "; });
    cout << endl;

    double avg = accumulate(s.begin(), s.end(), 0.0,
        [](double acc, const Pair& p) { return acc + p.f + p.s; }) / s.size();

    set<Pair> new_s;
    for (const auto& p : s) {
        new_s.insert(Pair(p.f + avg, p.s + avg));
    }

    cout << "set with average added: ";
    for_each(new_s.begin(), new_s.end(), [](const Pair& p) { cout << p << " "; });
    cout << endl;
}

int main() {
    task1();
    task2();
    task3();
    return 0;
}