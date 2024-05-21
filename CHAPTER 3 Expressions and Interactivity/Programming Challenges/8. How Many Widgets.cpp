/* The Yukon Widget Company manufactures widgets that weigh 12.5 pounds each.
Write a program that calculates how many widgets are stacked on a pallet, based on
the total weight of the pallet. The program should ask the user how much the pallet
weighs by itself and with the widgets stacked on it. It should then calculate and display
the number of widgets stacked on the pallet. */

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    
    float widget = 12.5;
    float pallet, weight, number;

    cout << "How much the pallet weighs by itself?" << endl;
    cin >> pallet;

    cout << "How much does it weigh witht he widgets stacked on it?" << endl;
    cin >> weight;

    number = (weight - pallet)/widget;

    cout << "Number of widgets stacked on the pallet = " << number << endl;

    return 0;
}

