/*
Базовый класс: 
ЧЕЛОВЕК (PERSON)
 - Имя (name) – string
 - Возраст (age) – int
Определить методы изменения полей.
Создать производный класс EMPLOYEE, имеющий поля:
 - Должность - string
 - Оклад - double
Определить методы изменения полей и вычисления зарплаты сотрудника по формуле:
 - Оклад + Премия (% от оклада)
*/

#include <iostream>
#include <vector>

class Person {
protected:
	std::string name;
	int age;
public:
	Person(std::string n, int a) {
		name = n;
		age = a;
	}
	~Person() {};

	void setName(std::string newName) { name = newName; }
	void setAge(int newAge) { age = newAge; }
	std::string getName() const { return name; }
	int getAge() const { return age; }

	virtual void print() const = 0;
	virtual double calculateSalary() const { return 0.0; }
};

class Employee : public Person {
	std::string profession;
	double salary;
public:
	Employee(std::string n, int a, std::string p, double s): Person(n, a) {
		profession = p;
		salary = s;
	}
	~Employee() {};

	void setProf(std::string newProf) { profession = newProf; }
	void setSal(double newSal) { salary = newSal; }

	double calculateSalary(double bonus) const {
		return salary * (1 + bonus / 100);
	}
	void print() const override {
		std::cout << getName() << " (" << getAge() << " years), prof: " << profession << ", salary with 50% bonus: " << calculateSalary(50) << std::endl;
	}
};

class Vector {
	std::vector <Person*> items;
public:
	void add(Person* item) {
		items.push_back(item);
	}

	friend std::ostream& operator<<(std::ostream& os, const Vector& v) {
		for (const auto& item : v.items) {
			item->print();
		}
		return os;
	}
};

int main() {
	Vector v;
	v.add(new Employee("ivanov ivan ivanovich", 20, "engeneer", 40000));
	v.add(new Employee("sergeev sergey sergeevich", 50, "dvornik", 10000));

	std::cout << "our workers:\n";
	std::cout << v;
	return 0;
}