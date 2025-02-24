#include <iostream>
#include "student.h"
#include "teacher_manager.h"
#include "course_manager.h"
#include "student_manager.h"

using namespace std;

void menu()
{
    cout << "\n===== University Management System =====\n";
    cout << "1. Add Student\n";
    cout << "2. Show All Students\n";
    cout << "3. Search Student by ID\n";
    cout << "4. Delete Student\n";
    cout << "5. Update Student Info\n";
    cout << "6. Add Teacher\n";
    cout << "7. Show All Teachers\n";
    cout << "8. Delete Teacher\n";
    cout << "9. Add Course\n";
    cout << "10. Show All Courses\n";
    cout << "11. Delete Course\n";
    cout << "12. Assign Student to Course\n";  // ✅ New option for Assigning Student to Course
    cout << "13. Show Students in a Course\n";  // ✅ New option to Show Students in Course
    cout << "14. Exit\n";
    cout << "Choose an option: ";
}

int main()
{
    StudentManager sm;
    TeacherManager tm;
    CourseManager cm;

    int choice, id, teacherID, courseID, studentID;
    string name, department;

    vector<Student> allStudents;  // Store all students for easy access

    while (true)
    {
        menu();
        cin >> choice;

        switch (choice)
        {
        case 1:
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
        case 2:
            sm.showAllStudents();
            break;
        case 3:
            cout << "Enter ID to search: ";
            cin >> id;
            {
                Student *s = sm.searchStudent(id);
                if (s)
                {
                    s->display();
                }
                else
                {
                    cout << "❌ Student Not Found!\n";
                }
            }
            break;
        case 4:
            cout << "Enter ID to delete: ";
            cin >> id;
            sm.deleteStudent(id);
            break;
        case 5:
            cout << "Enter ID to update: ";
            cin >> id;
            cout << "Enter New Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter New Department: ";
            getline(cin, department);
            sm.updateStudent(id, name, department);
            break;
        case 6:
            cout << "Enter Teacher ID: ";
            cin >> id;
            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Department: ";
            getline(cin, department);
            tm.addTeacher(id, name, department);
            break;
        case 7:
            tm.showTeachers();
            break;
        case 8:
            cout << "Enter Teacher ID to delete: ";
            cin >> id;
            tm.deleteTeacher(id);
            break;
        case 9:
            cout << "Enter Course ID: ";
            cin >> id;
            cout << "Enter Course Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Teacher ID: ";
            cin >> teacherID;
            cm.addCourse(id, name, teacherID);
            break;
        case 10:
            cm.showCourses();
            break;
        case 11:
            cout << "Enter Course ID to delete: ";
            cin >> id;
            cm.deleteCourse(id);
            break;
        case 12: // Assign Student to Course
            cout << "Enter Student ID: ";
            cin >> studentID;
            cout << "Enter Course ID: ";
            cin >> courseID;
            cm.assignStudentToCourse(studentID, courseID, allStudents);
            break;
        case 13: // Show Students in a Course
            cout << "Enter Course ID to see enrolled students: ";
            cin >> courseID;
            cm.showStudentsInCourse(courseID, allStudents);
            break;
        case 14:
            return 0;
        default:
            cout << "⚠️ Invalid choice! Please try again.\n";
        }
    }
}
