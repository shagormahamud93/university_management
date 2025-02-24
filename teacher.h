#ifndef TEACHER_H
#define TEACHER_H

#include <iostream>
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

    void display() {
        cout << "ID: " << id << " | Name: " << name << " | Department: " << department << endl;
    }
};

#endif
