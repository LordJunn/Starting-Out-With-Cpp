/* A retail company must file a monthly sales tax report listing the sales for the month and
the amount of sales tax collected. Write a program that asks for the month, the year,
and the total amount collected at the cash register (that is, sales plus sales tax). Assume
the state sales tax is 4 percent and the county sales tax is 2 percent.
If the total amount collected is known and the total sales tax is 6 percent, the amount
of product sales may be calculated as:
S = T/1.06
S is the product sales and T is the total income (product sales plus sales tax).
The program should display a report similar to
Month: October
--------------------
Total Collected: $ 26572.89
Sales: $ 25068.76
County Sales Tax: $ 501.38
State Sales Tax: $ 1002.75
Total Sales Tax: $ 1504.13 */

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {

    const float STATE_SALES_TAX  = 0.04,
                COUNTY_SALES_TAX = 0.02,
                SALES_TAX        = 0.06;

    string month, year;
    float total, sales, country, state, tax;

    cout << "Whats the month?" << endl;
    cin >> month;
    cout << "Whats the year?" << endl;
    cin >> year;

    cout << "Total amount collected at the cash register?" << endl;
    cin >> total;

    sales = total/1.06;
    country = sales * COUNTY_SALES_TAX;
    state = sales * STATE_SALES_TAX;
    tax = sales * SALES_TAX;
    
    cout << "Month: " << month << endl;
    cout << "Year: " << year << endl;    
    cout << "--------------------" << endl;
    cout << fixed << setprecision(2) << "Total Collected:   $" << total << endl
                                     << "Sales:             $" << sales << endl
                                     << "Country Sales Tax: $" << country << endl         
                                     << "State Sales Tax:   $" << state << endl
                                     << "Total Sales Tax:   $" << tax << endl;         

    return 0;
}