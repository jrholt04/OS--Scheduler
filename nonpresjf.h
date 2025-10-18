// File: nonpresjf.h
// Author: N Neagle, J Holt, and A Seng, Transy U
// Course: CS 3074 Operating Systems
//
// Header file for Non-Preemptive SJF

#ifndef NONPRESJF_H
#define NONPRESJF_H

#include <vector>
#include "PCB.h"
using namespace std;

void nonpresjf(vector<PCB> tasks, bool verbose);

#endif
