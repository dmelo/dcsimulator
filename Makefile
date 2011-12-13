CFLAGS=-g
BIN=bin
LIB=lib
SRC=src

all: ${BIN}/cnet

${BIN}/cnet: ${SRC}/main.cc ${LIB}/cnetwork.o ${LIB}/timer.o ${LIB}/log.o
	g++ ${CFLAGS} ${SRC}/main.cc ${LIB}/cnetwork.o ${LIB}/matrix.o ${LIB}/timer.o ${LIB}/log.o -o ${BIN}/cnet

${LIB}/cnetwork.o: ${SRC}/cnetwork.cc ${SRC}/cnetwork.h ${LIB}/matrix.o
	g++ ${CFLAGS} -c ${SRC}/cnetwork.cc -o ${LIB}/cnetwork.o

${LIB}/matrix.o: ${SRC}/matrix.cc ${SRC}/matrix.h
	g++ ${CFLAGS} -c ${SRC}/matrix.cc -o ${LIB}/matrix.o

${LIB}/timer.o: ${SRC}/timer.cc ${SRC}/timer.h
	g++ ${CFLAGS} -c ${SRC}/timer.cc -o ${LIB}/timer.o

${LIB}/log.o: ${SRC}/log.cc ${SRC}/log.h
	g++ ${CFLAGS} -c ${SRC}/log.cc -o ${LIB}/log.o

clean:
	rm ${LIB}/* ${BIN}/*
