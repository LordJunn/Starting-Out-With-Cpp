/* Write a program that asks the user to enter today’s sales for five stores. The program
should then display a bar graph comparing each store’s sales. Create each bar in the bar
graph by displaying a row of asterisks. Each asterisk should represent $100 of sales.
Here is an example of the program’s output.

Enter today's sales for store 1: 1000 [Enter]
Enter today's sales for store 2: 1200 [Enter]
Enter today's sales for store 3: 1800 [Enter]
Enter today's sales for store 4: 800 [Enter]
Enter today's sales for store 5: 1900 [Enter]

SALES BAR CHART
(Each * = $100)
Store 1: **********
Store 2: ************
Store 3: ******************
Store 4: ********
Store 5: ******************* */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int main() {

    int stars;
    int sales1, sales2, sales3, sales4, sales5;

    cout << "Enter today's sales for store 1:" << endl;
    cin >> sales1;
    cout << "Enter today's sales for store 2:" << endl;
    cin >> sales2;
    cout << "Enter today's sales for store 3:" << endl;
    cin >> sales3;
    cout << "Enter today's sales for store 4:" << endl;
    cin >> sales4;
    cout << "Enter today's sales for store 5:" << endl;
    cin >> sales5;

    cout << "SALES BAR CHART" << endl;
    cout << "(Each * = $100)" << endl;

    cout << "Store 1: ";
    for (int i = 1; (sales1) >= 100; i++) {
        sales1 -= 100;
        cout << "*";
    }
    cout << endl;
    cout << "Store 2: ";
    for (int i = 1; (sales2) >= 100; i++) {
        sales2 -= 100;
        cout << "*";
    }
    cout << endl;
    cout << "Store 3: ";
    for (int i = 1; (sales3) >= 100; i++) {
        sales3 -= 100;
        cout << "*";
    }
    cout << endl;
    cout << "Store 4: ";
    for (int i = 1; (sales4) >= 100; i++) {
        sales4 -= 100;
        cout << "*";
    }
    cout << endl;
    cout << "Store 5: ";
    for (int i = 1; (sales5) >= 100; i++) {
        sales5 -= 100;
        cout << "*";
    }

    return 0;
}