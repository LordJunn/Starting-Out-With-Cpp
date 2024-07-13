/* Write a program that calculates how much a person would earn over a period of time
if his or her salary is one penny the first day and two pennies the second day, and con-
tinues to double each day. The program should ask the user for the number of days.
Display a table showing how much the salary was for each day, and then show the
total pay at the end of the period. The output should be displayed in a dollar amount,
not the number of pennies.

Input Validation: Do not accept a number less than 1 for the number of days worked. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int main() {

    float penny, salary, dollar, days, total;


    cout << "Number of days?" << endl;
    cin >> days;

    while (days <= 0) {
        cout << "If I were to work 0 or less days, do I need to pay the company back?" << endl;
        cout << "Number of days?" << endl;
        cin >> days;
    }        

    for (int i = 1; i <= days; i++) {

        penny = 1;
        salary = pow(2, (i - 1));
        dollar = salary/100;

        cout << fixed << setprecision(2) << "day " << i << ", salary is $" << dollar << endl;
        total += dollar;

    }    

    cout << fixed << setprecision(2) << "Total pay = $" << total << endl;



    return 0;
}