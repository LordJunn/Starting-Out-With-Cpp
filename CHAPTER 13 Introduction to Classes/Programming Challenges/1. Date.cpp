/* Design a class called Date. The class should store a date in three integers: month, day,
and year. There should be member functions to print the date in the following forms:
12/25/2014
December 25, 2014
25 December 2014
Demonstrate the class by writing a complete program implementing it.

Input Validation: Do not accept values for the day greater than 31 or less than 1. Do
not accept values for the month greater than 12 or less than 1. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <cctype>
#include <cstring>
#include <fstream>
using namespace std;

class Date {
   private:
    int month, day, year;

   public:
    void setDate(int, int, int);
    void slash();
    void american(string[]);
    void global(string[]);
};

void Date::setDate(int d, int m, int y) {
    day = d;
    month = m;
    year = y;
}

void Date::slash() {
    cout << month << "/" << day << "/" << year << endl;
}

void Date::american(string months[]) {
    cout << months[month - 1] << " " << day << ", " << year << endl; 
}

void Date::global(string months[]) {
    cout << day << " " << months[month - 1] << " " << year << endl; 
}

int checker(int&, int, int);

int main() {

    Date date;
    int d, m, y;

    string months[12] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };


    cout << "Enter the day: ";
    d = checker(d, 1, 31);   
    cout << "Enter the month: ";
    m = checker(m, 1, 12);  
    cout << "Enter the year: ";
    cin >> y;

    date.setDate(d, m, y);
    date.slash();
    date.american(months);
    date.global(months);

    return 0;
}

int checker(int &x, int i, int j) {

    cin >> x;
    while (x < i || x > j) {
        cout << "Enter a bigger number, bigger than " << i << ", but smaller than " << j << ". ";
        cin.clear();
        cin >> x;
    }

    return x;

}
