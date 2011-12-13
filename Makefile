CFLAGS=-g

all: cnet

cnet: main.cc cnetwork.o timer.o log.o
	g++ ${CFLAGS} main.cc cnetwork.o matrix.o timer.o log.o -o cnet

cnetwork.o: cnetwork.cc cnetwork.h matrix.o
	g++ ${CFLAGS} -c cnetwork.cc

matrix.o: matrix.cc matrix.h
	g++ ${CFLAGS} -c matrix.cc

timer.o: timer.cc timer.h
	g++ ${CFLAGS} -c timer.cc

log.o: log.cc log.h
	g++ ${CFLAGS} -c log.cc

clean:
	rm *.o cnet
