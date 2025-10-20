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

    // Output the average wait time for the RR algorithm
    cout << "Average wait time of Round Robin: " << avgWait << endl;
}

//Round Robin simulation, calculating wait times and start times based on arrival order, time quanta, and remaining burst times.
void rrSimulation(vector<PCB> PCBList, vector<int>& waitTimes, vector<int>& startTimes, int quanta) {
    // Sort all processes by their arrival time
    sort(PCBList.begin(), PCBList.end(), [](const PCB& a, const PCB& b) {
        return a.getArrivalTime() < b.getArrivalTime();
    });

    // Initialize remaining burst times for each process.
    int n = PCBList.size();
    vector<int> remainingBurst(n);
    for (int i = 0; i < n; i++) {
        remainingBurst[i] = PCBList[i].getBurst();
    }
    
    queue<int> readyQueue;

    // Keep track of simulation time, number completed, and next process to add
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

        if (startTimes[i] == -1) {
            startTimes[i] = time;
        }
        
        // Determine how long the process will run.
        int runTime = min(quanta, remainingBurst[i]);
        remainingBurst[i] -= runTime;
        time += runTime;

        // Add any new arrivals that occurred during that run.
        while (nextProcess < n && PCBList[nextProcess].getArrivalTime() <= time) {
            readyQueue.push(nextProcess);
            nextProcess++;
        }

        if (remainingBurst[i] > 0) {
            readyQueue.push(i);
        } else {
            completed++;
            int finishTime = time;
            waitTimes[i] = finishTime - PCBList[i].getArrivalTime() - PCBList[i].getBurst();
        }
    }
}
