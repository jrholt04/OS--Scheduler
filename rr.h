// File: rr.h
// Author: N Neagle, J Holt, and A Seng, Transy U
// Course: CS 3074 Operating Systems
//
// Header file for Round Robin s

#ifndef RR_H
#define RR_H

#include <string>
#include <iostream>
#include <vector>
#include "PCB.h"

using namespace std;

// Round Robin scheduler
void rr(vector<PCB> tasks, bool verbose, int quanta);

#endif 
