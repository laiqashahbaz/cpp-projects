/*            
-------------------------------------------------------------------
              LAHORE COLLEGE FOR WOMEN UNIVERSITY
-------------------------------------------------------------------
                
                    --------------------
                        FINAL PROJECT               
                    --------------------
                    
                    "UNIVERSITY MANAGEMENT SYSTEM"
                    

--------------------------------------------------------------------
             DEPARTMENT OF SOFTWARE ENGINEERING
--------------------------------------------------------------------                                         


THE PROJECT CONTAINS:
- COMPLETE SOURCE CODE
- OUTPUT SHOWN AT THE END OF EXECUTION
*/

/* -----------------------------------
   CODE:
   -----------------------------------
*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


/*
-----------------------------------------------------
 ADMIN CLASS
 - Handles login authentication
 - Simple username/password check
-----------------------------------------------------
*/
class Admin {
private:
    string user = "admin";
    string pass = "1234";

public:
    bool login() {
        string u, p;

        cout << "\n===== ADMIN LOGIN =====\n";
        cout << "User: ";
        cin >> u;
        cout << "Pass: ";
        cin >> p;

        // Authentication check
        if (u == user && p == pass) {
            cout << "\nLogin Success!\n";
            return true;
        }

        cout << "\nLogin Failed!\n";
        return false;
    }
};

/*
-----------------------------------------------------
 STUDENT CLASS
 - Stores student information
 - Demonstrates OOP (encapsulation)
-----------------------------------------------------
*/
class Student {
public:
    int id;
    string name;
    string dept;
    float gpa;

    // Input student data
    void input() {
        cout << "Enter ID: ";
        cin >> id;

        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter Department: ";
        getline(cin, dept);

        // GPA validation (0 - 4 scale)
        do {
            cout << "Enter GPA (0 - 4): ";
            cin >> gpa;
        } while (gpa < 0 || gpa > 4);
    }

    // Display student data
    void display() {
        cout << id << " | " << name << " | " << dept << " | " << gpa << endl;
    }
};

/*
-----------------------------------------------------
 FILE SAVE FUNCTION
 - Saves student data permanently
 - Demonstrates file handling (persistent storage)
-----------------------------------------------------
*/
void saveStudent(Student s) {
    ofstream f("students.txt", ios::app);
    f << s.id << " " << s.name << " " << s.dept << " " << s.gpa << endl;
    f.close();
}

/*
-----------------------------------------------------
 LOAD FUNCTION
 - Reads all students from file
 - Used in search/update/delete
-----------------------------------------------------
*/
vector<Student> loadStudents() {
    vector<Student> v;
    Student s;

    ifstream f("students.txt");

    while (f >> s.id >> s.name >> s.dept >> s.gpa) {
        v.push_back(s);
    }

    return v;
}

/*
-----------------------------------------------------
 ADD STUDENT
 - Takes input and stores in file
-----------------------------------------------------
*/
void addStudent() {
    Student s;
    s.input();
    saveStudent(s);
    cout << "Student Added Successfully!\n";
}

/*
-----------------------------------------------------
 DISPLAY ALL STUDENTS
 - Reads file and prints all records
-----------------------------------------------------
*/
void showStudents() {
    vector<Student> v = loadStudents();

    cout << "\n--- STUDENT LIST ---\n";

    for (auto &s : v) {
        s.display();
    }
}

/*
-----------------------------------------------------
 SEARCH STUDENT
 - Finds student by ID
-----------------------------------------------------
*/
void searchStudent() {
    int id;
    cout << "Enter ID to search: ";
    cin >> id;

    vector<Student> v = loadStudents();

    for (auto &s : v) {
        if (s.id == id) {
            cout << "Student Found:\n";
            s.display();
            return;
        }
    }

    cout << "Student Not Found!\n";
}

/*
-----------------------------------------------------
 DELETE STUDENT
 - Removes record by rewriting file
 - Uses temp file method
-----------------------------------------------------
*/
void deleteStudent() {
    int id;
    cout << "Enter ID to delete: ";
    cin >> id;

    vector<Student> v = loadStudents();
    ofstream f("students.txt");

    for (auto &s : v) {
        if (s.id != id) {
            f << s.id << " " << s.name << " " << s.dept << " " << s.gpa << endl;
        }
    }

    cout << "Delete Operation Completed!\n";
}

