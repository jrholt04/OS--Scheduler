// File: presj.cpp
// Author: N Neagle, J Holt, and A Seng, Transy U
// Course: CS 3074 Operating Systems
//
// Implementation of Preemptive SJF

#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include "PCB.h"
#include "presjf.h"

using namespace std;

void presj(vector<PCB> tasks, bool verbose) {
    int n = tasks.size();
    vector<int> remaining(n);
    vector<int> waitTimes(n, 0);
    vector<int> startTimes(n, -1);
    vector<bool> finished(n, false);

    for (int i = 0; i < n; i++) remaining[i] = tasks[i].getBurst();

    int completed = 0;
    int time = 0;

    while (completed < n) {
        int minIndex = -1;
        int minBurst = 999999;

        for (int i = 0; i < n; i++) {
            if (!finished[i] && tasks[i].getArrivalTime() <= time && remaining[i] < minBurst && remaining[i] > 0) {
                minBurst = remaining[i];
                minIndex = i;
            }
        }

        if (minIndex == -1) {
            time++;
            continue;
        }

        if (startTimes[minIndex] == -1) startTimes[minIndex] = time;

        remaining[minIndex]--;
        time++;

        for (int i = 0; i < n; i++) {
            if (i != minIndex && !finished[i] && tasks[i].getArrivalTime() <= time) {
                waitTimes[i]++;
            }
        }

        if (remaining[minIndex] == 0) {
            finished[minIndex] = true;
            completed++;
        }
    }

    double totalWait = 0.0;
    for (int i = 0; i < n; i++) totalWait += waitTimes[i];
    double avgWait = totalWait / n;

    if (verbose) {
        cout << endl << "===== Preemptive SJF Execution Details =====" << endl;
        for (int i = 0; i < n; i++) {
            cout << "id: " << tasks[i].getId() << endl;
            cout << "executed for: " << tasks[i].getBurst() << endl;
            cout << "enter time: " << tasks[i].getArrivalTime() << endl;
            cout << "execution at: " << startTimes[i] << endl << endl;
        }
    }

    cout << "average wait time of presjf: " << avgWait << endl;
}