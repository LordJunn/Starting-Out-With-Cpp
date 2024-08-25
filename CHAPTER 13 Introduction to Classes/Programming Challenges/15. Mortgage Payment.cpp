/* Design a class that will determine the monthly payment on a home mortgage. The
monthly payment with interest compounded monthly can be calculated as follows:

Payment = [Loan x (Rate/12) x Term]/(Term - 1)

where Term = [1 + (Rate/12)]^(12 x Years)

Payment = the monthly payment
Loan = the dollar amount of the loan
Rate = the annual interest rate
Years = the number of years of the loan
The class should have member functions for setting the loan amount, interest rate, and
number of years of the loan. It should also have member functions for returning the
monthly payment amount and the total amount paid to the bank at the end of the loan
period. Implement the class in a complete program.
Input Validation: Do not accept negative numbers for any of the loan values. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <cctype>
#include <cstring>
#include <fstream>
using namespace std;

class Mortgage {
   private:
    double payment, loan, term, rate, years;

   public:
    // Setter methods
    void setPayment(double p) {
        payment = p;
    }

    void setLoan(double l) {
        loan = l;
    }

    void setTerm(double t) {
        term = t;
    }

    void setRate(double r) {
        rate = r;
    }

    void setYears(double y) {
        years = y;
    }

    // Getter methods
    double showPayment() {
        return payment;
    }

    double showLoan() {
        return loan;
    }

    double showTerm() {
        return term;
    }

    double showRate() {
        return rate;
    }

    double showYears() {
        return years;
    }

    double calcMonthly() {
        payment = ((loan*((rate / 12) / 100)*term)/(term - 1));
        setPayment(payment);
        return payment;
    }

    double calcTerm() {
        double r = (rate / 12) / 100; // Monthly interest rate
        term = pow(1 + r, 12 * years); // Compute term
        setTerm(term);
        return term;
    }

};

double checker(double&, double);

int main() {

    Mortgage home;

    double p, l, t, r, y;

    cout << "How much was the loan amount? ";
    l = checker(l, 0);
    home.setLoan(l);

    cout << "How much was the interest rate? ";
    r = checker(r, 0);
    home.setRate(r);

    cout << "How many years was the loan? ";
    y = checker(y, 0);
    home.setYears(y);

    t = home.calcTerm();
    p = home.calcMonthly();

    cout << "Total monthly payments per month: $" << p << endl;

    return 0;
}

/*
The class should have member functions for setting the loan amount, interest rate, and
number of years of the loan. It should also have member functions for returning the
monthly payment amount and the total amount paid to the bank at the end of the loan
period. Implement the class in a complete program.
Input Validation: Do not accept negative numbers for any of the loan values.
*/

double checker(double &x, double i) {

    cin >> x;
    while (x < i) {
        cout << "Enter a bigger number, bigger than " << i << ". ";
        cin.clear();
        cin >> x;
    }

    return x;

}