#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;
public:
    Person(string n = "", int a = 0) : name(n), age(a) {}
    virtual ~Person() {}
    virtual void print() const = 0;
    virtual void input() = 0;
    int getAge() const { return age; }
};

class Abiturient : public Person {
    int score;
    string specialty;
public:
    void print() const override {
        cout << name << ", " << age << " years. Score: " << score
            << ", speciality: " << specialty << endl;
    }

    void input() override {
        cout << "Name: "; cin >> name;
        cout << "Age: "; cin >> age;
        cout << "Score: "; cin >> score;
        cout << "Speciality: "; cin >> specialty;
    }
};

class Group {
protected:
    vector<Person*> items;
public:
    ~Group() {
        for (auto p : items) delete p;
    }

    void add(Person* p) { items.push_back(p); }

    void remove(int index) {
        if (index >= 0 && index < items.size()) {
            delete items[index];
            items.erase(items.begin() + index);
        }
    }

    void printAll() const {
        for (size_t i = 0; i < items.size(); ++i) {
            cout << i << ") ";
            items[i]->print();
        }
    }

    double averageAge() const {
        if (items.empty()) return 0;
        int sum = 0;
        for (auto p : items) sum += p->getAge();
        return (double)sum / items.size();
    }
};

class Dialog : public Group {
public:
    void process() {
        string cmd;
        while (true) {
            cout << "\nCommand: (m/+/-/s/z/q): ";
            cin >> cmd;

            if (cmd == "q") break;

            if (cmd == "m") {
                int size;
                cin >> size;
                for (int i = 0; i < size; i++) {
                    Person* p = new Abiturient();
                    p->input();
                    add(p);
                }
            }
            else if (cmd == "+") {
                Person* p = new Abiturient();
                p->input();
                add(p);
            }
            else if (cmd == "-") {
                int index;
                cout << "Idx for delete: ";
                cin >> index;
                remove(index);
            }
            else if (cmd == "s") {
                printAll();
            }
            else if (cmd == "z") {
                cout << "Avg age: " << averageAge() << endl;
            }
        }
    }
};

int main() {
    Dialog dlg;
    dlg.process();
    return 0;
}