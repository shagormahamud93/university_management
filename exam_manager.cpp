#include "exam_manager.h"
#include <iostream>

using namespace std;

void ExamManager::addExam(int id, string name, int courseID, string date) {
    exams.push_back(Exam(id, name, courseID, date));
    cout << "Exam added successfully!\n";
}

void ExamManager::showAllExams() {
    if (exams.empty()) {
        cout << "No exams available.\n";
        return;
    }
    cout << "===== Exam List =====\n";
    for (Exam &e : exams) {
        e.display();
    }
}

void ExamManager::deleteExam(int id) {
    for (auto it = exams.begin(); it != exams.end(); ++it) {
        if (it->id == id) {
            exams.erase(it);
            cout << "Exam deleted successfully!\n";
            return;
        }
    }
    cout << "Exam not found!\n";
}
