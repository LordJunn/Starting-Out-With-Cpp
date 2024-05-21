/* A movie theater only keeps a percentage of the revenue earned from ticket sales. The
remainder goes to the movie distributor. Write a program that calculates a theater’s
gross and net box office profit for a night. The program should ask for the name of the
movie, and how many adult and child tickets were sold. (The price of an adult ticket is
$10.00 and a child’s ticket is $6.00.) It should display a report similar to
Movie Name: “Wheels of Fury”
Adult Tickets Sold: 382
Child Tickets Sold: 127
Gross Box Office Profit: $ 4582.00
Net Box Office Profit: $ 916.40
Amount Paid to Distributor: $ 3665.60

NOTE: Assume the theater keeps 20 percent of the gross box office profit. */

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {

    string name;

    float adultT = 10.00,
          childT = 6.00;

    float adultN, childN, gross, net, dist;

    cout << "Movie name?" << endl;
    getline (cin, name);

    cout << "Adult tickets sold?" << endl;
    cin >> adultN;
    cout << "Child tickets sold?" << endl;
    cin >> childN; 

    gross = (adultT * adultN) + (childT * childN);
    net = gross * 0.20;
    dist = gross - net;

    cout << "Movie Name : ‘" << name << "’" << endl <<
            "Adult Tickets Sold: " << adultN << endl <<
            "Child Tickets Sold: " << childN << endl;

    cout << fixed << setprecision(2) << "Gross Box Office Profit: $ " << gross << endl <<
                                        "Net Box Office Profit: $ " << net << endl <<
                                        "Amount Paid to Distributor: $ " << dist << endl;

    return 0;
}