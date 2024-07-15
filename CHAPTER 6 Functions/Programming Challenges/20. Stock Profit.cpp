/* The profit from the sale of a stock can be calculated as follows:
Profit = ((NS x SP ) - SC ) - ((NS x PP ) + PC )
where NS is the number of shares, SP is the sale price per share, SC is the sale commis-
sion paid, PP is the purchase price per share, and PC is the purchase commission paid.
If the calculation yields a positive value, then the sale of the stock resulted in a profit.
If the calculation yields a negative number, then the sale resulted in a loss.
Write a function that accepts as arguments the number of shares, the purchase price per
share, the purchase commission paid, the sale price per share, and the sale commission
paid. The function should return the profit (or loss) from the sale of stock.
Demonstrate the function in a program that asks the user to enter the necessary data
and displays the amount of the profit or loss. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int checker(int&, int);
int calc(int, int, int, int, int);

int main() {

    int num, purchaseP, purchaseC, saleP, saleC, sale;

    cout << "Number of shares? ";
    num = checker(num, 0);
    cout << "The purchase price per share? ";
    purchaseP = checker(purchaseP, 0);    
    cout << "The purchase commission paid? ";
    purchaseC = checker(purchaseC, 0); 
    cout << "The sale price per share? ";
    saleP = checker(saleP, 0);    
    cout << "The sale commission paid? ";
    saleC = checker(saleC, 0);

    sale = calc(num, purchaseP, purchaseC, saleP, saleC);

    if (sale > 0) {
        cout << "It is a profit! You made $" << sale << "!!";
    }
    else if (sale == 0) {
        cout << "It is a draw, you just broke even.";
    }
    else {
        sale = abs(sale);
        cout << "It is a loss! You lost $" << sale << "!!";
    }

    return 0;
}

int checker(int &x, int i) {

    cin >> x;
    while (x <= i) {
        cout << "Enter a bigger number, bigger than " << i << ". ";
        cin >> x;
    }

    return x;

}

int calc(int NS, int PP, int PC, int SP, int SC) {

    int profit;
    profit = ((NS * SP) - SC ) - ((NS * PP) + PC );
    return profit;

}



