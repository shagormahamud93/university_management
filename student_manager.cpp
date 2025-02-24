#include "student_manager.h"
#include <iostream>

void StudentManager::addStudent(int id, std::string name, std::string department) {
    students.push_back(Student(id, name, department));
    std::cout << "✅ Student Added Successfully!\n";
}

void StudentManager::showAllStudents() {
    if (students.empty()) {
        std::cout << "⚠️ No students available!\n";
        return;
    }
    for (auto &s : students) {
        s.display();
    }
}

Student* StudentManager::searchStudent(int id) {
    for (auto &s : students) {
        if (s.id == id) {
            return &s;
        }
    }
    return nullptr;
}

void StudentManager::deleteStudent(int id) {
    for (auto it = students.begin(); it != students.end(); it++) {
        if (it->id == id) {
            students.erase(it);
            std::cout << "✅ Student Deleted Successfully!\n";
            return;
        }
    }
    std::cout << "❌ Student Not Found!\n";
}

void StudentManager::updateStudent(int id, std::string newName, std::string newDept) {
    Student* s = searchStudent(id);
    if (s) {
        s->name = newName;
        s->department = newDept;
        std::cout << "✅ Student Updated Successfully!\n";
    } else {
        std::cout << "❌ Student Not Found!\n";
    }
}
