// department_manager.h
#ifndef DEPARTMENT_MANAGER_H
#define DEPARTMENT_MANAGER_H

#include "department.h"
#include <vector>
using namespace std;

class DepartmentManager {
private:
    vector<Department> departments;

public:
    void addDepartment(int id, string name);
    void showAllDepartments() const;
    void deleteDepartment(int id);
    void assignTeacherToDepartment(int departmentID, int teacherID);
};

#endif