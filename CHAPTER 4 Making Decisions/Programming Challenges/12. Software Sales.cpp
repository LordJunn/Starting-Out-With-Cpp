/* A software company sells a package that retails for $99. Quantity discounts are given
according to the following table.

Quantity    Discount
10–19       20%
20–49       30%
50–99       40%
100 or more 50%

Write a program that asks for the number of units sold and computes the total cost of
the purchase.
Input Validation: Make sure the number of units is greater than 0. */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

int main() {

    float package, ori, cost;

    cout << "Number of units sold?" << endl;
    cin >> package;

    ori = package * 99;

    if (package >= 100) {
        cost = ori * 0.5;
    }
    else if (package >= 50) {
        cost = ori * 0.6;
    }
    else if (package >= 20) {
        cost = ori * 0.7;
    }
    else if (package >= 10) {
        cost = ori * 0.8;
    }
    else if (package > 0) {
        cost = ori;
    }    
    else {
        cout << "???" << endl;
        return 0;
    }

    cout << fixed << setprecision(2) << "Original price: $" << ori << endl;
    cout << fixed << setprecision(2) << "Total cost of the purchase: $" << cost << endl;

    return 0;
}