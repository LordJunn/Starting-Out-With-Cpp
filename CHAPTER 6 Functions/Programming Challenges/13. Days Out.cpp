/* Write a program that calculates the average number of days a company’s employees
are absent. The program should have the following functions:
• A function called by main that asks the user for the number of employees in
the company. This value should be returned as an int. (The function accepts no
arguments.)
• A function called by main that accepts one argument: the number of employees in
the company. The function should ask the user to enter the number of days each
employee missed during the past year. The total of these days should be returned as
an int.
• A function called by main that takes two arguments: the number of employees in
the company and the total number of days absent for all employees during the year.
The function should return, as a double, the average number of days absent. (This
function does not perform screen output and does not ask the user for input.)

Input Validation: Do not accept a number less than 1 for the number of employees. Do
not accept a negative number for the days any employee missed. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int numOfEmp(int&);
int daysMissed(int&);
double daysAbsent(int&, int&, double&);

int main() {

    int emp = 0, 
        day = 0, 
        days = 0;

    double avg = 0;

    cout << "Number of employees in the company? ";
    numOfEmp(emp);

    for (int i = 1; i <= emp; i++) {
        cout << "How many days did employee #" << i << " miss at work? ";
        daysMissed(day);
        days += day;
    }

    daysAbsent(days, emp, avg);
    cout << "On average, " << emp << " employee(s) have missed a total of " << avg << " days of work.";

    return 0;
}

int numOfEmp(int &emp) {
    cin >> emp;
    while (emp < 1) {
        cout << "I was told to not accept a number less than 1 for the number of employees. ";
        cin >> emp;
    }
    return emp;
}

int daysMissed(int &day) {
    cin >> day;
    while (day < 0) {
        cout << "I was told to not accept a negative number for the days any employee missed. ";
        cin >> day;
    }
    return day;
}

double daysAbsent(int &days, int &emp, double &avg) {

    avg = days/emp;
    return avg;
} 