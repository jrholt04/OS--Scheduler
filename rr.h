// File: rr.h
// Author: J Holt, N Neagle, and A Seng, Transy U
// Course: CS 3074 Operating Systems
//
// Header file for Round Robin

#ifndef RR_H
#define RR_H

#include <string>
#include <iostream>
#include <vector>
#include "PCB.h"

using namespace std;

// Round Robin scheduler
void rr(vector<PCB> tasks, bool verbose, int quanta);

// Runs the simulation for the Round Robin Scheduler
void rrSimulation(vector<PCB> PCBList, vector<int>& waitTimes, vector<int>& startTimes, int quanta);

#endif 
