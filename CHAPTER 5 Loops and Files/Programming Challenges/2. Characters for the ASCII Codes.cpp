/* Write a program that uses a loop to display the characters for the ASCII codes 0
through 127. Display 16 characters on each line. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int main() {

    char ascii;

    for (int i = 0; i <= 127; i++) {
        ascii = i;
        cout << ascii << " ";

        if (i % 16 == 0) {
            cout << endl;
        }

    }

    return 0;
}