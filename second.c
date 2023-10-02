#include <iostream>
using namespace std;

int main() {
    // Variables to store factors
    double socioEconomicStatus, age, gender;
    
    // Input factors (you can replace these with real data)
    cout << "Enter socio-economic status (0-10): ";
    cin >> socioEconomicStatus;
    
    cout << "Enter age: ";
    cin >> age;
    
    cout << "Enter gender (0 for male, 1 for female): ";
    cin >> gender;
    
    // Check factors and make a prediction
    bool safeFromSinking = false;
    
    if (socioEconomicStatus >= 5 && age <= 40 && gender == 1) {
        safeFromSinking = true;
    }
    
    // Output prediction
    if (safeFromSinking) {
        cout << "Based on the factors, it is likely that the person will be safe from sinking." << endl;
    } else {
        cout << "Based on the factors, it is not guaranteed that the person will be safe from sinking." << endl;
    }
    
    return 0;
}
