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
    // Sort all processes by arrival time and PID
    sort(PCBList.begin(), PCBList.end(), [](const PCB& a, const PCB& b) {
        if (a.getArrivalTime() == b.getArrivalTime()) {
            return a.getId() < b.getId(); 
        }
        return a.getArrivalTime() < b.getArrivalTime();
    });

    // remaining burst times for each process.
    int n = PCBList.size();
    vector<int> remainingBurst(n);
    for (int i = 0; i < n; i++) {
        remainingBurst[i] = PCBList[i].getBurst();
    }

    queue<int> readyQueue;

    // simulation time, number completed, and next process 
    int time = 0;
    int completed = 0;
    int nextProcess = 0;

    while (completed < n) {
        // Add any processes needed to ready queue
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

        // how long the process will run
        int runTime = min(quanta, remainingBurst[i]);
        remainingBurst[i] -= runTime;
        time += runTime;

        // Add any new arrivals 
        while (nextProcess < n && PCBList[nextProcess].getArrivalTime() <= time) {
            readyQueue.push(nextProcess);
            nextProcess++;
        }

        // If the process still has burst time left, push it, else calculate wait time
        if (remainingBurst[i] > 0) {
            readyQueue.push(i);
        } else {
            completed++;
            int finishTime = time;
            waitTimes[i] = finishTime - PCBList[i].getArrivalTime() - PCBList[i].getBurst();
        }
    }
}
