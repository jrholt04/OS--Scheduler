// File: Scheduler.cpp 
// Author: N Neagle, J Holt, and A Seng, Transy U
// Course: CS 3074 Operating Systems
//
// Main Program for a model scheduling algorithm 

#include <string>
#include <iostream>
#include <cstdio>
#include <vector>
#include "fcfs.h"
#include "rr.h"
#include "sjf.h"
#include "priority.h"
#include "PCB.h"
#include "schedulerTools.h"

using namespace std;

int main (int argc, char **argv) {
    char c;
    string type = "fcfs";
    string fileName = "sched.in";
    bool premptive = false;
    bool verbose = false;
    int quanta = 10;
    vector<PCB> PCBList;

    for (int i = 1; i < argc; ++i) { // start at 1 to skip program name
        string arg = argv[i];
        
        if (arg == "--type") { 
            string inputType = argv[i + 1];
            if (inputType == "FCFS" || inputType == "fcfs"){
                type = "fcfs";
                i++;
            }
            else if (inputType == "RR" || inputType == "rr"){
                type = "rr";
                i++;
            }
            else if (inputType == "SJF" || inputType == "sjf"){
                type = "sjf";
                i++;
            }
            else if (inputType == "priority" || inputType == "PRIORITY" || inputType == "Priority") {
                type = "priority";
                i++;
            }
            else{
                cout << "Algorithm type not found" << endl;
                return 0;
            }
        }
       if (arg == "--verbose" || arg == "--v"){
            verbose = true;
       }
       if (arg == "--quanta" || arg == "--q"){
            int inputQuanta = stoi(argv[i + 1]);
            quanta = inputQuanta;
       }
       if (arg == "--preemptive" || arg == "--p"){
            premptive = true;
       }
       if (arg == "--file" || arg == "--f"){
            fileName = argv[i + 1];
            i++;
       }
       if (arg == "--help" || arg == "--h") {
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
    
    if (type == "fcfs") {
        fcfs(PCBList, verbose);
    }
    else if (type == "rr") {
        rr(PCBList, verbose, quanta);
    }
    else if (type == "sjf") {
        if (premptive) {
            presjf(PCBList, verbose);
        }
        else {
            sjf(PCBList, verbose);
        }
    }
    else if (type == "priority") {
      if (premptive) {
	prePriority(PCBList, verbose);
      }
      else {
	nonprePriority(PCBList, verbose);
      }
    }
    
    return 0;           
}
