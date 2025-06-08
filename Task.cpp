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
    cout << "���D�G " << title << "\n";
    cout << "�����G " << description << "\n";
    cout << "�I��ɶ��G ";
    deadline.display();
    cout << "\n���A�G ";
    if (isCompleted) {
        cout << "�w����";
    }
    else if (deadline.isPast()) {
        cout << "�w�L��";
    }
    else {
        cout << "������";
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
