#include "TaskManager.h"
#include "DateTime.h"
#include <iostream>

using namespace std;

void showMenu() {
    cout << "======= 任務管理行事曆 =======\n";
    cout << "1. 新增任務\n";
    cout << "2. 列出任務\n";
    cout << "3. 標記任務為完成\n";
    cout << "4. 儲存任務到檔案\n";
    cout << "5. 從檔案讀取任務\n";
    cout << "0. 結束程式\n";
    cout << "請輸入選項：";
}

void run(TaskManager& manager) {
    int choice;
    do {
        showMenu();
        cin >> choice;
        cin.ignore(); // 清除換行符號

        if (choice == 1) {
            string title, description;
            int y, m, d, h, min;

            cout << "請輸入標題：";
            getline(cin, title);
            cout << "請輸入說明：";
            getline(cin, description);
            cout << "請輸入截止日期（年 月 日 時 分）：";
            cin >> y >> m >> d >> h >> min;
            cin.ignore();

            DateTime dt(y, m, d, h, min);
            Task newTask(title, description, dt);
            manager.addTask(newTask);

        }
        else if (choice == 2) {
            manager.listTasks();

        }
        else if (choice == 3) {
            int idx;
            cout << "請輸入要標記完成的任務編號：";
            cin >> idx;
            manager.markTaskDone(idx);

        }
        else if (choice == 4) {
            manager.saveToFile("行事曆.txt");

        }
        else if (choice == 5) {
            manager.loadFromFile("行事曆.txt");

        }
        else if (choice == 0) {
            cout << "結束程式，掰掰！\n";
        }
        else {
            cout << "無效選項，請重試。\n";
        }

    } while (choice != 0);
}
