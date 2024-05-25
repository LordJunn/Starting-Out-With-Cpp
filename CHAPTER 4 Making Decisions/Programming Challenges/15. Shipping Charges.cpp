/* The Fast Freight Shipping Company charges the following rates:

Weight of Package (in Kilograms)     Rate per 500 Miles Shipped
2 kg or less                         $1.10
Over 2 kg but not more than 6 kg     $2.20
Over 6 kg but not more than 10 kg    $3.70
Over 10 kg but not more than 20 kg   $4.80

Write a program that asks for the weight of the package and the distance it is to be
shipped, and then displays the charges.

Input Validation: Do not accept values of 0 or less for the weight of the package. Do
not accept weights of more than 20 kg (this is the maximum weight the company will
ship). Do not accept distances of less than 10 miles or more than 3,000 miles. These
are the company’s minimum and maximum shipping distances. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int main() {

    float weight, miles, rate;

    cout << "Weight of the package?" << endl;
    cin >> weight;

    if (weight > 0 && weight <= 20) {

        cout << "Distance of the package to be shipped?" << endl;
        cin >> miles;

        if (miles >= 10 && miles <= 3000){

             if (weight <= 2)
                rate = (miles / 500) * 1.10;
            else if (weight > 2 && weight <= 6)
                rate = (miles / 500) * 2.20;
            else if (weight > 6 && weight <= 10)
                rate = (miles / 500) * 3.70;
            else if (weight > 10 && weight <= 20)
                rate = (miles / 500) * 4.80;   

        cout << rate << endl;         

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