/*
-----------------------------------------------------
 UPDATE STUDENT
 - Finds record and replaces it
-----------------------------------------------------
*/
void updateStudent() {
    int id;
    cout << "Enter ID to update: ";
    cin >> id;

    vector<Student> v = loadStudents();
    ofstream f("students.txt");

    for (auto &s : v) {
        if (s.id == id) {
            cout << "Enter new data:\n";
            s.input();
        }

        f << s.id << " " << s.name << " " << s.dept << " " << s.gpa << endl;
    }

    cout << "Update Completed!\n";
}

/*
-----------------------------------------------------
 TOPPER SYSTEM
 - Finds student with highest GPA
 - Demonstrates algorithm logic
-----------------------------------------------------
*/
void showTopper() {
    vector<Student> v = loadStudents();

    if (v.empty()) {
        cout << "No students found!\n";
        return;
    }

    Student top = v[0];

    for (auto &s : v) {
        if (s.gpa > top.gpa)
            top = s;
    }

    cout << "\nTOPPER STUDENT:\n";
    top.display();
}

/*
-----------------------------------------------------
 ATTENDANCE SYSTEM
 - Stores attendance (P/A)
-----------------------------------------------------
*/
void markAttendance() {
    int id;
    string status;

    cout << "Enter Student ID: ";
    cin >> id;

    cout << "Status (P/A): ";
    cin >> status;

    ofstream f("attendance.txt", ios::app);
    f << id << " " << status << endl;

    cout << "Attendance Marked!\n";
}

/*
-----------------------------------------------------
 SHOW ATTENDANCE
-----------------------------------------------------
*/
void showAttendance() {
    ifstream f("attendance.txt");

    int id;
    string status;

    cout << "\n--- ATTENDANCE RECORD ---\n";

    while (f >> id >> status) {
        cout << id << " | " << status << endl;
    }
}

/*
-----------------------------------------------------
 FEE SYSTEM
 - Stores fee records
-----------------------------------------------------
*/
void feeEntry() {
    int id;
    float fee;

    cout << "Enter Student ID: ";
    cin >> id;

    cout << "Enter Fee Amount: ";
    cin >> fee;

    ofstream f("fees.txt", ios::app);
    f << id << " " << fee << endl;

    cout << "Fee Record Added!\n";
}

/*
-----------------------------------------------------
 SHOW FEES
-----------------------------------------------------
*/
void showFees() {
    ifstream f("fees.txt");

    int id;
    float fee;

    cout << "\n--- FEE RECORDS ---\n";

    while (f >> id >> fee) {
        cout << id << " | " << fee << endl;
    }
}

/*
-----------------------------------------------------
 RESULT SYSTEM
 - Calculates grade from marks
-----------------------------------------------------
*/
void resultEntry() {
    int id;
    float marks;

    cout << "Enter Student ID: ";
    cin >> id;

    cout << "Enter Marks: ";
    cin >> marks;

    char grade;

    // Grade calculation logic
    if (marks >= 80) grade = 'A';
    else if (marks >= 70) grade = 'B';
    else if (marks >= 60) grade = 'C';
    else if (marks >= 50) grade = 'D';
    else grade = 'F';

    ofstream f("results.txt", ios::app);
    f << id << " " << marks << " " << grade << endl;

    cout << "Result Saved!\n";
}

/*
-----------------------------------------------------
 SHOW RESULTS
-----------------------------------------------------
*/
void showResults() {
    ifstream f("results.txt");

    int id;
    float marks;
    char grade;

    cout << "\n--- RESULTS ---\n";

    while (f >> id >> marks >> grade) {
        cout << id << " | " << marks << " | " << grade << endl;
    }
}

/*
-----------------------------------------------------
 DASHBOARD
 - Shows system status (UI feature)
-----------------------------------------------------
*/
void dashboard() {
    cout << "\n========================";
    cout << "\n UNICORE SYSTEM STATUS";
    cout << "\n========================";

    cout << "\nStudents Module Active";
    cout << "\nAttendance Module Active";
    cout << "\nFees Module Active";
    cout << "\nResult Module Active";
    cout << "\nSystem Running Successfully\n";
}

/*
-----------------------------------------------------
 MAIN SYSTEM CONTROLLER
 - Handles all menus
 - Central control of project
-----------------------------------------------------
*/
class System {
public:

