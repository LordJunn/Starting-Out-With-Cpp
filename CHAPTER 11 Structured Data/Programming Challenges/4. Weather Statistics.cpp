/* Write a program that uses a structure to store the following weather data for a par-
ticular month:

    Total Rainfall
    High Temperature
    Low Temperature
    Average Temperature

The program should have an array of 12 structures to hold weather data for an
entire year. When the program runs, it should ask the user to enter data for each
month. (The average temperature should be calculated.) Once the data are entered
for all the months, the program should calculate and display the average monthly
rainfall, the total rainfall for the year, the highest and lowest temperatures for the
year (and the months they occurred in), and the average of all the monthly average
temperatures.

Input Validation: Only accept temperatures within the range between –100 and +140
degrees Fahrenheit */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <cctype>
#include <cstring>
using namespace std;

struct weatherData {
    double totalRain;
    double high;
    double low;
    double avg;
};

const int months = 12;

string monthNames[months] = {"January", "February", "March", "April", "May", "June", "July",
                                "August", "September", "October", "November", "December" }; 

double checker(double&, int);
double checker(double&, int, int);
int findHigh(weatherData[]);
int findLow(weatherData[]);
void displayHighLow(int, double, int, double);


int main() {
    
    weatherData weather[months];
    double totalrainfall, allavgtemp; 
    int highest, lowest;

    for (int i = 0; i < months; i++) { // gather info
        cout << "Insert data for " << monthNames[i] << endl;

        cout << "Total rainfall? ";
        weather[i].totalRain = checker(weather[i].totalRain, 0);
        totalrainfall += weather[i].totalRain;
        cout << "High temperature? ";
        weather[i].high = checker(weather[i].high, -100, 140);
        cout << "Low temperature? ";
        weather[i].low = checker(weather[i].low, -100, 140);

        cin.ignore();

        weather[i].avg = (weather[i].high + weather[i].low)/2;
        allavgtemp += weather[i].avg;
        cout << endl;       
    }

    cout << "Displaying data for the year..." << endl;
    cout << "Average monthly rainfall: " << totalrainfall/months << endl;
    cout << "The total rainfall for the year: " << totalrainfall << endl;

    highest = findHigh(weather);
    lowest = findLow(weather);

    displayHighLow(highest, weather[highest].high, lowest, weather[lowest].low);

    cout << "The average of all the monthly average temperatures: " << allavgtemp/months << endl;

    return 0;
}

double checker(double &x, int i) {

    cin >> x;
    while (x < i) {
        cout << "Enter a bigger number, bigger than " << i << " .";
        cin.clear();
        cin >> x;
    }

    return x;

}

double checker(double &x, int i, int j) {

    cin >> x;
    while (x < i || x > j) {
        cout << "Enter a bigger number, bigger than " << i << ", but smaller than " << j << " .";
        cin.clear();
        cin >> x;
    }

    return x;

}

int findHigh(weatherData weather[]) {
    double highest = 0;
    
    highest = weather[0].high;
    for(int i = 1; i < months; i++) {
        if(weather[i].high > weather[i - 1].high) {
            highest = i;
        }
    }

    return highest;
}

int findLow(weatherData weather[]) {
    double lowest = 0;
    
    lowest = weather[0].low;
    for(int i = 1; i < months; i++) {
        if(weather[i].low < weather[i - 1].low) {
            lowest = i;
        }
    }

    return lowest;
}

void displayHighLow(int index1, double temp1, int index2, double temp2) {
    cout << "The highest temperature for the year is " << temp1 << " that occured in " << monthNames[index1] << endl;
    cout << "The lowest temperature for the year is " << temp2 << " that occured in " << monthNames[index2] << endl;
}

