/* A car with a 20-gallon gas tank averages 23.5 miles per gallon when driven in town
and 28.9 miles per gallon when driven on the highway. Write a program that calculates
and displays the distance the car can travel on one tank of gas when driven in town
and when driven on the highway.

Hint: The following formula can be used to calculate the distance:
Distance = Number of Gallons = Average Miles per Gallon */

#include <iostream>
using namespace std;

int main()
{

    float tank = 20,
          town = 23.5,
          highway = 28.9;

    float townDistance = tank * town,
          highwayDistance = tank * highway;

    cout << "Distance the car can travel on one tank of gas when driven in town = " << townDistance << endl;
    
    cout << "Distance the car can travel on one tank of gas when driven on the highway = " << highwayDistance << endl;

return 0;

}
