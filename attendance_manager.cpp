#include "attendance_manager.h"
#include <iostream>

using namespace std;

// Mark Attendance
void AttendanceManager::markAttendance(int studentID, int courseID, string date, bool status) {
    records.push_back(Attendance(studentID, courseID, date, status));
    cout << "Attendance recorded for Student ID: " << studentID << " on " << date << endl;
}

// Show Attendance of a Specific Student
void AttendanceManager::showAttendance(int studentID) {
    cout << "\n Attendance for Student ID: " << studentID << "\n";
    cout << "----------------------------------------\n";
    
    bool found = false;
    for (const auto& record : records) {
        if (record.studentID == studentID) {
            record.display();
            found = true;
        }
    }

    if (!found) {
        cout << "No attendance records found.\n";
    }
}

//  Show Attendance for a Course
void AttendanceManager::showCourseAttendance(int courseID) {
    cout << "\n Attendance for Course ID: " << courseID << "\n";
    cout << "----------------------------------------\n";

    bool found = false;
    for (const auto& record : records) {
        if (record.courseID == courseID) {
            record.display();
            found = true;
        }
    }

    if (!found) {
        cout << "No attendance records for this course.\n";
    }
}
