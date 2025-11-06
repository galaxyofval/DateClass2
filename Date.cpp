#include "Date.h"
#include <cmath>

Date::Date() : day(1), month(1), year(1900) {}

Date::Date(int m, int d, int y) {
    if (!setDate(m, d, y)) {
        day = 1; month = 1; year = 1900;
    }
}

bool Date::operator==(const Date& rhs) const {
    return year == rhs.year && month == rhs.month && day == rhs.day;
}

bool Date::operator<(const Date& rhs) const {
    if (year != rhs.year)   return year < rhs.year;
    if (month != rhs.month) return month < rhs.month;
    return day < rhs.day;
}


bool Date::isLeapYear(int y) const {
    return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0); // tells if a year is divisible by 4, but not divisible by 100, unless divisible by 400. 2000 is a leap year, but 2100 is not.
}

int Date::daysInMonth(int m, int y) const {
    static int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (m == 2 && isLeapYear(y)) return 29;
    return days[m - 1];
}

bool Date::setDate(int m, int d, int y) {
    if (m < 1 || m > 12 || d < 1 || d > daysInMonth(m, y)) {
        day = 1; month = 1; year = 1900;
        return false;
    }
    month = m; day = d; year = y;
    return true;
}

void Date::dateAdd(int daysToAdd) {
    while (daysToAdd > 0) {
        int dim = daysInMonth(month, year);
        if (day + 1 > dim) {
            day = 1;
            if (month == 12) {
                month = 1;
                year++;
            } else month++;
        } else day++;
        daysToAdd--;
    }
}
// Subtracts from the date
void Date::dateSubtract(int daysToSubtract) {
    while (daysToSubtract > 0) {
        if (day - 1 < 1) {
            if (month == 1) {
                month = 12;
                year--;
            } else month--;
            day = daysInMonth(month, year);
        } else day--;
        daysToSubtract--;
    }
}
// Compares two dates given, and returns the distance
int Date::compareDateDistance(const Date& other) const {
    Date temp = *this;
    int count = 0;

    if (*this < other) {
        while (temp.day != other.day || temp.month != other.month || temp.year != other.year) {
            temp.dateAdd(1);
            count++;
        }
    } else {
        while (temp.day != other.day || temp.month != other.month || temp.year != other.year) {
            temp.dateSubtract(1);
            count++;
        }
    }
    return count;
}

// overloading operators
Date& Date::operator++() { dateAdd(1); return *this; }
Date Date::operator++(int) { Date temp = *this; dateAdd(1); return temp; }
Date& Date::operator--() { dateSubtract(1); return *this; }
Date Date::operator--(int) { Date temp = *this; dateSubtract(1); return temp; }

int Date::operator-(const Date& rhs) const {
    Date a = *this;
    return a.compareDateDistance(rhs);
}

ostream& operator<<(ostream& out, const Date& d) {
    static string months[] = {"January","February","March","April","May","June","July",
                              "August","September","October","November","December"};
    out << months[d.month - 1] << " " << d.day << ", " << d.year;
    return out;
}
// If a date is invalid, then return the default date.
istream& operator>>(istream& in, Date& d) {
    int m, dd, y;
    cout << "Enter month day year (e.g., 4 18 2018): ";
    in >> m >> dd >> y;
    if (!d.setDate(m, dd, y))
        cout << "Invalid date entered. Defaulting to 1/1/1900.\n";
    return in;
}
