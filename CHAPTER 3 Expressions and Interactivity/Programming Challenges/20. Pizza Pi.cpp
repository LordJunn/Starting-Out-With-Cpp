/* Joe’s Pizza Palace needs a program to calculate the number of slices a pizza of any size
can be divided into. The program should perform the following steps:
A) Ask the user for the diameter of the pizza in inches.
B) Calculate the number of slices that may be taken from a pizza of that size.
C) Display a message telling the number of slices.
To calculate the number of slices that may be taken from the pizza, you must know
the following facts:
• Each slice should have an area of 14.125 inches.
• To calculate the number of slices, simply divide the area of the pizza by 14.125.
• The area of the pizza is calculated with this formula:
Area = πr2

NOTE: π is the Greek letter pi. 3.14159 can be used as its value. The variable r is the
radius of the pizza. Divide the diameter by 2 to get the radius.

Make sure the output of the program displays the number of slices in fixed point nota-
tion, rounded to one decimal place of precision. Use a named constant for pi. */

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

int main() {
    
    const float pi = 3.14159,
                slice = 14.125;
    float diameter, radius, area, number;

    cout << "Diameter of the pizza in inches?" << endl;
    cin >> diameter;

    radius = diameter/2.0;
    area = pi * pow(radius, 2.0);

    number = area/slice;

    cout << fixed << setprecision(1) << "Number of slices that may be taken from a pizza of that size = " << number << endl;

    return 0;
}