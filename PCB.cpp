// FILE: PCB.cpp
// N Neagle, J Holt, and A Seng, Transylvania University
// CS 3074, Fall 2025


// Implementation - PCB class

#include "PCB.h"

// constructor
// sets private variables
PCB::PCB(void) {
  state = "testing";
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

// getState
string PCB::getState(void) {
  return state;
}

// getPriority
int PCB::getPriority(void) {
  return priority;
}

// getArrivalTime
int PCB::getArrivalTime(void) {
  return arrivalTime;
}

// getBurst
int PCB::getBurst(void) {
  return burst;
}

// getId
string PCB::getId(void) {
  return id;
}

// GetStartTime 
int PCB::getStartTime(void){
  return startTime;
}

// debugPrintPCB
void PCB::debugPrintPCB (void) {
  cout << "ID: " << id << endl;
  cout << "STATE: " << state << endl;
  cout << "PRIORITY: " << priority << endl;
  cout << "ARRIVAL: " << arrivalTime << endl;
  cout << "BURST: " << burst << endl;
}
  
// mutators

// setState
void PCB::setState(string inputState) {
  state = inputState;
  return;
}

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
  //id = inputId;
  id = inputId;
}

// setStartTime
void PCB::setStartTime(int time){
  startTime = time;
  return;
}



PCB& PCB::operator= (const PCB& other) {
  if (this == &other) {
    return *this;
  }

  id = other.id;
  state = other.state;
  priority = other.priority;
  arrivalTime = other.arrivalTime;
  burst = other.burst;

  return *this;
}

// something to take in a PCB from the file
vector<PCB> PCB::readPCBFile(string fileName){
  vector<PCB> PCBList;
  ifstream input;
  string id;
  int arrivalTime;
  int totalCPUBurst;
  int priority;
  
  input.open(fileName);
  if (!input){
      cout << "file not found" << endl;
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

  return PCBList;
}

