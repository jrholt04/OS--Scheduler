// File: SchedulerMain.cpp
// Author: Jackson Holt, Transy U
// Course: CS 3074 Operating Systems
//
// Main Program for the a model scheudling algorithm

#include <string>
#include <iostream>
#include <cstdio>

using namespace std;

int main (int argc, char **argv) {
    char c;
    string type = "fcfs";
    string fileName = "sched.in";
    bool premptive = false;
    bool verbose = false;
    int quanta = 10;

    for (int i = 1; i < argc; ++i) { // start at 1 to skip program name
        string arg = argv[i];
        string arg2 = argv[ i + 1 ];
        
        if (arg == "--type") {
            if (arg2 == "FCFS"){
                type = "fcfs";
                i++;
            }
            else if (arg2 == "RR"){
                type = "rr";
                i++;
            }
            else if (arg2 == "SJF"){
                type = "sjf";
                i++;
            }
            else if (arg2 == "Priority") {
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
          quanta = stoi(arg2);
       }

       if (arg == "--premptive"){
            premptive = true;
       }

       if (arg == "--file"){
            fileName = arg2;
            i++;
       }

    }
    cout << "type: "<<type << endl;
    cout << "fileName: " << fileName << endl;
    cout << "premptive: " << premptive << endl;
    cout << "quanta: " << quanta << endl;
    cout << "verbose: " << verbose << endl;
    
    return 1;           
}