// File schedulerTools.h
// Author: J Holt, N Neagle, and A Seng, Transy U
// Course: CS 3074 Operating Systems
//
// Header file for OS Scheduler Tools

#ifndef SCHEDULERTOOLS_H
#define SCHEDULERTOOLS_H

#include <vector>
#include "PCB.h"
using namespace std;

// sorts the given vector of PCBs by arrival time and puts in in the output vector
void sortPCBArrivalTime(vector<PCB> PCBList, vector<PCB>& output);

// calculates the average wait time of all processes
double calculateAvgWait(vector<int> waitTimes);

// prints out information information about the processes, including their ID, CPU Burst, Arrival Time, Start Time, and Wait Time.
void printVerbose(vector<PCB> PCBList, vector<int> startTimes, vector<int> waitTimes, string algorithm);

// prints out helpful information about the program
void printSchedulerHelp(void);

// interprets the type given through the command line and returns a string that indicates the selected scheduling algorithm
string interpretType (string inputType);

#endif  // SCHEDULERTOOLS_H
