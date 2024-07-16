/* Modify the grade book application in Programming Challenge 13 so it drops each stu-
dent’s lowest score when determining the test score averages and letter grades. */
//(dont u mean 12) 

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
int findLowest(int [][COLUMNS], int); // refering site + PC11 C6
char getGrade(double);

int students[ROWS][COLUMNS], total; // student count + test marks
string name[ROWS]; // student names

int main() {

    getValues(students, name);
    checkByStudents(students, name);

    return 0;
}

int checker(int &x, int i, int j) {

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
    int sum, summ, localArray[ROWS], lowest;
    localArray[0] = 0;
    char grade;

    for (int row = 0; row < ROWS; row++) {

        sum = 0;       
        for (int col = 0; col < COLUMNS; col++) {
            sum += array[row][col];
            lowest = findLowest(students, row);
        }
        sum -= lowest;
        localArray[row] = sum;
        grade = getGrade(sum);
        cout << b[row] << " has gotten a grade " << grade << " with an average test score of " << (sum/3) << endl;
        cout << "Their lowest score of " << lowest << " has been dropped." << endl << endl;
    }

}

int findLowest(int array[][COLUMNS], int w) {
    int lowest = array[w][0];

    for (int i = 1; i < COLUMNS; i++)
    {
        if (array[w][i] <= lowest)
            lowest = array[w][i];
    }

    return lowest;
}

char getGrade(double i) {

    i /= 3;

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


