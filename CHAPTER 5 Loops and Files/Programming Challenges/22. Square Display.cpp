/* Write a program that asks the user for a positive integer no greater than 15. The pro-
gram should then display a square on the screen using the character ‘X’. The number
entered by the user will be the length of each side of the square. For example, if the
user enters 5, the program should display the following:
XXXXX
XXXXX
XXXXX
XXXXX
XXXXX
If the user enters 8, the program should display the following:
XXXXXXXX
XXXXXXXX
XXXXXXXX
XXXXXXXX
XXXXXXXX
XXXXXXXX
XXXXXXXX
XXXXXXXX */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int main() {

    int square;

    cout << "Positive integer no greater than 15?" << endl;
    cin >> square;

    while (square > 15) {
        cout << "Blud did not listen. \nPositive integer no greater than 15?" << endl;
        cin >> square;
    }

    for (int i = 1; i <= square; i++) {
        
        for (int j = 1; j <= square; j++) {
            cout << "X";
        }
        cout << endl;
    }

    return 0;
}