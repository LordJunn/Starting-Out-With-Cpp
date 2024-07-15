/* Write a program that computes and displays the charges for a patient’s hospital stay.
First, the program should ask if the patient was admitted as an in-patient or an out-
patient. If the patient was an in-patient, the following data should be entered:
• The number of days spent in the hospital
• The daily rate
• Hospital medication charges
• Charges for hospital services (lab tests, etc.)
The program should ask for the following data if the patient was an out-patient:
• Charges for hospital services (lab tests, etc.)
• Hospital medication charges
The program should use two overloaded functions to calculate the total charges. One
of the functions should accept arguments for the in-patient data, while the other func-
tion accepts arguments for out-patient information. Both functions should return the
total charges.

Input Validation: Do not accept negative numbers for any data. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int checker(int&, int);
char choice(char);

// stolen from site
double calculateTotalCharges(double, double, double, double);
double calculateTotalCharges(double, double);

int main() {

    char letter;
    int days, rate, medCharge, serCharge, total;

    cout << "Select 1 if the patient was admitted as an in-patient or 2 if an out-patient." << endl;
    letter = choice(letter);

    if (letter == '1') {

        cout << "The number of days spent in the hospital? ";
        days = checker(days, -1);
        cout << "The daily rate? ";
        rate = checker(rate, -1);
        cout << "Hospital medication charges? ";
        medCharge = checker(medCharge, -1);
        cout << "Charges for hospital services (lab tests, etc.)? ";
        serCharge = checker(serCharge, -1);

        total = calculateTotalCharges(days, rate, medCharge, serCharge);

    }
    else {

        cout << "Hospital medication charges? ";
        medCharge = checker(medCharge, -1);
        cout << "Charges for hospital services (lab tests, etc.)? ";
        serCharge = checker(serCharge, -1);

        total = calculateTotalCharges(medCharge, serCharge);

    }

    cout << "Total charges: $" << total;

    return 0;
}

int checker(int &x, int i) {

    cin >> x;
    while (x <= i) {
        cout << "Enter a bigger number, bigger than " << i << ". ";
        cin >> x;
    }

    return x;

}


char choice(char letter) {

    cin >> letter;

    while (!((letter == '1') || (letter == '2'))) {
        cout << "1 or 2 please. ";
        cin >> letter;
    }
    return letter;

}

// not stolen from site
double calculateTotalCharges(double d, double r, double m, double s) {

    int total;

    total = (d * r) + m + s;

    return total;

}

double calculateTotalCharges(double m, double s) {

    int total;

    total = m + s;

    return total;

}