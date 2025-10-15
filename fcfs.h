// File: fcfs.h
// Author: N Neagle, J Holt, and A Seng, Transy U
// Course: CS 3074 Operating Systems
//
// header file for the First Come First Serve scheduling algorithm
#ifndef FCFS_H
#define FCFS_H

#include <string>
#include <iostream>
#include <queue>
#include <cstdio>
#include "PCB.h"

using namespace std;

// Simulates the FCFS scheduling algorithm.
void fcfs(vector<PCB> processes, bool verbose);

// Returns a new vector of PCBs sorted by arrival time (earliest first).
vector<PCB> createFcfsSchedule(vector<PCB> processes);

// Calculates and returns the average waiting time for a set of processes
int getAvgWait(vector<PCB>& scheduledProcesses);

#endif