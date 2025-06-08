#include "DateTime.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>

using namespace std;

DateTime::DateTime() : year(0), month(0), day(0), hour(0), minute(0) {}

DateTime::DateTime(int y, int m, int d, int h, int min)
    : year(y), month(m), day(d), hour(h), minute(min) {
}

void DateTime::input() {
    cout << "請輸入年月日時分（例如 2025 06 10 23 30）：";
    cin >> year >> month >> day >> hour >> minute;
}

void DateTime::display() const {
    cout << setfill('0') << setw(4) << year << "-"
        << setw(2) << month << "-"
        << setw(2) << day << " "
        << setw(2) << hour << ":"
        << setw(2) << minute;
}

bool DateTime::isPast() const {
    time_t now = time(0);
    tm t;
    localtime_s(&t, &now);  // 安全版寫法 for Windows

    if (year < t.tm_year + 1900) return true;
    if (year > t.tm_year + 1900) return false;
    if (month < t.tm_mon + 1) return true;
    if (month > t.tm_mon + 1) return false;
    if (day < t.tm_mday) return true;
    if (day > t.tm_mday) return false;
    if (hour < t.tm_hour) return true;
    if (hour > t.tm_hour) return false;
    return minute <= t.tm_min;
}

string DateTime::toString() const {
    ostringstream oss;
    oss << year << " " << month << " " << day << " " << hour << " " << minute;
    return oss.str();
}

DateTime DateTime::fromString(const string& str) {
    istringstream iss(str);
    int y, m, d, h, min;
    iss >> y >> m >> d >> h >> min;
    return DateTime(y, m, d, h, min);
}
