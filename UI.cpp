#include "TaskManager.h"
#include "DateTime.h"
#include <iostream>

using namespace std;

void showMenu() {
    cout << "======= ���Ⱥ޲z��ƾ� =======\n";
    cout << "1. �s�W����\n";
    cout << "2. �C�X����\n";
    cout << "3. �аO���Ȭ�����\n";
    cout << "4. �x�s���Ȩ��ɮ�\n";
    cout << "5. �q�ɮ�Ū������\n";
    cout << "0. �����{��\n";
    cout << "�п�J�ﶵ�G";
}

void run(TaskManager& manager) {
    int choice;
    do {
        showMenu();
        cin >> choice;
        cin.ignore(); // �M������Ÿ�

        if (choice == 1) {
            string title, description;
            int y, m, d, h, min;

            cout << "�п�J���D�G";
            getline(cin, title);
            cout << "�п�J�����G";
            getline(cin, description);
            cout << "�п�J�I�����]�~ �� �� �� ���^�G";
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
            cout << "�п�J�n�аO���������Ƚs���G";
            cin >> idx;
            manager.markTaskDone(idx);

        }
        else if (choice == 4) {
            manager.saveToFile("��ƾ�.txt");

        }
        else if (choice == 5) {
            manager.loadFromFile("��ƾ�.txt");

        }
        else if (choice == 0) {
            cout << "�����{���A�T�T�I\n";
        }
        else {
            cout << "�L�Ŀﶵ�A�Э��աC\n";
        }

    } while (choice != 0);
}
