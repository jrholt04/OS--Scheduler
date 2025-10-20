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
#include "schedulerTools.h"

using namespace std;

void rr(vector<PCB> tasks, bool verbose, int quanta) {
    vector<int> waitTimes(tasks.size(), 0);
    vector<int> startTimes(tasks.size(), -1);

    rrSimulation(tasks, waitTimes, startTimes, quanta);

    double avgWait = calculateAvgWait(waitTimes);

    if (verbose) {
        printVerbose(tasks, startTimes, waitTimes, "Round Robin");
    }

    cout << "Average wait time of Round Robin: " << avgWait << endl;
}

void rrSimulation(vector<PCB> PCBList, vector<int>& waitTimes, vector<int>& startTimes, int quanta) {
    int n = PCBList.size();
    vector<int> remainingBurst(n);

    for (int i = 0; i < n; i++) {
        remainingBurst[i] = PCBList[i].getBurst();
    }

    // If two processes arrive at the same time, sort by PID.
    vector<int> indices(n);
    for (int i = 0; i < n; ++i) indices[i] = i;

    sort(indices.begin(), indices.end(), [&](int a, int b) {
        if (PCBList[a].getArrivalTime() == PCBList[b].getArrivalTime())
            return PCBList[a].getPID() < PCBList[b].getPID();
        return PCBList[a].getArrivalTime() < PCBList[b].getArrivalTime();
    });

    queue<int> readyQueue;
    int time = 0;
    int completed = 0;
    int nextToArrive = 0;

    while (completed < n) {
        // Add processes that have arrived by this time
        while (nextToArrive < n && PCBList[indices[nextToArrive]].getArrivalTime() <= time) {
            readyQueue.push(indices[nextToArrive]);
            nextToArrive++;
        }

        // If queue is empty, CPU is idle
        if (readyQueue.empty()) {
            time++;
            continue;
        }

        // Get next process to execute
        int i = readyQueue.front();
        readyQueue.pop();

        // Record start time if this is the first execution
        if (startTimes[i] == -1)
            startTimes[i] = time;

        // Determine how long the process will run
        int runTime = min(quanta, remainingBurst[i]);
        remainingBurst[i] -= runTime;
        time += runTime;

        // Add any new arrivals 
        while (nextToArrive < n && PCBList[indices[nextToArrive]].getArrivalTime() <= time) {
            readyQueue.push(indices[nextToArrive]);
            nextToArrive++;
        }

        // If still has time left, push to back of queue
        if (remainingBurst[i] > 0) {
            readyQueue.push(i);
        } else {
            // Process finished, compute wait time
            completed++;
            int finishTime = time;
            waitTimes[i] = finishTime - PCBList[i].getArrivalTime() - PCBList[i].getBurst();
        }
    }
}
