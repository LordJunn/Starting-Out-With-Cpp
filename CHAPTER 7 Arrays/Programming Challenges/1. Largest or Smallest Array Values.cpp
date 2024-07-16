/* Write a program that lets the user enter 10 values into an array. The program should
then display the larger and smaller values stored in the array. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int checker(int&, int);
void getValues(int array[]);
int larger(int array[]);
int smaller(int array[]);

const int num_values = 10;

int main() {

    int values[num_values];

    getValues(values);

    int largerst = larger(values);
    cout << "Largest value = " << largerst << endl;
    int smallest = smaller(values);
    cout << "Smallest value = " << smallest << endl;

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

void getValues(int array[]) {

    for(int i = 0; i < num_values; i++) {
        cout << "Enter array #" << (i + 1) << " here. ";
        array[i] = checker(array[i], 0);
    }    
}

int larger(int array[]) {

    int lcount = 0;
    int larger = array[0];
    for (int i = 1; i < num_values; i++)
    {
        if (array[i] >= larger) {
            larger = array[i];
            lcount++;
        }
    }
    cout << "There were a total of " << lcount << " numbers larger than " << array[0] << endl;
    return larger;

}

int smaller(int array[]) {

    int scount = 0;
    int smaller = array[0];
    for (int i = 1; i < num_values; i++)
    {
        if (array[i] <= smaller) {
            smaller = array[i];
            scount++;
        }
    }
    cout << "There were a total of " << scount << " numbers smaller than " << array[0] << endl;
    return smaller;
    
}