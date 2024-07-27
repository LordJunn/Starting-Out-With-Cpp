/* The following function uses reference variables as parameters. Rewrite the function so
it uses pointers instead of reference variables, and then demonstrate the function in a
complete program.

int doSomething(int &x, int &y)
{
    int temp = x;
    x = y * 10;
    y = temp * 10;
    return x + y;
} 

*/

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int doSomething(int *, int *);

int main() {

    int owo, uwu;

    cout << "Enter a number: ";
    cin >> owo;

    int x = owo, 
        *y = &x,
        *z = &x;
        
    cout << endl;
    uwu = doSomething(y, z);

    cout << "I did something, it came out as: " << uwu << endl;

    return 0;
}

int doSomething(int *a, int *b) {

    int temp = *a;
    cout << "Value of temp: " << temp << endl;
    *a = *b * 10;
    cout << "Value of *a: " << *a << endl;
    *b = temp * 10;
    cout << "Value of *b: " << *b << endl;    
    return *a + *b;
    cout << endl;

}