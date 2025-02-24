
#include "teacher_manager.h"

// Add Teacher
void TeacherManager::addTeacher(int id, string name, string department) {
    teachers.push_back(Teacher(id, name, department));
    cout << "✅ Teacher Added Successfully!\n";
}

// Show All Teachers
void TeacherManager::showTeachers() {
    if (teachers.empty()) {
        cout << "⚠️ No teachers available!\n";
        return;
    }
    for (auto &t : teachers) {
        t.display();
    }
}

// Search Teacher by ID
Teacher* TeacherManager::searchTeacher(int id) {
    for (auto &t : teachers) {
        if (t.id == id) {
            return &t;
        }
    }
    return nullptr;
}

// Delete Teacher
void TeacherManager::deleteTeacher(int id) {
    for (auto it = teachers.begin(); it != teachers.end(); it++) {
        if (it->id == id) {
            teachers.erase(it);
            cout << "✅ Teacher Deleted Successfully!\n";
            return;
        }
    }
    cout << "❌ Teacher Not Found!\n";
}
