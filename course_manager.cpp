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

void CourseManager::assignStudentToCourse(int studentID, int courseID, vector<Student>& allStudents) {
    for (auto &student : allStudents) {
        if (student.id == studentID) {
            student.assignCourse(courseID);  // Assign the course to the student
            cout << "✅ Student " << student.name << " has been enrolled in Course " << courseID << "!\n";
            return;
        }
    }
    cout << "❌ Student Not Found!\n";
}

void CourseManager::showStudentsInCourse(int courseID, vector<Student>& allStudents) {
    bool found = false;
    for (auto &student : allStudents) {
        for (int course : student.courseIDs) {
            if (course == courseID) {
                cout << "Student ID: " << student.id << " | Name: " << student.name << endl;
                found = true;
                break;
            }
        }
    }
    if (!found) {
        cout << "❌ No students are enrolled in this course.\n";
    }
}
