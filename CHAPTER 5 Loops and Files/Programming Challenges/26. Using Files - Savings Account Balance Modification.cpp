/* Modify the Savings Account Balance program described in Programming Challenge 16
so that it writes the final report to a file. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

int main() {

    ifstream input_file;
    ofstream output_file;

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

    output_file.open("Balance.txt");

    if (bal < 0) {
        cout << "Bankrupt!" << endl;
        cout << "Account has been closed!" << endl;
    }
    else {
        cout << fixed << setprecision(2) << "Ending balance: $" << bal << endl;
        cout << fixed << setprecision(2) << "Total amount of deposits: $" << dept << endl;
        cout << fixed << setprecision(2) << "Total amount of withdrawals: $" << witht << endl;
        cout << fixed << setprecision(2) << "Total interest earned: $" << interestt << endl;

        output_file << fixed << setprecision(2) << "Ending balance: $" << bal << endl;
        output_file << fixed << setprecision(2) << "Total amount of deposits: $" << dept << endl;
        output_file << fixed << setprecision(2) << "Total amount of withdrawals: $" << witht << endl;
        output_file << fixed << setprecision(2) << "Total interest earned: $" << interestt << endl;
    }

    output_file.close();

    return 0;
}