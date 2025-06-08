#ifndef TASK_H
#define TASK_H

#include "DateTime.h"
#include <string>

using namespace std;

class Task {
private:
    string title;
    string description;
    DateTime deadline;
    bool isCompleted;

public:
    Task();
    Task(string t, string d, DateTime dl);
    void markCompleted();
    void display() const;
    bool isDone() const;
    string toFileString() const;
    static Task fromFileString(const string& str);
};

#endif
