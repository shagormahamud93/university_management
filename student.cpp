#include "student.h"

void Student::addStudent(int sid, string sname, string sdept) {
    id = sid;
    name = sname;
    department = sdept;
}

void Student::showStudent() {
    cout << "ID: " << id << " | Name: " << name << " | Department: " << department << endl;
}

// StudentManager Methods
void StudentManager::addStudent(int id, string name, string department) {
    Student newStudent;
    newStudent.addStudent(id, name, department);
    students.push_back(newStudent);
    cout << "✅ Student added successfully!\n";
}

void StudentManager::showAllStudents() {
    if (students.empty()) {
        cout << "❌ No students found!\n";
        return;
    }
    cout << "\n===== Student List =====\n";
    for (Student s : students) {
        s.showStudent();
    }
}

void StudentManager::searchStudent(int id) {
    for (Student s : students) {
        if (s.id == id) {
            cout << "✅ Student Found:\n";
            s.showStudent();
            return;
        }
    }
    cout << "❌ Student not found!\n";
}

void StudentManager::deleteStudent(int id) {
    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->id == id) {
            students.erase(it);
            cout << "✅ Student deleted successfully!\n";
            return;
        }
    }
    cout << "❌ Student not found!\n";
}

void StudentManager::updateStudent(int id, string newName, string newDept) {
    for (Student &s : students) {
        if (s.id == id) {
            s.name = newName;
            s.department = newDept;
            cout << "✅ Student updated successfully!\n";
            return;
        }
    }
    cout << "❌ Student not found!\n";
}
