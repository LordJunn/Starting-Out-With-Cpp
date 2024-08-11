/* Write a program that uses a structure to store the following data on a company division:
Division Name (such as East, West, North, or South)
Quarter (1, 2, 3, or 4)
Quarterly Sales
The user should be asked for the four quarters’ sales figures for the East, West, North,
and South divisions. The data for each quarter for each division should be written to
a file.

Input Validation: Do not accept negative numbers for any sales figures. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <cctype>
#include <cstring>
#include <fstream>
using namespace std; // stealing from PC3 C11

double checker(double&, int);

struct companyD {
    string division;
    double Q1S;
    double Q2S;
    double Q3S;
    double Q4S;
    double total;
    double avg;
};

int main() {

    const int divisions = 4;
    string corporate[divisions] = {"East", "West", "North", "South"};
    companyD cd[divisions];
    int index;

    // Open a file for binary output.
    fstream company("PC11C12.dat", ios::out | ios::binary); // stealing from 12-15

    // Get data about a division.
    cout << "Enter the details for " << divisions << " divisions." << endl;

    for (index = 0; index < divisions; index++) { 
        cout << "Enter sales figure for " << corporate[index] << " division." << endl;
        
        cout << "First-Quarter Sales? ";
        cd[index].Q1S = checker(cd[index].Q1S, 0);
        cout << "Second-Quarter Sales? ";
        cd[index].Q2S = checker(cd[index].Q2S, 0);
        cout << "Third-Quarter Sales? ";
        cd[index].Q3S = checker(cd[index].Q3S, 0);
        cout << "Fourth-Quarter Sales? ";
        cd[index].Q4S = checker(cd[index].Q4S, 0);

    }

    // Write the contents of the division structure to the file.
    company.write(reinterpret_cast<char *>(&cd), sizeof(cd));

    // Close the file.
    company.close();
    return 0;
}

double checker(double &x, int i) {

    cin >> x;
    while (x < i) {
        cout << "Enter a bigger number, bigger than " << i << " .";
        cin.clear();
        cin >> x;
    }

    return x;

}
