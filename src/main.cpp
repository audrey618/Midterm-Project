#include <iostream>
#include <vector>
#include <limits> 
using namespace std;

enum Grade {
    A, B, C, D, F
};

struct Student {
    string name;
    int age;
    Grade grade;
};

void displayMenu() {
    cout << "1. Add a student" << endl;
    cout << "2. Show all students" << endl;
    cout << "3. Show count of students by grade" << endl;
    cout << "4. Exit" << endl;
    cout << "Select an option: ";
}

Grade convertToGrade(int gradeInput) {
    switch(gradeInput) {
        case 1: return A;
        case 2: return B;
        case 3: return C;
        case 4: return D;
        case 5: return F;
        default: return F; 
    }
}

// This function adds a student to the system with input validation
void addStudent(vector<Student>& students) {
    Student newStudent;

    cout << "Enter the student's name: ";
    cin >> newStudent.name;

    // Input validation for age
    while (true) {
        cout << "Enter the student's age: ";
        cin >> newStudent.age;
        if (cin.fail() || newStudent.age <= 0) { // Checks if the input is invalid or non-positive
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // cin.ignore will ignore the invalid input
            cout << "Enter a valid positive integer." << endl;
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discards any extra input
            break; 
        }
    }

    int gradeInput;
    // Input validation for grade
    while (true) {
        cout << "Enter the student's grade (1=A, 2=B, 3=C, 4=D, 5=F): ";
        cin >> gradeInput;
        if (cin.fail() || gradeInput < 1 || gradeInput > 5) { // Validate grade input
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            cout << "Enter a number between 1 and 5." << endl;
        } else {
            break; 
        }
    }
    newStudent.grade = convertToGrade(gradeInput);

    students.push_back(newStudent);
    cout << "Student successfully added.\n";
}