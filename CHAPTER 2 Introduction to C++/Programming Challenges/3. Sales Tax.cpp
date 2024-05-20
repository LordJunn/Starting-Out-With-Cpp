/*  Write a program that will compute the total sales tax on a $95 purchase. Assume the
state sales tax is 4 percent and the county sales tax is 2 percent. */

#include <iostream>
using namespace std;

int main()
{

    float item = 95;
    float stateSalesTax = item * 0.04;
    float countrySalesTax = item * 0.02;

    float totalSalesTax = stateSalesTax + countrySalesTax;

    cout << "Total Tax = " << stateSalesTax << " + " << countrySalesTax << endl;

    cout << totalSalesTax << endl;

    float itemPostSales = item - totalSalesTax;

    cout << itemPostSales << endl;

return 0;

}