// File: nonpresjf.cpp
// Author: J Holt, N Neagle, and A Seng, Transy U
// Course: CS 3074 Operating Systems
//
// Implementation of Non-Preemptive SJF

#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include "PCB.h"
#include "nonpresjf.h"

using namespace std;

void nonpresjf(vector<PCB> tasks, bool verbose) {
    int n = tasks.size();
    vector<bool> finished(n, false);
    vector<int> waitTimes(n, 0);
    vector<int> startTimes(n, -1);
    int completed = 0;
    int time = 0;

    while (completed < n) {
        int minIndex = -1;
        int minBurst = 999999;

        // Find the shortest job that has arrived and is not finished
        for (int i = 0; i < n; i++) {
            if (!finished[i] && tasks[i].getArrivalTime() <= time && tasks[i].getBurst() < minBurst) {
                minBurst = tasks[i].getBurst();
                minIndex = i;
            }
        }

        if (minIndex == -1) {
            time++;
            continue;
        }

        // Record when process starts
        if (startTimes[minIndex] == -1)
            startTimes[minIndex] = time;

        // Calculate waiting time for process
        waitTimes[minIndex] = time - tasks[minIndex].getArrivalTime();

        // Run the process
        time += tasks[minIndex].getBurst();
        finished[minIndex] = true;
        completed++;
    }

    // Compute average waiting time
    double totalWait = 0.0;
    for (int i = 0; i < n; i++) totalWait += waitTimes[i];
    double avgWait = totalWait / n;

    if (verbose) {
        cout << endl << "===== Non-Preemptive SJF Execution Details =====" << endl;
        for (int i = 0; i < n; i++) {
            cout << "id: " << tasks[i].getId() << endl;
            cout << "executed for: " << tasks[i].getBurst() << endl;
            cout << "enter time: " << tasks[i].getArrivalTime() << endl;
            cout << "execution at: " << startTimes[i] << endl << endl;
        }
    }

    cout << "average wait time of nonpremptive sjf: " << avgWait << endl;
}