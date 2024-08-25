/* Design a TestScores class that has member variables to hold three test scores. The
class should have a constructor, accessor, and mutator functions for the test score fields
and a member function that returns the average of the test scores. Demonstrate the
class by writing a separate program that creates an instance of the class. The program
should ask the user to enter three test scores, which are stored in the TestScores
object. Then the program should display the average of the scores, as reported by the
TestScores object. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <cctype>
#include <cstring>
#include <fstream>
#include "TestScores.h" //noway im using header files
using namespace std;

int main() {
    
    TestScores ujian;

    double m1, m2, m3, ma;

    cout << "Enter your 1st test score here: ";
    cin >> m1;
    ujian.setTest1(m1);

    cout << "Enter your 2nd test score here: ";
    cin >> m2;
    ujian.setTest2(m2);

    cout << "Enter your 3rd test score here: ";
    cin >> m3;
    ujian.setTest3(m3);

    cout << "1st test score: " << ujian.getTest1() << endl;
    cout << "2nd test score: " << ujian.getTest2() << endl;
    cout << "3rd test score: " << ujian.getTest3() << endl;

    ma = ujian.testAvg();
    cout << "Test score average: " << ma << endl;

    return 0;
}