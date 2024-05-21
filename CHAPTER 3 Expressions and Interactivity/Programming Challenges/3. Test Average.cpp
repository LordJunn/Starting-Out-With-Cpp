/* Write a program that asks for five test scores. The program should calculate the aver-
age test score and display it. The number displayed should be formatted in fixed-point
notation, with one decimal point of precision. */

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    
    int a, b, c, d, e;
    float avg;

    cout << "Test score #1? " << endl;
    cin >> a;
    cout << "Test score #2? " << endl;
    cin >> b;
    cout << "Test score #3? " << endl;
    cin >> c;
    cout << "Test score #4? " << endl;
    cin >> d;
    cout << "Test score #5? " << endl;
    cin >> e;

    avg = (a+b+c+d+e)/5;

    cout << fixed << setprecision(1) << "Average test score: " << avg << endl;


    return 0;
}