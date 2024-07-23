/* Modify the program you wrote for Programming Challenge 2 (Lottery Winners) so it
performs a binary search instead of a linear search. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

const int lotto = 10;
int binarySearch(const int[], int, int);
int checker(int&, int, int);

int main() {

    int player, winner, winning;
    int lucky[10] = {13579, 26791, 26792, 33445, 55555, 62483, 77777, 79422, 85647, 93121};

    cout << "Enter this week's winning 5-digit number. ";
    winning = checker(winning, 10000, 99999);
    winner = binarySearch(lucky, lotto, winning);
    
    if(winner == -1) {
        cout << "None of the tickets are a winner this week." << endl;
    }
    else {
        cout << "One of the tickets is a winner this week." << endl;
        cout << "It is lucky ticket #" << (winner + 1) << endl;
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

int binarySearch(const int array[], int size, int value) {
    int first = 0,        // First array element
        last = size - 1,  // Last array element
        middle,           // Midpoint of search
        position = -1;    // Position of search value
    bool found = false;   // Flag

    while (!found && first <= last) {
        middle = (first + last) / 2;  // Calculate midpoint
        if (array[middle] == value)   // If value is found at mid
        {
            found = true;
            position = middle;
        } else if (array[middle] > value)  // If value is in lower half
            last = middle - 1;
        else
            first = middle + 1;  // If value is in upper half
    }
    return position;
}
