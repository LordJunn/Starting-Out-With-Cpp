// Specification file for the TestScores Class.
#ifndef TESTSCORES_H
#define TESTSCORES_H

class TestScores {
   private:
    double test1, test2, test3;

   public:
    TestScores() {
        test1 = 0;
        test2 = 0;
        test3 = 0;
    };

    TestScores(double t1, double t2, double t3) {
        t1 = test1;
        t2 = test2;
        t3 = test3;
    }

    // Accessor and mutator functions for test1
    double getTest1() const {
        return test1;
    }

    void setTest1(double t) {
        test1 = t;
    }

    // Accessor and mutator functions for test2
    double getTest2() const {
        return test2;
    }

    void setTest2(double t) {
        test2 = t;
    }

    // Accessor and mutator functions for test3
    double getTest3() const {
        return test3;
    }

    void setTest3(double t) {
        test3 = t;
    }

    double testAvg() {
        return (test1 + test2 + test3)/3.0;
    }

};
#endif