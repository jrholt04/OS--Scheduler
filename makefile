##makefile for scheudler
##N Neagle, J Holt, and A Seng

sched: SchedulerMain.o PCB.o fcfs.o
	g++ SchedulerMain.o fcfs.o PCB.o -o sched

SchedulerMain.o: SchedulerMain.cpp
	g++ -c SchedulerMain.cpp

PCB.o: PCB.cpp
	g++ -c PCB.cpp

fcfs.o: fcfs.cpp
	g++ -c fcfs.cpp