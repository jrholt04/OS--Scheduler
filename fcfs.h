// File: fcfs.h
// Author: N Neagle, J Holt, and A Seng, Transy U
// Course: CS 3074 Operating Systems
//
// header file for the First Come First Serve scheduling algorithm
#include <string>
#include <iostream>
#include <queue>
#include <cstdio>
#include "PCB.h"

using namespace std;

// Main function that will immitate fcfs alg
void fcfs(vector<PCB> tasks, bool verbose);

// Creates an ordered vector based on arrival time
vector<PCB> createFcfsV(vector<PCB> tasks);

// Calculates average wait time of fcfs for that set of PCB's
int getAvgWait(vector<PCB> fcfsV);