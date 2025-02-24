
#ifndef TEACHER_MANAGER_H
#define TEACHER_MANAGER_H

#include "teacher.h"
#include <vector>

class TeacherManager {
private:
    vector<Teacher> teachers;

public:
    void addTeacher(int id, string name, string department);
    void showTeachers();
    Teacher* searchTeacher(int id);
    void deleteTeacher(int id);
};

#endif
