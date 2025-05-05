#ifndef CR_MANAGER_H
#define CR_MANAGER_H

#include <vector>

// Forward declarations
class CourseManager;
class StudentManager;

struct CR {
    int studentId;
    int courseId;
};

struct CRVote {
    int studentId;
    int votes;
};

class CRManager {
private:
    std::vector<CR> crList;
    CourseManager* courseManager;
    StudentManager* studentManager;
    
public:
    CRManager(CourseManager* cm, StudentManager* sm);
    void voteForCR(CRVote votes[], int numStudents);
    int findCR(CRVote votes[], int numStudents);
    void assignCRToCourse(int courseId, int crStudentId);
    void addCR(int studentId, int courseId);
    void showAllCRs();
    void deleteCR(int courseId);
};

#endif