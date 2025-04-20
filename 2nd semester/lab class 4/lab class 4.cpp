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

class Person {
	std::string name;
	int age;
public:
	Person(std::string Name, int Age) {
		name = Name;
		age = Age;
	}
	~Person() {};

	std::string getName() { return name; }
	int getAge() { return age; }

	void setName(std::string newName) { name = newName; }
	void setAge(int newAge) { age = newAge; }
};

class Employee : public Person {
	std::string position;
	double salary; // оклад
public:
	Employee(std::string Name, int Age, std::string Position, double Salary) : Person(Name, Age) {
		position = Position;
		salary = Salary;
	}
	~Employee() {};
	
	std::string getPosition() { return position; }
	double getSalary() { return salary; }

	void setPosition(std::string newPosition) { position = newPosition; }
	void setSalary(double newSalary) { salary = newSalary; }

	double calculateFullSalary() {
		return salary + salary * 0.5; // salary * 0.5 - размер премии 50% от оклада
	}
};

int main() {
	Employee a("Ivanov Ivan Ivanovich", 30, "engineer", 30000);
	std::cout << "employee a: " << a.getName() << ", age: " << a.getAge() << ", position: " << a.getPosition() << ", base salary: " << a.getSalary() << ", full salary = " << a.calculateFullSalary();
	a.setName("a a a");
	a.setAge(0);
	a.setPosition("fired");
	a.setSalary(0);
	std::cout << std::endl << std::endl << "new a: " << a.getName() << ", age: " << a.getAge() << ", position: " << a.getPosition() << ", base salary: " << a.getSalary() << ", full salary = " << a.calculateFullSalary() << std::endl;
	return 0;
}