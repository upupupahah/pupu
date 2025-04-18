/*
Пользовательский класс: АБИТУРИЕНТ
    ФИО абитуриента: string
    Специальность: string
    Балл ЕГЭ: int
*/

#include <iostream>

class applicant {
    std::string name;
    std::string prof;
    int marks; 

public:
    applicant(std::string Name, std::string Prof, int Marks) {
        name = Name;
        prof = Prof;
        marks = Marks;
    }
    
    ~applicant() {}

    std::string getName() { return name; }
    std::string getProf() { return prof; }
    int getMarks() { return marks; }

    void setName(std::string newName) { name = newName; }
    void setProf(std::string newProf) { prof = newProf; }
    void setMarks(int newMarks) { marks = newMarks; }
};

int main() {
    applicant A("Ivanov Ivan Ivanovich", "engineer", 130);
    std::cout << "applicant A: " << A.getName() << " ## " << A.getProf() << " ## " << A.getMarks() << std::endl << std::endl;

    A.setName("Petrov Petr Petrovich");
    A.setProf("cleaning manager");
    A.setMarks(300);

    std::cout << "new applicant A: " << A.getName() << " ## " << A.getProf() << " ## " << A.getMarks() << std::endl;

    return 0;
}