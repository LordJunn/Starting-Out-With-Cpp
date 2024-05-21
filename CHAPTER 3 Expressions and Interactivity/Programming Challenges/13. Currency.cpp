/* Write a program that will convert U.S. dollar amounts to Japanese yen and to euros,
storing the conversion factors in the constants YEN_PER_DOLLAR and EUROS_PER_
DOLLAR. To get the most up-to-date exchange rates, search the Internet using the
term “currency exchange rate”. If you cannot find the most recent exchange rates, use
the following:
1 Dollar = 98.93 Yen
1 Dollar = 0.74 Euros
Format your currency amounts in fixed-point notation, with two decimal places of
precision, and be sure the decimal point is always displayed. */

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {

    const float YEN_PER_DOLLAR   = 154.42, // as of 16/5/2024 waduhell
                EUROS_PER_DOLLAR = 0.92;   

    float usd, yen, euro;

    cout << "Enter the U.S. dollar amounts you want to convert to Japanese yen and to euros" << endl;
    cin >> usd;

    yen = usd * YEN_PER_DOLLAR;
    euro = usd * EUROS_PER_DOLLAR;

    cout << fixed << setprecision(2) << "Japanese yen per " << usd << " U.S. dollar = " << yen << endl;
    cout << fixed << setprecision(2) << "Euros per " << usd << " U.S. dollar = " << euro << endl;    

    return 0;
}