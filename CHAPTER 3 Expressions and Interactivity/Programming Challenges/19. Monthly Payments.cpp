/* The monthly payment on a loan may be calculated by the following formula:
Payment = [Rate * (1 + Rate)^N] / [((1 + Rate)^N - 1)] x L
Rate is the monthly interest rate, which is the annual interest rate divided by 12. (12%
annual interest would be 1 percent monthly interest.) N is the number of payments, and
L is the amount of the loan. Write a program that asks for these values and displays a
report similar to
Loan Amount: $ 10000.00
Monthly Interest Rate: 1%
Number of Payments: 36
Monthly Payment: $ 332.14
Amount Paid Back: $ 11957.15
Interest Paid: $ 1957.15 */

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

int main() {
    
    float loan, rate, monthly, interest, amount;
    int times;

    cout << "Loan amount?" << endl;
    cin >> loan;
    cout << "Monthly interest rate?" << endl;
    cin >> rate;
    cout << "Number of payments?" << endl;
    cin >> times;

    rate /= 100;

    monthly = ((rate) * pow(1 + (rate), times) / (pow(1 + (rate), times) - 1)) * loan ;
    amount = monthly * times;
    interest = amount - loan;

    rate *= 100;
    
    cout << setprecision(2) << fixed <<  "Loan amount: $" << loan << endl;

    cout << "Monthly Interest Rate: " << rate << "%" << endl;
    cout << "Numbers of Payments: " << times << endl;

    cout << fixed << setprecision(2) << "Monthly Payment: $" << monthly << endl
                                     << "Amount Paid Back: $" << amount << endl
                                     << "Interest Paid: $" << interest << endl;


    return 0;
}