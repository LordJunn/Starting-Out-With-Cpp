/* Write a program that uses a loop to display Pattern A below, followed by another loop
that displays Pattern B.
Pattern A Pattern B
+         ++++++++++
++         +++++++++
+++         ++++++++
++++         +++++++
+++++         ++++++
++++++         +++++
+++++++         ++++
++++++++         +++
+++++++++         ++
++++++++++         + */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int main() {

    int pattern, pattern2, owo, uwu;

    const int min = 0;

    cout << "Pattern amount?" << endl;
    cin >> pattern;

    cout << "Pattern A:";

    for (int i = min; i < pattern; i++) {
        for (int j = min; j <= i; j++) {
            cout << "+";
        }
        cout << endl;
    }
    
    cout << endl;
    cout << "Pattern B:" << endl;

    for (int k = min; k < pattern; k++) {
        for (int w = pattern; w > k; w--) {
            cout << "+";
        }
        cout << endl;
    }



    return 0;
}