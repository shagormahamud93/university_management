#ifndef ATTENDANCE_H
#define ATTENDANCE_H

#include <iostream>
#include <string>

using namespace std;

class Attendance {
public:
    int studentID;
    int courseID;
    string date;
    bool isPresent; // true = Present, false = Absent

    Attendance(int sID, int cID, string d, bool status)
        : studentID(sID), courseID(cID), date(d), isPresent(status) {}

    void display() const {  // Marked as const 
        cout << "Date: " << date << " | Student ID: " << studentID
             << " |  Course ID: " << courseID
             << " | Status: " << (isPresent ? "Present" : "Absent") << endl;
    }
};

#endif
