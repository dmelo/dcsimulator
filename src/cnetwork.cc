#include<stdlib.h>
#include"cnetwork.h"

CNetwork::CNetwork(int size) {
    srand(time(NULL));
    matrix = new Matrix(size);
}

CNetwork::~CNetwork() {
    delete matrix;
}

void CNetwork::initBAModel() {
    matrix->setLink(0, 1);
    matrix->setLink(1, 0);
    for(int i = 2; i < matrix->getSize(); i++) {
        int r = rand() % 5;
        for(int j = 0; j < r; j++) {
            int c = matrix->getRandomByPriotiyBLink();
            matrix->setLink(i, c);
            printf("setLink(%d, %d)\n", i, c);
        }
    }
}
