#include "student.h"

void StudentManager::addStudent(int id, string name, string department) {
    students.push_back(Student(id, name, department));
    cout << "✅ Student Added Successfully!\n";
}

void StudentManager::showAllStudents() {
    if (students.empty()) {
        cout << "⚠️ No students available!\n";
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
            cout << "✅ Student Deleted Successfully!\n";
            return;
        }
    }
    cout << "❌ Student Not Found!\n";
}

void StudentManager::updateStudent(int id, string newName, string newDept) {
    Student* s = searchStudent(id);
    if (s) {
        s->name = newName;
        s->department = newDept;
        cout << "✅ Student Updated Successfully!\n";
    } else {
        cout << "❌ Student Not Found!\n";
    }
}
