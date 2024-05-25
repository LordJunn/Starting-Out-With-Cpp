/* Serendipity Booksellers has a book club that awards points to its customers based on
the number of books purchased each month. The points are awarded as follows:
• If a customer purchases 0 books, he or she earns 0 points.
• If a customer purchases 1 book, he or she earns 5 points.
• If a customer purchases 2 books, he or she earns 15 points.
• If a customer purchases 3 books, he or she earns 30 points.
• If a customer purchases 4 or more books, he or she earns 60 points.
Write a program that asks the user to enter the number of books that he or she has
purchased this month and then displays the number of points awarded. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int main() {

    int book, points;

    cout << "Number of books purchased?" << endl;
    cin >> book;

    if (book >= 4) {
        points = 60;
    }
    else if (book >= 3) {
        points = 30;
    }
    else if (book >= 2) {
        points = 15;
    }
    else if (book >= 1) {
        points = 5;
    }        
    else if (book >= 0) {
        points = 0;
    }    
    else {
        cout << "???" << endl;
        return 0;
    }

    cout << fixed << setprecision(2) << "Total books purchased = " << book << endl;
    cout << fixed << setprecision(2) << "Total points earned = " << points << endl;    



    return 0;
}