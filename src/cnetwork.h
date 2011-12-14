#ifndef CNETWORK_H
#define CNETWORK_H

#include"matrix.h"


class CNetwork {
    private:
       Matrix *matrix; 
       char text[5000];

    public:
        CNetwork(int size);
        ~CNetwork();

        void initBAModel();
        void exportNodesBCountRelation(FILE *fd);
};

#endif
