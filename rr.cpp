// File: rr.cpp
// Author: N Neagle, J Holt, and A Seng, Transy U
// Course: CS 3074 Operating Systems
//
// Implementation of Round Robin

#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include "PCB.h"
#include "rr.h"

using namespace std;

void rr(vector<PCB> tasks, bool verbose, int quanta) {
    // Sort by arrival time
    vector<PCB> readyList;
    readyList.push_back(tasks[0]);
    for (size_t i = 1; i < tasks.size(); ++i) {
        int j = readyList.size() - 1;
        while (j >= 0 && readyList[j].getArrivalTime() > tasks[i].getArrivalTime()) {
            j--;
        }
        readyList.insert(readyList.begin() + (j + 1), tasks[i]);
    }

    vector<int> remaining;
    for (size_t i = 0; i < readyList.size(); ++i) {
        remaining.push_back(readyList[i].getBurst());
    }

    int time = 0;
    int completed = 0;
    int n = readyList.size();
    vector<int> waitTimes(n, 0);
    vector<int> startTimes(n, -1);

    while (completed < n) {
        bool progress = false;

        for (int i = 0; i < n; i++) {
            if (remaining[i] <= 0 || readyList[i].getArrivalTime() > time) continue;

            progress = true;
            if (startTimes[i] == -1) startTimes[i] = time; // record first start time
            int runTime = (remaining[i] < quanta) ? remaining[i] : quanta;

            remaining[i] -= runTime;
            time += runTime;

            for (int j = 0; j < n; j++) {
                if (j != i && remaining[j] > 0 && readyList[j].getArrivalTime() <= time) {
                    waitTimes[j] += runTime;
                }
            }

            if (remaining[i] <= 0) {
                completed++;
            }
        }

        if (!progress) {
            time++;
        }
    }

    // Calculate average wait time
    double totalWait = 0.0;
    for (int i = 0; i < n; i++) totalWait += waitTimes[i];
    double avgWait = totalWait / n;

    if (verbose) {
        cout << endl << "===== Round Robin Execution Details =====" << endl;
        for (int i = 0; i < n; i++) {
            cout << "id: " << readyList[i].getId() << endl;
            cout << "executed for: " << readyList[i].getBurst() << endl;
            cout << "enter time: " << readyList[i].getArrivalTime() << endl;
            cout << "execution at: " << startTimes[i] << endl << endl;
        }
    }

    cout << "average wait time of rr: " << avgWait << endl;
}
