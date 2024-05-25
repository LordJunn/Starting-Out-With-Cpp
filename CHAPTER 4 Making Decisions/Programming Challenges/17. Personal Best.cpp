/* Write a program that asks for the name of a pole vaulter and the dates and vault
heights (in meters) of the athlete’s three best vaults. It should then report, in order of
height (best first), the date on which each vault was made and its height.

Input Validation: Only accept values between 2.0 and 5.0 for the heights. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int main() {

    const float vaultmi = 2.0,
                vaultma = 5.0;

    string name, date1, date2, date3, d1, d2, d3;
    float vault1, vault2, vault3, place1, place2, place3;  

    cout << "Name?" << endl;
    cin >> name;

    cout << "Date of first vault?" << endl;
    cin >> date1;
    cout << "Height of first vault?" << endl;
    cin >> vault1;
    cout << "Date of second vault?" << endl;
    cin >> date2;
    cout << "Height of second vault?" << endl;
    cin >> vault2;    
    cout << "Date of third vault?" << endl;
    cin >> date3;
    cout << "Height of third vault?" << endl;
    cin >> vault3;

    if ((vault1 > vaultmi || vault1 < vaultma) || (vault2 > vaultmi || vault2 < vaultma) || (vault3 > vaultmi || vault3 < vaultma)) {

        if (vault1 < vault2 && vault1 < vault3) {

            if (vault2 < vault3) {
                place1 = vault1;
                d1 = date1;
                place2 = vault2;
                d2 = date2;
                place3 = vault3;
                d3 = date3;
            }
            else {
                place1 = vault1;
                d1 = date1;
                place2 = vault3;
                d2 = date3;
                place3 = vault2;
                d3 = date2;
            }

        }
        else if (vault2 < vault3 && vault2 < vault1) {

            if (vault1 < vault3) {
                place1 = vault2;
                d1 = date2;
                place2 = vault1;
                d2 = date1;
                place3 = vault3;
                d3 = date3;
            }
            else {
                place1 = vault2;
                d1 = date2;
                place2 = vault3;
                d2 = date3;
                place3 = vault1;
                d3 = date1;
            }

        }
        else {

            if (vault1 < vault2) {
                place1 = vault3;
                d1 = date3;
                place2 = vault1;
                d2 = date1;
                place3 = vault2;
                d3 = date2;
            }
            else {
                place1 = vault3;
                d1 = date3;
                place2 = vault1;
                d2 = date1;
                place3 = vault2;
                d3 = date2;            
            }
        }

    cout << "Height 1 = " << vault1 << ". Date = " << date1 << endl;
    cout << "Height 2 = " << vault2 << ". Date = " << date2 << endl;
    cout << "Height 3 = " << vault3 << ". Date = " << date3 << endl;

    cout << place1 << " " << d1 << endl;
    cout << place2 << " " << d2 << endl;    
    cout << place3 << " " << d3 << endl;

    }

    else {
        cout << "???" << endl;
    }

    return 0;
}