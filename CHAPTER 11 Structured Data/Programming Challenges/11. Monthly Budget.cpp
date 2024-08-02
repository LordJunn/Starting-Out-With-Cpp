/* A student has established the following monthly budget:
    Housing             500.00
    Utilities           150.00
    Household Expenses  65.00
    Transportation      50.00
    Food                250.00
    Medical             30.00
    Insurance           100.00
    Entertainment       150.00
    Clothing            75.00
    Miscellaneous       50.00
Write a program that has a MonthlyBudget structure designed to hold each of these
expense categories. The program should pass the structure to a function that asks the
user to enter the amounts spent in each budget category during a month. The pro-
gram should then pass the structure to a function that displays a report indicating the
amount over or under in each category, as well as the amount over or under for the
entire monthly student. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <cctype>
#include <cstring>
using namespace std;

double houseB = 500.00, 
       utilB = 150.00, 
       expsB = 65.00,
       transB = 50.00, 
       foodB = 250.00, 
       medB = 30.00, 
       insB = 100.00, 
       entB = 150.00, 
       clothB = 75.00, 
       miscB = 50.00,
       totalB = houseB + utilB + expsB + transB + foodB + medB + insB + entB + clothB + miscB;

struct MonthlyBudget {
    double house, util, exps, trans, food, med, ins, ent, cloth, misc, total; // imagine typing out everything
};

double checker(double&, double); // u aint spending negatives boi
void getInfo(MonthlyBudget&);
void report(MonthlyBudget&);
void overunder(double, double, string);

int main() {

    MonthlyBudget student;

    getInfo(student);
    report(student);

    return 0;
}

double checker(double &x, double i) {

    cin >> x;
    while (x < i) {
        cout << "Enter a bigger number, bigger than " << i << " .";
        cin.clear();
        cin >> x;
    }

    return x;

}

void getInfo(MonthlyBudget &student) {
    
    cout << "How much did you spend on housing? ";
    student.house = checker(student.house, 0);
    student.total += student.house;

    cout << "How much did you spend on utilities? ";
    student.util = checker(student.util, 0);
    student.total += student.util;

    cout << "How much did you spend on household expenses? ";
    student.exps = checker(student.exps, 0);
    student.total += student.exps;

    cout << "How much did you spend on transportation? ";
    student.trans = checker(student.trans, 0);
    student.total += student.trans;

    cout << "How much did you spend on food? ";
    student.food = checker(student.food, 0);
    student.total += student.food;

    cout << "How much did you spend on medical? ";
    student.med = checker(student.med, 0);
    student.total += student.med;

    cout << "How much did you spend on insurance? ";
    student.ins = checker(student.ins, 0);
    student.total += student.ins;

    cout << "How much did you spend on entertainment? ";
    student.ent = checker(student.ent, 0);
    student.total += student.ent;

    cout << "How much did you spend on clothing? ";
    student.cloth = checker(student.cloth, 0);
    student.total += student.cloth;

    cout << "How much did you spend on miscellaneous? ";
    student.misc = checker(student.misc, 0);
    student.total += student.misc;


}

void report(MonthlyBudget &student) {

    cout << "Reporting... \n";

    cout << "Total spent on housing = $" << student.house << endl;
    overunder(student.house, houseB, "housing");

    cout << "Total spent on utilities = $" << student.util << endl;
    overunder(student.util, utilB, "utilities");    

    cout << "Total spent on household expenses = $" << student.exps << endl;
    overunder(student.exps, expsB, "household expenses");

    cout << "Total spent on transportation = $" << student.trans << endl;
    overunder(student.trans, transB, "transportation");

    cout << "Total spent on food = $" << student.food << endl;
    overunder(student.food, foodB, "food");

    cout << "Total spent on medical = $" << student.med << endl;
    overunder(student.med, medB, "medical");

    cout << "Total spent on insurance = $" << student.ins << endl;
    overunder(student.ins, insB, "insurance");

    cout << "Total spent on entertainment = $" << student.ent << endl;
    overunder(student.ent, entB, "entertainment");

    cout << "Total spent on clothing = $" << student.cloth << endl;
    overunder(student.cloth, clothB, "clothing");

    cout << "Total spent on miscellaneous = $" << student.misc << endl;
    overunder(student.misc, miscB, "miscellaneous");

    cout << "Total spent = $" << student.total << endl;
    overunder(student.total, totalB, "the month");

}

void overunder(double spent, double budget, string owo) {

    double remains = budget - spent;

    if(remains < 0) {
        remains = abs(remains);
        cout << "You have spent over the budget for " << owo << " by $" << remains << endl;
    }
    else if (remains == 0) {
        cout << "You have spent clean the budget for " << owo << " exactly! " << endl;
    }
    else {
        cout << "You stayed within the budget for " << owo << " with $" << remains << " remaining! " << endl;
    }

}
