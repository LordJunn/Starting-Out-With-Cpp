/* Write a program that asks the user to enter an item’s wholesale cost and its markup
percentage. It should then display the item’s retail price. For example:

• If an item’s wholesale cost is 5.00 and its markup percentage is 100%, then the
item’s retail price is 10.00.
• If an item’s wholesale cost is 5.00 and its markup percentage is 50%, then the item’s
retail price is 7.50.

The program should have a function named calculateRetail that receives the
wholesale cost and the markup percentage as arguments and returns the retail price
of the item.

Input Validation: Do not accept negative values for either the wholesale cost of the
item or the markup percentage. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

void calculateRetail(int, float);

int main() {

    float retail, markup;
    int cost;

    cout << "Wholesale cost? ";
    cin >> cost;

    while (cost <= 0) {
        cout << "Bad!" << endl;
        cout << "Wholesale cost? ";
        cin >> cost;
    }

    cout << "Markup percentage? ";
    cin >> markup;

    while (markup <= 0) {
        cout << "Bad!" << endl;
        cout << "Markup percentage? ";
        cin >> markup;
    }    

    calculateRetail(cost, markup);

    return 0;
}

void calculateRetail(int cost, float markup) {

    markup /= 100;
    cout << "Item's retail price: $" << cost + (cost * markup) << endl;

}