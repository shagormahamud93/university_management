#include "course_manager.h"

void CourseManager::addCourse(int id, string name, int teacherID) {
    courses.push_back(Course(id, name, teacherID));
    cout << "Course Added Successfully!\n";
}

void CourseManager::showCourses() {
    if (courses.empty()) {
        cout << "No courses available!\n";
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
            cout << "Course Deleted Successfully!\n";
            return;
        }
    }
    cout << "Course Not Found!\n";
}

void CourseManager::assignStudentToCourse(int studentID, int courseID, vector<Student>& allStudents) {
    for (auto &student : allStudents) {
        if (student.id == studentID) {
            student.assignCourse(courseID);  // Assign the course to the student
            cout << "Student " << student.name << " has been enrolled in Course " << courseID << "!\n";
            return;
        }
    }
    cout << "Student Not Found!\n";
}

// Show students enrolled in a specific course
void CourseManager::showStudentsInCourse(int courseID, vector<Student>& allStudents) {
    bool found = false;

    cout << "\n Students Enrolled in Course ID: " << courseID << "\n";
    cout << "----------------------------------------\n";

    for (const auto& student : allStudents) {
        for (int enrolledCourseID : student.courseIDs) {
            if (enrolledCourseID == courseID) { 
                cout << "Student ID: " << student.id << " | 🏷 Name: " << student.name << "\n";
                found = true;
                break;
            }
        }
    }

    if (!found) {
        cout << "No students enrolled in this course.\n";
    }
}

void CourseManager::removeStudentFromCourse(int studentID, int courseID, vector<Student>& students) {
    for (auto& student : students) {
        if (student.id == studentID) {
            student.removeCourse(courseID);
            return;
        }
    }
    cout << "Student Not Found!\n";
}

bool CourseManager::courseExists(int id) {
    for (const auto& course : courses) {
        if (course.id == id) {
            return true;
        }
    }
    return false;
}