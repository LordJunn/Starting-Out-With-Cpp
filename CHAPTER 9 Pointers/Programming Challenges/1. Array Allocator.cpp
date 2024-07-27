/* Write a function that dynamically allocates an array of integers. The function should
accept an integer argument indicating the number of elements to allocate. The function
should return a pointer to the array. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int main() {

    int *integers = nullptr,
        numbers,
        amount,
        count;

    cout << "How many numbers do you wish to put into the array? ";
    cin >> amount;

    integers = new int[amount];

    cout << "Enter the numbers below:" << endl;
    for (count = 0; count < amount; count++) {
        cout << "Number #" << (count + 1) << ": ";
        cin >> integers[count];
    }    

    cout << "Displaying the contents of the array: ";
    for (int i = 0; i < amount; i++) {
        cout << *(integers + i) << " ";
    }

    delete[] integers;
    integers = nullptr;

    return 0;
}       