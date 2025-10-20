// File: rr.h
// Author: J Holt, N Neagle, and A Seng, Transy U
// Course: CS 3074 Operating Systems
//
// Header file for Round Robin

#ifndef RR_H
#define RR_H

#include <vector>
#include "PCB.h"
using namespace std;

// Top-level Round Robin scheduler call. Handles setup, printing, and calling
void rr(vector<PCB> tasks, bool verbose, int quanta);


// Performs the actual Round Robin CPU scheduling.
void rrSimulation(vector<PCB> PCBList, vector<int>& waitTimes, vector<int>& startTimes, int quanta);

#endif
