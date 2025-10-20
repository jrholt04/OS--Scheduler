// File: rr.cpp
// Author: N Neagle, J Holt, and A Seng, Transy U
// Course: CS 3074 Operating Systems
//
// Round Robin

#include <iostream>
#include <vector>
#include <queue>          
#include "PCB.h"
#include "rr.h"

using namespace std;

void rr(vector<PCB> tasks, bool verbose, int quanta) {
    vector<int> waitTimes(tasks.size(), 0);
    vector<int> startTimes(tasks.size(), -1);

    rrSimulation(tasks, waitTimes, startTimes, quanta);
    // avg wait time
    double totalWait = 0.0;
    for (int i = 0; i < waitTimes.size(); i++) {
        totalWait += waitTimes[i];
    }
    double avgWait = totalWait / waitTimes.size();

    if (verbose) {
        cout << endl << "===== Round Robin Execution Details =====" << endl;
        for (int i = 0; i < tasks.size(); i++) {
            cout << "id: " << tasks[i].getId() << endl;
            cout << "executed for: " << tasks[i].getBurst() << endl;
            cout << "enter time: " << tasks[i].getArrivalTime() << endl;
            cout << "execution at: " << startTimes[i] << endl;
            cout << "wait time: " << waitTimes[i] << endl << endl;
        }
    }

    cout << "Average wait time of Round Robin: " << avgWait << endl;
}

void rrSimulation(vector<PCB> PCBList, vector<int>& waitTimes, vector<int>& startTimes, int quanta) {
    int n = PCBList.size();
    
    // Initialize remaining burst times for each process.
    vector<int> remainingBurst(n);
    for (int i = 0; i < n; i++) {
        remainingBurst[i] = PCBList[i].getBurst();
    }

    // Create the ready queue for processes ready to run.
    queue<int> readyQueue;

    // simulation time, number completed, and next process to add
    int time = 0;
    int completed = 0;
    int nextProcess = 0;

    while (completed < n) {
        while (nextProcess < n && PCBList[nextProcess].getArrivalTime() <= time) {
            readyQueue.push(nextProcess);
            nextProcess++;
        }

        if (readyQueue.empty()) {
            time++;
            continue;
        }

        int i = readyQueue.front();
        readyQueue.pop();

        // record start time
        if (startTimes[i] == -1) {
            startTimes[i] = time;
        }

        // Determine how long the process will run.
        int runTime = min(quanta, remainingBurst[i]);
        remainingBurst[i] -= runTime;
        time += runTime;

        while (nextProcess < n && PCBList[nextProcess].getArrivalTime() <= time) {
            readyQueue.push(nextProcess);
            nextProcess++;
        }

        if (remainingBurst[i] > 0) {
            // Process not finished — back of the queue
            readyQueue.push(i);
        } else {
            // Process is done — calculate its wait time:
            completed++;
            int finishTime = time;
            waitTimes[i] = finishTime - PCBList[i].getArrivalTime() - PCBList[i].getBurst();
        }
    }
}
