#ifndef ATTENDANCE_MANAGER_H
#define ATTENDANCE_MANAGER_H

#include "attendance.h"
#include <vector>

class AttendanceManager {
private:
    vector<Attendance> records; // Store all attendance records

public:
    void markAttendance(int studentID, int courseID, string date, bool status);
    void showAttendance(int studentID);
    void showCourseAttendance(int courseID);
};

#endif
