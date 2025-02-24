#ifndef COURSE_MANAGER_H
#define COURSE_MANAGER_H

#include "course.h"
#include <vector>

class CourseManager {
private:
    vector<Course> courses;

public:
    void addCourse(int id, string name, int teacherID);
    void showCourses();
    void deleteCourse(int id);
};

#endif
