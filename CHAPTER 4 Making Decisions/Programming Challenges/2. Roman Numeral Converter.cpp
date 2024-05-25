/* Write a program that asks the user to enter a number within the range of 1 through
10. Use a switch statement to display the Roman numeral version of that number.

Input Validation: Do not accept a number less than 1 or greater than 10. */

#include <iostream>
using namespace std;

int main() {

    int num;

    cout << "Enter a number within the range of 1 through 10." << endl;
    cin >> num;

    switch (num)
    {
        case 1:
            cout << "The Roman numeral for ";
            cout  << num << " is I\n";
            break;
        case 2:
            cout << "The Roman numeral for ";
            cout << num << " is II\n";
            break;
        case 3:
            cout << "The Roman numeral for ";
            cout << num << " is III\n";
            break;
        case 4:
            cout << "The Roman numeral for ";
            cout << num << " is IV\n";
            break;
        case 5:
            cout << "The Roman numeral for ";
            cout << num << " is V\n";
            break;
        case 6:
            cout << "The Roman numeral for ";
            cout << num << " is VI\n";
            break;
        case 7:
            cout << "The Roman numeral for ";
            cout << num << " is VII\n";
            break;
        case 8:
            cout << "The Roman numeral for ";
            cout << num << " is VIII\n";
            break;
        case 9:
            cout << "The Roman numeral for ";
            cout << num << " is XI\n";
            break;
        case 10:
            cout << "The Roman numeral for ";
            cout << num << " is X\n";
            break;
        default:
            cout << "You must enter a number between 1 and 10\n";
            cout << "Run the program over and try again.\n";
            break;
    }
    return 0;
}