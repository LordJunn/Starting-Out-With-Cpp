/* Assuming the ocean’s level is currently rising at about 1.5 millimeters per year, write
a program that displays:

• The number of millimeters higher than the current level that the ocean’s level will be
in 5 years

• The number of millimeters higher than the current level that the ocean’s level will be
in 7 years

• The number of millimeters higher than the current level that the ocean’s level will be
in 10 years */

#include <iostream>
using namespace std;

int main()
{

    float rise = 1.5;
    
    cout << "Ocean level in 5 years: + " << rise * 5 << " mm" << endl;    
    cout << "Ocean level in 7 years: + " << rise * 7 << " mm" << endl;   
    cout << "Ocean level in 10 years: + " << rise * 10 << " mm" << endl;       

return 0;

}
