/* A teacher has asked all her students to line up single file according to their first name.
For example, in one class Amy will be at the front of the line and Yolanda will be at
the end. Write a program that prompts the user to enter the number of students in the
class, then loops to read that many names. Once all the names have been read it reports
which student would be at the front of the line and which one would be at the end of
the line. You may assume that no two students have the same name.

Input Validation: Do not accept a number less than 1 or greater than 25 for the number
of students. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int main() {

    int number;
    string student, first, last;

    cout << "Number of students in the class? ";
    cin >> number;

    while (number < 1 || number > 25) {
        cout << "A number less than 1 or greater than 25 for the number of students is unaccepted. " << endl;
        cout << "Number of students in the class? ";
        cin >> number;
    }

        first = 'a';
        last = 'a';    

    for (int i = 1; i <= number; i++) {
        cout << "Enter a name: ";
        cin >> student;

        if (student > last) {
            last = student;
        }
        if (student < first) {
            first = student;
        }  

    }

    cout << first << endl;
    cout << last << endl;

    return 0;
}