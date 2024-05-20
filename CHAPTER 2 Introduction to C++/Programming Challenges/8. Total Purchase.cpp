/* A customer in a store is purchasing five items. The prices of the five items are
Price of item 1 = $15.95
Price of item 2 = $24.95
Price of item 3 = $6.95
Price of item 4 = $12.95
Price of item 5 = $3.95

Write a program that holds the prices of the five items in five variables. Display each
item’s price, the subtotal of the sale, the amount of sales tax, and the total. Assume the
sales tax is 7%. */

#include <iostream>
using namespace std;

int main()
{

    float item1 = 15.95,
          item2 = 24.95,
          item3 = 6.95,
          item4 = 12.95,
          item5 = 3.95;
        
    cout << "Price of item 1 = $" << item1 << endl;
    cout << "Price of item 2 = $" << item2 << endl;
    cout << "Price of item 3 = $" << item3 << endl;
    cout << "Price of item 4 = $" << item4 << endl;
    cout << "Price of item 5 = $" << item5 << endl << endl;

    float subtotal = item1 + item2 + item3 + item4 + item5;
    cout << "Subtotal of the sale = $" << subtotal << endl << endl;

    float salestax = subtotal * 0.07;
    cout << "Amount of sales tax = $" << salestax << endl << endl;  

    float total = salestax + subtotal;
    cout << "Total = $" << total << endl << endl;        

return 0;

}