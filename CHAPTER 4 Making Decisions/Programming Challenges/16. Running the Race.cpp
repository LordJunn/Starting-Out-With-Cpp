/* Write a program that asks for the names of three runners and the time it took each
of them to finish a race. The program should display who came in first, second, and
third place.

Input Validation: Only accept positive numbers for the times. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int main() {

    string name1, name2, name3;
    int time1, time2, time3;
    string place1, place2, place3;

    cout << "Name of first runner?" << endl;
    cin >> name1;
    cout << "Time for first runner to finish the race?" << endl;
    cin >> time1;
    cout << "Name of second runner?" << endl;
    cin >> name2;
    cout << "Time for second runner to finish the race?" << endl;
    cin >> time2;    
    cout << "Name of third runner?" << endl;
    cin >> name3;
    cout << "Time for third runner to finish the race?" << endl;
    cin >> time3;

    if (time1 <=! 0 && time2 <=! 0 && time3 <=! 0) {

        if (time1 < time2 && time1 < time3) {

            if (time2 < time3) {
                place1 = name1;
                place2 = name2;
                place3 = name3;
            }
            else {
                place1 = name1;
                place2 = name3;
                place3 = name2;
            }

        }
        else if (time2 < time3 && time2 < time1) {

            if (time1 < time3) {
                place1 = name2;
                place2 = name1;
                place3 = name3;
            }
            else {
                place1 = name2;
                place2 = name3;
                place3 = name1;
            }

        }
        else {

            if (time1 < time2) {
                place1 = name3;
                place2 = name1;
                place3 = name2;
            }
            else {
                place1 = name3;
                place2 = name1;
                place3 = name2;            
            }
        }

    cout << "Name 1 = " << name1 << ". Time = " << time1 << endl;
    cout << "Name 2 = " << name2 << ". Time = " << time2 << endl;
    cout << "Name 3 = " << name3 << ". Time = " << time3 << endl;

    cout << place1 << endl;
    cout << place2 << endl;    
    cout << place3 << endl;

    }

    else {
        cout << "???" << endl;
    }

    return 0;
}