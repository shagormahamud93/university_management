#include <iostream>
#include "cr_manager.h"
#include "course_manager.h"  
#include "student_manager.h"

using namespace std;

CRManager::CRManager(CourseManager* cm, StudentManager* sm) 
    : courseManager(cm), studentManager(sm) {}

void CRManager::voteForCR(CRVote votes[], int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        cout << "Enter student ID for student " << i + 1 << ": ";
        cin >> votes[i].studentId;
        cout << "Enter number of votes received: ";
        cin >> votes[i].votes;
    }
}

int CRManager::findCR(CRVote votes[], int numStudents) {
    int maxVotes = -1;
    int crId = -1;
    for (int i = 0; i < numStudents; i++) {
        if (votes[i].votes > maxVotes) {
            maxVotes = votes[i].votes;
            crId = votes[i].studentId;
        }
    }
    return crId;
}

void CRManager::assignCRToCourse(int courseId, int crStudentId) {
    addCR(crStudentId, courseId);
}

void CRManager::addCR(int studentId, int courseId) {
    if (!courseManager->courseExists(courseId)) {
        cout << "Error: Course ID " << courseId << " does not exist. Please create the course first." << endl;
        return;
    }

    if (!studentManager->studentExists(studentId)) {
        cout << "Error: Student ID " << studentId << " does not exist. Please create the student first." << endl;
        return;
    }

    CR newCR;
    newCR.studentId = studentId;
    newCR.courseId = courseId;
    crList.push_back(newCR);
    cout << "CR added successfully." << endl;
}
void CRManager::showAllCRs() {
    if (crList.empty()) {
        cout << "No CRs assigned yet." << endl;
        return;
    }

    cout << "\nAll Course CRs:" << endl;
    for (const auto& cr : crList) {
        cout << "Course ID: " << cr.courseId << " | Student ID (CR): " << cr.studentId << endl;
    }
}

void CRManager::deleteCR(int courseId) {
    bool found = false;
    for (auto it = crList.begin(); it != crList.end(); ) {
        if (it->courseId == courseId) {
            it = crList.erase(it);
            found = true;
            cout << "CR for course " << courseId << " deleted." << endl;
        } else {
            ++it;
        }
    }
    if (!found) {
        cout << "No CR found for course " << courseId << endl;
    }
}