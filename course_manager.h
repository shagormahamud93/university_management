#ifndef COURSE_MANAGER_H
#define COURSE_MANAGER_H

#include "course.h"
#include "student.h"
#include <vector>

class CourseManager {
private:
    vector<Course> courses;
    vector<Student*> students;  // Keep track of all students

public:
    void addCourse(int id, string name, int teacherID);
    void showCourses();
    void deleteCourse(int id);
    void assignStudentToCourse(int studentID, int courseID, vector<Student>& allStudents);
    void showStudentsInCourse(int courseID, vector<Student>& allStudents);
};

#endif
