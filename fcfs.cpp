// File: fcfs.cpp
// Author: N Neagle, J Holt, and A Seng, Transy U
// Course: CS 3074 Operating Systems
//
// Implementation of the First Come First Serve scheduling algorithm
#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include "PCB.h"

using namespace std;

void fcfs(vector<PCB> tasks, bool verbose){
    vector<PCB> fcfsList;

    //insert sort
    fcfsList.push_back(tasks[0]);
    for (size_t i = 1; i < tasks.size(); ++i) {
        int j = fcfsList.size() - 1;

        while (j >= 0 && fcfsList[j].getArrivalTime() > tasks[i].getArrivalTime()) {
            --j;
        }
        fcfsList.insert(fcfsList.begin() + (j + 1), tasks[i]);
    }
    
    for (int i = 0; i < fcfsList.size(); i++){
        cout << "id: " << fcfsList[i].getId() << endl;
    }
}