#ifndef TIMER_H
#define TIMER_H
#include<sys/time.h>
#include<iostream>
#include<string>
#include<stdio.h>

using namespace std;

class timer {
    private:
	struct timezone tz;
	bool started;
	bool ended;
	struct timeval st;
	struct timeval en;
    public:
	timer();
	void restart();
	bool start();
	bool end();
	struct timeval getDiff();
	string toString();

    
};

#endif // TIMER_H
