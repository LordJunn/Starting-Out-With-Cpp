/* Write a program that asks the user to enter a number of seconds.
• There are 60 seconds in a minute. If the number of seconds entered by the user is
greater than or equal to 60, the program should display the number of minutes in
that many seconds.
• There are 3,600 seconds in an hour. If the number of seconds entered by the user is
greater than or equal to 3,600, the program should display the number of hours in
that many seconds.
• There are 86,400 seconds in a day. If the number of seconds entered by the user is
greater than or equal to 86,400, the program should display the number of days in
that many seconds. */

#include <iostream>
#include <cmath>
using namespace std;

int main() {

    float s, m, h, d;

    cout << "Enter a number of seconds:" << endl;
    cin >> s;

    if (s >= 86400) {
        d = s/86400;
        cout << d << " days.";
    }
    else if (s >= 3600) {
        h = s/3600;
        cout << h << " hours.";
    }
    else if (s >= 60) {
        m = s/60;
        cout << m << " minutes.";
    }    
    else {
        cout << s << " seconds.";
    }

    return 0;
}