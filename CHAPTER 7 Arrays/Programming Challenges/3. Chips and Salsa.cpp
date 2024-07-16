/* Write a program that lets a maker of chips and salsa keep track of sales for five differ-
ent types of salsa: mild, medium, sweet, hot, and zesty. The program should use two
parallel 5-element arrays: an array of strings that holds the five salsa names and
an array of integers that holds the number of jars sold during the past month for each
salsa type. The salsa names should be stored using an initialization list at the time the
name array is created. The program should prompt the user to enter the number of jars
sold for each type. Once this sales data has been entered, the program should produce
a report that displays sales for each salsa type, total sales, and the names of the highest
selling and lowest selling products.

Input Validation: Do not accept negative values for number of jars sold. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int checker(int&, int); 
int getValues(const string names[], int values[]);
string larger(const string names[], int values[]); // damn i need double thingys in there
string smaller(const string names[], int values[]);

const int FLAVOURS = 5;
string levels[FLAVOURS] = {"Mild", "Medium", "Sweet", "Hot", "Zesty"};
int sales[FLAVOURS];

int main() {

    int smallerv = 0;

    int total = getValues(levels, sales);
    cout << "Total sales (jars) = " << total << endl << endl;

    for (int i = 0; i < FLAVOURS; i++) {
        cout << "Sales (jars) for salsa type: " << levels[i] << " = " << sales[i] << endl;
    }
    cout << endl;

    string largest = larger(levels, sales);
    cout << "Highest sales = " << largest << endl;
    string smallest = smaller(levels, sales);
    cout << "Lowest sales = " << smallest << endl;


    return 0;
}

int checker(int &x, int i) {

    cin >> x;
    while (x <= i) {
        cout << "Enter a bigger number, bigger than " << i << ". ";
        cin.clear();
        cin >> x;
    }

    return x;

}

int getValues(const string names[], int values[]) {

    int total = 0;

    for (int i = 0; i < FLAVOURS; i++) {
        cout << "Enter the amount of jars sold during the past month for salsa type: " << names[i] << endl;
        values[i] = checker(values[i], -1);
        total += values[i];
    }

    return total;
}

string larger(const string names[], int values[]) {

    int lcount = 0;
    int larger = values[0];
    string largern = names[0];

    for (int i = 1; i < FLAVOURS; i++)
    {
        if (values[i] > larger) {
            larger = values[i];
            largern = names[i];
            lcount++;
        }
        else if (values[i] == larger) {
            larger = values[i];
            largern += ", ";
            largern += names[i];
        }
    }

    return largern; // damn i cant return int

}

string smaller(const string names[], int values[]) {

    int scount = 0;
    int smallerv= values[0];
    string smallern = names[0];

    for (int i = 1; i < FLAVOURS; i++)
    {
        if (values[i] < smallerv) {
            smallerv= values[i];
            smallern = names[i];
            scount++;
        }
        else if (values[i] == smallerv) {
            smallerv= values[i];
            smallern += ", ";
            smallern += names[i];
        }
    }

    return smallern;
    
}