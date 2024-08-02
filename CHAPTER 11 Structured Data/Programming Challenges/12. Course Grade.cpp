/* Write a program that uses a structure to store the following data:

Member Name     Description
Name            Student name
Idnum           Student ID number
Tests           Pointer to an array of test scores
Average         Average test score
Grade           Course grade

The program should keep a list of test scores for a group of students. It should ask the
user how many test scores there are to be and how many students there are. It should
then dynamically allocate an array of structures. Each structure’s Tests member
should point to a dynamically allocated array that will hold the test scores.
After the arrays have been dynamically allocated, the program should ask for the ID
number and all the test scores for each student. The average test score should be cal-
culated and stored in the average member of each structure. The course grade should
be computed on the basis of the following grading scale:

Average Test Grade   Course Grade
        91–100           A
        81–90            B
        71–80            C
        61–70            D
     60 or below         F

The course grade should then be stored in the Grade member of each structure. Once
all this data is calculated, a table should be displayed on the screen listing each student’s
name, ID number, average test score, and course grade.
Input Validation: Be sure all the data for each student is entered. Do not accept negative
numbers for any test score. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <cctype>
#include <cstring>
using namespace std;

struct group {
    string name;
    int idnum;
    double* tests;
    double average;
    char grade;
};

int checker(int&, int);
double checker(double&, double);
double checker(double&, double, double);
void getData(group*, int, int);
char grader(double);
void tableHeader();
void displayStudent(const group&);

int main() {
    int NS, NT;

    cout << "Enter number of students: ";
    NS = checker(NS, 1);

    cout << "Enter number of tests: ";
    NT = checker(NT, 1);

    group* students = new group[NS];

    for(int i = 0; i < NS; i++) {
        getData(&students[i], NT, i); // huh what is this magic called & whatever [array]
    }

    for(int j = 0; j < NS; j++) {
        if(j == 0) {
            tableHeader();
        }
        displayStudent(students[j]);
    }    

    return 0;
}

int checker(int &x, int i) {

    cin >> x;
    while (x < i) {
        cout << "Enter a bigger number, bigger than " << i << " .";
        cin.clear();
        cin >> x;
    }

    return x;

}

double checker(double &x, double i) {

    cin >> x;
    while (x < i) {
        cout << "Enter a bigger number, bigger than " << i << " .";
        cin.clear();
        cin >> x;
    }

    return x;

}

double checker(double &x, double i, double j) {

    cin >> x;
    while (x < i || x > j) {
        cout << "Enter a bigger number, bigger than " << i << ", but smaller than " << j << " .";
        cin.clear();
        cin >> x;
    }

    return x;

}

void getData(group *s, int looper, int count) {
    
    double total = 0, 
           avg = 0;

    cout << "Student #" << (count + 1) << "'s name? ";
    cin.ignore();
    getline(cin, s->name);
    
    cout << s->name << "'s ID number? ";
    s->idnum = checker(s->idnum, 0);

    s->tests = new double[looper];

    for(int i = 0; i < looper; i++) {
        cout << "Enter " << s->name << "'s #" << (i + 1) << " test score: ";
        s->tests[i] = checker(s->tests[i], 0, 100);
        total += s->tests[i];
    }
    avg = total/looper;
    (*s).average = avg; // if u hate -> for some reason

    s->grade = grader(avg);

}

char grader(double marks) {

    if(marks > 90) {
        return 'A';
    }
    else if(marks > 80) {
        return 'B';
    }
    else if(marks > 70) {
        return 'C';
    }
    else if(marks > 60) {
        return 'D';
    }
    else {
        return 'F';
    }

}

void tableHeader() {
    cout << setw(20) << left << "Name"
         << setw(15) << left << "ID Number"
         << setw(20) << left << "Average Score"
         << setw(15) << left << "Course Grade" << endl;
}

void displayStudent(const group& student) {
    cout << setw(20) << left << student.name
         << setw(15) << left << student.idnum
         << setw(20) << left << student.average
         << setw(15) << left << student.grade << endl;
}

