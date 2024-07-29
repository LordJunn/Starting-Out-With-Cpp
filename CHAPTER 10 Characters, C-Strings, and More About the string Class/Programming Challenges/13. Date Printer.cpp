/* Write a program that reads a string from the user containing a date in the form mm/dd/yyyy.
It should print the date in the form March 12, 2014. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <cctype>
#include <cstring>
using namespace std;

string months[] = {
        "January", "February", "March", "April", "May", "June", "July",
        "August", "September", "October", "November", "December" };

void linefunction(string&, int);
void dateFormat(string&);

int main() {

    string date;
    int SIZE = 9;

    cout << "The date format is mm/dd/yyyy. " << endl;
    linefunction(date, SIZE); 

    dateFormat(date);

    return 0;
}

void linefunction(string &array, int SIZE) {
    cout << "Input a date no more than " << (SIZE) << " in length. " << endl;
    cin >> array;
}

void dateFormat(string &date) {
    
    string s1, s2, s3, month;
    s1.assign(date, 0, 2);
    int mon = stoi(s1);
    month = months[mon - 1];
    s2.assign(date, 2, 2);
    s3.assign(date, 4, 4);

    cout << month << " " << s2 << ", " << s3;
}