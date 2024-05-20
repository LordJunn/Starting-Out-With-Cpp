/* An electronics company sells circuit boards at a 35 percent profit. Write a program that
will calculate the selling price of a circuit board that costs $14.95. Display the result
on the screen. */

#include <iostream>
using namespace std;

int main()
{

    float cost = 14.95,
          profit = 0.35,
          price = cost * 0.35;

    cout << "price = $" << cost + price << endl;    

return 0;

}
