#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include "Task.h"
#include <vector>
#include <string>

using namespace std;

class TaskManager {
private:
    vector<Task> tasks;

public:
    void addTask(const Task& task);
    void listTasks() const;
    void markTaskDone(int index);
    void saveToFile(const string& filename) const;
    void loadFromFile(const string& filename);
};

#endif
