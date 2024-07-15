/* Write a program that calculates the average of a group of test scores, where the lowest
score in the group is dropped. It should use the following functions:

• void getScore() should ask the user for a test score, store it in a reference param-
eter variable, and validate it. This function should be called by main once for each
of the five scores to be entered.
• void calcAverage() should calculate and display the average of the four highest
scores. This function should be called just once by main and should be passed the
five scores.
• int findLowest() should find and return the lowest of the five scores passed to it.
It should be called by calcAverage, which uses the function to determine which of
the five scores to drop.

Input Validation: Do not accept test scores lower than 0 or higher than 100. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

double positive(double);
void getScore(double &);  // 6.13 Using Reference Variables as Parameters, so thats what killing my code
double ifLowest(double, double, double, double, double);
double findLowest(double, double, double, double, double);
void calcAverage(double, double, double, double, double);

int main() {

    double s1, s2, s3, s4, s5;

    getScore(s1);
    getScore(s2);
    getScore(s3);
    getScore(s4);
    getScore(s5);

    calcAverage(s1, s2, s3, s4, s5);

    return 0;
}

double positive(double score) {

    cin >> score;
    while (score < 0) {
        cout << "Positive numbers only please. ";
        cin >> score;
    }
    return score;

}

void getScore(double &score) {

    cout << "Score? ";
    score = positive(score);

}

double ifLowest(double s1, double s2, double s3, double s4, double s5) {

    double lowest;

    if ((s1 <= s2) && (s1 <= s3) && (s1 <= s4) && (s1 <= s5)) {
        lowest = s1;
    }

    return lowest;

}

double findLowest(double s1, double s2, double s3, double s4, double s5) {

    double lowest = 0;

    lowest = ifLowest(s1, s2, s3, s4, s5);
    lowest = ifLowest(s2, s1, s3, s4, s5);
    lowest = ifLowest(s3, s2, s1, s4, s5);
    lowest = ifLowest(s4, s2, s3, s1, s5);
    lowest = ifLowest(s5, s2, s3, s4, s1);

    return lowest;

}

void calcAverage(double s1, double s2, double s3, double s4, double s5) {

    double avg = 0;

    double lowest = findLowest(s1, s2, s3, s4, s5);

    if (s1 == lowest) {
        avg = (s2 + s3 + s4 + s5) / 4;
        cout << "The lowest score (" << s1 << ") is removed." << endl;
    }

     else if (s2 == lowest) {
        avg = (s1 + s3 + s4 + s5) / 4;
        cout << "The lowest score (" << s2 << ") is removed." << endl;
     }
     else if (s3 == lowest) {
        avg = (s1 + s2 + s4 + s5) / 4;
        cout << "The lowest score (" << s3 << ") is removed." << endl;
     }
     else if (s4 == lowest) {
        avg = (s1 + s2 + s3 + s5) / 4;
        cout << "The lowest score (" << s4 << ") is removed." << endl;
     }
        
     else if (s5 == lowest) {
        avg = (s1 + s2 + s3 + s4) / 4;
        cout << "The lowest score (" << s5 << ") is removed." << endl;
     }
        
    cout << fixed << setprecision(2) << "The average is: " << avg << endl;

}

