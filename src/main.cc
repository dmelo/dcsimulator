#include<stdio.h>
#include<stdlib.h>
#include"cnetwork.h"
#include"log.h"



int main(int argc, char **argv) {
    CNetwork *cnet = new CNetwork(1000000);
    Log::setLogLevel(3);
    cnet->initBAModel();
    FILE *fgnuplot = fopen("/var/tmp/gnuplot", "w");
    cnet->exportNodesBCountRelation(fgnuplot);
    fclose(fgnuplot);

    delete cnet;

    return 0;
}