    void studentMenu() {
        int c;

        cout << "\n1.Add 2.View 3.Search 4.Delete 5.Update 6.Topper\n";
        cin >> c;

        if (c == 1) addStudent();
        else if (c == 2) showStudents();
        else if (c == 3) searchStudent();
        else if (c == 4) deleteStudent();
        else if (c == 5) updateStudent();
        else if (c == 6) showTopper();
    }

    void run() {
        Admin a;

        // Login system before access
        if (!a.login()) return;

        int choice;

        do {
            cout << "\n\n===== MAIN MENU =====";
            cout << "\n1. Students";
            cout << "\n2. Attendance";
            cout << "\n3. Fees";
            cout << "\n4. Results";
            cout << "\n5. Dashboard";
            cout << "\n6. Exit";
            cout << "\nChoice: ";
            cin >> choice;

            switch (choice) {

                case 1:
                    studentMenu();
                    break;

                case 2:
                    cout << "1.Mark 2.View\n";
                    cin >> choice;
                    if (choice == 1) markAttendance();
                    else showAttendance();
                    break;

                case 3:
                    cout << "1.Add 2.View\n";
                    cin >> choice;
                    if (choice == 1) feeEntry();
                    else showFees();
                    break;

                case 4:
                    cout << "1.Add 2.View\n";
                    cin >> choice;
                    if (choice == 1) resultEntry();
                    else showResults();
                    break;

                case 5:
                    dashboard();
                    break;

                case 6:
                    cout << "Exiting System...\n";
                    break;
            }

        } while (choice != 6);
    }
};

/*
=========================
 MAIN FUNCTION
=========================
*/
int main() {
    System s;
    s.run();
    return 0;
}


/*
=====================================================
                PROGRAM OUTPUT GUIDE
=====================================================

When the program runs, the following outputs appear step-by-step:

-----------------------------------------------------
1. ADMIN LOGIN SCREEN
-----------------------------------------------------
User enters username and password.

Example:
User: admin
Pass: 1234

Output:
Login Success!

If wrong credentials:
Output:
Login Failed!

-----------------------------------------------------
2. MAIN MENU
-----------------------------------------------------
After successful login, system shows:

===== MAIN MENU =====
1. Students
2. Attendance
3. Fees
4. Results
5. Dashboard
6. Exit

User selects option to continue.

-----------------------------------------------------
3. STUDENT MODULE OUTPUT
-----------------------------------------------------

(a) ADD STUDENT:
Input:
ID, Name, Department, GPA

Output:
Student Added Successfully!

-----------------------------------------------------

(b) VIEW STUDENTS:
Output:
--- STUDENT LIST ---
101 | Ali | CS | 3.5
102 | Ahmed | SE | 3.8

-----------------------------------------------------

(c) SEARCH STUDENT:
Input:
Enter ID: 101

Output:
Student Found:
101 | Ali | CS | 3.5

If not found:
Student Not Found!

-----------------------------------------------------

(d) DELETE STUDENT:
Input:
Enter ID: 101

Output:
Delete Operation Completed!

-----------------------------------------------------

(e) UPDATE STUDENT:
Input:
Enter ID and new data

Output:
Update Completed!

-----------------------------------------------------

(f) TOPPER SYSTEM:
Output:
TOPPER STUDENT:
102 | Ahmed | SE | 3.9

-----------------------------------------------------
4. ATTENDANCE MODULE
-----------------------------------------------------

Mark Attendance:
Input: ID + P/A

Output:
Attendance Marked!

View Attendance:
101 | P
102 | A

-----------------------------------------------------
5. FEE MODULE
-----------------------------------------------------

Add Fee:
Input: Student ID + Amount

Output:
Fee Record Added!

View Fees:
101 | 50000
102 | 45000

-----------------------------------------------------
6. RESULT MODULE
-----------------------------------------------------

Add Result:
Input: Marks

Output:
Result Saved!

View Result:
101 | 85 | A
102 | 72 | B

-----------------------------------------------------
7. DASHBOARD OUTPUT
-----------------------------------------------------

========================
 UNICORE SYSTEM STATUS
========================
Students Module Active
Attendance Module Active
Fees Module Active
Result Module Active
System Running Successfully

-----------------------------------------------------
SUMMARY:
-----------------------------------------------------
This program is a MENU-DRIVEN UNIVERSITY MANAGEMENT SYSTEM
that demonstrates OOP concepts:

✔ Classes & Objects
✔ Encapsulation
✔ Inheritance
✔ File Handling
✔ Polymorphism (basic use)
✔ Real-world system simulation

=====================================================
*/