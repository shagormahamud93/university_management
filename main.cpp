#include <iostream>
#include "student.h"
#include "teacher_manager.h"

using namespace std;

void menu() {
    cout << "\n===== University Management System =====\n";
    cout << "1. Add Student\n";
    cout << "2. Show All Students\n";
    cout << "3. Search Student by ID\n";
    cout << "4. Delete Student by ID\n";
    cout << "5. Update Student Info\n";
    cout << "6. Add Teacher\n";
    cout << "7. Show All Teachers\n";
    cout << "8. Search Teacher by ID\n";
    cout << "9. Delete Teacher by ID\n";
    cout << "10. Exit\n";
    cout << "Choose an option: ";
}

int main() {
    StudentManager sm;
    TeacherManager tm;
    int choice, id;
    string name, department;

    while (true) {
        menu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Student ID: ";
                cin >> id;
                cout << "Enter Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Department: ";
                getline(cin, department);
                sm.addStudent(id, name, department);
                break;
            case 2:
                sm.showAllStudents();
                break;
            case 3:
                cout << "Enter Student ID to search: ";
                cin >> id;
                sm.searchStudent(id);
                break;
            case 4:
                cout << "Enter Student ID to delete: ";
                cin >> id;
                sm.deleteStudent(id);
                break;
            case 5:
                cout << "Enter Student ID to update: ";
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
                cout << "Enter Teacher ID to search: ";
                cin >> id;
                if (Teacher* t = tm.searchTeacher(id)) {
                    t->display();
                } else {
                    cout << "❌ Teacher Not Found!\n";
                }
                break;
            case 9:
                cout << "Enter Teacher ID to delete: ";
                cin >> id;
                tm.deleteTeacher(id);
                break;
            case 10:
                cout << "Exiting program...\n";
                return 0;
            default:
                cout << "❌ Invalid choice! Try again.\n";
        }
    }
}
