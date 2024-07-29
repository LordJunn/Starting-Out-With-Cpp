/* Write a program that displays a simulated paycheck. The program should ask the user to
enter the date, the payee’s name, and the amount of the check (up to $10,000). It should
then display a simulated check with the dollar amount spelled out, as shown here:
Date: 11/24/2014
Pay to the Order of: John Phillips $1920.85
One thousand nine hundred twenty and 85 cents
Be sure to format the numeric value of the check in fixed-point notation with two
decimal places of precision. Be sure the decimal place always displays, even when the
number is zero or has no fractional part. Use either C-strings or string class objects
in this program.
Input Validation: Do not accept negative dollar amounts, or amounts over $10,000. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <cctype>
#include <cstring>
using namespace std;

double checker(double&, int, int);
void linefunction(string&, int);
void datefunction(string&, int);
void dateFormat(string&);
void nameFormat(string&);
void moneyFormat(double);
string ringgitFormat(int);
void moneyOutput(string&, string&, int, int);

string ones[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
string teens[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
string tens[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

int main() {

    string date, name, myr, mys;
    int ringgit, sen;
    int SIZE = 9,
        nameL = 999;
    double money;

    cout << "The date format is mm/dd/yyyy. " << endl;
    datefunction(date, SIZE); 
    cout << "Who are we paying by the order to? " << endl;
    linefunction(name, nameL); 
    cout << "How much was given? " << endl;
    money = checker(money, 0, 10000);

    ringgit = static_cast<int>(money);
    sen = static_cast<int>((money - ringgit) * 100);

    myr = ringgitFormat(ringgit);
    mys = ringgitFormat(sen);

    cout << endl << endl << endl;
    dateFormat(date);
    nameFormat(name);
    moneyFormat(money);

    moneyOutput(myr, mys, ringgit, sen);

    return 0;
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

void linefunction(string &array, int SIZE) {
    cout << "Input no more than " << (SIZE) << " in length. " << endl;
    getline(cin, array);
}

void datefunction(string &array, int SIZE) {
    cout << "Input a date no more than " << (SIZE) << " in length. " << endl;
    while (true) {
        getline(cin, array);
        if (array.length() >= 5) // Ensure the input has at least 5 characters
            break;
        else
            cout << "Please enter a valid date (MM/DD/YYYY): ";
    }
}

void dateFormat(string &date) {
    
    string s1, s2, s3;
    s1.assign(date, 0, 2);
    s2.assign(date, 2, 2);
    s3.assign(date, 4, 4);

    cout << "Date: " << s1 << "/" << s2 << "/" << s3 << endl;
}

void nameFormat(string &name) {
    cout << "Pay to the Order of: " << name << endl;
}

void moneyFormat(double duit) {
    cout << fixed << setprecision(2) << "$" << duit << endl;
}

string ringgitFormat(int rm) {
    if (rm == 0) {
        cout << "Wow did bro really give him no money at all?" << endl;
        return "zero";
    }

    string result;

    if(rm >= 1000) {
        result += ones[rm/1000] + " thousand ";
        rm %= 1000;
    }

    if (rm >= 100) {
        result += ones[rm / 100] + " hundred ";
        rm %= 100;
    }

    if (rm >= 10 && rm < 20) {
        result += teens[rm - 10];
        return result;
    }

    if (rm >= 20) {
        result += tens[rm / 10] + " ";
        rm %= 10;
    }

    if (rm > 0) {
        result += ones[rm];
    }

    return result;

}

void moneyOutput(string& dol, string& cen, int rm, int s) {

    if(rm == 1) {
        cout << dol << " dollar";

        if (s == 1) {
            cout << " and " << cen << " cent. ";
        }
        else if (s == 0) {
            cout << " ";
        }
        else {
            cout << " and " << cen << " cents. ";
        }

    }
    else if(rm == 0) {
        cout << "";

        if (s == 1) {
            cout << cen << " cent. ";
        }
        else if (s == 0) {
            cout << "No money was given.";
        }
        else {
            cout << cen << " cents. ";
        }

    }
    else {
        cout << dol << " dollars";

        if (s == 1) {
            cout << " and " << cen << " cent. ";
        }
        else if (s == 0) {
            cout << " ";
        }
        else {
            cout << " and " << cen << " cents. ";
        }

    }

}

