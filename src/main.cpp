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
    string studentID;
    Grade grade;
};

void showMenu() {
    cout << "Welcome to the Student Registration System! Please look at all options below and select one by entering the number next to it: " << endl;
    cout << "1. Add a student" << endl;
    cout << "2. Show all students" << endl;
    cout << "3. Show count of students by grade" << endl;
    cout << "4. Exit" << endl;
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
    // Validating the student's name
    cout << "Enter the student's name (has to be at least 3 characters): ";
    cin >> newStudent.name;
    while (newStudent.name.length() < 3) {
        cout << "Enter a name with at LEAST 3 characters: ";
        cin >> newStudent.name;
    }

    cout << "Enter the student's ID (must have at least 5 numbers): ";
    cin >> newStudent.studentID;
    while (newStudent.studentID.length() < 5) {
        cout << "You must enter an ID that is at least 5 numbers long: ";
        cin >> newStudent.studentID;
    }

    // Input validation for age
    while (true) {
        cout << "Enter the student's age: ";
        cin >> newStudent.age;
        if (cin.fail() || newStudent.age <= 0) { // Checks if the input is invalid or non-positive
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // cin.ignore will ignore the invalid input
            cout << "Enter a valid positive integer." << endl;
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            break; 
        }
    }

    int gradeInput;
    // Input validation for grade
    while (true) {
        cout << "Enter the student's grade (1=A, 2=B, 3=C, 4=D, 5=F): ";
        cin >> gradeInput;
        if (cin.fail() || gradeInput < 1 || gradeInput > 5) { // Validate grade input
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Enter a number between 1 and 5." << endl;
        } else {
            break; 
        }
    }
    newStudent.grade = convertToGrade(gradeInput);

    students.push_back(newStudent);
    cout << "Student has been added.\n";
}

void studentsByGrade(const vector<Student>& students) {
    int gradeCounts[5] = {0};

    for (const auto& student : students) {
        gradeCounts[student.grade]++;
    }

    cout << "Grade counts:" << endl;
    cout << "A: " << gradeCounts[A] << endl;
    cout << "B: " << gradeCounts[B] << endl;
    cout << "C: " << gradeCounts[C] << endl;
    cout << "D: " << gradeCounts[D] << endl;
    cout << "F: " << gradeCounts[F] << endl;
}

// This function will display all students
void displayStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "There are no students to display." << endl;
        return;
    }

    cout << "Student List:\n";
    for (const auto& student : students) {
        cout << "Name: " << student.name << ", Age: " << student.age << ", ID: " << student.studentID << ", Grade: ";
        switch (student.grade) {
            case A: cout << "A"; break;
            case B: cout << "B"; break;
            case C: cout << "C"; break;
            case D: cout << "D"; break;
            case F: cout << "F"; break;
        }
        cout << endl;
    }
}

int main() {
    vector<Student> students;
    int choice;

    do {
        showMenu();
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

        switch(choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                displayStudents(students);
                break;
            case 3:
                studentsByGrade(students);
                break;
            case 4:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid option. Try again." << endl;
                break;
        }
    } while (choice != 4);

    return 0;
}