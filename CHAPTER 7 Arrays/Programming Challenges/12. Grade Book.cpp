/* A teacher has five students who have taken four tests. The teacher uses the following
grading scale to assign a letter grade to a student, based on the average of his or her
four test scores.
Test Score Letter Grade
90–100     A
80–89      B
70–79      C
60–69      D
0–59       F
Write a program that uses an array of string objects to hold the five student names,
an array of five characters to hold the five students’ letter grades, and five arrays of
four doubles to hold each student’s set of test scores.
The program should allow the user to enter each student’s name and his or her four
test scores. It should then calculate and display each student’s average test score and a
letter grade based on the average.
Input Validation: Do not accept test scores less than 0 or greater than 100. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

const int ROWS = 5, // stud
          COLUMNS = 4; // test

int checker(int&, int, int);
void getValues(int[][COLUMNS], string[]);
void checkByStudents(int[][COLUMNS], string[]); // refer checkByRow PC8 C7
char getGrade(double);

int main() {

    int students[ROWS][COLUMNS], total; // student count + test marks
    string name[ROWS]; // student names

    getValues(students, name);
    checkByStudents(students, name);

    return 0;
}

int checker(int &x, int i, int j) {

    char owo;

    cin >> x;
    while (x < i || x > j) {
        cout << "Enter a bigger number, bigger than " << i << ", but smaller than " << j << " .";
        cin.clear();
        cin >> x;
    }

    return x;

}

void getValues(int array[][COLUMNS], string b[]) {

    for(int row = 0; row < ROWS; row++) {

        cout << "Enter name for student #" << (row + 1) << ": ";
        cin >> b[row];

        for(int col = 0; col < COLUMNS; col++) {

            cout << "Enter marks for " << b[row] <<  "'s test #" << (col + 1) << " here. ";
            array[row][col] = checker(array[row][col], 0, 100);

        }
    }

}

void checkByStudents(int array[][COLUMNS], string b[]) {

    int test = 0;
    int sum, localArray[ROWS];
    localArray[0] = 0;
    char grade;

    for (int row = 0; row < ROWS; row++) {

        sum = 0;       
        for (int col = 0; col < COLUMNS; col++) {
            sum += array[row][col];
        }
        localArray[row] = sum;
        grade = getGrade(sum);
        cout << b[row] << " has gotten a grade " << grade << " with an average test score of " << (sum/COLUMNS) << endl;
    }

}

char getGrade(double i) {

    i /= COLUMNS;

    char owo;

    if (i >= 90) {
        owo = 'A';
    }
    else if (i >= 80) {
        owo = 'B';
    }
    else if (i >= 70) {
        owo = 'C';
    }
    else if (i >= 60) {
        owo = 'D';
    }
    else {
        owo = 'F';
    }
    
    return owo;
}


