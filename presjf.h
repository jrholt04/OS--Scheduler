// File: presj.h
// Author: N Neagle, J Holt, and A Seng, Transy U
// Course: CS 3074 Operating Systems
//
// Header file for the Preemptive SJF

#ifndef PRESJ_H
#define PRESJ_H

#include <string>
#include <iostream>
#include <vector>
#include "PCB.h"

using namespace std;

// Preemptive SJF scheduler
void presj(vector<PCB> tasks, bool verbose);

#endif 