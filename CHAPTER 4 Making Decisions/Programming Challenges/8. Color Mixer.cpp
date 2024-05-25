/* The colors red, blue, and yellow are known as the primary colors because they cannot
be made by mixing other colors. When you mix two primary colors, you get a second-
ary color, as shown here:
When you mix red and blue, you get purple.
When you mix red and yellow, you get orange.
When you mix blue and yellow, you get green.
Write a program that prompts the user to enter the names of two primary colors to
mix. If the user enters anything other than “red,” “blue,” or “yellow,” the program
should display an error message. Otherwise, the program should display the name of
the secondary color that results by mixing two primary colors. */

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main() {

    string c1, c2;

    cout << "Enter the name of the first primary colour to mix:(“red,” “blue,” or “yellow,”)" << endl;
    cin >> c1;
    cout << "Enter the name of the second primary colour to mix:(“red,” “blue,” or “yellow,”)" << endl;
    cin >> c2;   

    if (c1 == "red" || c1 == "Red")
    {
        if (c2 == "blue" || c2 == "Blue")
        {
            cout << c1 << " & ";
            cout << c2 << " = purple.\n";
        }
        else if (c2 == "yellow" || c2 == "Yellow")
        {
            cout << c1 << " & ";
            cout << c2 << " = Orange.\n";
        }
        else {
            cout << "I don't think you're mixing anything at all." << endl;                  
        }
    }

    else if (c1 == "blue" || c1 == "Blue")
    {
        if (c2 == "red" || c2 == "Red")
        {
            cout << c1 << " & ";
            cout << c2 << " = purple.\n";
        }
        else if (c2 == "yellow" || c2 == "Yellow")
        {
            cout << c1 << " & ";
            cout << c2 << " = green.\n";
        }
        else {
            cout << "I don't think you're mixing anything at all." << endl;            
        }
    }

    else if (c1 == "yellow" || c1 == "Yellow")
    {
        if (c2 == "red" || c2 == "Red")
        {
            cout << c1 << " & ";
            cout << c2 << " = orange.\n";
        }
        else if (c2 == "blue" || c2 == "Blue")
        {
            cout << c1 << " & ";
            cout << c2 << " = green.\n";
        }
        else {
            cout << "I don't think you're mixing anything at all." << endl;                   
        }
    }
    else
    {
        cout << "This isn't an option." << endl;
    }

    return 0;
}