/* To get the average of a series of values, you add the values up and then divide the sum
by the number of values. Write a program that stores the following values in five dif-
ferent variables: 28, 32, 37, 24, and 33. The program should first calculate the sum
of these five variables and store the result in a separate variable named sum. Then, the
program should divide the sum variable by 5 to get the average. Display the average
on the screen. */

// TIP: Use the double data type for all variables in this program.

#include <iostream>
using namespace std;

int main()
{

    double var1 = 28,
           var2 = 32,
           var3 = 37,
           var4 = 24,
           var5 = 33;
           
    double sum = var1 + var2 + var3 + var4 + var5;

    double average = sum/5;

    cout << average << endl;

return 0;

}