/* Assuming there are no deposits other than the original investment, the balance in a
savings account after one year may be calculated as
Amount = Principal * (1 + Rate/T)^T
Principal is the balance in the savings account, Rate is the interest rate, and T is
the number of times the interest is compounded during a year (T is 4 if the interest is
compounded quarterly).
Write a program that asks for the principal, the interest rate, and the number of times
the interest is compounded. It should display a report similar to
Interest Rate: 4.25%
Times Compounded: 12
Principal: $ 1000.00
Interest: $ 43.34
Amount in Savings: $ 1043.34 */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

int main() {
    float principal, rate, times, interest, amount;

    cout << "Balance in the savings account?" << endl;
    cin >> principal;
    cout << "Interest rate?" << endl;
    cin >> rate;
    cout << "Number of times the interest is compounded during a year?" << endl;
    cin >> times;

    amount = principal * pow((1 + ((rate/100.0)/times)), times);
    interest = amount - principal;

    cout << "Interest Rate: " << rate << "%" << endl;
    cout << "Times Compounded: " << times << endl;
    cout << fixed << setprecision(2) << "Principal: $" << principal << endl
                                     << "Interest: $" << interest << endl
                                     << "Amount in Savings: $" << amount << endl;


    return 0;
}