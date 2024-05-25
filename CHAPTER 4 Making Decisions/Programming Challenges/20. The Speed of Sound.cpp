/* The following table shows the approximate speed of sound in air, water, and steel.

Medium             Speed
Air                1,100 feet per second
Water              4,900 feet per second
Steel              16,400 feet per second

Write a program that displays a menu allowing the user to select air, water, or steel.
After the user has made a selection, he or she should be asked to enter the distance
a sound wave will travel in the selected medium. The program will then display the
amount of time it will take. (Round the answer to four decimal places.)
Input Validation: Check that the user has selected one of the available choices from the
menu. Do not accept distances less than 0. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int main() {

    const int air = 1100,
              water = 4900,
              steel = 16400;

    int menu;
    float distance, time;

    cout << "Select 1 for air, 2 for water & 3 for steel." << endl;
    cin >> menu;

    switch(menu) {

        case 1:
        
            cout << "Enter the distance a sound wave will travel in the selected medium." << endl;
            cin >> distance;

            if (distance > 0) {
                time = distance/air;
                cout << fixed << setprecision(4) << time << " seconds." << endl;
            }
            else {
                cout << "???" << endl;
            }
        break;

        case 2:
        
            cout << "Enter the distance a sound wave will travel in the selected medium." << endl;
            cin >> distance;

            if (distance > 0) {
                time = distance/water;
                cout << fixed << setprecision(4) << time << " seconds." << endl;
            }
            else {
                cout << "???" << endl;
            }
        break;

        case 3:
        
            cout << "Enter the distance a sound wave will travel in the selected medium." << endl;
            cin >> distance;

            if (distance > 0) {
                time = distance/steel;
                cout << fixed << setprecision(4) << time << " seconds." << endl;
            }
            else {
                cout << "???" << endl;
            }
        break;

        default:

        cout << "???" << endl;

        break;

    }

    return 0;
}