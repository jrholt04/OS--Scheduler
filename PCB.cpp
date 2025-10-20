// FILE: PCB.cpp
// Authors: J Holt, N Neagle and A Seng, Transylvania University
// CS 3074, Fall 2025

// Implementation - PCB class

#include "PCB.h"

// constructor
// sets private variables
PCB::PCB(void) {
  priority = 0;
  arrivalTime = 0;
  burst = 0;
  startTime = 0;
  id = " ";
}

// destructor
PCB::~PCB(void) {}

// public member functions

// accessors
// getPriority
int PCB::getPriority(void) const{
  return priority;
}

// getArrivalTime
int PCB::getArrivalTime(void) const{
  return arrivalTime;
}

// getBurst
int PCB::getBurst(void) const{
  return burst;
}

// getId
string PCB::getId(void) const{
  return id;
}

// GetStartTime 
int PCB::getStartTime(void) const{
  return startTime;
}

// debugPrintPCB
void PCB::debugPrintPCB (void) const{
  cout << "ID: " << id << endl;
  cout << "PRIORITY: " << priority << endl;
  cout << "ARRIVAL: " << arrivalTime << endl;
  cout << "BURST: " << burst << endl;
  //return;
}
  
// mutators
// setPriority
void PCB::setPriority(int inputPriority) {
  priority = inputPriority;
  return;
}

// setArrivalTime
void PCB::setArrivalTime(int inputArrivalTime) {
  arrivalTime = inputArrivalTime;
  return;
}

// setBurst
void PCB::setBurst(int inputBurst) {
  burst = inputBurst;
  return;
}

// setId
void PCB::setId(string inputId) {
  id = inputId;
  return;
}

// setStartTime
void PCB::setStartTime(int time){
  startTime = time;
  return;
}

// overloaded =
PCB& PCB::operator= (const PCB& other) {
  if (this == &other) {
    return *this;
  }

  id = other.id;
  priority = other.priority;
  arrivalTime = other.arrivalTime;
  burst = other.burst;

  return *this;
}

// creates PCB vector from the file
vector<PCB> PCB::readPCBFile(string fileName){
  vector<PCB> PCBList;
  ifstream input;
  string id;
  int arrivalTime;
  int totalCPUBurst;
  int priority;
  
  input.open(fileName);
  if (!input){
      cout << "File not found" << endl;
      exit(0);
  }

  while (input >> id){
    PCB tempPCB;
    input >> arrivalTime;
    input >> totalCPUBurst;
    input >> priority;  

    tempPCB.setId(id);
    tempPCB.setArrivalTime(arrivalTime);
    tempPCB.setBurst(totalCPUBurst);
    tempPCB.setPriority(priority);

    PCBList.push_back(tempPCB);
  }

  // if id is not valid then do not continue
  if (id == ""){
    cout << "File data is not valid" << endl;
    exit(0);
  }

  return PCBList;
}