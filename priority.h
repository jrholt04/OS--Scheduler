// File: priority.h
// Author: J Holt, N Neagle, and A Seng, Transy U
// Course: CS 3074 Operating Systems
//
// Header file for Priority Scheduler

#ifndef PRIORITY_H
#define PRIORITY_H

#include <vector>
#include "PCB.h"
using namespace std;

// Preemptive Priority Scheduler
double prePriority(vector<PCB> tasks, bool verbose);

// Runs the simulation for the Preemptive Priority Scheduler
void prePrioritySimulation(vector<PCB> PCBList, vector<int>& waitTimes, vector<int>& startTimes);

// Non Preemptive Priority Scheduler
double nonprePriority(vector<PCB> tasks, bool verbose);

// Runs the simulation for Non Preemptive Priority Scheduler
void nonprePrioritySimulation(vector<PCB> PCBList, vector<int>& waitTimes, vector<int>& startTimes);

#endif