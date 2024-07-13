/* Write a program that asks the user to enter the amount that he or she has budgeted
for a month. A loop should then prompt the user to enter each of his or her expenses
for the month and keep a running total. When the loop finishes, the program should
display the amount that the user is over or under budget. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int main() {

    float start, end, expense, expenses;
    int amount;

    cout << "Budget for a month?" << endl;
    cin >> start;

    while (start < 0) {
        cout << "You starting with negative money? Let's type in a positive number." << endl;
        cin >> start;
    }

    cout << "Amount of expenses?" << endl;
    cin >> amount;

    while (amount <= 0) {
        cout << "If you don't have any amount of expenses, why are you using this program? Let's type in a positive number." << endl;
        cin >> amount;
    }

    for (int i = 1; i <= amount && expense >= 0; i++) {
        cout << "How much are you budgeting for expense #" << i << " ?" << endl;
        cin >> expense;

        if (expense < 0) {
            expenses -= expense;
        }

        expenses += expense;
    }

    end = start - expenses;
    
    if (end > 0) {
        cout << "You still have $" << end << " remaining, congratulations!" << endl;
    }
    else if (end == 0) {
        cout << "You have exactly $" << end << " remaining, congratulations?" << endl;        
    }
    else {
        end = abs(end);
        cout << "You need at least $" << end << " more to satisfy your spendings." << endl;
        end += start;
        cout << "In other words, you need a budget of at least $" << end << " to satisfy your spendings." << endl;
    }


    return 0;
}