/* Write a program that lets the user enter a charge account number. The program should
determine if the number is valid by checking for it in the following list:
5658845 4520125 7895122 8777541 8451277 1302850
8080152 4562555 5552012 5050552 7825877 1250255
1005231 6545231 3852085 7576651 7881200 4581002
The list of numbers above should be initialized in a single-dimensional array. A simple
linear search should be used to locate the number entered by the user. If the user enters
a number that is in the array, the program should display a message saying that the
number is valid. If the user enters a number that is not in the array, the program should
display a message indicating that the number is invalid. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int searchList(const int[], int, int);
int checker(int&, int, int); // is checker necessary actually
const int SIZE = 18;

int main() {

    int results, value;
    int numbers[SIZE] = { 5658845, 4520125, 7895122, 8777541, 8451277, 1302850,
                        8080152, 4562555, 5552012, 5050552, 7825877, 1250255,
                        1005231, 6545231, 3852085, 7576651, 7881200, 4581002 };

    cout << "Enter a charge account number. " << endl;
    value = checker(value, 1000000, 9999999);
    results = searchList(numbers, SIZE, value);

    if(results == -1) {
        cout << "The number is invalid." << endl;
    }
    else {
        cout << "The number is valid." << endl;
        cout << "It is found at position #" << (results + 1) << endl;
    }

    return 0;
}

int checker(int &x, int i, int j) {

    cin >> x;
    while (x < i || x > j) {
        cout << "Enter a bigger number, bigger than " << i << ", but smaller than " << j << " .";
        cin.clear();
        cin >> x;
    }

    return x;

}

int searchList(const int list[], int numElems, int value) {
    int index = 0;       // Used as a subscript to search array
    int position = -1;   // To record position of search value
    bool found = false;  // Flag to indicate if the value was found

    while (index < numElems && !found) {
        if (list[index] == value)  // If the value is found
        {
            found = true;      // Set the flag
            position = index;  // Record the value's subscript
        }
        index++;  // Go to the next element
    }
    return position;  // Return the position, or -1
}