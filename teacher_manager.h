#ifndef TEACHER_MANAGER_H
#define TEACHER_MANAGER_H

#include <iostream>
#include <vector>

using namespace std;

class Teacher {
public:
    int id;
    string name, department;

    Teacher(int tid, string tname, string tdept) {
        id = tid;
        name = tname;
        department = tdept;
    }
    int getId() const { return id; }
    void display() {
        cout << "Teacher ID: " << id << " | Name: " << name 
             << " | Department: " << department << endl;
    }
};

class TeacherManager {
private:
    vector<Teacher> teachers;

public:
    void addTeacher(int id, string name, string department);
    void showTeachers();
    Teacher* searchTeacher(int id);
    void deleteTeacher(int id);
    bool isTeacherExists(int teacherID) const;
};

#endif
