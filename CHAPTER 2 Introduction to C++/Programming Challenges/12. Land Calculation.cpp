/* One acre of land is equivalent to 43,560 square feet. Write a program that calculates
the number of acres in a tract of land with 391,876 square feet. */

#include <iostream>
using namespace std;

int main()
{

    int acre = 43560,
        land = 391876;
    
    float tract = land/acre;

    cout << "Number of acres in a tract of land with " << land << " square feet = " << tract << endl;

return 0;

}
