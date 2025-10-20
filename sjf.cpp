// File: sjf.cpp
// Author: J Holt, N Neagle, and A Seng, Transy U
// Course: CS 3074 Operating Systems
//
// Implementation of Non-Preemptive and Preemptive SJF

#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include "PCB.h"
#include "sjf.h"
#include "schedulerTools.h"

using namespace std;

double sjf(vector<PCB> tasks, bool verbose) {
  vector<int> waitTimes(tasks.size(), 0);
  vector<int> startTimes(tasks.size(), -1);

  sjfSimulation(tasks, waitTimes, startTimes);

  double avgWait = calculateAvgWait(waitTimes);

  if (verbose) {
    printVerbose(tasks, startTimes, waitTimes, "Non Preemptive SJF");
  }

  return avgWait;
}

void sjfSimulation(vector<PCB> PCBList, vector<int>& waitTimes, vector<int>& startTimes) {
  int numberOfProcesses = PCBList.size();
  vector<bool> finished(numberOfProcesses, false);
  int completed = 0;
  int time = 0;
  
  while (completed < numberOfProcesses) {
    int minIndex = -1;
    int minBurst = 999999;
    
    for (int i = 0; i < numberOfProcesses; i++) {
      if (!finished[i] && (PCBList[i].getArrivalTime() <= time) && (PCBList[i].getBurst() < minBurst)) {
	minBurst = PCBList[i].getBurst();
	minIndex = i;
      }
    }
    
    if (minIndex == -1) {
      time++;
      continue;
    }
    
    if (startTimes[minIndex] == -1)
      startTimes[minIndex] = time;
    
    waitTimes[minIndex] = time - PCBList[minIndex].getArrivalTime();
    
    time += PCBList[minIndex].getBurst();
    finished[minIndex] = true;
    completed++;
  }
}

double presjf(vector<PCB> tasks, bool verbose) {
  vector<int> waitTimes(tasks.size(), 0);
  vector<int> startTimes(tasks.size(), -1);

  presjfSimulation(tasks, waitTimes, startTimes);

  double avgWait = calculateAvgWait(waitTimes);
  
  if (verbose) {
    printVerbose(tasks, startTimes, waitTimes, "Preemptive SJF");
  }
  
  return avgWait;
}

void presjfSimulation(vector<PCB> PCBList, vector<int>& waitTimes, vector<int>& startTimes) {
  int numberOfProcesses = PCBList.size();
  vector<int> remainingTime(numberOfProcesses);
  vector<bool> finished(numberOfProcesses, false);
  
  for (int i = 0; i < numberOfProcesses; i++) {
    remainingTime[i] = PCBList[i].getBurst();
  }
  
  int completed = 0;
  int time = 0;
  
  while (completed < numberOfProcesses) {
    int minIndex = -1;
    int minBurst = 999999;
    
    for (int i = 0; i < numberOfProcesses; i++) {
      if (!finished[i] && (PCBList[i].getArrivalTime() <= time) && (remainingTime[i] < minBurst) && (remainingTime[i] > 0)) {
	minBurst = remainingTime[i];
	minIndex = i;
      }
    }
    
    if (minIndex == -1) {
      time++;
      continue;
    }
    
    if (startTimes[minIndex] == -1) {
      startTimes[minIndex] = time;
    }
    
    for (int i = 0; i < numberOfProcesses; i++) {
      if (i != minIndex && !finished[i] && PCBList[i].getArrivalTime() <= time) {
	waitTimes[i]++;
      }
    }
    
    remainingTime[minIndex]--;
    time++;
    
    if (remainingTime[minIndex] == 0) {
      finished[minIndex] = true;
      completed++;
    }
  }
  return;

}
