/* Write a program that determines which of a company’s four divisions (Northeast,
Southeast, Northwest, and Southwest) had the greatest sales for a quarter. It should
include the following two functions, which are called by main.

• double getSales() is passed the name of a division. It asks the user for a division’s
quarterly sales figure, validates the input, then returns it. It should be called once for
each division.
• void findHighest() is passed the four sales totals. It determines which is the larg-
est and prints the name of the high grossing division, along with its sales figure.

Input Validation: Do not accept dollar amounts less than $0.00. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

const string NE = "North East",
             NW = "North West",
             SE = "South East",
             SW = "South West";

double positive(double sales);
double getSales(string);
void findHighest(double, double, double, double);
void checkIfHighest(double, double, double, double, string);

int main() {

    double NES, SES, NWS, SWS;

    NES = getSales(NE);
    SES = getSales(SE);
    NWS = getSales(NW);
    SWS = getSales(SW);

    cout << endl;

    findHighest(NES, SES, NWS, SWS);

    return 0;
}

double positive(double sales) {

    cin >> sales;
    while (sales <= 0) {
        cout << "Positive numbers only please. ";
        cin >> sales;
    }
    return sales;

}

double getSales(string division) {

    double sales;
    cout << "Quarterly sales figure for " << division << "? ";
    sales = positive(sales);

    return sales;

}

void findHighest(double NES, double NWS, double SES, double SWS)
{
    cout << "The highest grossing division is... ";

    checkIfHighest(NES, NWS, SES, SWS, NE);
    checkIfHighest(NWS, NES, SES, SWS, NW);
    checkIfHighest(SES, NES, NWS, SWS, SE);
    checkIfHighest(SWS, NES, NWS, SES, SW);
  
    cout << endl << endl;
}

void checkIfHighest(double sales1, double sales2, double sales3, double sales4, string division)
{
   if ((sales1 > sales2) && (sales1 > sales3) && (sales1 > sales4))
   {
    cout << division << " with a sales figure at: $" << sales1 << endl;
   }
   
}