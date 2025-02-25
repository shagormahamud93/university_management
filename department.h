// department.h
#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <iostream>
#include <vector>
using namespace std;

class Department {
private:
    int id;
    string name;
    vector<int> teacherIDs; // List of assigned teacher IDs

public:
    Department(int id, string name);
    int getId() const;
    string getName() const;
    void addTeacher(int teacherID);
    void showTeachers() const;
    void display() const;
};

#endif
