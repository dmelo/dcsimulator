#include<stdlib.h>
#include"cnetwork.h"

CNetwork::CNetwork(int size) {
    network = (int *) calloc(size, sizeof(int));
}

CNetwork::~CNetwork() {
    free(network);
}

