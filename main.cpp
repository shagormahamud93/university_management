#include <iostream>
#include "student.h"
#include "teacher_manager.h"
#include "course_manager.h"
#include "student_manager.h"
#include "attendance_manager.h"
#include "department_manager.h"
#include "exam_manager.h"
#include "exam.h"
#include "cr_manager.h"

using namespace std;

void menu()
{

    cout << "\n===== University Management System =====\n";
    cout << "\n===== Department Management =====\n";
    cout << " 1. Add Department\n";
    cout << " 2. Show All Departments\n";
    cout << " 3. Delete Department\n";
    
    cout << "\n===== Teacher Management =====\n";
    cout << "4. Add Teacher\n";
    cout << "5. Show All Teachers\n";
    cout << "6. Delete Teacher\n";
    
    cout << "\n===== Student Management =====\n";
    cout << " 7. Add Student\n";
    cout << "8. Show All Students\n";
    cout << "9. Search Student by ID\n";
    cout << "10. Update Student Info\n";
    cout << "11. Delete Student\n";
    
    cout << "\n===== Course Management =====\n";
    cout << "12. Add Course\n";
    cout << "13. Show All Courses\n";
    cout << "14. Delete Course\n";
    
    cout << "\n===== Enrollment =====\n";
    cout << "15. Assign Student to Course\n";
    cout << "16. Show Students in a Course\n";
    cout << "17. Remove Student from Course\n";
    
    cout << "\n===== Attendance Management =====\n";
    cout << "18. Mark Attendance\n";
    cout << "19. Show Attendance for Student\n";
    cout << "20. Show Attendance for Course\n";
    
    cout << "\n===== Exam Management =====\n";
    cout << "21. Add Exam\n";
    cout << "22. Show All Exams\n";
    cout << "23. Delete Exam\n";
    
    cout << "\n===== CR Management =====\n";
    cout << "24. Conduct CR Vote\n";
    cout << "25. Manually Assign CR\n";
    cout << "26. Show All CRs\n";
    cout << "27. Delete CR\n";
    
    cout << "\n0. Exit\n";
    cout << "Choose an option: ";

}

