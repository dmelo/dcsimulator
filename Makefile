CFLAGS=-g

all: cnet

cnet: main.cc cnetwork.o
	g++ ${CFLAGS} main.cc cnetwork.o matrix.o -o cnet

cnetwork.o: cnetwork.cc cnetwork.h matrix.o
	g++ ${CFLAGS} -c cnetwork.cc

matrix.o: matrix.cc matrix.h
	g++ ${CFLAGS} -c matrix.cc

clean:
	rm *.o cnet
