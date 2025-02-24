#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <vector>

using namespace std;

class Student {
public:
    int id;
    string name;
    string department;

    void addStudent(int sid, string sname, string sdept);
    void showStudent();
};

class StudentManager {
private:
    vector<Student> students;
public:
    void addStudent(int id, string name, string department);
    void showAllStudents();
    void searchStudent(int id);
    void deleteStudent(int id);
    void updateStudent(int id, string newName, string newDept);
};

#endif
