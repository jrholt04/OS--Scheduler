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

// Inputs vector of PCB tasks, verbose flag, and time quanta
void rr(vector<PCB> tasks, bool verbose, int quanta);

// Computes start times and wait times for each process
void rrSimulation(vector<PCB> PCBList, vector<int>& waitTimes, vector<int>& startTimes, int quanta);

#endif
