/* Write a program that uses the following arrays:
• empId: an array of seven long integers to hold employee identification numbers. The
array should be initialized with the following numbers:
5658845 4520125 7895122 8777541 8451277 1302850 7580489
• hours: an array of seven integers to hold the number of hours worked by each
employee
• payRate: an array of seven doubles to hold each employee’s hourly pay rate
• wages: an array of seven doubles to hold each employee’s gross wages
The program should relate the data in each array through the subscripts. For example,
the number in element 0 of the hours array should be the number of hours worked by
the employee whose identification number is stored in element 0 of the empId array.
That same employee’s pay rate should be stored in element 0 of the payRate array.
The program should display each employee number and ask the user to enter that
employee’s hours and pay rate. It should then calculate the gross wages for that
employee (hours times pay rate) and store them in the wages array. After the data has
been entered for all the employees, the program should display each employee’s iden-
tification number and gross wages.
Input Validation: Do not accept negative values for hours or numbers less than 15.00
for pay rate. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

const int MAXSIZE = 7;
int empID[MAXSIZE] = {5658845, 4520125, 7895122, 8777541, 8451277, 1302850, 7580489};

double checker(double&, double); 
void getEmpInfo(const int, const int[], double[], double[], double[]);
void displayEmpInfo(const int, const int[], double[]);

double hours[MAXSIZE],
       payRate[MAXSIZE],
       wages[MAXSIZE];

int main() {

    getEmpInfo(MAXSIZE, empID, hours, payRate, wages);
    displayEmpInfo(MAXSIZE, empID, wages);

    return 0;
}


double checker(double &x, double i) {

    cin >> x;
    while (x <= i) {
        cout << "Enter a bigger number, bigger than " << i << ". ";
        cin.clear();
        cin >> x;
    }

    return x;

}

void getEmpInfo(const int a, const int b[], double c[], double d[], double e[]) {

    for (int i = 0; i < a; i++) {

        cout << "Enter info regarding Employee #" << (i + 1) << ", ID number: " << b[i] << endl;

        cout << "Hours worked by them? ";
        c[i] = checker(c[i], -1);

        cout << "Payrate for them? ";
        d[i] = checker(d[i], 14);

        e[i] = c[i] * d[i];
        cout << endl;
        
    }

}

void displayEmpInfo(const int a, const int b[], double e[]) {

    cout << setprecision(2) << fixed << endl;

    for (int i = 0; i < a; i++) {

        cout << "Total wage for Employee #" << (i + 1) << ", ID number: " << b[i] <<
                " = $" << e[i] << endl;
    }
    cout << endl;

}




