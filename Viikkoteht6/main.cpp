#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Student {
private:
    string name;
    int age;

public:
    Student(string n, int a) : name(n), age(a) {}

    string getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    void printStudentInfo() const {
        cout << "Student " << name << " Age " << age << endl;
    }
};

int main() {
    int selection = 0;
    vector<Student> studentList;

    Student a("Jani", 30);
    Student b("Kari", 22);
    Student c("Jarmo", 25);
    Student d("Siiri", 23);

    studentList.push_back(a);
    studentList.push_back(b);
    studentList.push_back(c);
    studentList.push_back(d);

    do {
        cout << endl;
        cout << "Select" << endl;
        cout << "Add students = 0" << endl;
        cout << "Print all students = 1" << endl;
        cout << "Sort and print students according to Name = 2" << endl;
        cout << "Sort and print students according to Age = 3" << endl;
        cout << "Find and print student = 4" << endl;
        cin >> selection;

        switch (selection) {
        case 0: {
            string name;
            int age;
            cout << "Name the new student: ";
            cin >> name;
            cout << "New student age: ";
            cin >> age;
            studentList.push_back(Student(name, age));
            break;
        }
        case 1: {
            for (auto &student : studentList) {
                student.printStudentInfo();
            }
            break;
        }
        case 2: {
            sort(studentList.begin(), studentList.end(),
                 [](const Student &a, const Student &b) {
                     return a.getName() < b.getName();
                 });
            for (auto &student : studentList) {
                student.printStudentInfo();
            }
            break;
        }
        case 3: {
            sort(studentList.begin(), studentList.end(),
                 [](const Student &a, const Student &b) {
                     return a.getAge() < b.getAge();
                 });
            for (auto &student : studentList) {
                student.printStudentInfo();
            }
            break;
        }
        case 4: {
            string searchName;
            cout << "Which student to seach for?: ";
            cin >> searchName;

            auto it = find_if(studentList.begin(), studentList.end(),
                              [=](const Student &s) {
                                  return s.getName() == searchName;
                              });

            if (it != studentList.end()) {
                it->printStudentInfo();
            } else {
                cout << "Student not found" << endl;
            }
            break;
        }
        default:
            cout << "Wrong selection, stopping..." << endl;
            break;
        }
    } while (selection < 5);

    return 0;
}
