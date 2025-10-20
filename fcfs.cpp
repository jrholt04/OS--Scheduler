// File: fcfs.cpp
// Author: J Holt, N Neagle, and A Seng, Transy U
// Course: CS 3074 Operating Systems
//
// Implementation of the First Come First Serve scheduling algorithm
#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include "PCB.h"
#include "fcfs.h"

using namespace std;

void fcfs(vector<PCB> processes, bool verbose){
    vector<PCB> scheduledProcesses = createFcfsSchedule(processes);
    vector<int> waitTimes;
    double avgWait = getAvgWait(scheduledProcesses, waitTimes);
   

    if (verbose){
        for (int i = 0; i < scheduledProcesses.size(); i++){
            cout << "id: " << scheduledProcesses[i].getId() << endl;
            cout << "executed for: " << scheduledProcesses[i].getBurst() << endl;
            cout << "enter time: " << scheduledProcesses[i].getArrivalTime() << endl;
            cout << "execution at: " << scheduledProcesses[i].getStartTime() << endl;
            cout << "waited for: " << waitTimes[i] << endl << endl;
        }
    }
    
    cout << "average wait time of fcfs: " << avgWait << endl;

    return;
}

vector<PCB> createFcfsSchedule(vector<PCB> processes){
    vector<PCB> scheduledProcesses;

    //insert sort based on arrival time
    scheduledProcesses.push_back(processes[0]);
    for (size_t i = 1; i < processes.size(); ++i) {
        int j = scheduledProcesses.size() - 1;

        while (j >= 0 && scheduledProcesses[j].getArrivalTime() > processes[i].getArrivalTime()) {
            --j;
        }
        scheduledProcesses.insert(scheduledProcesses.begin() + (j + 1), processes[i]);
    }

    return scheduledProcesses;
}

double getAvgWait(vector<PCB>& scheduledProcesses, vector<int>& waitTimes){
    double currentTime = 0.0;
    double totalWait = 0.0;
    double avgWait;
    for (int i = 0; i < scheduledProcesses.size(); i++){
        
        ///need to account for if there is idle time
        if (currentTime < scheduledProcesses[i].getArrivalTime()) {
            currentTime = scheduledProcesses[i].getArrivalTime();
        }
        
        totalWait = totalWait + (currentTime - scheduledProcesses[i].getArrivalTime());
        waitTimes.push_back((currentTime - scheduledProcesses[i].getArrivalTime()));
        // Updates PCB start time for later reporting.
        scheduledProcesses[i].setStartTime(currentTime); 
        currentTime = currentTime + scheduledProcesses[i].getBurst();
    }
    
    avgWait = totalWait / scheduledProcesses.size();

    return avgWait; 
}