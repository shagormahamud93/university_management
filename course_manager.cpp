#include "course_manager.h"

void CourseManager::addCourse(int id, string name, int teacherID) {
    courses.push_back(Course(id, name, teacherID));
    cout << "✅ Course Added Successfully!\n";
}

void CourseManager::showCourses() {
    if (courses.empty()) {
        cout << "⚠️ No courses available!\n";
        return;
    }
    for (auto &c : courses) {
        c.display();
    }
}

void CourseManager::deleteCourse(int id) {
    for (auto it = courses.begin(); it != courses.end(); it++) {
        if (it->id == id) {
            courses.erase(it);
            cout << "✅ Course Deleted Successfully!\n";
            return;
        }
    }
    cout << "❌ Course Not Found!\n";
}
