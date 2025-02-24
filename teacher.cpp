#include "teacher.h"
#include <iostream>
using namespace std;

// Define constructor here
Teacher::Teacher(int id, const string& n, const string& sub) : teacherID(id), name(n), subject(sub) {}

// Define showDetails method here
void Teacher::showDetails() const {
    cout << "ID: " << teacherID 
         << ", Name: " << name 
         << ", Subject: " << subject << endl;
}
