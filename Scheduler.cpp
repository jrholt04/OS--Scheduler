// File: Scheduler.cpp 
// Author: J Holt, N Neagle, and A Seng, Transy U
// Course: CS 3074 Operating Systems
//
// Main Program for a model scheduling algorithm 

#include <string>
#include <iostream>
#include <cstdio>
#include <vector>
#include "fcfs.h"
#include "rr.h"
#include "priority.h"
#include "sjf.h"
#include "PCB.h"
#include "schedulerTools.h"

using namespace std;

int main (int argc, char **argv) {
  string type = "fcfs";
  string fileName = "sched.in";
  bool premptive = false;
  bool verbose = false;
  int quanta = 10;
  vector<PCB> PCBList;
  
  for (int i = 1; i < argc; ++i) { // start at 1 to skip program name
    string arg = argv[i];
    
    if (arg == "--type" || arg == "-t") { 
      string inputType = argv[i + 1];
      type = interpretType (inputType);
      if (type == "error") {
	cout << "Algorithm type not found" << endl;
	exit(1);
      }
    }
    
    if (arg == "--verbose" || arg == "-v"){
      verbose = true;
    }
    
    if (arg == "--quanta" || arg == "-q"){
      int inputQuanta = stoi(argv[i + 1]);
      if (inputQuanta <= 0){
	cout << "non-valid Quanta" << endl;
	exit(1);
      }
      quanta = inputQuanta;
    }
    
    if (arg == "--preemptive" || arg == "-p"){
      premptive = true;
    }
    
    if (arg == "--file" || arg == "-f"){
      fileName = argv[i + 1];
      i++;
    }
    
    if (arg == "--help" || arg == "-h") {
      printSchedulerHelp();
      return 0;
    }
  }
  if (verbose){
    cout << "type: "<<type << endl;
    cout << "fileName: " << fileName << endl;
    cout << "premptive: " << premptive << endl;
    cout << "quanta: " << quanta << endl;
    cout << "verbose: " << verbose << endl;
  }
  
  PCBList = PCB::readPCBFile(fileName);
  
  double avgWaitTime = 0.0;
  if (type == "fcfs") {
    avgWaitTime = fcfs(PCBList, verbose);
    cout << "Average wait for FCFS: " << avgWaitTime << endl;
  }
  else if (type == "rr") {
    avgWaitTime = rr(PCBList, verbose, quanta);
    cout << "Average wait for RR: " << avgWaitTime << endl;
  }
  else if (type == "sjf") {
    if (premptive) {
      avgWaitTime = presjf(PCBList, verbose);
      cout << "Average wait for Preemptive SJF: "<< avgWaitTime << endl;
    }
    else {
      avgWaitTime = sjf(PCBList, verbose);
      cout << "Average wait for SJF: "<< avgWaitTime << endl;
    }
  }
  else if (type == "priority") {
    if (premptive) {
      avgWaitTime = prePriority(PCBList, verbose);
      cout << "Average wait for Preemptive Priority: "<< avgWaitTime << endl;
    }
    else {
      avgWaitTime = nonprePriority(PCBList, verbose);
      cout << "Average wait for Priority: "<< avgWaitTime << endl;
    }
  }
  return 0;           
}
