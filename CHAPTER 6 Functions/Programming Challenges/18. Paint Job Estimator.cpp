/* A painting company has determined that for every 110 square feet of wall space,
one gallon of paint and eight hours of labor will be required. The company charges
$25.00 per hour for labor. Write a modular program that allows the user to enter
the number of rooms that are to be painted and the price of the paint per gallon. It
should also ask for the square feet of wall space in each room. It should then display
the following data:
• The number of gallons of paint required
• The hours of labor required
• The cost of the paint
• The labor charges
• The total cost of the paint job

Input validation: Do not accept a value less than 1 for the number of rooms. Do not
accept a value less than $10.00 for the price of paint. Do not accept a negative value
for square footage of wall space. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

const int hLabour = 8,
          cLabour = 25,
          paint = 110;

int checker(int&, int); // i love this one
void data(int, int);

int main() {

    int rooms, pain, sqft, sqFeet;

    cout << "Number of rooms that are to be painted? ";
    rooms = checker(rooms, 0);
    cout << "Price of the paint per gallon? ";
    pain = checker(pain, 0);

    for (int i = 1; i <= rooms; i++) {
        cout << "Square feet of wall space in room #" << i << "? ";
        sqft = checker(sqft, -1);
        sqFeet += sqft;
    }

    data(pain, sqFeet);

    return 0;
}

int checker(int &x, int i) {

    cin >> x;
    while (x <= i) {
        cout << "Enter a bigger number, bigger than " << i << ". ";
        cin >> x;
    }

    return x;

}

void data(int p, int s) {

    int gal, hrs, charges, total;

    cout << "The number of gallons of paint required: " << s << endl;
    hrs = (s/paint) * hLabour;   
    cout << "The hours of labor required: " << hrs << endl;
    gal = (s/paint) * p;   
    cout << "The cost of the paint: $" << gal << endl;
    charges = hrs * cLabour;
    cout << "The labor charges: $" << charges << endl;

    total = gal + charges;
    cout << "The total cost of the paint job: $" << total << endl;

}

