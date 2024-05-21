/* Last month Joe purchased some stock in Acme Software, Inc. Here are the details of
the purchase:
• The number of shares that Joe purchased was 1,000.
• When Joe purchased the stock, he paid $45.50 per share.
• Joe paid his stockbroker a commission that amounted to 2% of the amount he paid
for the stock.
Two weeks later Joe sold the stock. Here are the details of the sale:
• The number of shares that Joe sold was 1,000.
• He sold the stock for $56.90 per share.
• He paid his stockbroker another commission that amounted to 2% of the amount
he received for the stock.
Write a program that displays the following information:
• The amount of money Joe paid for the stock.
• The amount of commission Joe paid his broker when he bought the stock.
• The amount that Joe sold the stock for.
• The amount of commission Joe paid his broker when he sold the stock.
• Display the amount of profit that Joe made after selling his stock and paying the two
commissions to his broker. (If the amount of profit that your program displays is a
negative number, then Joe lost money on the transaction.) */

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

int main() {
    
    const float commission = 0.02,
                purchase = 45.50,
                sold = 56.90,
                share = 1000;

    float paid1, paid2, com1, com2, profit;

    cout << "Week 1" << endl;
    paid1 = purchase * share;
    com1 = paid1 * commission;
    cout << fixed << setprecision(2) << "The amount of money Joe paid for the stock = $" << paid1 << endl;
    cout << fixed << setprecision(2) << "The amount of commission Joe paid his broker when he bought the stock = $" << com1 << endl;   

    cout << "Week 2" << endl;
    paid2 = sold * share;
    com2 = paid2 * commission;
    cout << fixed << setprecision(2) << "The amount that Joe sold the stock for = $" << paid2 << endl;
    cout << fixed << setprecision(2) << "The amount of commission Joe paid his broker when he sold the stock = $" << com2 << endl;  

    profit = paid2 - (paid1 + com1 + com2);

    cout << fixed << setprecision(2) << 
    "The amount of profit that Joe made after selling his stock and paying the two commissions to his broker = $" 
    << profit << endl;    

    return 0;
}