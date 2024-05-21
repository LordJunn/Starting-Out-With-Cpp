/* A bag of cookies holds 30 cookies. The calorie information on the bag claims that there
are 10 “servings” in the bag and that a serving equals 300 calories. Write a program
that asks the user to input how many cookies he or she actually ate and then reports
how many total calories were consumed. */

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    
    int bag = 30,
        servings = (bag/10),
        calories = (300/servings),
        cookies,
        actualCalories;

    cout << "How many cookies did you actually ate?" << endl;
    cin >> cookies;

    actualCalories = cookies * calories;
    cout << "Total calories consumed = " << actualCalories << endl;

    return 0;
}