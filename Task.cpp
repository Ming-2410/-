#include "Task.h"
#include <iostream>
#include <sstream>

using namespace std;

Task::Task() : title(""), description(""), deadline(), isCompleted(false) {}

Task::Task(string t, string d, DateTime dl)
    : title(t), description(d), deadline(dl), isCompleted(false) {
}

void Task::markCompleted() {
    isCompleted = true;
}

void Task::display() const {
    cout << "標題： " << title << "\n";
    cout << "說明： " << description << "\n";
    cout << "截止時間： ";
    deadline.display();
    cout << "\n狀態： ";
    if (isCompleted) {
        cout << "已完成";
    }
    else if (deadline.isPast()) {
        cout << "已過期";
    }
    else {
        cout << "未完成";
    }
    cout << "\n";
}

bool Task::isDone() const {
    return isCompleted;
}

string Task::toFileString() const {
    return title + "|" + description + "|" + deadline.toString() + "|" + (isCompleted ? "1" : "0");
}

Task Task::fromFileString(const string& str) {
    istringstream iss(str);
    string t, d, datetimeStr;
    string segment;
    getline(iss, t, '|');
    getline(iss, d, '|');
    getline(iss, datetimeStr, '|');
    string doneStr;
    getline(iss, doneStr);
    DateTime dt = DateTime::fromString(datetimeStr);
    Task task(t, d, dt);
    if (doneStr == "1") task.markCompleted();
    return task;
}
