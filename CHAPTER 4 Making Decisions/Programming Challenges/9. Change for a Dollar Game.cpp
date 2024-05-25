/* Create a change-counting game that gets the user to enter the number of coins required
to make exactly one dollar. The program should ask the user to enter the number of
pennies, nickels, dimes, and quarters. If the total value of the coins entered is equal to
one dollar, the program should congratulate the user for winning the game. Otherwise,
the program should display a message indicating whether the amount entered was more
than or less than one dollar. */

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main() {

    int p, n, d, q;
    float t;

    cout << "Enter the number of pennies:" << endl;
    cin >> p;
    cout << "Enter the number of nickels:" << endl;
    cin >> n;
    cout << "Enter the number of dimes:" << endl;
    cin >> d;
    cout << "Enter the number of quarters:" << endl;
    cin >> q;    

    t = p + (n*5) + (d*10) + (q*25);

    cout << t << endl;
    if (t > 100) {
        cout << "The amount entered was more than one dollar." << endl;
    }
    else if (t < 100) {
        cout << "The amount entered was less than one dollar." << endl;
    }
    else {
        cout << "You win!" << endl;
    }

    return 0;
}