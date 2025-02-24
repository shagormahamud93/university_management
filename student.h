#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <vector>

using namespace std;

class Student {
public:
    int id;
    string name, department;

    Student(int sid, string sname, string sdept) {
        id = sid;
        name = sname;
        department = sdept;
    }

    void display() {
        cout << "Student ID: " << id << " | Name: " << name 
             << " | Department: " << department << endl;
    }
};

class StudentManager {
private:
    vector<Student> students;

public:
    void addStudent(int id, string name, string department);
    void showAllStudents();
    Student* searchStudent(int id);
    void deleteStudent(int id);
    void updateStudent(int id, string newName, string newDept);
};

#endif
