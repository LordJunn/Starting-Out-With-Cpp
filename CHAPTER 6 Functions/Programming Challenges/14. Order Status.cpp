/* The Middletown Wholesale Copper Wire Company sells spools of copper wiring for
$100 each. Write a program that displays the status of an order. The program should
have a function that asks for the following data:
• The number of spools ordered.
• The number of spools in stock.
• Whether there are special shipping and handling charges.
(Shipping and handling is normally $10 per spool.) If there are special charges, the
program should ask for the special charges per spool.
The gathered data should be passed as arguments to another function that displays
• The number of spools ready to ship from current stock.
• The number of spools on backorder (if the number ordered is greater than what is
in stock).
• Subtotal of the portion ready to ship (the number of spools ready to ship times
$100).
• Total shipping and handling charges on the portion ready to ship.
• Total of the order ready to ship.
The shipping and handling parameter in the second function should have the default
argument 10.00.

Input Validation: Do not accept numbers less than 1 for spools ordered. Do not accept
a number less than 0 for spools in stock or shipping and handling charges. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

const int pricew = 100;

int checker(int&, int);
int spool(int&, int&, int&);
void ready(int&, int&, int&);

int main() {

    int ordered, stock,
        shiphand = 10;

    spool(ordered, stock, shiphand);

    ready(ordered, stock, shiphand);



    return 0;
}

int checker(int &x, int i) {

    cin >> x;
    while (x <= i) {
        cout << "Enter a bigger number. ";
        cin >> x;
    }

    return x;

}

int spool(int &ordered, int &stock, int &shiphand) {

    char owo;

    cout << "The number of spools ordered? ";
    ordered = checker(ordered, 1);
    cout << "The number of spools in stock? ";
    stock = checker(stock, 0);
    cout << "Any special charges for shipping and handling? ";
    cin >> owo;
    if (owo == 'Y' || owo == 'y') {
        cout << "Enter it then. ";
        shiphand = checker(shiphand, 0);
    }
    else {
        cout << "We're going to use the default, which is 10 then." << endl;
        shiphand = 10;
    }

    return ordered, stock, shiphand;

}

void ready(int &ordered, int &stock, int &shiphand) {

    int backorder, price, charges, total;

    cout << "Ordered: " << ordered << ", Stock: " << stock << ", Ship & Hand: " << shiphand << endl << endl;

    cout << "The number of spools ready to ship from current stock: " << stock << endl;

    backorder = stock - ordered;

    if (backorder < 0) {
        backorder = abs(backorder);
        cout << "The number of spools on backorder: " << backorder << endl;
    }
    else if (backorder == 0) {
        cout << "Backordering is not a must as we have exactly enough." << endl;
    }
    else {
        cout << "Backordering is not necessary as we have enough stock (" << backorder << " remaining)." << endl;
    }

    price = stock * pricew;
    cout << "Subtotal of the portion ready to ship: $" << price << endl;

    charges = stock * shiphand;
    cout << "Total shipping and handling charges on the portion ready to ship: $" << charges << endl;

    total = price + charges;
    cout << "Total of the order ready to ship: $" << total << endl;

}