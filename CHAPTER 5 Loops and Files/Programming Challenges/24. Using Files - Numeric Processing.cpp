/* If you have downloaded this book’s source code from the companion Web site, you
will find a file named Random.txt in the Chapter 05 folder. (The companion Web
site is at www.pearsonhighered.com/gaddis.) This file contains a long list of random
numbers. Copy the file to your hard drive and then write a program that opens the file,
reads all the numbers from the file, and calculates the following:

A) The number of numbers in the file
B) The sum of all the numbers in the file (a running total)
C) The average of all the numbers in the file

The program should display the number of numbers found in the file, the sum of the
numbers, and the average of the numbers. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

int main() {

    ifstream input_file;
    float numbers, sum, avg, total, owo;

    input_file.open("Random.txt");

    if (input_file.fail())
    {
        cout << "Error opening the file." << endl;
    }

    while (input_file >> numbers) {
        cout << numbers << endl;
        sum += numbers;
        total++;
    }
    cout << endl;

    avg = sum/total;

    cout << "Total sum: " << sum << endl;
    cout << "Total numbers: " << total << endl;  
    cout << "Total average: " << avg << endl;

    input_file.close();
    
    return 0;
}