// department_manager.cpp
#include "department_manager.h"

Department::Department(int id, string name) : id(id), name(name) {}

int Department::getId() const { return id; }
string Department::getName() const { return name; }

void Department::addTeacher(int teacherID) {
    teacherIDs.push_back(teacherID);
}

void Department::showTeachers() const {
    cout << "Teachers in " << name << ": ";
    for (int teacherID : teacherIDs) {
        cout << teacherID << " ";
    }
    cout << endl;
}

void Department::display() const {
    cout << "Department ID: " << id << " Name: " << name << endl;
}

void DepartmentManager::addDepartment(int id, string name) {
    departments.push_back(Department(id, name));
}

void DepartmentManager::showAllDepartments() const {
    for (const auto& dept : departments) {
        dept.display();
    }
}

void DepartmentManager::deleteDepartment(int id) {
    for (auto it = departments.begin(); it != departments.end(); ++it) {
        if (it->getId() == id) {
            departments.erase(it);
            cout << "Department deleted successfully." << endl;
            return;
        }
    }
    cout << "Department not found!" << endl;
}

void DepartmentManager::assignTeacherToDepartment(int departmentID, int teacherID) {
    for (auto& dept : departments) {
        if (dept.getId() == departmentID) {
            dept.addTeacher(teacherID);
            cout << "Teacher assigned successfully!" << endl;
            return;
        }
    }
    cout << "Department not found!" << endl;
}

bool DepartmentManager::isDepartmentExists(const string& name) const {
    for (const auto& dept : departments) {
        if (dept.getName() == name) {
            return true;
        }
    }
    return false;
}

bool DepartmentManager::isDepartmentExists() const {
    return !departments.empty();
}