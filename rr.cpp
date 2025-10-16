// File: rr.cpp
// Author: N Neagle, J Holt, and A Seng, Transy U
// Course: CS 3074 Operating Systems
//
// Implementation of Round Robin 

#include <iostream>
#include <vector>
#include <string>
#include "rr.h"
#include "PCB.h"

void rr(vector<PCB> tasks, bool verbose, int quanta) {
    // Sort processes by arrival time 
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
    vector<int> waitTimes(readyList.size(), 0);

    if (verbose) {
        cout << endl << "Starting Round Robin Scheduling (quantum = " << quanta << ")" << endl;
    }

    while (completed < (int)readyList.size()) {
        bool progress = false;

        for (size_t i = 0; i < readyList.size(); ++i) {
            if (remaining[i] <= 0 || readyList[i].getArrivalTime() > time) continue;

            progress = true;
            int runTime = (remaining[i] < quanta) ? remaining[i] : quanta;

            if (verbose) {
                cout << "Time " << time << ": running " << readyList[i].getId()
                     << " for " << runTime << " units" << endl;
            }

            time += runTime;
            remaining[i] -= runTime;

            // Update waiting times for other ready processes
            for (size_t j = 0; j < readyList.size(); ++j) {
                if (j != i && remaining[j] > 0 && readyList[j].getArrivalTime() <= time) {
                    waitTimes[j] += runTime;
                }
            }

            // If finished
            if (remaining[i] <= 0) {
                completed++;
                if (verbose) {
                    cout << "Process " << readyList[i].getId() << " completed at time " << time << endl;
                }
            }
        }

        if (!progress) {
            time++;
        }
    }

    // Calculate average wait time
    double totalWait = 0.0;
    for (size_t i = 0; i < waitTimes.size(); ++i) {
        totalWait += waitTimes[i];
    }
    double avgWait = totalWait / waitTimes.size();

    cout << endl << "Average wait time (Round Robin): " << avgWait << endl;
}
