#ifndef EXAM_H
#define EXAM_H

#include <iostream>
#include <string>

using namespace std;

class Exam {
public:
    int id;
    string name;
    int courseID;
    string date;

    Exam(int id, string name, int courseID, string date) {
        this->id = id;
        this->name = name;
        this->courseID = courseID;
        this->date = date;
    }

    void display() {
        cout << "Exam ID: " << id << ", Name: " << name 
             << ", Course ID: " << courseID << ", Date: " << date << endl;
    }
};

#endif
