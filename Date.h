#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>
using namespace std;

class Date {
private:
    int day, month, year;

    // helper functions
    bool isLeapYear(int y) const;
    int daysInMonth(int m, int y) const;

public:
    // constructors
    Date(); // default 1/1/1900
    Date(int m, int d, int y);

    // setters/getters
    bool setDate(int m, int d, int y);
    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }

    // date math
    void dateAdd(int daysToAdd);
    void dateSubtract(int daysToSubtract);
    int compareDateDistance(const Date& other) const;

    // operator overloads
    bool operator<(const Date& rhs) const;
bool operator==(const Date& rhs) const;

    Date& operator++();      // prefix ++
    Date operator++(int);    // postfix ++
    Date& operator--();      // prefix --
    Date operator--(int);    // postfix --
    int operator-(const Date& rhs) const;
    friend ostream& operator<<(ostream& out, const Date& d);
    friend istream& operator>>(istream& in, Date& d);
};

#endif
