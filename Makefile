all: cnet

cnet: main.cc cnetwork.o
	g++ main.cc cnetwork.o -o cnet

cnetwork.o: cnetwork.cc cnetwork.h matrix.o
	g++ -c cnetwork.cc

matrix.o: matric.cc matric.h
	g++ -c matrix.cc
