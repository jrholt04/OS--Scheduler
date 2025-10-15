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

void fcfs(vector<PCB> tasks, bool verbose);