/* A country club, which currently charges $2,500 per year for membership, has
announced it will increase its membership fee by 4% each year for the next six years.
Write a program that uses a loop to display the projected rates for the next six years. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int main() {

    const double increase = 0.04,
                 membership = 2500.0;
    double cost;

    for (int i = 0; i <= 6; i++) {

        cost = membership + (membership * (i * increase));
        cout << "Membership price is projected to be $" << cost << " for the next " << i << " years." << endl;

    }

    return 0;
}