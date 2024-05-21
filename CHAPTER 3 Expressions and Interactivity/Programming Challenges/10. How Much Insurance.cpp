/* Many financial experts advise that property owners should insure their homes or build-
ings for at least 80 percent of the amount it would cost to replace the structure. Write a
program that asks the user to enter the replacement cost of a building and then displays
the minimum amount of insurance he or she should buy for the property. */

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    
    float home, insurance;
    
    cout << "How much does your home cost (replacement?) ?" << endl;
    cin >> home;

    insurance = home * 0.8;

    cout << "the minimum amount of insurance he or she should buy for the property = $" << insurance << endl;


    return 0;
}