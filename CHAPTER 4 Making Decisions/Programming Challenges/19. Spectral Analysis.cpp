/* If a scientist knows the wavelength of an electromagnetic wave, he or she can deter-
mine what type of radiation it is. Write a program that asks for the wavelength of an
electromagnetic wave in meters and then displays what that wave is according to the
chart below. (For example, a wave with a wavelength of 1E-10 meters would be an
X-ray.)

1x 10-??     1 × 10–2    1 × 10–3   7 × 10–7       4 × 10 –7    1 × 10–8   1 × 10–11
Radio Waves  Microwaves  Infrared   Visible Light  Ultraviolet  X Rays     Gamma Rays */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int main() {

    double wave;

    cout << "Wavelength of an electromagnetic wave? " << endl;
    cin >> wave;

    if (wave <= 1E-11 ) {
        cout << "Gamma Rays" << endl;     
    }
    else if (wave <= 1E-8) {
        cout << "X Rays" << endl;            
    }
    else if (wave <= 4E-7) {
        cout << "Ultraviolet" << endl;            
    }
    else if (wave <= 7E-7) {
        cout << "Visible Light" << endl;            
    }
    else if (wave <= 1E-3) {
        cout << "Infared" << endl;            
    }
    else if (wave <= 1E-2) {
        cout << "Microwaves" << endl;            
    }
    else {
        cout << "Radio Waves" << endl;
    }

    return 0;
}