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
  id = "P_test";
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
  // depending on how the input file looks, we may need to append the P_
  //id = inputId;
  id = "P_" + inputId;
}

// operator=
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



// something to take in a PCB from the file?
