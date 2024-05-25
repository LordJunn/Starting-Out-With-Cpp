/* Write a program that asks for the number of calories and fat grams in a food. The pro-
gram should display the percentage of calories that come from fat. If the calories from
fat are less than 30% of the total calories of the food, it should also display a message
indicating that the food is low in fat.
One gram of fat has 9 calories, so
Calories from fat = fat grams * 9
The percentage of calories from fat can be calculated as
Calories from fat / total calories

Input Validation: Make sure the number of calories and fat grams are not less than
0. Also, the number of calories from fat cannot be greater than the total number of
calories. If that happens, display an error message indicating that either the calories or
fat grams were incorrectly entered. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int main() {

    float cal, fat, fatcal, total, ratio;

    cout << "Number of calories?" << endl;
    cin >> cal;
    cout << "Number of fat grams?" << endl;
    cin >> fat;

    if (cal >= 0 && fat >= 0) {

        if (cal > fat) {

            fatcal = fat * 9;
            total = cal + fatcal;
            ratio = (fatcal / total) * 100;

            cout << "Total calories: " << total << endl;

            if (ratio < 30) {
                cout << "Percentage of calories that come from fat: " << ratio << "%" << endl;
                cout << "Helth!" << endl;

            }
            else {
                cout << "Percentage of calories that come from fat: " << ratio << "%" << endl;
            }

    }

    else {
        cout << "How does a food contain more fats than calories?" << endl;
    }

        }

    else {
        if (cal < 0 && fat < 0) {
            cout << "???" << endl;
        }
        else if (cal < 0) {
            cout << "Cal 0 ???" << endl;
        }
        else {
            cout << "Fat 0 ???" << endl;
        }
    }

    return 0;
}