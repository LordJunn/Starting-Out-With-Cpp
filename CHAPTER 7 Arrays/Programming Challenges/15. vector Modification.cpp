/* Modify the National Commerce Bank case study presented in Program 7-23 so pin1,
pin2, and pin3 are vectors instead of arrays. You must also modify the testPIN
function to accept a vector instead of an array. */

// i dont get wtf happened here but ok

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

// Function Prototype
bool testPIN(vector<int>, vector<int>, int);

int main() {
    const int NUM_DIGITS = 7;                      // Number of digits in a PIN
    vector <int> pin1 = {2, 4, 1, 8, 7, 9, 0};  // Base set of values.
    vector <int> pin2 = {2, 4, 6, 8, 7, 9, 0};  // Only 1 element is
    // different from pin1.
    vector <int> pin3 = {1, 2, 3, 4, 5, 6, 7};  // All elements are
    // different from pin1.
    if (testPIN(pin1, pin2, NUM_DIGITS))
        cout << "ERROR: pin1 and pin2 report to be the same.\n";
    else
        cout << "SUCCESS: pin1 and pin2 are different.\n";

    if (testPIN(pin1, pin3, NUM_DIGITS))
        cout << "ERROR: pin1 and pin3 report to be the same.\n";
    else
        cout << "SUCCESS: pin1 and pin3 are different.\n";

    if (testPIN(pin2, pin3, NUM_DIGITS))
        cout << "SUCCESS: pin2 and pin3 report to be the same.\n";
    else
        cout << "ERROR: pin2 and pin3 report to be different.\n";
    return 0;
}

bool testPIN(vector<int> custPIN, vector<int> databasePIN, int size) {
    for (int index = 0; index < size; index++) {
        if (custPIN[index] != databasePIN[index])
            return false;  // We've found two different values.
    }
    return true;  // If we make it this far, the values are the same.
}
