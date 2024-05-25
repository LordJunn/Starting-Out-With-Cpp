/* A bank charges $10 per month plus the following check fees for a commercial check-
ing account:
$.10 each for fewer than 20 checks
$.08 each for 20–39 checks
$.06 each for 40–59 checks
$.04 each for 60 or more checks
The bank also charges an extra $15 if the balance of the account falls below $400 (before
any check fees are applied). Write a program that asks for the beginning balance and the
number of checks written. Compute and display the bank’s service fees for the month.

Input Validation: Do not accept a negative value for the number of checks written. If a
negative value is given for the beginning balance, display an urgent message indicating
the account is overdrawn. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int main() {

    float fee, charge, bal, check;
    charge = 15;

    cout << "Beginning balance?" << endl;
    cin >> bal;

    if (bal >= 400) {
        cout << "Number of checks written?" << endl;
        cin >> check;

        if (check >= 60) {
            fee = check * 0.04;
        }
        else if (check >= 40) {
            fee = check * 0.06;            
        }
        else if (check >= 20) {
            fee = check * 0.08;
        }
        else if (check > 0) {
            fee = check * 0.1;            
        }
        else {
            cout << "???" << endl;
        }

        cout << fixed << setprecision(2) << "Bank's service fee for the month: $" << fee << endl;

    }
    else if (bal > 0)
    {
        cout << "Number of checks written?" << endl;
        cin >> check;

        if (check >= 60) {
            fee = check * 0.04;
        }
        else if (check >= 40) {
            fee = check * 0.06;            
        }
        else if (check >= 20) {
            fee = check * 0.08;
        }
        else if (check > 0) {
            fee = check * 0.1;            
        }
        else {
            cout << "???" << endl;
        }

        cout << fixed << setprecision(2) << "Bank's service fee for the month: $" << fee + charge << endl;        
        
    }
    else {
        cout << "Urgent message indicating the account is overdrawn." << endl;
    }

    return 0;
}