/* Write a program that computes the tax and tip on a restaurant bill for a patron with
a $88.67 meal charge. The tax should be 6.75 percent of the meal cost. The tip should
be 20 percent of the total after adding the tax. Display the meal cost, tax amount, tip
amount, and total bill on the screen. */

#include <iostream>
using namespace std;

int main()
{

    auto meal = 88.67;
    cout << "Meal cost = " << meal << endl;

    auto tax = meal * 0.0675;
    cout << "Tax amount = " << tax << endl;

    auto mealTaxed = meal + tax;
    
    auto tip = mealTaxed * 0.20;
    cout << "Tip amount = " << tip << endl;    

    auto bill = mealTaxed + tip;
    cout << "Total bill = " << bill << endl << endl;   

return 0;

}