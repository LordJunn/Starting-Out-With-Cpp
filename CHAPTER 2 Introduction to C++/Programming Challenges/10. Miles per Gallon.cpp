/* A car holds 15 gallons of gasoline and can travel 375 miles before refueling. Write a
program that calculates the number of miles per gallon the car gets. Display the result
on the screen.

Hint: Use the following formula to calculate miles per gallon (MPG):
MPG = Miles Driven/Gallons of Gas Used */

#include <iostream>
using namespace std;

int main()
{

    int tank = 15;
    int maxDistance = 375;

    float MPG = maxDistance/tank;

    cout << "Number of miles per gallon the car gets = " << MPG << endl;

return 0;

}
