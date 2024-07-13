/* Assuming the ocean’s level is currently rising at about 1.5 millimeters per year, write
a program that displays a table showing the number of millimeters that the ocean will
have risen each year for the next 25 years. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int main() {

    const float rise = 1.5;
    const int years = 25;

    for (int i = 1; i <= years; i++) {
        cout << "In the next " << i << " years, the ocean will have risen by " << i * rise << " mm." << endl;
    }

    return 0;
}