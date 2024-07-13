/* Write a program that asks the user for a positive integer value. The program should use
a loop to get the sum of all the integers from 1 up to the number entered. For example,
if the user enters 50, the loop will find the sum of 1, 2, 3, 4, … 50.
Input Validation: Do not accept a negative starting number. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int main() {

    int value, integer, total;
    integer = 2;

    cout << "Positive integer value?" << endl;
    cin >> value;

    while (value <= 0) {
        cout << "???" << endl;
        cin >> value;
    }

    for (int num = 1; num <= value; num++) {
        cout << num << endl;
        total += num;
    }

    cout << "Total " << total << endl;

    return 0;
}