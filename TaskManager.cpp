#include "TaskManager.h"
#include <fstream>
#include <iostream>

using namespace std;

void TaskManager::addTask(const Task& task) {
    tasks.push_back(task);
}

void TaskManager::listTasks() const {
    if (tasks.empty()) {
        cout << "目前沒有任何任務。\n";
        return;
    }

    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << "任務編號：" << i + 1 << "\n";
        tasks[i].display();
        cout << "--------------------------\n";
    }
}

void TaskManager::markTaskDone(int index) {
    if (index >= 1 && index <= static_cast<int>(tasks.size())) {
        tasks[index - 1].markCompleted();
        cout << "任務已標記為完成。\n";
    }
    else {
        cout << "無效的任務編號。\n";
    }
}

void TaskManager::saveToFile(const string& filename) const {
    ofstream outFile(filename);
    if (!outFile) {
        cout << "無法儲存檔案。\n";
        return;
    }

    for (const auto& task : tasks) {
        outFile << task.toFileString() << endl;
    }

    outFile.close();
    cout << "已成功儲存至 " << filename << "\n";
}

void TaskManager::loadFromFile(const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cout << "找不到檔案，將建立新清單。\n";
        return;
    }

    tasks.clear();
    string line;
    while (getline(inFile, line)) {
        tasks.push_back(Task::fromFileString(line));
    }

    inFile.close();
    cout << "已成功從 " << filename << " 載入任務。\n";
}
