/* The following table lists the freezing and boiling points of several substances. Write a
program that asks the user to enter a temperature and then shows all the substances
that will freeze at that temperature and all that will boil at that temperature. For exam-
ple, if the user enters −20 the program should report that water will freeze and oxygen
will boil at that temperature.

Substance        Freezing Point (°F)    Boiling Point (°F)
Ethyl alcohol    -173                   172
Mercury          -38                    676
Oxygen           -362                   -306
Water            32                     212 */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int main() {

    const float eaf = -173, eab = 172,
                mf = -38, mb = 676,
                of = -362, ob = -306,
                wf = 32, wb = 212;

    float temp;

    cout << "Enter a temperature: " << endl;
    cin >> temp;

    if (temp < eaf) {
        cout << "Ethyl alcohol will freeze." << endl;
    }
    else if (temp >= eaf && temp <= eab) {

    }
    else {
        cout << "Ethyl alcohol will boil." << endl;
    }

    if (temp < mf) {
        cout << "Mercury will freeze." << endl;
    }
    else if (temp >= mf && temp <= mb) {

    }
    else {
        cout << "Mercury will boil." << endl;
    }
    
    if (temp < of) {
        cout << "Oxygen will freeze." << endl;
    }
    else if (temp >= of && temp <= ob) {

    }
    else {
        cout << "Oxygen will boil." << endl;
    }

    if (temp < wf) {
        cout << "Water will freeze." << endl;
    }
    else if (temp >= wf && temp <= wb) {

    }
    else {
        cout << "Water will boil." << endl;
    }

    return 0;
}