#include"log.h"

#ifdef LOG_LEVEL
int Log::logLevel = LOG_LEVEL;
#else
int Log::logLevel = 3;
#endif

#ifdef LOG_FILE
FILE *Log::fd = fopen(LOG_FILE, "a");
#else
FILE *Log::fd = NULL;
#endif

Log::Log(char *text, int logLevel) {
    if(logLevel <= Log::logLevel) {
        if(fd) 
            fprintf(fd, text);
        else
            printf(text);
    }
}

void Log::setLogLevel(int logLevel) {
    Log::logLevel = logLevel;
}

int Log::getLogLevel() {
    return Log::logLevel;
}

void Log::setFile(FILE *fd) {
    Log::fd = fd;
}

FILE *Log::getFile() {
    return Log::fd;
}
