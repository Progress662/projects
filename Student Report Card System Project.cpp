#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Student {
public:
    int rollNo;
    string name;
    vector<int> marks;
    double average;
    char grade;

    Student(int r, string n, vector<int> m) : rollNo(r), name(n), marks(m) {
        calcAverageAndGrade();
    }

    void calcAverageAndGrade() {
        int sum = 0;
        for (int mark : marks) sum += mark;
        average = (double)sum / marks.size();
        if (average >= 90) grade = 'A';
        else if (average >= 80) grade = 'B';
        else if (average >= 70) grade = 'C';
        else if (average >= 60) grade = 'D';
        else grade = 'F';
    }
};

class StudentDatabase {
    vector<Student> students;

    int findIndexByRollNo(int rollNo) {
        for (int i = 0; i < students.size(); i++)
            if (students[i].rollNo == rollNo) return i;
        return -1;
    }

public:
    void addStudent(Student s) {
        students.push_back(s);
    }

    void removeStudent(int rollNo) {
        int idx = findIndexByRollNo(rollNo);
        if (idx != -1) students.erase(students.begin() + idx);
    }

    Student* searchStudent(int rollNo) {
        int idx = findIndexByRollNo(rollNo);
        if (idx != -1) return &students[idx];
        return nullptr;
    }

    void updateStudent(int rollNo, string name, vector<int> marks) {
        int idx = findIndexByRollNo(rollNo);
        if (idx != -1) {
            students[idx].name = name;
            students[idx].marks = marks;
            students[idx].calcAverageAndGrade();
        }
    }

    void printAll() {
        cout << "Roll No\tName\t\tAverage\tGrade\n";
        for (auto& s : students)
            cout << s.rollNo << "\t" << s.name << "\t\t" << s.average << "\t" << s.grade << endl;
    }

    void sortByAverage() {
        sort(students.begin(), students.end(), [](Student& a, Student& b) {
            return a.average > b.average;
        });
    }
};

void menu() {
    cout << "1. Add Student\n";
    cout << "2. Remove Student\n";
    cout << "3. Search Student\n";
    cout << "4. Update Student\n";
    cout << "5. Print All Students\n";
    cout << "6. Sort by Average\n";
    cout << "7. Exit\n";
    cout << "Enter option: ";
}

int main() {
    StudentDatabase db;
    while (true) {
        menu();
        int op;
        cin >> op;
        if (op == 1) {
            int rollNo, n;
            string name;
            vector<int> marks;
            cout << "Enter Roll No: ";
            cin >> rollNo;
            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter number of subjects: ";
            cin >> n;
            marks.resize(n);
            for (int i = 0; i < n; i++) {
                cout << "Mark " << i + 1 << ": ";
                cin >> marks[i];
            }
            db.addStudent(Student(rollNo, name, marks));
        }
        else if (op == 2) {
            int rollNo;
            cout << "Enter Roll No: ";
            cin >> rollNo;
            db.removeStudent(rollNo);
        }
        else if (op == 3) {
            int rollNo;
            cout << "Enter Roll No: ";
            cin >> rollNo;
            Student* s = db.searchStudent(rollNo);
            if (s)
                cout << "Name: " << s->name << ", Average: " << s->average << ", Grade: " << s->grade << endl;
            else
                cout << "Student not found\n";
        }
        else if (op == 4) {
            int rollNo,n;
            string name;
            vector<int> marks;
            cout << "Enter Roll No: ";
            cin >> rollNo;
            cout << "Enter New Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter number of subjects: ";
            cin >> n;
            marks.resize(n);
            for (int i = 0; i < n; i++) {
                cout << "Mark " << i + 1 << ": ";
                cin >> marks[i];
            }
            db.updateStudent(rollNo, name, marks);
        }
        else if (op == 5) {
            db.printAll();
        }
        else if (op == 6) {
            db.sortByAverage();
            db.printAll();
        }
        else if (op == 7) break;
        else cout << "Invalid Option\n";
    }
    return 0;
}
