##makefile for scheduler
##N Neagle, J Holt, and A Seng

sched: Scheduler.o PCB.o fcfs.o rr.o nonpresjf.o presj.o
	g++ Scheduler.o fcfs.o PCB.o rr.o nonpresjf.o presj.o -o sched

Scheduler.o: Scheduler.cpp
	g++ -c Scheduler.cpp

PCB.o: PCB.cpp
	g++ -c PCB.cpp

fcfs.o: fcfs.cpp
	g++ -c fcfs.cpp

rr.o: rr.cpp
	g++ -c rr.cpp

nonpresjf.o: nonpresjf.cpp
	g++ -c nonpresjf.cpp

presj.o: presj.cpp
	g++ -c presj.cpp
