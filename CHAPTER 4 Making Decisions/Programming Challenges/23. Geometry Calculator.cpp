/* Write a program that displays the following menu:

Geometry Calculator
1. Calculate the Area of a Circle
2. Calculate the Area of a Rectangle
3. Calculate the Area of a Triangle
4. Quit
Enter your choice (1-4):

If the user enters 1, the program should ask for the radius of the circle and then display
its area. Use the following formula:

area = πr2

Use 3.14159 for π and the radius of the circle for r . If the user enters 2, the program
should ask for the length and width of the rectangle and then display the rectangle’s
area. Use the following formula:

area = length * width

If the user enters 3 the program should ask for the length of the triangle’s base and its
height, and then display its area. Use the following formula:

area = base * height * .5

If the user enters 4, the program should end.

Input Validation: Display an error message if the user enters a number outside the range
of 1 through 4 when selecting an item from the menu. Do not accept negative values
for the circle’s radius, the rectangle’s length or width, or the triangle’s base or height. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int main() {

    int choice;
    const float pi = 3.14159;

    cout << "Geometry Calculator " << endl <<
            "1. Calculate the Area of a Circle " << endl <<
            "2. Calculate the Area of a Rectangle " << endl <<
            "3. Calculate the Area of a Triangle " << endl <<
            "4. Quit " << endl <<
            "Enter your choice (1-4): " << endl;

    cin >> choice;

    switch(choice) {

        case 1: //stolen from 3-5

            double area, radius;

            cout << "This program calculates the area of a circle.\n";
            cout << "What is the radius of the circle? ";
            cin >> radius;

            if (radius > 0) {
                area = pi * pow(radius, 2.0);
                cout << "The area is " << area << endl;
            }
            else {
                cout << "???" << endl;
            }

        break;

        case 2: //stolen from 3-2

            int length, width, area2;

            cout << "This program calculates the area of a ";
            cout << "rectangle.\n";
            cout << "Enter the length and width of the rectangle ";
            cout << "separated by a space.\n";

            cin >> length >> width;

            if (length > 0 && width > 0) {
                area2 = length * width;
                cout << "The area of the rectangle is " << area2 << endl;   
            }
            else {
                cout << "???" << endl;
            }
            
        break;

        case 3: 
        
            int base, height, area3;

            cout << "This program calculates the area of a ";
            cout << "triangle.\n";
            cout << "Enter the base and height of the triangle ";
            cout << "separated by a space.\n";

            cin >> base >> height;

            if (base > 0 && height > 0) {
                area3 = base * height * 0.5;
                cout << "The area of the triangle is " << area3 << endl;   
            }
            else {
                cout << "???" << endl;
            }
            
        break;

        case 4:
            cout << "Quit w" << endl;        
        break;

        default: 
            cout << "???" << endl;
        break;

    }

    return 0;
}