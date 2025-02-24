#ifndef STUDENT_MANAGER_H
#define STUDENT_MANAGER_H

#include <vector>
#include "student.h"

class StudentManager {
public:
    void addStudent(int id, std::string name, std::string department);
    void showAllStudents();
    Student* searchStudent(int id);
    void deleteStudent(int id);
    void updateStudent(int id, std::string newName, std::string newDept);

private:
    std::vector<Student> students;  // List to store students
};

#endif  // STUDENT_MANAGER_H
