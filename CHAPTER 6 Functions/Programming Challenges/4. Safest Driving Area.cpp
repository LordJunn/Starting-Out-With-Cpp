/* Write a program that determines which of five geographic regions within a major city
(north, south, east, west, and central) had the fewest reported automobile accidents last
year. It should have the following two functions, which are called by main.

• int getNumAccidents() is passed the name of a region. It asks the user for the
number of automobile accidents reported in that region during the last year, vali-
dates the input, then returns it. It should be called once for each city region.
• void findLowest() is passed the five accident totals. It determiNNs which is the
smallest and prints the name of the region, along with its accident figure.

Input Validation: Do not accept an accident number that is less than 0. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

const string NN = "North",
             SS = "South",
             EE = "East",
             WW = "West",
             CC = "Central";

double positive(double accidents);
int getNumAccidents(string);
void findLowest(double, double, double, double, double);
void checkIfLowest(double, double, double, double, double, string);

int main() { // proudly stolen from PC3 C6

    double NNS, SSS, EES, WWS, CCS;

    NNS = getNumAccidents(NN);
    SSS = getNumAccidents(SS);
    EES = getNumAccidents(EE);
    WWS = getNumAccidents(WW);
    CCS = getNumAccidents(CC);

    cout << endl;

    findLowest(NNS, SSS, EES, WWS, CCS);

    return 0;
}

double positive(double accidents) {

    cin >> accidents;
    while (accidents < 0) {
        cout << "Positive numbers (or 0) only please. ";
        cin >> accidents;
    }
    return accidents;

}

int getNumAccidents(string region) {

    double accidents;
    cout << "Accidents figure during the last year for " << region << "? ";
    accidents = positive(accidents);

    return accidents;

}

void findLowest(double NNS, double SSS, double EES, double WWS, double CCS)
{
    cout << "The lowest accident prone region is... ";

    if ((NNS == SSS) && (NNS == EES) && (NNS == WWS) && (NNS == CCS)) {
        cout << endl << "It's... a tie??" << endl;
        exit;
    }

    checkIfLowest(NNS, SSS, EES, WWS, CCS, NN);
    checkIfLowest(SSS, NNS, EES, WWS, CCS, SS);
    checkIfLowest(EES, NNS, SSS, WWS, CCS, EE);
    checkIfLowest(WWS, NNS, SSS, EES, CCS, WW);
    checkIfLowest(CCS, NNS, SSS, EES, WWS, CC);
  
    cout << endl << endl;
}


void checkIfLowest(double accidents1, double accidents2, double accidents3, double accidents4, double accidents5, string division)
{
   if ((accidents1 < accidents2) && (accidents1 < accidents3) && (accidents1 < accidents4) && (accidents1 < accidents5))
   {
    cout << division << ", with an accidents figure of: " << accidents1 << endl;
   }
   
}
