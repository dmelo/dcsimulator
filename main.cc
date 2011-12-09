#include<stdio.h>
#include<stdlib.h>
#include"cnetwork.h"



int main(int argc, char **argv) {
    CNetwork *cnet = new CNetwork(100000);
    cnet->initBAModel();

    delete cnet;

    return 0;
}
