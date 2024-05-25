/* A mobile phone service provider has three different subscription packages for its
customers:

Package A: For $39.99 per month 450 minutes are provided. Additional minutes are
$0.45 per minute.
Package B: For $59.99 per month 900 minutes are provided. Additional minutes are
$0.40 per minute.
Package C: For $69.99 per month unlimited minutes provided.

Write a program that calculates a customer’s monthly bill. It should ask which package
the customer has purchased and how many minutes were used. It should then display
the total amount due.

Input Validation: Be sure the user only selects package A, B, or C. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int main() {

    char menu;
    float cost, min;

    cout << "Which package have you purchased?" << endl;
    cin >> menu;

    switch (menu) {

        case 'a':
        case 'A':

            cout << "How many minutes were used?" << endl;
            cin >> min;

            if (min <= 450) {
                cout << "$39.99";
            }
            else {
                cost = 39.99 + ((min - 450) * 0.45);
                cout << "$" << cost << endl;
            }

        break;

        case 'b':
        case 'B':

            cout << "How many minutes were used?" << endl;
            cin >> min;

            if (min <= 900) {
                cout << "$59.99";
            }
            else {
                cost = 59.99 + ((min - 900) * 0.40);
                cout << "$" << cost << endl;
            }

        break;

        case 'c':
        case 'C':

            cout << "How many minutes were used?" << endl;
            cin >> min;

            cout << "$69.99";

        break;

    }

    return 0;
}