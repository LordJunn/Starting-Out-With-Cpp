/* Write a program that calculates the balance of a savings account at the end of a period
of time. It should ask the user for the annual interest rate, the starting balance, and the
number of months that have passed since the account was established. A loop should
then iterate once for every month, performing the following:

A) Ask the user for the amount deposited into the account during the month. (Do not
accept negative numbers.) This amount should be added to the balance.

B) Ask the user for the amount withdrawn from the account during the month. (Do
not accept negative numbers.) This amount should be subtracted from the balance.

C) Calculate the monthly interest. The monthly interest rate is the annual interest rate
divided by twelve. Multiply the monthly interest rate by the balance, and add the
result to the balance.

After the last iteration, the program should display the ending balance, the total
amount of deposits, the total amount of withdrawals, and the total interest earned.

NOTE: If a negative balance is calculated at any point, a message should be displayed
indicating the account has been closed and the loop should terminate. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int main() {

    float rate, mrate, interest, interestt;
    float bal, months, dep, dept, with, witht;

    rate = mrate = interest = interestt = 0;
    bal = months = dep = dept = with = witht = 0;

    cout << "Annual interest rate?" << endl;
    cin >> rate;

    cout << "Starting balance?" << endl;
    cin >> bal; 

    cout << "The number of months that have passed since the account was established?" << endl;
    cin >> months;       

    for (int i = 1; i <= months; i++) {

        cout << "Amount deposited into the account during month " << i << " ?" << endl;
        cin >> dep;

        while (dep < 0) {
            cout << "No!" << endl;
            cout << "Amount deposited into the account during month " << i << " ?" << endl;
            cin >> dep;
        }

        bal += dep;
        dept += dep;
    
        if (bal < 0) {
            break;
        }

        cout << "Amount withdrawn from the account during month " << i << " ?" << endl;
        cin >> with;

        while (with < 0) {
            cout << "No!" << endl;
            cout << "Amount withdrawn from the account during month " << i << " ?" << endl;
            cin >> with;
        }

        bal -= with;
        witht += with;
    
        if (bal < 0) {
            break;
        }

        rate = rate/100;
        mrate = rate/12;

        interest = (bal * mrate);

        bal += interest;
        interestt += interest;
    }

    if (bal < 0) {
        cout << "Bankrupt!" << endl;
        cout << "Account has been closed!" << endl;
    }
    else {
        cout << fixed << setprecision(2) << "Ending balance: $" << bal << endl;
        cout << fixed << setprecision(2) << "Total amount of deposits: $" << dept << endl;
        cout << fixed << setprecision(2) << "Total amount of withdrawals: $" << witht << endl;
        cout << fixed << setprecision(2) << "Total interest earned: $" << interestt << endl;
    }

    return 0;
}