/* Kathryn bought 750 shares of stock at a price of $35.00 per share. She must pay her
stockbroker a 2 percent commission for the transaction. Write a program that calcu-
lates and displays the following:
• The amount paid for the stock alone (without the commission)
• The amount of the commission
• The total amount paid (for the stock plus the commission) */

#include <iostream>
using namespace std;

int main()
{

    int share = 35,
        amount = 750,
        stock = share * amount;
    
    cout << stock << endl;

    float commission = stock * 0.02;

    cout << commission << endl;

    float paid = stock + commission;

    cout << paid << endl;

return 0;

}