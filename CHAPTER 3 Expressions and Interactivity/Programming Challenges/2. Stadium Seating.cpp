/* There are three seating categories at a stadium. For a softball game, Class A seats cost
$15, Class B seats cost $12, and Class C seats cost $9. Write a program that asks how
many tickets for each class of seats were sold, then displays the amount of income gen-
erated from ticket sales. Format your dollar amount in fixed-point notation, with two
decimal places of precision, and be sure the decimal point is always displayed. */

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    
    int A = 15,
        B = 12,
        C = 9;

    int aa, bb, cc;
    int as, bs, cs, ts;

    cout << "How many tickets for class A seats were sold? " << endl;
    cin >> aa;
    cout << "How many tickets for class B seats were sold? " << endl;
    cin >> bb;    
    cout << "How many tickets for class C seats were sold? " << endl;
    cin >> cc;

    as = aa * A;
    bs = bb * B;
    cs = cc * C;
    ts = as + bs + cs;

    cout << setprecision(2) << fixed << "Class A tickets sold = $" << as << endl;
    cout << setprecision(2) << fixed << "Class B tickets sold = $" << bs << endl;
    cout << setprecision(2) << fixed << "Class C tickets sold = $" << cs << endl;
    cout << setprecision(2) << fixed << "Total tickets sold = $" << ts << endl;

    return 0;
}