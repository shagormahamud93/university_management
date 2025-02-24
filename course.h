#ifndef COURSE_H
#define COURSE_H

#include <iostream>
using namespace std;

class Course {
public:
    int id;
    string name;
    int teacherID;

    Course(int cid, string cname, int tID) {
        id = cid;
        name = cname;
        teacherID = tID;
    }

    void display() {
        cout << "Course ID: " << id << " | Name: " << name 
             << " | Assigned Teacher ID: " << teacherID << endl;
    }
};

#endif
