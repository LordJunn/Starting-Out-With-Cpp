/* The date June 10, 1960 is special because when we write it in the following format, the
month times the day equals the year.

6/10/60

Write a program that asks the user to enter a month (in numeric form), a day, and a
two-digit year. The program should then determine whether the month times the day is
equal to the year. If so, it should display a message saying the date is magic. Otherwise
it should display a message saying the date is not magic. */

#include <iostream>
using namespace std;

int main() {

    int month, day, year, add;

    cout << "Enter a month (in numeric form):" << endl;
    cin >> month;
    cout << "Enter a day (in numeric form):" << endl;
    cin >> day;
    cout << "Enter a two-digit year (in numeric form):" << endl;
    cin >> year;    

    add = month + day;

    if (add == year) {
        cout << "The date is magic." << endl;
    }
    else {
        cout << "The date is not magic." << endl;        
    }
    return 0;
}