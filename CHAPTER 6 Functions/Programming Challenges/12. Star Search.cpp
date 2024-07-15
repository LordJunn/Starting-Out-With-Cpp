/* A particular talent competition has five judges, each of whom awards a score between
0 and 10 to each performer. Fractional scores, such as 8.3, are allowed. A performer’s
final score is determined by dropping the highest and lowest score received, then aver-
aging the three remaining scores. Write a program that uses this method to calculate a
contestant’s score. It should include the following functions:

• void getJudgeData() should ask the user for a judge’s score, store it in a reference
parameter variable, and validate it. This function should be called by main once for
each of the five judges.
• void calcScore() should calculate and display the average of the three scores that
remain after dropping the highest and lowest scores the performer received. This
function should be called just once by main and should be passed the five scores.
The last two functions, described below, should be called by calcScore, which uses
the returned information to determine which of the scores to drop.
• int findLowest() should find and return the lowest of the five scores passed to it.
• int findHighest() should find and return the highest of the five scores passed to it.

Input Validation: Do not accept judge scores lower than 0 or higher than 10. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

double scores(double);
void getJudgeData(double &);
double ifLowest(double, double, double, double, double);
double findLowest(double, double, double, double, double);
double ifHighest(double, double, double, double, double);
double findHighest(double, double, double, double, double);
void calcScore(double, double, double, double, double);

int main() {

    double j1, j2, j3, j4, j5;
    getJudgeData(j1);
    getJudgeData(j2);
    getJudgeData(j3);
    getJudgeData(j4);
    getJudgeData(j5);

    cout << "Score given by Judge 1 = " << j1 << endl;
    cout << "Score given by Judge 2 = " << j2 << endl;
    cout << "Score given by Judge 3 = " << j3 << endl;
    cout << "Score given by Judge 4 = " << j4 << endl;
    cout << "Score given by Judge 5 = " << j5 << endl;  

    calcScore(j1, j2, j3, j4, j5);  

    return 0;
}

double scores(double score) {

    cin >> score;
    while (score < 0 || score > 10) {
        cout << "I was told to not accept judge scores lower than 0 or higher than 10. ";
        cin >> score;
    }
    return score;

}

void getJudgeData(double &score) {

    cout << "Score given? ";
    score = scores(score);

}


double ifLowest(double j1, double j2, double j3, double j4, double j5) {

    double lowest;

    if ((j1 <= j2) && (j1 <= j3) && (j1 <= j4) && (j1 <= j5)) {
        lowest = j1;
    }

    return lowest;

}

double findLowest(double j1, double j2, double j3, double j4, double j5) {

    double lowest = 0;

    lowest = ifLowest(j1, j2, j3, j4, j5);
    lowest = ifLowest(j2, j1, j3, j4, j5);
    lowest = ifLowest(j3, j2, j1, j4, j5);
    lowest = ifLowest(j4, j2, j3, j1, j5);
    lowest = ifLowest(j5, j2, j3, j4, j1);

    return lowest;

}

double ifHighest(double j1, double j2, double j3, double j4, double j5) {

    double highest;

    if ((j1 >= j2) && (j1 >= j3) && (j1 >= j4) && (j1 >= j5)) {
        highest = j1;
    }

    return highest;

}

double findHighest(double j1, double j2, double j3, double j4, double j5) {

    double highest = 0;

    highest = ifHighest(j1, j2, j3, j4, j5);
    highest = ifHighest(j2, j1, j3, j4, j5);
    highest = ifHighest(j3, j2, j1, j4, j5);
    highest = ifHighest(j4, j2, j3, j1, j5);
    highest = ifHighest(j5, j2, j3, j4, j1);

    return highest;

}

void calcScore(double j1, double j2, double j3, double j4, double j5) {

    double lowest = findLowest(j1, j2, j3, j4, j5),
           highest = findHighest(j1, j2, j3, j4, j5),
           avg,
           sum = j1 + j2 + j3 + j4 + j5;

    sum -= (lowest + highest);
    avg = sum/3;

    cout << lowest << " is removed as it is the lowest. " << endl;
    cout << highest << " is removed as it is the highest. " << endl;
    cout << "With that said, the average 3 scores is " << avg << endl;   

}