int main()
{
    StudentManager sm;
    TeacherManager tm;
    CourseManager cm;
    AttendanceManager am;
    DepartmentManager dm;
    ExamManager em;
    CRManager crManager(&cm, &sm);
    int choice, id, teacherID, courseID, studentID;
    string name, department, date;
    bool status;

    vector<Student> allStudents;

    while (true)
    {
        menu();
        cin >> choice;

        switch (choice)
        {

         case 1: // Add Department
            cout << "Enter Department ID: ";
            cin >> id;
            cout << "Enter Department Name: ";
            cin.ignore();
            getline(cin, name);
            dm.addDepartment(id, name);
            break;

        case 2: // Show All Departments
            dm.showAllDepartments();
            break;

        case 3: // Delete Department
            cout << "Enter Department ID to delete: ";
            cin >> id;
            dm.deleteDepartment(id);
            break;

        //Teacher manage
         case 4:
            cout << "Enter Teacher ID: ";
            cin >> id;
            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Department: ";
            getline(cin, department);
            tm.addTeacher(id, name, department);
            break;
        case 5:
            tm.showTeachers();
            break;
        case 6:
            cout << "Enter Teacher ID to delete: ";
            cin >> id;
            tm.deleteTeacher(id);
            break;
       //Teacher Manage End

         //Student Manage 
        case 7:
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Department: ";
            getline(cin, department);
            sm.addStudent(id, name, department);
            allStudents.push_back(Student(id, name, department));
            break;
        case 8:
            sm.showAllStudents();
            break;
        case 9:
            cout << "Enter ID to search: ";
            cin >> id;
            {
                Student *s = sm.searchStudent(id);
                if (s)
                    s->display();
                else
                    cout << "Student Not Found!\n";
            }
            break;
        case 10:
            cout << "Enter ID to delete: ";
            cin >> id;
            sm.deleteStudent(id);
            break;
        case 11:
            cout << "Enter ID to update: ";
            cin >> id;
            cout << "Enter New Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter New Department: ";
            getline(cin, department);
            sm.updateStudent(id, name, department);
            break;
        //Student Manage End

        //Course Manage 
        case 12:
            cout << "Enter Course ID: ";
            cin >> id;
            cout << "Enter Course Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Teacher ID: ";
            cin >> teacherID;
            cm.addCourse(id, name, teacherID);
            break;
        case 13:
            cm.showCourses();
            break;
        case 14:
            cout << "Enter Course ID to delete: ";
            cin >> id;
            cm.deleteCourse(id);
            break;
        //Course Manage End

        //Student Enrollment
        case 15: // Assign Student to Course
            cout << "Enter Student ID: ";
            cin >> studentID;
            cout << "Enter Course ID: ";
            cin >> courseID;
            cm.assignStudentToCourse(studentID, courseID, allStudents);
            break;
        case 16: // Show Students in a Course
            cout << "Enter Course ID: ";
            cin >> courseID;
            cm.showStudentsInCourse(courseID, allStudents);
            break;
        case 17:
            cout << "Enter Student ID: ";
            cin >> studentID;
            cout << "Enter Course ID: ";
            cin >> courseID;
            cm.removeStudentFromCourse(studentID, courseID, allStudents);
            break;
       //Student Enrollment End

        //  Attendance Feature
        case 18: // Mark Attendance
            cout << "Enter Student ID: ";
            cin >> studentID;
            cout << "Enter Course ID: ";
            cin >> courseID;
            cout << "Enter Date (YYYY-MM-DD): ";
            cin >> date;
            cout << "Enter Status (1 for Present, 0 for Absent): ";
            cin >> status;
            am.markAttendance(studentID, courseID, date, status);
            break;
        case 19: // Show Student Attendance
            cout << "Enter Student ID: ";
            cin >> studentID;
            am.showAttendance(studentID);
            break;
        case 20: // Show Course Attendance
            cout << "Enter Course ID: ";
            cin >> courseID;
            am.showCourseAttendance(courseID);
            break;
         //  Attendance Feature End

         //  Exam Management
        case 21: // Add Exam
            cout << "Enter Exam ID: ";
            cin >> id;
            cout << "Enter Exam Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Course ID: ";
            cin >> courseID;
            cout << "Enter Exam Date (YYYY-MM-DD): ";
            cin >> date;
            em.addExam(id, name, courseID, date);
            break;

        case 22: // Show All Exams
            em.showAllExams();
            break;

        case 23: // Delete Exam
            cout << "Enter Exam ID to delete: ";
            cin >> id;
            em.deleteExam(id);
            break;
       //  Exam Management

        // CR Management
        case 24: // Conduct CR Vote
        {
            int total;
            cout << "Enter Course ID for CR election: ";
            cin >> courseID;
            cout << "How many students are enrolled in this course? ";
            cin >> total;
            if (total <= 0) {
                cout << "Invalid number of students." << endl;
                break;
            }
            CRVote* votes = new CRVote[total];
            crManager.voteForCR(votes, total);
            int crId = crManager.findCR(votes, total);
            if (crId != -1) {
                crManager.assignCRToCourse(courseID, crId);
                cout << "Student " << crId << " elected as CR for course " << courseID << endl;
            } else {
                cout << "CR election failed." << endl;
            }
            delete[] votes;
            break;
        }
        case 25: // Manual CR assign
            cout << "Enter Student ID to make CR: ";
            cin >> studentID;
            cout << "Enter Course ID: ";
            cin >> courseID;
            crManager.addCR(studentID, courseID);
            break;
        case 26:
            crManager.showAllCRs();
            break;
        case 27:
            cout << "Enter Course ID to remove CR: ";
            cin >> courseID;
            crManager.deleteCR(courseID);
            break;

        case 0:
            cout << "Exiting system...\n";
            return 0;
        
            default:
             cout << "Invalid choice! Please try again.\n";
    }
}
return 0;
}