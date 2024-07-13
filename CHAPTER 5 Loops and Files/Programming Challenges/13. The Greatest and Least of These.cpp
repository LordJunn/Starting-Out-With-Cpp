/* Write a program with a loop that lets the user enter a series of integers. The user should
enter −99 to signal the end of the series. After all the numbers have been entered, the
program should display the largest and smallest numbers entered. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int main() {

    int largest, smallest;
    int value = 0;

    while (value != -99) {
        cout << "Enter an integer: ";
        cin >> value;

        if (value > largest && value != -99) {
            largest = value;
        }
        if (value < smallest && value != -99) {
            smallest = value;
        }        
    }

    cout << largest << endl;
    cout << smallest << endl;

    return 0;
}