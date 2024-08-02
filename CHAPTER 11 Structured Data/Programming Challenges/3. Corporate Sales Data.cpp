/* Write a program that uses a structure to store the following data on a company
division:

Division Name (such as East, West, North, or South)
First-Quarter Sales
Second-Quarter Sales
Third-Quarter Sales
Fourth-Quarter Sales
Total Annual Sales
Average Quarterly Sales

The program should use four variables of this structure. Each variable should rep-
resent one of the following corporate divisions: East, West, North, and South. The
user should be asked for the four quarters’ sales figures for each division. Each
division’s total and average sales should be calculated and stored in the appropriate
member of each structure variable. These figures should then be displayed on the
screen.
Input Validation: Do not accept negative numbers for any sales figures. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <cctype>
#include <cstring>
using namespace std;

double checker(double&, int);

struct companyD {
    string division;
    double Q1S;
    double Q2S;
    double Q3S;
    double Q4S;
    double total;
    double avg;
};

int main() {

    const int divisions = 4;
    string corporate[divisions] = {"East", "West", "North", "South"};
    companyD cd[divisions];
    int index;

    cout << "Enter the details for " << divisions << " divisions." << endl;

    for (index = 0; index < divisions; index++) {
        cout << "Enter sales figure for " << corporate[index] << " division." << endl;
        
        cout << "First-Quarter Sales? ";
        cd[index].Q1S = checker(cd[index].Q1S, 0);
        cout << "Second-Quarter Sales? ";
        cd[index].Q2S = checker(cd[index].Q2S, 0);
        cout << "Third-Quarter Sales? ";
        cd[index].Q3S = checker(cd[index].Q3S, 0);
        cout << "Fourth-Quarter Sales? ";
        cd[index].Q4S = checker(cd[index].Q4S, 0);

        cin.ignore();

        cd[index].total = cd[index].Q1S + cd[index].Q2S + cd[index].Q3S + cd[index].Q4S;
        cd[index].avg = cd[index].total/divisions;

        cout << endl;
    }

    for (index = 0; index < divisions; index++) {
        cout << "These are the sales figure for " << corporate[index] << " division." << endl;
        
        cout << fixed << setprecision(2);
        cout << "Total annual sales: $" << cd[index].total << endl;
        cout << "Average per quarter: $" << cd[index].avg << endl;

        cout << endl;
    }

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









