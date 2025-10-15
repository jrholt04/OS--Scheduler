// FILE: PCB.h
// N Neagle, J Holt, and A Seng, Transylvania University
// CS 3074, Fall 2025

// Interface - PCB class

#ifndef PCB_H
#define PCB_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class PCB {

 public:
  // Constructor
  PCB(void);

  // Destructor
  ~PCB(void);

  // accessors
  // return the state of the PCB (or should we say process)
  string getState(void);
  
  // return the priority of the PCB
  int getPriority(void);
  
  // return the arrival time of the PCB
  int getArrivalTime(void);
  
  // return the CPU burst time of the PCB
  int getBurst(void);

  // return the ID of the PCB
  string getId(void);

  // prints out the contents of the PCB. for debug use only
  void debugPrintPCB(void);
  
  // mutators
  // sets the state of the PCB
  void setState(string inputState);

  // sets the priority of the PCB
  void setPriority(int inputPriority);

  // sets the arrival time of the PCB
  void setArrivalTime(int inputArrivalTime);

  // sets the CPU Burst of the PCB
  void setBurst(int inputBurst);

  // sets the ID of the PCB
  void setId(string inputId);

  // reads in (something) and fills in the entire PCB
  // bool read(ifstream& inFile);   // contemplating if we should have this in the class for the PCB or elsewhere. If it is here, should we have it take in the file or a string we get from the file elsewhere? getline could work here. also, does the file have those headder columns? - NN

  // overloaded =; allows us to copy PCBs using PCB1 = PCB2;
  PCB& operator=(const PCB& other);

  //read pcb file and return a vector of pcb 
  static vector<PCB> readPCBFile(string fileName);
  
 private:
  string state;
  int priority;
  int arrivalTime;
  int burst;
  string id;
  
};
  
#endif // PCB_H




