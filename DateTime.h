#ifndef DATETIME_H
#define DATETIME_H

#include <string>

class DateTime {
private:
    int year, month, day, hour, minute;

public:
    DateTime();
    DateTime(int y, int m, int d, int h, int min);
    void input();
    void display() const;
    bool isPast() const;
    std::string toString() const;
    static DateTime fromString(const std::string& str);
};

#endif

