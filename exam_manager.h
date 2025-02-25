#ifndef EXAM_MANAGER_H
#define EXAM_MANAGER_H

#include <vector>
#include "exam.h"

class ExamManager {
private:
    vector<Exam> exams;

public:
    void addExam(int id, string name, int courseID, string date);
    void showAllExams();
    void deleteExam(int id);
};

#endif
