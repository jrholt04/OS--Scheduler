// FILE: PCB.h
// Authors: J Holt, N Neagle, and A Seng, Transylvania University
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
  // return the priority of the PCB
  int getPriority(void) const;
  
  // return the arrival time of the PCB
  int getArrivalTime(void) const;
  
  // return the CPU burst time of the PCB
  int getBurst(void) const;

  // return the ID of the PCB
  string getId(void) const;

  // get execute time 
  int getStartTime(void) const;

  // prints out the contents of the PCB. for debug use only
  void debugPrintPCB(void) const;
  
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

  // sets the start time of the PCB
  void setStartTime(int time);

  // overloaded =; allows us to copy PCBs using PCB1 = PCB2;
  PCB& operator=(const PCB& other);

  //read pcb file and return a vector of pcb 
  static vector<PCB> readPCBFile(string fileName);
  
 private:
  int priority;
  int arrivalTime;
  int burst;
  string id;
  int startTime;
};
  
#endif // PCB_H