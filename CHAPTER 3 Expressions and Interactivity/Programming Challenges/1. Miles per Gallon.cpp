/* Write a program that calculates a car’s gas mileage. The program should ask the user
to enter the number of gallons of gas the car can hold and the number of miles it can
be driven on a full tank. It should then display the number of miles that may be driven
per gallon of gas. */

#include <iostream>
using namespace std;

int main() {
    
    double gallons, miles, mpg;

    cout << "Number of gallons of gas the car can hold:" << endl;
    cin >> gallons;
    cout << "Number of miles it can be driven on a full tank:" << endl;
    cin >> miles;

    mpg = miles/gallons;

    cout << mpg << " miles per gallon" << endl;

    return 0;
}