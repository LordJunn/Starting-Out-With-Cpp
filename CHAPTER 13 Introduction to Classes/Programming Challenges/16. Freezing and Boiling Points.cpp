/* The following table lists the freezing and boiling points of several substances.
Substance       Freezing Point      Boiling Point
Ethyl Alcohol       −173                172
Oxygen              −362               −306
Water                 32                212

Design a class that stores a temperature in a temperature member variable and has the
appropriate accessor and mutator functions. In addition to appropriate constructors,
the class should have the following member functions:
• isEthylFreezing. This function should return the bool value true if the tem-
perature stored in the temperature field is at or below the freezing point of ethyl
alcohol. Otherwise, the function should return false.
• isEthylBoiling. This function should return the bool value true if the tempera-
ture stored in the temperature field is at or above the boiling point of ethyl alcohol.
Otherwise, the function should return false.
• isOxygenFreezing. This function should return the bool value true if the tem-
perature stored in the temperature field is at or below the freezing point of oxygen.
Otherwise, the function should return false.
• isOxygenBoiling. This function should return the bool value true if the tem-
perature stored in the temperature field is at or above the boiling point of oxygen.
Otherwise, the function should return false.
• isWaterFreezing. This function should return the bool value true if the tem-
perature stored in the temperature field is at or below the freezing point of water.
Otherwise, the function should return false.
• isWaterBoiling. This function should return the bool value true if the tem-
perature stored in the temperature field is at or above the boiling point of water.
Otherwise, the function should return false.
Write a program that demonstrates the class. The program should ask the user to enter
a temperature and then display a list of the substances that will freeze at that tempera-
ture and those that will boil at that temperature. For example, if the temperature is −20
the class should report that water will freeze and oxygen will boil at that temperature. */

#include <iostream> // full gpt kys i aint got time for all that
#include <string>
using namespace std;

class Temperature {
private:
    int temperature;
public:
    Temperature(int temp) : temperature(temp) {}

    // Accessor and mutator
    int getTemperature() const {
        return temperature;
    }

    void setTemperature(int temp) {
        temperature = temp;
    }

    // Functions to check freezing and boiling points
    bool isEthylFreezing() const {
        return temperature <= -173;
    }

    bool isEthylBoiling() const {
        return temperature >= 172;
    }

    bool isOxygenFreezing() const {
        return temperature <= -362;
    }

    bool isOxygenBoiling() const {
        return temperature >= -306;
    }

    bool isWaterFreezing() const {
        return temperature <= 32;
    }

    bool isWaterBoiling() const {
        return temperature >= 212;
    }
};

int main() {
    int temp;
    cout << "Enter the temperature: ";
    cin >> temp;

    Temperature t(temp);

    cout << "Substances that will freeze at " << temp << " degrees:" << endl;
    if (t.isEthylFreezing()) {
        cout << "Ethyl Alcohol" << endl;
    }
    if (t.isOxygenFreezing()) {
        cout << "Oxygen" << endl;
    }
    if (t.isWaterFreezing()) {
        cout << "Water" << endl;
    }
    

    cout << "Substances that will boil at " << temp << " degrees:" << endl;
    if (t.isEthylBoiling()) {
        cout << "Ethyl Alcohol" << endl;
    }
    if (t.isOxygenBoiling()) {
        cout << "Oxygen" << endl;
    }
    if (t.isWaterBoiling()) {
        cout << "Water" << endl;
    }

    return 0;
}