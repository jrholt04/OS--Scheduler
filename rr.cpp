// File: rr.cpp
// Author: N Neagle, J Holt, and A Seng, Transy U
// Course: CS 3074 Operating Systems
//
// Implementation of Round Robin

#include <iostream>
#include <vector>
#include <string>
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

  vector<int> remaining;
  for (size_t i = 0; i < numberOfProcesses; ++i) {
    remaining.push_back(readyList[i].getBurst());
  }
  
  int time = 0;
  int completed = 0;
      
  while (completed < numberOfProcesses) {
    bool progress = false;
    
    for (int i = 0; i < numberOfProcesses; i++) {
      if (remaining[i] <= 0 || readyList[i].getArrivalTime() > time) continue;
      
      progress = true;
      if (startTimes[i] == -1) startTimes[i] = time; // record first start time
      int runTime = (remaining[i] < quanta) ? remaining[i] : quanta;
      
      remaining[i] -= runTime;
      time += runTime;
      
      for (int j = 0; j < numberOfProcesses; j++) {
	if (j != i && remaining[j] > 0 && readyList[j].getArrivalTime() <= time) {
	  waitTimes[j] += runTime;
	}
      }
      
      if (remaining[i] <= 0) {
	completed++;
      }
    }
    
    if (!progress) {
      time++;
    }
  }
}
