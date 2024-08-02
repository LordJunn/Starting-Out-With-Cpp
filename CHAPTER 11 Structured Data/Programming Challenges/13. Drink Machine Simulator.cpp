/* Write a program that simulates a soft drink machine. The program should use a structure
that stores the following data:

    Drink Name
    Drink Cost
    Number of Drinks in Machine
    
The program should create an array of five structures. The elements should be initialized
with the following data:

Drink Name      Cost   Number in Machine
Cola            .75         20
Root Beer       .75         20
Lemon-Lime      .75         20
Grape Soda      .80         20
Cream Soda      .80         20

Each time the program runs, it should enter a loop that performs the following steps:
A list of drinks is displayed on the screen. The user should be allowed to either quit the
program or pick a drink. If the user selects a drink, he or she will next enter the amount
of money that is to be inserted into the drink machine. The program should display
the amount of change that would be returned and subtract one from the number of
that drink left in the machine. If the user selects a drink that has sold out, a message
should be displayed. The loop then repeats. When the user chooses to quit the program
it should display the total amount of money the machine earned.

Input Validation: When the user enters an amount of money, do not accept negative
values or values greater than $1.00. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <cctype>
#include <cstring>
using namespace std;

struct Drink {
    string name;
    double cost;
    int number;
};

Drink drinks[5] = {
    {"Cola", 0.75, 20},
    {"Root Beer", 0.75, 20},
    {"Lemon-Lime", 0.75, 20},
    {"Grape Soda", 0.80, 20},
    {"Cream Soda", 0.80, 20}
};

void displayMenu();
int checker(int&, int, int);
double checker(double&, double, double);
void choices(Drink[], int);
void buying(Drink* drinks);
double paying(Drink* drinks);

double earnings;

int main() {

    int choice;

    do{
        displayMenu();
        cout << "Enter your choice: ";
        choice = checker(choice, 1, 6);
        choices(drinks, choice);
    }while(choice != 6);

    cout << "You have earned a total of $" << earnings << endl;

    return 0;
}

void displayMenu() {
    cout << "\nMenu:\n";
    cout << "1. Buy " << drinks[0].name << " \n";
    cout << "2. Buy " << drinks[1].name << " \n";
    cout << "3. Buy " << drinks[2].name << " \n";
    cout << "4. Buy " << drinks[3].name << " \n";  
    cout << "5. Buy " << drinks[4].name << " \n";      
    cout << "6. Exit & see profits \n";    
}

int checker(int &x, int i, int j) {

    cin >> x;
    while (x < i || x > j) {
        cout << "Enter a bigger number, bigger than " << i << ", but smaller than " << j << ".";
        cin.clear();
        cin >> x;
    }

    return x;

}

double checker(double &x, double i, double j) {

    cin >> x;
    while (x < i || x > j) {
        cout << "Enter a bigger number, bigger than " << i << ", but smaller than " << j << ".";
        cin.clear();
        cin >> x;
    }

    return x;

}

void choices(Drink drinks[], int choice) {
    
    switch(choice) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            cout << "Buying " << drinks[choice - 1].name << "... \n";
            cin.ignore();
            buying(&drinks[choice - 1]);
            break;
        
        case 6:
            cout << "Exiting... \n";
            break;

        default:
            cout << "This is NOT a valid option.";

    }

}

void buying(Drink* drinks) {

    if(drinks->number <= 0) {
        cout << drinks->name << " has ran out of stock. Please buy another drink. ";
    }
    else {
        earnings += paying(drinks);
        drinks->number--; // Using the arrow operator to access the member of the object pointed to by the pointer
    }

}

double paying(Drink* drinks) {

    double duit, spare;
    bool w = false; // if u didnt insert enough money

    do{
        cout << "How much will you insert into the machine? ";
        duit = checker(duit, 0, 1);
        spare = duit - drinks->cost; 

        if(spare > 0) {
            cout << "You have successfully purchased 1 " << drinks->name << "!" << endl;
            cout << "Your change is $" << spare << endl;
            w = true;
        }
        else if(spare == 0) {
            cout << "You have successfully purchased 1 " << drinks->name << "!" << endl;
            cout << "...There is no change." << endl;
            w = true;            
        }
        else {
            spare = abs(spare);
            cout << "Sorry, you need at least $" << spare << " more to afford. " << endl;
        }

    }while (w == false);

    return drinks->cost;

}
