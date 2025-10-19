// File schedulerTools.cpp
// Author: N Neagle, J Holt, A Seng, Transy U
// Course: CS 3074 Operating Systems
//
// Implementation file for OS Scheduler Tools

#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include "PCB.h"
#include "schedulerTools.h"
using namespace std;

void sortPCBArrivalTime(vector<PCB> PCBList, vector<PCB>& output) {
  output.push_back(PCBList[0]);
  for (size_t i = 1; i < PCBList.size(); ++i) {
    int j = output.size() - 1;
    while (j >= 0 && output[j].getArrivalTime() > PCBList[i].getArrivalTime()) {
      j--;
    }
    output.insert(output.begin() + (j + 1), PCBList[i]);
  }
  return;
}

double calculateAvgWait(vector<int> waitTimes) {
  double totalWait = 0.0;
  for (int i = 0; i < waitTimes.size(); i++) totalWait += waitTimes[i];
  return totalWait / waitTimes.size();
}

void printVerbose(vector<PCB> PCBList, vector<int> startTimes, vector<int> waitTimes, string algorithm) {
  cout << endl << "===== " << algorithm << " Execution Details =====" << endl;
  for (int i = 0; i < PCBList.size(); i++) {
    cout << "id: " << PCBList[i].getId() << endl;
    cout << "executed for: " << PCBList[i].getBurst() << endl;
    cout << "enter time: " << PCBList[i].getArrivalTime() << endl;
    cout << "execution at: " << startTimes[i] << endl;
    cout << "wait time: " << waitTimes[i] << endl << endl;
  }
  return;
}

void printSchedulerHelp (void) {
  cout << endl << endl
       << "This is a scheduler simulator, with the ability to simulate First Come First Serve (FCFS), Round Robin (RR), and both preemptive and nonpreemptive Priority and Shortest Job First (SJF)." << endl << endl
       << "The program can be called with these command flags: " << endl << endl
       << "\t--type {FCFS|RR|SJF|Priority}" << endl
       << "\t\tSelects what scheduling algorithm you would like to select. The default is FCFS." << endl
       << "\t--verbose or --v" << endl
       << "\t\tPrints out a detailed description of the processes and information related to the scheduling" << endl
       << "\t--quanta {INTEGER} or --q {INTEGER}" << endl
       << "\t\tInput the quanta value used for Round Robin. The default value is 10." << endl
       << "\t--file {FILEPATH} or --f {FILEPATH}" << endl
       << "\t\tInput the file that conatains the process information used for the schedulers. The file takes the format of rows of ID Arrival_Time Total_CPU_Burst Priority. The default value is sched.in" << endl
       << "\t--help or --h" << endl
       << "\t\tPrints out this helpful how to!" << endl
       << endl;
  return;
}
