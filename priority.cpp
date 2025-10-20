// File: priority.cpp
// Author: J Holt, N Neagle, and A Seng, Transy U
// Course: CS 3074 Operating Systems
//
// Implementation file for Priority Scheduler

#include <vector>
#include <iostream>
#include <string>
#include <cstdio>
#include "PCB.h"
#include "priority.h"
#include "schedulerTools.h"
using namespace std;

double prePriority(vector<PCB> tasks, bool verbose) {
  vector<int> waitTimes(tasks.size(), 0);
  vector<int> startTimes(tasks.size(), -1);

  prePrioritySimulation(tasks, waitTimes, startTimes);

  double avgWait = calculateAvgWait(waitTimes);
  
  if (verbose) {
    printVerbose(tasks, startTimes, waitTimes, "Premptive Priority");
  }

  return avgWait;
}

void prePrioritySimulation(vector<PCB> PCBList, vector<int>& waitTimes, vector<int>& startTimes) {
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
    int minPriority = 101;
    
    for (int i = 0; i < numberOfProcesses; i++) {
      if (!finished[i] && (PCBList[i].getArrivalTime() <= time) && (PCBList[i].getPriority() < minPriority) && (remainingTime[i] > 0)) {
	      minPriority = PCBList[i].getPriority();
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
}

double nonprePriority(vector<PCB> tasks, bool verbose) {
  vector<int> startTimes(tasks.size(), -1);
  vector<int> waitTimes(tasks.size(), 0);
  
  nonprePrioritySimulation(tasks, waitTimes, startTimes);
  
  double avgWait = calculateAvgWait(waitTimes);
  
  if (verbose) {
    printVerbose(tasks, startTimes, waitTimes, "Non-Preemptive Priority");
  }
  
  return avgWait;
}

void nonprePrioritySimulation(vector<PCB> PCBList, vector<int>& waitTimes, vector<int>& startTimes) {
  int numberOfProcesses = PCBList.size();
  int time = 0;
  int completed = 0;
  vector<bool> finished(numberOfProcesses, false);
  
  while (completed < numberOfProcesses) {
    int minIndex = -1;
    int minPriority = 101;
    
    for (int i = 0; i < numberOfProcesses; i++) {
      if (!finished[i] && (PCBList[i].getArrivalTime() <= time) && (PCBList[i].getPriority() < minPriority)) {
	minPriority = PCBList[i].getPriority();
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
    
    waitTimes[minIndex] = time - PCBList[minIndex].getArrivalTime();
    
    time += PCBList[minIndex].getBurst();
    finished[minIndex] = true;
    completed++;
  }
  return;
}