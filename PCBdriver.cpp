// FILE: PCBDriver.cpp
// N Neagle, Transy U

// test driver for PCB Class

#include <iostream>
#include "PCB.h"
using namespace std;

int main (void) {

  PCB testPCB;
  PCB copyPCB;
    
  string userInput = "";
  int userInt = 0;

  cout << endl << "Would you like to make a test PCB? (type exit to quit) " << endl;
  cin >> userInput;

  while (userInput != "exit") {
    cout << endl << "Please input the following information for your PCB:" << endl;
    cout << "\tID: ";
    cin >> userInput;
    testPCB.setId(userInput);

    cout << "\tState: ";
    cin >> userInput;
    testPCB.setState(userInput);

    cout << "\tPriority: ";
    cin >> userInt;
    testPCB.setPriority(userInt);

    cout << "\tArrival Time: ";
    cin >> userInt;
    testPCB.setArrivalTime(userInt);

    cout << "\tBurst: ";
    cin >> userInt;
    testPCB.setBurst(userInt);

    cout << "debug pring" << endl;
    testPCB.debugPrintPCB();
    cout << endl;

    cout << endl << "print w/ accessors" << endl;
    cout << "ID: " << testPCB.getId() << endl;
    cout << "STATE: " << testPCB.getState() << endl;
    cout << "PRIORITY: " << testPCB.getPriority() << endl;
    cout << "ARRIVAL: " << testPCB.getArrivalTime() << endl;
    cout << "BURST: " << testPCB.getBurst() << endl;

    cout << endl << "copy print /w debug" << endl;
    copyPCB = testPCB;
    copyPCB.debugPrintPCB();
    cout << endl;
    
    cout << "Would you like to make another? ";
    cin >> userInput;
  }
  cout << "toodaloo!" << endl;
}

    
