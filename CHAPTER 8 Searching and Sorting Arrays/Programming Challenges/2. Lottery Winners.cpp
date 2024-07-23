/* A lottery ticket buyer purchases 10 tickets a week, always playing the same 10 5-digit
“lucky” combinations. Write a program that initializes an array or a vector with
these numbers and then lets the player enter this week’s winning 5-digit number.
The program should perform a linear search through the list of the player’s numbers
and report whether or not one of the tickets is a winner this week. Here are the
numbers:
13579 26791 26792 33445 55555
62483 77777 79422 85647 93121 */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

const int lotto = 10;
int searchList(const int[], int, int);
int checker(int&, int, int);


int main() {

    int player, winner, winning;
    int lucky[10] = {13579, 26791, 26792, 33445, 55555, 62483, 77777, 79422, 85647, 93121};

    cout << "Enter this week's winning 5-digit number. ";
    winning = checker(winning, 10000, 99999);
    winner = searchList(lucky, lotto, winning);
    
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

