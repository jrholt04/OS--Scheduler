// File: fcfs.cpp
// Author: N Neagle, J Holt, and A Seng, Transy U
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

void fcfs(vector<PCB> tasks, bool verbose){
    vector<PCB> fcfsV = createFcfsV(tasks);
    int avgWait = getAvgWait(fcfsV);

    if (verbose){
        //create a verbose play by play
        // Print: when it entered, when it executed, and how long it executed for
    }
    
    cout << "average wait time of fcfs: " << avgWait << endl;

    return;
}

vector<PCB> createFcfsV(vector<PCB> tasks){
    vector<PCB> fcfsV;

    //insert sort
    fcfsV.push_back(tasks[0]);
    for (size_t i = 1; i < tasks.size(); ++i) {
        int j = fcfsV.size() - 1;

        while (j >= 0 && fcfsV[j].getArrivalTime() > tasks[i].getArrivalTime()) {
            --j;
        }
        fcfsV.insert(fcfsV.begin() + (j + 1), tasks[i]);
    }

    return fcfsV;
}

int getAvgWait(vector<PCB> fcfsV){
    int runningTime = 0;
    int totalWait = 0;
    int avgWait;
    for (int i = 0; i < fcfsV.size(); i++){
        totalWait = totalWait + (runningTime - fcfsV[i].getArrivalTime() );
        runningTime = runningTime + fcfsV[i].getBurst();
    }
    
    avgWait = totalWait / fcfsV.size();

    return avgWait; 
}