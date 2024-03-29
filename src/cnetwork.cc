#include<stdlib.h>
#include"cnetwork.h"
#include"log.h"

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
    int z = 0;
    for(int i = 2; i < matrix->getSize(); i++) {
        int r = rand() % 5;
        for(int j = 0; j < r; j++) {
            int c = matrix->getRandomByPriotiyBLink();
            matrix->setLink(i, c);
            sprintf(text, "setLink(%d, %d)", i, c);
            Log(text, 0 == z % 100 ? 3: 5);
            z++;
        }
    }
}


void CNetwork::exportNodesBCountRelation(FILE *fd) {
    matrix->exportNodesBCountRelation(fd);
}
