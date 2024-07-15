/* Modify Programming Challenge 15, Overloaded Hospital, to write the report it creates
to a file. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <fstream> // stolen from PC26 C5
using namespace std;

// entire program generally stolen from PC15 C6
int checker(int&, int);
char choice(char);

// stolen from site
double calculateTotalCharges(double, double, double, double);
double calculateTotalCharges(double, double);

int main() {

    ofstream output_file;    

    char letter;
    int days, rate, medCharge, serCharge, total;

    cout << "Select 1 if the patient was admitted as an in-patient or 2 if an out-patient." << endl;
    letter = choice(letter);

    output_file.open("Hospital Report.txt");

    if (letter == '1') {

        output_file << "Category: In-patient." << endl << endl;

        cout << "The number of days spent in the hospital? ";
        days = checker(days, -1);
        cout << "The daily rate? ";
        rate = checker(rate, -1);
        cout << "Hospital medication charges? ";
        medCharge = checker(medCharge, -1);
        cout << "Charges for hospital services (lab tests, etc.)? ";
        serCharge = checker(serCharge, -1);

        total = calculateTotalCharges(days, rate, medCharge, serCharge);

        output_file << "The number of days spent in the hospital: " << days << endl;
        output_file << "The daily rate: " << rate << endl;
        output_file << "Hospital medication charges: " << medCharge << endl;
        output_file << "Charges for hospital services (lab tests, etc.) " << serCharge << endl;

    }
    else {

        output_file << "Category: Out-patient." << endl << endl;

        cout << "Hospital medication charges? ";
        medCharge = checker(medCharge, -1);
        cout << "Charges for hospital services (lab tests, etc.)? ";
        serCharge = checker(serCharge, -1);

        total = calculateTotalCharges(medCharge, serCharge);

        output_file << "Hospital medication charges: " << medCharge << endl;
        output_file << "Charges for hospital services (lab tests, etc.) " << serCharge << endl;

    }

    cout << "Total charges: $" << total;

    output_file << "Total charges: $" << total;
    output_file.close();

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

