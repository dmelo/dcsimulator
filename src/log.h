#ifndef LOG_H
#define LOG_H

#include<stdio.h>
#include<stdlib.h>

#define LOG_LEVEL_0 0
#define LOG_LEVEL_1 1
#define LOG_LEVEL_2 2
#define LOG_LEVEL_3 3
#define LOG_LEVEL_4 4
#define LOG_LEVEL_5 5

class Log {
    public:
        Log(char *text, int logLevel);
        static void setLogLevel(int logLevel);
        static int getLogLevel();
        static void setFile(FILE *fd);
        static FILE *getFile();


    private:
        static int logLevel;
        static FILE *fd;
};

#endif
