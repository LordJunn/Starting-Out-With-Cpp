/* A long-distance carrier charges the following rates for telephone calls:

Starting Time of Call    Rate per Minute
00:00–06:59              0.05
07:00–19:00              0.45
19:01–23:59              0.20

Write a program that asks for the starting time and the number of minutes of the call,
and displays the charges. The program should ask for the time to be entered as a floating-
point number in the form HH.MM. For example, 07:00 hours will be entered as 07.00,
and 16:28 hours will be entered as 16.28.

Input Validation: The program should not accept times that are greater than 23:59. Also,
no number whose last two digits are greater than 59 should be accepted. Hint: Assuming
num is a floating-point variable, the following expression will give you its fractional part:
num − static_cast<int>(num) */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int main() {

    float num, m, time, charge;

    cout << "Starting time?" << endl;
    cin >> num;

    if (num <= 23.59) {

        m = num - static_cast<int>(num);

        if (m <= 0.59) {

            cout << "Number of minutes of the call?" << endl;
            cin >> time;    

            if (num > 19.01) {
                charge = time * 0.2;
                cout << charge;
            }
            else if (num >= 7.00) {
                charge = time * 0.45;
                cout << charge;
            } 
            else {
                charge = time * 0.05;
                cout << charge;
            }

        }
        else {
            cout << "???" << endl;
        }

    }
    else {
        cout << "???" << endl;
    }

    return 0;
}