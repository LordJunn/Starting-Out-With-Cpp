/* Use the function that you wrote for Programming Challenge 20 (Stock Profit) in a
program that calculates the total profit or loss from the sale of multiple stocks. The
program should ask the user for the number of stock sales and the necessary data for
each stock sale. It should accumulate the profit or loss for each stock sale and then
display the total */

// mostly stolen from PC20 C6
#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int checker(int&, int);
void info(string, int&); // stolen from site
int calc(int, int, int, int, int);
void profloss(int);
void profloss(int, int); // stolen from site

int main() {

    int stocks, num, purchaseP, purchaseC, saleP, saleC, sale, sales;

    cout << "Number of stocks bought? ";
    stocks = checker(stocks, 0);

    for (int i = 1; i <= stocks; i++) {

        cout << "Checking for stock #" << i << "..." << endl;

        info("Number of shares? ", num);
        info("The purchase price per share?  ", purchaseP);
        info("The purchase commission paid? ", purchaseC);
        info("The sale price per share?  ", saleP);
        info("The sale commission paid? ", saleC);

        sale = calc(num, purchaseP, purchaseC, saleP, saleC);
        sales += sale;

        profloss(sale, i);
        cout << endl << endl;
    }
    cout << endl << endl << endl;
    profloss(sales);

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


void info(string prompt, int &type) {
    cout << prompt;
    type = checker(type, 0);
}


int calc(int NS, int PP, int PC, int SP, int SC) {

    int profit;
    profit = ((NS * SP) - SC ) - ((NS * PP) + PC );
    return profit;

}

void profloss(int sale, int i) {

    if (sale > 0) {
        cout << "It is a profit for stock " << i << "! You made $" << sale << "!!";
    }
    else if (sale == 0) {
        cout << "It is a draw for stock " << i << ", you just broke even.";
    }
    else {
        sale = abs(sale);
        cout << "It is a loss for stock " << i << "! You lost $" << sale << "!!";
    }

}

void profloss(int sale) {
    
    cout << "In conclusion..." << endl;

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

}
