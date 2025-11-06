#include "Date.h"
#include <iostream>
using namespace std;

int main() {
    Date d1, d2(4, 18, 2014);
    cout << "Default date: " << d1 << endl;
    cout << "Parameterized: " << d2 << endl;

    d1.setDate(13, 45, 2018); // invalid date
    cout << "Invalid test (13/45/2018): " << d1 << endl;

    d1.setDate(4, 10, 2014);
    d2.setDate(4, 18, 2014);
    cout << "Distance: " << (d2 - d1) << " days\n"; // compare two dates

    d1.setDate(12, 31, 2024);
    cout << "Pre-increment test: " << ++d1 << endl;
    cout << "Decrement test (before): " << d1-- << endl;
    cout << "Decrement test (after): " << d1 << endl;

    return 0;
}
