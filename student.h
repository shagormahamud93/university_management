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
    vector<int> courseIDs; // To store the IDs of courses the student is enrolled in

    Student(int studentID, string studentName, string studentDepartment)
        : id(studentID), name(studentName), department(studentDepartment) {}

    void display() {
        cout << "Student ID: " << id << " | Name: " << name << " | Department: " << department << endl;
        cout << "Enrolled Courses: ";
        if (courseIDs.empty()) {
            cout << "No courses enrolled.\n";
        } else {
            for (int courseID : courseIDs) {
                cout << courseID << " ";
            }
            cout << endl;
        }
    }

    void assignCourse(int courseID) {
        courseIDs.push_back(courseID);  // Add course to the student's course list
    }
};

#endif
