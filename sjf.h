// File: sjf.h
// Author: J Holt, N Neagle, and A Seng, Transy U
// Course: CS 3074 Operating Systems
//
// Header file for the Preemptive SJF

#ifndef SJF_H
#define SJF_H

#include <string>
#include <iostream>
#include <vector>
#include "PCB.h"

using namespace std;

// Non Preemptive SJF scheduler
void sjf(vector<PCB> tasks, bool verbose);

// Runs the simulation for Non Preemptive SJF Scheduler
void sjfSimulation(vector<PCB> PCBList, vector<int>& waitTimes, vector<int>& startTimes);

// Preemptive SJF scheduler
void presjf(vector<PCB> tasks, bool verbose);

// Runs the simulation for Preemptive SJF Scheduler
void presjfSimulation(vector<PCB> PCBList, vector<int>& waitTimes, vector<int>& startTimes);

#endif 
