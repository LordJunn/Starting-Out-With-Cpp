/* Modify the Program in Programming Challenge 25 so that it also displays how much
money Package A customers would save if they purchased packages B or C, and how
much money Package B customers would save if they purchased Package C. If there
would be no savings, no message should be printed. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int main() {

    char menu;
    float cost1, cost2, savingsb, savingsc, min;

    const float cost3 = 69.99;

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
                cost1 = 39.99 + ((min - 450) * 0.45);
                cout << "$" << cost1 << endl;
            }

            if (min <= 900) {
                cost2 = 59.99;
            }
            else {
                cost2 = 59.99 + ((min - 900) * 0.40);
            }

            if (cost2 < cost1) {
                savingsb = cost1 - cost2;
                cout << "If you purchased package B, you would've saved as much as $" << savingsb << endl;
            }       

            if (cost3 < cost1) {
                savingsc = cost1 - cost3;
                cout << "If you purchased package C, you would've saved as much as $" << savingsc << endl;
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
                cost2 = 59.99 + ((min - 900) * 0.40);
                cout << "$" << cost2 << endl;
            }

            if (cost3 < cost2) {
                savingsc = cost2 - cost3;
                cout << "If you purchased package C, you would've saved as much as $" << savingsc << endl;
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