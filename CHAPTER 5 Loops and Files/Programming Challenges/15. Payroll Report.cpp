/* Write a program that displays a weekly payroll report. A loop in the program should
ask the user for the employee number, gross pay, state tax, federal tax, and FICA with-
holdings. The loop will terminate when 0 is entered for the employee number. After the
data is entered, the program should display totals for gross pay, state tax, federal tax,
FICA withholdings, and net pay.

Input Validation: Do not accept negative numbers for any of the items entered. Do
not accept values for state, federal, or FICA withholdings that are greater than the
gross pay. If the sum state tax + federal tax + FICA withholdings for any employee is
greater than gross pay, print an error message and ask the user to reenter the data for
that employee. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int main() {

    int empnum, gross = 0,
                grosst = 0, 
                state = 0, 
                statet = 0, 
                federal = 0, federalt = 0,
                fica = 0, ficat = 0, 
                sum = 0, sumt = 0, net = 0, nett = 0;

    cout << "Employee number?" << endl;
    cin >> empnum;

    while (empnum < 0) {
        cout << "No!" << endl;
        cout << "Employee number?" << endl;
        cin >> empnum;          
    }

    while (empnum != 0) {

        cout << "Gross pay?" << endl;
        cin >> gross;

        while (gross <= 0) {
            cout << "No!" << endl;
            cout << "Gross pay?" << endl;
            cin >> gross;  
        }

        cout << "State tax?" << endl;
        cin >> state;

        while (state > gross || state <= 0) {
            cout << "No!" << endl;
            cout << "State tax?" << endl;
            cin >> state;   
        }


        cout << "Federal tax?" << endl;
        cin >> federal;  

        while (federal > gross || federal <= 0) {
            cout << "No!" << endl;
            cout << "Federal tax?" << endl;
            cin >> federal;   
        }    


        cout << "FICA withholdings?" << endl;
        cin >> fica; 

        while (fica > gross || fica <= 0) {
            cout << "No!" << endl;
            cout << "FICA withholdings?" << endl;
            cin >> fica; 
        }

        sum = state + federal + fica;

        while (sum > gross) {
            cout << "No! No! No!" << endl;
            cout << "I'm gonna reset all the values!" << endl;
            state = 0;
            federal = 0;
            fica = 0;
            gross = 0;

            sum = state + federal + fica;
        }
        grosst += gross;
        statet += state;        
        federalt += federal;
        ficat += fica;

        sumt += sum;
        net = gross - sum;
        nett += net;

    cout << "Employee number?" << endl;
    cin >> empnum;

    while (empnum < 0) {
        cout << "No!" << endl;
        cout << "Employee number?" << endl;
        cin >> empnum;          
    }

    }

    cout << "Gross pay: $" << grosst << endl;
    cout << "State tax: $" << statet << endl;
    cout << "Federal tax: $" << federalt << endl;
    cout << "FICA withholdings: $" << ficat << endl;
    cout << "Net pay: $" << nett << endl;

    return 0;
}
