/* A cookie recipe calls for the following ingredients:
• 1.5 cups of sugar
• 1 cup of butter
• 2.75 cups of flour
The recipe produces 48 cookies with this amount of the ingredients. Write a program
that asks the user how many cookies he or she wants to make, and then displays the
number of cups of each ingredient needed for the specified number of cookies. */

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    
    float sugar, butter, flour;
    int cookies;

    cout << "How many cookies do you want to make?" << endl;
    cin >> cookies;

    sugar = (1.5/48) * cookies;
    butter = (1.0/48) * cookies;
    flour = (2.75/48) * cookies;

    cout << "Sugar needed: " << sugar << " cups" << endl;
    cout << "Butter needed: " << butter << " cups" << endl;
    cout << "Flour needed: " << flour << " cups" << endl;

    return 0;
}