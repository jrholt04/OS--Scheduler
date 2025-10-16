// File: SchedulerMain.cpp
// Author: N Neagle, J Holt, and A Seng, Transy U
// Course: CS 3074 Operating Systems
//
// Main Program for the a model scheudling algorithm

#include <string>
#include <iostream>
#include <cstdio>
#include <vector>
#include "fcfs.h"
#include "rr.h"
#include "PCB.h"

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
            string type = argv[i +1];
            if (type == "FCFS"){
                type = "fcfs";
                i++;
            }
            else if (type == "RR"){
                type = "rr";
                i++;
            }
            else if (type == "SJF"){
                type = "sjf";
                i++;
            }
            else if (type == "Priority") {
                type = "priority";
                i++;
            }
            else{
                cout << "algorithm type not found" << endl;
                return 0;
            }
            
        }

       if (arg == "--verbose"){
            verbose = true;
       }

       if (arg == "--quanta"){
            int inputQuanta = stoi(argv[i + 1]);
            quanta = inputQuanta;
       }

       if (arg == "--premptive"){
            premptive = true;
       }

       if (arg == "--file"){
            fileName = argv[i + 1];
            i++;
       }

    }
    cout << "type: "<<type << endl;
    cout << "fileName: " << fileName << endl;
    cout << "premptive: " << premptive << endl;
    cout << "quanta: " << quanta << endl;
    cout << "verbose: " << verbose << endl;

    PCBList = PCB::readPCBFile(fileName);

    fcfs(PCBList, verbose);
    rr(PCBList, verbose, quanta);

    return 0;           
}