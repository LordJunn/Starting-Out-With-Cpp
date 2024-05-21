/* Write a program that asks the user for an angle, entered in radians. The program
should then display the sine, cosine, and tangent of the angle. (Use the sin, cos, and
tan library functions to determine these values.) The output should be displayed in
fixed-point notation, rounded to four decimal places of precision. */

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

int main() {
    
    float radians;

    cout << "Angle, entered in radians?" << endl;
    cin >> radians;

    cout << fixed << setprecision(4) << endl;

    cout << "Sine of the angle = " << sin(radians) << endl;
    cout << "Cosine of angle   = " << cos(radians) << endl;
    cout << "Tangent of angle  = " << tan(radians) << endl;

    return 0;
}