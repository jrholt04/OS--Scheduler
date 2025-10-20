// File: rr.cpp
// Author: N Neagle, J Holt, and A Seng, Transy U
// Course: CS 3074 Operating Systems
//
// Implementation of Round Robin

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cstdio>
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
    vector<PCB> readyList;
    sortPCBArrivalTime(PCBList, readyList);

    int numberOfProcesses = readyList.size();
    vector<int> remaining(numberOfProcesses);
    vector<bool> finished(numberOfProcesses, false);
    vector<bool> inQueue(numberOfProcesses, false);

    for (int i = 0; i < numberOfProcesses; i++) remaining[i] = readyList[i].getBurst();

    queue<int> readyQueue;
    int time = 0;
    int completed = 0;

    while (completed < numberOfProcesses) {
        // Add new processes to the queue
        for (int i = 0; i < numberOfProcesses; i++) {
            if (!inQueue[i] && !finished[i] && readyList[i].getArrivalTime() <= time) {
                readyQueue.push(i);
                inQueue[i] = true;
            }
        }

        if (readyQueue.empty()) {
            time++;
            continue;
        }

        int i = readyQueue.front();
        readyQueue.pop();

        if (startTimes[i] == -1) startTimes[i] = time;

        int runTime = (remaining[i] < quanta) ? remaining[i] : quanta;
        remaining[i] -= runTime;
        time += runTime;

        // Update waiting times for all other processes in queue
        for (int j = 0; j < numberOfProcesses; j++) {
            if (inQueue[j] && j != i && !finished[j])
                waitTimes[j] += runTime;
        }

        // Add any new arrivals
        for (int j = 0; j < numberOfProcesses; j++) {
            if (!inQueue[j] && !finished[j] && readyList[j].getArrivalTime() <= time) {
                readyQueue.push(j);
                inQueue[j] = true;
            }
        }

        if (remaining[i] > 0) {
            readyQueue.push(i); 
        } else {
            finished[i] = true;
            completed++;
        }
    }
}
