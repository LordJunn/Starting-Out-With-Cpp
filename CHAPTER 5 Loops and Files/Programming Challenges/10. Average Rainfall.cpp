/* Write a program that uses nested loops to collect data and calculate the average rainfall
over a period of years. The program should first ask for the number of years. The outer
loop will iterate once for each year. The inner loop will iterate twelve times, once for
each month. Each iteration of the inner loop will ask the user for the inches of rainfall
for that month.
After all iterations, the program should display the number of months, the total inches
of rainfall, and the average rainfall per month for the entire period.

Input Validation: Do not accept a number less than 1 for the number of years. Do not
accept negative numbers for the monthly rainfall. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int main() { // some stuff stolen from PC4 C3

    float years = 0, 
        inches = 0, 
        months = 0,
        totaly = 0,
        total = 0;
    const int month = 12;
    float avg = 0;

    cout << "Enter the amount of years to check: " << endl;
    cin >> years;

    while (years <= 0) {
        
        cout << "Nooo negative years can't exist!!" << endl;
        cout << "Enter the amount of years to check: " << endl;
        cin >> years;   

    }

    for (int i = 1; i <= years; i++) {

        cout << "Let's figure out the rainfall for year " << i << "." << endl;

        for (int j = 1; j <= month; j++) {

            cout << "Inches of rainfall for year " << i << ", month " << j << " ?" << endl;
            cin >> inches;

            while (inches < 0) {
            
            cout << "That's... very dry." << endl;
            cout << "Inches of rainfall for year " << i << ", month " << j << " ?" << endl;
            cin >> inches;

            }

            totaly += inches;
        }
        total += totaly;
    }

    months = years * 12;
    cout << "Total rainfall for " << months << " months = " << total << endl;

    avg = total/months;
    cout << "Average rainfall for " << months << " months = " << avg << endl;    

    return 0;
}