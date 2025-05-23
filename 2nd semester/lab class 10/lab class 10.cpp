#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Pair {
    int first;
    double second;
public:
    Pair(int f = 0, double s = 0.0) : first(f), second(s) {}

    bool operator<(const Pair& other) const {
        return (first < other.first) || (first == other.first && second < other.second);
    }
    bool operator>(const Pair& other) const {
        return (first > other.first) || (first == other.first && second > other.second);
    }

    Pair& operator--() {
        --first;
        return *this;
    }

    Pair operator--(int) {
        Pair temp = *this;
        --second;
        return temp;
    }

    bool operator==(const Pair& other) const {
        return first == other.first && second == other.second;
    }

    friend ostream& operator<<(ostream& os, const Pair& p) {
        os << p.first << ":" << p.second;
        return os;
    }

    friend istream& operator>>(istream& is, Pair& p) {
        is >> p.first >> p.second;
        return is;
    }
};

vector<Pair> readFile(const string& filename) {
    ifstream file(filename);
    vector<Pair> data;
    Pair p;
    while (file >> p) data.push_back(p);
    return data;
}

void writeFile(const string& filename, const vector<Pair>& data) {
    ofstream file(filename);
    for (const auto& p : data) file << p << endl;
}

void deletePairs(vector<Pair>& data, const Pair& target) {
    data.erase(remove(data.begin(), data.end(), target), data.end());
}

void decreasePairs(vector<Pair>& data, const Pair& target, int L) {
    for (auto& p : data) {
        if (p == target) {
            --p;
            Pair temp = p--;
        }
    }
}

void insertPairs(vector<Pair>& data, const Pair& target, int K) {
    auto it = find(data.begin(), data.end(), target);
    if (it != data.end()) {
        vector<Pair> newPairs(K);
        for (auto& p : newPairs) {
            cout << "Enter new pair (int double): ";
            cin >> p;
        }
        data.insert(it + 1, newPairs.begin(), newPairs.end());
    }
}

int main() {
    string filename = "data.txt";
    vector<Pair> data;
    int choice;

    do {
        cout << "\nMenu:\n1. Input data\n2. Show data\n3. Delete pairs\n4. Decrease pairs\n5. Insert pairs\n0. Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            int n;
            cout << "Enter number of pairs: ";
            cin >> n;
            data.clear();
            Pair p;
            for (int i = 0; i < n; ++i) {
                cout << "Pair " << i + 1 << ": ";
                cin >> p;
                data.push_back(p);
            }
            writeFile(filename, data);
        }
        else if (choice == 2) {
            data = readFile(filename);
            for (const auto& p : data) cout << p << endl;
        }
        else if (choice == 3) {
            Pair target;
            cout << "Enter pair to delete (int double): ";
            cin >> target;
            deletePairs(data, target);
            writeFile(filename, data);
        }
        else if (choice == 4) {
            Pair target;
            int L;
            cout << "Enter target pair (int double): ";
            cin >> target;
            cout << "Enter L: ";
            cin >> L;
            decreasePairs(data, target, L);
            writeFile(filename, data);
        }
        else if (choice == 5) {
            Pair target;
            int K;
            cout << "Enter target pair (int double): ";
            cin >> target;
            cout << "Enter K: ";
            cin >> K;
            insertPairs(data, target, K);
            writeFile(filename, data);
        }
    } while (choice != 0);

    return 0;
}