##makefile for scheduler
##N Neagle, J Holt, and A Seng

sched: Scheduler.o PCB.o fcfs.o rr.o sjf.o priority.o schedulerTools.o
	g++ Scheduler.o fcfs.o PCB.o rr.o sjf.o priority.o schedulerTools.o -o sched

Scheduler.o: Scheduler.cpp PCB.o
	g++ -c Scheduler.cpp

PCB.o: PCB.cpp PCB.h
	g++ -c PCB.cpp

fcfs.o: fcfs.cpp fcfs.h PCB.o
	g++ -c fcfs.cpp

rr.o: rr.cpp rr.h PCB.o
	g++ -c rr.cpp

nonpresjf.o: sjf.cpp sjf.h PCB.o
	g++ -c sjf.cpp

priority.o: priority.cpp priority.h PCB.o
	g++ -c priority.cpp

schedulerTools.o: schedulerTools.cpp schedulerTools.h PCB.o
	g++ -c schedulerTools.cpp
