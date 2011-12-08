#include<stdlib.h>
#include"cnetwork.h"

CNetwork::CNetwork(int size) {
    this->size = size;
    network = (set<int> **) calloc(size, sizeof(set<int> *));

    for(int i = 0; i < size; i++)
        network[i] = new set<int>;


}

CNetwork::~CNetwork() {
    for(int i = 0; i < size; i++)
        free(network[i]);
    free(network);
}

