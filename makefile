##makefile for scheudler
##N Neagle, J Holt, and A Seng

sched: Scheduler.o PCB.o fcfs.o rr.o
	g++ Scheduler.o fcfs.o PCB.o rr.o -o sched

SchedulerMain.o: Scheduler.cpp
	g++ -c Scheduler.cpp

PCB.o: PCB.cpp
	g++ -c PCB.cpp

fcfs.o: fcfs.cpp
	g++ -c fcfs.cpp

rr.o: rr.cpp
	g++ -c rr.cpp