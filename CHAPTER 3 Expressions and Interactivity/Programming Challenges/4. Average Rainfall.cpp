/* Write a program that calculates the average rainfall for three months. The program
should ask the user to enter the name of each month, such as June or July, and the
amount of rain (in inches) that fell each month. The program should display a message
similar to the following:
The average rainfall for June, July, and August is 6.72 inches. */

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    
    string m1, m2, m3;
    float a, b, c;
    float total;

    cout << "Enter the name of the first month to check: " << endl;
    cin >> m1;
    cout << "Enter " << m1 << "'s rainfall in inches: " << endl;
    cin >> a;

    cout << "Enter the name of the second month to check: " << endl;
    cin >> m2;
    cout << "Enter " << m2 << "'s rainfall in inches: " << endl;
    cin >> b;

    cout << "Enter the name of the third month to check: " << endl;
    cin >> m3;
    cout << "Enter " << m3 << "'s rainfall in inches: " << endl;
    cin >> c;

    total = (a + b + c)/3;

    cout << fixed << setprecision(2) << "The average rainfall for " << m1 << ", " << m2 << " and " << m3 << " is " << total << " inches." << endl;

    return 0;
}