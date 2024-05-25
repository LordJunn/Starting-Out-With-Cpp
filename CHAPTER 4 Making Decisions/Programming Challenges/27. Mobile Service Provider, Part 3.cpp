/* Months with 30 days have 720 hours, and months with 31 days have 744 hours.
February, with 28 days, has 672 hours. You can calculate the number of minutes in
a month by multiplying its number of hours by 60. Enhance the input validation of
the Mobile Service Provider program by asking the user for the month (by name), and
validating that the number of minutes entered is not more than the maximum for the
entire month. Here is a table of the months, their days, and number of hours in each.
Month      Days      Hours
January    31        744
February   28        672
March      31        744
April      30        720
May        31        744
June       30        720
July       31        744
August     31        744
September  30        720
October    31        744
November   30        720
December   31        744 */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int main() {

    char menu;
    float cost1, cost2, cost3, savingsb, savingsc, min, maxmin;
    int month;

    cout << "Which package have you purchased?" << endl;
    cin >> menu;

    cout << "What is the month (in digits)?" << endl;
    cin >> month;
    switch (month)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            maxmin = 744 * 60;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            maxmin = 720 * 60;
            break;
        case 2:
            maxmin = 672 * 60;
            break;
    
        default:
            cout << "Invalid month. Rerun program.\n"
                    << "Try again." 
                    << endl;
            break;
    }

    switch (menu) {

        case 'a':
        case 'A':

            cout << "How many minutes were used?" << endl;
            cin >> min;

            if (min <= maxmin) {
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
            }

            else {
                cout << "I too, would like to have more than 1440 minutes in a day." << endl;
            }

        break;

        case 'b':
        case 'B':

            cout << "How many minutes were used?" << endl;
            cin >> min;

            if (min <= maxmin) {
                if (min <= 900) {
                    cout << "$59.99";
                }
                else {
                    cost2 = 59.99 + ((min - 900) * 0.40);
                    cout << "$" << cost2 << endl;
                }

                if (cost2 < cost1) {
                    savingsb = cost1 - cost2;
                    cout << "If you purchased package B, you would've saved as much as $" << savingsb << endl;
                }       

                if (cost3 < cost1) {
                    savingsc = cost1 - cost3;
                    cout << "If you purchased package C, you would've saved as much as $" << savingsc << endl;
                }  
            }

            else {
                cout << "I too, would like to have more than 1440 minutes in a day." << endl;
            }

        break;

        case 'c':
        case 'C':

            cout << "How many minutes were used?" << endl;
            cin >> min;

            if (min <= maxmin) {
                cout << "$69.99"; 
            }

            else {
                cout << "I too, would like to have more than 1440 minutes in a day." << endl;
            }            

        break;

    }

    return 0;
}