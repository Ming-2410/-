#include "TaskManager.h"
#include <fstream>
#include <iostream>

using namespace std;

void TaskManager::addTask(const Task& task) {
    tasks.push_back(task);
}

void TaskManager::listTasks() const {
    if (tasks.empty()) {
        cout << "�ثe�S��������ȡC\n";
        return;
    }

    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << "���Ƚs���G" << i + 1 << "\n";
        tasks[i].display();
        cout << "--------------------------\n";
    }
}

void TaskManager::markTaskDone(int index) {
    if (index >= 1 && index <= static_cast<int>(tasks.size())) {
        tasks[index - 1].markCompleted();
        cout << "���Ȥw�аO�������C\n";
    }
    else {
        cout << "�L�Ī����Ƚs���C\n";
    }
}

void TaskManager::saveToFile(const string& filename) const {
    ofstream outFile(filename);
    if (!outFile) {
        cout << "�L�k�x�s�ɮסC\n";
        return;
    }

    for (const auto& task : tasks) {
        outFile << task.toFileString() << endl;
    }

    outFile.close();
    cout << "�w���\�x�s�� " << filename << "\n";
}

void TaskManager::loadFromFile(const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cout << "�䤣���ɮסA�N�إ߷s�M��C\n";
        return;
    }

    tasks.clear();
    string line;
    while (getline(inFile, line)) {
        tasks.push_back(Task::fromFileString(line));
    }

    inFile.close();
    cout << "�w���\�q " << filename << " ���J���ȡC\n";
}
