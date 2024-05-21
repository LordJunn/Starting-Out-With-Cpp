/* Modify the program you wrote in Programming Challenge 18 (Pizza Pi) so that it
reports the number of pizzas you need to buy for a party if each person attending
is expected to eat an average of four slices. The program should ask the user for the
number of people who will be at the party and for the diameter of the pizzas to be
ordered. It should then calculate and display the number of pizzas to purchase. */

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

int main() {
    
    const float pi = 3.14159,
                slice = 14.125;
    float diameter, 
          radius, 
          area, 
          number, 
          slices, 
          people, 
          total;

    cout << "Number of people who will be at the party?" << endl;
    cin >> people;
    cout << "Diameter of the pizza to be ordered?" << endl;
    cin >> diameter;

    radius = diameter/2.0;
    area = pi * pow(radius, 2.0);

    slices = people * 4.0;

    number = area/slice;
    total = slices/number;


    cout << fixed << setprecision(1) << "Slices needed = " << slices << endl
                                     << "Slices per pizza = " << number << endl;

    cout << fixed << setprecision(1) << "Number of pizzas to purchase = " << total << endl;

    return 0;
}